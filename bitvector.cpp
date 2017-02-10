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
    assert(bit>=0&&bit<Bits);//���ݳ���
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
    //bytes[bit/CHAR_BIT]&=~(1<<(bit % CHAR_BIT))��
}
int BitVector::read(int bit)
{
    assert(bit >= 0 && bit < Bits);
    int index = bit / CHAR_BIT;
    int offset = bit % CHAR_BIT;
    unsigned char mask = (1 << offset);
    return bytes[index] & mask;
    //return bytes[bit/CHAR_BIT] & (1<<(bit % CHAR_BIT))��
}

int BitVector::bits()
/*��һ��������һ����ȡ������һ����û�з���Ȩ�޵����ṩ˽�г�Ա���ݵĺ�����
����֪�����й��ж���λ��*/
{
    return Bits;
}
void BitVector::bits(int size)
/*�ڶ������������Ĳ�����������
����ֽ�����Ȼ����realloc()�������·����ڴ棨���bytesΪ�㣬�����������ڴ�
��������������λ���㡣ע�⣬�������Ҫ���λ����ԭ�е�λ����ȣ����������
�п������·����ڴ棨��ȡ����realloc()������ʵ�֣������ⲻ���ƻ��κζ�����*/
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
/*print()������ʾmsg�ִ�����׼�� C�⺯��puts()�Ѿ�����һ�����У����Զ�ȱʡ
���������һ�����С�Ȼ������read()��ȡÿһλ��ֵ��ȷ����ʾʲô�ַ���Ϊ����
�����㣬��ÿ���� 8λ������ʾһ���ո����ڵڶ��� BitVector���캯���Ƕ�ȡ��
������ķ�ʽ�� print()������������Ϥ����ʽ��ʾ�����*/
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
