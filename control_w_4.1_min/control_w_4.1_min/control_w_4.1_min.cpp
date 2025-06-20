#include <iostream>
using namespace std;

class A
{
    int i;
    char c;
    char v[10];
public:
    A(int ni = 0, char nc = '*') { cout << "Конструктор класса A " << endl; i = ni; c = nc; }
    ~A() { cout << "Деструктор класса A " << endl ; }
};
class B1:public A
{
double j;
public:
    B1(double nj = 0.00){ cout << "Конструктор класса B1 " << endl; j = nj;}
    ~B1() { cout << "Деструктор класса B1 " << endl; }

};
class B2 :public A
{
    float f;
public:
    B2(float nf = 0.0) { cout << "Конструктор класса B2 " << endl; f = nf; }
    ~B2() { cout << "Деструктор класса B2 " << endl; }

};
class C :public B1, public B2
{
    long int li;
public:
    C(long int nli = 0) { cout << "Конструктор класса C " << endl; nli = li; }
    ~C() { cout << "Деструктор класса C " << endl; }

};
int main()
{
    setlocale(LC_ALL,"ru");
    A a;
    cout << sizeof(a) << endl;
    B1 b1;
    cout << sizeof(b1) << endl;
    B2 b2;
    cout << sizeof(b2) << endl;
    C c;
    cout << sizeof(c) << endl;

    return  0;
}