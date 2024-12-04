//
// Created by William Mossberg on 2024-12-04.
//
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>

#include "../include/http.h"


static int _generate_full_response(http_response *res);


/*
* Function to free allocated http_response struct. */
void free_response(http_response *res)
{
    free(res->content_type);
    free(res->body);
    free(res->full_response);
    free(res);
}


/*
* Function to create a new http_response.
* Returns a full http response.
* Remember to use free_response() function when done with the response. */
int generate_response(http_response *res, int status_code, char *content_type, char *body)
{
    // Validate status code.
    http_status status = _generate_status(status_code);
    if (status.code == -1)
    {
        return -1;
    }

    // Validate content type.
    if (!_validate_content_type(content_type))
    {
        return -1;
    }

    // Make sure body length is less that max body length.
    size_t body_length = strlen(body);
    if (body_length >= MAX_BODY_LENGTH)
    {
        return -1;
    }

    res->status = status;

    res->content_type = malloc(strlen(content_type) + 1);
    if (res->content_type == NULL)
    {
        return -1;
    }
    strcpy(res->content_type, content_type);

    res->content_length = body_length;

    res->body = malloc(body_length + 1);
    if (res->body == NULL)
    {
        free(res->content_type);
        return -1;
    }
    strcpy(res->body, body);

    if (_generate_full_response(res) == -1)
    {
        free(res->content_type);
        free(res->body);
        return -1;
    }

    return 0;
}


/*
* Function to generate a full response.
* This function allocates memory.
* Remember to free with free_response when done. */
static int _generate_full_response(http_response *res)
{
    // Calculate size to allocate for full response.
    size_t size = snprintf(
        NULL,
        0,
        "HTTP/1.1 %d %s\r\n"
        "Content-Type: %s\r\n"
        "Content-Length: %zu\r\n"
        "\r\n%s",
        res->status.code,
        res->status.message,
        res->content_type,
        res->content_length,
        res->body
    ) + 1;

    res->full_response = malloc(size);
    if (res->full_response == NULL)
    {
        return -1;
    }

    snprintf(
        res->full_response,
        size,
        "HTTP/1.1 %d %s\r\n"
        "Content-Type: %s\r\n"
        "Content-Length: %zu\r\n"
        "\r\n%s",
        res->status.code,
        res->status.message,
        res->content_type,
        res->content_length,
        res->body
    );

    return 0;
}


