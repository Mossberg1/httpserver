#ifndef HTTP_H
#define HTTP_H


#include <stddef.h>


typedef struct {
        char key[32];
        char value[256];
} http_header;


typedef struct {
        char method[8];
        char path[256];
        char version[16];
        http_header headers[16];
        size_t content_length;
        char* body;
} http_request;


#endif 
