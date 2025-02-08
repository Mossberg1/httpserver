#include <string.h>

#include "../include/http.h"

/*
 * Function to parse http requests.
 */
int parse(char buffer[], size_t size, http_request* req) 
{
        char* delims = " :\n";
        
        // Parse the firstline
        char* method  = strtok(buffer, delims);
        char* path    = strtok(NULL, delims);
        char* version = strtok(NULL, delims);
        
        if (method == NULL || path == NULL || version == NULL) {
                return -1;
        }

        strncpy(req->method, method, sizeof(req->method) - 1);
        req->method[sizeof(req->method) - 1] = '\0';
        
        strncpy(req->path, path, sizeof(req->path) - 1);
        req->path[sizeof(req->path) - 1] = '\0';

        strncpy(req->version, version, sizeof(req->version) - 1);
        req->version[sizeof(req->version) - 1] = '\0';
 
        // Parse the headers

        // Parse body
        return 0;
}


//Example request:
//Request: GET / HTTP/1.1
//Host: 127.0.0.1:8080
//User-Agent: Mozilla/5.0 (X11; Linux x86_64; rv:135.0) Gecko/20100101 Firefox/135.0
//Accept: text/html,application/xhtml+xml,application/xml;q=0.9,*/*;q=0.8
//Accept-Language: en-US,en;q=0.5
//Accept-Encoding: gzip, deflate, br, zstd
//Connection: keep-alive
//Upgrade-Insecure-Requests: 1
//Sec-Fetch-Dest: document
//Sec-Fetch-Mode: navigate
//Sec-Fetch-Site: none
//Sec-Fetch-User: ?1
//Priority: u=0, i

