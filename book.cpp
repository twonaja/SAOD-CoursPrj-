#include "book.h"

book::book(std::string& cphr, const std::string& athr, const std::string& bkNm, const std::string& pblHs,
	const unsigned int& pblYr, const unsigned int& qnttAl, const unsigned int& qnttStck)
{
	while (cphr.length() != 7 && cphr[3] != '.')
	{
		std::cout << "\nВведите шифр повторно (ФОРМАТ - NNN.MMM):" << std::endl;
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
	if (this->cipher == myBook.cipher)
	{
		return true;
	}
	else if(this->cipher != myBook.cipher)
	{
		return false;
	}
}

bool book::operator>=(const book& myBook)
{
	if (this->cipher >= myBook.cipher)
	{
		return true;
	}
	else if (this->cipher >= myBook.cipher)
	{
		return false;
	}
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
	os << "\nШифр книги: " << myBook.cipher
		<< "\nНазвание: " << myBook.bookName
		<< "\nАвтор: " << myBook.author
		<< "\nДоступное количество: " << myBook.quantityStock;
	return os;
}
