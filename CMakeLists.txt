cmake_minimum_required(VERSION 3.25)
project(Zombie VERSION 0.1.0 LANGUAGES C CXX)

add_executable(Zombie main.cpp Game.cpp Game.h window.h window.cpp Player.hpp Player.cpp Bullet.hpp Bullet.cpp)

target_include_directories(Zombie PRIVATE C:/SDL2/include)
target_link_directories(Zombie PRIVATE C:/SDL2/lib)
target_link_libraries(Zombie PRIVATE -static-libgcc -static-libstdc++ -lmingw32 -lSDL2main -lSDL2 -lSDL2_image)