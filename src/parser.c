#include <stdbool.h>
#include <string.h>

#include "../include/http.h"

/*
 * Function to parse http requests.
 */
int parse_request(char buffer[], size_t size, http_request* req) 
{
        char* bufsave;
        char* linesave;
        char* line = strtok_r(buffer, "\n", &bufsave);
        
        // Parse the firstline
        if (line != NULL) { 
                char* method  = strtok_r(line, " ", &linesave);
                char* path    = strtok_r(NULL, " ", &linesave);
                char* version = strtok_r(NULL, " ", &linesave);

                if (method == NULL || path == NULL || version == NULL) {
                        return -1;
                }

                strncpy(req->method, method, sizeof(req->method) - 1);
                strncpy(req->path, path, sizeof(req->path) - 1);
                strncpy(req->version, version, sizeof(req->version) - 1);
        }
        
        size_t index = 0;

        // Parse the headers
        while ((line = strtok_r(NULL, "\n", &bufsave)) != NULL) {
                if (index >= MAXHEADERS) {
                        return -2;
                }

                http_header header;
                char* separator = strchr(line, ':');
                
                if (separator != NULL) {
                        *separator = '\0';

                        char* key = line;
                        char* value = separator + 2;
                        strncpy(header.key, key, sizeof(header.key));
                        strncpy(header.value, value, sizeof(header.value));

                        req->headers[index++] = header;
                        req->n_headers++;
                }
        }

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

