#ifndef EM3_H_INCLUDED
#define EM3_H_INCLUDED
#endif // EM3_H_INCLUDED

class Mobile{
    struct con;
    con* concent;
protected:
    int gn;
public:
    void initialize();
    void set(int j);
    void cleanup();
    void read();

};
