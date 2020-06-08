#pragma once

#include "book.h"
#include "MyList.h"
#include "openHashTable.h"
#include "avl.h"
#include "function.h"

int main()
{
	system("chcp 1251");
	setlocale(LC_ALL, "Russian");
	
	//для читателя фамилия отчество имя
	std::string name = "\0";
	std::string surname = "\0";
	std::string patronymic = "\0";
	
	std::string str1 = "\0"; //для читателя номер билета  --- для книги шифр
	std::string str2 = "\0"; //для книги имя автора // иногда шифр книги
	std::string str3 = "\0"; //адрес проживания  читателя  --- название книги
	std::string str4 = "\0"; //место работы или учебы читателя --- издательство

	unsigned int in1 = 0; // год рождения читателя --- год публикации
	unsigned int in2 = 0; //для книги всего экземпляров  
	unsigned int in3 = 0; //для книги экземпляры в наличии 


	myList hoTakeWhatTake; //список в котором хранятся шифр книг и номер билета 
	AVL<book> bookTree; //АВЛ дерево с книгами
	hashTable readHash; //хеш таблица с читателями 

	int choice = 0;
	int uchce = 0;
	int delShfrTckt = -1;
	bool noExit = true;
	while (noExit)
	{
		system("cls");
		choice = 0;
		std::cout << "1 - Регистрация нового читателя;\n"
			"2 - Снятие с обслуживания читателя\n"
			"3 - Просмотр всех зарегистрированных читателей\n"
			"4 - Очистка данных о читателях\n"
			"5 - Поиск читателя по № читательского билета\n"
			"6 - Поиск читателя по ФИО\n"
			"7 - Добавление новой книги!\n"
			"8 - Удаление сведений о книге\n" 
			"9 - Просмотр всех имеющихся книг\n"
			"10 - Очистка данных о книгах\n"
			"11 - Поиск книги по шифру\n"
			"12 - Поиск книги по фрагментам ФИО автора(ов) или названия\n"
			"13 - Регистрация выдачи экземпляра книги читателю\n"
			"14 - Регистрация приема экземпляра книги от читателя\n"
			"20 - Выход\n";

		std::cin >> choice;

		switch (choice)
		{
		case 1:
		{
			system("cls");
			std::cout << "Регистрация нового читателя:\n\n";
			
			std::cout << "Номер читательского билета: ";
			std::cin >> str1;
			cinClear();
			std::cout << "Фамилия: ";  
			std::cin >> surname;
			cinClear();
			std::cout << "Имя: ";
			std::cin >> name;
			cinClear();
			std::cout << "Отчество: ";
			std::cin >> patronymic;
			cinClear();

			std::cout << "Год рождения: ";
			std::cin >> in1;
			cinClear();
			std::cout << "Адрес проживания: ";
			std::getline(std::cin, str3);
			cinClear();
			std::cout << "Место работы или учебы: ";
			std::getline(std::cin,str4);
			cinClear();
			readHash.add(*(new reader(str1, surname, name, patronymic, in1, str3, str4)));
			
			system("pause");
			break;
		}
		case 2:
		{
			system("cls");
			std::cout << "Снятие с обслуживания читателя:\n\n";
			std::cout << "Номер читательского билета: ";
			std::cin >> str1;
			cinClear();
			
			readHash.remove(str1);
			break;
		}
		case 3:
		{
			system("cls");
			std::cout << "Просмотр всех зарегистрированных читателей\n\n";
			std::cout << readHash;
			system("pause");
			break;
		}
		case 4:
		{
			system("cls");
			std::cout << "Очистка данных о читателях\n\n";
			readHash.сlear();
			break;
		}
		case 5:
		{
			system("cls");
			std::cout << "Поиск читателя по № читательского билета\n\n";

			std::cout << "Номер читательского билета: ";
			std::cin >> str1;
			cinClear();
			if (readHash.searchShf(str1) == false)
			{
				std::cout << "Номер читательского билета не найден!\n";
				system("pause");
				break;
			}
			hoTakeWhatTake.prntBook(str1);
			system("pause");
			break;
		}
		case 6:
		{
			system("cls");
			std::cout << "Поиск читателя по ФИО\n\n";

			std::cout << "Фамилия: ";
			std::cin >> surname;
			cinClear();
			std::cout << "Имя: ";
			std::cin >> name;
			cinClear();
			std::cout << "Отчество: ";
			std::cin >> patronymic;
			cinClear();
			readHash.searchNM(surname, name, patronymic);
			
			system("pause");
			break;
		}
		case 7:
		{
			system("cls");
			std::cout << "Добавление новой книги\n\n";

			std::cout << "Шифр книги: ";
			std::cin >> str1;
			cinClear();
			std::cout << "Фамилия И.О. Автора: ";
			std::getline(std::cin, str2);
			cinClear();
			std::cout << "Название книги: ";
			std::getline(std::cin, str3);
			cinClear();
			std::cout << "Издательство: ";
			std::getline(std::cin, str4);
			cinClear();
			std::cout << "Год публикации: ";
			std::cin >> in1;
			cinClear();
			std::cout << "Всего экземпляров: ";
			std::cin >> in2;
			cinClear();
			std::cout << "Экземпляров в наличии: ";
			std::cin >> in3;
			cinClear();
			bookTree.insert(book(str1, str2, str3, str4, in1, in2, in3));
			system("pause");
			break;
		}
		case 8:
		{
			system("cls");
			std::cout << "Удаление сведений о книге\n\n";


			bookTree.deleteKey(str1);
			break;
		}
		case 9:
		{
			system("cls");
			std::cout << "Просмотр всех имеющихся книг\n";
			bookTree.printBalance();
			system("pause");
			break;
		}
		case 10:
		{
			system("cls");
			std::cout << "Очистка данных о книгах\n\n";

			break;
		}
		case 11:
		{
			system("cls");
			std::cout << "Поиск книги по шифру\n\n";
			
			std::cout << "Введите шифр книги: ";
			std::cin >> str1;
			cinClear();
			bookTree.searchShfr(str1, uchce);
			if (uchce == 3)
			{
				hoTakeWhatTake.readerInfo(str1, readHash);
			}
			system("pause");
			break;
		}
		case 12:
		{
			system("cls");
			std::cout << "Поиск книги по фрагментам ФИО автора(ов) или названия\n\n";
			std::cout << hoTakeWhatTake;
			system("pause");
			break;
		}
		case 13:
		{
			system("cls");
			std::cout << "Регистрация выдачи экземпляра книги читателю\n\n";
			std::cout << "Читательский билет: ";
			std::cin >> str1;
			cinClear();
			std::cout << "Шифр книги: ";
			std::cin >> str2;
			cinClear();
			hoTakeWhatTake.Add(str1 + str2);
			uchce = 1;
			bookTree.retGetBook(str2, uchce);
			break;
		}
		case 14:
		{
			system("cls");
			std::cout << "Регистрация приема экземпляра книги от читателя\n\n";
			std::cout << "Читательский билет: ";
			std::cin >> str1;
			cinClear();
			std::cout << "Шифр книги: ";
			std::cin >> str2;
			cinClear();
			delShfrTckt = hoTakeWhatTake.searchBkTicket(str1, str2);
			if (delShfrTckt == -1)
			{
				break;
			}
			uchce = 2;
			bookTree.retGetBook(str2, uchce);
			system("cls");
			std::cout << "Книга принята!";
			system("pause");
			break;
		}
		case 20:
		{
			noExit = false; 
			system("pause");
			break;
		}
		default:
		{
			system("cls");
			std::cout << "\nНеправильный ввод!\n";
			system("pause");
			break;
		}
		}
	}
	return 0;
}