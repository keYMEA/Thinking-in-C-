#include <stdio.h>
#include <iostream>
#include <stdlib.h>
#include<assert.h>
//#include "em3.h"
using namespace std;
struct Mobile::con{
   int i;
};

void Mobile::initialize(){
   concent=(con*)malloc(sizeof(con));
   assert(concent);
   concent->i = 0;
}
void Mobile::set(int j){
    concent->i = j;
}
void Mobile::read(){
    std::cout<<concent->i<<endl;
}
void Mobile::cleanup(){
     free(concent);
}
