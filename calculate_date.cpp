#include "calculate_date.h"
#include <iostream>
#include <ctime>

namespace Calculate_Date {

	calculateDate::calculateDate(std::string date){

		std::string day = date.substr(0, 2);

		std::string month = date.substr(3, 2);

		std::string year = date.substr(6, 4);


		day_ = std::stoi(day);
		month_ = std::stoi(month);
		year_ = std::stoi(year);
	}

	calculateDate::~calculateDate() {

		return;
	}

    

    // This function counts number of
    // leap years before the given date
    int countLeapYears(int y, int m)
    {
        int years = y;

        // Check if the current year needs to be
        //  considered for the count of leap years
        // or not
        if (m <= 2)
            years--;

        // An year is a leap year if it
        // is a multiple of 4,
        // multiple of 400 and not a
         // multiple of 100.
        return years / 4
            - years / 100
            + years / 400;
    }

    // This function returns number of
    // days between two given dates
    int getDifference(int y1, int m1, int d1, int y2, int m2, int d2)
    {
        const int monthDays[12] = { 31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31 };
        // COUNT TOTAL NUMBER OF DAYS
        // BEFORE FIRST DATE 'dt1'

        // initialize count using years and day
        long int n1 = y1 * 365 + d1;

        // Add days for months in given date
        for (int i = 0; i < m1 - 1; i++)
            n1 += monthDays[i];

        // Since every leap year is of 366 days,
        // Add a day for every leap year
        n1 += countLeapYears(y1, m1);

        // SIMILARLY, COUNT TOTAL NUMBER OF
        // DAYS BEFORE 'dt2'

        long int n2 = y2 * 365 + d2;
        for (int i = 0; i < m2 - 1; i++)
            n2 += monthDays[i];
        n2 += countLeapYears(y2, m2);

        // return difference between two counts
        return (n2 - n1);
    }

	void calculateDate::dateBetween(int &different) {

		time_t t = time(0);
		struct tm* timeStruct = localtime(&t);

		int year = timeStruct->tm_year+1900;
		int month = timeStruct->tm_mon+1;
		int day = timeStruct->tm_mday;

        different = getDifference(year_, month_, day_, year, month, day);

	}
}
