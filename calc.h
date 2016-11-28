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
	Month _name;

	//список людей
	std::vector<human> _humans;
public:
	//конструктор
	month_of_training(Month name = Jan) : _name(name) {}


};



#endif // CALC_H
