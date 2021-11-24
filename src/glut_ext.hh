#ifndef GLUT_EXT_H
#define GLUT_EXT_H

#define GLUT_EXEC_STATE_INIT 0
#define GLUT_EXEC_STATE_RUNNING 1
#define GLUT_EXEC_STATE_STOP 2

extern "C" {
  int   glutExecState( void );
  void  glutMainLoopBegin( void );
  void  glutMainLoopStep( void );
  void  glutMainLoopEnd( void );
  int   glutGetWindowHandle( void );
}

#endif
