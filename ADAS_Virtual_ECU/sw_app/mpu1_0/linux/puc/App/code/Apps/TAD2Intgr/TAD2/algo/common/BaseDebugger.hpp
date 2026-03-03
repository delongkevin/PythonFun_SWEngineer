// ----------------------------------------------------------------------------
// --- Written by Joshua Teichroeb [01-Aug-2019]
// --- Copyright (c) Magna Vectrics (MEVC) 2017
// ----------------------------------------------------------------------------

#ifndef __I_DEBUGGER__HPP_
#define __I_DEBUGGER__HPP_

#include "BaseDebugger.h"

#ifdef _WIN32
template<typename T>
inline void db::BaseDebugger::Plot(const char * winname, T * x, T * y, int numPoints, db::Colour colour, int shift)
{
	winname;
	x;
	y;
	numPoints;
	colour;
	shift;
}

template<typename T>
inline void db::BaseDebugger::Imshow(const char * winname, image::Image<T>& image, db::imshow_options option, T maxVal, T minVal)
{
	winname;
	image;
	option;
	maxVal;
	minVal;
}

template<typename T>
inline void db::BaseDebugger::Imshow_log(const char * winname, image::Image<T>& image, T maxVal, T minVal)
{
	winname;
	image;
	maxVal;
	minVal;
}

template<typename T, typename U>
inline void db::BaseDebugger::Imshow_segmented(const char * winname, image::Image<T>& image, image::Image<U>& thresh_low, image::Image<U>& thresh_high)
{
	winname;
	image;
	thresh_low;
	thresh_high;
}

template<typename T>
inline void db::BaseDebugger::Imshow_segmented(const char * winname, image::Image<T>& image, T thresh_low, T thresh_high)
{
	winname;
	image;
	thresh_low;
	thresh_high;
}

template<typename T>
inline void db::BaseDebugger::Imshow_threshold(const char * winname, image::Image<T>& image, T thresh, T maxVal, T minVal)
{
	winname;
	image;
	thresh;
	maxVal;
	minVal;
}

template<typename T>
inline void db::BaseDebugger::Imshow_range(const char * winname, image::Image<T>& image, T maxVal, T minVal)
{
}

template<typename T>
inline void db::BaseDebugger::Imshow_threshold_and_range(const char * winname, image::Image<T>& image, T thresh, T maxVal, T minVal)
{
	winname;
	image;
	thresh;
	maxVal;
	minVal;
}

template<typename T>
inline void db::BaseDebugger::Imshow_overlap(const char * winname, image::Image<T>& image1, image::Image<T>& image2)
{
	winname;
	image1;
	image2;
}

template<typename T>
inline void db::BaseDebugger::Imshow_templateOverlap(const char * winname, image::Image<T>& template1, image::Image<T>& template2, float32_t tmFactor)
{
	winname;
	template1;
	template2;
	tmFactor;
}
#endif // _WIN32
#endif // !__I_DEBUGGER__HPP_
