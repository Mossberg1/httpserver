#ifndef PARSER_H
#define PARSER_H


#include "http.h"


int parse(char buffer[], size_t size, http_request* req);


#endif
