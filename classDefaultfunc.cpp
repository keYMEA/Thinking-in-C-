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
    cout<<"����Ĭ�Ϲ��캯�����õĲ���:"<<endl;
    cout<<"\nδ��ʾ���ù��캯����"<<endl;
    test ts;
    cout<<"\n��ʾ���ù��캯����"<<endl;
    test *mcptr = new test;
    //��MyClass *mcptr = new MyClass();
    cout<<"\n��̬�������飺"<<endl;
    test tsArrayStatic[5];
    cout<<"\n��̬�������飺"<<endl;
    test *tsArrayDynamic = new tsArrayDynamic[6];
    cout<<"\nʹ�ñ�׼��������"<<endl;
    vector<test> vmc(7);//�������Ϊ7
    cout<<"\n���������ࣺ"<<endl;
    testChild tsc;
    cout<<"\n����������Ա����Ĵ�����"<<endl;
    test2 mc2;
}
