#include <iostream>
using namespace std;

class A
{
    int i;
    char c;
    char v[10];
public:
    A(int ni = 0, char nc = '*') { cout << "Конструктор класса A " << endl; i = ni; c = nc; }
    ~A() { cout << "Деструктор класса A " << endl; }
};
class B1 :public virtual A
{
    double j;
public:
    B1(double nj = 0.00) { cout << "Конструктор класса B1 " << endl; j = nj; }
    ~B1() { cout << "Деструктор класса B1 " << endl; }

};
class B2 :public virtual A
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
    setlocale(LC_ALL, "ru");
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
//Когда используется виртуальное наследование, компилятор добавляет в объект указатель (обычно называют vptr — virtual pointer), который указывает на таблицу виртуального базового класса (vtable). 
// Эта таблица помогает следить за тем, чтобы был доступен только один экземпляр данных базового класса, даже если есть несколько путей наследования.

//Эти дополнительные указатели и таблицы увеличивают размер каждого объекта, использующего виртуальное наследование.Кроме того, если класс 
// содержит несколько виртуальных базовых классов,то потребуется несколько указателей, что ещё сильнее увеличивает память