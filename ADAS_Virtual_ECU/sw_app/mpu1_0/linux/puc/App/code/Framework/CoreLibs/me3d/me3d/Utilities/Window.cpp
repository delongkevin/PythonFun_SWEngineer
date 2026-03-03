#ifdef ME_PLATFORM_WIN

#include "Utilities/Window.h"

#include <tchar.h>
#include "InputHandler.h"

namespace me3d
{

  LRESULT CALLBACK WndProc(HWND hWnd, UINT message, WPARAM wParam, LPARAM lParam) 
  {
    Window* window = reinterpret_cast<Window*>(GetWindowLongPtr(hWnd, GWLP_USERDATA));

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
        window->onResize_v(LOWORD(lParam), HIWORD(lParam));
        break;
      }
    case WM_DESTROY:
      return 0;
    case WM_CLOSE:
      window->setShutDown_v();
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
          window->setShutDown_v();
          break;

        case 'W':
          {
            SingletonInput::getInstance_rx().setKeyDown(e_KeyW, true);
            break;
          }
        case 'S':
          {
            SingletonInput::getInstance_rx().setKeyDown(e_KeyS, true);
            break;
          }
        case 'A':
          {
            SingletonInput::getInstance_rx().setKeyDown(e_KeyA, true);
            break;
          }
        case 'D':
          {
            SingletonInput::getInstance_rx().setKeyDown(e_KeyD, true);
            break;
          }
        case 'Q':
          {
            SingletonInput::getInstance_rx().setKeyDown(e_KeyQ, true);
            break;
          }
        case 'E':
          {
            SingletonInput::getInstance_rx().setKeyDown(e_KeyE, true);
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
            SingletonInput::getInstance_rx().setKeyDown(e_KeyW, false);
            break;
          }
        case 'S':
          {
            SingletonInput::getInstance_rx().setKeyDown(e_KeyS, false);
            break;
          }
        case 'A':
          {
            SingletonInput::getInstance_rx().setKeyDown(e_KeyA, false);
            break;
          }
        case 'D':
          {
            SingletonInput::getInstance_rx().setKeyDown(e_KeyD, false);
            break;
          }
        case 'Q':
          {
            SingletonInput::getInstance_rx().setKeyDown(e_KeyQ, false);
            break;
          }

        case 'E':
          {
            SingletonInput::getInstance_rx().setKeyDown(e_KeyE, false);
            break;
          }

          break;
        }
        break;
      }

      // mouse input
    case WM_LBUTTONDOWN:
      {
        SingletonInput::getInstance_rx().setButtonDown(e_ButtonLeft, true);
        break;
      }
    case WM_LBUTTONUP:
      {
        SingletonInput::getInstance_rx().setButtonDown(e_ButtonLeft, false);
        break;
      }

    case WM_RBUTTONDOWN:
      {
        SingletonInput::getInstance_rx().setButtonDown(e_ButtonRight, true);
        break;
      }
    case WM_RBUTTONUP:
      {
        SingletonInput::getInstance_rx().setButtonDown(e_ButtonRight, false);
        break;
      }

    case WM_MOUSEMOVE:
      {
        SingletonInput::getInstance_rx().setMousePos(LOWORD(lParam), HIWORD(lParam));
        break;
      }

    case WM_MOUSEWHEEL:
      {
        SingletonInput::getInstance_rx().setMouseWheelDelta_v(GET_WHEEL_DELTA_WPARAM(wParam) / 120.0F);
        break;
      }

    default:
      break;
    }

    return DefWindowProc(hWnd, message, wParam, lParam);
  }


Window* g_Window_po = NULL;

Window::Window()
  : close_b(false)
  , hWnd(NULL)
  , hDc(NULL)
{
}

Window::~Window()
{
  release_v();
}

bool Window::create_b(const WindowDesc_s& i_Desc_rs)
{
  g_Window_po = this;

  windowDesc_s = i_Desc_rs;

  bool success = true;


  HINSTANCE applicationInstance = GetModuleHandle(NULL);

  LPCSTR windowClassName = "Ovl3DWindow";

  WNDCLASS wndClass;
  wndClass.style = CS_HREDRAW | CS_VREDRAW;
  wndClass.lpfnWndProc = (WNDPROC)WndProc;
  wndClass.cbClsExtra = 0;
  wndClass.cbWndExtra = 0;
  wndClass.hInstance = applicationInstance;
  wndClass.hIcon = LoadIcon(applicationInstance, _T("ICON"));
  wndClass.hCursor = 0;
  wndClass.lpszMenuName = 0;
  wndClass.hbrBackground = (HBRUSH) GetStockObject(WHITE_BRUSH);
  wndClass.lpszClassName = windowClassName;

  ATOM registerClass = RegisterClass(&wndClass);
  if (NULL == registerClass)
  {
    Assert(false);
    success = false;
  }

  // Create a rectangle describing the area of the window
  RECT windowRectangle;
  SetRect(&windowRectangle, i_Desc_rs.posX_s32, i_Desc_rs.posY_s32, i_Desc_rs.screenWidth_u32, i_Desc_rs.screenHeight_u32);
  AdjustWindowRectEx(&windowRectangle, WS_CAPTION | WS_SYSMENU, false, 0);

  // Create the window from the available information
  hWnd = CreateWindow(windowClassName, "OVL3D",  WS_VISIBLE | WS_SYSMENU |WS_OVERLAPPEDWINDOW , CW_USEDEFAULT, CW_USEDEFAULT, 
    windowRectangle.right - windowRectangle.left, windowRectangle.bottom - windowRectangle.top,
    NULL, NULL, applicationInstance, this);
  if (NULL == hWnd)
  {
    Assert(false);
    success = false;
  }

  // Get the associated device context from the window
  hDc = GetDC(hWnd);
  if (!hDc)
  {
    Assert(false);
    success = false;
  }

  return success;
}

void Window::release_v()
{
  ReleaseDC(hWnd, hDc);
  DestroyWindow(hWnd);
}

void Window::messageLoop_v()
{
  MSG		msg;

  while(PeekMessage(&msg, hWnd, 0, 0, PM_REMOVE))
  {
    HACCEL	hAccelTable = 0;

    if (!TranslateAccelerator(msg.hwnd, hAccelTable, &msg))
    {
      TranslateMessage(&msg);
      DispatchMessage(&msg);
    }
  }

}

void* Window::getWindowHandle_pv() const
{
  return hWnd;
}

void* Window::getDeviceHandle_pv() const
{
  return hDc;
}

void Window::setShutDown_v()
{
  close_b = true;
}

bool Window::shutDown_b() const
{
  return close_b;
}

void Window::onResize_v(uint32_t i_Width_u32, uint32_t i_Height_u32)
{
  windowDesc_s.screenWidth_u32  = i_Width_u32;
  windowDesc_s.screenHeight_u32 = i_Height_u32;
}

uint32_t Window::getWidth_u32() const
{
  return windowDesc_s.screenWidth_u32;
}

uint32_t Window::getHeight_u32() const
{
  return windowDesc_s.screenHeight_u32;
}

} // namespace me3d

#endif //_WINDOWS