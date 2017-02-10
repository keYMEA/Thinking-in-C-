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
	unsigned char* storage;   //storageָ����һ��unsigned char*������ C ������֧�ֵ���С�Ĵ洢Ƭ��������ĳЩ����
	                          //��������������һ����������ھ���ʵ�֡� storageָ����ڴ�Ӷ��з���
	void inflate(int increase);
	/*inflate()����ʹ��realloc()Ϊstash�õ�����Ŀռ�顣 realloc()���Ѿ��������ϣ���ط���
	�Ĵ洢��Ԫ�׵�ַ��Ϊ���ĵ�һ������������������Ϊ�㣬���� initialize()�ոձ�����ʱ��
	realloc()����һ���¿飩���ڶ���������������µĳ��ȣ����������ȱ�ԭ����С�������
	������Ҫ���������򵥵ظ��߶ѹ�����ʣ�µĿռ��ǿ��еġ����������ȱ�ԭ���Ĵ��ڶ�
	��û���㹻�����ٿռ䣬����Ҫ�����¿飬����Ҫ�����ڴ档 assert()�����ȷ�����������
	���������������ù��ˣ� malloc()�� calloc()��realloc()�������㡣��*/
public:
	//stash(int Size);          //���캯��
	stash(int Size, int InitQuant = 100);
	~stash();                 //��������
	int add(void* element);   //add()������stash����һ������λ���ϲ���һ��Ԫ�ء����ȣ�������Ƿ��п��ÿռ䣬��
	                          //��û�У������ú�����ܵ� inflate() ������չ�洢�ռ䡣
	void* fetch(int index);   //fetch()���ȿ������Ƿ�Խ�磬���û��Խ�磬������ϣ���ı�����ַ����ַ�ļ��������
	                          //add()����ͬ�ķ���
	int count();              //�������洢�ռ��С
};


#endif // STASH_H_INCLUDED
