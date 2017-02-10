#ifndef FILECLAS_H_INCLUDED
#define FILECLAS_H_INCLUDED
#include <stdio.h>
class file{
   FILE* f;
public:
    file(const char* fname, const char* mode = "r");
    ~file();
    FILE* fp();
};
#endif // FILECLAS_H_INCLUDED
