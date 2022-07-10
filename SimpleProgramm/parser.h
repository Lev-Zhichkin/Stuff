#pragma once
#include "date.h"
#include "budget_manager.h"
#include <string_view>
#include <tuple>

/*class Parser {

};

class QueryParser {

};

class ModifyParser {

}; */

class Parser {
public:
	Parser(BudgetManager& budget_manager);
	void ParseQuery(std::string_view line_view);

private:
	std::pair<Date, Date> ComputeDates(std::string& line, size_t& space);

private:
	BudgetManager& budget_manager_;
};

