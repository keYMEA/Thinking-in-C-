#include <iostream>
#include "message.h"

using namespace std;

message::message(char*msg){
  name = msg;
}
void message::print(){
 cout<<name<<endl;
}
void message::print(char*str){
cout<<str<<" "<<name<<endl;
}
