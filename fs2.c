#include <string.h>
#include <stdlib.h>
#include <stdio.h>
#include <unistd.h>
#include "fs2.h"
#define max_input 256

dir createNewDir(const char* newName) {
  node* chnode = malloc(sizeof(node));
  chnode->perms = 0;
  chnode->numChildren = 2;
  chnode->size = 4;
  dir child = { .name = malloc(sizeof(char) * 256), .node = chnode };
  dir current = { .name = ".", .node = chnode };
  dir parent = { .name = "..", .node = chnode };
  char* nameRef = child.name;
  strcpy(nameRef, newName);
  chnode->children[0] = current;
  chnode->children[1] = parent;
  return child;
}

bool dirIsInCwd(dir* root, const char* dirName) {
  
  return false;
}

char* mkdir(dir* root, const char* args, const char* newName) {
  return "";
}

char* cd(dir** root, const char* args, const char* dirName) {
  return "";
}

char* rm(dir* root, const char* args, const char* dirName) {
  return "";
}

char* pwd(dir* root) {
  return "";
}

char* ls(dir* root, const char* args, const char* dirName) {
  if (strlen(dirName) < 1) {

  }
  return "";
}

char* cp(dir* root, const char* args, const char* dir1, const char* dir2) {
  return "";
}

/**
 *
 */
char* mv(dir* root, const char* args, const char* dir1, const char* dir2) {
  return "";

}

void prettyPrint(const dir* root, const char* start) {
  // printf("%s%s/\n", start, root->name);
  char* spaces = "  -";
  node temp = (*root->node);
  printf("%d\n", temp.numChildren);
  for (int i = 0; i < temp.numChildren; i++) {
    if (i > 2) {
    }
    else {
      strcat(spaces, start);
      prettyPrint(&temp.children[i], spaces);
    }
  }
}

char* getcin() {
  char* cmd = malloc(sizeof(char) * max_input);
  int c, i = 0;
  while ((c = getchar()) != '\n' && i < max_input - 1) {
    *(cmd + i++) = c;
  }
  *(cmd + i) = '\0';
  return cmd;
}

char* cat(dir* root, const char* fileName) {

}

int main() {
  dir root = createNewDir("root");
  dir* cwd = &root;
  mkdir(cwd, "", "info");
  cd(&cwd, "", "info");

  while (1) {
    char* cmd = getcin();
    char* token = strtok(cmd, " ");
    char* first = strtok(NULL, " ");
    char* args = "";
    if (first[0] != '-') {
      strcpy(args, first);
      first = strtok(NULL, " ");
    }
    if (strcmp(token, "mkdir")) {
      char* args = strtok(NULL, " ");
    }

  }

  // printf(root);
  printf("%d\n", root.node->size);
  prettyPrint(&root, "-");
}