// с++22.cpp : Этот файл содержит функцию "main". Здесь начинается и заканчивается выполнение программы.
//

#include "pch.h"
#include <iostream>
#include <math.h>
#include <conio.h>
#define M_PI       3.14159
#pragma pack()

using namespace std;

class Angle
{
private:
	int _gradusy, _minute;
	double _radian;

public:



	void Init()
	{
		_gradusy = 0;
		_minute = 0;
		_radian = 0;
	}

	/*Angle(int gradusy, int minute)
		: _gradusy(gradusy), _minute(minute) {}

	Angle()
		: _gradusy(0), _minute(0) {}

	~Angle() {}*/

	int getGradusy() { return _gradusy; }
	int getMinute() { return _minute; }

	void removeRoughs()
	{
		_minute += _gradusy * 60;
		_gradusy = _minute / 60;
		_minute = _minute % 60;
	}

	void setAngle()
	{
		cout << "Градусов = ";
		cin >> _gradusy;
		cout << "Минут = ";
		cin >> _minute;
		this->removeRoughs();
	}

	void increaseAngle()
	{
		Angle a;
		a.setAngle();
		_gradusy += a.getGradusy();
		_minute += a.getMinute();
		this->removeRoughs();
	}

	void decreaseAngle()
	{
		Angle a;
		a.setAngle();
		_gradusy -= a.getGradusy();
		_minute -= a.getMinute();
		this->removeRoughs();
	}

	double getRadians()
	{
		_radian = (_gradusy + _minute / 60.)*M_PI / 180.;
		return _radian;
	}

	void intoRange()
	{
		if (_minute < 0)
		{
			_gradusy--;
			_minute += 60;
		}
		if (_gradusy > 0)_gradusy = _gradusy % 360;
		else _gradusy = _gradusy % 360 + 360;
	}

	double sinA()
	{
		return sin(this->getRadians());
	}

	void Display()
	{
		cout<<"Значение угла:\n "<<"\nГрадусов = " << _gradusy << "\nМинут = " << _minute << "\n";
	}

	friend int angleCmp(Angle &a1, Angle &a2)
	{
		int m1 = a1.getMinute() + a1.getGradusy() * 60;
		int m2 = a2.getMinute() + a2.getGradusy() * 60;
		if (m1 < m2) return -1;
		else if (m1 > m2) return 1;
		else return 0;
	}
};


int main()
{
	setlocale(LC_ALL, "Russian");
	Angle d1;
	Angle d2;
	d1.Init();
	d2.Init();

	cout << "Введите значения для первого угла\n";
	d1.setAngle();
	d1.Display();
	cout << "Введите значения для второго угла\n";
	d2.setAngle();
	d2.Display();
	
	
	
	
	/*//инициализируем и выводим для проверуи на экран угол d1
	Angle d1;
	d1.Init();
	cout << "Первоначальное значение для угла d1:";
	d1.Display();

	//инициализируем и выводим для проверуи на экран угол d2
	Angle d2;
	d2.Init();
	cout << "\nПервоначальное значение для d2:";
	d2.Display();

	// изменение объекта, метод setAngle()
	cout << "------------------------------------------";
	cout << "\nВведите новое значение для угла d1\n";
	d1.setAngle();
	cout << "\nугол d1 стал равен \nГрадусов = " << d1.getGradusy() << "\nМинут = " << d1.getMinute() << "\n";

	// изменение объекта, метод setAngle()
	cout << "\nВведите новое значение для угла d2\n";
	d2.setAngle();
	cout << "\nугол d2 стал равен \nГрадусов =  " << d2.getGradusy() << "\nМинут = " << d2.getMinute() << "\n";

	//увеличения угла на заданную величину, метод increaseAngle()
	cout << "------------------------------------------";
	cout << "\nДобавить значение в угол d1\n";
	d1.increaseAngle();
	cout << "\nугол d1 стал равен \nГрадусов = " << d1.getGradusy() << "\nМинут = " << d1.getMinute() << "\n";

	// уменьшение угла на заданную величину, метод decreaseAngle()
	cout << "\nМинус значение для угла d1\n";
	d1.decreaseAngle();
	cout << "\nугол d1 стал равен \nГрадусов = " << d1.getGradusy() << "\nМинут = " << d1.getMinute() << "\n";

	//перевод в радианы, метод getRadians()

	cout << "\n угол d1 в радианах = " << d1.getRadians();
	cout << "\n угол d2 в радианах = " << d2.getRadians();

	//приведение к диапазону 0-360, метод intoRange()
	cout << "\n------------------------------------------";
	cout << "\nПриведение угла d3 к диапазону <0 - 360>\n";
	Angle d3;
	d3.setAngle();
	d3.intoRange();
	cout << "\nугол d3 в диапазоне <0-360>  " << "\nГрадусов = " << d3.getGradusy() << "\nМинут = " << d3.getMinute() << "\n";

	//синус, метод sinA()
	cout << "\n------------------------------------------";
	cout << "\nСинусы для углов d1, d2, d3\n";
	cout << "синус угла d1 = " << d1.sinA() << "\n";
	cout << "синус угла d2 = " << d2.sinA() << "\n";
	cout << "синус угла d3 = " << d3.sinA() << "\n";

	// сравнение углов d1 и d2
	cout << "\n------------------------------------------";
	cout << "\nСравнение углов d1 и d2\n";
	cout << "угол d1 \nГрадусов = " << d1.getGradusy() << " Минут = " << d1.getMinute() << "\n";
	cout << "угол d2 \nГрадусов = " << d2.getGradusy() << " Минут = " << d2.getMinute() << "\n";
	int res = angleCmp(d1, d2);
	if (res == -1) cout << "d1 < d2\n";
	else if (res == 1) cout << "d1 > d2\n";
	else cout << "d1 = d2\n";

	cin.get();
	_getch();*/
	return 0;
}