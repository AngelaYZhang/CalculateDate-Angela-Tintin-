#pragma once
#include <string>
#include <iostream>
#include <ctime>

namespace Calculate_Date {

	class calculateDate {

	public:

		calculateDate(std::string date);
		virtual ~calculateDate();

		void dateBetween(int &different);
	
	private:

		int year_ = 0;
		int month_ = 0;
		int day_ = 0;

	};
}