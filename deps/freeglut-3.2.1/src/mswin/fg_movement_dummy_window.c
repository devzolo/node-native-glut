#include "fg_movement_dummy_window.h"

SFG_MovementDummyWindow* pCurrentMovementDummyWindow = NULL;

LRESULT CALLBACK ProcessDummyWindowMessage(HWND hwnd, UINT uMsg, WPARAM wParam, LPARAM lParam)
{
    SFG_MovementDummyWindow* pThis = pCurrentMovementDummyWindow;

    switch (uMsg)
    {
        case WM_NCMOUSEMOVE:
        case WM_MOUSEMOVE:
        {
            POINT CursorPos;
            GetCursorPos(&CursorPos);
            SetWindowPos(hwnd, NULL, CursorPos.x + pThis->moveOffset.x, CursorPos.y + pThis->moveOffset.y, 0, 0, SWP_NOZORDER | SWP_NOSIZE);
            break;
        }
        case WM_LBUTTONUP:
        {
            // Destroy the dummy window
            DestroyWindow(hwnd);
            pThis->hWnd = NULL;

            POINT CursorPos;
            GetCursorPos(&CursorPos);

            // Move the main window to the last position of the dummy window
            SetWindowPos(pThis->hWndParent, NULL, CursorPos.x + pThis->moveOffset.x, CursorPos.y + pThis->moveOffset.y, 0, 0,
                         SWP_NOZORDER | SWP_NOSIZE);
            // ShowWindow ( pThis->m_HookedWindowHandle, SW_SHOW );

            // Release mouse capture
            ReleaseCapture();

            break;
        }
        case WM_PAINT:
        {
            PAINTSTRUCT PS;
            BeginPaint(hwnd, &PS);
            RECT ClientRect;
            GetClientRect(hwnd, &ClientRect);
            RECT BorderRect = {5, 5, ClientRect.right - 5, ClientRect.bottom - 5};

            // Give it some color
            HBRUSH BorderBrush = CreateSolidBrush(0x00000000);
            HBRUSH FillBrush = CreateSolidBrush(RGB(255, 255, 255));
            FillRect(PS.hdc, &ClientRect, BorderBrush);
            FillRect(PS.hdc, &BorderRect, FillBrush);
            DeleteObject(BorderBrush);
            DeleteObject(FillBrush);
            EndPaint(hwnd, &PS);

            break;
        }
        default:
            return DefWindowProc(hwnd, uMsg, wParam, lParam);
    }
    return 0;
}

SFG_MovementDummyWindow* movementDummyWindowCreate() {
  SFG_MovementDummyWindow* window = (SFG_MovementDummyWindow *)malloc( sizeof(SFG_MovementDummyWindow) );
  window->hWnd = NULL;

  return window;
}


void movementDummyWindowInit(HWND hFocusWindow)
{
    if(pCurrentMovementDummyWindow == NULL) {
      pCurrentMovementDummyWindow = movementDummyWindowCreate();
    }

    if (pCurrentMovementDummyWindow->hWndParent == NULL)
    {
        // Save the hooked window handle.
        pCurrentMovementDummyWindow->hWndParent = hFocusWindow;

        // Enable Unicode (UTF-16) characters in WM_CHAR messages
        // SetWindowLongW(hFocusWindow, GWL_WNDPROC, GetWindowLong(hFocusWindow, GWL_WNDPROC));

        // Register window class for dummy movement window
        WNDCLASSEX wcDummy;
        wcDummy.cbSize = sizeof(WNDCLASSEX);
        wcDummy.style = 0;
        wcDummy.lpfnWndProc = ProcessDummyWindowMessage;
        wcDummy.cbClsExtra = 0;
        wcDummy.cbWndExtra = 0;
        wcDummy.hInstance = GetModuleHandle(NULL);
        wcDummy.hIcon = LoadIcon(NULL, IDI_APPLICATION);
        wcDummy.hCursor = LoadCursor(NULL, IDC_ARROW);
        wcDummy.hbrBackground = (HBRUSH)(COLOR_WINDOW + 1);
        wcDummy.lpszMenuName = NULL;
        wcDummy.lpszClassName = "MovementDummy";
        wcDummy.hIconSm = LoadIcon(NULL, IDI_APPLICATION);
        RegisterClassEx(&wcDummy);
    }
}

void movementDummyWindowStartWindowMovement()
{
    SFG_MovementDummyWindow* pThis = pCurrentMovementDummyWindow;

    RECT ClientRect;
    GetWindowRect(pThis->hWndParent, &ClientRect);
    POINT CursorPos;
    GetCursorPos(&CursorPos);

    pThis->moveOffset.x = ClientRect.left - CursorPos.x;
    pThis->moveOffset.y = ClientRect.top - CursorPos.y;

    pThis->hWnd = CreateWindowEx(0, "MovementDummy", "", 0, CW_USEDEFAULT, CW_USEDEFAULT, ClientRect.right - ClientRect.left,
                                           ClientRect.bottom - ClientRect.top, NULL, NULL, GetModuleHandle(NULL), NULL);

    LONG lStyle = GetWindowLong(pThis->hWnd, GWL_STYLE);
    lStyle &= ~(WS_CAPTION | WS_THICKFRAME | WS_SYSMENU);
    SetWindowLong(pThis->hWnd, GWL_STYLE, lStyle);

    LONG lExStyle = GetWindowLong(pThis->hWnd, GWL_EXSTYLE);
    lExStyle &= ~(WS_EX_DLGMODALFRAME | WS_EX_CLIENTEDGE | WS_EX_STATICEDGE);
    lExStyle |= WS_EX_LAYERED;
    SetWindowLong(pThis->hWnd, GWL_EXSTYLE, lExStyle);
    SetLayeredWindowAttributes(pThis->hWnd, 0, 140, LWA_ALPHA);

    SetWindowPos(pThis->hWnd, NULL, ClientRect.left, ClientRect.top, 0, 0, SWP_DRAWFRAME | SWP_NOZORDER | SWP_NOSIZE);
    // ShowWindow ( m_HookedWindowHandle, SW_HIDE );
    ShowWindow(pThis->hWnd, SW_SHOW);
    UpdateWindow(pThis->hWnd);

    // Set mouse capture to handle mouse event also if the cursor is not on the window (due to a too fast mouse)
    SetCapture(pThis->hWnd);
}
