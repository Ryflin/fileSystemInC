#include "fs2.c"


int main() {
  dir tempRoot = createNewDir("root");
  setRt(&tempRoot);
  dir *temp2 = getDir();
  // printf("%d",temp2->node->numChildren);
  while (1) {
    char cmd[256] = "";
    fgets(cmd, sizeof(cmd), stdin);
    char* token;
    char* tokens[5];  // assume max 5 tokens

    token = strtok(cmd, " ");
    int i = 0;
    while (token != NULL && i < 5) {
      printf("%d ", i);
      tokens[i] = token;
      token = strtok(NULL, " ");
      i++;
    }
    execv(, tokens);
  }
  prettyPrint(rt, "-");
  return 0;
}