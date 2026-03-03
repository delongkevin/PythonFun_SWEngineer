// ----------------------------------------------------------------------------
// --- Written by Joshua Teichroeb [01-Aug-2019]
// --- Copyright (c) Magna Vectrics (MEVC) 2017
// ----------------------------------------------------------------------------

#include "WindowsDebugger.h"
#include "TemplateWeightMask.h"

#ifndef __WINDOWS_DEBUGGER__HPP_
#define __WINDOWS_DEBUGGER__HPP_

#ifdef WINDOWS_DEBUGGING

#ifndef max
#define max(a,b) ((a) > (b) ? (a) : (b))
#endif

#ifndef min
#define min(a,b) ((a) < (b) ? (a) : (b))
#endif

template<typename T>
inline void db::WindowsDebugger::Plot(const char * winname, T * x, T * y, int numPoints, db::Colour colour, int shift)
{
	if (m_pWindowManager->IsEnabled(winname))
	{
		getPlotter(winname)->plot(x, y, numPoints, colour, shift);
		cv::ImageView* pView = getImageView(winname);
		pView->invalidate();
		pView->requestRefresh();
	}
}

template<typename T>
inline void db::WindowsDebugger::Imshow(const char * winname, image::Image<T>& image, db::imshow_options option, T maxVal, T minVal)
{
	if (!m_pWindowManager->IsEnabled(winname))
	{
		return;
	}

	cv::ImageView* pView = getImageView(winname, image.getWidth(), image.getHeight(), CV_8UC3);
	cv::Mat& displayImg = pView->getMat();
	//cv::Mat displayImg = cv::Mat( image.height, image.width, CV_8UC3 );
	uint8_t* dst_ptr = displayImg.data;
	image::Image<T>::iterator src_it = image.begin();
	image::Image<T>::iterator src_end = image.end();

	if (maxVal == minVal)
	{
		maxVal = FindMax(image);
		minVal = FindMin(image);
	}

	float factor = 255.0f / (float)(maxVal - minVal);

	// --- Do conversion to 3 channel
	switch (option)
	{
	case db::ImShow_Grey2Colour:
	{
		float qrtrFactor = factor * 4;
		T MagentaVal = minVal + (maxVal - minVal) / 4;
		T GreenVal = minVal + (maxVal - minVal) / 2;
		T YellowVal = minVal + 3 * (maxVal - minVal) / 4;
		unsigned char B, G, R;

		for (; src_it < src_end; src_it += image.getNumChannels(), dst_ptr += 3)
		{
			if (*src_it < MagentaVal)
			{
				B = 255;
				G = (unsigned char)((*src_it - minVal) * qrtrFactor);
				R = 0;
			}
			else if (*src_it < GreenVal)
			{
				B = 255 - (unsigned char)((*src_it - MagentaVal) * qrtrFactor);
				G = 255;
				R = 0;
			}
			else if (*src_it < YellowVal)
			{
				B = 0;
				G = 255;
				R = (unsigned char)((*src_it - GreenVal) * qrtrFactor);
			}
			else
			{
				B = 0;
				G = 255 - (unsigned char)((*src_it - YellowVal) * qrtrFactor);
				R = 255;
			}

			dst_ptr[0] = B;
			dst_ptr[1] = G;
			dst_ptr[2] = R;
		}

		break;
	}

	case db::ImShow_Binary:
	{
		if (displayImg.isContinuous())
		{
			for (; src_it < src_end; ++src_it, dst_ptr += 3)
			{
				dst_ptr[0] = (*src_it >(T)0) ? 255 : 0;
				dst_ptr[1] = (*src_it > (T)0) ? 255 : 0;
				dst_ptr[2] = (*src_it > (T)0) ? 255 : 0;
			}
		}
		else
		{
			uint8_t* dst_row = dst_ptr;

			for (unsigned int y = 0; y < image.getHeight(); y++)
			{
				dst_ptr = dst_row;

				for (unsigned int x = 0; x < image.getWidth(); x++)
				{
					dst_ptr[0] = (*src_it >(T)0) ? 255 : 0;
					dst_ptr[1] = (*src_it >(T)0) ? 255 : 0;
					dst_ptr[2] = (*src_it > (T)0) ? 255 : 0;
					dst_ptr += 3;
					++src_it;
				}

				dst_row += displayImg.step;
			}
		}

		break;
	}

	case db::ImShow_BGR:
	{
		for (; src_it < src_end; src_it += image.getNumChannels(), dst_ptr += 3)
		{
			dst_ptr[0] = (uint8_t)((src_it[0] - minVal) * factor);
			dst_ptr[1] = (uint8_t)((src_it[1] - minVal) * factor);
			dst_ptr[2] = (uint8_t)((src_it[2] - minVal) * factor);
		}

		break;
	}

	case db::ImShow_Grey:
	{
		if (displayImg.isContinuous())
		{
			for (; src_it < src_end; ++src_it, dst_ptr += 3)
			{
				dst_ptr[0] = (uint8_t)((*src_it - minVal) * factor);
				dst_ptr[1] = (uint8_t)((*src_it - minVal) * factor);
				dst_ptr[2] = (uint8_t)((*src_it - minVal) * factor);
			}
		}
		else
		{
			uint8_t* dst_row = dst_ptr;

			for (unsigned int y = 0; y < image.getHeight(); y++)
			{
				dst_ptr = dst_row;

				for (unsigned int x = 0; x < image.getWidth(); x++)
				{
					dst_ptr[0] = (uint8_t)((*src_it - minVal) * factor);
					dst_ptr[1] = (uint8_t)((*src_it - minVal) * factor);
					dst_ptr[2] = (uint8_t)((*src_it - minVal) * factor);
					dst_ptr += 3;
					++src_it;
				}

				dst_row += displayImg.step;
			}
		}

		break;
	}
	}

	pView->invalidate();
	pView->requestRefresh();
}

template<typename T>
inline void db::WindowsDebugger::Imshow_log(const char * winname, image::Image<T>& image, T maxVal, T minVal)
{
}

template<typename T, typename U>
inline void db::WindowsDebugger::Imshow_segmented(const char * winname, image::Image<T>& image, image::Image<U>& thresh_low, image::Image<U>& thresh_high)
{
	if (!m_pWindowManager->IsEnabled(winname))
	{
		return;
	}

	cv::ImageView* pView = getImageView(winname, image.getWidth(), image.getHeight(), CV_8UC3);
	cv::Mat& cvImg = pView->getMat();
	//cv::Mat cvImg = cv::Mat( image.height, image.width, CV_8UC3 );
	uint8_t* dst_ptr = cvImg.data;
	image::Image<T>::iterator img_it = image.begin();
	image::Image<U>::iterator low_it = thresh_low.begin();
	image::Image<U>::iterator high_it = thresh_high.begin();
	image::Image<T>::iterator img_end = image.end();

	for (; img_it != img_end; ++img_it, ++low_it, ++high_it, dst_ptr += 3)
	{
		if (*img_it < (T)*low_it)
		{
			dst_ptr[0] = 255;
			dst_ptr[1] = 0;
			dst_ptr[2] = 0;
		}
		else if (*img_it < (T)*high_it)
		{
			dst_ptr[0] = 0;
			dst_ptr[1] = 255;
			dst_ptr[2] = 0;
		}
		else
		{
			dst_ptr[0] = 0;
			dst_ptr[1] = 0;
			dst_ptr[2] = 255;
		}
	}

	pView->invalidate();
	pView->requestRefresh();
}

template<typename T>
inline void db::WindowsDebugger::Imshow_segmented(const char * winname, image::Image<T>& image, T thresh_low, T thresh_high)
{
	if (!m_pWindowManager->IsEnabled(winname))
	{
		return;
	}

	cv::ImageView* pView = getImageView(winname, image.getWidth(), image.getHeight(), CV_8UC3);
	cv::Mat& cvImg = pView->getMat();
	uint8_t* dst_ptr = cvImg.data;
	image::Image<T>::iterator img_it = image.begin();
	image::Image<T>::iterator img_end = image.end();

	for (; img_it != img_end; ++img_it, dst_ptr += 3)
	{
		if (*img_it < thresh_low)
		{
			dst_ptr[0] = 255;
			dst_ptr[1] = 0;
			dst_ptr[2] = 0;
		}
		else if (*img_it < thresh_high)
		{
			dst_ptr[0] = 0;
			dst_ptr[1] = 255;
			dst_ptr[2] = 0;
		}
		else
		{
			dst_ptr[0] = 0;
			dst_ptr[1] = 0;
			dst_ptr[2] = 255;
		}
	}

	pView->invalidate();
	pView->requestRefresh();
}

template<typename T>
inline void db::WindowsDebugger::Imshow_threshold(const char * winname, image::Image<T>& image, T thresh, T maxVal, T minVal)
{
	if (!m_pWindowManager->IsEnabled(winname))
	{
		return;
	}

	cv::ImageView* pView = getImageView(winname, image.width, image.height, CV_8UC3);
	cv::Mat& displayImg = pView->getMat();
	uint8_t* dst_ptr = displayImg.data;
	image::Image<T>::iterator src_it = image.begin();
	image::Image<T>::iterator src_end = image.end();

	auto f = [](T arg)
	{
		if (arg == 0)
		{
			return 0.0f;
		}
		else
		{
			return log((float)arg);
		}
	};

	if (maxVal == minVal)
	{
		maxVal = FindMax(image);
		minVal = FindMin(image);
	}

	float minVal_f = f(minVal);
	float maxVal_f = f(maxVal);
	float thresh_f = f(thresh);

	float factor1 = 255.0f / (float)(thresh_f - minVal_f);
	float factor2 = 255.0f / (float)(maxVal_f - thresh_f);

	for (; src_it < src_end; src_it += image.numChannels, dst_ptr += 3)
	{
		float val = f(*src_it);

		if (val < thresh_f)
		{
			dst_ptr[0] = (uint8_t)((val - minVal_f) * factor1);
			dst_ptr[1] = (uint8_t)((val - minVal_f) * factor1);
			dst_ptr[2] = 255;
		}
		else
		{
			dst_ptr[0] = 255;
			dst_ptr[1] = (uint8_t)(255.0f - (val - thresh_f) * factor2);
			dst_ptr[2] = (uint8_t)(255.0f - (val - thresh_f) * factor2);
		}
	}

	pView->invalidate();
	pView->requestRefresh();
}

template<typename T>
inline void db::WindowsDebugger::Imshow_range(const char * winname, image::Image<T>& image, T maxVal, T minVal)
{
	if (!m_pWindowManager->IsEnabled(winname))
	{
		return;
	}

	cv::ImageView* pView = getImageView(winname, image.getWidth(), image.getHeight(), CV_8UC3);
	cv::Mat& displayImg = pView->getMat();
	uint8_t* dst_ptr = displayImg.data;
	image::Image<T>::iterator src_it = image.begin();
	image::Image<T>::iterator src_end = image.end();

	if (maxVal == minVal)
	{
		maxVal = FindMax(image);
		minVal = FindMin(image);
	}

	float factor = 255.0f / (float)(maxVal - minVal);

	if (displayImg.isContinuous())
	{
		for (; src_it < src_end; ++src_it, dst_ptr += 3)
		{
			if (*src_it < minVal)
			{
				dst_ptr[0] = 255;
				dst_ptr[1] = 0;
				dst_ptr[2] = 0;
			}
			else if (*src_it > maxVal)
			{
				dst_ptr[0] = 0;
				dst_ptr[1] = 0;
				dst_ptr[2] = 255;
			}
			else
			{
				dst_ptr[0] = (uint8_t)((*src_it - minVal) * factor);
				dst_ptr[1] = (uint8_t)((*src_it - minVal) * factor);
				dst_ptr[2] = (uint8_t)((*src_it - minVal) * factor);
			}
		}
	}
	else
	{
		uint8_t* dst_row = dst_ptr;

		for (unsigned int y = 0; y < image.getHeight(); y++)
		{
			dst_ptr = dst_row;

			for (unsigned int x = 0; x < image.getWidth(); x++)
			{
				if (*src_it < minVal)
				{
					dst_ptr[0] = 255;
					dst_ptr[1] = 0;
					dst_ptr[2] = 0;
				}
				else if (*src_it > maxVal)
				{
					dst_ptr[0] = 0;
					dst_ptr[1] = 0;
					dst_ptr[2] = 255;
				}
				else
				{
					dst_ptr[0] = (uint8_t)((*src_it - minVal) * factor);
					dst_ptr[1] = (uint8_t)((*src_it - minVal) * factor);
					dst_ptr[2] = (uint8_t)((*src_it - minVal) * factor);
				}

				dst_ptr += 3;
				++src_it;
			}

			dst_row += displayImg.step;
		}
	}

	pView->invalidate();
	pView->requestRefresh();
}

template<typename T>
inline void db::WindowsDebugger::Imshow_threshold_and_range(const char * winname, image::Image<T>& image, T thresh, T maxVal, T minVal)
{
	if (!m_pWindowManager->IsEnabled(_winname))
	{
		return;
	}

	cv::ImageView* pView = getImageView(winname, _image.width, _image.height, CV_8UC3);
	cv::Mat& displayImg = pView->getMat();
	uint8_t* dst_ptr = displayImg.data;
	image::Image<T>::iterator src_it = _image.begin();
	image::Image<T>::iterator src_end = _image.end();

	auto f = [](T arg)
	{
		if (arg == 0)
		{
			return 0.0f;
		}
		else
		{
			return log((float)arg);
		}
	};

	if (_maxVal == _minVal)
	{
		_maxVal = FindMax(_image);
		_minVal = FindMin(_image);
	}

	float minVal = f(_minVal);
	float maxVal = f(_maxVal);
	float thresh = f(_thresh);

	float factor1 = 255.0f / (float)(thresh - minVal);
	float factor2 = 255.0f / (float)(maxVal - thresh);

	for (; src_it < src_end; src_it += _image.numChannels, dst_ptr += 3)
	{
		float val = f(*src_it);

		if (val < minVal)
		{
			dst_ptr[0] = 0;
			dst_ptr[1] = 0;
			dst_ptr[2] = 255;
		}
		else if (val > maxVal)
		{
			dst_ptr[0] = 255;
			dst_ptr[1] = 0;
			dst_ptr[2] = 0;
		}
		else if (val < thresh)
		{
			dst_ptr[0] = (val - minVal) * factor1;
			dst_ptr[1] = (val - minVal) * factor1;
			dst_ptr[2] = 255;
		}
		else
		{
			dst_ptr[0] = 255;
			dst_ptr[1] = 255 - (val - thresh) * factor2;
			dst_ptr[2] = 255 - (val - thresh) * factor2;
		}
	}

	pView->invalidate();
	pView->requestRefresh();
}

template<typename T>
inline void db::WindowsDebugger::Imshow_overlap(const char * winname, image::Image<T>& image1, image::Image<T>& image2)
{
	if (!m_pWindowManager->IsEnabled(winname))
	{
		return;
	}

	cv::ImageView* pView = getImageView(winname, image1.width, image1.height, CV_8UC3);
	cv::Mat& result = pView->getMat();
	uint8_t* rslt_ptr = result.data;
	Image<T>::iterator img1_it = image1.begin();
	Image<T>::iterator img2_it = image2.begin();
	Image<T>::iterator img1_end = image1.end();
	unsigned int x = 0;
	unsigned int y = 0;

	for (; img1_it != img1_end; ++img1_it, ++img2_it, rslt_ptr += 3)
	{
		if (*img1_it > 0 && *img2_it == 0)
		{
			rslt_ptr[0] = 255;
			rslt_ptr[1] = 0;
			rslt_ptr[2] = 0;
		}
		else if (*img1_it == 0 && *img2_it > 0)
		{
			rslt_ptr[0] = 0;
			rslt_ptr[1] = 0;
			rslt_ptr[2] = 255;
		}
		else if (*img1_it == 0 && *img2_it == 0)
		{
			rslt_ptr[0] = 0;
			rslt_ptr[1] = 0;
			rslt_ptr[2] = 0;
		}
		else if (*img1_it > 0 && *img2_it > 0)
		{
			rslt_ptr[0] = 255;
			rslt_ptr[1] = 0;
			rslt_ptr[2] = 255;
		}

		x++;

		if (x == image1.width)
		{
			x = 0;
			y++;
		}
	}

	pView->invalidate();
	pView->requestRefresh();
}

template<typename T>
inline void db::WindowsDebugger::Imshow_templateOverlap(const char * winname, image::Image<T>& template1, image::Image<T>& template2, float32_t tmFactor)
{
	if (!m_pWindowManager->IsEnabled(winname))
	{
		return;
	}

	cv::ImageView* pView = getImageView(winname, template1.getWidth(), template1.getHeight(), CV_8UC3);
	cv::Mat& result = pView->getMat();
	uint8_t* rslt_row = result.data;
	uint8_t* rslt_ptr;
	image::Image<T>::iterator img1_it = template1.begin();
	image::Image<T>::iterator img2_it = template2.begin();
	image::Image<T>::iterator img1_end = template1.end();

	for (unsigned int y = 0; y < template1.getHeight(); y++)
	{
		rslt_ptr = rslt_row;

		for (unsigned int x = 0; x < template1.getWidth(); x++)
		{
			if (*img1_it > 0 && *img2_it == 0)
			{
				rslt_ptr[0] = (uint8_t)(255 * max((1.0f + mask::TemplateWeightMask[y][x] * tmFactor), 0.0f) / (1 + mask::TemplateWeightMaskRange[1]));
				rslt_ptr[1] = 0;
				rslt_ptr[2] = 0;
			}
			else if (*img1_it == 0 && *img2_it > 0)
			{
				rslt_ptr[0] = 0;
				rslt_ptr[1] = 0;
				rslt_ptr[2] = (uint8_t)(255 * max((1.0f + mask::TemplateWeightMask[y][x] * tmFactor), 0.0f) / (1 + mask::TemplateWeightMaskRange[1]));
			}
			else if (*img1_it == 0 && *img2_it == 0)
			{
				rslt_ptr[0] = 0;
				rslt_ptr[1] = 0;
				rslt_ptr[2] = 0;
			}
			else if (*img1_it > 0 && *img2_it > 0)
			{
				rslt_ptr[0] = (uint8_t)(255 * max((1.0f + mask::TemplateWeightMask[y][x] * tmFactor), 0.0f) / (1 + mask::TemplateWeightMaskRange[1]));
				rslt_ptr[1] = 0;
				rslt_ptr[2] = (uint8_t)(255 * max((1.0f + mask::TemplateWeightMask[y][x] * tmFactor), 0.0f) / (1 + mask::TemplateWeightMaskRange[1]));
			}

			++img1_it;
			++img2_it;
			rslt_ptr += 3;
		}

		rslt_row += result.step;
	}

	pView->invalidate();
	pView->requestRefresh();
}

template<typename T>
inline cv::Mat db::WindowsDebugger::createDisplayMat(image::Image<T>& image, T maxVal, T minVal)
{
	cv::Mat displayImg = cv::Mat(image.height, image.width, CV_8UC3);
	uint8_t* dst_ptr = displayImg.data;
	image::Image<T>::iterator src_it = image.begin();
	image::Image<T>::iterator src_end = image.end();
	T factor = 255 / (maxVal - minVal);

	for (; src_it < src_end; src_it += image.numChannels, dst_ptr += 3)
	{
		if (image.numChannels == 1)
		{
			dst_ptr[0] = (uint8_t)((*src_it - minVal) * factor);
			dst_ptr[1] = (uint8_t)((*src_it - minVal) * factor);
			dst_ptr[2] = (uint8_t)((*src_it - minVal) * factor);
		}
		else if (image.numChannels <= 3)
		{
			dst_ptr[0] = (uint8_t)((*src_it - minVal) * factor);
			dst_ptr[1] = (uint8_t)((*src_it - minVal) * factor);
			dst_ptr[2] = (uint8_t)((*src_it - minVal) * factor);
		}
		else
		{
			// Not supported
		}
	}

	return displayImg;
}

template<typename T>
inline T db::WindowsDebugger::FindMax(const image::Image<T>& image)
{
	if (image.getSize() == 0)
	{
		return (T)0;
	}

	image::Image<T>::iterator img_it = image.begin();
	image::Image<T>::iterator img_end = image.end();
	T max = *image.at(0, 0);

	for (; img_it < img_end; ++img_it)
	{
		if (*img_it > max)
		{
			max = *img_it;
		}
	}

	return max;
}

template<typename T>
inline T db::WindowsDebugger::FindMin(const image::Image<T>& image)
{
	if (image.getSize() == 0)
	{
		return (T)0;
	}

	image::Image<T>::iterator img_it = image.begin();
	image::Image<T>::iterator img_end = image.end();
	T min = *image.at(0, 0);

	for (; img_it < img_end; ++img_it)
	{
		if (*img_it < min)
		{
			min = *img_it;
		}
	}

	return min;
}

#endif // !WINDOWS_DEBUGGING

#endif // !__WINDOWS_DEBUGGER__HPP_
