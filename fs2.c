#include <string.h>
#include <stdlib.h>
#include <stdio.h>
#include <unistd.h>
#include "fs2.h"



struct dir {
  char* name;
  node* node;
};
struct node {
  unsigned int perms : 2;
  unsigned int isFile : 1;
  unsigned int numChildren;
  unsigned int size;
  dir* children;
};

dir createNewDir(char* newName) {
  node chnode = {
    .perms = 0,
    .isFile = 0,
    .numChildren = 2,
    .size = 4,
    .children = malloc(sizeof(dir) * 4)
  };
  dir child = { .name = malloc(sizeof(char) * 256), .node = &chnode };
  dir current = { .name = ".", .node = &chnode };
  dir parent = { .name = "..", .node = &chnode};
  char* nameRef = child.name;
  strcpy(nameRef, newName);
  chnode.children[0] = current;
  chnode.children[1] = parent;
  return child;
}

void prettyPrint(const dir* root, const char* start) {
  printf("%s%s/\n", start, root->name);
  char* spaces = "  -";
  node temp  = (*root->node);
  printf("%d\n",temp.numChildren);
  for (int i = 0; i < temp.numChildren; i++) {
    if (i > 2) {
    }
    else {
      strcat(spaces, start);
      prettyPrint(&temp.children[i], spaces);
    }
  }
}

int main() {
  dir root = createNewDir("root");
  printf(root.name);
  printf("%d\n", root.node->size);
  prettyPrint(&root, "-");
}