// ----------------------------------------------------------------------------
// --- Written by Joshua Teichroeb [10-Sep-2018]
// --- Copyright (c) Magna Electronics - Brampton 2018
// ----------------------------------------------------------------------------

#ifndef CV_CONTAINERS_H
#define CV_CONTAINERS_H

#include "Defines.h"

#ifdef WINDOWS_DEBUGGING

#include "highgui/highgui.hpp"
#include "imgcodecs.hpp"
#include "imgproc/imgproc.hpp"

namespace cv
{
    /*
    * Colour used to represent transparent pixels.
    */
    const cv::Scalar CV_TRANSPARENT = cv::Scalar( -1, -1, -1 );

    /*
    * View type enumeration.
    */
    enum eViewType
    {
        eUndefinedView,
        eAbstractView,
        eTextView,
        eScrollView,
        eListView,
        eGridView,
        eGridView2,
        eButtonView,
        eImageView
    };

    /*
    * Text alignment used in TextViews.
    */
    enum eTextAlignment
    {
        AlignLeft,
        AlignRight,
        AlignCentre
    };

    /*
    * Mouse event opcode.
    */
    enum eEventOpcode
    {
        EventNone,
        EventLeftClick,
        EventMouseWheel
    };

    /*
    * Mouse event.
    */
    typedef struct MouseEvent
    {
        eEventOpcode op;
        int dy;
        int dx;
    } _MouseEvent_t;

    /*
    * Parameters to create a View.
    */
    typedef struct ViewParameters
    {
        int borderWidth = 1;
        int horMargin = 1;
        int verMargin = 1;
        cv::Scalar colour = cv::Scalar( 255, 255, 255 );
        cv::Scalar borderColour = cv::Scalar( 0, 0, 0 );
    } _ViewParameters_t;

    /*
    * Parameters to create a TextView.
    */
    typedef struct TextViewParameters
    {
        int font = FONT_HERSHEY_SIMPLEX;
        int textThickness = 1;
        double fontScale = 1.0;
        double textRatio = 1.0;
        bool fitTextSet = true;
        cv::Scalar textColour = cv::Scalar( 0, 0, 0 );
        eTextAlignment alignment = AlignLeft;
        ViewParameters viewParams;
    } _TextViewParameters_t;

    class View;

    /*
    * Holds the relative position and size of a view within its parent view
    */
    class ViewProxy
    {
    public:
        float x;
        float y;
        float width;
        float height;
        View* view;

        ViewProxy( float i_x, float i_y, float i_width, float i_height );
        ViewProxy();
        virtual ~ViewProxy();

        void refreshView( cv::Mat& parentImg );
    };

    /** An empty view. **/
    class View
    {
    public:
        View( ViewParameters viewParams, eViewType i_viewType );
        View();
        virtual ~View();

        void Uninit();

        void invalidate();
        void requestRefresh();
        void refresh( cv::Mat& img );
        void refreshChildren( cv::Mat& img );

        virtual void drawView( cv::Mat& img );
        virtual void drawOverlay( cv::Mat& img );
        virtual bool isChildInView( const ViewProxy* child );
        virtual bool doesChildContainPoint( const ViewProxy* child, float i_x, float i_y );
        virtual void processMouseEvent( MouseEvent e, float i_x, float i_y );

        virtual std::vector<View*> getChildren() = 0;
        virtual std::vector<ViewProxy*> getProxies() = 0;
        virtual ViewProxy* getChildPos( View* childView ) = 0;

        virtual eViewType getViewType();
        virtual void setParent( View& parentView );
        virtual void setColour( int b, int g, int r );
        virtual void setColour( cv::Scalar i_colour );
        virtual void setBorderColour( int b, int g, int r );
        virtual void setBorderColour( cv::Scalar i_colour );
        virtual void setBorderThickness( int thickness );
        virtual void setMargins( int i_horMargin, int i_verMargin );

    protected:
        View* parent;
        bool invalid;
        bool refreshRequested;

        int borderWidth;
        int horMargin;
        int verMargin;
        cv::Scalar colour;
        cv::Scalar borderColour;
        eViewType viewType;
    };

    /** A view which holds other views. **/
    class AbstractView : public View
    {
    public:
        AbstractView( ViewParameters viewParams );
        AbstractView();
        virtual ~AbstractView();

        virtual std::vector<View*> getChildren() override;
        virtual std::vector<ViewProxy*> getProxies() override;
        virtual ViewProxy* getChildPos( View* childView ) override;

        virtual void addChildView( View* childView, float i_x, float i_y, float i_width, float i_height );
        virtual void addChildView( View* childView );
        virtual void resizeChild( View* childView, float i_width, float i_height );

    protected:
        std::vector<ViewProxy*> children;

    };

    /** A view which holds text. **/
    class TextView : public AbstractView
    {
    public:
        TextView( std::string i_text , TextViewParameters params );
        TextView( std::string i_text );
        virtual ~TextView();

        virtual void drawView( cv::Mat& img ) override;

        virtual void resizeText( int height );
        virtual void fitText( int width, int height, double i_minRatio, double i_maxRatio );

        virtual std::string getText();
        virtual void setText( std::string i_text );
        virtual void setFont( int i_font );
        virtual void setTextThickness( int i_thickness );
        virtual void setFontScale( double i_fontScale );
        virtual void setTextRatio( double i_ratio );
        virtual void setTextColour( int b, int g, int r );
        virtual void setTextColour( cv::Scalar i_colour );
        virtual void setTextAlignment( eTextAlignment i_alignment );

    protected:
        std::string text;
        int font;
        int textThickness;
        double fontScale;
        double textRatio;
        bool fitTextSet;
        cv::Scalar textColour;
        eTextAlignment alignment;
    };

    /** A view which can scroll. **/
    class ScrollView : public View
    {
    public:
        ScrollView();
        virtual ~ScrollView();

        virtual void drawView( cv::Mat& img ) override;
        virtual std::vector<View*> getChildren() = 0;
        virtual std::vector<ViewProxy*> getProxies() = 0;
        virtual ViewProxy* getChildPos( View* ) = 0;
        virtual void processMouseEvent( MouseEvent e, float i_x, float i_y ) override;

        virtual void scroll( float dy );
        virtual void scrollToBottom();
        virtual float distanceFromBottom();
        virtual float distanceFromTop();

        void setScrollAmount( float i_amt );
        void setTop( float i_top );
        void setHeight( float i_height );

    protected:
        float scrollAmount;
        float top;
        float height;
    };

    /** A view which places its children one on top of another. **/
    class ListView : public View
    {
    public:
        ListView( int i_rows );
        ListView();
        virtual ~ListView();

        virtual void drawOverlay( cv::Mat& img ) override;
        virtual void addChildView( View* childView );
        virtual void insert( int row, View* childView );
        virtual std::vector<View*> getChildren() override;
        virtual std::vector<ViewProxy*> getProxies() override;
        virtual ViewProxy* getChildPos( View* ) override;

        virtual void fitCells();
        virtual void updateCells( int startIndex = 0 );

        virtual void setCellHeight( float i_height );
        virtual void setGridThickness( unsigned int thickness );
        virtual void setGridColour( int b, int g, int r );

    protected:
        std::vector<ViewProxy*> children;
        int rows;
        float cellHeight;
        int gridThickness;
        cv::Scalar gridColour;
    };

    /** A view which holds other views in a grid. **/
    class GridView : public ScrollView
    {
    public:
        GridView( int i_cols, int i_rows );
        GridView();
        virtual ~GridView();

        virtual void drawOverlay( cv::Mat& img ) override;
        virtual void insert( int row, int col, View* childView );
        virtual void fitCells();
        virtual std::vector<View*> getChildren() override;
        virtual std::vector<ViewProxy*> getProxies() override;
        virtual ViewProxy* getChildPos( View* childView ) override;

        virtual void clearCells();
        virtual void updateCells( int startRow = 0, int startCol = 0 );
        virtual void addRow( float rowHeight );
        virtual void addRow( );
        virtual void deleteRow( int row );

        virtual View* getCell( int row, int col );
        virtual std::vector<View*> getRow( int row );
        virtual std::vector<View*> getCol( int col );
        virtual void setRowHeight( float i_height );
        virtual void setRowHeight( int index, float i_height );
        virtual void setColWidth( float i_width );
        virtual void setColWidth( int index, float i_width );
        virtual void setGridThickness( unsigned int thickness );
        virtual void setGridColour( int b, int g, int r );

    protected:
        std::vector<std::vector<ViewProxy*>> children;
        std::vector<float> cellWidths;
        std::vector<float> cellHeights;
        float defaultCellWidth;
        float defaultCellHeight;
        int rows;
        int cols;
        int gridThickness;
        cv::Scalar gridColour;
    };

    /** A view which holds other views in a grid. **/
    class GridView2 : public View
    {
    public:
        GridView2( int rows, int cols );
        GridView2();
        virtual ~GridView2();

        virtual std::vector<View*> getChildren() override;
        virtual std::vector<ViewProxy*> getProxies() override;
        virtual ViewProxy* getChildPos( View* childView ) override;

        virtual void insert( int row, int col, View* childView );

    private:
        std::vector<std::vector<ViewProxy*>> m_children;
        int m_rows;
        int m_cols;

        virtual void setNumRows( int numRows );
        virtual void setNumCols( int numCols );

    };

    /** A button which observes clicks. (Not fully implemented) **/
    template <class CallBackType>
    class ButtonView : public View
    {
    public:
        ButtonView();
        virtual ~ButtonView();

        virtual std::vector<View*> getChildren() override;
        virtual std::vector<ViewProxy*> getProxies() override;
        virtual ViewProxy* getChildPos( View* childView ) override;
        virtual void processMouseEvent( MouseEvent e, float i_x, float i_y ) override;

        void addListener( void ( CallBackType::* listener )( MouseEvent, float, float ) );

    private:
        std::vector<void ( CallBackType::* )( MouseEvent, float, float )> listeners;
        CallBackType* pObj;

    };

    /** A view which holds an image. **/
    class ImageView : public AbstractView
    {
    public:
        ImageView( cv::Mat img );
        ImageView();
        virtual ~ImageView();

        virtual void drawView( cv::Mat& img ) override;

        virtual cv::Mat& getMat();
        virtual void resize( int i_width, int i_height );

    private:
        cv::Mat mat;

    };

    /** A window which holds views and serves as the top-most component of a display. **/
    class Window
    {
    public:
        std::string name;

        Window( std::string i_name, int i_width, int i_height, int i_type );
        Window( std::string i_name, cv::Mat i_mat );
        Window( std::string i_name );
        Window();
        ~Window();

        virtual void refresh();
        virtual void processMouseEvent( MouseEvent e, int i_x, int i_y );
        virtual void show();
        virtual void addView( View* view, float i_x, float i_y, float i_width, float i_height );
        virtual void addView( View* view );
        virtual bool isViewInWindow( const ViewProxy* view );

        virtual void resize( int i_width, int i_height );
        virtual void setColour( int b, int g, int r );
        virtual void setColour( cv::Scalar i_colour );
        virtual cv::Size getSize();
        virtual std::vector<View*> getViews();

    private:
        cv::Mat m_mat;
        std::vector<ViewProxy*> m_views;
        cv::Scalar m_colour;
    };
}

#endif // !WINDOWS_DEBUGGING

#endif // !CV_CONTAINERS_H
