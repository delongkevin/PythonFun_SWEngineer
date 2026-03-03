// ----------------------------------------------------------------------------
// --- Written by Joshua Teichroeb [03-Apr-2019]
// --- Last Modified by Joshua Teichroeb [03-Apr-2019]
// --- Copyright (c) Magna Vectrics (MEVC) 2017
// ----------------------------------------------------------------------------

#ifndef __FO__H_
#define __FO__H_

#include "Defines.h"
#ifdef DIAGNOSTICS
#include "FileOutput.h"
#include "Image.h"

#ifdef ENABLE_OPENCV
    #include "highgui/highgui.hpp"
    #include "imgcodecs.hpp"
    #include "imgproc/imgproc.hpp"
#endif // ENABLE_OPENCV

///------------------------------------------------------------------------------
/// File output library.
///
/// This header is to remain free from OpenCV and std library functions/classes.
///------------------------------------------------------------------------------
namespace fo
{
    template<class impl_type>
    class FileStreamWrapper
    {
    public:
        FileStreamWrapper();
        FileStreamWrapper( impl_type* handle );
        ~FileStreamWrapper();

        void open( const char* filename );
        void close();

        bool_t isopen();

        template<typename T>
        FileStreamWrapper<impl_type>& operator<<( T arg );

    private:
        impl_type* m_handle = NULL;
    };

    typedef FileStreamWrapper<FileOutput> filestream;
    typedef FileStreamWrapper<CSVOutput> csvstream;

    filestream getFileStream( const char* filename );
    csvstream getCSVStream( const char* filename );
    void closeAllStreams();

    template<typename T>
    void outputImage( const char* filename, image::Image<T>& image );

    ///------------------------------------------------------------------------------
    /// FileStreamWrapper function definitions.
    ///------------------------------------------------------------------------------

    template<class impl_type>
    inline FileStreamWrapper<impl_type>::FileStreamWrapper() :
        handle( NULL )
    {
    }

    template<class impl_type>
    inline FileStreamWrapper<impl_type>::FileStreamWrapper( impl_type* handle ) :
        m_handle( handle )
    {
    }
    template<class impl_type>
    inline FileStreamWrapper<impl_type>::~FileStreamWrapper()
    {
    }
    template<class impl_type>
    inline void FileStreamWrapper<impl_type>::open( const char* filename )
    {
        if( m_handle != NULL )
        {
            m_handle->open( filename );
        }
    }
    template<class impl_type>
    inline void FileStreamWrapper<impl_type>::close()
    {
        if( m_handle != NULL )
        {
            m_handle->close();
            m_handle = NULL;
        }
    }
    template<class impl_type>
    inline bool_t FileStreamWrapper<impl_type>::isopen()
    {
        if( m_handle != NULL )
        {
            return m_handle->is_open();
        }
        else
        {
            return false;
        }
    }
    template<class impl_type>
    template<typename T>
    inline FileStreamWrapper<impl_type>& FileStreamWrapper<impl_type>::operator<<( T arg )
    {
        if( m_handle != NULL )
        {
            *m_handle << arg;
        }

        return *this;
    }

    ///------------------------------------------------------------------------------
    /// fo function definitions.
    ///------------------------------------------------------------------------------

    template<typename T>
    void outputImage( const char* filename, image::Image<T>& image )
    {
        filename;
        image;
#ifdef ENABLE_FILE_OUTPUT
#ifdef ENABLE_OPENCV
        cv::Mat cvImage = processing::ImageProcessing::ConvertToCV( image );
        cv::Size size( image.getWidth(), image.getHeight() );
        cv::resize( cvImage, cvImage, size );
        cv::imwrite( filename, cvImage );
#endif // ENABLE_OPENCV
#endif // ENABLE_FILE_OUTPUT
    }
}
#endif

#endif // __FO__H_
