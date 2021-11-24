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
  'targets': [
    {
      'target_name': 'native-glut',
      "cflags!": [ "-fno-exceptions" ],
      "cflags_cc!": [ "-fno-exceptions" ],
      'sources': [
		    "src/common.h",
        "src/framework.h",

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
      ],
      "conditions":[
        ["OS=='win'", {
      	  "sources": [
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
      	["OS=='linux'", {
      	  "sources": [
            "deps/freeglut-3.2.1/src/x11/fg_cursor_x11.c",
            "deps/freeglut-3.2.1/src/x11/fg_display_x11_glx.c",
            "deps/freeglut-3.2.1/src/x11/fg_ext_x11.c",
            "deps/freeglut-3.2.1/src/x11/fg_gamemode_x11.c",
            "deps/freeglut-3.2.1/src/x11/fg_glutfont_definitions_x11.c",
            "deps/freeglut-3.2.1/src/x11/fg_init_x11.c",
            "deps/freeglut-3.2.1/src/x11/fg_input_devices_x11.c",
            "deps/freeglut-3.2.1/src/x11/fg_internal_x11.h",
            "deps/freeglut-3.2.1/src/x11/fg_joystick_x11.c",
            "deps/freeglut-3.2.1/src/x11/fg_main_x11.c",
            "deps/freeglut-3.2.1/src/x11/fg_menu_x11.c",
            "deps/freeglut-3.2.1/src/x11/fg_spaceball_x11.c",
            "deps/freeglut-3.2.1/src/x11/fg_state_x11.c",
            "deps/freeglut-3.2.1/src/x11/fg_state_x11_glx.c",
            "deps/freeglut-3.2.1/src/x11/fg_structure_x11.c",
            "deps/freeglut-3.2.1/src/x11/fg_window_x11.c",
            "deps/freeglut-3.2.1/src/x11/fg_window_x11_glx.c",
            "deps/freeglut-3.2.1/src/x11/fg_xinput_x11.c",
           ]
        }],
      	["OS=='mac'", {
      	  "sources": []
      	}]
      ],
      'defines' : ['NAPI_DISABLE_CPP_EXCEPTIONS', 'FREEGLUT_EXPORTS', 'FREEGLUT_PRINT_ERRORS', '_WIN32_WINNT=0x0501','INT_MAX=0x7fffffff'],
      'libraries': ['libX11'],
      "include_dirs": [
        "./deps/freeglut-3.2.1/include",
        "./deps/freeglut-3.2.1/src",
        "<!@(node -p \"require('node-addon-api').include\")"
      ],
      'library_dirs' : [],
      'msvs_disabled_warnings': [4101, 4293, 4018]
    },
    {
      "target_name": "copy_dll",
      "type":"none",
      "dependencies" : [ "native-glut" ],
      "conditions": [
        ['OS=="win"', {
          "copies":
            [
              {
                'destination': '<(module_root_dir)/bin/<(platform)/<(target_arch)',
                'files': [
                  '<(module_root_dir)/build/Release/native-glut.node',
                ]
              }
            ]
          }
        ]
      ],
      "copies":
      [
        {
          'destination': '<(module_root_dir)/dist',
          'files': [
            '<(module_root_dir)/src/types/index.d.ts',
          ]
        }
      ]
    }
  ]
}
