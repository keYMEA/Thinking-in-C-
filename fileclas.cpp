#include"fileclas.h"
#include<stdlib.h>
#include "FILECLAS.h"
/*FILECLAS.cpp*/
file::file(const char* fname, const char* mode)
//������������ζ�Ŵ��ļ�ʱ���������������ļ����ͱ���ӡ�����Һ��� exit( )������
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
