
/*������һ��������ƹ��ߣ�������ʱ���ı�����һ�����飬�����ĳ�����������ʱ��
�����ҳ���Ϊstash*/
#include"stash.h"
/*stash::stash(int Size)
{
	size = Size;
	quantity = 0;
	storage = 0;
	next = 0;
}
*/
stash::stash(int Size, int InitQuant)
//stash()�ĵ�һ�����캯����ǰ��һ�������ڶ�������һ�� Quantity������ָ�������ڴ��
//��ʼ��С������������У����ǿ��Կ��� quantity���ڲ�ֵ��storageָ��һ������
{
	size = Size;
	quantity = 0;
	next = 0;
	storage = 0;
	inflate(InitQuant);
}

stash::~stash()
{
	if(storage)
	{
		puts("freeing storage");
		free(storage);
	}
}

int stash::add(void* element)
{
	if(next >= quantity)
	{
		inflate(100);
	}
	memcpy(&(storage[next * size]),element,size );
	/*���Ǳ����ñ�׼ C �⺯��memcpy( )һ���ֽ�һ���ֽڵؿ��������������һ�������� memcpy()
	��ʼ�����ֽڵ�Ŀ�ĵ�ַ����������ʽ������
	                &(S->storage[S->next * S->size])
	��ָʾ�Ӵ洢�鿪ʼ�ĵ� next�����õ�Ԫ�����������ʵ���Ͼ����Ѿ��ù��ĵ�Ԫ�ż�һ
	�ļ��������������ÿ����Ԫӵ�е��ֽ������������ֽڼ����ƫ�������ⲻ������ַ������
	�������������ַ���ֽڣ�Ϊ�˲�����ַ������ʹ�õ�ַ������ &��
	memcpy()�ĵڶ��͵����������ֱ��Ǳ����������Ŀ�ʼ��ַ��Ҫ�������ֽ����� n e x t����
	����һ�������ر���ֵ������������������Ա�����ں������ fetch( )ʱ������ȡ�����Ԫ�ء�*/
	next ++;
	return (next - 1);
}

void* stash::fetch(int index)
{
	if(index >= next || index < 0)
	{
		return 0;
	}
	return &(storage[index * size]);
}

int stash::count()
{
	return next;
}

void stash::inflate(int increase)
{
	void* v = realloc(storage,(quantity + increase)*size );
	assert(v);
	storage = (unsigned char*)v;
	quantity += increase;
}
