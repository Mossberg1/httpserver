//
// Created by William Mossberg on 2024-12-04.
//
#include "../include/http.h"


/*
* Generate a status code.
* Returns -1 on invalid code. */
http_status _generate_status(int code)
{
    switch (code)
    {
        case 100:
            return (http_status){100, "Continue"};
        case 101:
            return (http_status){101, "Switching Protocols"};
        case 102:
            return (http_status){102, "Processing"};
        case 103:
            return (http_status){103, "Early Hints"};
        case 200:
            return (http_status){200, "OK"};
        case 201:
            return (http_status){201, "Created"};
        case 202:
            return (http_status){202, "Accepted"};
        case 203:
            return (http_status){203, "Non-Authoritative Information"};
        case 204:
            return (http_status){204, "No Content"};
        case 205:
            return (http_status){205, "Reset Content"};
        case 206:
            return (http_status){206, "Partial Content"};
        case 207:
            return (http_status){207, "Multi-Status"};
        case 208:
            return (http_status){208, "Already Reported"};
        case 226:
            return (http_status){226, "IM Used"};
        case 300:
            return (http_status){300, "Multiple Choices"};
        case 301:
            return (http_status){301, "Moved Permanently"};
        case 302:
            return (http_status){302, "Found"};
        case 303:
            return (http_status){303, "See Other"};
        case 304:
            return (http_status){304, "Not Modified"};
        case 305:
            return (http_status){305, "Use Proxy"};
        case 306:
            return (http_status){306, "Switch Proxy"};
        case 307:
            return (http_status){307, "Temporary Redirect"};
        case 308:
            return (http_status){308, "Permanent Redirect"};
        case 400:
            return (http_status){400, "Bad Request"};
        case 401:
            return (http_status){401, "Unauthorized"};
        case 402:
            return (http_status){402, "Payment Required"};
        case 403:
            return (http_status){403, "Forbidden"};
        case 404:
            return (http_status){404, "Not Found"};
        case 405:
            return (http_status){405, "Method Not Allowed"};
        case 406:
            return (http_status){406, "Not Acceptable"};
        case 407:
            return (http_status){407, "Proxy Authentication Required"};
        case 408:
            return (http_status){408, "Request Timeout"};
        case 409:
            return (http_status){409, "Conflict"};
        case 410:
            return (http_status){410, "Gone"};
        case 411:
            return (http_status){411, "Length Required"};
        case 412:
            return (http_status){412, "Precondition Failed"};
        case 413:
            return (http_status){413, "Payload Too Large"};
        case 414:
            return (http_status){414, "URI Too Long"};
        case 415:
            return (http_status){415, "Unsupported Media Type"};
        case 416:
            return (http_status){416, "Range Not Satisfiable"};
        case 417:
            return (http_status){417, "Expectation Failed"};
        case 418:
            return (http_status){418, "I'm a teapot"};
        case 421:
            return (http_status){421, "Misdirected Request"};
        case 422:
            return (http_status){422, "Unprocessable Entity"};
        case 423:
            return (http_status){423, "Locked"};
        case 424:
            return (http_status){424, "Failed Dependency"};
        case 425:
            return (http_status){425, "Too Early"};
        case 426:
            return (http_status){426, "Upgrade Required"};
        case 428:
            return (http_status){428, "Precondition Required"};
        case 429:
            return (http_status){429, "Too Many Requests"};
        case 431:
            return (http_status){431, "Request Header Fields Too Large"};
        case 451:
            return (http_status){451, "Unavailable For Legal Reasons"};
        case 500:
            return (http_status){500, "Internal Server Error"};
        case 501:
            return (http_status){501, "Not Implemented"};
        case 502:
            return (http_status){502, "Bad Gateway"};
        case 503:
            return (http_status){503, "Service Unavailable"};
        case 504:
            return (http_status){504, "Gateway Timeout"};
        case 505:
            return (http_status){505, "HTTP Version Not Supported"};
        case 506:
            return (http_status){506, "Variant Also Negotiates"};
        case 507:
            return (http_status){507, "Insufficient Storage"};
        case 508:
            return (http_status){508, "Loop Detected"};
        case 510:
            return (http_status){510, "Not Extended"};
        case 511:
            return (http_status){511, "Network Authentication Required"};
        default:
            return (http_status){-1, "Unknown Status Code"};
    }
}