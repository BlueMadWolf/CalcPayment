#ifndef CALC_H
#define CALC_H

#include <vector>

//Оплата за месяц
double payment_for_month;

//Возврат за пропущенную тренировку
double refund_for_missed_training;


//Человек
struct human
{
    //Имя
    std::string name;
    //Фамилия
    std::string full_name;

    //Количество пропущенных занятий
    int count_missed;

	//Сумма к оплате за месяц
	double amount_payable_for_month()
	{
		return payment_for_month - (refund_for_missed_training * count_missed);
	}
};

//Месяц тренировок
struct month_of_training
{
    std::vector<human> humans;
	
};



#endif // CALC_H
