#include "fs2.c"
#include <stdio.h>
#include <string.h>
#include <stdlib.h>

int main(int argc, char* argv[]) {
  if (argc > 2) {
    return -1; 
  }

  char *dirName = argv[argc-1];
  printf("%s  dirname\n", dirName);
  dir *rt = getDir();

  // printf("%s",(*rt).name);
  // printf("%d", rt->node->numChildren);

  // printf("%d", temp->numChildren);
  // for (int i = 0; i < temp->numChildren; i++) {
  //   if (strcmp(temp->children[i].name, dirName) == 0) {
  //     return 1;
  //   }
  // }
  // if (temp->size <= temp->numChildren) {
  //   temp->children = realloc(temp->children, sizeof(dir) * temp->size * 2);
  // }
  // dir toBeAdded = createNewDir(dirName);
  // temp->children[temp->numChildren] = toBeAdded;
  // temp->numChildren++;
  return 0;
}