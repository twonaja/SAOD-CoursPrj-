#include "reader.h"

reader::reader(const std::string& tmpTN, const  std::string& tmpSurname, const  std::string& tmpName, const  std::string& tmpPatr,
	const unsigned int& tmpYB, const std::string& tmpADD, const std::string& tmpSWS)
{
	this->ticketNumber = tmpTN;
	this->surname = tmpSurname;
	this->name = tmpName;
	this->patronymic = tmpPatr;
	this->yearBorn = tmpYB;
	this->adress = tmpADD;
	this->stateWoStd = tmpSWS;
}

reader::~reader()
{
	this->ticketNumber = "\0";
	this->surname = "\0";
	this->name = "\0";
	this->patronymic = "\0";
	this->yearBorn = 0;
	this->adress = "\0";
	this->stateWoStd = "\0";
}

std::ostream& operator<<(std::ostream& os, const reader& myRd)
{
	os << "Номер читательского билета: " << myRd.ticketNumber
		<< "\nФамилия Имя Отчество: " << myRd.surname << " " << myRd.name << " " << myRd.patronymic 
		<< "\nГод рождения: " << myRd.yearBorn
		<< "\nАдрес проживания: " << myRd.adress
		<< "\nМесто работы или учебы: " << myRd.stateWoStd << std::endl;
	return os;
}
