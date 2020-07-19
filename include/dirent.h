#pragma once
#include <ygg/dirent.h>

typedef struct __DIR DIR;

DIR *opendir(const char *pathname);
int closedir(DIR *dir);
struct dirent *readdir(DIR *dir);
