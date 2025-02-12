#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>


#include "../include/server.h"



int server_run(flask_app flask) 
{
        char gunicorn[128];
        char port[32];
        char workers[16];
        
        if (chdir(flask.app) == -1) {
                return -1;
        }

        snprintf(gunicorn, sizeof(gunicorn), "%s/bin/gunicorn", flask.venv);
        snprintf(port, sizeof(port), "-b 0.0.0.0:%d", flask.port);
        snprintf(workers, sizeof(workers), "-w %d", flask.n_workers);

        char* args[] = {
                gunicorn,
                workers,
                port,
                "app:app",
                NULL
        };

        execvp(gunicorn, args);

        return -1;
}
