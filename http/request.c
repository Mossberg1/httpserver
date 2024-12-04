//
// Created by William Mossberg on 2024-12-04.
//
#include <stdio.h>
#include <string.h>
#include <stdlib.h>

#include "../include/http.h"


static void _parse_header(http_request *req, char *line);


/*
* Function to free request structure. */
void free_request(http_request *req)
{
    free(req->method);
    free(req->path);
    free(req->version);
    free(req->host);
    free(req->user_agent);
    free(req->accept_language);
    free(req->accept_encoding);
    free(req->connection);
    free(req->content_type);
    free(req->content_length);
    free(req->body);
    free(req);
}


/*
* Functio to parse http request.
* FIXME: Does not parse request body correct.
*/
void parse_request(http_request *req, char *buffer)
{
    char *save;
    char *line = strtok_r(buffer, "\r\n", &save);

    // Parse the request line.
    if (line)
    {
        req->method = strdup(strtok(line, " "));
        req->path = strdup(strtok(NULL, " "));
        req->version = strdup(strtok(NULL, " "));
    }

    while ((line = strtok_r(NULL, "\r\n", &save)) && strlen(line) > 0)
    {
        _parse_header(req, line);

        // Parse the body.
        if (req->content_length && save != NULL)
        {
            int len = atoi(req->content_length);
            req->body = strndup(save, len + 1);
        }
    }

}

/* Function to validate http request
* TODO: Implement. */
bool validate_request(http_request *req)
{
    return true;
}


static void _parse_header(http_request *req, char *line)
{
    char *key = strtok(line, ": ");
    char *value = strtok(NULL, "\r\n");

    if (key && value)
    {
        if (strcasecmp(key, "Host") == 0)
        {
            req->host = strdup(value);
        }
        else if (strcasecmp(key, "User-Agent") == 0)
        {
            req->user_agent = strdup(value);
        }
        else if (strcasecmp(key, "Accept") == 0)
        {
            req->accept = strdup(value);
        }
        else if (strcasecmp(key, "Accept-Language") == 0)
        {
            req->accept_language = strdup(value);
        }
        else if (strcasecmp(key, "Accept-Encoding") == 0)
        {
            req->accept_encoding = strdup(value);
        }
        else if (strcasecmp(key, "Connection") == 0)
        {
            req->connection = strdup(value);
        }
        else if (strcasecmp(key, "Content-Type") == 0)
        {
            req->content_type = strdup(value);
        }
        else if (strcasecmp(key, "Content-Length") == 0)
        {
            req->content_length = strdup(value);
        }
    }
}


