cmake_minimum_required(VERSION 4.4)
project(projeto_dupla C)

set(CMAKE_C_STANDARD 11)

add_executable(projeto_dupla main.c
        jogos.c
        jogos.h)
