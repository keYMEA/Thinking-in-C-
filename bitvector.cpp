#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <assert.h>
#include"bitvector.h"
#include<limits.h>

const unsigned char highbit = 1 << (CHAR_BIT - 1);
BitVector::BitVector()
{
    bytes = 0;
    Bits = 0;
    numBytes = 0;
}
BitVector::BitVector(unsigned char* init, int size)
{
    numBytes = size;
    Bits = numBytes *CHAR_BIT;
    bytes = (unsigned char*)calloc(numBytes,1);
    assert(bytes);
    if(init == 0)
    {
        return;
    }
    for(int index = 0; index<numBytes; index++)
    {
        for(int offset =0; offset<CHAR_BIT; offset++)
        {
            if(init[index]&highbit>>offset)
            {
                set(index*CHAR_BIT + offset);
            }
        }
    }
}
BitVector::BitVector(char* binary)
{
    Bits = strlen(binary);
    numBytes = Bits/CHAR_BIT;
    if(Bits%CHAR_BIT)
    {
        numBytes++;
    }
    bytes = (unsigned char*)calloc(numBytes,1);
    assert(bytes);
    for(int i=0; i<Bits; i++)
    {
        if(binary[i]=='1')
        {
            set(i);
        }
    }
}
BitVector::~BitVector()
{
    free(bytes);
}
void BitVector::set(int bit)
{
    assert(bit>=0&&bit<Bits);//数据长度
    int index = bit/CHAR_BIT;
    int offset = bit%CHAR_BIT;
    unsigned char mask =(1<<offset);
    bytes[index] |= mask;
}
void BitVector::clear(int bit)
{
    assert(bit >= 0 && bit < Bits);
    int index = bit / CHAR_BIT;
    int offset = bit % CHAR_BIT;
    unsigned char mask = ~(1 << offset);
    bytes[index] &= mask;
    //bytes[bit/CHAR_BIT]&=~(1<<(bit % CHAR_BIT))；
}
int BitVector::read(int bit)
{
    assert(bit >= 0 && bit < Bits);
    int index = bit / CHAR_BIT;
    int offset = bit % CHAR_BIT;
    unsigned char mask = (1 << offset);
    return bytes[index] & mask;
    //return bytes[bit/CHAR_BIT] & (1<<(bit % CHAR_BIT))；
}

int BitVector::bits()
/*第一个仅仅是一个存取函数（一种向没有访问权限的人提供私有成员数据的函数）
，告知数组中共有多少位。*/
{
    return Bits;
}
void BitVector::bits(int size)
/*第二个函数用它的参数来计算所
需的字节数，然后用realloc()函数重新分配内存（如果bytes为零，它将分配新内存
），并对新增的位置零。注意，如果我们要求的位数与原有的位数相等，这个函数仍
有可能重新分配内存（这取决于realloc()函数的实现）。但这不会破坏任何东西。*/
{
    int oldsize = Bits;
    Bits = size;
    numBytes = Bits / CHAR_BIT;
    if(Bits % CHAR_BIT)
    {
        numBytes++;
    }
    void* v = realloc(bytes, numBytes);
    assert(v);
    bytes = (unsigned char*)v;
    for(int i = oldsize; i < Bits; ++i)
    {
        clear(i);
    }
}

void BitVector::print(const char* msg)
/*print()函数显示msg字串，标准的 C库函数puts()已经加了一个新行，所以对缺省
参数将输出一个新行。然后它用read()读取每一位的值以确定显示什么字符。为了阅
读方便，在每读完 8位后它显示一个空格。由于第二个 BitVector构造函数是读取字
节数组的方式， print()函数将会用熟悉的形式显示结果。*/
{
    puts(msg);
    for(int i = 0; i < Bits; ++i)
    {
        if(read(i))
        {
            putchar('1');
        }
        else
        {
            putchar('0');
        }
        if((i+1) % CHAR_BIT == 0)
        {
            putchar(' ');
        }
    }
    putchar('\n');
}
