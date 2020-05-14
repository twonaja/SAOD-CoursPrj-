#include "avl.h"
#include "book.h"
#include "MyList.h"
#include "openHashTable.h"
#include "avl.h"


int main()
{
	setlocale(LC_ALL, "Russian");

	std::string str1 = "\0"; //для читателя номер билета  ---
	std::string str2 = "\0"; //для читателя фамилия отчество имя --- 
	std::string str3 = "\0"; //адрес проживания  читателя  ---
	std::string str4 = "\0"; //место работы или учебы читателя ---

	unsigned int in1 = 0; // год рождения читателя ---
	unsigned int in2 = 0;
	unsigned int in3 = 0;


	myList hoTakeWhatTake; //список в котором хранятся шифр книг и номер билета 
	AVL<book> bookTree; //АВЛ дерево с книгами
	hashTable readHash; //хеш таблица с читателями 

	int choice = 0;


	bool noExit = true;
	while (noExit)
	{
		system("cls");

		std::cout << "1 - Регистрация нового читателя;\n"
			"2 - Снятие с обслуживания читателя\n"
			"3 - Просмотр всех зарегистрированных читателей\n"
			"4 - Очистка данных о читателях\n"
			"5 - Поиск читателя по № читательского билета\n"
			"6 - Поиск читателя по ФИО\n"
			"7 - Добавление новой книги!\n"
			"8 - Очистка данных о книгах\n"
			"9 - Поиск книги по шифру\n"
			"10 - Поиск книги по фрагментам ФИО автора(ов) или названия\n"
			"11 - Регистрация выдачи экземпляра книги читателю\n"
			"12 - Регистрация приема экземпляра книги от читателя\n";

		std::cin >> choice;

		switch (choice)
		{
		case 1:
		{
			system("cls");
			std::cout << "Регистрация нового читателя:\n";
			std::cout << "Номер читательского билета: ";
			std::cin >> str1;
			std::cout << "\nФамилия Имя Отчество: ";
			std::getline(std::cin, str2);
			std::cout << "\nГод рождения: ";
			std::cin >> in1;
			std::cout << "\nАдрес проживания: ";
			std::getline(std::cin, str3);
			std::cout << "\nМесто работы или учебы: ";
			std::getline(std::cin,str4);

			readHash.add(*(new reader(str1, str2, in1, str3, str4)));
			
			system("pause");
			break;
		}
		case 2:
		{
			system("cls");
			std::cout << "Снятие с обслуживания читателя:\n";

			break;
		}
		case 3:
		{
			system("cls");
			std::cout << "Просмотр всех зарегистрированных читателей\n";

			break;
		}
		case 4:
		{
			system("cls");
			std::cout << "Очистка данных о читателях\n";
			break;
		}
		case 5:
		{
			system("cls");
			std::cout << "Поиск читателя по № читательского билета\n";

			break;
		}
		case 6:
		{
			system("cls");
			std::cout << "Поиск читателя по ФИО\n";

			break;
		}
		case 7:
		{
			system("cls");
			std::cout << "Добавление новой книги!\n";
			break;
		}
		case 8:
		{
			system("cls");
			std::cout << "Очистка данных о книгах\n";
			break;
		}
		case 9:
		{
			system("cls");
			std::cout << "Поиск книги по шифру\n";

			break;
		}
		case 10:
		{
			system("cls");
			std::cout << "Поиск книги по фрагментам ФИО автора(ов) или названия";
			break;
		}
		case 11:
		{
			system("cls");
			std::cout << "Регистрация выдачи экземпляра книги читателю\n";
			break;
		}
		case 12:
		{
			system("cls");
			std::cout << "Регистрация приема экземпляра книги от читателя\n";
			break;
		}
		default:
		{
			system("cls");
			std::cout << "\nInvalid input, please repeat one more time!\n";
			system("pause");
			break;
		}
		}
	}
	return 0;
}