#include "reader.h"

reader::reader(const std::string& tmpTN, const  std::string& tmpSPN, const unsigned int& tmpYB,
	const std::string& tmpADD, const std::string& tmpSWS)
{
	this->ticketNumber = tmpTN;
	this->SPN = tmpSPN;
	this->yearBorn = tmpYB;
	this->adress = tmpADD;
	this->stateWoStd = tmpSWS;
}

reader::~reader()
{
	this->ticketNumber = '\0';
	this->SPN = '\0';
	this->yearBorn = 0;
	this->adress = '\0';
	this->stateWoStd = '\0';
}

std::ostream& operator<<(std::ostream& os, const reader& myRd)
{
	os << "����� ������������� ������: " << myRd.ticketNumber
		<< "\n������� ��� ��������: " << myRd.SPN
		<< "\n��� ��������: " << myRd.yearBorn
		<< "\n����� ����������: " << myRd.adress
		<< "\n����� ������ ��� �����: " << myRd.stateWoStd << std::endl;
	return os;
}
