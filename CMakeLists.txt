cmake_minimum_required(VERSION 3.28)
project(Http C)

set(CMAKE_C_STANDARD 23)

add_executable(Http main.c
        http/response.c
        http/request.c
        http/status.c
        http/content.c
        log/ascii.c
        log/stdout.c
        include/http.h
        include/log.h)
