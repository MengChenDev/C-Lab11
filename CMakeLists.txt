cmake_minimum_required(VERSION 3.30)
project(<ScoreSystem> C)

set(CMAKE_C_STANDARD 23)

add_executable(ScoreSystem
  src/prac11.c
  src/menu.c
  src/menu.h
  src/core.c
  src/core.h
  src/file.c
  src/file.h
  src/common.h
)