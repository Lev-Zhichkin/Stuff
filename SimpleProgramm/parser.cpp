#include "parser.h"

Parser::Parser(BudgetManager& budget_manager)
	: budget_manager_(budget_manager)
{
}

void Parser::ParseQuery(std::string_view line_view) {
	std::string line(line_view);
	size_t space = line.find(' ');
	std::string func_name = line.substr(0, space);
	if (func_name == "Earn") {
		std::pair<Date, Date> dates = ComputeDates(line, space);
		line = line.substr(++space);
		double income = stod(line);
		budget_manager_.Earn(dates.first, dates.second, income);

	}
	else if (func_name == "ComputeIncome") {
		std::pair<Date, Date> dates = ComputeDates(line, space);
		budget_manager_.ComputeIncome(dates.first, dates.second);
	}
	else if (func_name == "PayTax") {
		std::pair<Date, Date> dates = ComputeDates(line, space);
		line = line.substr(++space);
		int rate = stoi(line);
		budget_manager_.PayTax(dates.first, dates.second, rate);
	}
	else if (func_name == "Spend") {
		std::pair<Date, Date> dates = ComputeDates(line, space);
		line = line.substr(++space);
		double amount = stod(line);
		budget_manager_.Spend(dates.first, dates.second, amount);
	}
}

std::pair<Date, Date> Parser::ComputeDates(std::string& line, size_t& space) {
	line = line.substr(++space);
	space = line.find(' ');
	std::string data_from = line.substr(0, space);
	Date from = Date().FromString(data_from);
	line = line.substr(++space);
	space = line.find(' ');
	std::string data_to = line.substr(0, space);
	Date to = Date().FromString(data_to);

	return { std::move(from), std::move(to) };
}
