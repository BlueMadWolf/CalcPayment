#ifndef CALC_H
#define CALC_H

#include <vector>


//Оплата за месяц
double payment_for_month;

//Возврат за пропущенную тренировку
double refund_for_missed_training;


//Человек
class human
{
    //Имя
    std::string _name;
    //Фамилия
    std::string _full_name;

    //Количество пропущенных занятий
    int _count_missed;

public:
	human(std::string name, std::string full_name, int count_missed) :
		_name(name), _full_name(full_name), _count_missed(count_missed) {}

	//Сумма к оплате за месяц
	double amount_payable_for_month()
	{
		 return payment_for_month - (refund_for_missed_training * _count_missed);
	}

	//Имя
	std::string name() const { return _name; }

	//Фамилия
	std::string full_name() const { return _full_name; }
};

//месяца
enum Month{Jan, Feb, Mar, Apr, May, Jun, Jul, Aug, Sep, Oct, Nov, Dec};

//Месяц тренировок
class month_of_training
{
	//Название месяца
	Month _month;

	//список людей
	std::vector<human> _humans;
public:
	//конструктор
	month_of_training(Month m = Jan) : _month(m) {}

	//переходит на следующий + i месяц
	void next_month(int i = 0)
	{
		int m = _month + i;
			switch (m)
			{
			case(0):
				_month = Feb;
				break;
			case(1):
				_month = Mar;
				break;
			case(2):
				_month = Apr;
				break;
			case(3):
				_month = May;
				break;
			case(4):
				_month = Jun;
				break;
			case(5):
				_month = Jul;
				break;
			case(6):
				_month = Aug;
				break;
			case(7):
				_month = Sep;
				break;
			case(8):
				_month = Oct;
				break;
			case(9):
				_month = Nov;
				break;
			case(10):
				_month = Dec;
				break;
			case(11):
					_month = Jan;
			}
	}

	//Добавляет человека в список
	void push_human(human h)
	{
		_humans.push_back(h);
	}

	//Сортирует список по фамилиям
	void sort_humans() {}   //Нужно будет реализовать... пока я не успела

	//Печатает ведомость за месяц (нва консоль) 
	void print_statement()
	{
		if (_humans.size() == 0)
			throw std::out_of_range("no humans!"); 
		sort_humans();

		std::cout << "Месяц: "<< _month << std::endl;
		for (human h : _humans)
		{
			std::cout << "Фамилия: " << h.full_name << " | Имя: " << h.name();
			std::cout << " | Оплата за месяц: " << h.amount_payable_for_month() << std::endl;
		}
	}
};



#endif // CALC_H
