#include <iostream>
using namespace std;

enum Engine_Type
{
	Screw,
	Jet
};
enum Gas_Type
{
	H,
	He
};
class Airship
{
protected:
	int passengers_num;
	int baggage_num;
public:
	Airship(int passengers, int cargo) : passengers_num(passengers), baggage_num(cargo) {}
	// чисто абстрактная функция -> делает класс абстрактным и нельзя создать его объект напрямую
	// при этом наследники должны ее реализовать
    virtual void displayInfo() = 0;
};
class Airplane:public Airship
{
private:
	float flight_distance;
	Engine_Type engine_type;
public:
	//явно вызываем конструктор базового класса, т.к. нет конструктора базового класса по умолчанию, а объект базового должен создаться
	Airplane(int passengers, int cargo, Engine_Type engine, float flightRange)
		: Airship(passengers, cargo), engine_type(engine), flight_distance(flightRange) {}
	void displayInfo() override {

		cout << "Самолет -> Пассажиров: " << passengers_num << ", Груз: " << baggage_num
			<< " кг, Тип двигателя: " << (engine_type == Screw ? "Винтовой" : "Реактивный")
			<< ", Дальность полета: " << flight_distance << " км" << endl;
	}
};
class Balloon:public Airship
{
private:
	Gas_Type gas_type;
	float max_ceil;
public:
	Balloon(int passengers, int cargo, Gas_Type gas, int maxAltitude)
		: Airship(passengers, cargo), gas_type(gas), max_ceil(maxAltitude) {
	}
	void displayInfo() override
		{
		cout << "Дирижабль -> Пассажиров: " << passengers_num << ", Груз: " << baggage_num
			<< " кг, Тип газа: " << (gas_type == H ? "Водород" : "Гелий")
			<< ", Максимальный потолок: " << max_ceil << " м" << endl;
	}
};
void PeopleChoice(Airship *ship)
{
	cout<<"Чeловек выбрал следующий вид транспорта"<<endl;
	ship->displayInfo();
}
int main()
{
	setlocale(LC_ALL, "");
	Airplane airplane(180, 20000, Jet, 15000);
	// Создаем объект дирижабля
	Balloon balloon(10, 500, He, 3000);
	// Выводим информацию о летательных аппаратах
	airplane.displayInfo();
	balloon.displayInfo();
	//создаем объект в куче; указатель базового класса может ссылаться на любой объект-наследник
	Airship* cargo = new Airplane(100, 30000, Screw, 20000);
	PeopleChoice(cargo);
	//освобождаем память в куче
	delete cargo;
	return 0;
}
