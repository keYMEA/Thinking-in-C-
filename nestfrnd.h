#ifndef NESTFRND_H_INCLUDED
#define NESTFRND_H_INCLUDED



#endif // NESTFRND_H_INCLUDED
#include<stdio.h>
#include<string.h>
#define SZ 20

struct holder
{
private:
    int a[SZ];
public:
    void initialize();
    struct pointer
    {
    private:
        holder* h;
        int* p;
    public:
        void initialize(holder* H);
        void next();
        void previous();
        void top();
        void end();

        int read();
        void set(int i);
    };
    friend holder :: pointer;
};
void holder::initialize()
{
    memset(a,0,SZ*sizeof(int));
}//不能在ain里使用

void holder::pointer::initialize(holder* H)
{
    h= H;
    p=h->a;
}
void holder::pointer::next()
{
    if(p<&(h->a[SZ-1])) p++;
}

void holder::pointer::previous()
{
    if(p>&(h->a[0])) p--;
}

void holder::pointer::top()
{
    if(p=&(h->a[0])) ;//取地址&
}

void holder::pointer::end()
{
    if(p=&(h->a[SZ-1])) ;
}

int holder::pointer::read()
{
    return *p;
}

void holder::pointer::set(int i)
{
    *p = i;
}

