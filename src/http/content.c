#include <stdbool.h>
#include <string.h>


#include "http.h"


static const char *VALID_CONTENT_TYPES[] = {
    "text/html",
    "application/json",
    "text/plain",
    "image/png",
    "image/jpeg"
};


/* 
* Function to validate conent type
* Returns true when valid, and false when not. */
bool _validate_content_type(char *content_type) 
{
    // Make sure the content type is not too long.
    if (strlen(content_type) >= MAX_CONTENT_TYPE_LENGTH) 
    {
        return false;
    }

    for (int i = 0; i < sizeof(VALID_CONTENT_TYPES) / sizeof(VALID_CONTENT_TYPES[0]); i++) 
    {
        if (strcmp(content_type, VALID_CONTENT_TYPES[i]) == 0) 
        {
            return true;
        }
    }

    return false;
}