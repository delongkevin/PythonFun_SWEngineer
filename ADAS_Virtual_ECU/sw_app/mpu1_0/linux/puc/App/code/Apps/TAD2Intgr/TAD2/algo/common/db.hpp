// ----------------------------------------------------------------------------
// --- Written by Joshua Teichroeb [17-Jan-2019]
// --- Last Modified by Joshua Teichroeb [02-Aug-2019]
// --- Copyright (c) Magna Vectrics (MEVC) 2017
// ----------------------------------------------------------------------------

#ifndef __DB__HPP_
#define __DB__HPP_

#include "Defines.h"
#include "db.h"

#ifdef WINDOWS_DEBUGGING
	#include "WindowsDebugger.h"
	extern db::WindowsDebugger* g__pDebugger;
#else
	#include "BaseDebugger.h"
	extern db::BaseDebugger* g__pDebugger;
#endif

///------------------------------------------------------------------------------
/// Logic for the debugging library is placed in a separate class so that
/// if certain libraries were to be disabled (e.g. if OpenCV or std libraries
/// were to be removed), then we can simply switch to an implementation which
/// does not use these libraries.
///
/// There is no interface for this implementation class due to the fact that some
/// of the functions are template functions (virtual template functions are not
/// yet supported in C++), however, this library serves as a reference and any
/// implementation of the "debugger" class should implement all the functions in
/// this library, with the exception of "init()", "uninit()", and "isRunning()".
/// ------------------------------------------------------------------------------
#ifdef _WINDOWS_
template<typename T>
void db::plot(const char* winname, T* x, T* y, int numPoints, Colour colour, int shift)
{
	if (isRunning())
	{
		g__pDebugger->Plot( winname, x, y,  numPoints, colour, shift);
	}
}

template<typename T>
void db::imshow(const char* winname, image::Image<T> image, imshow_options option, T maxVal, T minVal)
{
	if (isRunning())
	{
		g__pDebugger->Imshow(winname,  image,  option, maxVal,  minVal);
	}
}

template<typename T, typename U>
void db::imshow_segmented(const char* winname, image::Image<T> image, image::Image<U> thresh_low, image::Image<U> thresh_high)
{
	if (isRunning())
	{
		g__pDebugger->Imshow_segmented(winname, image, thresh_low, thresh_high);
	}
}

template<typename T>
void db::imshow_segmented(const char* winname, image::Image<T> image, T thresh_low, T thresh_high)
{
	if (isRunning())
	{
		g__pDebugger->Imshow_segmented(winname, image, thresh_low, thresh_high);
	}
}

template<typename T>
void db::imshow_overlap(const char* winname, image::Image<T> image1, image::Image<T> image2)
{
	if (isRunning())
	{
		g__pDebugger->Imshow_overlap(winname, image1, image2);
	}
}

template<typename T>
void db::imshow_templateOverlap(const char* winname, image::Image<T> template1, image::Image<T> template2, float32_t tmFactor)
{
	if (isRunning())
	{
		g__pDebugger->Imshow_templateOverlap(winname, template1, template2, tmFactor);
	}
}

template<typename T>
void db::imshow_threshold(const char * _winname, image::Image<T> _image, T _thresh, T _maxVal, T _minVal)
{
	if (isRunning())
	{
		g__pDebugger->Imshow_threshold(_winname, _image, _thresh, _maxVal, _minVal);
	}
}

template<typename T>
void db::imshow_range(const char * winname, image::Image<T> image, T maxVal, T minVal)
{
	if (isRunning())
	{
		g__pDebugger->Imshow_range(winname, image, maxVal, minVal);
	}
}

template<typename T>
void db::imshow_threshold_and_range(const char * _winname, image::Image<T> _image, T _thresh, T _maxVal, T _minVal)
{
	if (isRunning())
	{
#ifdef __QNX__
		g__pDebugger->Imshow_threshold_and_range(_winname, _image, _thresh, _maxVal, _minVal);
#else
		g__pDebugger->Imshow_threshold_and_range(winname, _image, _thresh, _maxVal, _minVal);
#endif
	}
}

#endif //!__DB__HPP_

#endif //_WINDOWS_
