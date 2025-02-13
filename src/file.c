#include <stdio.h>
#include <stdbool.h>
#include <string.h>
#include <stdlib.h>

#include "../include/file.h"


/* Creates a file node structure
 * this function allocates memory,
 * remember to free memory when done. */
struct fnode* fnode_create(const char name[], struct fnode* parent, bool isdir) 
{
        struct fnode* fn = (struct fnode*)malloc(sizeof(struct fnode));
        if (fn == NULL) { 
                return NULL; 
        }

        strncpy(fn->name, name, sizeof(fn->name) - 1);
        
        fn->isdir       = isdir;
        fn->parent      = parent;
        fn->firstchild  = NULL;
        fn->next        = NULL;
        
        return fn;
}


void fnode_fullpath(struct fnode* node, char buffer[], size_t size) 
{
        if (node == NULL) {
                return;
        }

        if (node->parent) {
                fnode_fullpath(node->parent, buffer, size);
                strncat(buffer, "/", size - strlen(buffer) - 1);
        }

        strncat(buffer, node->name, size - strlen(buffer) - 1);
        
        return;
}


void fnode_add_child(struct fnode* parent, struct fnode* child) 
{
        if (!parent->isdir) { // Can create sub directories on a file.
                return;
        }

        if (parent->firstchild == NULL) {
                parent->firstchild = child;
        } 
        else {
                struct fnode* sibling = parent->firstchild;
                while (sibling->next) {
                        sibling = sibling->next; // Find the last child (sub directory)
                }

                sibling->next = child; // Add child at the end of the children (sub directories)
        }

        return;
}


void fnode_print(struct fnode* node, int depth) 
{
        if (node == NULL) {
                return;
        }
        
        // Print indentation for tree structure.
        for (size_t i = 0; i < depth; i++) {
                printf("    "); 
        }

        printf("%s%s\n", node->name, node->isdir ? "/" : "");

        if (node->firstchild) fnode_print(node->firstchild, depth + 1); // Print children
        if (node->next) fnode_print(node->next, depth); // Print siblings
        
        return;
}
