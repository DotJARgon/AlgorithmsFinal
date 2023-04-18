cmake_minimum_required(VERSION 3.21)
project(FinalProject)

set(CMAKE_CXX_STANDARD 14)

set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -std=c++11 -lmingw32")
set(CMAKE_EXE_LINKER_FLAGS "-static-libgcc -static-libstdc++")

include_directories("SDL2/SDL2-2.0.16/x86_64-w64-mingw32/include/SDL2")
include_directories("SDL2_mixer-2.0.4/x86_64-w64-mingw32/include/SDL2")


link_directories("SDL2/SDL2-2.0.16/x86_64-w64-mingw32/lib")
link_directories("SDL2_mixer-2.0.4/x86_64-w64-mingw32/lib")

add_executable(FinalProject main.cpp SDL_Plotter.h SLD_Plotter.cpp TextureLoader.h TextureBuffer.h WriteableBuffer.h Texture.cpp Texture.h PlotterTexture.cpp PlotterTexture.h InputHandler.cpp InputHandler.h TextAtlas.cpp TextAtlas.h GridManager.cpp GridManager.h MaskedTexture.cpp MaskedTexture.h)

target_link_libraries(FinalProject SDL2main SDL2 SDL2_mixer)
