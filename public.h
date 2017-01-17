#ifndef PUBLIC_H_INCLUDED
#define PUBLIC_H_INCLUDED
#endif // PUBLIC_H_INCLUDED
#include<iostream>
//PUBLIC.H
using namespace std;

class A
{
public:
    int i;
    char j;
    friend int sum(int,int,A&);

private:
    int f;
    void foo(int a,int b);

};
int sum(int a, int b,A&t)
{
    t.f = b;
    return a+t.f;
}

//void A::foo(int a, int b)
//{
//    int t =a+b;
//    cout<<t+"\n"<<endl;
//
//};
//struct B
//{
//    int i;
//    char j;
//    float f;
//    void foo();
//};
//void B::foo() {};
