#ifndef SERVER_H
#define SERVER_H


typedef struct {
        char app[256];
        char venv[256];
        int port;
        int n_workers;
} flask_app;


#endif
