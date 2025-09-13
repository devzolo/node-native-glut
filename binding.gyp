{
    'variables': {
    'platform': '<(OS)',
    'build_arch': '<!(node -p "process.arch")',
    'build_win_platform': '<!(node -p "process.arch==\'ia32\'?\'Win32\':process.arch")',
  },
  'conditions': [
    # Replace gyp platform with node platform, blech
    ['platform == "mac"', {'variables': {'platform': 'darwin'}}],
    ['platform == "win"', {'variables': {'platform': 'win32'}}],
  ],
  "targets": [
    {
      "target_name": "native-glut",
      "sources": [

      ],
      "defines": [
        "NAPI_DISABLE_CPP_EXCEPTIONS"
      ],
      "include_dirs": [
        "<!@(node -p \"require('node-addon-api').include\")"
      ],
      "dependencies": [
        "<!(node -p \"require('node-addon-api').gyp\")"
      ],
      "cflags": ["-Wall"],
      "cflags_cc": ["-Wall"],
      "msvs_disabled_warnings": [4101, 4293, 4018],
      "conditions": [
        ["OS=='linux'", {
          "defines": ["HAVE_CONFIG_H"],
          "include_dirs": [
            "/usr/include",
            "/usr/include/GL",
            "./deps/freeglut-3.2.1/include",
            "./deps/freeglut-3.2.1/src",
            "./deps/freeglut-3.2.1"
          ],
          "libraries": [
            "-lglut",
            "-lGL",
            "-lX11",
            "-lXxf86vm",
            "-lXrandr",
            "-lXi",
            "-lm"
          ],
          "cflags": ["-Wall", "-pedantic"],
          "cflags_cc": ["-Wall", "-pedantic"],
          "sources": [
            "src/glut_ext.c",
            "src/glut.cc"
          ]
        }],
        ["OS=='win'", {
          "defines": [
            "_WIN32_WINNT=0x0601",
            "WINVER=0x0601",
            "_CRT_SECURE_NO_WARNINGS",
            "FREEGLUT_EXPORTS",
            "FREEGLUT_PRINT_ERRORS"
          ],
          "include_dirs": [
            "./deps/freeglut-3.2.1/include",
            "./deps/freeglut-3.2.1/src",
            "./deps/freeglut-3.2.1"
          ],
          "libraries": ["opengl32", "winmm", "gdi32"],
          "cflags": ["-Wall"],
          "cflags_cc": ["-Wall"],
          "sources": [
            "src/common.h",
            "src/framework.h",

            "GL/freeglut.h",
            "GL/freeglut_ucall.h",
            "GL/freeglut_ext.h",
            "GL/freeglut_std.h",
            "deps/freeglut-3.2.1/src/fg_callbacks.c",
            "deps/freeglut-3.2.1/src/fg_cursor.c",
            "deps/freeglut-3.2.1/src/fg_display.c",
            "deps/freeglut-3.2.1/src/fg_ext.c",
            "deps/freeglut-3.2.1/src/fg_font_data.c",
            "deps/freeglut-3.2.1/src/fg_gamemode.c",
            "deps/freeglut-3.2.1/src/fg_geometry.c",
            "deps/freeglut-3.2.1/src/fg_gl2.c",
            "deps/freeglut-3.2.1/src/fg_gl2.h",
            "deps/freeglut-3.2.1/src/fg_init.c",
            "deps/freeglut-3.2.1/src/fg_init.h",
            "deps/freeglut-3.2.1/src/fg_internal.h",
            "deps/freeglut-3.2.1/src/fg_callback_macros.h",
            "deps/freeglut-3.2.1/src/fg_input_devices.c",
            "deps/freeglut-3.2.1/src/fg_joystick.c",
            "deps/freeglut-3.2.1/src/fg_main.c",
            "deps/freeglut-3.2.1/src/fg_misc.c",
            "deps/freeglut-3.2.1/src/fg_overlay.c",
            "deps/freeglut-3.2.1/src/fg_spaceball.c",
            "deps/freeglut-3.2.1/src/fg_state.c",
            "deps/freeglut-3.2.1/src/fg_stroke_mono_roman.c",
            "deps/freeglut-3.2.1/src/fg_stroke_roman.c",
            "deps/freeglut-3.2.1/src/fg_structure.c",
            "deps/freeglut-3.2.1/src/fg_teapot.c",
            "deps/freeglut-3.2.1/src/fg_teapot_data.h",
            "deps/freeglut-3.2.1/src/fg_videoresize.c",
            "deps/freeglut-3.2.1/src/fg_window.c",

            "deps/freeglut-3.2.1/src/fg_font.c",
            "deps/freeglut-3.2.1/src/fg_menu.c",

            "deps/freeglut-3.2.1/src/util/xparsegeometry_repl.h",
            "deps/freeglut-3.2.1/src/util/xparsegeometry_repl.c",

            "src/glut_ext.c",
            "src/glut.cc",

            "deps/freeglut-3.2.1/src/mswin/fg_cursor_mswin.c",
            "deps/freeglut-3.2.1/src/mswin/fg_display_mswin.c",
            "deps/freeglut-3.2.1/src/mswin/fg_ext_mswin.c",
            "deps/freeglut-3.2.1/src/mswin/fg_gamemode_mswin.c",
            "deps/freeglut-3.2.1/src/mswin/fg_init_mswin.c",
            "deps/freeglut-3.2.1/src/mswin/fg_internal_mswin.h",
            "deps/freeglut-3.2.1/src/mswin/fg_input_devices_mswin.c",
            "deps/freeglut-3.2.1/src/mswin/fg_joystick_mswin.c",
            "deps/freeglut-3.2.1/src/mswin/fg_main_mswin.c",
            "deps/freeglut-3.2.1/src/mswin/fg_menu_mswin.c",
            "deps/freeglut-3.2.1/src/mswin/fg_spaceball_mswin.c",
            "deps/freeglut-3.2.1/src/mswin/fg_state_mswin.c",
            "deps/freeglut-3.2.1/src/mswin/fg_structure_mswin.c",
            "deps/freeglut-3.2.1/src/mswin/fg_window_mswin.c",
          ]
        }],
        ["OS=='mac'", {
          "defines": ["HAVE_CONFIG_H"],
          "libraries": [
            "-framework OpenGL",
            "-framework GLUT",
            "-framework Cocoa",
            "-framework IOKit",
            "-framework CoreVideo"
          ],
          "cflags": ["-Wall", "-pedantic"],
          "cflags_cc": ["-Wall", "-pedantic"],
          "sources": [
            "src/glut_ext.c",
            "src/glut.cc"
          ]
        }]
      ]
    },
    {
      "target_name": "copy_dll",
      "type": "none",
      "dependencies": ["native-glut"],
      "copies": [
        {
          "destination": "<(module_root_dir)/dist",
          "files": ["<(module_root_dir)/src/types/index.d.ts"]
        },
        {
          'destination': '<(module_root_dir)/bin/<(platform)/<(target_arch)',
          'files': [
            '<(module_root_dir)/build/Release/native-glut.node',
          ]
        }
      ]
    }
  ]
}
