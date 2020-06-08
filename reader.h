#pragma once
#include "inc.h"

class reader
{
private:
	std::string ticketNumber = "C0000-00"; //номер чит билета формат А - права доступа, цифры до "-" порядковый номер регистрации, 
	// после год регистрации
	std::string name = "\0";//фамилия
	std::string surname = "\0"; //имя
	std::string patronymic = "\0";  //отчество 
	unsigned int yearBorn = 0; // год рождения
	std::string adress = "\0"; //адрес проживания 
	std::string stateWoStd = "\0"; //место работы или учебы
public:
	reader(const std::string&, const  std::string&, const  std::string&, const  std::string&, const unsigned int&, const  std::string&, const std::string&);
	~reader();

	//гетры
	const std::string getTN() { return this->ticketNumber; } //возвращает номер чит билета
	
	const std::string getSur() { return this->surname; }
	const std::string getName() { return this->name; }
	const std::string getPatr() { return this->patronymic; }

	friend std::ostream& operator<<(std::ostream& os, const reader& myRd);

	
};

