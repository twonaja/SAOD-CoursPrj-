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

void book::minusBook()
{
	if ((this->quantityStock != 0) && ((this->quantityStock - 1) > 0))
	{
		this->quantityStock--;
	}
}

void book::plusBook()
{
	if (this->getQnttAll() >= (1 + this->getQnttStock() ))
	{
		this->quantityStock++;
	}
}

bool book::operator==(const book& myBook)
{
	if (this->bookName == myBook.bookName && this->cipher == myBook.cipher);
	{
		return true;
	}
	
	return false;
}

bool book::operator==(std::string& cphr)
{
	if (this->cipher == cphr)
	{
		return true;
	}
	return false;
}

bool book::operator>=(std::string& cphr)
{
	if (this->cipher >= cphr)
	{
		return true;
	}
	return false;
}

std::ostream& operator<<(std::ostream& os, const book& myBook)
{
	os << "Шифр книги: " << myBook.cipher
		<< "Название: " << myBook.bookName
		<< "Автор: " << myBook.author
		<< "Доступное количество: " << myBook.quantityStock;
	return os;
}
