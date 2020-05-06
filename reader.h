#pragma once
#include "inc.h"
class reader
{
private:
	std::string ticketNumber = "C0000-00"; //номер чит билета формат ј - права доступа, цифры до "-" пор€дковый номер регистрации, 
	// после год регистрации
	std::string SPN = '\0'; //фамили€ отчество им€
	unsigned int yearBorn = 0; //
	std::string adress = '\0';
	std::string stateWoStd = '\0';
	std::list<std::string> bookShfr;
public:
	reader(const std::string&, const  std::string&, const unsigned int&, const  std::string&, const std::string&);
	~reader();

	//гетры
	const std::string getTN() { return this->ticketNumber; } //возвращает номер чит билета
	const std::string getSPN() { return this->SPN; }
	
};

