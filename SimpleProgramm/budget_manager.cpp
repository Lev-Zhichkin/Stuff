#include "budget_manager.h"

void BudgetManager::ComputeIncome(Date from, Date to) {
    int to_index = Date().ComputeDistance(START_DATE, to);
    if (to_index >= days_.size()) {
        days_.resize(to_index + 1);
    }
    int from_index = Date().ComputeDistance(START_DATE, from);

    double total_income = 0;
    for (int i = from_index; i != (to_index + 1); ++i) {
        total_income += (days_[i].cash_ - days_[i].spent_);
    }
    std::cout << total_income << std::endl;
}

void BudgetManager::Earn(Date from, Date to, double income) {
    int to_index = Date().ComputeDistance(START_DATE, to);
    if (to_index >= days_.size()) {
        days_.resize(to_index + 1);
    }
    double from_to = Date().ComputeDistance(from, to);
    int from_index = to_index - from_to;
    double middle_income = income / (from_to + 1.);

    for (int i = from_index; i != (to_index + 1); ++i) {
        days_[i].cash_ += middle_income;
    }
}

void BudgetManager::PayTax(Date from, Date to, int rate) {
    int to_index = Date().ComputeDistance(START_DATE, to);
    if (to_index >= days_.size()) {
        days_.resize(to_index + 1);
    }
    int from_index = Date().ComputeDistance(START_DATE, from);

    for (int i = from_index; i != (to_index + 1); ++i) {
        if (days_[i].cash_ > 0) {
            days_[i].cash_ *= ((100. - static_cast<double>(rate)) / 100.);
        }
    }
}

void BudgetManager::Spend(Date from, Date to, double amount) {
    int to_index = Date().ComputeDistance(START_DATE, to);
    if (to_index >= days_.size()) {
        days_.resize(to_index + 1);
    }
    double from_to = Date().ComputeDistance(from, to);
    int from_index = to_index - from_to;
    double middle_amount = amount / (from_to + 1.);

    for (int i = from_index; i != (to_index + 1); ++i) {
        days_[i].spent_ += middle_amount;
    }
}