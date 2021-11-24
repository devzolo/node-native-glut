declare module '@devzolo/node-native-glut' {
  export namespace GLUT {
    /*
     * The freeglut and GLUT API versions
     */
    const API_VERSION = 4;
    const XLIB_IMPLEMENTATION = 13;

    /*
     * GLUT API macro definitions -- the special key codes:
     */
    const KEY_F1 = 0x0001;
    const KEY_F2 = 0x0002;
    const KEY_F3 = 0x0003;
    const KEY_F4 = 0x0004;
    const KEY_F5 = 0x0005;
    const KEY_F6 = 0x0006;
    const KEY_F7 = 0x0007;
    const KEY_F8 = 0x0008;
    const KEY_F9 = 0x0009;
    const KEY_F10 = 0x000a;
    const KEY_F11 = 0x000b;
    const KEY_F12 = 0x000c;
    const KEY_LEFT = 0x0064;
    const KEY_UP = 0x0065;
    const KEY_RIGHT = 0x0066;
    const KEY_DOWN = 0x0067;
    const KEY_PAGE_UP = 0x0068;
    const KEY_PAGE_DOWN = 0x0069;
    const KEY_HOME = 0x006a;
    const KEY_END = 0x006b;
    const KEY_INSERT = 0x006c;

    /*
     * GLUT API macro definitions -- mouse state definitions
     */
    const LEFT_BUTTON = 0x0000;
    const MIDDLE_BUTTON = 0x0001;
    const RIGHT_BUTTON = 0x0002;
    const DOWN = 0x0000;
    const UP = 0x0001;
    const LEFT = 0x0000;
    const ENTERED = 0x0001;

    /*
     * GLUT API macro definitions -- the display mode definitions
     */
    const RGB = 0x0000;
    const RGBA = 0x0000;
    const INDEX = 0x0001;
    const SINGLE = 0x0000;
    const DOUBLE = 0x0002;
    const ACCUM = 0x0004;
    const ALPHA = 0x0008;
    const DEPTH = 0x0010;
    const STENCIL = 0x0020;
    const MULTISAMPLE = 0x0080;
    const STEREO = 0x0100;
    const LUMINANCE = 0x0200;

    /*
     * GLUT API macro definitions -- windows and menu related definitions
     */
    const MENU_NOT_IN_USE = 0x0000;
    const MENU_IN_USE = 0x0001;
    const NOT_VISIBLE = 0x0000;
    const VISIBLE = 0x0001;
    const HIDDEN = 0x0000;
    const FULLY_RETAINED = 0x0001;
    const PARTIALLY_RETAINED = 0x0002;
    const FULLY_COVERED = 0x0003;

    /*
     * GLUT API macro definitions -- fonts definitions
     */

    const STROKE_ROMAN = 0x0000;
    const STROKE_MONO_ROMAN = 0x0001;
    const BITMAP_9_BY_15 = 0x0002;
    const BITMAP_8_BY_13 = 0x0003;
    const BITMAP_TIMES_ROMAN_10 = 0x0004;
    const BITMAP_TIMES_ROMAN_24 = 0x0005;
    const BITMAP_HELVETICA_10 = 0x0006;
    const BITMAP_HELVETICA_12 = 0x0007;
    const BITMAP_HELVETICA_18 = 0x0008;
    /*
     * GLUT API macro definitions -- the glutGet parameters
     */
    const WINDOW_X = 0x0064;
    const WINDOW_Y = 0x0065;
    const WINDOW_WIDTH = 0x0066;
    const WINDOW_HEIGHT = 0x0067;
    const WINDOW_BUFFER_SIZE = 0x0068;
    const WINDOW_STENCIL_SIZE = 0x0069;
    const WINDOW_DEPTH_SIZE = 0x006a;
    const WINDOW_RED_SIZE = 0x006b;
    const WINDOW_GREEN_SIZE = 0x006c;
    const WINDOW_BLUE_SIZE = 0x006d;
    const WINDOW_ALPHA_SIZE = 0x006e;
    const WINDOW_ACCUM_RED_SIZE = 0x006f;
    const WINDOW_ACCUM_GREEN_SIZE = 0x0070;
    const WINDOW_ACCUM_BLUE_SIZE = 0x0071;
    const WINDOW_ACCUM_ALPHA_SIZE = 0x0072;
    const WINDOW_DOUBLEBUFFER = 0x0073;
    const WINDOW_RGBA = 0x0074;
    const WINDOW_PARENT = 0x0075;
    const WINDOW_NUM_CHILDREN = 0x0076;
    const WINDOW_COLORMAP_SIZE = 0x0077;
    const WINDOW_NUM_SAMPLES = 0x0078;
    const WINDOW_STEREO = 0x0079;
    const WINDOW_CURSOR = 0x007a;

    const SCREEN_WIDTH = 0x00c8;
    const SCREEN_HEIGHT = 0x00c9;
    const SCREEN_WIDTH_MM = 0x00ca;
    const SCREEN_HEIGHT_MM = 0x00cb;
    const MENU_NUM_ITEMS = 0x012c;
    const DISPLAY_MODE_POSSIBLE = 0x0190;
    const INIT_WINDOW_X = 0x01f4;
    const INIT_WINDOW_Y = 0x01f5;
    const INIT_WINDOW_WIDTH = 0x01f6;
    const INIT_WINDOW_HEIGHT = 0x01f7;
    const INIT_DISPLAY_MODE = 0x01f8;
    const ELAPSED_TIME = 0x02bc;
    const WINDOW_FORMAT_ID = 0x007b;

    /*
     * GLUT API macro definitions -- the glutDeviceGet parameters
     */
    const HAS_KEYBOARD = 0x0258;
    const HAS_MOUSE = 0x0259;
    const HAS_SPACEBALL = 0x025a;
    const HAS_DIAL_AND_BUTTON_BOX = 0x025b;
    const HAS_TABLET = 0x025c;
    const NUM_MOUSE_BUTTONS = 0x025d;
    const NUM_SPACEBALL_BUTTONS = 0x025e;
    const NUM_BUTTON_BOX_BUTTONS = 0x025f;
    const NUM_DIALS = 0x0260;
    const NUM_TABLET_BUTTONS = 0x0261;
    const DEVICE_IGNORE_KEY_REPEAT = 0x0262;
    const DEVICE_KEY_REPEAT = 0x0263;
    const HAS_JOYSTICK = 0x0264;
    const OWNS_JOYSTICK = 0x0265;
    const JOYSTICK_BUTTONS = 0x0266;
    const JOYSTICK_AXES = 0x0267;
    const JOYSTICK_POLL_RATE = 0x0268;

    /*
     * GLUT API macro definitions -- the glutLayerGet parameters
     */
    const OVERLAY_POSSIBLE = 0x0320;
    const LAYER_IN_USE = 0x0321;
    const HAS_OVERLAY = 0x0322;
    const TRANSPARENT_INDEX = 0x0323;
    const NORMAL_DAMAGED = 0x0324;
    const OVERLAY_DAMAGED = 0x0325;

    /*
     * GLUT API macro definitions -- the glutVideoResizeGet parameters
     */
    const VIDEO_RESIZE_POSSIBLE = 0x0384;
    const VIDEO_RESIZE_IN_USE = 0x0385;
    const VIDEO_RESIZE_X_DELTA = 0x0386;
    const VIDEO_RESIZE_Y_DELTA = 0x0387;
    const VIDEO_RESIZE_WIDTH_DELTA = 0x0388;
    const VIDEO_RESIZE_HEIGHT_DELTA = 0x0389;
    const VIDEO_RESIZE_X = 0x038a;
    const VIDEO_RESIZE_Y = 0x038b;
    const VIDEO_RESIZE_WIDTH = 0x038c;
    const VIDEO_RESIZE_HEIGHT = 0x038d;

    /*
     * GLUT API macro definitions -- the glutUseLayer parameters
     */
    const NORMAL = 0x0000;
    const OVERLAY = 0x0001;

    /*
     * GLUT API macro definitions -- the glutGetModifiers parameters
     */
    const ACTIVE_SHIFT = 0x0001;
    const ACTIVE_CTRL = 0x0002;
    const ACTIVE_ALT = 0x0004;

    /*
     * GLUT API macro definitions -- the glutSetCursor parameters
     */
    const CURSOR_RIGHT_ARROW = 0x0000;
    const CURSOR_LEFT_ARROW = 0x0001;
    const CURSOR_INFO = 0x0002;
    const CURSOR_DESTROY = 0x0003;
    const CURSOR_HELP = 0x0004;
    const CURSOR_CYCLE = 0x0005;
    const CURSOR_SPRAY = 0x0006;
    const CURSOR_WAIT = 0x0007;
    const CURSOR_TEXT = 0x0008;
    const CURSOR_CROSSHAIR = 0x0009;
    const CURSOR_UP_DOWN = 0x000a;
    const CURSOR_LEFT_RIGHT = 0x000b;
    const CURSOR_TOP_SIDE = 0x000c;
    const CURSOR_BOTTOM_SIDE = 0x000d;
    const CURSOR_LEFT_SIDE = 0x000e;
    const CURSOR_RIGHT_SIDE = 0x000f;
    const CURSOR_TOP_LEFT_CORNER = 0x0010;
    const CURSOR_TOP_RIGHT_CORNER = 0x0011;
    const CURSOR_BOTTOM_RIGHT_CORNER = 0x0012;
    const CURSOR_BOTTOM_LEFT_CORNER = 0x0013;
    const CURSOR_INHERIT = 0x0064;
    const CURSOR_NONE = 0x0065;
    const CURSOR_FULL_CROSSHAIR = 0x0066;

    /*
     * GLUT API macro definitions -- RGB color component specification definitions
     */
    const RED = 0x0000;
    const GREEN = 0x0001;
    const BLUE = 0x0002;

    /*
     * GLUT API macro definitions -- additional keyboard and joystick definitions
     */
    const KEY_REPEAT_OFF = 0x0000;
    const KEY_REPEAT_ON = 0x0001;
    const KEY_REPEAT_DEFAULT = 0x0002;

    const JOYSTICK_BUTTON_A = 0x0001;
    const JOYSTICK_BUTTON_B = 0x0002;
    const JOYSTICK_BUTTON_C = 0x0004;
    const JOYSTICK_BUTTON_D = 0x0008;

    /*
     * GLUT API macro definitions -- game mode definitions
     */
    const GAME_MODE_ACTIVE = 0x0000;
    const GAME_MODE_POSSIBLE = 0x0001;
    const GAME_MODE_WIDTH = 0x0002;
    const GAME_MODE_HEIGHT = 0x0003;
    const GAME_MODE_PIXEL_DEPTH = 0x0004;
    const GAME_MODE_REFRESH_RATE = 0x0005;
    const GAME_MODE_DISPLAY_CHANGED = 0x0006;


    function getWindowHandle(): number;

    /*
     * Initialization functions
     */
    function init(pargc?: number, argv?: string[]): void;
    function initWindowPosition(x: number, y: number): void;
    function initWindowSize(width: number, height: number): void;
    function initDisplayMode(displayMode: number): void;
    function initDisplayString(displayMode: string): void;

    /*
     * Process loop function
     */
    function mainLoop(): void;

    /*
     * Window management functions
     */
    function createWindow(title: string): number;
    function createSubWindow(window: number, x: number, y: number, width: number, height: number): number;
    function destroyWindow(window: number): void;
    function setWindow(window: number): void;
    function getWindow(): number;
    function setWindowTitle(title: string): void;
    function setIconTitle(title: string): void;
    function reshapeWindow(width: number, height: number): void;
    function positionWindow(x: number, y: number): void;
    function showWindow(): void;
    function hideWindow(): void;
    function iconifyWindow(): void;
    function pushWindow(): void;
    function popWindow(): void;
    function fullScreen(): void;

    /*
     * Display-related functions
     */
    function postWindowRedisplay(window: number): void;
    function postRedisplay(): void;
    function swapBuffers(): void;

    /*
     * Mouse cursor functions
     */
    function warpPointer(x: number, y: number): void;
    function setCursor(cursor: number): void;

    /*
     * Overlay stuff, see fg_overlay.c
     */
    function establishOverlay(): void;
    function removeOverlay(): void;
    function useLayer(layer: GLenum): void;
    function postOverlayRedisplay(): void;
    function postWindowOverlayRedisplay(window: number): void;
    function showOverlay(): void;
    function hideOverlay(): void;

    /*
     * Menu stuff
     */
    function createMenu(callback: (menu: number) => void): number;
    function destroyMenu(menu: number): void;
    function getMenu(): number;
    function setMenu(menu: number): void;
    function addMenuEntry(label: string, value: number): void;
    function addSubMenu(label: string, subMenu: number): void;
    function changeToMenuEntry(item: number, label: string, value: number): void;
    function changeToSubMenu(item: number, label: string, value: number): void;
    function removeMenuItem(item: number): void;
    function attachMenu(button: number): void;
    function detachMenu(button: number): void;

    /*
     * Global callback functions
     */
    function timerFunc(time: number, cb: (value: number) => void, value: number): void;
    function idleFunc(cb: () => void): void;

    /*
     * Window-specific callback functions
     */
    function keyboardFunc(cb: (key: string, x: number, y: number) => void): void;
    function specialFunc(cb: (key: number, x: number, y: number) => void): void;
    function reshapeFunc(cb: (width: number, height: number) => void): void;
    function visibilityFunc(cb: (state: number) => void): void;
    function displayFunc(cb: () => void): void;
    function mouseFunc(cb: (button: number, state: number, x: number, y: number) => void): void;
    function motionFunc(cb: (x: number, y: number) => void): void;
    function passiveMotionFunc(cb: (x: number, y: number) => void): void;
    function entryFunc(cb: (state: number) => void): void;

    function keyboardUpFunc(cb: (key: string, x: number, y: number) => void): void;
    function specialUpFunc(cb: (key: number, x: number, y: number) => void): void;
    function joystickFunc(cb: (buttonMask: number, x: number, y: number, z: number) => void, pollInterval: number): void;
    function menuStateFunc(cb: (status: number) => void): void;
    function menuStatusFunc(cb: (status: number, x: number, y: number) => void): void;
    function overlayDisplayFunc(cb: () => void): void;
    function windowStatusFunc(cb: (state: number) => void): void;

    function spaceballMotionFunc(cb: (x: number, y: number, z: number) => void): void;
    function spaceballRotateFunc(cb: (x: number, y: number, z: number) => void): void;
    function spaceballButtonFunc(cb: (button: number, state: number) => void): void;
    function buttonBoxFunc(cb: (button: number, state: number) => void): void;
    function dialsFunc(cb: (dial: number, value: number) => void): void;
    function tabletMotionFunc(cb: (x: number, y: number) => void): void;
    function tabletButtonFunc(cb: (button: number, state: number, x: number, y: number) => void): void;

    /*
     * State setting and retrieval functions
     */
    function get(query: GLenum): number;
    function deviceGet(query: GLenum): number;
    function getModifiers(): number;
    function layerGet(query: GLenum): number;

    /*
     * Font stuff
     */
    function bitmapCharacter(font: number, character: number): void;
    function bitmapWidth(font: number, character: number): number;
    function strokeCharacter(font: number, character: number): void;
    function strokeWidth(font: number, character: number): number;
    function strokeWidthf(font: number, character: number): GLfloat;
    function bitmapLength(font: number, str: string): number;
    function strokeLength(font: number, str: string): number;
    function strokeLengthf(font: number, str: string): GLfloat;

    /*
     * Geometry functions
     */

    function wireCube(size: number): void;
    function solidCube(size: number): void;
    function wireSphere(radius: number, slices: GLint, stacks: GLint): void;
    function solidSphere(radius: number, slices: GLint, stacks: GLint): void;
    function wireCone(base: number, height: number, slices: GLint, stacks: GLint): void;
    function solidCone(base: number, height: number, slices: GLint, stacks: GLint): void;
    function wireTorus(innerRadius: number, outerRadius: number, sides: GLint, rings: GLint): void;
    function solidTorus(innerRadius: number, outerRadius: number, sides: GLint, rings: GLint): void;
    function wireDodecahedron(): void;
    function solidDodecahedron(): void;
    function wireOctahedron(): void;
    function solidOctahedron(): void;
    function wireTetrahedron(): void;
    function solidTetrahedron(): void;
    function wireIcosahedron(): void;
    function solidIcosahedron(): void;

    /*
     * Teapot rendering functions
     * NB: front facing polygons have clockwise winding, not counter clockwise
     */
    function wireTeapot(size: number): void;
    function solidTeapot(size: number): void;

    /*
     * Game mode functions
     */
    function gameModeString(str: string): void;
    function enterGameMode(): number;
    function leaveGameMode(): void;
    function gameModeGet(query: GLenum): number;

    /*
     * Video resize functions
     */
    function videoResizeGet(query: GLenum): number;
    function setupVideoResizing(): void;
    function stopVideoResizing(): void;
    function videoResize(x: number, y: number, width: number, height: number): void;
    function videoPan(x: number, y: number, width: number, height: number): void;

    /*
     * Colormap functions
     */
    function setColor(color: number, red: GLfloat, green: GLfloat, blue: GLfloat): void;
    function getColor(color: number, component: number): GLfloat;
    function copyColormap(window: number): void;

    /*
     * Misc keyboard and joystick functions
     */
    function ignoreKeyRepeat(ignore: number): void;
    function setKeyRepeat(repeatMode: number): void;
    function forceJoystickFunc(): void;

    /*
     * Misc functions
     */
    function extensionSupported(extension: string): number;
    function reportErrors(): void;
  }
  export default GLUT;
}
