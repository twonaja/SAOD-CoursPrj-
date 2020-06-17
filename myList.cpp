#include "myList.h"

myList::~myList()
{
	while (size != 0)                        //Пока размерность списка не станет нулевой
	{
		Node* temp = Head->Next;
		delete Head;                           //Освобождаем память от активного элемента
		Head = temp;                           //Смена адреса начала на адрес следующего элемента
		size--;                                //Один элемент освобожден. корректируем число элементов
	}
}

int myList::Count()
{
	return size;                             //Возвращаем число элементов списка
}

void myList::Add(std::string x)
{
	size++;                                    //При каждом добавлении элемента увеличиваем число элементов в списке
	Node* temp = new Node;
	temp->Next = Head;                         //Замыкание контура. Последний элемент - это начало списка
	temp->str = x;                               //Записываем в выделенную ячейку памяти значение x

	if (Head != NULL)                       //В том случае если список не пустой
	{
		Tail->Next = temp;                    //Запись данных в следующее за последним элементом поле
		Tail = temp;                          //Последний активный элемент=только что созданный.
	}
	else
	{
		Head = Tail = temp;	//Если список пуст то создается первый элемент.
	}
	this->Sort();
}

void myList::Remove(int num)
{
	if (num <= size && num > 0)
	{
		if (num == 1)
		{
			Node* temp = Head->Next;
			Head->Next = nullptr;
			Head->str = "\0";
			delete Head;
			Head = temp;
		}
		else if (num > 1 && num < size)
		{
			Node* temp = Head;
			Node* temp2 = temp->Next;
			for (size_t i = 0; i < (num - 2); i++)
			{
				temp = temp->Next;
				temp2 = temp2->Next;
			}
			temp->Next = temp2->Next;
			temp2->Next = nullptr;
			temp2->str = "\0";
			delete temp2;
		}
		else if (num == size)
		{
			Node* temp = Head;
			for (size_t i = 0; i < (num - 2); i++)
			{
				temp = temp->Next;
			}
			Tail->Next = nullptr;
			Tail->str = "\0";
			delete Tail;
			Tail = temp;
			Tail->Next = Head;
		}
	}
	size--;
}

void myList::Sort()
{
	if (size > 1)
	{

		static int plc1 = 0;
		static int plc2 = 0;
		static int plc3 = 0;
		static int plc4 = 0;
		static int plc5 = 0;


		int counter[5];

		for (size_t i = 0; i < 5; i++)
		{
			counter[i] = 0;
		}
		myList::Node* temp = this->Head;
		for (size_t i = 0; i < size; i++)
		{
			if (temp->str.substr(8, 3) == "001")
			{
				counter[0] = counter[0] + 1;
			}
			else if (temp->str.substr(8, 3) == "002")
			{
				counter[1] = counter[1] + 1;
			}
			else if (temp->str.substr(8, 3) == "003")
			{
				counter[2] = counter[2] + 1;
			}
			else if (temp->str.substr(8, 3) == "004")
			{
				counter[3] = counter[3] + 1;
			}
			else if (temp->str.substr(8, 3) == "005")
			{
				counter[4] = counter[4] + 1;
			}
			temp = temp->Next;
		}
		temp = this->Head;
		std::string* str1 = new std::string[counter[0]];
		std::string* str2 = new std::string[counter[1]];
		std::string* str3 = new std::string[counter[2]];
		std::string* str4 = new std::string[counter[3]];
		std::string* str5 = new std::string[counter[4]];


		for (size_t i = 0; i < size; i++)
		{
			if (temp->str.substr(8, 3) == "001")
			{
				str1[plc1] = temp->str;
				plc1++;
			}
			else if (temp->str.substr(8, 3) == "002")
			{
				str2[plc2] = temp->str;
				plc2++;
			}
			else if (temp->str.substr(8, 3) == "003")
			{
				str3[plc3] = temp->str;
				plc3++;
			}
			else if (temp->str.substr(8, 3) == "004")
			{
				str4[plc4] = temp->str;
				plc4++;
			}
			else if (temp->str.substr(8, 3) == "005")
			{
				str5[plc5] = temp->str;
				plc5++;
			}
			temp = temp->Next;
		}
		temp = this->Head;
		for (size_t i = 0; i < counter[0]; i++)
		{
			temp->str = str1[i];
			temp = temp->Next;
		}
		for (size_t i = 0; i < counter[1]; i++)
		{
			temp->str = str2[i];
			temp = temp->Next;
		}
		for (size_t i = 0; i < counter[2]; i++)
		{
			temp->str = str3[i];
			temp = temp->Next;
		}
		for (size_t i = 0; i < counter[3]; i++)
		{
			temp->str = str4[i];
			temp = temp->Next;
		}
		for (size_t i = 0; i < counter[4]; i++)
		{
			temp->str = str5[i];
			temp = temp->Next;
		}
		delete[] str1;
		delete[] str2;
		delete[] str3;
		delete[] str4;
		delete[] str5;

	}
}

void myList::prntBook(std::string tckt)
{
	myList::Node* temp = this->Head;
	for (int i = 0; i < this->size; i++)
	{
		if ((temp->str.substr(0, 8) == tckt))
		{
			std::cout << i + 1 << ") шифр книги: " << temp->str.substr(8) << std::endl;
		}
		temp = temp->Next;
	}
}

void myList::readerInfo(std::string& book, hashTable& reader)
{
	myList::Node* temp = this->Head;
	for (int i = 0; i < this->size; i++)
	{
		if ((temp->str.substr(8) == book))
		{
			std::cout << i + 1 << ") Читательский билет: " << temp->str.substr(8) << std::endl;
			reader.searchShf(temp->str.substr(0, 8));
		}
		temp = temp->Next;
	}
}


int myList::searchBkTicket(std::string tckt, std::string bk)
{
	myList::Node* temp = this->Head;
	for (int i = 0; i < this->size; i++)
	{
		if ((temp->str.substr(0,8) == tckt) && (temp->str.substr(8) == bk))
		{
			return i + 1;
		}
		temp = temp->Next;
	}
	return -1;
}

std::ostream& operator<<(std::ostream& os, const myList& lst)
{
	myList::Node* temp = lst.Head;
	for (size_t i = 0; i < lst.size; i++)
	{
		os << i + 1 << "\nЧитательский билет: " << temp->str.substr(0,8) << std::endl
			<<"Шифр книги: " << temp->str.substr(8) << std::endl;
		temp = temp->Next;
	}
	return os;
}
