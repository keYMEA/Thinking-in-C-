
/*假设有一个程序设计工具，当创建时它的表现像一个数组，但它的长度能在运行时建
立。我称它为stash*/
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
//stash()的第一个构造函数与前面一样，但第二个带了一个 Quantity参数来指明分配内存的
//初始大小。在这个定义中，我们可以看到 quantity的内部值与storage指针一起被置零
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
	/*我们必须用标准 C 库函数memcpy( )一个字节一个字节地拷贝这个变量，第一个参数是 memcpy()
	开始拷贝字节的目的地址，由下面表达式产生：
	                &(S->storage[S->next * S->size])
	它指示从存储块开始的第 next个可用单元结束。这个数实际上就是已经用过的单元号加一
	的计数，它必须乘上每个单元拥有的字节数，产生按字节计算的偏移量。这不产生地址，而是
	产生处于这个地址的字节，为了产生地址，必须使用地址操作符 &。
	memcpy()的第二和第三个参数分别是被拷贝变量的开始地址和要拷贝的字节数。 n e x t计数
	器加一，并返回被存值的索引。这样，程序员可以在后面调用 fetch( )时用它来取得这个元素。*/
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
