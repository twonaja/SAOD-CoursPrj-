#include "book.h"

book::book(std::string& cphr, const std::string& athr, const std::string& bkNm, const std::string& pblHs,
	const unsigned int& pblYr, const unsigned int& qnttAl, const unsigned int& qnttStck)
{
	while (cphr.length() != 7 && cphr[3] != '.')
	{
		std::cout << "Введите шифр повторно (ФОРМАТ - NNN.MMM):" << std::endl;
		std::cin >> cphr;
	}
	cipher = cphr;
	author = athr;
	bookName = bkNm;
	publHouse = pblHs;
	publyear = pblYr;
	quantityAll = qnttAl;
	quantityStock = qnttStck;	
}

bool book::operator>(book& tmp)
{
	if(this->cipher > tmp.cipher)
	{
		return true;
	}
	return false;
}

bool book::operator<(book& tmp)
{
	if (this->cipher < tmp.cipher)
	{
		return true;
	}
	return false;
}
