#pragma once
#include "inc.h"
class reader
{
private:
	std::string ticketNumber = "C0000-00"; //����� ��� ������ ������ � - ����� �������, ����� �� "-" ���������� ����� �����������, 
	// ����� ��� �����������
	std::string SPN = '\0'; //������� �������� ���
	unsigned int yearBorn = 0; //
	std::string adress = '\0';
	std::string stateWoStd = '\0';
	std::list<std::string> bookShfr;
public:
	reader(const std::string&, const  std::string&, const unsigned int&, const  std::string&, const std::string&);
	~reader();

	//�����
	const std::string getTN() { return this->ticketNumber; } //���������� ����� ��� ������
	const std::string getSPN() { return this->SPN; }
	
};

