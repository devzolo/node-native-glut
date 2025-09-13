# @devzolo/node-native-glut

Native OpenGL Utility Toolkit (GLUT) bindings for Node.js (with TypeScript typings), powered by FreeGLUT.

[![npm](https://img.shields.io/npm/v/%40devzolo%2Fnode-native-glut)](https://www.npmjs.com/package/@devzolo/node-native-glut)
[![node](https://img.shields.io/node/v/%40devzolo%2Fnode-native-glut)](https://www.npmjs.com/package/@devzolo/node-native-glut)
[![license](https://img.shields.io/github/license/devzolo/node-native-glut)](./LICENSE)
[![os](https://img.shields.io/badge/OS-Windows%2010%2B%20%7C%20Linux%20%7C%20macOS-blue)](https://github.com/devzolo/node-native-glut)

This package exposes GLUT (OpenGL Utility Toolkit) functions directly to Node.js via N-API, with full IntelliSense using `src/types/index.d.ts`. It provides window management, input handling, and utility functions for creating OpenGL applications with cross-platform support.

Note: this package creates and manages OpenGL contexts and windows. It can be used standalone or in combination with other OpenGL libraries like `@devzolo/node-native-gl` and `@devzolo/node-native-glu`.

## Installation

Prerequisites:

- Node.js 16+ (LTS recommended)
- pnpm, npm, or yarn

If you use GitHub Packages, add to your `.npmrc`:

```env
@devzolo:registry=https://npm.pkg.github.com
//npm.pkg.github.com/:_authToken=${GITHUB_TOKEN}
```

Install:

```bash
# pnpm
pnpm add @devzolo/node-native-glut

# npm
npm install @devzolo/node-native-glut

# yarn
yarn add @devzolo/node-native-glut
```

The package attempts to download prebuilt binaries. If a binary is not available for your platform, it will build from source (requires a C++ toolchain).

## Quick start

TypeScript / ESM:

```ts
import GLUT from '@devzolo/node-native-glut';

// Initialize GLUT
GLUT.init();

// Create a window
GLUT.createWindow('My GLUT Window');

// Set up display callback
GLUT.displayFunc(() => {
  // Your OpenGL rendering code here
  GLUT.swapBuffers();
});

// Set up reshape callback
GLUT.reshapeFunc((width, height) => {
  // Handle window resize
  console.log(`Window resized to ${width}x${height}`);
});

// Set up keyboard callback
GLUT.keyboardFunc((key, x, y) => {
  if (key === 27) { // ESC key
    process.exit(0);
  }
});

// Start the main loop
GLUT.mainLoop();
```

JavaScript (CommonJS):

```js
const GLUT = require('@devzolo/node-native-glut').default;

GLUT.init();
GLUT.createWindow('My GLUT Window');

GLUT.displayFunc(() => {
  // Your OpenGL rendering code here
  GLUT.swapBuffers();
});

GLUT.mainLoop();
```

## API

- Constants and functions mirror the GLUT API, exposed under the `GLUT` namespace with TypeScript types.
- Type reference: see `src/types/index.d.ts` in this repository.
- Examples of available symbols:
  - Window functions: `GLUT.createWindow()`, `GLUT.setWindowTitle()`, `GLUT.setWindowSize()`, `GLUT.setWindowPosition()`.
  - Callback functions: `GLUT.displayFunc()`, `GLUT.reshapeFunc()`, `GLUT.keyboardFunc()`, `GLUT.mouseFunc()`.
  - Utility functions: `GLUT.mainLoop()`, `GLUT.swapBuffers()`, `GLUT.postRedisplay()`.

Typing: the default export is a `GLUT` object containing all typed members (TypeScript).

## Platforms and binaries

- **Supported platforms**: Windows (x64/x86), Linux (x64), macOS (x64/ARM64)
- **GLUT implementation**: FreeGLUT 3.2.1 (bundled)
- Prebuilt binaries are downloaded automatically when available.
- Fallback: local build with `node-pre-gyp`/`node-gyp` (requires a C++ toolchain). See next section.

### Platform-specific requirements

#### Windows
- **OpenGL libraries**: `opengl32.lib`, `freeglut.lib` (bundled)
- **Build tools**: Visual Studio Build Tools 2019/2022 with C++ (MSVC)
- **Python**: 3.x in PATH

#### Linux
- **OpenGL libraries**: `libGL.so`, `libGLU.so`, `libglut.so` (system packages)
- **Installation** (Ubuntu/Debian):
  ```bash
  sudo apt update
  sudo apt install -y libgl1-mesa-dev libglu1-mesa-dev freeglut3-dev
  ```
- **Installation** (CentOS/RHEL/Fedora):
  ```bash
  sudo yum install -y mesa-libGL-devel mesa-libGLU-devel freeglut-devel
  # or for newer versions:
  sudo dnf install -y mesa-libGL-devel mesa-libGLU-devel freeglut-devel
  ```
- **Build tools**: `gcc`, `g++`, `make`, `python3`

#### macOS
- **OpenGL libraries**: `OpenGL.framework`, `GLUT.framework` (system/bundled)
- **Build tools**: Xcode Command Line Tools
- **Installation**:
  ```bash
  xcode-select --install
  ```

## Build from source

### Prerequisites by platform

#### Windows
- Visual Studio Build Tools 2019/2022 with C++ (MSVC)
- Python 3.x in PATH
- Compatible `node-gyp` (pulled by the ecosystem as needed)

#### Linux
- GCC/G++ compiler
- Make
- Python 3.x
- OpenGL development libraries (see installation commands above)

#### macOS
- Xcode Command Line Tools
- Python 3.x

### Build steps

```bash
# Install dependencies
pnpm install
# or
npm install

# Build the native module
pnpm build
# or
npm run build
```

Other useful scripts:

```bash
pnpm test        # run tests
pnpm dist        # compile TypeScript to ./dist
pnpm package     # build addon + tests + package
```

## Troubleshooting

### Common issues

- **Missing context**: GLUT call failures usually indicate initialization issues. Ensure `GLUT.init()` is called before other functions.
- **Missing build tools**: if binary download fails, a local build requires platform-specific tools. Install the required tools and retry.
- **Unsupported Node**: for N-API errors, upgrade to Node 16+ or a recent LTS.

### Platform-specific issues

#### Windows
- **Missing build tools**: Install Visual Studio Build Tools 2019/2022 with C++ (MSVC)
- **Python 3.12: 'distutils' missing**: If you hit `ModuleNotFoundError: No module named 'distutils'` with Python 3.12, run:
  ```powershell
  py -3 -m ensurepip --upgrade
  py -3 -m pip install --upgrade pip
  py -3 -m pip install "setuptools<70" packaging wheel
  pnpm build
  ```

#### Linux
- **Missing OpenGL libraries**: Install the required development packages:
  ```bash
  # Ubuntu/Debian
  sudo apt update
  sudo apt install -y libgl1-mesa-dev libglu1-mesa-dev freeglut3-dev

  # CentOS/RHEL/Fedora
  sudo yum install -y mesa-libGL-devel mesa-libGLU-devel freeglut-devel
  # or for newer versions:
  sudo dnf install -y mesa-libGL-devel mesa-libGLU-devel freeglut-devel
  ```
- **Missing build tools**: Install GCC, Make, and Python:
  ```bash
  # Ubuntu/Debian
  sudo apt install -y build-essential python3-dev

  # CentOS/RHEL/Fedora
  sudo yum groupinstall -y "Development Tools"
  sudo yum install -y python3-devel
  ```

#### macOS
- **Missing Xcode tools**: Install Xcode Command Line Tools:
  ```bash
  xcode-select --install
  ```
- **Python issues**: Ensure Python 3.x is available and in PATH

## Technical details

### Cross-platform compatibility

This package is designed to work across Windows, Linux, and macOS with the following considerations:

#### Windows
- Uses `opengl32.lib` and bundled `freeglut.lib` (static linking)
- Requires Windows 10+ for optimal OpenGL support
- Supports both x64 and x86 architectures
- Uses Windows-specific headers conditionally (`windows.h`, `tchar.h`)

#### Linux
- Uses system OpenGL libraries and bundled FreeGLUT
- Compatible with Mesa drivers (software and hardware acceleration)
- Supports major distributions (Ubuntu, Debian, CentOS, RHEL, Fedora)
- Uses Linux-specific headers (`unistd.h`, `dlfcn.h`)

#### macOS
- Uses `OpenGL.framework` and system GLUT
- Compatible with both Intel and Apple Silicon (ARM64)
- Requires macOS 10.14+ for optimal OpenGL support
- Uses macOS-specific OpenGL headers

### Build system

The package uses `node-gyp` with platform-specific configurations:

- **Windows**: MSVC compiler with Windows SDK
- **Linux**: GCC/G++ with system OpenGL libraries
- **macOS**: Clang with Xcode Command Line Tools

### FreeGLUT configuration

- **Cross-platform**: FreeGLUT 3.2.1 is bundled for consistent behavior
- **Static linking**: Used on Windows for easier distribution
- **Dynamic linking**: Used on Linux and macOS for better compatibility

## Contributing

Contributions are welcome! Please open issues and pull requests. Keep the project style and ensure tests pass.

## License

MIT © devzolo. See `LICENSE`.

## Acknowledgements

- [FreeGLUT 3.2.1](https://github.com/dcnieho/FreeGLUT) for providing a modern, cross-platform GLUT implementation.
