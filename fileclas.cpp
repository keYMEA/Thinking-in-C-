#include"fileclas.h"
#include<stdlib.h>
#include "FILECLAS.h"
/*FILECLAS.cpp*/
file::file(const char* fname, const char* mode)
//如果结果是零意味着打开文件时出错。如果出错，这个文件名就被打印，而且函数 exit( )被调用
{
	f = fopen(fname, mode);
	if(f == NULL)
	{
		printf("%s: file not found\n",fname);
		exit(1);
	}
}

file::~file()
{
	fclose(f);
}
FILE*file::fp(){
    return f;
}
