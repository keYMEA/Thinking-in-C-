#ifndef MESSAGE_H_INCLUDED
#define MESSAGE_H_INCLUDED
class message{
public:
    message(char* msg=" ");
    void print();
    void print(char* str);
private:
    char *name;
};


#endif // MESSAGE_H_INCLUDED
