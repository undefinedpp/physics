# Physics school project

## Dependencies

- SFML 2.6.x for rendering graphics (packaged as submodule)

## Requirements

- System that supports legacy OpenGL (graphics only)
- CMake 3.16 or greater
- Ninja/GNU Make
- A c++ compiler such as clang or g++ with c++ 17 support
- Git for cloning recursively (optional, *.zip downloads are not encouraged)
- (All of the mentioned tools must be in the PATH in order for the instructions to work properly)

## Build instructions for bash/powershell

```bash
git clone --recursive https://github.com/undefinedpp/physics.git
cd physics && mkdir build && cd build && cmake -G [name of generator] ..
```

For CMake generator examples, see [Link to the CMake manual](https://cmake.org/cmake/help/latest/manual/cmake-generators.7.html)

## Future plans

- Add support for modern OpenGL using GLFW/GLEW
