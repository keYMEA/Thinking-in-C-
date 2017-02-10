#include<iostream>
#include<vector>

class test
{
public:
    test(){
      value = 1;
      std::cout<<"no para contributor"<<std::endl;
    }
private:
    int value;
}
class testChild:public test{
public:
    testChild(){
    std::cout<<"child para contributor"<<std::endl;
    }
};
class test2{
public:
    test2(){
    std::cout<<"test2 no pare"<<std::endl;
    }
private:
    test2 t;
};

int main(){
    cout<<"对于默认构造函数调用的测试:"<<endl;
    cout<<"\n未显示调用构造函数："<<endl;
    test ts;
    cout<<"\n显示调用构造函数："<<endl;
    test *mcptr = new test;
    //或MyClass *mcptr = new MyClass();
    cout<<"\n静态分配数组："<<endl;
    test tsArrayStatic[5];
    cout<<"\n动态分配数组："<<endl;
    test *tsArrayDynamic = new tsArrayDynamic[6];
    cout<<"\n使用标准库容器："<<endl;
    vector<test> vmc(7);//最大容量为7
    cout<<"\n创建派生类："<<endl;
    testChild tsc;
    cout<<"\n包含别的类成员的类的创建："<<endl;
    test2 mc2;
}
