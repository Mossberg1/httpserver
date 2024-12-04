//
// Created by William Mossberg on 2024-12-04.
//
#ifndef LOG_H
#define LOG_H

#include "http.h"

// Define ANSI color codes
#define RESET   "\033[0m"
#define RED     "\033[31m"
#define GREEN   "\033[32m"
#define YELLOW  "\033[33m"
#define BLUE    "\033[34m"
#define MAGENTA "\033[35m"
#define CYAN    "\033[36m"
#define WHITE   "\033[37m"


void ascii_art(char *path);
void log_stdout(http_request *req, http_response *res);


#endif
