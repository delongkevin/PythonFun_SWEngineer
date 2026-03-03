#ifndef CAMERACFG_H
#define CAMERACFG_H

#include "Camera.h"
#include "mecl/mecl.h"

struct CameraCfg
{
	char m_CameraNameStr[50];
	char m_ProfileName[50];

	float32_t axisX;
	float32_t axisY;

    float32_t ang_alpha;
    float32_t ang_beta;
    float32_t ang_gamma;
    float32_t ang_preroll;
    float32_t deltaX;
    float32_t deltaY;
    float32_t deltaZ;
    float32_t pixelsize;
    float32_t focallength;


	Camera::CameraType_ID m_CameraType;

	Camera::LensSignatureIDs m_LensSignature;

	float32_t cylaxisX;
	float32_t cylaxisY;
	float32_t cylZoomRatioX;
	float32_t cylZoomRatioY;
	float32_t orig_x0;
	float32_t orig_y0;
	float32_t orig_x;
	float32_t orig_y; 

	//bool m_ConvertToCylinder; 
	bool m_MECLParameterLoaded;

	// define real lens (polynomials)
	mecl::model::LensRadial<float32_t, 5, 5>::Config_s m_realLensCfg;

    float32_t Virtualang_alpha;
    float32_t Virtualang_beta;
    float32_t Virtualang_gamma;
    float32_t Virtualang_preroll;
    float32_t VirtualdeltaX;
    float32_t VirtualdeltaY;
    float32_t VirtualdeltaZ;
    float32_t Virtualfocallength;
};


class ICameraCfg
{
public:
	virtual ~ICameraCfg() {}

	virtual void loadCameraCfg() = 0;

	virtual const CameraCfg& getCameraCfg() = 0;
};

#endif // !CAMERACFG_H
