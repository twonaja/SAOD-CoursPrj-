#pragma once
#include "inc.h"
class book
{
private:
	std::string cipher = "000.000"; //NNN Ц номер тематического раздела (цифры), MMM Ц пор€дковый номер книги в разделе (цифры); 
	std::string author = "\0";
	std::string bookName = "\0";
	std::string publHouse = "\0"; //издательство
	unsigned int publyear = 0; // год публикации
	unsigned int quantityAll = 0; //количество экземпл€ров
	unsigned int quantityStock = 0; //количество в наличие
public:
	book() = default;
	~book() = default;
	
	book(std::string&, const std::string&, const std::string&, const std::string&,
		const unsigned int&, const unsigned int&, const unsigned int&);
	bool operator >(book& tmp);
	bool operator <(book& tmp);
	
	const std::string getCipher() { return cipher; }
	const std::string getAuthor() { return author; }
	const std::string getBkNm() { return bookName; }
	const std::string getPblHs() { return publHouse; }
	unsigned int getQnttAll() { return quantityAll; }
	unsigned int getQnttStock() { return quantityStock; }
	void minusBook();
	void plusBook();
	friend std::ostream& operator<<(std::ostream& os, const book& myBook);
	bool operator==(const book& myBook);
	bool operator>=(const book& myBook);
	bool operator==(std::string& cphr);
	bool operator>=(std::string& cphr);

	void setQnttStock(const unsigned int qnttStck) { quantityStock = qnttStck; }
};

