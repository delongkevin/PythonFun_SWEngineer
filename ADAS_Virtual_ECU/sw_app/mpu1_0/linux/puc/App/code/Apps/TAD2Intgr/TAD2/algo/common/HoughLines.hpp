// ----------------------------------------------------------------------------
// --- Written by Joshua Teichroeb [06-Jun-2019]
// --- Copyright (c) Magna Vectrics (MEVC) 2017
// ----------------------------------------------------------------------------

#include "HoughLines.h"

/*
* Return the line with the lesser score.
*/
template<uint32_t max_lines_returned>
inline bool_t TAD2::HoughLines<max_lines_returned>::ParameterizedLine::operator<(ParameterizedLine const& other) const
{
	return (this->score < other.score);
}

/*
* Return the line with the greater score.
*/
template<uint32_t max_lines_returned>
inline bool_t TAD2::HoughLines<max_lines_returned>::ParameterizedLine::operator>(ParameterizedLine const& other) const
{
	return (this->score > other.score);
}

/*
* Perform hough lines.
*/
template<uint32_t max_lines_returned>
inline TAD2::HoughLines<max_lines_returned>::HoughLines(const image::Image<uint8_t>& i_edges, const image::Image<uint8_t>& i_edgeDir, uint32_t i_threshold, uint32_t i_lineSep, mecl::core::ArrayList<TAD2::Line, max_lines_returned>& o_lines)
{
	m_nodes = new EdgeNode[c_maxImageWidth * c_maxImageHeight];
	m_lineDefs = new LineDef[c_maxRho * c_maxTheta];
	memset(&m_accumulator[0][0], 0, sizeof(m_accumulator));
	memset(m_nodes, 0, c_maxImageWidth * c_maxImageHeight * sizeof(m_nodes[0]));
	memset(m_lineDefs, 0, c_maxRho * c_maxTheta * sizeof(m_lineDefs[0]));
	
	// --- Accumulate line potential
	Accumulate(i_edges, i_edgeDir);
	//
	// --- Decumulate line potential along non-lines
	Decumulate(i_edges, i_edgeDir);
	//
	// --- Gather results above theshold
	std::priority_queue<ParameterizedLine, std::vector<ParameterizedLine>> orderedLines;

	for (uint32_t rho = 0; rho < c_maxRho; rho++)
	{
		for (uint32_t theta = 0; theta < c_maxTheta; theta++)
		{
			if (m_accumulator[rho][theta] > i_threshold)
			{
				orderedLines.push(ParameterizedLine(rho, theta, m_accumulator[rho][theta]));
				//o_lines.pushBack_v(TAD2::ParameterizedLine(rho, theta));
			}
		}
	}

	// --- Non-maxima suppression
	ParameterizedLine filteredLines[max_lines_returned];
	uint32_t numLines;
	NonMaximaSuppresssionUsingMask(orderedLines, filteredLines, numLines);
	//
	// --- Find endpoints
	//GetLineEndPoints(filteredLines, numLines, i_edges.width, i_edges.height, o_lines);
	GetLineEndPoints2(filteredLines, numLines, i_threshold, i_lineSep, o_lines);
	//
	Image<uint16_t> temp(c_maxTheta, c_maxRho, &m_accumulator[0][0], 1);
	db::imshow("(HUF-1) Hough Space", temp, db::ImShow_Grey2Colour, (uint16_t)0, (uint16_t)0);
	//
	delete[] m_nodes;
	delete[] m_lineDefs;
}

/*
* Called on destruction.
*/
template<uint32_t max_lines_returned>
inline TAD2::HoughLines<max_lines_returned>::~HoughLines()
{
}

/*
* Accumulate the number of edges accounting for each possible line.
*/
template<uint32_t max_lines_returned>
inline void TAD2::HoughLines<max_lines_returned>::Accumulate(const image::Image<uint8_t>& i_edges, const image::Image<uint8_t>& i_edgeDir)
{
	//const float32_t c_thetaStep_rad = PI / 180.0f;
	float32_t theta_rad;
	uint32_t start_deg, end_deg;

	// --- Loop through edge pixels
	for (uint32_t y = 0; y < i_edges.height; y++)
	{
		for (uint32_t x = 0; x < i_edges.width; x++)
		{
			if (*i_edges.at(x, y) > 0)
			{
				// --- Get possible range of line angles
				switch (*i_edgeDir.at(x,y))
				{
				case TAD2::Canny::c_0deg:
					start_deg = 158;
					end_deg = 204;
					//theta_rad = 158 * PI / 180;
					break;
				case TAD2::Canny::c_45deg:
					start_deg = 23;
					end_deg = 69;
					//theta_rad = 23 * PI / 180;
					break;
				case TAD2::Canny::c_90deg:
					start_deg = 68;
					end_deg = 114;
					//theta_rad = 68 * PI / 180;
					break;
				case TAD2::Canny::c_135deg:
					start_deg = 113;
					end_deg = 159;
					//theta_rad = 113 * PI / 180;
					break;
				}

				// --- Increment each possible line
				for (uint32_t theta_deg = start_deg; theta_deg != end_deg; theta_deg++)
				{
					theta_rad = (float32_t)theta_deg * PI / 180.0f;
					int32_t rho =(int32_t)((float32_t)x * cos(theta_rad) + (float32_t)y * sin(theta_rad) + 0.5f);

					if (rho < 0)
					{
						if (theta_deg > 180)
						{
							m_accumulator[-rho][theta_deg - 180]++;
							//if (-rho > 0) m_accumulator[-rho - 1][theta_deg - 180]++;
							//if (-rho < c_maxRho - 1) m_accumulator[-rho + 1][theta_deg - 180]++;
						}
						else
						{
							m_accumulator[-rho][theta_deg + 180]++;
							//if (-rho > 0) m_accumulator[-rho - 1][theta_deg + 180]++;
							//if (-rho < c_maxRho - 1) m_accumulator[-rho + 1][theta_deg + 180]++;
						}
					}
					else if (rho > c_maxRho)
					{
						m_accumulator[c_maxRho][theta_deg]++;
						m_accumulator[c_maxRho - 1][theta_deg]++;
					}
					else
					{
						m_accumulator[rho][theta_deg]++;

						//if (rho > 0) m_accumulator[rho - 1][theta_deg]++;
						//if (rho < c_maxRho - 1) m_accumulator[rho + 1][theta_deg]++;
					}
				}
			}
		}
	}
}

/*
* Re-iterate over every edge and decrement the accumulator where the line was
* not the determined to be the best line. Results in each edge accounting for 
* only a single line
*/
template<uint32_t max_lines_returned>
inline void TAD2::HoughLines<max_lines_returned>::Decumulate(const image::Image<uint8_t>& i_edges, const image::Image<uint8_t>& i_edgeDir)
{
	//const float32_t c_thetaStep_rad = PI / 180.0f;
	float32_t theta_rad;
	uint32_t start_deg, end_deg;

	// --- Loop through edge pixels
	for (uint32_t y = 0; y < i_edges.height; y++)
	{
		for (uint32_t x = 0; x < i_edges.width; x++)
		{
			if (*i_edges.at(x, y) > 0)
			{
				// --- Get possible range of line angles
				switch (*i_edgeDir.at(x, y))
				{
				case TAD2::Canny::c_0deg:
					start_deg = 158;
					end_deg = 204;
					//theta_rad = 158 * PI / 180;
					break;
				case TAD2::Canny::c_45deg:
					start_deg = 23;
					end_deg = 69;
					//theta_rad = 23 * PI / 180;
					break;
				case TAD2::Canny::c_90deg:
					start_deg = 68;
					end_deg = 114;
					//theta_rad = 68 * PI / 180;
					break;
				case TAD2::Canny::c_135deg:
					start_deg = 113;
					end_deg = 159;
					//theta_rad = 113 * PI / 180;
					break;
				}

				// --- Decrement each possible line except for max
				uint32_t max = 0;
				uint32_t best_rho = 0;
				uint32_t best_theta = 0;

				for (uint32_t theta_deg = start_deg; theta_deg != end_deg; theta_deg++)
				{
					theta_rad = (float32_t)theta_deg * PI / 180.0f;
					int32_t rho = (int32_t)((float32_t)x * cos(theta_rad) + (float32_t)y * sin(theta_rad) + 0.5f);
					uint32_t rho_ind, theta_ind;

					if (rho < 0)
					{
						if (theta_deg > 180)
						{
							rho_ind = -rho;
							theta_ind = theta_deg - 180;
						}
						else
						{
							rho_ind = -rho;
							theta_ind = theta_deg + 180;
						}
					}
					else if (rho > c_maxRho)
					{
						rho_ind = c_maxRho;
						theta_ind = theta_deg;
					}
					else
					{
						rho_ind = rho;
						theta_ind = theta_deg;
					}

					if (m_accumulator[rho_ind][theta_ind] > max)
					{
						best_rho = rho_ind;
						best_theta = theta_ind;
						max = m_accumulator[rho_ind][theta_ind];
					}

					m_accumulator[rho_ind][theta_ind]--;
					//if (rho_ind > 0) m_accumulator[rho_ind - 1][theta_ind]--;
					//if (rho_ind < c_maxRho) m_accumulator[rho_ind + 1][theta_ind]--;
				}

				m_accumulator[best_rho][best_theta]++;

				// --- Add node to corresponding line
				if (m_lineDefs[best_rho * c_maxTheta + best_theta].head == NULL)
				{
					m_lineDefs[best_rho * c_maxTheta + best_theta].head = &m_nodes[y * c_maxImageWidth + x];
					m_lineDefs[best_rho * c_maxTheta + best_theta].tail = &m_nodes[y * c_maxImageWidth + x];
				}
				else
				{
					m_lineDefs[best_rho * c_maxTheta + best_theta].tail->next = &m_nodes[y * c_maxImageWidth + x];
					m_lineDefs[best_rho * c_maxTheta + best_theta].tail = &m_nodes[y * c_maxImageWidth + x];
				}
			}
		}
	}
}

/*
* Perform non-maxima suppression on the accumulator.
*/
template<uint32_t max_lines_returned>
inline void TAD2::HoughLines<max_lines_returned>::NonMaximaSuppresssionUsingMask(std::priority_queue<ParameterizedLine>& i_orderedLines, ParameterizedLine o_filteredLines[max_lines_returned], uint32_t& o_numLines)
{
	//bool_t hash_map[c_maxRho][c_maxTheta];
	bool_t* hash_map = new bool_t[901 * 360];
	memset(hash_map, false, 901 * 360 * sizeof(bool_t));
	o_numLines = 0;
	//std::priority_queue<TAD2::ParameterizedLine, std::vector<TAD2::ParameterizedLine>, decltype(compare)>:: it = orderedLines.begin();

	while (!i_orderedLines.empty())
	{
		const ParameterizedLine& line = i_orderedLines.top();
		i_orderedLines.pop();

		if (!hash_map[line.rho * 360 + line.theta])
		{
			uint32_t k = 3;
			uint32_t min_rho = (line.rho > k) ? line.rho - k : 0;
			uint32_t max_rho = (line.rho + k < c_maxRho) ? line.rho + k : c_maxRho;
			uint32_t min_theta = (line.theta > k) ? line.theta - k : 0;
			uint32_t max_theta = (line.theta + k < c_maxTheta) ? line.theta + k : c_maxTheta;

			for (uint32_t i = min_rho; i < max_rho; i++)
			{
				for (uint32_t j = min_theta; j < max_theta; j++)
				{
					hash_map[i * 360 + j] = true;
				}
			}

			if (o_numLines < max_lines_returned)
			{
				o_filteredLines[o_numLines] = line;
				o_numLines++;
			}
			else
			{
				break;
			}
		}
	}

	delete[] hash_map;
}

/*
* Calculate the endpoints of each of the paramterized lines, by finding their intersection
* with the boundaries of the image.
*/
template<uint32_t max_lines_returned>
inline void TAD2::HoughLines<max_lines_returned>::GetLineEndPoints(ParameterizedLine i_lines[max_lines_returned], uint32_t i_numLines, uint32_t i_imgWidth, uint32_t i_imgHeight, mecl::core::ArrayList<TAD2::Line, max_lines_returned>& o_lines)
{
	uint32_t w = i_imgWidth - 1;
	uint32_t h = i_imgHeight - 1;

	for (uint32_t i = 0; i < i_numLines; i++)
	{
		const ParameterizedLine& line = i_lines[i];
		Point2i p1, p2;

		if (line.theta == 0 || line.theta == 180)
		{
			p1 = Point2i(line.rho, 0);
			p2 = Point2i(line.rho, h);
		}
		else if (line.theta == 90 || line.theta == 270)
		{
			p1 = Point2i(0, line.rho);
			p2 = Point2i(w, line.rho);
		}
		else
		{
			float32_t theta_rad = line.theta * PI / 180.0f;
			Point2i y1_inter = Point2i(0, line.rho / sin(theta_rad));
			Point2i y2_inter = Point2i(w, (-cos(theta_rad) / sin(theta_rad)) * w + line.rho / sin(theta_rad));
			Point2i x1_inter = Point2i(line.rho / cos(theta_rad), 0);
			Point2i x2_inter = Point2i((h - line.rho / sin(theta_rad)) * (-sin(theta_rad) / cos(theta_rad)), h);
			Point2i* curP = &p1;

			if (0 <= x1_inter.x && x1_inter.x <= w)
			{
				*curP = x1_inter;
				curP = &p2;
			}

			if (0 < y1_inter.y && y1_inter.y <= h)
			{
				*curP = y1_inter;
				curP = &p2;
			}

			if (0 < y2_inter.y && y2_inter.y <= h)
			{
				*curP = y2_inter;
				curP = &p2;
			}

			if (0 < x2_inter.x && x2_inter.x < w)
			{
				*curP = x2_inter;
				curP = &p2;
			}

			if (p1.y > p2.y)
			{
				Point2i tmp = p1;
				p1 = p2;
				p2 = tmp;
			}
		}

		o_lines.pushBack_v(TAD2::Line(p1, p2, line.score));
	}
}

/*
* Take each of the parameterized lines and separate them into lines defined by endpoints.
* 
* Each line must have at least 'i_threshold' number of edges to be considered a line, and 
* cannot have a gap in edges that is greter than 'i_lineSep'.
*/
template<uint32_t max_lines_returned>
inline void TAD2::HoughLines<max_lines_returned>::GetLineEndPoints2(ParameterizedLine i_lines[max_lines_returned], uint32_t i_numLines, uint32_t i_threshold, uint32_t i_lineSep, mecl::core::ArrayList<TAD2::Line, max_lines_returned>& o_lines)
{
	for (uint32_t i = 0; i < i_numLines; i++)
	{
		const ParameterizedLine& line = i_lines[i];
		const LineDef& lineDef = m_lineDefs[line.rho * c_maxTheta + line.theta];
		Point2i p1, p2;

		if (lineDef.head == NULL)
		{
			continue;
		}

		p1 = Point2i((lineDef.head - m_nodes) % c_maxImageWidth, (lineDef.head - m_nodes) / c_maxImageWidth);
		EdgeNode* prevNode = lineDef.head;
		EdgeNode* curNode = lineDef.head->next;
		uint32_t count = 1;

		// --- Loop through edge points
		while (curNode != NULL)
		{
			Point2i prevPoint = Point2i((prevNode - m_nodes) % c_maxImageWidth, (prevNode - m_nodes) / c_maxImageWidth);
			Point2i curPoint = Point2i((curNode - m_nodes) % c_maxImageWidth, (curNode - m_nodes) / c_maxImageWidth);
			float32_t dist = sqrt((curPoint.y - prevPoint.y) * (curPoint.y - prevPoint.y) + (curPoint.x - prevPoint.x) * (curPoint.x - prevPoint.x));

			// --- Check for too great separation between points
			if (dist > i_lineSep)
			{
				// --- Add line if long enough
				if (count > i_threshold && o_lines.size_u32() < max_lines_returned)
				{
					p2 = prevPoint;
					o_lines.pushBack_v(TAD2::Line(p1, p2));
				}

				// --- Start new line
				p1 = curPoint;
				count = 1;
			}

			prevNode = curNode;
			curNode = curNode->next;
			count++;
		}

		// --- Add final line if long enough
		if (count > i_threshold && o_lines.size_u32() < max_lines_returned)
		{
			p2 = Point2i((prevNode - m_nodes) % c_maxImageWidth, (prevNode - m_nodes) / c_maxImageWidth);
			o_lines.pushBack_v(TAD2::Line(p1, p2));
		}
	}
}
