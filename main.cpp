#include "avl.h"
#include "book.h"
#include "MyList.h"
#include "openHashTable.h"
#include "avl.h"


int main()
{
	setlocale(LC_ALL, "Russian");

	std::string str1 = "\0"; //для читателя номер билета  --- для книги шифр
	std::string str2 = "\0"; //для читателя фамилия отчество имя --- для книги имя автора // иногда шифр книги
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
			std::cout << "Номер читательского билета: ";
			std::cin >> str1;
			std::cout << "\nФамилия Имя Отчество: ";
			std::getline(std::cin, str2);
			readHash.remove(str1, str2);
			break;
		}
		case 3:
		{
			system("cls");
			std::cout << "Просмотр всех зарегистрированных читателей\n";
			std::cout << readHash;
			system("pause");
			break;
		}
		case 4:
		{
			system("cls");
			std::cout << "Очистка данных о читателях\n";
			readHash.сlear();
			break;
		}
		case 5:
		{
			system("cls");
			std::cout << "Поиск читателя по № читательского билета\n";

			std::cout << "Номер читательского билета: ";
			std::cin >> str1;
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
			std::cout << "Поиск читателя по ФИО\n";

			std::cout << "\nФамилия Имя Отчество: ";
			std::getline(std::cin, str2);
			readHash.searchNM(str2);
			break;
		}
		case 7:
		{
			system("cls");
			std::cout << "Добавление новой книги\n";

			std::cout << "Шифр книги: ";
			std::cin >> str1;
			std::cout << "\nФамилия И.О. Автора: ";
			std::getline(std::cin, str2);
			std::cout << "\nНазвание книги: ";
			std::getline(std::cin, str3);
			std::cout << "\nИздательство: ";
			std::getline(std::cin, str4);
			
			std::cout << "\nГод публикации: ";
			std::cin >> in1;
			std::cout << "\nВсего экземпляров: ";
			std::cin >> in2;
			std::cout << "\nЭкземпляров в наличии: ";
			std::cin >> in3;
			bookTree.insert(book(str1, str2, str3, str4, in1, in2, in3));
			break;
		}
		case 8:
		{
			system("cls");
			std::cout << "Удаление сведений о книге\n";


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
			std::cout << "Очистка данных о книгах\n";

			break;
		}
		case 11:
		{
			system("cls");
			std::cout << "Поиск книги по шифру\n";
			bookTree.searchShfr(str1, uchce);
			break;
		}
		case 12:
		{
			system("cls");
			std::cout << "Поиск книги по фрагментам ФИО автора(ов) или названия";
			break;
		}
		case 13:
		{
			system("cls");
			std::cout << "Регистрация выдачи экземпляра книги читателю\n";
			std::cout << "Читательский билет: ";
			std::cin >> str1;
			std::cout << "Шифр книги: ";
			std::cin >> str2;
			hoTakeWhatTake.Add(str1 + str2);
			uchce = 1;
			bookTree.retGetBook(str2, uchce);
			break;
		}
		case 14:
		{
			system("cls");
			std::cout << "Регистрация приема экземпляра книги от читателя\n";
			std::cout << "Читательский билет: ";
			std::cin >> str1;
			std::cout << "Шифр книги: ";
			std::cin >> str2;
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