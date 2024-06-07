#include <stdbool.h>
typedef struct dir dir;
typedef struct node node;
typedef struct file file;
struct dir {
  char* name;
  bool isFile;
  node* node;
};
struct node {
  unsigned int perms : 2;
  unsigned int numChildren;
  unsigned int size;
  dir* children;
};
struct file {
  char* givenName;
  char* link;
};
dir createNewDir(const char* name);
void prettyPrint(const dir* root, const char* start);
char* mkdir(dir* root,const char* args, const char* dirName);
char* cd(dir** root,const char *args, const char* placeToGo);
dir* getDir();
char* ls(dir* root, const char* args, const char* dirName);
char* mv(dir* root, const char* args, const char* dir1, const char* dir2);
char* getcin();
bool dirIsInCwd(dir* root, const char* dirName);