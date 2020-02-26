#include <napi.h>

// OpenGL Graphics Includes
#include <GL/freeglut.h>
#include "glut_ext.hh"
#include <map>

#define JS_GLUT___________________________TODO(name) puts("TODO: GLUT."#name)
#define JS_GLUT_CONSTANT(name) exports.Set(Napi::String::New(env, #name), Napi::Number::New(env, GLUT_##name))
#define JS_GLUT_SET_METHOD(name) exports.Set(Napi::String::New(env, #name), Napi::Function::New(env, name));
#define JS_ARGS(argc) \
if (info.Length() < argc) { \
  Napi::TypeError::New(env, "Wrong number of arguments").ThrowAsJavaScriptException(); \
  return env.Null(); \
}

#define JS_INT_ARG(pos, name) int32_t name = info[pos].As<Napi::Number>().Int32Value();
#define JS_LONG_ARG(pos, name) int64_t name = info[pos].As<Napi::Number>().Int64Value();
#define JS_UINT_ARG(pos, name) uint32_t name = info[pos].As<Napi::Number>().Uint32Value();
#define JS_STR_ARG(pos, name) std::string name = info[pos].As<Napi::String>().Utf8Value();
#define JS_DOUBLE_ARG(pos, name) double_t name = info[pos].As<Napi::Number>().DoubleValue();
#define JS_FLOAT_ARG(pos, name) float_t name = info[pos].As<Napi::Number>().FloatValue();
#define JS_PVOID_ARG(pos, name) void* name = (void*)info[pos].As<Napi::Number>().Int64Value();

#define JS_GLDOUBLE_ARG(pos, name) GLdouble name = info[pos].As<Napi::Number>().DoubleValue();
#define JS_GLFLOAT_ARG(pos, name) GLfloat name = info[pos].As<Napi::Number>().FloatValue();
#define JS_GLENUM_ARG(pos, name) GLenum name = info[pos].As<Napi::Number>().Uint32Value();
#define JS_GLUINT_ARG(pos, name) GLuint name = info[pos].As<Napi::Number>().Uint32Value();
#define JS_GLINT_ARG(pos, name) GLint name = info[pos].As<Napi::Number>().Int32Value();

#define JS_ARG_TYPE(pos, type)  if (!info[pos].Is##type()) { \
  Napi::TypeError::New(env, "Wrong arguments").ThrowAsJavaScriptException(); \
  return env.Null(); \
}

namespace glut {

const std::vector<napi_value> NO_ARGS;

Napi::String HelloMethod(const Napi::CallbackInfo& info) {
  Napi::Env env = info.Env();
  info[0].As<Napi::Number>().Uint32Value();
  return Napi::String::New(env, "world");
}


Napi::Value init(const Napi::CallbackInfo& info) {
  Napi::Env env = info.Env();
  char *myargv[1];
	int myargc = 1;
	myargv[0] = strdup("NodeApp");
	glutInit(&myargc, myargv);
  return info.Env().Undefined();
}

// initWindowPosition(x: number, y: number): void;
Napi::Value initWindowPosition(const Napi::CallbackInfo& info) {
	Napi::Env env = info.Env();
	JS_ARGS(2);
	JS_ARG_TYPE(0, Number);
	JS_ARG_TYPE(1, Number);
	JS_INT_ARG(0, x);
	JS_INT_ARG(1, y);
	glutInitWindowPosition(x, y);
	return info.Env().Undefined();
}

// initWindowSize(width: number, height: number): void;
Napi::Value initWindowSize(const Napi::CallbackInfo& info) {
	Napi::Env env = info.Env();
	JS_ARGS(2);
	JS_ARG_TYPE(0, Number);
	JS_ARG_TYPE(1, Number);
	JS_INT_ARG(0, width);
	JS_INT_ARG(1, height);
	glutInitWindowSize(width, height);
	return info.Env().Undefined();
}

// initDisplayMode(displayMode: number): void;
Napi::Value initDisplayMode(const Napi::CallbackInfo& info) {
	Napi::Env env = info.Env();
	JS_ARGS(1);
	JS_ARG_TYPE(0, Number);
	JS_UINT_ARG(0, displayMode);
	glutInitDisplayMode(displayMode);
	return info.Env().Undefined();
}

// initDisplayString(displayMode: string): void;
Napi::Value initDisplayString(const Napi::CallbackInfo& info) {
	Napi::Env env = info.Env();
	JS_ARGS(1);
	JS_ARG_TYPE(0, String);
	JS_STR_ARG(0, displayMode);
	glutInitDisplayString(displayMode.c_str());
	return info.Env().Undefined();
}

/*
 * Process loop function, see fg_main.c
 */
// mainLoop( void ): void
Napi::Value mainLoop(const Napi::CallbackInfo& info) {
	glutMainLoop();
	return info.Env().Undefined();
}
// mainLoopEvent( void ): void
Napi::Value mainLoopEvent(const Napi::CallbackInfo& info) {
	glutMainLoopEvent();
	return info.Env().Undefined();
}


/*
 * Window management functions, see fg_window.c
 */
// createWindow(title:string): number;
Napi::Value createWindow(const Napi::CallbackInfo& info) {
	Napi::Env env = info.Env();
	JS_ARGS(1);
	JS_ARG_TYPE(0, String);
	JS_STR_ARG(0, title);
  return Napi::Number::New(info.Env(), glutCreateWindow(title.c_str()));
}

// int  createSubWindow( int window, int x, int y, int width, int height );
Napi::Value createSubWindow(const Napi::CallbackInfo& info) {
	Napi::Env env = info.Env();
	JS_ARGS(5);
	JS_ARG_TYPE(0, Number);
	JS_ARG_TYPE(1, Number);
	JS_ARG_TYPE(2, Number);
	JS_ARG_TYPE(3, Number);
	JS_ARG_TYPE(4, Number);
	JS_INT_ARG(0, parentID);
	JS_INT_ARG(1, x);
	JS_INT_ARG(2, y);
	JS_INT_ARG(3, w);
	JS_INT_ARG(4, h);
	return Napi::Number::New(info.Env(), glutCreateSubWindow(parentID, x , y, w, h));
}

// void destroyWindow( int window );
Napi::Value destroyWindow(const Napi::CallbackInfo& info) {
	Napi::Env env = info.Env();
	JS_ARGS(1);
	JS_ARG_TYPE(0, Number);
	JS_INT_ARG(0, window);
	glutDestroyWindow(window);
	return info.Env().Undefined();
}

// void setWindow( int window );
Napi::Value setWindow(const Napi::CallbackInfo& info) {
	Napi::Env env = info.Env();
	JS_ARGS(1);
	JS_ARG_TYPE(0, Number);
	JS_INT_ARG(0, window);
	glutSetWindow(window);
	return info.Env().Undefined();
}

// int  getWindow( void );
Napi::Value getWindow(const Napi::CallbackInfo& info) {
	return Napi::Number::New(info.Env(), glutGetWindow());
}

// void setWindowTitle( const char* title );
Napi::Value setWindowTitle(const Napi::CallbackInfo& info) {
	Napi::Env env = info.Env();
	JS_ARGS(1);
	JS_ARG_TYPE(0, String);
	JS_STR_ARG(0, title);
	glutSetWindowTitle(title.c_str());
	return info.Env().Undefined();
}

// void setIconTitle( const char* title );
Napi::Value setIconTitle(const Napi::CallbackInfo& info) {
	Napi::Env env = info.Env();
	JS_ARGS(1);
	JS_ARG_TYPE(0, String);
	JS_STR_ARG(0, title);
	glutSetIconTitle(title.c_str());
	return info.Env().Undefined();
}

// void reshapeWindow( int width, int height );
Napi::Value reshapeWindow(const Napi::CallbackInfo& info) {
	Napi::Env env = info.Env();
	JS_ARGS(2);
	JS_ARG_TYPE(0, Number);
	JS_ARG_TYPE(1, Number);
	JS_INT_ARG(0, width);
	JS_INT_ARG(1, height);
	glutReshapeWindow(width, height);
	return info.Env().Undefined();
}

// void positionWindow( int x, int y );
Napi::Value positionWindow(const Napi::CallbackInfo& info) {
	Napi::Env env = info.Env();
	JS_ARGS(2);
	JS_ARG_TYPE(0, Number);
	JS_ARG_TYPE(1, Number);
	JS_INT_ARG(0, x);
	JS_INT_ARG(1, y);
	glutPositionWindow(x, y);
	return info.Env().Undefined();
}

// void showWindow( void );
Napi::Value showWindow(const Napi::CallbackInfo& info) {
	glutShowWindow();
	return info.Env().Undefined();
}

// void hideWindow( void );
Napi::Value hideWindow(const Napi::CallbackInfo& info) {
	glutHideWindow();
	return info.Env().Undefined();
}

// void iconifyWindow( void );
Napi::Value iconifyWindow(const Napi::CallbackInfo& info) {
	glutIconifyWindow();
	return info.Env().Undefined();
}


// void pushWindow( void );
Napi::Value pushWindow(const Napi::CallbackInfo& info) {
	glutPushWindow();
	return info.Env().Undefined();
}

// void popWindow( void );
Napi::Value popWindow(const Napi::CallbackInfo& info) {
	glutPopWindow();
	return info.Env().Undefined();
}

// void fullScreen( void );
Napi::Value fullScreen(const Napi::CallbackInfo& info) {
	glutFullScreen();
	return info.Env().Undefined();
}


/*
 * Display-related functions, see fg_display.c
 */
// void postWindowRedisplay( int window );
Napi::Value postWindowRedisplay(const Napi::CallbackInfo& info) {
	Napi::Env env = info.Env();
	JS_ARGS(1);
	JS_ARG_TYPE(0, Number);
	JS_INT_ARG(0, window);
	glutPostWindowRedisplay(window);
	return info.Env().Undefined();
}

// void postRedisplay( void );
Napi::Value postRedisplay(const Napi::CallbackInfo& info) {
	glutPostRedisplay();
	return info.Env().Undefined();
}

// void swapBuffers( void );
Napi::Value swapBuffers(const Napi::CallbackInfo& info) {
	glutSwapBuffers();
	return info.Env().Undefined();
}

/*
 * Mouse cursor functions, see fg_cursor.c
 */
// void warpPointer( int x, int y );
Napi::Value warpPointer(const Napi::CallbackInfo& info) {
	Napi::Env env = info.Env();
	JS_ARGS(2);
	JS_ARG_TYPE(0, Number);
	JS_ARG_TYPE(1, Number);
	JS_INT_ARG(0, x);
	JS_INT_ARG(1, y);
	glutWarpPointer(x, y);
	return info.Env().Undefined();
}

// void setCursor( int cursor );
Napi::Value setCursor(const Napi::CallbackInfo& info) {
	Napi::Env env = info.Env();
	JS_ARGS(1);
	JS_ARG_TYPE(0, Number);
	JS_INT_ARG(0, cursor);
	glutSetCursor(cursor);
	return info.Env().Undefined();
}


/*
 * Overlay stuff, see fg_overlay.c
 */
// void establishOverlay( void );
Napi::Value establishOverlay(const Napi::CallbackInfo& info) {
	glutEstablishOverlay();
	return info.Env().Undefined();
}

// void removeOverlay( void );
Napi::Value removeOverlay(const Napi::CallbackInfo& info) {
	glutRemoveOverlay();
	return info.Env().Undefined();
}

// void useLayer( GLenum layer );
Napi::Value useLayer(const Napi::CallbackInfo& info) {
	Napi::Env env = info.Env();
	JS_ARGS(1);
	JS_ARG_TYPE(0, Number);
	JS_UINT_ARG(0, layer);
	glutUseLayer(layer);
	return info.Env().Undefined();
}

// void postOverlayRedisplay( void );
Napi::Value postOverlayRedisplay(const Napi::CallbackInfo& info) {
	glutPostOverlayRedisplay();
	return info.Env().Undefined();
}

// void postWindowOverlayRedisplay( int window );
Napi::Value postWindowOverlayRedisplay(const Napi::CallbackInfo& info) {
	Napi::Env env = info.Env();
	JS_ARGS(1);
	JS_ARG_TYPE(0, Number);
	JS_INT_ARG(0, window);
	glutPostWindowOverlayRedisplay(window);
	return info.Env().Undefined();
}

// void showOverlay( void );
Napi::Value showOverlay(const Napi::CallbackInfo& info) {
	glutShowOverlay();
	return info.Env().Undefined();
}

// void hideOverlay( void );
Napi::Value hideOverlay(const Napi::CallbackInfo& info) {
	glutHideOverlay();
	return info.Env().Undefined();
}

std::map<int, Napi::FunctionReference> m_menuFuncCBRefs;
void m_menuFunc(int menu) {
  if(!m_menuFuncCBRefs[menu].IsEmpty()) {
    m_menuFuncCBRefs[menu].Call({ Napi::Number::New(m_menuFuncCBRefs[menu].Env(), menu) });
  }
}
/*
 * Menu stuff, see fg_menu.c
 */
// int  createMenu( void (* callback)( int menu ) );
Napi::Value createMenu(const Napi::CallbackInfo& info) {
	Napi::Env env = info.Env();
	JS_ARGS(1);
  JS_ARG_TYPE(0, Function);
  Napi::Function func = info[0].As<Napi::Function>();
	int menu = glutCreateMenu(m_menuFunc);
  m_menuFuncCBRefs[menu] = Napi::Persistent(func);
  m_menuFuncCBRefs[menu].SuppressDestruct();
	return Napi::Number::New(env, menu);
}


// void destroyMenu( int menu );
Napi::Value destroyMenu(const Napi::CallbackInfo& info) {
  Napi::Env env = info.Env();
  JS_ARGS(1);
	JS_ARG_TYPE(0, Number);
	JS_INT_ARG(0, menu);
  glutDestroyMenu(menu);
	return env.Undefined();
}

// int  getMenu( void );
Napi::Value getMenu(const Napi::CallbackInfo& info) {
	return Napi::Number::New(info.Env(), glutGetMenu());
}

// void setMenu( int menu );
Napi::Value setMenu(const Napi::CallbackInfo& info) {
  Napi::Env env = info.Env();
  JS_ARGS(1);
	JS_ARG_TYPE(0, Number);
	JS_INT_ARG(0, menu);
  glutSetMenu(menu);
	return env.Undefined();
}

// void addMenuEntry( const char* label, int value );
Napi::Value addMenuEntry(const Napi::CallbackInfo& info) {
  Napi::Env env = info.Env();
  JS_ARGS(2);
	JS_ARG_TYPE(0, String);
  JS_ARG_TYPE(1, Number);
	JS_STR_ARG(0, label);
  JS_INT_ARG(1, value);
  glutAddMenuEntry(label.c_str(), value);
	return env.Undefined();
}

// void addSubMenu( const char* label, int subMenu );
Napi::Value addSubMenu(const Napi::CallbackInfo& info) {
  Napi::Env env = info.Env();
  JS_ARGS(2);
	JS_ARG_TYPE(0, String);
  JS_ARG_TYPE(1, Number);
	JS_STR_ARG(0, label);
  JS_INT_ARG(1, subMenu);
  glutAddSubMenu(label.c_str(), subMenu);
	return env.Undefined();
}

// void changeToMenuEntry( int item, const char* label, int value );
Napi::Value changeToMenuEntry(const Napi::CallbackInfo& info) {
  Napi::Env env = info.Env();
  JS_ARGS(3);
  JS_ARG_TYPE(0, Number);
	JS_ARG_TYPE(1, String);
  JS_ARG_TYPE(2, Number);
  JS_INT_ARG(0, item);
	JS_STR_ARG(1, label);
  JS_INT_ARG(2, value);
  glutChangeToMenuEntry(item, label.c_str(), value);
	return info.Env().Undefined();
}

// void changeToSubMenu( int item, const char* label, int value );
Napi::Value changeToSubMenu(const Napi::CallbackInfo& info) {
  Napi::Env env = info.Env();
  JS_ARGS(3);
	JS_ARG_TYPE(0, Number);
  JS_ARG_TYPE(1, String);
  JS_ARG_TYPE(2, Number);
	JS_INT_ARG(0, item);
  JS_STR_ARG(1, label);
  JS_INT_ARG(2, value);
  glutChangeToSubMenu(item, label.c_str(), value);
	return env.Undefined();
}

// void removeMenuItem( int item );
Napi::Value removeMenuItem(const Napi::CallbackInfo& info) {
  Napi::Env env = info.Env();
  JS_ARGS(1);
	JS_ARG_TYPE(0, Number);
	JS_INT_ARG(0, item);
  glutRemoveMenuItem(item);
	return env.Undefined();
}

// void attachMenu( int button );
Napi::Value attachMenu(const Napi::CallbackInfo& info) {
  Napi::Env env = info.Env();
  JS_ARGS(1);
	JS_ARG_TYPE(0, Number);
	JS_INT_ARG(0, button);
  glutAttachMenu(button);
	return env.Undefined();
}

// void detachMenu( int button );
Napi::Value detachMenu(const Napi::CallbackInfo& info) {
  Napi::Env env = info.Env();
  JS_ARGS(1);
	JS_ARG_TYPE(0, Number);
	JS_INT_ARG(0, button);
  glutDetachMenu(button);
	return env.Undefined();
}


/*
 * Global callback functions, see fg_callbacks.c
 */

class TimerFunctionNode {
  public:

  Napi::FunctionReference ref;
  int value;

  TimerFunctionNode(Napi::Function func, int value): value(value) {
    ref = Napi::Persistent(func);
    ref.SuppressDestruct();
  }

  ~TimerFunctionNode() {
    ref.Unref();
  }

  void m_timerFunc(int value) {
    if(!ref.IsEmpty()) {
     ref.Call({ Napi::Number::New(ref.Env(), value) });
    }
    delete this;
  }
};

std::map<int, TimerFunctionNode> m_timerFuncNodes;

void m_timerFunc(int timerNode) {
  TimerFunctionNode* node = reinterpret_cast<TimerFunctionNode*>(timerNode);
  if(node != NULL) {
    node->m_timerFunc(node->value);
    delete node;
  }
}

// void timerFunc( unsigned int time, void (* callback)( int ), int value );
Napi::Value timerFunc(const Napi::CallbackInfo& info) {
	Napi::Env env = info.Env();

	JS_ARGS(3);
	JS_ARG_TYPE(0, Number);
  JS_ARG_TYPE(1, Function);
  JS_ARG_TYPE(2, Number);
  JS_INT_ARG(0, time);
  Napi::Function func = info[1].As<Napi::Function>();
  JS_INT_ARG(2, value);
	glutTimerFunc(time, m_timerFunc, reinterpret_cast<int>(new TimerFunctionNode(func, value)));
	return env.Undefined();
}

Napi::FunctionReference m_idleFuncCBRef;

void m_idleFunc(void) {
  if(!m_idleFuncCBRef.IsEmpty()) {
    m_idleFuncCBRef.Call(NO_ARGS);
  }
}

// void idleFunc( void (* callback)( void ) );
Napi::Value idleFunc(const Napi::CallbackInfo& info) {
	Napi::Env env = info.Env();

	JS_ARGS(1);

  Napi::Function func = info[0].As<Napi::Function>();

  m_idleFuncCBRef = Napi::Persistent(func);
  m_idleFuncCBRef.SuppressDestruct();

	glutIdleFunc(m_idleFunc);

	return env.Undefined();
}


/*
 * Window-specific callback functions, see fg_callbacks.c
 */

Napi::FunctionReference m_keyboardFuncCBRef;

void m_keyboardFunc(unsigned char key, int x, int y) {
  if(!m_keyboardFuncCBRef.IsEmpty()) {
    m_keyboardFuncCBRef.Call({
      Napi::Number::New(m_keyboardFuncCBRef.Env(), key),
      Napi::Number::New(m_keyboardFuncCBRef.Env(), x),
      Napi::Number::New(m_keyboardFuncCBRef.Env(), y)
    });
  }
}

// function keyboardFunc(cb: (key: string, x: number, y: number) => void): void;
Napi::Value keyboardFunc(const Napi::CallbackInfo& info) {
	Napi::Env env = info.Env();
	JS_ARGS(1);
  Napi::Function func = info[0].As<Napi::Function>();
  m_keyboardFuncCBRef = Napi::Persistent(func);
  m_keyboardFuncCBRef.SuppressDestruct();
	glutKeyboardFunc(m_keyboardFunc);
	return env.Undefined();
}

Napi::FunctionReference m_specialFuncCBRef;

void m_specialFunc(int key, int x, int y) {
  if(!m_specialFuncCBRef.IsEmpty()) {
    m_specialFuncCBRef.Call({
      Napi::Number::New(m_specialFuncCBRef.Env(), key),
      Napi::Number::New(m_specialFuncCBRef.Env(), x),
      Napi::Number::New(m_specialFuncCBRef.Env(), y)
    });
  }
}

// function specialFunc(cb: (key: number, x: number, y: number) => void): void;
Napi::Value specialFunc(const Napi::CallbackInfo& info) {
	Napi::Env env = info.Env();
	JS_ARGS(1);
  Napi::Function func = info[0].As<Napi::Function>();
  m_specialFuncCBRef = Napi::Persistent(func);
  m_specialFuncCBRef.SuppressDestruct();
	glutSpecialFunc(m_specialFunc);
	return env.Undefined();
}


Napi::FunctionReference m_reshapeFuncCBRef;

void m_reshapeFunc(int width, int height) {
  if(!m_reshapeFuncCBRef.IsEmpty()) {
    m_reshapeFuncCBRef.Call({
      Napi::Number::New(m_reshapeFuncCBRef.Env(), width),
      Napi::Number::New(m_reshapeFuncCBRef.Env(), height)
    });
  }
}

// void reshapeFunc( void (* callback)( int, int ) );
Napi::Value reshapeFunc(const Napi::CallbackInfo& info) {
	Napi::Env env = info.Env();
	JS_ARGS(1);
  Napi::Function func = info[0].As<Napi::Function>();
  m_reshapeFuncCBRef = Napi::Persistent(func);
  m_reshapeFuncCBRef.SuppressDestruct();
	glutReshapeFunc(m_reshapeFunc);
	return env.Undefined();
}


Napi::FunctionReference m_visibilityFuncCBRef;

void m_visibilityFunc(int state) {
  if(!m_visibilityFuncCBRef.IsEmpty()) {
    m_visibilityFuncCBRef.Call({
      Napi::Number::New(m_visibilityFuncCBRef.Env(), state)
    });
  }
}

// function visibilityFunc(cb: (state: number) => void): void;
Napi::Value visibilityFunc(const Napi::CallbackInfo& info) {
	Napi::Env env = info.Env();
	JS_ARGS(1);
  Napi::Function func = info[0].As<Napi::Function>();
  m_visibilityFuncCBRef = Napi::Persistent(func);
  m_visibilityFuncCBRef.SuppressDestruct();
	glutReshapeFunc(m_reshapeFunc);
	return env.Undefined();
}

Napi::FunctionReference m_displayFuncCBRef;

void m_displayFunc(void) {
  if(!m_displayFuncCBRef.IsEmpty()) {
    m_displayFuncCBRef.Call(NO_ARGS);
  }
}

// void displayFunc( void (* callback)( void ) );
Napi::Value displayFunc(const Napi::CallbackInfo& info) {
	Napi::Env env = info.Env();
	JS_ARGS(1);
  Napi::Function func = info[0].As<Napi::Function>();
  m_displayFuncCBRef = Napi::Persistent(func);
  m_displayFuncCBRef.SuppressDestruct();
	glutDisplayFunc(m_displayFunc);
	return env.Undefined();
}

Napi::FunctionReference m_mouseFuncCBRef;

void m_mouseFunc(int button, int state, int x, int y) {
  if(!m_mouseFuncCBRef.IsEmpty()) {
    m_mouseFuncCBRef.Call({
      Napi::Number::New(m_mouseFuncCBRef.Env(), button),
      Napi::Number::New(m_mouseFuncCBRef.Env(), state),
      Napi::Number::New(m_mouseFuncCBRef.Env(), x),
      Napi::Number::New(m_mouseFuncCBRef.Env(), y)
    });
  }
}

// function mouseFunc(cb: (button: number, state: number, x: number, y: number) => void): void;
Napi::Value mouseFunc(const Napi::CallbackInfo& info) {
	Napi::Env env = info.Env();
	JS_ARGS(1);
  Napi::Function func = info[0].As<Napi::Function>();
  m_mouseFuncCBRef = Napi::Persistent(func);
  m_mouseFuncCBRef.SuppressDestruct();
	glutMouseFunc(m_mouseFunc);
	return env.Undefined();
}


Napi::FunctionReference m_motionFuncCBRef;

void m_motionFunc(int x, int y) {
  if(!m_motionFuncCBRef.IsEmpty()) {
    m_motionFuncCBRef.Call({
      Napi::Number::New(m_motionFuncCBRef.Env(), x),
      Napi::Number::New(m_motionFuncCBRef.Env(), y)
    });
  }
}


// function motionFunc(cb: (x: number, y: number) => void): void;
Napi::Value motionFunc(const Napi::CallbackInfo& info) {
	Napi::Env env = info.Env();
	JS_ARGS(1);
  Napi::Function func = info[0].As<Napi::Function>();
  m_motionFuncCBRef = Napi::Persistent(func);
  m_motionFuncCBRef.SuppressDestruct();
	glutMotionFunc(m_motionFunc);
	return env.Undefined();
}

Napi::FunctionReference m_passiveMotionFuncCBRef;

void m_passiveMotionFunc(int x, int y) {
  if(!m_passiveMotionFuncCBRef.IsEmpty()) {
    m_passiveMotionFuncCBRef.Call({
      Napi::Number::New(m_passiveMotionFuncCBRef.Env(), x),
      Napi::Number::New(m_passiveMotionFuncCBRef.Env(), y)
    });
  }
}

// function passiveMotionFunc(cb: (x: number, y: number) => void): void;
Napi::Value passiveMotionFunc(const Napi::CallbackInfo& info) {
	Napi::Env env = info.Env();
	JS_ARGS(1);
  Napi::Function func = info[0].As<Napi::Function>();
  m_passiveMotionFuncCBRef = Napi::Persistent(func);
  m_passiveMotionFuncCBRef.SuppressDestruct();
	glutPassiveMotionFunc(m_passiveMotionFunc);
	return env.Undefined();
}



Napi::FunctionReference m_entryFuncCBRef;

void m_entryFunc(int state) {
  if(!m_entryFuncCBRef.IsEmpty()) {
    m_entryFuncCBRef.Call({
      Napi::Number::New(m_entryFuncCBRef.Env(), state)
    });
  }
}

// function entryFunc(cb: (state: number) => void): void;
Napi::Value entryFunc(const Napi::CallbackInfo& info) {
	Napi::Env env = info.Env();
	JS_ARGS(1);
  Napi::Function func = info[0].As<Napi::Function>();
  m_entryFuncCBRef = Napi::Persistent(func);
  m_entryFuncCBRef.SuppressDestruct();
	glutEntryFunc(m_entryFunc);
	return env.Undefined();
}

Napi::FunctionReference m_keyboardUpFuncCBRef;

void m_keyboardUpFunc(unsigned char key, int x, int y) {
  if(!m_keyboardUpFuncCBRef.IsEmpty()) {
    m_keyboardUpFuncCBRef.Call({
      Napi::Number::New(m_keyboardUpFuncCBRef.Env(), key),
      Napi::Number::New(m_keyboardUpFuncCBRef.Env(), x),
      Napi::Number::New(m_keyboardUpFuncCBRef.Env(), y)
    });
  }
}

// function keyboardUpFunc(cb: (key: string, x: number, y: number) => void): void;
Napi::Value keyboardUpFunc(const Napi::CallbackInfo& info) {
	Napi::Env env = info.Env();
	JS_ARGS(1);
  Napi::Function func = info[0].As<Napi::Function>();
  m_keyboardUpFuncCBRef = Napi::Persistent(func);
  m_keyboardUpFuncCBRef.SuppressDestruct();
	glutKeyboardUpFunc(m_keyboardUpFunc);
	return env.Undefined();
}

Napi::FunctionReference m_specialUpFuncCBRef;
void m_specialUpFunc(int key, int x, int y) {
  if(!m_specialUpFuncCBRef.IsEmpty()) {
    m_specialUpFuncCBRef.Call({
      Napi::Number::New(m_specialUpFuncCBRef.Env(), key),
      Napi::Number::New(m_specialUpFuncCBRef.Env(), x),
      Napi::Number::New(m_specialUpFuncCBRef.Env(), y)
    });
  }
}

// function specialUpFunc(cb: (key: number, x: number, y: number) => void): void;
Napi::Value specialUpFunc(const Napi::CallbackInfo& info) {
	Napi::Env env = info.Env();
	JS_ARGS(1);
  Napi::Function func = info[0].As<Napi::Function>();
  m_specialUpFuncCBRef = Napi::Persistent(func);
  m_specialUpFuncCBRef.SuppressDestruct();
	glutSpecialUpFunc(m_specialUpFunc);
	return env.Undefined();
}

Napi::FunctionReference m_joystickFuncCBRef;
void m_joystickFunc(unsigned int buttonMask, int x, int y, int z) {
  if(!m_joystickFuncCBRef.IsEmpty()) {
    m_joystickFuncCBRef.Call({
      Napi::Number::New(m_joystickFuncCBRef.Env(), buttonMask),
      Napi::Number::New(m_joystickFuncCBRef.Env(), x),
      Napi::Number::New(m_joystickFuncCBRef.Env(), y),
      Napi::Number::New(m_joystickFuncCBRef.Env(), z)
    });
  }
}

// function joystickFunc(cb: (buttonMask: number, x: number, y: number, z: number) => void, pollInterval: number): void;
Napi::Value joystickFunc(const Napi::CallbackInfo& info) {
	Napi::Env env = info.Env();
	JS_ARGS(2);
	JS_ARG_TYPE(0, Function);
  JS_ARG_TYPE(1, Number);
  Napi::Function func = info[0].As<Napi::Function>();
  JS_INT_ARG(1, pollInterval);
  m_joystickFuncCBRef = Napi::Persistent(func);
  m_joystickFuncCBRef.SuppressDestruct();
	glutJoystickFunc(m_joystickFunc, pollInterval);
	return env.Undefined();
}
Napi::FunctionReference m_menuStateFuncCBRef;

void m_menuStateFunc(int status) {
  if(!m_menuStateFuncCBRef.IsEmpty()) {
    m_menuStateFuncCBRef.Call({
      Napi::Number::New(m_menuStateFuncCBRef.Env(), status)
    });
  }
}

// function menuStateFunc(cb: (status: number) => void): void;
Napi::Value menuStateFunc(const Napi::CallbackInfo& info) {
	Napi::Env env = info.Env();
	JS_ARGS(1);
  Napi::Function func = info[0].As<Napi::Function>();
  m_menuStateFuncCBRef = Napi::Persistent(func);
  m_menuStateFuncCBRef.SuppressDestruct();
	glutMenuStateFunc(m_menuStateFunc);
	return env.Undefined();
}

Napi::FunctionReference m_menuStatusFuncCBRef;
void m_menuStatusFunc(int status, int x, int y) {
  if(!m_menuStatusFuncCBRef.IsEmpty()) {
    m_menuStatusFuncCBRef.Call({
      Napi::Number::New(m_menuStatusFuncCBRef.Env(), status),
      Napi::Number::New(m_menuStatusFuncCBRef.Env(), x),
      Napi::Number::New(m_menuStatusFuncCBRef.Env(), y)
    });
  }
}

// function menuStatusFunc(cb: (status: number, x: number, y: number) => void): void;
Napi::Value menuStatusFunc(const Napi::CallbackInfo& info) {
	Napi::Env env = info.Env();
	JS_ARGS(1);
  Napi::Function func = info[0].As<Napi::Function>();
  m_menuStatusFuncCBRef = Napi::Persistent(func);
  m_menuStatusFuncCBRef.SuppressDestruct();
	glutMenuStatusFunc(m_menuStatusFunc);
	return env.Undefined();
}

Napi::FunctionReference m_overlayDisplayFuncCBRef;

void m_overlayDisplayFunc(void) {
  if(!m_overlayDisplayFuncCBRef.IsEmpty()) {
    m_overlayDisplayFuncCBRef.Call(NO_ARGS);
  }
}

// function overlayDisplayFunc(cb: () => void): void;
Napi::Value overlayDisplayFunc(const Napi::CallbackInfo& info) {
	Napi::Env env = info.Env();
	JS_ARGS(1);
  Napi::Function func = info[0].As<Napi::Function>();
  m_overlayDisplayFuncCBRef = Napi::Persistent(func);
  m_overlayDisplayFuncCBRef.SuppressDestruct();
	glutOverlayDisplayFunc(m_overlayDisplayFunc);
	return env.Undefined();
}

Napi::FunctionReference m_windowStatusFuncCBRef;

void m_windowStatusFunc(int state) {
  if(!m_windowStatusFuncCBRef.IsEmpty()) {
    m_windowStatusFuncCBRef.Call({
      Napi::Number::New(m_windowStatusFuncCBRef.Env(), state)
    });
  }
}

// function windowStatusFunc(cb: (state: number) => void): void;
Napi::Value windowStatusFunc(const Napi::CallbackInfo& info) {
	Napi::Env env = info.Env();
	JS_ARGS(1);
  Napi::Function func = info[0].As<Napi::Function>();
  m_windowStatusFuncCBRef = Napi::Persistent(func);
  m_windowStatusFuncCBRef.SuppressDestruct();
	glutWindowStatusFunc(m_windowStatusFunc);
	return env.Undefined();
}

Napi::FunctionReference m_spaceballMotionFuncCBRef;
void m_spaceballMotionFunc(int x, int y, int z) {
  if(!m_spaceballMotionFuncCBRef.IsEmpty()) {
    m_spaceballMotionFuncCBRef.Call({
      Napi::Number::New(m_spaceballMotionFuncCBRef.Env(), x),
      Napi::Number::New(m_spaceballMotionFuncCBRef.Env(), y),
      Napi::Number::New(m_spaceballMotionFuncCBRef.Env(), z)
    });
  }
}

// function spaceballMotionFunc(cb: (x: number, y: number, z: number) => void): void;
Napi::Value spaceballMotionFunc(const Napi::CallbackInfo& info) {
	Napi::Env env = info.Env();
	JS_ARGS(1);
  Napi::Function func = info[0].As<Napi::Function>();
  m_spaceballMotionFuncCBRef = Napi::Persistent(func);
  m_spaceballMotionFuncCBRef.SuppressDestruct();
	glutSpaceballMotionFunc(m_spaceballMotionFunc);
	return env.Undefined();
}

Napi::FunctionReference m_spaceballRotateFuncCBRef;

void m_spaceballRotateFunc(int x, int y, int z) {
  if(!m_spaceballRotateFuncCBRef.IsEmpty()) {
    m_spaceballRotateFuncCBRef.Call({
      Napi::Number::New(m_spaceballRotateFuncCBRef.Env(), x),
      Napi::Number::New(m_spaceballRotateFuncCBRef.Env(), y),
      Napi::Number::New(m_spaceballRotateFuncCBRef.Env(), z)
    });
  }
}

// void spaceballRotateFunc( void (* callback)( int, int, int ) );
Napi::Value spaceballRotateFunc(const Napi::CallbackInfo& info) {
	Napi::Env env = info.Env();
	JS_ARGS(1);
  Napi::Function func = info[0].As<Napi::Function>();
  m_spaceballRotateFuncCBRef = Napi::Persistent(func);
  m_spaceballRotateFuncCBRef.SuppressDestruct();
	glutSpaceballRotateFunc(m_spaceballRotateFunc);
	return env.Undefined();
}

Napi::FunctionReference m_spaceballButtonFuncCBRef;
void m_spaceballButtonFunc(int button, int state) {
  if(!m_spaceballButtonFuncCBRef.IsEmpty()) {
    m_spaceballButtonFuncCBRef.Call({
      Napi::Number::New(m_spaceballButtonFuncCBRef.Env(), button),
      Napi::Number::New(m_spaceballButtonFuncCBRef.Env(), state)
    });
  }
}

// function spaceballButtonFunc(cb: (button: number, state: number) => void): void;
Napi::Value spaceballButtonFunc(const Napi::CallbackInfo& info) {
	Napi::Env env = info.Env();
	JS_ARGS(1);
  Napi::Function func = info[0].As<Napi::Function>();
  m_spaceballButtonFuncCBRef = Napi::Persistent(func);
  m_spaceballButtonFuncCBRef.SuppressDestruct();
	glutSpaceballButtonFunc(m_spaceballButtonFunc);
	return env.Undefined();
}

Napi::FunctionReference m_buttonBoxFuncCBRef;
void m_buttonBoxFunc(int button, int state) {
  if(!m_buttonBoxFuncCBRef.IsEmpty()) {
    m_buttonBoxFuncCBRef.Call({
      Napi::Number::New(m_buttonBoxFuncCBRef.Env(), button),
      Napi::Number::New(m_buttonBoxFuncCBRef.Env(), state)
    });
  }
}

// function buttonBoxFunc(cb: (button: number, state: number) => void): void;
Napi::Value buttonBoxFunc(const Napi::CallbackInfo& info) {
	Napi::Env env = info.Env();
	JS_ARGS(1);
  Napi::Function func = info[0].As<Napi::Function>();
  m_buttonBoxFuncCBRef = Napi::Persistent(func);
  m_buttonBoxFuncCBRef.SuppressDestruct();
	glutButtonBoxFunc(m_buttonBoxFunc);
	return env.Undefined();
}

Napi::FunctionReference m_dialsFuncCBRef;
void m_dialsFunc(int dial, int value) {
  if(!m_dialsFuncCBRef.IsEmpty()) {
    m_dialsFuncCBRef.Call({
      Napi::Number::New(m_dialsFuncCBRef.Env(), dial),
      Napi::Number::New(m_dialsFuncCBRef.Env(), value)
    });
  }
}

// function dialsFunc(cb: (dial: number, value: number) => void): void;
Napi::Value dialsFunc(const Napi::CallbackInfo& info) {
	Napi::Env env = info.Env();
	JS_ARGS(1);
  Napi::Function func = info[0].As<Napi::Function>();
  m_dialsFuncCBRef = Napi::Persistent(func);
  m_dialsFuncCBRef.SuppressDestruct();
	glutDialsFunc(m_dialsFunc);
	return env.Undefined();
}

Napi::FunctionReference m_tabletMotionFuncCBRef;
void m_tabletMotionFunc(int x, int y) {
  if(!m_tabletMotionFuncCBRef.IsEmpty()) {
    m_tabletMotionFuncCBRef.Call({
      Napi::Number::New(m_tabletMotionFuncCBRef.Env(), x),
      Napi::Number::New(m_tabletMotionFuncCBRef.Env(), y)
    });
  }
}

// function tabletMotionFunc(cb: (x: number, y: number) => void): void;
Napi::Value tabletMotionFunc(const Napi::CallbackInfo& info) {
	Napi::Env env = info.Env();
	JS_ARGS(1);
  Napi::Function func = info[0].As<Napi::Function>();
  m_tabletMotionFuncCBRef = Napi::Persistent(func);
  m_tabletMotionFuncCBRef.SuppressDestruct();
	glutTabletMotionFunc(m_tabletMotionFunc);
	return env.Undefined();
}

Napi::FunctionReference m_tabletButtonFuncCBRef;

void m_tabletButtonFunc(int button, int state, int x, int y) {
  if(!m_tabletMotionFuncCBRef.IsEmpty()) {
    m_tabletMotionFuncCBRef.Call({
      Napi::Number::New(m_tabletMotionFuncCBRef.Env(), button),
      Napi::Number::New(m_tabletMotionFuncCBRef.Env(), state),
      Napi::Number::New(m_tabletMotionFuncCBRef.Env(), x),
      Napi::Number::New(m_tabletMotionFuncCBRef.Env(), y)
    });
  }
}

// function tabletButtonFunc(cb: (button: number, state: number, x: number, y: number) => void): void;
Napi::Value tabletButtonFunc(const Napi::CallbackInfo& info) {
	Napi::Env env = info.Env();
	JS_ARGS(1);
  Napi::Function func = info[0].As<Napi::Function>();
  m_tabletButtonFuncCBRef = Napi::Persistent(func);
  m_tabletButtonFuncCBRef.SuppressDestruct();
	glutTabletButtonFunc(m_tabletButtonFunc);
	return env.Undefined();
}

/*
 * State setting and retrieval functions, see fg_state.c
 */
// int  get( GLenum query );
Napi::Value get(const Napi::CallbackInfo& info) {
	Napi::Env env = info.Env();
	JS_ARGS(1);
	JS_ARG_TYPE(0, Number);
	JS_UINT_ARG(0, query);
	return Napi::Number::New(info.Env(), glutGet(query));
}

// int  deviceGet( GLenum query );
Napi::Value deviceGet(const Napi::CallbackInfo& info) {
	Napi::Env env = info.Env();
	JS_ARGS(1);
	JS_ARG_TYPE(0, Number);
	JS_UINT_ARG(0, query);
	return Napi::Number::New(info.Env(), glutDeviceGet(query));
}

// int  getModifiers( void );
Napi::Value getModifiers(const Napi::CallbackInfo& info) {
  Napi::Env env = info.Env();
	return Napi::Number::New(info.Env(), glutGetModifiers());
}

// int  layerGet( GLenum query );
Napi::Value layerGet(const Napi::CallbackInfo& info) {
	Napi::Env env = info.Env();
	JS_ARGS(1);
	JS_ARG_TYPE(0, Number);
	JS_UINT_ARG(0, query);
	return Napi::Number::New(info.Env(), glutLayerGet(query));
}

/*
 * Font stuff, see fg_font.c
 */
// void bitmapCharacter( void* font, int character );
Napi::Value bitmapCharacter(const Napi::CallbackInfo& info) {
  Napi::Env env = info.Env();
	JS_ARGS(2);
	JS_ARG_TYPE(0, Number);
  JS_ARG_TYPE(1, Number);
  JS_PVOID_ARG(0, font);
  JS_INT_ARG(1, character);
  glutBitmapCharacter(font, character);
	return env.Undefined();
}

// int  bitmapWidth( void* font, int character );
Napi::Value bitmapWidth(const Napi::CallbackInfo& info) {
  Napi::Env env = info.Env();
	JS_ARGS(2);
	JS_ARG_TYPE(0, Number);
  JS_ARG_TYPE(1, Number);
  JS_PVOID_ARG(0, font);
  JS_INT_ARG(1, character);
	return Napi::Number::New(env, glutBitmapWidth(font, character));
}

// void strokeCharacter( void* font, int character );
Napi::Value strokeCharacter(const Napi::CallbackInfo& info) {
  Napi::Env env = info.Env();
	JS_ARGS(2);
	JS_ARG_TYPE(0, Number);
  JS_ARG_TYPE(1, Number);
  JS_PVOID_ARG(0, font);
  JS_INT_ARG(1, character);
  glutStrokeCharacter(font, character);
	return env.Undefined();
}

// int  strokeWidth( void* font, int character );
Napi::Value strokeWidth(const Napi::CallbackInfo& info) {
  Napi::Env env = info.Env();
	JS_ARGS(2);
	JS_ARG_TYPE(0, Number);
  JS_ARG_TYPE(1, Number);
  JS_PVOID_ARG(0, font);
  JS_INT_ARG(1, character);
	return Napi::Number::New(env, glutStrokeWidth(font, character));
}

// GLfloat strokeWidthf( void* font, int character ); /* GLUT 3.8 */
Napi::Value strokeWidthf(const Napi::CallbackInfo& info) {
  Napi::Env env = info.Env();
	JS_ARGS(2);
	JS_ARG_TYPE(0, Number);
  JS_ARG_TYPE(1, Number);
  JS_PVOID_ARG(0, font);
  JS_INT_ARG(1, character);
	return Napi::Number::New(env, glutStrokeWidthf(font, character));
}

// int  bitmapLength( void* font, const unsigned char* string );
Napi::Value bitmapLength(const Napi::CallbackInfo& info) {
  Napi::Env env = info.Env();
	JS_ARGS(2);
	JS_ARG_TYPE(0, Number);
  JS_ARG_TYPE(1, String);
  JS_PVOID_ARG(0, font);
  JS_STR_ARG(1, str);
	return Napi::Number::New(env, glutBitmapLength(font, (const unsigned char *)str.c_str()));
}

// int  strokeLength( void* font, const unsigned char* string );
Napi::Value strokeLength(const Napi::CallbackInfo& info) {
  Napi::Env env = info.Env();
	JS_ARGS(2);
	JS_ARG_TYPE(0, Number);
  JS_ARG_TYPE(1, String);
  JS_PVOID_ARG(0, font);
  JS_STR_ARG(1, str);
	return Napi::Number::New(env, glutStrokeLength(font, (const unsigned char *)str.c_str()));
}

// GLfloat FGAPIENTRY strokeLengthf( void* font, const unsigned char *string ); /* GLUT 3.8 */
Napi::Value strokeLengthf(const Napi::CallbackInfo& info) {
  Napi::Env env = info.Env();
	JS_ARGS(2);
	JS_ARG_TYPE(0, Number);
  JS_ARG_TYPE(1, String);
  JS_LONG_ARG(0, font);
  JS_STR_ARG(1, str);
	return Napi::Number::New(env, glutStrokeLengthf((void*)font, (const unsigned char *)str.c_str()));
}

/*
 * Geometry functions, see fg_geometry.c
 */

// void wireCube( double size );
Napi::Value wireCube(const Napi::CallbackInfo& info) {
  Napi::Env env = info.Env();
	JS_ARGS(1);
	JS_ARG_TYPE(0, Number);
  JS_DOUBLE_ARG(0, size);
  glutWireCube(size);
	return env.Undefined();
}

// void solidCube( double size );
Napi::Value solidCube(const Napi::CallbackInfo& info) {
  Napi::Env env = info.Env();
	JS_ARGS(1);
	JS_ARG_TYPE(0, Number);
  JS_DOUBLE_ARG(0, size);
  glutSolidCube(size);
	return env.Undefined();
}

// void wireSphere( double radius, GLint slices, GLint stacks );
Napi::Value wireSphere(const Napi::CallbackInfo& info) {
  Napi::Env env = info.Env();
	JS_ARGS(3);
	JS_ARG_TYPE(0, Number);
  JS_ARG_TYPE(1, Number);
  JS_ARG_TYPE(2, Number);
  JS_DOUBLE_ARG(0, radius);
  JS_GLINT_ARG(1, slices);
  JS_GLINT_ARG(2, stacks);
  glutWireSphere(radius, slices, stacks);
	return env.Undefined();
}

// void solidSphere( double radius, GLint slices, GLint stacks );
Napi::Value solidSphere(const Napi::CallbackInfo& info) {
  Napi::Env env = info.Env();
	JS_ARGS(3);
	JS_ARG_TYPE(0, Number);
  JS_ARG_TYPE(1, Number);
  JS_ARG_TYPE(2, Number);
  JS_DOUBLE_ARG(0, radius);
  JS_GLINT_ARG(1, slices);
  JS_GLINT_ARG(2, stacks);
  glutSolidSphere(radius, slices, stacks);
	return env.Undefined();
}

// void wireCone( double base, double height, GLint slices, GLint stacks );
Napi::Value wireCone(const Napi::CallbackInfo& info) {
  Napi::Env env = info.Env();
	JS_ARGS(4);
	JS_ARG_TYPE(0, Number);
  JS_ARG_TYPE(1, Number);
  JS_ARG_TYPE(2, Number);
  JS_ARG_TYPE(3, Number);
  JS_DOUBLE_ARG(0, base);
  JS_DOUBLE_ARG(1, height);
  JS_GLINT_ARG(2, slices);
  JS_GLINT_ARG(3, stacks);
  glutWireCone(base, height, slices, stacks);
	return env.Undefined();
}

// void solidCone( double base, double height, GLint slices, GLint stacks );
Napi::Value solidCone(const Napi::CallbackInfo& info) {
  Napi::Env env = info.Env();
	JS_ARGS(4);
	JS_ARG_TYPE(0, Number);
  JS_ARG_TYPE(1, Number);
  JS_ARG_TYPE(2, Number);
  JS_ARG_TYPE(3, Number);
  JS_DOUBLE_ARG(0, base);
  JS_DOUBLE_ARG(1, height);
  JS_GLINT_ARG(2, slices);
  JS_GLINT_ARG(3, stacks);
  glutSolidCone(base, height, slices, stacks);
	return env.Undefined();
}

// void wireTorus( double innerRadius, double outerRadius, GLint sides, GLint rings );
Napi::Value wireTorus(const Napi::CallbackInfo& info) {
  Napi::Env env = info.Env();
	JS_ARGS(4);
	JS_ARG_TYPE(0, Number);
  JS_ARG_TYPE(1, Number);
  JS_ARG_TYPE(2, Number);
  JS_ARG_TYPE(3, Number);
  JS_DOUBLE_ARG(0, innerRadius);
  JS_DOUBLE_ARG(1, outerRadius);
  JS_GLINT_ARG(2, sides);
  JS_GLINT_ARG(3, rings);
  glutWireTorus(innerRadius, outerRadius, sides, rings);
	return env.Undefined();
}

// void solidTorus( double innerRadius, double outerRadius, GLint sides, GLint rings );
Napi::Value solidTorus(const Napi::CallbackInfo& info) {
  Napi::Env env = info.Env();
	JS_ARGS(4);
	JS_ARG_TYPE(0, Number);
  JS_ARG_TYPE(1, Number);
  JS_ARG_TYPE(2, Number);
  JS_ARG_TYPE(3, Number);
  JS_DOUBLE_ARG(0, innerRadius);
  JS_DOUBLE_ARG(1, outerRadius);
  JS_GLINT_ARG(2, sides);
  JS_GLINT_ARG(3, rings);
  glutSolidTorus(innerRadius, outerRadius, sides, rings);
	return env.Undefined();
}

// void wireDodecahedron( void );
Napi::Value wireDodecahedron(const Napi::CallbackInfo& info) {
  glutWireDodecahedron();
	return info.Env().Undefined();
}

// void solidDodecahedron( void );
Napi::Value solidDodecahedron(const Napi::CallbackInfo& info) {
  glutSolidDodecahedron();
	return info.Env().Undefined();
}

// void wireOctahedron( void );
Napi::Value wireOctahedron(const Napi::CallbackInfo& info) {
  glutWireOctahedron();
	return info.Env().Undefined();
}

// void solidOctahedron( void );
Napi::Value solidOctahedron(const Napi::CallbackInfo& info) {
  glutSolidOctahedron();
	return info.Env().Undefined();
}

// void wireTetrahedron( void );
Napi::Value wireTetrahedron(const Napi::CallbackInfo& info) {
  glutWireTetrahedron();
	return info.Env().Undefined();
}

// void solidTetrahedron( void );
Napi::Value solidTetrahedron(const Napi::CallbackInfo& info) {
  glutSolidTetrahedron();
	return info.Env().Undefined();
}

// void wireIcosahedron( void );
Napi::Value wireIcosahedron(const Napi::CallbackInfo& info) {
  glutWireIcosahedron();
	return info.Env().Undefined();
}

// void solidIcosahedron( void );
Napi::Value solidIcosahedron(const Napi::CallbackInfo& info) {
  glutSolidIcosahedron();
	return info.Env().Undefined();
}

/*
 * Teapot rendering functions, found in fg_teapot.c
 * NB: front facing polygons have clockwise winding, not counter clockwise
 */
// void wireTeapot( double size );
Napi::Value wireTeapot(const Napi::CallbackInfo& info) {
  Napi::Env env = info.Env();
	JS_ARGS(1);
	JS_ARG_TYPE(0, Number);
  JS_DOUBLE_ARG(0, size);
  glutWireTeapot(size);
	return env.Undefined();
}

// void solidTeapot( double size );
Napi::Value solidTeapot(const Napi::CallbackInfo& info) {
  Napi::Env env = info.Env();
	JS_ARGS(1);
	JS_ARG_TYPE(0, Number);
  JS_DOUBLE_ARG(0, size);
  glutSolidTeapot(size);
	return env.Undefined();
}


/*
 * Game mode functions, see fg_gamemode.c
 */
// void gameModeString( const char* string );
Napi::Value gameModeString(const Napi::CallbackInfo& info) {
  Napi::Env env = info.Env();
	JS_ARGS(1);
	JS_ARG_TYPE(0, String);
  JS_STR_ARG(0, str);
  glutGameModeString(str.c_str());
	return env.Undefined();
}

// int  enterGameMode( void );
Napi::Value enterGameMode(const Napi::CallbackInfo& info) {
  return Napi::Number::New(info.Env(), glutEnterGameMode());
}

// void leaveGameMode( void );
Napi::Value leaveGameMode(const Napi::CallbackInfo& info) {
  glutLeaveGameMode();
	return info.Env().Undefined();
}

// int  gameModeGet( GLenum query );
Napi::Value gameModeGet(const Napi::CallbackInfo& info) {
  Napi::Env env = info.Env();
	JS_ARGS(1);
	JS_ARG_TYPE(0, Number);
  JS_GLENUM_ARG(0, query);
  glutGameModeGet(query);
	return env.Undefined();
}

/*
 * Video resize functions, see fg_videoresize.c
 */
// int  videoResizeGet( GLenum query );
Napi::Value videoResizeGet(const Napi::CallbackInfo& info) {
  Napi::Env env = info.Env();
	JS_ARGS(1);
	JS_ARG_TYPE(0, Number);
  JS_GLENUM_ARG(0, query);
  glutVideoResizeGet(query);
	return env.Undefined();
}

// void setupVideoResizing( void );
Napi::Value setupVideoResizing(const Napi::CallbackInfo& info) {
  glutSetupVideoResizing();
	return info.Env().Undefined();
}

// void stopVideoResizing( void );
Napi::Value stopVideoResizing(const Napi::CallbackInfo& info) {
  glutStopVideoResizing();
	return info.Env().Undefined();
}

// void videoResize( int x, int y, int width, int height );]
Napi::Value videoResize(const Napi::CallbackInfo& info) {
  Napi::Env env = info.Env();
	JS_ARGS(4);
	JS_ARG_TYPE(0, Number);
  JS_ARG_TYPE(1, Number);
  JS_ARG_TYPE(2, Number);
  JS_ARG_TYPE(4, Number);
	JS_INT_ARG(0, x);
  JS_INT_ARG(1, y);
  JS_INT_ARG(2, width);
  JS_INT_ARG(3, height);
  glutVideoResize(x, y, width, height);
	return env.Undefined();
}

// void videoPan( int x, int y, int width, int height );
Napi::Value videoPan(const Napi::CallbackInfo& info) {
  Napi::Env env = info.Env();
	JS_ARGS(4);
	JS_ARG_TYPE(0, Number);
  JS_ARG_TYPE(1, Number);
  JS_ARG_TYPE(2, Number);
  JS_ARG_TYPE(4, Number);
	JS_INT_ARG(0, x);
  JS_INT_ARG(1, y);
  JS_INT_ARG(2, width);
  JS_INT_ARG(3, height);
  glutVideoPan(x, y, width, height);
	return env.Undefined();
}

/*
 * Colormap functions, see fg_misc.c
 */
// void setColor( int color, GLfloat red, GLfloat green, GLfloat blue );
Napi::Value setColor(const Napi::CallbackInfo& info) {
	Napi::Env env = info.Env();
	JS_ARGS(4);
	JS_ARG_TYPE(0, Number);
  JS_ARG_TYPE(1, Number);
  JS_ARG_TYPE(2, Number);
  JS_ARG_TYPE(4, Number);
	JS_INT_ARG(0, color);
  JS_GLFLOAT_ARG(1, red);
  JS_GLFLOAT_ARG(2, green);
  JS_GLFLOAT_ARG(3, blue);
  glutSetColor(color, red, green, blue);
	return env.Undefined();
}

// GLfloat FGAPIENTRY getColor( int color, int component );
Napi::Value getColor(const Napi::CallbackInfo& info) {
	Napi::Env env = info.Env();
	JS_ARGS(2);
	JS_ARG_TYPE(0, Number);
  JS_ARG_TYPE(1, Number);
	JS_INT_ARG(0, color);
  JS_INT_ARG(1, component);
	return Napi::Number::New(env, glutGetColor(color, component));
}

// void copyColormap( int window );
Napi::Value copyColormap(const Napi::CallbackInfo& info) {
	Napi::Env env = info.Env();
	JS_ARGS(1);
	JS_ARG_TYPE(0, Number);
	JS_INT_ARG(0, window);
  glutCopyColormap(window);
	return info.Env().Undefined();
}

/*
 * Misc keyboard and joystick functions, see fg_misc.c
 */
// void ignoreKeyRepeat( int ignore );
Napi::Value ignoreKeyRepeat(const Napi::CallbackInfo& info) {
	Napi::Env env = info.Env();
	JS_ARGS(1);
	JS_ARG_TYPE(0, Number);
	JS_INT_ARG(0, ignore);
  glutIgnoreKeyRepeat(ignore);
	return info.Env().Undefined();
}

// void setKeyRepeat( int repeatMode );
Napi::Value setKeyRepeat(const Napi::CallbackInfo& info) {
	Napi::Env env = info.Env();
	JS_ARGS(1);
	JS_ARG_TYPE(0, Number);
	JS_INT_ARG(0, repeatMode);
  glutSetKeyRepeat(repeatMode);
	return info.Env().Undefined();
}

// void forceJoystickFunc( void );
Napi::Value forceJoystickFunc(const Napi::CallbackInfo& info) {
  glutForceJoystickFunc();
	return info.Env().Undefined();
}

/*
 * Misc functions, see fg_misc.c
 */
// extensionSupported(extension: string ): number;
Napi::Value extensionSupported(const Napi::CallbackInfo& info) {
	Napi::Env env = info.Env();
	JS_ARGS(1);
	JS_ARG_TYPE(0, String);
	JS_STR_ARG(0, extension);
	return Napi::Number::New(info.Env(), glutExtensionSupported(extension.c_str()));
}

//  reportErrors(): void;
Napi::Value reportErrors(const Napi::CallbackInfo& info) {
  glutReportErrors();
	return info.Env().Undefined();
}


//  reportErrors(): void;
Napi::Value sleep(const Napi::CallbackInfo& info) {
	Napi::Env env = info.Env();
	JS_ARGS(1);
	JS_ARG_TYPE(0, String);
	JS_INT_ARG(0, milliseconds);
  Sleep(milliseconds);
	return info.Env().Undefined();
}


Napi::Value execState(const Napi::CallbackInfo& info) {
	Napi::Env env = info.Env();
	return Napi::Number::New(info.Env(), glutExecState());
}


Napi::Value mainLoopBegin(const Napi::CallbackInfo& info) {
	glutMainLoopBegin();
	return info.Env().Undefined();
}
Napi::Value mainLoopStep(const Napi::CallbackInfo& info) {
	glutMainLoopStep();
	return info.Env().Undefined();
}
Napi::Value mainLoopEnd(const Napi::CallbackInfo& info) {
	glutMainLoopEnd();
	return info.Env().Undefined();
}

//

Napi::Value focus(const Napi::CallbackInfo& info) {
	//JS_INT_ARG(0, windowID);
	//SFG_Window* window = fgWindowByID(windowID);
	return info.Env().Undefined();
}

Napi::Object Init(Napi::Env env, Napi::Object exports) {

  /*
  * GLUT API macro definitions -- the special key codes:
  */
  JS_GLUT_CONSTANT(KEY_F1);
  JS_GLUT_CONSTANT(KEY_F2);
  JS_GLUT_CONSTANT(KEY_F3);
  JS_GLUT_CONSTANT(KEY_F4);
  JS_GLUT_CONSTANT(KEY_F5);
  JS_GLUT_CONSTANT(KEY_F6);
  JS_GLUT_CONSTANT(KEY_F7);
  JS_GLUT_CONSTANT(KEY_F8);
  JS_GLUT_CONSTANT(KEY_F9);
  JS_GLUT_CONSTANT(KEY_F10);
  JS_GLUT_CONSTANT(KEY_F11);
  JS_GLUT_CONSTANT(KEY_F12);
  JS_GLUT_CONSTANT(KEY_LEFT);
  JS_GLUT_CONSTANT(KEY_UP);
  JS_GLUT_CONSTANT(KEY_RIGHT);
  JS_GLUT_CONSTANT(KEY_DOWN);
  JS_GLUT_CONSTANT(KEY_PAGE_UP);
  JS_GLUT_CONSTANT(KEY_PAGE_DOWN);
  JS_GLUT_CONSTANT(KEY_HOME);
  JS_GLUT_CONSTANT(KEY_END);
  JS_GLUT_CONSTANT(KEY_INSERT);

  /*
  * GLUT API macro definitions -- mouse state definitions
  */
  JS_GLUT_CONSTANT(LEFT_BUTTON);
  JS_GLUT_CONSTANT(MIDDLE_BUTTON);
  JS_GLUT_CONSTANT(RIGHT_BUTTON);
  JS_GLUT_CONSTANT(DOWN);
  JS_GLUT_CONSTANT(UP);
  JS_GLUT_CONSTANT(LEFT);
  JS_GLUT_CONSTANT(ENTERED);

  /*
  * GLUT API macro definitions -- the display mode definitions
  */
  JS_GLUT_CONSTANT(RGB);
  JS_GLUT_CONSTANT(RGBA);
  JS_GLUT_CONSTANT(INDEX);
  JS_GLUT_CONSTANT(SINGLE);
  JS_GLUT_CONSTANT(DOUBLE);
  JS_GLUT_CONSTANT(ACCUM);
  JS_GLUT_CONSTANT(ALPHA);
  JS_GLUT_CONSTANT(DEPTH);
  JS_GLUT_CONSTANT(STENCIL);
  JS_GLUT_CONSTANT(MULTISAMPLE);
  JS_GLUT_CONSTANT(STEREO);
  JS_GLUT_CONSTANT(LUMINANCE);

  /*
  * GLUT API macro definitions -- windows and menu related definitions
  */
  JS_GLUT_CONSTANT(MENU_NOT_IN_USE);
  JS_GLUT_CONSTANT(MENU_IN_USE);
  JS_GLUT_CONSTANT(NOT_VISIBLE);
  JS_GLUT_CONSTANT(VISIBLE);
  JS_GLUT_CONSTANT(HIDDEN);
  JS_GLUT_CONSTANT(FULLY_RETAINED);
  JS_GLUT_CONSTANT(PARTIALLY_RETAINED);
  JS_GLUT_CONSTANT(FULLY_COVERED);

  /*
  * GLUT API macro definitions -- fonts definitions
  *
  * Steve Baker suggested to make it binary compatible with GLUT:
  */
  //JS_GLUT_CONSTANT(STROKE_ROMAN);
  //JS_GLUT_CONSTANT(STROKE_MONO_ROMAN);
  //JS_GLUT_CONSTANT(BITMAP_9_BY_15);
  //JS_GLUT_CONSTANT(BITMAP_8_BY_13);
  //JS_GLUT_CONSTANT(BITMAP_TIMES_ROMAN_10);
  //JS_GLUT_CONSTANT(BITMAP_TIMES_ROMAN_24);
  //JS_GLUT_CONSTANT(BITMAP_HELVETICA_10);
  //JS_GLUT_CONSTANT(BITMAP_HELVETICA_12);
  //JS_GLUT_CONSTANT(BITMAP_HELVETICA_18);


  /*
  * GLUT API macro definitions -- the glutGet parameters
  */
  JS_GLUT_CONSTANT(WINDOW_X);
  JS_GLUT_CONSTANT(WINDOW_Y);
  JS_GLUT_CONSTANT(WINDOW_WIDTH);
  JS_GLUT_CONSTANT(WINDOW_HEIGHT);
  JS_GLUT_CONSTANT(WINDOW_BUFFER_SIZE);
  JS_GLUT_CONSTANT(WINDOW_STENCIL_SIZE);
  JS_GLUT_CONSTANT(WINDOW_DEPTH_SIZE);
  JS_GLUT_CONSTANT(WINDOW_RED_SIZE);
  JS_GLUT_CONSTANT(WINDOW_GREEN_SIZE);
  JS_GLUT_CONSTANT(WINDOW_BLUE_SIZE);
  JS_GLUT_CONSTANT(WINDOW_ALPHA_SIZE);
  JS_GLUT_CONSTANT(WINDOW_ACCUM_RED_SIZE);
  JS_GLUT_CONSTANT(WINDOW_ACCUM_GREEN_SIZE);
  JS_GLUT_CONSTANT(WINDOW_ACCUM_BLUE_SIZE);
  JS_GLUT_CONSTANT(WINDOW_ACCUM_ALPHA_SIZE);
  JS_GLUT_CONSTANT(WINDOW_DOUBLEBUFFER);
  JS_GLUT_CONSTANT(WINDOW_RGBA);
  JS_GLUT_CONSTANT(WINDOW_PARENT);
  JS_GLUT_CONSTANT(WINDOW_NUM_CHILDREN);
  JS_GLUT_CONSTANT(WINDOW_COLORMAP_SIZE);
  JS_GLUT_CONSTANT(WINDOW_NUM_SAMPLES);
  JS_GLUT_CONSTANT(WINDOW_STEREO);
  JS_GLUT_CONSTANT(WINDOW_CURSOR);

  JS_GLUT_CONSTANT(SCREEN_WIDTH);
  JS_GLUT_CONSTANT(SCREEN_HEIGHT);
  JS_GLUT_CONSTANT(SCREEN_WIDTH_MM);
  JS_GLUT_CONSTANT(SCREEN_HEIGHT_MM);
  JS_GLUT_CONSTANT(MENU_NUM_ITEMS);
  JS_GLUT_CONSTANT(DISPLAY_MODE_POSSIBLE);
  JS_GLUT_CONSTANT(INIT_WINDOW_X);
  JS_GLUT_CONSTANT(INIT_WINDOW_Y);
  JS_GLUT_CONSTANT(INIT_WINDOW_WIDTH);
  JS_GLUT_CONSTANT(INIT_WINDOW_HEIGHT);
  JS_GLUT_CONSTANT(INIT_DISPLAY_MODE);
  JS_GLUT_CONSTANT(ELAPSED_TIME);
  JS_GLUT_CONSTANT(WINDOW_FORMAT_ID);

  /*
  * GLUT API macro definitions -- the glutDeviceGet parameters
  */
  JS_GLUT_CONSTANT(HAS_KEYBOARD);
  JS_GLUT_CONSTANT(HAS_MOUSE);
  JS_GLUT_CONSTANT(HAS_SPACEBALL);
  JS_GLUT_CONSTANT(HAS_DIAL_AND_BUTTON_BOX);
  JS_GLUT_CONSTANT(HAS_TABLET);
  JS_GLUT_CONSTANT(NUM_MOUSE_BUTTONS);
  JS_GLUT_CONSTANT(NUM_SPACEBALL_BUTTONS);
  JS_GLUT_CONSTANT(NUM_BUTTON_BOX_BUTTONS);
  JS_GLUT_CONSTANT(NUM_DIALS);
  JS_GLUT_CONSTANT(NUM_TABLET_BUTTONS);
  JS_GLUT_CONSTANT(DEVICE_IGNORE_KEY_REPEAT);
  JS_GLUT_CONSTANT(DEVICE_KEY_REPEAT);
  JS_GLUT_CONSTANT(HAS_JOYSTICK);
  JS_GLUT_CONSTANT(OWNS_JOYSTICK);
  JS_GLUT_CONSTANT(JOYSTICK_BUTTONS);
  JS_GLUT_CONSTANT(JOYSTICK_AXES);
  JS_GLUT_CONSTANT(JOYSTICK_POLL_RATE);

  /*
  * GLUT API macro definitions -- the glutLayerGet parameters
  */
  JS_GLUT_CONSTANT(OVERLAY_POSSIBLE);
  JS_GLUT_CONSTANT(LAYER_IN_USE);
  JS_GLUT_CONSTANT(HAS_OVERLAY);
  JS_GLUT_CONSTANT(TRANSPARENT_INDEX);
  JS_GLUT_CONSTANT(NORMAL_DAMAGED);
  JS_GLUT_CONSTANT(OVERLAY_DAMAGED);

  /*
  * GLUT API macro definitions -- the glutVideoResizeGet parameters
  */
  JS_GLUT_CONSTANT(VIDEO_RESIZE_POSSIBLE);
  JS_GLUT_CONSTANT(VIDEO_RESIZE_IN_USE);
  JS_GLUT_CONSTANT(VIDEO_RESIZE_X_DELTA);
  JS_GLUT_CONSTANT(VIDEO_RESIZE_Y_DELTA);
  JS_GLUT_CONSTANT(VIDEO_RESIZE_WIDTH_DELTA);
  JS_GLUT_CONSTANT(VIDEO_RESIZE_HEIGHT_DELTA);
  JS_GLUT_CONSTANT(VIDEO_RESIZE_X);
  JS_GLUT_CONSTANT(VIDEO_RESIZE_Y);
  JS_GLUT_CONSTANT(VIDEO_RESIZE_WIDTH);
  JS_GLUT_CONSTANT(VIDEO_RESIZE_HEIGHT);

  /*
  * GLUT API macro definitions -- the glutUseLayer parameters
  */
  JS_GLUT_CONSTANT(NORMAL);
  JS_GLUT_CONSTANT(OVERLAY);

  /*
  * GLUT API macro definitions -- the glutGetModifiers parameters
  */
  JS_GLUT_CONSTANT(ACTIVE_SHIFT);
  JS_GLUT_CONSTANT(ACTIVE_CTRL);
  JS_GLUT_CONSTANT(ACTIVE_ALT);

  /*
  * GLUT API macro definitions -- the glutSetCursor parameters
  */
  JS_GLUT_CONSTANT(CURSOR_RIGHT_ARROW);
  JS_GLUT_CONSTANT(CURSOR_LEFT_ARROW);
  JS_GLUT_CONSTANT(CURSOR_INFO);
  JS_GLUT_CONSTANT(CURSOR_DESTROY);
  JS_GLUT_CONSTANT(CURSOR_HELP);
  JS_GLUT_CONSTANT(CURSOR_CYCLE);
  JS_GLUT_CONSTANT(CURSOR_SPRAY);
  JS_GLUT_CONSTANT(CURSOR_WAIT);
  JS_GLUT_CONSTANT(CURSOR_TEXT);
  JS_GLUT_CONSTANT(CURSOR_CROSSHAIR);
  JS_GLUT_CONSTANT(CURSOR_UP_DOWN);
  JS_GLUT_CONSTANT(CURSOR_LEFT_RIGHT);
  JS_GLUT_CONSTANT(CURSOR_TOP_SIDE);
  JS_GLUT_CONSTANT(CURSOR_BOTTOM_SIDE);
  JS_GLUT_CONSTANT(CURSOR_LEFT_SIDE);
  JS_GLUT_CONSTANT(CURSOR_RIGHT_SIDE);
  JS_GLUT_CONSTANT(CURSOR_TOP_LEFT_CORNER);
  JS_GLUT_CONSTANT(CURSOR_TOP_RIGHT_CORNER);
  JS_GLUT_CONSTANT(CURSOR_BOTTOM_RIGHT_CORNER);
  JS_GLUT_CONSTANT(CURSOR_BOTTOM_LEFT_CORNER);
  JS_GLUT_CONSTANT(CURSOR_INHERIT);
  JS_GLUT_CONSTANT(CURSOR_NONE);
  JS_GLUT_CONSTANT(CURSOR_FULL_CROSSHAIR);

  /*
  * GLUT API macro definitions -- RGB color component specification definitions
  */
  JS_GLUT_CONSTANT(RED);
  JS_GLUT_CONSTANT(GREEN);
  JS_GLUT_CONSTANT(BLUE);

  /*
  * GLUT API macro definitions -- additional keyboard and joystick definitions
  */
  JS_GLUT_CONSTANT(KEY_REPEAT_OFF);
  JS_GLUT_CONSTANT(KEY_REPEAT_ON);
  JS_GLUT_CONSTANT(KEY_REPEAT_DEFAULT);

  JS_GLUT_CONSTANT(JOYSTICK_BUTTON_A);
  JS_GLUT_CONSTANT(JOYSTICK_BUTTON_B);
  JS_GLUT_CONSTANT(JOYSTICK_BUTTON_C);
  JS_GLUT_CONSTANT(JOYSTICK_BUTTON_D);

  /*
  * GLUT API macro definitions -- game mode definitions
  */
  JS_GLUT_CONSTANT(GAME_MODE_ACTIVE);
  JS_GLUT_CONSTANT(GAME_MODE_POSSIBLE);
  JS_GLUT_CONSTANT(GAME_MODE_WIDTH);
  JS_GLUT_CONSTANT(GAME_MODE_HEIGHT);
  JS_GLUT_CONSTANT(GAME_MODE_PIXEL_DEPTH);
  JS_GLUT_CONSTANT(GAME_MODE_REFRESH_RATE);
  JS_GLUT_CONSTANT(GAME_MODE_DISPLAY_CHANGED);


  JS_GLUT_CONSTANT(EXEC_STATE_INIT);
  JS_GLUT_CONSTANT(EXEC_STATE_RUNNING);
  JS_GLUT_CONSTANT(EXEC_STATE_STOP);


	/*
	 * Initialization functions, see fglut_init.c
	 */
	JS_GLUT_SET_METHOD(init);
	JS_GLUT_SET_METHOD(initWindowPosition);
	JS_GLUT_SET_METHOD(initWindowSize);
	JS_GLUT_SET_METHOD(initDisplayMode);
	JS_GLUT_SET_METHOD(initDisplayString);

	/*
	 * Process loop function, see fg_main.c
	 */
	//JS_GLUT_SET_METHOD(mainLoop);
	JS_GLUT_SET_METHOD(mainLoopEvent);

	/*
	 * Window management functions, see fg_window.c
	 */
	JS_GLUT_SET_METHOD(createWindow);
	JS_GLUT_SET_METHOD(createSubWindow);
	JS_GLUT_SET_METHOD(destroyWindow);
	JS_GLUT_SET_METHOD(setWindow);
	JS_GLUT_SET_METHOD(getWindow);
	JS_GLUT_SET_METHOD(setWindowTitle);
	JS_GLUT_SET_METHOD(setIconTitle);
	JS_GLUT_SET_METHOD(reshapeWindow);
	JS_GLUT_SET_METHOD(positionWindow);
	JS_GLUT_SET_METHOD(showWindow);
	JS_GLUT_SET_METHOD(hideWindow);
	JS_GLUT_SET_METHOD(iconifyWindow);
	JS_GLUT_SET_METHOD(pushWindow);
	JS_GLUT_SET_METHOD(popWindow);
	JS_GLUT_SET_METHOD(fullScreen);

	/*
	 * Display-related functions, see fg_display.c
	 */
	JS_GLUT_SET_METHOD(postWindowRedisplay);
	JS_GLUT_SET_METHOD(postRedisplay);
	JS_GLUT_SET_METHOD(swapBuffers);

	/*
	 * Mouse cursor functions, see fg_cursor.c
	 */
	JS_GLUT_SET_METHOD(warpPointer);
	JS_GLUT_SET_METHOD(setCursor);


	/*
	 * Overlay stuff, see fg_overlay.c
	 */
	JS_GLUT_SET_METHOD(establishOverlay);
	JS_GLUT_SET_METHOD(removeOverlay);
	JS_GLUT_SET_METHOD(useLayer);
	JS_GLUT_SET_METHOD(postOverlayRedisplay);
	JS_GLUT_SET_METHOD(postWindowOverlayRedisplay);
	JS_GLUT_SET_METHOD(showOverlay);
	JS_GLUT_SET_METHOD(hideOverlay);

	/*
	 * Menu stuff, see fg_menu.c
	 */
	JS_GLUT_SET_METHOD(createMenu);
	JS_GLUT_SET_METHOD(destroyMenu);
	JS_GLUT_SET_METHOD(getMenu);
	JS_GLUT_SET_METHOD(setMenu);
	JS_GLUT_SET_METHOD(addMenuEntry);
	JS_GLUT_SET_METHOD(addSubMenu);
	JS_GLUT_SET_METHOD(changeToMenuEntry);
	JS_GLUT_SET_METHOD(changeToSubMenu);
	JS_GLUT_SET_METHOD(removeMenuItem);
	JS_GLUT_SET_METHOD(attachMenu);
	JS_GLUT_SET_METHOD(detachMenu);

	/*
	 * Global callback functions, see fg_callbacks.c
	 */
	JS_GLUT_SET_METHOD(timerFunc);
	JS_GLUT_SET_METHOD(idleFunc);

	/*
	 * Window-specific callback functions, see fg_callbacks.c
	 */
	JS_GLUT_SET_METHOD(keyboardFunc);
	JS_GLUT_SET_METHOD(specialFunc);
	JS_GLUT_SET_METHOD(reshapeFunc);
	JS_GLUT_SET_METHOD(visibilityFunc);
	JS_GLUT_SET_METHOD(displayFunc);
	JS_GLUT_SET_METHOD(mouseFunc);
	JS_GLUT_SET_METHOD(motionFunc);
	JS_GLUT_SET_METHOD(passiveMotionFunc);
	JS_GLUT_SET_METHOD(entryFunc);
	JS_GLUT_SET_METHOD(keyboardUpFunc);
	JS_GLUT_SET_METHOD(specialUpFunc);
	JS_GLUT_SET_METHOD(joystickFunc);
	JS_GLUT_SET_METHOD(menuStateFunc);
	JS_GLUT_SET_METHOD(menuStatusFunc);
	JS_GLUT_SET_METHOD(overlayDisplayFunc);
	JS_GLUT_SET_METHOD(windowStatusFunc);
	JS_GLUT_SET_METHOD(spaceballMotionFunc);
	JS_GLUT_SET_METHOD(spaceballRotateFunc);
	JS_GLUT_SET_METHOD(spaceballButtonFunc);
	JS_GLUT_SET_METHOD(buttonBoxFunc);
	JS_GLUT_SET_METHOD(dialsFunc);
	JS_GLUT_SET_METHOD(tabletMotionFunc);
	JS_GLUT_SET_METHOD(tabletButtonFunc);

	/*
	 * State setting and retrieval functions, see fg_state.c
	 */
	JS_GLUT_SET_METHOD(get);
	JS_GLUT_SET_METHOD(deviceGet);
	JS_GLUT_SET_METHOD(getModifiers);
	JS_GLUT_SET_METHOD(layerGet);

	/*
	 * Font stuff, see fg_font.c
	 */
	JS_GLUT_SET_METHOD(bitmapCharacter);
	JS_GLUT_SET_METHOD(bitmapWidth);
	JS_GLUT_SET_METHOD(strokeCharacter);
	JS_GLUT_SET_METHOD(strokeWidth);
	JS_GLUT_SET_METHOD(strokeWidthf);
	JS_GLUT_SET_METHOD(bitmapLength);
	JS_GLUT_SET_METHOD(strokeLength);
	JS_GLUT_SET_METHOD(strokeLengthf);

	/*
	 * Geometry functions, see fg_geometry.c
	 */
	JS_GLUT_SET_METHOD(wireCube);
	JS_GLUT_SET_METHOD(solidCube);
	JS_GLUT_SET_METHOD(wireSphere);
	JS_GLUT_SET_METHOD(solidSphere);
	JS_GLUT_SET_METHOD(wireCone);
	JS_GLUT_SET_METHOD(solidCone);
	JS_GLUT_SET_METHOD(wireTorus);
	JS_GLUT_SET_METHOD(solidTorus);
	JS_GLUT_SET_METHOD(wireDodecahedron);
	JS_GLUT_SET_METHOD(solidDodecahedron);
	JS_GLUT_SET_METHOD(wireOctahedron);
	JS_GLUT_SET_METHOD(solidOctahedron);
	JS_GLUT_SET_METHOD(wireTetrahedron);
	JS_GLUT_SET_METHOD(solidTetrahedron);
	JS_GLUT_SET_METHOD(wireIcosahedron);
	JS_GLUT_SET_METHOD(solidIcosahedron);

	/*
	 * Teapot rendering functions, found in fg_teapot.c
	 * NB: front facing polygons have clockwise winding, not counter clockwise
	 */
	JS_GLUT_SET_METHOD(wireTeapot);
	JS_GLUT_SET_METHOD(solidTeapot);

	/*
	 * Game mode functions, see fg_gamemode.c
	 */
	JS_GLUT_SET_METHOD(gameModeString);
	JS_GLUT_SET_METHOD(enterGameMode);
	JS_GLUT_SET_METHOD(leaveGameMode);
	JS_GLUT_SET_METHOD(gameModeGet);

	/*
	 * Video resize functions, see fg_videoresize.c
	 */
	JS_GLUT_SET_METHOD(videoResizeGet);
	JS_GLUT_SET_METHOD(setupVideoResizing);
	JS_GLUT_SET_METHOD(stopVideoResizing);
	JS_GLUT_SET_METHOD(videoResize);
	JS_GLUT_SET_METHOD(videoPan);

	/*
	 * Colormap functions, see fg_misc.c
	 */
	JS_GLUT_SET_METHOD(setColor);
	JS_GLUT_SET_METHOD(getColor);
	JS_GLUT_SET_METHOD(copyColormap);

	/*
	 * Misc keyboard and joystick functions, see fg_misc.c
	 */
	JS_GLUT_SET_METHOD(ignoreKeyRepeat);
	JS_GLUT_SET_METHOD(setKeyRepeat);
	JS_GLUT_SET_METHOD(forceJoystickFunc);

	/*
	 * Misc functions, see fg_misc.c
	 */
	JS_GLUT_SET_METHOD(extensionSupported);
	JS_GLUT_SET_METHOD(reportErrors);


	JS_GLUT_SET_METHOD(sleep);


	JS_GLUT_SET_METHOD(execState);
	JS_GLUT_SET_METHOD(mainLoopBegin);
	JS_GLUT_SET_METHOD(mainLoopStep);
	JS_GLUT_SET_METHOD(mainLoopEnd);

  return exports;
}

NODE_API_MODULE(hello, Init)

}  // namespace glut
