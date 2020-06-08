#pragma once
#include "inc.h"

class reader
{
private:
	std::string ticketNumber = "C0000-00"; //����� ��� ������ ������ � - ����� �������, ����� �� "-" ���������� ����� �����������, 
	// ����� ��� �����������
	std::string name = "\0";//�������
	std::string surname = "\0"; //���
	std::string patronymic = "\0";  //�������� 
	unsigned int yearBorn = 0; // ��� ��������
	std::string adress = "\0"; //����� ���������� 
	std::string stateWoStd = "\0"; //����� ������ ��� �����
public:
	reader(const std::string&, const  std::string&, const  std::string&, const  std::string&, const unsigned int&, const  std::string&, const std::string&);
	~reader();

	//�����
	const std::string getTN() { return this->ticketNumber; } //���������� ����� ��� ������
	
	const std::string getSur() { return this->surname; }
	const std::string getName() { return this->name; }
	const std::string getPatr() { return this->patronymic; }

	friend std::ostream& operator<<(std::ostream& os, const reader& myRd);

	
};

