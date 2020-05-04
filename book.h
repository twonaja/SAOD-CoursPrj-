#pragma once
#include "inc.h"
class book
{
private:
	std::string cipher = "000.00"; //NNN � ����� ������������� ������� (�����), MMM � ���������� ����� ����� � ������� (�����); 
	std::string author = '\0';
	std::string bookName = '\0';
	std::string publHouse = '\0'; //������������
	unsigned int publyear = 0; // ��� ����������
	unsigned int quantityAll = 0; //���������� �����������
	unsigned int quantityStock = 0; //���������� � �������
public:
	book(std::string&, const std::string&, const std::string&, const std::string&,
		const unsigned int&, const unsigned int&, const unsigned int&);

	const std::string getCipher() { return cipher; }
	const std::string getAuthor() { return author; }
	const std::string getBkNm() { return bookName; }
	const std::string getPblHs() { return publHouse; }
	const unsigned int getQnttAll() { return quantityAll; }
	const unsigned int getQnttStock() { return quantityStock; }
	
	void setQnttStock(const unsigned int qnttStck) { quantityStock = qnttStck; }
	
};

