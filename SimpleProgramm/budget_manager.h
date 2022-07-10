#pragma once
#include "date.h"
#include <vector>
#include <numeric>
#include <algorithm>
#include <iostream>

struct Day {
    double cash_ = 0;
    double spent_ = 0;
};

class BudgetManager {
public:
    inline static const Date START_DATE{ 2000, 1, 1 };
    inline static const Date END_DATE{ 2100, 1, 1 };

    void ComputeIncome(Date from, Date to);
    void Earn(Date from, Date to, double income);
    void PayTax(Date from, Date to, int rate);
    void Spend(Date from, Date to, double amount);

private:
    std::vector<Day> days_;
};
