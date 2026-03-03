//--------------------------------------------------------------------------
/// @file ME_Window_WIN.c
/// @brief Interface to abstract standard-library Thread
///
/// --------------------------------------------------------------------------
/// @copyright MAGNA Electronics - C O N F I D E N T I A L <br>
/// This document in its entirety is CONFIDENTIAL and may not be disclosed,
/// disseminated or distributed to parties outside MAGNA Electronics
/// without written permission from MAGNA Electronics.
///
/// @author Martin Rachor (martin.rachor@magna.com)
///
//  --------------------------------------------------------------------------

#include "bsp/graphics/Window.h"

#ifdef ME_PLATFORM_WIN

namespace bsp
{

#include <tchar.h>

LRESULT CALLBACK windowProcedure_t(HWND hWnd, UINT message, WPARAM wParam, LPARAM lParam) 
{
  Window* v_Window_pt = reinterpret_cast<Window*>(GetWindowLongPtr(hWnd, GWLP_USERDATA));

  switch (message)
  {
  case WM_CREATE:
  {
    CREATESTRUCT	*pCreate = (CREATESTRUCT*)lParam;
    SetWindowLongPtr(hWnd, GWLP_USERDATA, (LONG_PTR)pCreate->lpCreateParams);
    break;
  }
  case WM_SIZE:
  {
    break;
  }
  case WM_PAINT:
  {
    v_Window_pt->fill_b();
    break;
  }
  case WM_DESTROY:
    return 0;
  case WM_CLOSE:
    return 0;
  case WM_QUIT:
    return 0;
  case WM_SETFOCUS:
    return 0;
  case WM_KILLFOCUS:
    return 0;
  case WM_KEYDOWN:
    {
      switch(wParam)
      {
      case VK_ESCAPE:
      case 0xC1:
        break;

      case 'W':
        {
          break;
        }
      case 'S':
        {
          break;
        }
      case 'A':
        {
          break;
        }
      case 'D':
        {
          break;
        }
      case 'Q':
        {
          break;
        }
      case 'E':
        {
          break;
        }
        break;
      }
      break;
    }

  case WM_KEYUP:
    {
      switch(wParam)
      {
      case 'W':
        {
          break;
        }
      case 'S':
        {
          break;
        }
      case 'A':
        {
          break;
        }
      case 'D':
        {
          break;
        }
      case 'Q':
        {
          break;
        }

      case 'E':
        {
          break;
        }

        break;
      }
      break;
    }

    // mouse input
  case WM_LBUTTONDOWN:
    {
      break;
    }
  case WM_LBUTTONUP:
    {
      break;
    }

  case WM_RBUTTONDOWN:
    {
      break;
    }
  case WM_RBUTTONUP:
    {
      break;
    }

  case WM_MOUSEMOVE:
    {
      break;
    }

  case WM_MOUSEWHEEL:
    {
      break;
    }

  default:
    break;
  }

  return DefWindowProc(hWnd, message, wParam, lParam);
}


Window::Window()
  : window_t()
  , deviceContext_t()
  , context_t()
  , numOfBuffer_u8(2U)
  , xPos_u32(0U)
  , yPos_u32(0U)
  , width_u32(640U)
  , height_u32(480U)
{
  renderBuffers_apv[0] = NULL;
  renderBuffers_apv[1] = NULL;
}

Window::~Window()
{
  destroy_b();
}

bool_t Window::create_b(ScreenContext_t i_ScreenContext_t,
                        WindowUsage_e i_Usage_e,
                        uint32_t i_Width_u32, uint32_t i_Height_u32,
                        uint32_t i_Xpos_u32, uint32_t i_Ypos_u32,
                        uint8_t i_NumOfBuffer_u8)
{
  bool_t v_Result_b = true;

  context_t = NULL;
  numOfBuffer_u8 = i_NumOfBuffer_u8;
  width_u32 = i_Width_u32;
  height_u32 = i_Height_u32;
  xPos_u32 = i_Xpos_u32;
  yPos_u32 = i_Ypos_u32;

  HINSTANCE v_ApplicationInstance_t = GetModuleHandle(NULL);
  LPCSTR windowClassName = "OutputWindow";

  WNDCLASS v_WndClass_t;
  v_WndClass_t.style = CS_HREDRAW | CS_VREDRAW;
  v_WndClass_t.lpfnWndProc = (WNDPROC)windowProcedure_t;
  v_WndClass_t.cbClsExtra = 0;
  v_WndClass_t.cbWndExtra = 0;
  v_WndClass_t.hInstance = v_ApplicationInstance_t;
  v_WndClass_t.hIcon = LoadIcon(v_ApplicationInstance_t, _T("ICON"));
  v_WndClass_t.hCursor = 0;
  v_WndClass_t.lpszMenuName = 0;
  v_WndClass_t.hbrBackground = (HBRUSH) GetStockObject(WHITE_BRUSH);
  v_WndClass_t.lpszClassName = windowClassName;

  ATOM registerClass = RegisterClass(&v_WndClass_t);
  if (NULL == registerClass)
  {
    v_Result_b = false;
  }

  // Create a rectangle describing the area of the window
  RECT windowRectangle;
  SetRect(&windowRectangle, xPos_u32, yPos_u32, width_u32, height_u32);
  AdjustWindowRectEx(&windowRectangle, WS_CAPTION | WS_SYSMENU, false, 0);

  // Create the window from the available information
  window_t = CreateWindow(windowClassName, "Window",  WS_VISIBLE | WS_SYSMENU |WS_OVERLAPPEDWINDOW , CW_USEDEFAULT, CW_USEDEFAULT, 
                                         windowRectangle.right - windowRectangle.left, windowRectangle.bottom - windowRectangle.top,
                                         NULL, NULL, v_ApplicationInstance_t, this);

  if (NULL == window_t)
  {
    v_Result_b = false;
  }

  // Get the associated device context from the window
  deviceContext_t = GetDC(window_t);
  if (!deviceContext_t)
  {
    v_Result_b = false;
  }

  return v_Result_b;
}

bool_t Window::destroy_b() const
{
  bool_t v_Result_b = true;

  ReleaseDC(window_t, deviceContext_t);
  
  v_Result_b = DestroyWindow(window_t);

  return v_Result_b;
}

bool_t Window::post_b() const
{
  bool_t v_Result_b = true;

  MSG	v_Message_t;
  HACCEL v_HAccelTable_t;
  while(PeekMessage(&v_Message_t, window_t, 0, 0, PM_REMOVE))
  {
    v_HAccelTable_t = 0;
    if (!TranslateAccelerator(window_t, v_HAccelTable_t, &v_Message_t))
    {
      TranslateMessage(&v_Message_t);
      DispatchMessage(&v_Message_t);
    }
  }

  return v_Result_b;
}

bool_t Window::fill_b()
{
  bool_t v_Result_b = true;
  PAINTSTRUCT ps;
  HDC hdc = BeginPaint(window_t, &ps);

  FillRect(hdc, &ps.rcPaint, (HBRUSH) (COLOR_WINDOW+1));

  EndPaint(window_t, &ps);

  return v_Result_b;
}


bool_t Window::fill_b(const uint8_t* i_RgbBuff_pu8, uint32_t i_Width_u32, uint32_t i_Height_u32)
{
  bool_t v_Result_b = true;

  // Update output frame dimension if output resolution changed 
  RECT v_RectClient_t;
  GetClientRect(window_t, &v_RectClient_t);
  if(  (v_RectClient_t.right != i_Width_u32)
    ||(v_RectClient_t.bottom != i_Height_u32)
    )
  {
    RECT v_RectWindow_t;
    POINT v_PointDiff_t;
    GetWindowRect(window_t, &v_RectWindow_t);
    v_PointDiff_t.x = (v_RectWindow_t.right - v_RectWindow_t.left) - v_RectClient_t.right;
    v_PointDiff_t.y = (v_RectWindow_t.bottom - v_RectWindow_t.top) - v_RectClient_t.bottom;
    MoveWindow(window_t,v_RectWindow_t.left, v_RectWindow_t.top, i_Width_u32 + v_PointDiff_t.x, i_Height_u32 + v_PointDiff_t.y, TRUE);
  }

  // Create Bitmap from ByteArray
  BITMAPINFOHEADER   v_BitmapHeader_t;
  memset(&v_BitmapHeader_t, 0, sizeof(BITMAPINFOHEADER));

  v_BitmapHeader_t.biWidth = i_Width_u32;
  v_BitmapHeader_t.biHeight = i_Height_u32;
  v_BitmapHeader_t.biBitCount = 24;
  v_BitmapHeader_t.biCompression = BI_RGB;
  v_BitmapHeader_t.biSize = sizeof(BITMAPINFOHEADER);
  v_BitmapHeader_t.biPlanes = 1;

  BITMAPINFO* v_BitmapInfo_t = (BITMAPINFO*)&v_BitmapHeader_t;
  HBITMAP v_HBitmap_t = CreateDIBitmap((HDC)deviceContext_t, &v_BitmapHeader_t, CBM_INIT, i_RgbBuff_pu8, v_BitmapInfo_t, DIB_RGB_COLORS);


  // Create Bitmap from output frame
  HDC v_BitmapDC_t = CreateCompatibleDC(NULL); // This will hold the BMP image itself.
  SelectObject(v_BitmapDC_t, v_HBitmap_t); // Put the image into the DC.
  
  XFORM v_XForm_t;
  GetWorldTransform(deviceContext_t,(LPXFORM)&v_XForm_t);
  v_XForm_t.eM22 = (FLOAT)-1;
  v_XForm_t.eDy  = (FLOAT)i_Height_u32-1;

  SetGraphicsMode(deviceContext_t, GM_ADVANCED);
  SetWorldTransform(deviceContext_t,&v_XForm_t);

  // Draw input image to to output frame
  BitBlt(deviceContext_t, 0, 0, i_Width_u32, i_Height_u32, v_BitmapDC_t, 0, 0, SRCCOPY); // Finally, Draw it

  // Cleanup
  DeleteDC(v_BitmapDC_t);
  DeleteObject(v_HBitmap_t);


  return v_Result_b;
}


} // namespace bsp

#endif // ME_PLATFORM_QNX
