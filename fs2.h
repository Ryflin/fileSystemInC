typedef struct dir dir;
typedef struct node node;
dir createNewDir(char *name);
void prettyPrint(const dir *root, const char *start);