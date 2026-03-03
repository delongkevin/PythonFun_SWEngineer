
// ----------------------------------------------------------------------------
// --- Written by Sandip Suman Senapati [04-Feb-2025]
// ----------------------------------------------------------------------------
#include "OpticalFlow.h"
#include "float.h"

//#inlcude "mecl.h"


//image::Image<uint8_t>*  prevPyr_app, *nextPyr_app;

Point2f nextPts_g[NO_OF_POINTS_TO_TRACK_PER_LAYER_OF_PYRAMID];
uint8_t status_g[NO_OF_POINTS_TO_TRACK_PER_LAYER_OF_PYRAMID];
float err_g[NO_OF_POINTS_TO_TRACK_PER_LAYER_OF_PYRAMID];
int16_t data_derivBuff[global::TOPVIEW_IMAGE_SIZE];
short calclulBuf[MAXIMUM_WIDTH];
Point2f prevPtsScld[NO_OF_POINTS_TO_TRACK_PER_LAYER_OF_PYRAMID];
uint8_t temp_backup[96000];
int distanceArr[NO_OF_POINTS_TO_TRACK_PER_LAYER_OF_PYRAMID] = {0};


void locateROI( image::Image<uint8_t>img, Size2i& wholeSize, Point2i& ofs )
{
    assert( img.getNumChannels() <= 2 && img.getStep() > 0 );
    size_t esz = img.elemSize(), minstep;
    long long delta1 = img.getData() - img.datastart, delta2 = img.dataend - img.datastart;

    if( delta1 == 0 )
    {
        ofs.x = ofs.y = 0;
    }
    else
    {
        ofs.y = ( int )( delta1 / img.getStep() );
        ofs.x = ( int )( ( delta1 - img.getStep() * ofs.y ) / esz );
        assert( img.getData() == img.datastart + ofs.y * img.getStep() + ofs.x * esz );
    }

    minstep = ( ofs.x + img.getWidth() ) * esz;
    wholeSize.height = ( int )( ( delta2 - minstep ) / img.getStep() + 1 );
    wholeSize.height = max_int32( wholeSize.height, ofs.y + img.getHeight() );
    wholeSize.width = ( int )( ( delta2 - img.getStep() * ( wholeSize.height - 1 ) ) / esz );
    wholeSize.width = max_int32( wholeSize.width, ofs.x + img.getWidth() );
}
void adjustROI( image::Image<uint8_t>& img, int dtop, int dbottom, int dleft, int dright )
{
    assert( img.getNumChannels() <= 2 && img.getStep() > 0 );
    Size2i wholeSize;
    Point2i ofs;
    size_t esz = img.elemSize();
    locateROI( img, wholeSize, ofs );
    //int row1 = std::min( std::max( ofs.y - dtop, 0 ), wholeSize.height ), row2 = std::max( 0, std::min( ofs.y + rows + dbottom, wholeSize.height ) );
    //int col1 = std::min( std::max( ofs.x - dleft, 0 ), wholeSize.width ), col2 = std::max( 0, std::min( ofs.x + cols + dright, wholeSize.width ) );
    int row1 = min_int32( max_int32( ofs.y - dtop, 0 ), wholeSize.height ), row2 = max_int32( 0, min_int32( ofs.y + img.getHeight() + dbottom, wholeSize.height ) );
    int col1 = min_int32( max_int32( ofs.x - dleft, 0 ), wholeSize.width ), col2 = max_int32( 0, min_int32( ofs.x + img.getWidth() + dright, wholeSize.width ) );

    if( row1 > row2 )
    {
        //std::swap( row1, row2 );
        swap_APP( row1, row2 );
    }

    if( col1 > col2 )
    {
        swap_APP( col1, col2 );
    }

    img.setData( img.getData() + ( row1 - ofs.y ) * ( uint64_t )img.getStep() + ( col1 - ofs.x ) * ( uint64_t )esz );
    img.setHeight( row2 - row1 );
    img.setWidth( col2 - col1 );
}


int OpticalFlow::buldOpticalFlowPyramid( image::Image<uint8_t> _img, image::Image<uint8_t>( & pyramid_app )[MAX_LAYER],
        size2i winSize, int maxLevel, bool withDerivatives,
        int pyrBorder, int derivBorder, bool tryReuseInputImage )
{
    image::Image<uint8_t> img_App = _img;
    uint8_t* ds = nullptr;
    uint8_t* de = nullptr;
    assert( winSize.width > 2 && winSize.height > 2 );
    int pyrstep = withDerivatives ? 2 : 1;
    //pyramid_app = new image::Image<uint8_t>[maxLevel + 1];
    //level 0
    bool lvl0IsSet = false;

    if( !lvl0IsSet )
    {
        image::Image<uint8_t>& tempImg = pyramid_app[0];
        //cv::Mat prevImg_App_cv = cv::Mat( cv::Size( tempImg.getWidth(), tempImg.getHeight() ), CV_8UC1, tempImg.getData(), tempImg.getStep() * sizeof( uint8_t ) );

        //if( tempImg.getData() != NULL )
        //{
        //    adjustROI( tempImg, winSize.height, winSize.height, winSize.width, winSize.width );
        //}

        if( tempImg.getWidth() != static_cast<uint32_t>( winSize.width * 2 + img_App.getWidth() ) || static_cast<uint32_t>( tempImg.getHeight() != winSize.height * 2 + img_App.getHeight() ) )
        {
            int imgSize = ( winSize.width * 2 + img_App.getWidth() ) * ( winSize.height * 2 + img_App.getHeight() ) * img_App.getNumChannels();
            //uint8_t* data = new uint8_t[imgSize];
            //uint8_t data[global::TOPVIEW_IMAGE_WIDTH * global::TOPVIEW_IMAGE_HEIGHT];
            //tempImg = memory::MemoryPool::GetImage<uint8_t>( itype::IMTP_TopView_U8C1 );
            tempImg.setHeight( winSize.height * 2 + img_App.getHeight() );
            tempImg.setWidth( winSize.width * 2 + img_App.getWidth() );
            //tempImg.setData( data );
            tempImg.setStep( winSize.width * 2 + img_App.getWidth() );
            tempImg.setNumChannels( img_App.getNumChannels() );
            //uint32_t sizeofImage =
            tempImg.datastart = tempImg.getData();
            tempImg.dataend = tempImg.getData() + imgSize;
        }

        if( pyrBorder == APP_BORDER_TRANSPARENT )
        {
            //img.copyTo( temp( cv::Rect( winSize.width, winSize.height, img.cols, img.rows ) ) );
        }
        else
        {
            //copyMakeBorder( img, temp, winSize.height, winSize.height, winSize.width, winSize.width, pyrBorder );
            copyMkeBorder_8u( img_App, tempImg, winSize.height, winSize.height, winSize.width, winSize.width, pyrBorder );
        }

        //temp.adjustROI( -winSize.height, -winSize.height, -winSize.width, -winSize.width );
        adjustROI( tempImg , -winSize.height, -winSize.height, -winSize.width, -winSize.width );
    }

    size2i sz = size2i( img_App.getWidth(), img_App.getHeight() );
    image::Image<uint8_t> prevLevel_app = pyramid_app[0];
    image::Image<uint8_t> thisLevel_app = prevLevel_app;

    for( int level = 0; level <= maxLevel; ++level )
    {
        if( level != 0 )
        {
            image::Image<uint8_t>& tempImg = pyramid_app[level * pyrstep];

            //if( tempImg.getData() != NULL )
            //{
            //    //temp.adjustROI( winSize.height, winSize.height, winSize.width, winSize.width );
            //    adjustROI( tempImg, -winSize.height, -winSize.height, -winSize.width, -winSize.width );
            //}

            if( tempImg.getWidth() != static_cast<uint32_t>( winSize.width * 2 + sz.width ) || tempImg.getHeight() != static_cast<uint32_t>( winSize.height * 2 + sz.height ) )
            {
                int imgSize = ( winSize.width * 2 + sz.width ) * ( winSize.height * 2 + sz.height ) * img_App.getNumChannels();
                //uint8_t* data = new uint8_t[imgSize];
                //uint8_t data[global::TOPVIEW_IMAGE_WIDTH * global::TOPVIEW_IMAGE_HEIGHT];
                //tempImg = memory::MemoryPool::GetImage<uint8_t>( itype::IMTP_TopView_U8C1 );
                tempImg.setHeight( winSize.height * 2 + sz.height );
                tempImg.setWidth( winSize.width * 2 + sz.width );
                //tempImg.setData( data );
                tempImg.setStep( winSize.width * 2 + sz.width );
                tempImg.setNumChannels( img_App.getNumChannels() );
                tempImg.datastart = tempImg.getData();
                tempImg.dataend = tempImg.getData() + imgSize;
            }

            thisLevel_app = tempImg.subImage( winSize.width, winSize.height, sz.width, sz.height );
            pyramidDown( prevLevel_app, thisLevel_app, sz );

            if( pyrBorder != APP_BORDER_TRANSPARENT )
            {
                copyMkeBorder_8u( thisLevel_app, tempImg, winSize.height, winSize.height, winSize.width, winSize.width, pyrBorder | APP_BORDER_ISOLATED );
            }

            adjustROI( tempImg, -winSize.height, -winSize.height, -winSize.width, -winSize.width );
        }

        sz = size2i( ( sz.width + 1 ) / 2, ( sz.height + 1 ) / 2 );

        if( sz.width <= winSize.width || sz.height <= winSize.height )
        {
            return level;
        }

        prevLevel_app = thisLevel_app;
    }

    return maxLevel;
}

void ScharrDerivInvoker::sequenceOperation( const Range& range )
{
    int rows = src.getHeight(), cols = src.getWidth(), cn = src.getNumChannels(), colsn = cols * cn;
    int x, y, delta = ( int )alinSize( ( cols + 2 ) * cn, 16 );
    memset( ( void* )&calclulBuf, 0, sizeof( calclulBuf ) );
    //short* _tempBuf = new short[delta * 2 + 64];
    short* _tempBuf = calclulBuf;
    short* trow0 = alnPtr( _tempBuf + cn, 16 ), *trow1 = alnPtr( trow0 + delta, 16 );

    for( y = range.start; y < range.end; y++ )
    {
        const uint8_t* srow0 = src.ptr( y > 0 ? y - 1 : rows > 1 ? 1 : 0 );
        const uint8_t* srow1 = src.ptr( y );
        const uint8_t* srow2 = src.ptr( y < rows - 1 ? y + 1 : rows > 1 ? rows - 2 : 0 );
        short* drow = ( short* )dst.ptr( y );
        // do vertical convolution
        x = 0;

        for( ; x < colsn; x++ )
        {
            int t0 = ( srow0[x] + srow2[x] ) * 3 + srow1[x] * 10;
            int t1 = srow2[x] - srow0[x];
            trow0[x] = ( short )t0;
            trow1[x] = ( short )t1;
        }

        // make border
        int x0 = ( cols > 1 ? 1 : 0 ) * cn, x1 = ( cols > 1 ? cols - 2 : 0 ) * cn;

        for( int k = 0; k < cn; k++ )
        {
            trow0[-cn + k] = trow0[x0 + k];
            trow0[colsn + k] = trow0[x1 + k];
            trow1[-cn + k] = trow1[x0 + k];
            trow1[colsn + k] = trow1[x1 + k];
        }

        // do horizontal convolution, interleave the results and store them to dst
        x = 0;

        for( ; x < colsn; x++ )
        {
            short t0 = ( short )( trow0[x + cn] - trow0[x - cn] );
            short t1 = ( short )( ( trow1[x + cn] + trow1[x - cn] ) * 3 + trow1[x] * 10 );
            drow[x * 2] = t0;
            drow[x * 2 + 1] = t1;
        }
    }

    //delete[] _tempBuf;
    //_tempBuf = nullptr;
}

LKTrackerInvoker::LKTrackerInvoker(
    const image::Image<uint8_t>& _prevImg_App,  const image::Image<int16_t>& _prevDeriv, const image::Image<uint8_t>& _nextImg,
    const Point2f* _prevPts, Point2f* _nextPts,
    uint8_t* _status, float* _err,
    size2i _winSize, TermCriteria _criteria,
    int _level, int _maxLevel, int _flags, float _minEigThreshold )
{
    prevImg_App = _prevImg_App;
    dervI_App = _prevDeriv;
    nextImg_App = _nextImg;
    prevPts = _prevPts;
    nextPts = _nextPts;
    status = _status;
    err = _err;
    winSize = _winSize;
    criteria = _criteria;
    level = _level;
    maxLevel = _maxLevel;
    flags = _flags;
    minEigThreshold = _minEigThreshold;
}

void LKTrackerInvoker::sequenceOperation( const Range& range )
{
    const int W_BITS = 14, W_BITS1 = 14;
    const float FLT_SCALE = 1.f / ( 1 << 20 );
    Point2f halfWin( ( winSize.width - 1 ) * 0.5f, ( winSize.height - 1 ) * 0.5f );
    //Point2f* prevPtsScld = new Point2f[global::TOPVIEW_IMAGE_SIZE];
    memset( ( void* )&prevPtsScld, 0, sizeof( prevPtsScld ) );
    int j, cn = prevImg_App.getNumChannels(), cn2 = cn * 2;
    //short* winArr = new short[winSize.width * winSize.height * cn];
    //short* derwinArr = new short[winSize.width * winSize.height * cn2];
    short winArr[WIN_SIZE * WIN_SIZE * SINGLE_CHANNEL];
    short derwinArr[WIN_SIZE * WIN_SIZE * DOUBLE_CHANNEL];

    for( int ptidx = range.start; ptidx < range.end; ptidx++ )
    {
        Point2f prevPt = Point2f( prevPts[ptidx].x * ( float )( 1. / ( 1 << level ) ), prevPts[ptidx].y * ( float )( 1. / ( 1 << level ) ) );
        Point2f nextPt;

        if( level == maxLevel )
        {
            if( flags & APP_OPTFLOW_USE_INITIAL_FLOW )
            {
                nextPt = Point2f( nextPts[ptidx].x * ( float )( 1. / ( 1 << level ) ), nextPts[ptidx].y * ( float )( 1. / ( 1 << level ) ) );
            }
            else
            {
                nextPt = prevPt;
            }
        }
        else
        {
            nextPt = Point2f( nextPts[ptidx].x * 2.f, nextPts[ptidx].y * 2.f );
        }

        nextPts[ptidx] = Point2f( nextPt.x, nextPt.y );
        prevPtsScld[ptidx - range.start] = prevPt;
    }

    for( int ptidx = range.start; ptidx < range.end; ptidx++ )
    {
        Point2f prevPt = prevPtsScld[ptidx - range.start];
        Point2i iprevPt, inextPt;
        prevPt -= halfWin;
        iprevPt.x = floor( prevPt.x );
        iprevPt.y = floor( prevPt.y );

        if( static_cast<int16_t>( iprevPt.x ) < -1 * ( static_cast<int16_t>( winSize.width ) ) || static_cast<int16_t>( iprevPt.x ) >= static_cast<int16_t>( dervI_App.getWidth() ) ||
            static_cast<int16_t>( iprevPt.y ) < -1 * ( static_cast<int16_t>( winSize.height ) ) || static_cast<int16_t>( iprevPt.y ) >= static_cast<int16_t>( dervI_App.getHeight() ) )
        {
            if( level == 0 )
            {
                status[ptidx] = false;

                if( err )
                {
                    err[ptidx] = 0;
                }
            }

            continue;
        }

        float a = prevPt.x - iprevPt.x;
        float b = prevPt.y - iprevPt.y;
        int iw00 = round( ( 1.f - a ) * ( 1.f - b ) * ( 1 << W_BITS ) );
        int iw01 = round( a * ( 1.f - b ) * ( 1 << W_BITS ) );
        int iw10 = round( ( 1.f - a ) * b * ( 1 << W_BITS ) );
        int iw11 = ( 1 << W_BITS ) - iw00 - iw01 - iw10;
        int dstep = ( int )( dervI_App.getStep() );
        int stepI = ( int )( prevImg_App.getStep() );
        int stepJ = ( int )( nextImg_App.getStep() );
        float iA11 = 0, iA12 = 0, iA22 = 0;
        float A11, A12, A22;
        // extract the patch from the first image, compute covariation matrix of derivatives
        int x, y;

        for( y = 0; y < winSize.height; y++ )
        {
            //const uchar* src = I.ptr() + ( y + iprevPt.y ) * stepI + iprevPt.x * cn;
            uint8_t* src = prevImg_App.getData() + ( y + iprevPt.y ) * stepI + iprevPt.x * cn;
            const short* dsrc = ( short* )dervI_App.getData() + ( y + iprevPt.y ) * dstep + iprevPt.x * cn2;
            //short* Iptr = IWinBuf.ptr<short>( y );
            //short* dIptr = derivIWinBuf.ptr<short>( y );
            short* Iptr = winArr + y * winSize.width;
            short* dIptr = derwinArr + y * winSize.width * 2;
            x = 0;

            for( ; x < winSize.width * cn; x++, dsrc += 2, dIptr += 2 )
            {
                int ival = CV_DESCALE( src[x] * iw00 + src[x + cn] * iw01 +
                                       src[x + stepI] * iw10 + src[x + stepI + cn] * iw11, W_BITS1 - 5 );
                int ixval = CV_DESCALE( dsrc[0] * iw00 + dsrc[cn2] * iw01 +
                                        dsrc[dstep] * iw10 + dsrc[dstep + cn2] * iw11, W_BITS1 );
                int iyval = CV_DESCALE( dsrc[1] * iw00 + dsrc[cn2 + 1] * iw01 + dsrc[dstep + 1] * iw10 +
                                        dsrc[dstep + cn2 + 1] * iw11, W_BITS1 );
                Iptr[x] = ( short )ival;
                dIptr[0] = ( short )ixval;
                dIptr[1] = ( short )iyval;
                iA11 += ( float )( ixval * ixval );
                iA12 += ( float )( ixval * iyval );
                iA22 += ( float )( iyval * iyval );
            }
        }

        A11 = iA11 * FLT_SCALE;
        A12 = iA12 * FLT_SCALE;
        A22 = iA22 * FLT_SCALE;
        float D = A11 * A22 - A12 * A12;
        float minEig = ( A22 + A11 - sqrt_newton( ( A11 - A22 ) * ( A11 - A22 ) +
                         4.f * A12 * A12 ) ) / ( 2 * winSize.width * winSize.height );

        if( err && ( flags & APP_OPTFLOW_LK_GET_MIN_EIGENVALS ) != 0 )
        {
            err[ptidx] = ( float )minEig;
        }

        if( minEig < minEigThreshold || D < FLT_EPSILON )
        {
            if( level == 0 )
            {
                status[ptidx] = false;
            }

            continue;
        }

        D = 1.f / D;
        Point2f nextPt = Point2f( nextPts[ptidx].x - halfWin.x, nextPts[ptidx].y - halfWin.y );
        Point2f prevDelta;

        for( j = 0; j < criteria.maxCount; j++ )
        {
            inextPt.x = floor( nextPt.x );
            inextPt.y = floor( nextPt.y );

            if( static_cast<int16_t>( inextPt.x ) < static_cast<int16_t>( -winSize.width ) || static_cast<int16_t>( inextPt.x ) >= static_cast<int16_t>( nextImg_App.getWidth() ) ||
                static_cast<int16_t>( inextPt.y ) < static_cast<int16_t>( -winSize.height ) || static_cast<int16_t>( inextPt.y ) >= static_cast<int16_t>( nextImg_App.getHeight() ) )
            {
                if( level == 0 )
                {
                    status[ptidx] = false;
                }

                break;
            }

            a = nextPt.x - inextPt.x;
            b = nextPt.y - inextPt.y;
            iw00 = round( ( 1.f - a ) * ( 1.f - b ) * ( 1 << W_BITS ) );
            iw01 = round( a * ( 1.f - b ) * ( 1 << W_BITS ) );
            iw10 = round( ( 1.f - a ) * b * ( 1 << W_BITS ) );
            iw11 = ( 1 << W_BITS ) - iw00 - iw01 - iw10;
            float ib1 = 0, ib2 = 0;
            float b1, b2;

            for( y = 0; y < winSize.height; y++ )
            {
                const uint8_t* Jptr = nextImg_App.getData() + ( y + inextPt.y ) * stepJ + inextPt.x * cn;
                //const short* Iptr = IWinBuf.ptr<short>( y );
                //const short* dIptr = derivIWinBuf.ptr<short>( y );
                short* Iptr = winArr + y * winSize.width;
                short* dIptr = derwinArr + y * winSize.width * 2;
                x = 0;

                for( ; x < winSize.width * cn; x++, dIptr += 2 )
                {
                    int diff = CV_DESCALE( Jptr[x] * iw00 + Jptr[x + cn] * iw01 +
                                           Jptr[x + stepJ] * iw10 + Jptr[x + stepJ + cn] * iw11,
                                           W_BITS1 - 5 ) - Iptr[x];
                    ib1 += ( float )( diff * dIptr[0] );
                    ib2 += ( float )( diff * dIptr[1] );
                }
            }

            b1 = ib1 * FLT_SCALE;
            b2 = ib2 * FLT_SCALE;
            Point2f delta( ( float )( ( A12 * b2 - A22 * b1 ) * D ),
                           ( float )( ( A12 * b1 - A11 * b2 ) * D ) );
            //delta = -delta;
            nextPt += delta;
            nextPts[ptidx] = Point2f( nextPt.x + halfWin.x, nextPt.y + halfWin.y );

            if( delta.ddot( delta ) <= criteria.epsilon )
            {
                break;
            }

            if( j > 0 && mecl::math::abs_x( delta.x + prevDelta.x ) < 0.01 &&
                mecl::math::abs_x( delta.y + prevDelta.y ) < 0.01 )
            {
                nextPts[ptidx] -= Point2f( delta.x * 0.5f, delta.y * 0.5f );
                break;
            }

            prevDelta = delta;
        }

        if( status[ptidx] && err && level == 0 && ( flags & APP_OPTFLOW_LK_GET_MIN_EIGENVALS ) == 0 )
        {
            Point2f nextPoint = Point2f( nextPts[ptidx].x - halfWin.x, nextPts[ptidx].y - halfWin.y );
            Point2i inextPoint;
            inextPoint.x = floor( nextPoint.x );
            inextPoint.y = floor( nextPoint.y );

            //if( inextPoint.x < -winSize.width || inextPoint.x >= nextImg_App.getWidth() ||
            //    inextPoint.y < -winSize.height || inextPoint.y >= nextImg_App.getHeight() )
            /* we don't want to track the image points till image border, that is why remove previous conditions*/
            if( static_cast<int16_t>( inextPoint.x ) < static_cast<int16_t>( -winSize.width ) || static_cast<int16_t>( inextPoint.x ) >= static_cast<int16_t>( nextImg_App.getWidth() - 2 * winSize.width ) ||
                static_cast<int16_t>( inextPoint.y ) < static_cast<int16_t>( - winSize.height ) || static_cast<int16_t>( inextPoint.y ) >= static_cast<int16_t>( nextImg_App.getHeight() - 2 * winSize.height ) )
            {
                status[ptidx] = false;
                continue;
            }

            float aa = nextPoint.x - inextPoint.x;
            float bb = nextPoint.y - inextPoint.y;
            iw00 = round( ( 1.f - aa ) * ( 1.f - bb ) * ( 1 << W_BITS ) );
            iw01 = round( aa * ( 1.f - bb ) * ( 1 << W_BITS ) );
            iw10 = round( ( 1.f - aa ) * bb * ( 1 << W_BITS ) );
            iw11 = ( 1 << W_BITS ) - iw00 - iw01 - iw10;
            float errval = 0.f;

            for( y = 0; y < winSize.height; y++ )
            {
                const uint8_t* Jptr = nextImg_App.getData() + ( y + inextPoint.y ) * stepJ + inextPoint.x * cn;
                //const short* Iptr = IWinBuf.ptr<short>( y );
                short* Iptr = winArr + y * winSize.width;

                for( x = 0; x < winSize.width * cn; x++ )
                {
                    int diff = CV_DESCALE( Jptr[x] * iw00 + Jptr[x + cn] * iw01 +
                                           Jptr[x + stepJ] * iw10 + Jptr[x + stepJ + cn] * iw11,
                                           W_BITS1 - 5 ) - Iptr[x];
                    errval += mecl::math::abs_x( ( float )diff );
                }
            }

            err[ptidx] = errval * 1.f / ( 32 * winSize.width * cn * winSize.height );
        }
    }

    //delete[] prevPtsScld;
    //prevPtsScld = nullptr;
    //delete[] winArr;
    //winArr = nullptr;
    //delete[] derwinArr;
    //derwinArr = nullptr;
}

void OpticalFlow::calcScharrDeriv( image::Image<uint8_t>& src, image::Image<int16_t>& dst )
{
    int rows = src.getHeight(), cols = src.getWidth(), cn = src.getNumChannels()/*, depth = src.depth()*/;
    ScharrDerivInvoker sc( src ,  dst );
    sc.sequenceOperation( Range( 0, rows ) );
}

void OpticalFlow::lkopticalFlowCalc( image::Image<uint8_t> _prevImg, image::Image<uint8_t> _nextImg,
                                     Point2f* _prevPts, Point2f*& _nextPts, uint32_t featureSize,
                                     uint8_t*& _status, float*& _err,
                                     size2i winSize, int maxLevel,
                                     int flags, double minEigThreshold )
{
    const int derivDepth = 3;
    assert( maxLevel >= 0 && winSize.width > 2 && winSize.height > 2 );
    int16_t level = 0, i, npoints;
    //assert( featureSize >= 0 );
    _nextImg.datastart = _nextImg.getData();
    _nextImg.dataend = _nextImg.getData() + _nextImg.getHeight() * _nextImg.getWidth();

    if( featureSize == 0 )
    {
        return;
    }

    if( !( flags & APP_OPTFLOW_USE_INITIAL_FLOW ) )
    {
        //_nextPts = new Point2f[featureSize];
        _nextPts = nextPts_g;
    }

    const Point2f* prevPts = _prevPts;
    Point2f* nextPts = _nextPts;
    //_status = new uchar[featureSize];
    _status = status_g;
    uint8_t* status = _status;
    float* err = nullptr;

    for( i = 0; i < static_cast<int16_t>( featureSize ); i++ )
    {
        status[i] = true;
    }

    if( true )
    {
        //_err = new float[featureSize];
        _err = err_g;
        err = _err;
    }

    int levels1 = -1;
    int lvlStep1 = 1;
    int levels2 = -1;
    int lvlStep2 = 1;
    TermCriteria criteria;
    //image::Image<uint8_t>  prevPyr_app[MAX_LAYER], nextPyr_app[MAX_LAYER];

    for( int i = 0; i <= maxLevel; i++ )
    {
        prevPyr_app[i] = memory::MemoryPool::GetImage<uint8_t>( itype::IMTP_TopView_U8C1 );
        nextPyr_app[i] = memory::MemoryPool::GetImage<uint8_t>( itype::IMTP_TopView_U8C1 );
    }

    if( levels1 < 0 )
    {
        maxLevel = buldOpticalFlowPyramid( _prevImg, prevPyr_app, winSize, maxLevel, false );
    }

    if( levels2 < 0 )
    {
        //cv::Mat nImage = processing::ImageProcessing::ConvertToCV( _nextImg );
        maxLevel = buldOpticalFlowPyramid( _nextImg, nextPyr_app, winSize, maxLevel, false );
    }

    criteria.type = 3;
    criteria.maxCount = 30;
    criteria.epsilon = 0.0001;
    // dI/dx ~ Ix, dI/dy ~ Iy
    //int16_t* data_derivBuff;

    //if( lvlStep1 == 1 )
    //{
    //    data_derivBuff = new int16_t[( prevPyr_app[0].getHeight() + winSize.height * 2 ) * ( prevPyr_app[0].getWidth() + winSize.width * 2 ) * 2];
    //}

    for( level = maxLevel; level >= 0; level-- )
    {
        image::Image<int16_t> dervI_App;
        image::Image<uint8_t> prevImg_App;
        image::Image<uint8_t> nextImg_App;
        prevImg_App = prevPyr_app[level * lvlStep1];
        nextImg_App = nextPyr_app[level * lvlStep1];
        //cv::Mat prevImg_App_cv = cv::Mat( cv::Size( prevImg_App.getWidth(), prevImg_App.getHeight() ), CV_8UC1, prevImg_App.getData(), prevImg_App.getStep() * sizeof( uint8_t ) );

        if( lvlStep1 == 1 )
        {
            image::Image<int16_t> _dervI_App = image::Image<int16_t>( prevImg_App.getWidth() + winSize.width * 2,
                                               prevImg_App.getHeight() + winSize.height * 2, data_derivBuff, 2 );
            dervI_App = _dervI_App.subImage( winSize.width, winSize.height, prevImg_App.getWidth(), prevImg_App.getHeight() );
            calcScharrDeriv( prevImg_App, dervI_App );
            copyMkeBorder_16u( dervI_App, _dervI_App, winSize.height, winSize.height, winSize.width, winSize.width, APP_BORDER_CONSTANT | APP_BORDER_ISOLATED );
        }

        //assert(prevPyr_app[level * lvlStep1].size() == nextPyr_app[level * lvlStep2].size() );
        //assert( prevPyr[level * lvlStep1].type() == nextPyr[level * lvlStep2].type() );
        LKTrackerInvoker templkInvoker = LKTrackerInvoker( prevImg_App, dervI_App,
                                         nextImg_App, prevPts, nextPts,
                                         status, err,
                                         winSize, criteria, level, maxLevel,
                                         flags, ( float )minEigThreshold );
        templkInvoker.sequenceOperation( Range( 0, featureSize ) );
        memory::MemoryPool::ReleaseImage( dervI_App );
    }

    //cv::Mat prevImg_App_cv = cv::Mat( cv::Size( _nextImg.getWidth(), _nextImg.getHeight() ), CV_8UC1, _nextImg.getData(), _nextImg.getStep() * sizeof( uint8_t ) );
    bool check = _nextImg.datastart < prevPyr_app[0].dataend && prevPyr_app[0].datastart < _nextImg.dataend;
    //bool check = nextPyr_app[0].datastart < prevPyr_app[0].dataend && prevPyr_app[0].datastart < nextPyr_app[0].dataend;
    memset( ( void* )&temp_backup, 0, sizeof( temp_backup ) );
    memcpy( temp_backup, _nextImg.getData(), sizeof( temp_backup ) );

    for( int i = 0; i <= maxLevel; i++ )
    {
        memory::MemoryPool::ReleaseImage( prevPyr_app[i] );
        memory::MemoryPool::ReleaseImage( nextPyr_app[i] );
        memcpy( _nextImg.getData(), temp_backup, sizeof( temp_backup ) );
    }

    //delete[] data_derivBuff;
    //data_derivBuff = nullptr;
}

OpticalFlow::OpticalFlow():
    m_initOK( false ),
    m_isRunning( false ),
    m_lastFrameRun( 0 )
{
}

OpticalFlow::~OpticalFlow()
{
}

template <typename T>
void OpticalFlow::mySwap( T& a, T& b )
{
    T temp = a;
    a = b;
    b = temp;
}

bool OpticalFlow::compareIntegersDescending( int a, int b )
{
    return a > b;
}
template <typename T>
void OpticalFlow::genericSort( T arr[], int n )
{
    for( int i = 0; i < n - 1; ++i )
    {
        for( int j = 0; j < n - i - 1; ++j )
        {
            if( compareIntegersDescending( arr[j], arr[j + 1] ) )
            {
                // Use custom swap function
                mySwap( arr[j], arr[j + 1] );
            }
        }
    }
}

void OpticalFlow::Run( image::Image<uint8_t> _prevImg, image::Image<uint8_t> _nextImg, Point2f* _prevPts, Point2f*& _nextPts, uint32_t featureSize, uint8_t*& _status, float*& _err )
{
    static int32_t count = 0, totalDistant = 0, intialFeatureSize = featureSize;
    static Point2f* intialFeaturePoints = nullptr;

    if( count == 0 )
    {
        intialFeaturePoints = _prevPts;
    }

    lkopticalFlowCalc( _prevImg, _nextImg, _prevPts, _nextPts, featureSize, _status, _err );
    int16_t tempDistant = 0, meanDistance = 0;
    memset( ( void* )&distanceArr, 0, sizeof( distanceArr ) );

    for( int16_t featureIndex = 0; featureIndex < static_cast<int16_t>( featureSize ); featureIndex++ )
    {
        //tempDistant = MIN( tempDistant , _nextPts[featureIndex].x - intialFeaturePoints[featureIndex].x );
        tempDistant = _nextPts[featureIndex].x - intialFeaturePoints[featureIndex].x;
        distanceArr[featureIndex] = tempDistant;
    }

    genericSort( distanceArr, featureSize );
    meanDistance = distanceArr[featureSize / 2] /*/ featureSize*/;
    totalDistant = totalDistant + meanDistance;

    if( count > FRAME_THRESHOLD )
    {
        if( totalDistant > DISTANT_THRESHOLD_INPIXEL )
        {
            for( int16_t featureIndex = 0; featureIndex < static_cast<int16_t>( featureSize ); featureIndex++ )
            {
                _status[featureIndex] = false;
            }
        }

        intialFeatureSize = featureSize;
        totalDistant = 0;

        for( int i = 0; i < NO_OF_POINTS_TO_TRACK_PER_LAYER_OF_PYRAMID; i++ )
        {
            distanceArr[i] = 0;
        }

        count = 0;
    }

    count = count + 1;

    if( intialFeatureSize < static_cast<int32_t>( featureSize ) )
    {
        count = 0;
        intialFeatureSize = featureSize;
        totalDistant = 0;

        for( int i = 0; i < NO_OF_POINTS_TO_TRACK_PER_LAYER_OF_PYRAMID; i++ )
        {
            distanceArr[i] = 0;
        }
    }
}

bool_t OpticalFlow::Init()
{
    m_initOK = true;
    return true;
}

bool_t OpticalFlow::Start()
{
    bool_t returnValue = false;

    if( m_initOK )
    {
        if( m_isRunning )
        {
            Finish();
        }

        m_isRunning = true;
        returnValue = true;
    }

    return returnValue;
}

void OpticalFlow::Finish()
{
    m_isRunning = false;
}
