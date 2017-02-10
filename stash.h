#ifndef STASH_H_INCLUDED
#define STASH_H_INCLUDED

#include <assert.h>
#include <stdlib.h>
#include <string.h>
#include <stdio.h>
//C++
class stash
{
	int size;                 //Size of each space
	int quantity;             //Number of storage spaces
	int next;                 //Next empty space
	unsigned char* storage;   //storage指针是一个unsigned char*。这是 C 编译器支持的最小的存储片，尽管在某些机器
	                          //上它可能与最大的一般大，这依赖于具体实现。 storage指向的内存从堆中分配
	void inflate(int increase);
	/*inflate()函数使用realloc()为stash得到更大的空间块。 realloc()把已经分配而又希望重分配
	的存储单元首地址作为它的第一个参数（如果这个参数为零，例如 initialize()刚刚被调用时，
	realloc()分配一个新块）。第二个参数是这个块新的长度，如果这个长度比原来的小，这个块
	将不需要作拷贝，简单地告诉堆管理器剩下的空间是空闲的。如果这个长度比原来的大，在堆
	中没有足够的相临空间，所以要分配新块，并且要拷贝内存。 assert()检查以确信这个操作成
	功。（如果这个堆用光了， malloc()、 calloc()和realloc()都返回零。）*/
public:
	//stash(int Size);          //构造函数
	stash(int Size, int InitQuant = 100);
	~stash();                 //析构函数
	int add(void* element);   //add()函数在stash的下一个可用位子上插入一个元素。首先，它检查是否有可用空间，如
	                          //果没有，它就用后面介绍的 inflate() 函数扩展存储空间。
	void* fetch(int index);   //fetch()首先看索引是否越界，如果没有越界，返回所希望的变量地址，地址的计算采用与
	                          //add()中相同的方法
	int count();              //返回所存储空间大小
};


#endif // STASH_H_INCLUDED
