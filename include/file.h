#ifndef FILE_H
#define FILE_H

#include <stdbool.h>
#include <stddef.h>


struct fnode {
        char name[64];
        bool isdir;
        struct fnode* parent;
        struct fnode* firstchild;
        struct fnode* next;
};


struct fnode* fnode_create(const char name[], struct fnode* parent, bool isdir);
void fnode_fullpath(struct fnode* node, char buffer[], size_t size);
void fnode_add_child(struct fnode* parent, struct fnode* child);
void fnode_print(struct fnode* node, int depth);


#endif
