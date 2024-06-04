#include <stdio.h>
#include <math.h>
#include <string.h>
#include <stdlib.h>

const int START_FILE_SIZE = 2;
typedef struct dir dir;
dir newDir(char dirName[]);
void mkdir(dir* root, char* newName);
void printDirectories(const dir* root);
dir parse_directory(const dir* root, char*);
dir makeCurrentDirectory(const dir* root);
void cd(dir** root, char* dest);


struct dir {
  unsigned int size;
  unsigned int numChildren;
  char* name;
  dir* children;
};


void printDirectories(const dir* root) {
  printf("/%s", root->name);
  dir* temp = root->children;
  printf("%d", root->numChildren);
  for (int i = 0; i < root->numChildren; i++) {
    if (i < 2) {
      printf("/%s", root->children[i].name);
    }
    else {
      printDirectories(&root->children[i]);
    }
  }
}

void cd(dir** root, char* dest) {
  for (int i = 0; i < (*root)->numChildren; i++) {
    printf("child %d, %s\n", i, (*root)->children[i].name);
  }
  for (int i = 0; i < (*root)->numChildren; i++) {
    if (strcmp(dest, (*root)->children[i].name) == 0) {
      printf("cd to %s\n", (*root)->children[i].name);
      *root = &((*root)->children[i]);
      // if (strcmp((*root)->children[i].name, "..") == 0 || strcmp((*root)->name, ".")) {
      //   *root = &((*root)->children[0]);
      // }
      break;
    }
  }
}

dir parse_directory(const dir* root, char* given) {

}

void mkdir(dir* root, char* newName) {
  printf("mkdir from: %s\n", root->name);
  if (root->size <= root->numChildren) {
    root->children = realloc(root->children, root->size * 2 * sizeof(dir));
  }
  dir child = newDir(newName);
  // 1 is the parent (..)
  // 0 is the current (.)
  child.children[1].children = &child;
  root->children[root->numChildren] = child;
  root->numChildren++;
}

dir newDir(char* dirName) {
  dir child = {
      .name = malloc(sizeof(char) * 256),
      .children = malloc(sizeof(dir) * 4),
      .numChildren = 2,
      .size = 4
  };

  dir parent = { .name = "..",.size = 1,.numChildren = 1,.children = &child };
  dir current = { .name = ".", .size = 1,.numChildren = 1,.children = &child };
  child.children[0] = current;
  child.children[1] = parent;
  strcpy(child.name, dirName);
  return child;
}

int main() {
  dir root = newDir("root/");
  dir* rootDir = &root;
  dir* cwd = &root;
  while (1) {
    char cmd[256] = "";
    fgets(cmd, sizeof(cmd), stdin);
    char* token = strtok(cmd, " ");
    if (strcmp(token, "mkdir") == 0) {
      token = strtok(NULL, " ");
      if (token[strlen(token) - 1] == '\n') {
        token[strlen(token) - 1] = '\0';
      }
      printf("%s\n", token);
      mkdir(cwd, token);
    }
    else if (strcmp(token, "cd") == 0) {
      token = strtok(NULL, " ");
      if (token[strlen(token) - 1] == '\n') {
        token[strlen(token) - 1] = '\0';
      }
      printf("pre-cd root: %s\n", cwd->name);
      cd(&cwd, token);
      printf("cd root: %s", cwd->name);
    }
    else if (strcmp(cmd, "q") == 0) {
      break;
    }
    if (strcmp(cwd->name, "..") == 0) {
      cwd = cwd->children;
    }
    printf("\n");
    printDirectories(rootDir);
    printf("\n");
  }

  return 0;
}