// ----------------------------------------------------------------------------
// --- written by X.Phan [28-JUN-2012]
// --- Copyright (c) Magna Vectrics (MEVC) 2012
// ----------------------------------------------------------------------------
// --- Camera.h - Camera related parameter struct/methods.
// ----------------------------------------------------------------------------

#ifndef CAMERA_H
#define CAMERA_H

// --- never include stdafx.h in the include file, since the path determined by the
// --- compiler when this file is included in a different project may conflict
// --- with the project types (especially with MFC and Non-MFC projects)
// --- #include "stdafx.h"

#include "CameraPoint.h"
#include "mecl/mecl.h"

const int32_t REAR_SCALE_SIZE1 = 800;

class do_CameraParam;
struct CameraCfg;
class ICameraCfg;
namespace cameranew {
	void Degree2Radian(float32_t &a);
}
enum Camera_ID
{
	Front = 0,
	Rear = 1,
	Left = 2,
	Right = 3,
	NUM_SVS_CAM = 4,
	MLeft = 4,
	MRight = 5,
	Windshield = 6,
	Ultrasonic = 7,
	Radar = 8,
	MAX_CameraID
} ;

//-------------------------------------------------------------------------
// Camera parameters
class Camera
{
public:
	typedef enum CameraType_ID
	{
		Cam_SVS = 0,
		Zurich_Rear = 1,
		Zurich_Side = 2,
		Zurich_Mirror = 3,
		Zurich_Lite = 4,
		Zurich_HD = 5,
		Cylinder = 6,      // obsoleted, use 8 instead
		MECL_Radial = 7,
		MECL_Cylinder = 8,
		Cylinder_VarScale = 9,
		Top_View = 10,
		MECL_Normal=11,
		MAX_CameraType_ID
	} CameraType_t;

    typedef enum LensSignatureIDs
    {
        LSI_None=0,
		LSI_4063	= 1, 
		BEV_LENS	= 2, 
		LSI_4086    = 3,
		MAX_LensSignature_ID
	} LensSignature_t;

	Camera()
		: m_CameraType(MECL_Radial)
		, downsamp_sensor(1.0f, 1.0f)
		, m_ProfileName("NOT_INITIALIZED")
		, m_ConvertToCylinder(false)
		, m_CamOrientation(Front)

	{};
	~Camera();
    char m_CameraNameStr[ 50 ];
	CameraType_t m_CameraType;
	mecl::model::ImageOriginPosition_e sensorOrientation;
	// LensSignature to be remove once camera model fully aligned
	LensSignatureIDs m_LensSignature;
	
	Point2f downsamp_sensor;

	inline float32_t getFocalLength(void) { return m_realPinhole.getIntrinsic_rs().foclX_x; } //focallength
	inline float32_t getOrigX(void) const { return m_realSensor.getLowerRight_x().getPosX(); } //orig_x
	inline float32_t getOrigY(void) const { return m_realSensor.getLowerRight_x().getPosY(); } //orig_y
	inline float32_t getAxisX(void) const { return m_realSensor.getPpp_rx().getPosX(); } //axisX
	inline float32_t getAxisY(void) const { return m_realSensor.getPpp_rx().getPosY(); } //axisY
	inline Camera_ID getOrientation() const { return m_CamOrientation; }

	float32_t getPitch(bool_t inDegrees = true) const;	//ang_alpha
	float32_t getYaw(bool_t inDegrees = true) const;	//ang_beta
	float32_t getRoll(bool_t inDegrees = true) const;	//ang_gamma
	float32_t getPreRoll(bool_t inDegrees = true) const;//ang_preroll
	bool_t isRollIn14Quadrants(void) const;
	bool_t isRollIn23Quadrants(void) const;

	inline float32_t getDeltaX(void) const { return m_realPinhole.getExtrinsic_rs().pos_x.cVal_ax[0]; } //deltaX
	inline float32_t getDeltaY(void) const { return (m_realPinhole.getExtrinsic_rs().pos_x.cVal_ax[1]); } //deltaY
	inline float32_t getDeltaZ(void) const { return m_realPinhole.getExtrinsic_rs().pos_x.cVal_ax[2]; } //deltaZ
	inline float32_t getPixelSize(void) const { return m_realSensor.getPsz_rx().getPosX(); } //pixelsize
	Point2f World2CamDisPt(Point2f worldPt)const;
	Point2f Cam2WorldDisPt(Point2f worldPt)const;

    char m_ProfileName[50];
    bool m_ConvertToCylinder;
	unsigned char *GetCameraCfg( unsigned int &cfgSz );
	void UpdateCameraCfg(const CameraCfg* camCfg);
private:
	bool m_MECLParameterLoaded;
	Camera_ID m_CamOrientation;
	unsigned char m_CameraCfg[400];
public:
	struct cylZoomArgs
	{
		float ppx;
		float ppy;
		float zoomX;
		float zoomY;
	};
	struct normalArgs
	{
		float x, y, z;
		float alpha_deg;
	};
	struct CamParamsSet
	{
		CameraType_t camType;
		union
		{
			cylZoomArgs cyl;
			normalArgs norm;
		};
	};

	Point2f pixel_warp( Point2f& pt );
    Point2f pixel_unwarp(const Point2f *pPtInput);
	static Point2f unwarped_distance(const Point2f& unwarpedPt, const float32_t i_P[3][4]);
	Point2f unwarped_distance(const Point2f& unwarpedPt, bool unwarp = false);
	Point2f unwarped_distanceVirtual(const Point2f& unwarpedPt)const;

	//bool Init(unsigned int imgW, unsigned imgH, do_CameraParam& CamIfo, const CameraCfg* camCfg = NULL, char *pCameraName = NULL, const char *pCamProfileName = NULL, unsigned long hTracer = 0,
	//	float ppX = 0.0f, float ppY = 0.0f, float zoomX = 0.0f, float zoomY = 0.0f, CameraType_t cameratypeID = MAX_CameraType_ID, int converttovirtual = -1);
	bool Init(unsigned int imgW, 
		unsigned int imgH, 
		do_CameraParam& CamIfo, 
		CameraType_t cameratypeID, // ::Cam_SVS,		
		const CameraCfg* camCfg			
		);//pSetting should be removed 
	void dumpCamParam4Embedded(do_CameraParam camParam);

    void ApplyDistortion_MECL(float32_t *b_X_pf32, float32_t *b_Y_pf32)const;
    void ApplyDistortion_MECL_Virtual(float32_t *b_X_pf32, float32_t *b_Y_pf32)const;
    void Radial2CylinderConversion(float32_t *b_X_pf32, float32_t *b_Y_pf32);
    void ApplyTransformation( float32_t *io_x, float32_t *io_y, bool direction );
    void ApplyUndistortion_MECL(float32_t *b_X_pf32, float32_t *b_Y_pf32)const;
    void ApplyUndistortion_MECL_Virtual(float32_t *b_X_pf32, float32_t *b_Y_pf32)const;
    void Virtual2RadialConversion(float32_t *b_X_pf32, float32_t *b_Y_pf32);
	void CreateCameraMatricesMECL(float32_t P_MECL[3][4])const;
	void SetNormal(CamParamsSet *pSetting, const CameraCfg* camCfg);
	// MECL lens model
    // create model instances for real camera and components
    mecl::model::Sensor<float32_t> m_realSensor;
    mecl::model::LensRadial<float32_t, 5, 5> m_realLens;
    mecl::model::Pinhole<float32_t> m_realPinhole;
    mecl::model::Camera<float32_t> m_realCam;
    
    // create instances for Cylinder camera and components
    mecl::model::Sensor<float32_t> m_VirtualSensor;
    mecl::model::LensCylinder<float32_t> m_CylinderLens;
    mecl::model::Pinhole<float32_t> m_VirtualPinhole;
    mecl::model::Camera<float32_t> m_virtualCam;

    // create Single view instance yielding the projective model
    mecl::model::SingleView<float32_t> m_singleView;

    // create an instance for the Variable Scale CylinderModel
 //   mecl::model::SensorVarScale<float32_t, mecl::model::e_VarScaleY> m_VarScaleCylinderLens;
} ;

// ----------------------------------------------------------------------------
class do_CameraParam
{
public:

    // --- camera intrinsic & extrinsic parameters ---
    Camera_ID camera_id;
    Camera camera_param;

    // --- projection matrix for real and virtual cameras ---
	float32_t P_MECL[3][4];

	// --- Configuration data for virtual Camera ---
	int VirtualImageX;
	int VirtualImageY;
	float32_t VirtualaxisX;
	float32_t VirtualaxisY;
	float32_t Virtualang_alpha;
	float32_t Virtualang_beta;
	float32_t Virtualang_gamma;
	float32_t Virtualang_preroll;
	float32_t VirtualdeltaX;
	float32_t VirtualdeltaY;
	float32_t VirtualdeltaZ;
	float32_t Virtualpixelsize;
	float32_t Virtualfocallength;

    // --- initializer
    do_CameraParam()
    {
		memset(P_MECL, 0, sizeof(P_MECL));
    }

	bool SetCameraID(char *pCameraNameStr);

	// move projection functions in side of CameraModel?
	Point2f ProjectTo2D( const Point3f& pt, bool warp = false, bool *warpError = 0);
	Point2f ProjectTo2DVirtual(const Point3f& pt)const;
	Point2f ProjectTo2D(const Point3f& pt, const float32_t i_P[3][4], bool warp = false);
	Point3f BackProjectTo3D( const Point2f& pt, bool unwarp = false );
	void UpDateVirtualCamera(void);//virtual
	void GenerateVirtualLUT(float32_t *pMapx, float32_t *pMapy); // move to do camera params
	// used for Projection on P Matrix
	static void MatrixMultiple(const float32_t *pKernel, const float32_t *pKarmaVector, float32_t *pOutput);
	void dumpCamParam4Embedded(do_CameraParam camParam);
};

#endif //#ifndef CAMERA_H
