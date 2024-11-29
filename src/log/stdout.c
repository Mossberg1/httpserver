#include <stdio.h>
#include <time.h>

#include "http.h"


/*
* Function to log a simple request and response to stdout */
void log_stdout(http_request *req, http_response *res) 
{
    // Example format : [TIME] GET / HTTP/1.1 -> 200 OK :: ip address

    time_t now = time(NULL);
    struct tm *local = localtime(&now);

    printf(
        "[%02d:%02d:%02d] %s %s %s -> %d %s :: %s\n", 
        local->tm_hour, local->tm_min, local->tm_sec, 
        req->method, req->path, req->version, 
        res->status.code, res->status.message, 
        req->host
    );
}