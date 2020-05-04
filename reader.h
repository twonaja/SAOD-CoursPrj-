#pragma once
#include "inc.h"
class reader
{
private:
	std::string ticketNumber = '\0'; //номер чит билета
	std::string SPN = '\0'; //фамилия отчество имя
	unsigned int yearBorn = 0; //
	std::string adress = '\0';
	std::string stateWoStd = '\0';
public:
	reader(const std::string&, const  std::string&, const unsigned int&, const  std::string&, const std::string&);
	~reader();

	//геттеры
	const std::string getTN() { return this->ticketNumber; }
	const std::string getSPN() { return this->SPN; }

};

