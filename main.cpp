#include"fileclas.h"
#include"fileclas.cpp"
#include<assert.h>
#define BSIZE 100
/*USEFILECLAS.cpp*/
int main(int argc, char* argv[])
{
	//char* fn="sad.txt";
	//assert(argc == 2);
	file f("debug.log");
	char buf[BSIZE];
	while(fgets(buf, BSIZE, f.fp()))
	{
		puts(buf);
	}

	return 0;
}
