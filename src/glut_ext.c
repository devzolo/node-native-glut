#include <GL/freeglut.h>
#include <fg_internal.h>
#include <limits.h>

extern void fgPlatformSleepForEvents(fg_time_t msec);
extern void fgPlatformMainLoopPreliminaryWork(void);

static void fghHavePendingWorkCallback(SFG_Window *w, SFG_Enumerator *e)
{
  if (w->State.WorkMask)
  {
    e->found = GL_TRUE;
    e->data = w;
    return;
  }
  fgEnumSubWindows(w, fghHavePendingWorkCallback, e);
}

static int fghHavePendingWork(void)
{
  SFG_Enumerator enumerator;

  enumerator.found = GL_FALSE;
  enumerator.data = NULL;
  fgEnumWindows(fghHavePendingWorkCallback, &enumerator);
  return !!enumerator.data;
}

/*
 * Returns the number of GLUT ticks (milliseconds) till the next timer event.
 */
static fg_time_t fghNextTimer(void)
{
  fg_time_t currentTime;
  SFG_Timer *timer = fgState.Timers.First; /* timers are sorted by trigger time, so only have to check the first */

  if (!timer)
    return INT_MAX;

  currentTime = fgElapsedTime();
  if (timer->TriggerTime < currentTime)
    return 0;
  else
    return timer->TriggerTime - currentTime;
}

static void fghSleepForEvents(void)
{
  fg_time_t msec;

  if (fghHavePendingWork())
    return;

  msec = fghNextTimer();
  /* XXX Should use GLUT timers for joysticks... */
  /* XXX Dumb; forces granularity to .01sec */
  if (fgState.NumActiveJoysticks > 0 && (msec > 10))
    msec = 10;

  fgPlatformSleepForEvents(msec);
}

int FGAPIENTRY glutExecState(void)
{
  return fgState.ExecState;
}

void FGAPIENTRY glutMainLoopBegin(void)
{
  FREEGLUT_EXIT_IF_NOT_INITIALISED("glutMainLoop");

  if (!fgStructure.Windows.First)
    fgError(" ERROR:  glutMainLoop called with no windows created.");

  fgPlatformMainLoopPreliminaryWork();

  fgState.ExecState = GLUT_EXEC_STATE_RUNNING;
}

void FGAPIENTRY glutMainLoopStep(void)
{
  SFG_Window *window;

  glutMainLoopEvent();
  if (fgState.ExecState != GLUT_EXEC_STATE_RUNNING)
    return;
  /*
        * Step through the list of windows, seeing if there are any
        * that are not menus
        */
  for (window = (SFG_Window *)fgStructure.Windows.First;
       window;
       window = (SFG_Window *)window->Node.Next)
    if (!(window->IsMenu))
      break;

  if (!window)
    fgState.ExecState = GLUT_EXEC_STATE_STOP;
  else
  {
    if (fgState.IdleCallback)
    {
      if (fgStructure.CurrentWindow &&
          fgStructure.CurrentWindow->IsMenu)
        /* fail safe */
        fgSetWindow(window);
      fgState.IdleCallback(fgState.IdleCallbackData);
    }
    else
      fghSleepForEvents();
  }
}

void FGAPIENTRY glutMainLoopEnd(void)
{
  int action = fgState.ActionOnWindowClose;
  fgDeinitialize();
  if (action == GLUT_ACTION_EXIT)
    exit(0);
}

void * FGAPIENTRY glutGetWindowHandle(void)
{
  SFG_Window *window = (SFG_Window *)fgStructure.Windows.First;
  if (window)
    return (void *)window->Window.Handle;
  return NULL;
}
