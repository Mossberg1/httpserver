#ifndef HTTP_H
#define HTTP_H


#include <stddef.h>


#define MAXHEADERS 16


typedef struct {
        char key[32];
        char value[256];
} http_header;


typedef struct {
        char method[8];
        char path[256];
        char version[16];
        size_t n_headers;
        http_header headers[MAXHEADERS];
        size_t content_length;
        char* body;
} http_request;


#endif 
