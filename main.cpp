#include <iostream>
#include"public.h"
#include"nestfrnd.h"
#include<conio.h>
#include"em3.h"
#include"em3.cpp"

using namespace std;


int main()
{
//    class A t;
//    int a= 1;
//    int b =9;
//    int res = sum(a,b,t);
//
//    cout<<res<<endl;
//    holder h;
//    holder::pointer hp1,hp2;
//    int i;
//
//    h.initialize();
//    hp1.initialize(&h);
//    hp2.initialize(&h);
//    for(int i=0; i<SZ; i++)
//    {
//        hp1.set(i);
//        hp1.next();
//    }
//    hp1.top();
//    hp2.end();
//    for(i=0; i<SZ; i++)
//    {
//        printf("hp1=%d,hp2=%d\n",hp1.read(),hp2.read());
//        hp1.next();
//        hp2.previous();
//    }
  Mobile u;
  u.initialize();

  u.set(5);
  u.read();
  u.cleanup();
  getch();
  //return 0;
}
