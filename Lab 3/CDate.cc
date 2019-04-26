// ..................................................  
// CDate class definitions
// Adapted from Hagit Schechter, Jan 2007 for 2014W2 
// ..................................................

#include <iostream>
#include <string>
#include "CDate.h"

CDate::CDate(void){
	m_year = m_month = m_day = 0;
}

CDate::CDate(int year, int month, int day){
	setDate( year, month, day );        
}

CDate::CDate(int year, std::string month, int day){
	int month_num = monthStr2Num(month);
     setDate( year, month_num , day );        
}

bool CDate::isValidDate(int year, int month, int day){
     return (year>=1000 && year<=9999) && 
                 isValidDay(year, month, day);
}

bool CDate::isValidDate(int year, std::string month, int day){
     int month_num = monthStr2Num(month);
     return isValidDate(year, month_num, day);
}

int CDate::monthStr2Num(std::string month){
	int ans;
     if (month.compare("January") == 0)
         ans = 1;
     else if (month.compare("February") == 0)
         ans = 2;
     else if (month.compare("March") == 0)
         ans = 3;
     else if (month.compare("April") == 0)
         ans = 4;
     else if (month.compare("May") == 0)
         ans = 5;
     else if (month.compare("June") == 0)
         ans = 6;
     else if (month.compare("July") == 0)
         ans = 7;
     else if (month.compare("August") == 0)
         ans = 8;
     else if (month.compare("September") == 0)
         ans = 9;
     else if (month.compare("October") == 0)
         ans = 10;
     else if (month.compare("November") == 0)
         ans = 11;
     else if (month.compare("December") == 0)
         ans = 12;
     else
         ans = -1;
     return ans;
}

bool CDate::isValidDay(int year, int month, int day){
	if ((day < 1) || (day > 31)) return false;

	bool valid = false;
	switch (month) {
		case 1:
		case 3:
		case 5:
		case 7:
		case 8:
		case 10:
		case 12:
			valid = (day <= 31);
                break;
		case 2:
			// Don't worry about this code too much.
			// It handles all the leap year rules for February.
			if ((year % 4) != 0) {
				valid = (day <=28);
			} else if ((year % 400) == 0) {
				valid = (day <= 29);
			} else if ((year % 100) == 0) {
				valid = (day <= 28);
			} else {
				valid = (day <= 29);
			}
			break;
		case 4:
		case 6:
		case 9:
		case 11:
                valid = (day <= 30);
                break;			
		default:
			valid = false;
			break; 
	}
	return valid;
}

void CDate::setDate(int year, int month, int day){
	if(isValidDate(year, month, day)){    
		m_year = year;
		m_month = month;
		m_day = day;
	}
	else {
		m_year = m_month = m_day = 0;
	}
}


void CDate::setDate(int year, std::string month, int day){
	int month_num = monthStr2Num(month);
      if(isValidDate(year, month_num, day)){    
		m_year = year;
		m_month = month_num;
		m_day = day;
	}
	else {
		m_year = m_month = m_day = 0;
	}

}

void CDate::print(void){
	std::cout << m_year << "/" << m_month << "/" << m_day << std::endl;
}

int CDate::getDate(void){
	return (m_year * 10000) + (m_month * 100) + m_day;
}



