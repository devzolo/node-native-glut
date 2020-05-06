#ifndef  FREEGLUT_MOVEMENT_DUMMY_WINDOW_H
#define  FREEGLUT_MOVEMENT_DUMMY_WINDOW_H

#include <windows.h>

typedef struct tagMovementDummyWindow SFG_MovementDummyWindow;
struct tagMovementDummyWindow
{
    HWND hWndParent;
    HWND hWnd;
    POINT moveOffset;
};

SFG_MovementDummyWindow* movementDummyWindowCreate();
void movementDummyWindowInit(HWND hFocusWindow);
void movementDummyWindowStartWindowMovement();

#endif
