#include "avl.h"
#include "book.h"
#include "MyList.h"
#include "openHashTable.h"
#include "avl.h"


int main()
{
	setlocale(LC_ALL, "Russian");

	std::string str1 = "\0"; //��� �������� ����� ������  ---
	std::string str2 = "\0"; //��� �������� ������� �������� ��� --- 
	std::string str3 = "\0"; //����� ����������  ��������  ---
	std::string str4 = "\0"; //����� ������ ��� ����� �������� ---

	unsigned int in1 = 0; // ��� �������� �������� ---
	unsigned int in2 = 0;
	unsigned int in3 = 0;


	myList hoTakeWhatTake; //������ � ������� �������� ���� ���� � ����� ������ 
	AVL<book> bookTree; //��� ������ � �������
	hashTable readHash; //��� ������� � ���������� 

	int choice = 0;


	bool noExit = true;
	while (noExit)
	{
		system("cls");

		std::cout << "1 - ����������� ������ ��������;\n"
			"2 - ������ � ������������ ��������\n"
			"3 - �������� ���� ������������������ ���������\n"
			"4 - ������� ������ � ���������\n"
			"5 - ����� �������� �� � ������������� ������\n"
			"6 - ����� �������� �� ���\n"
			"7 - ���������� ����� �����!\n"
			"8 - ������� ������ � ������\n"
			"9 - ����� ����� �� �����\n"
			"10 - ����� ����� �� ���������� ��� ������(��) ��� ��������\n"
			"11 - ����������� ������ ���������� ����� ��������\n"
			"12 - ����������� ������ ���������� ����� �� ��������\n";

		std::cin >> choice;

		switch (choice)
		{
		case 1:
		{
			system("cls");
			std::cout << "����������� ������ ��������:\n";
			std::cout << "����� ������������� ������: ";
			std::cin >> str1;
			std::cout << "\n������� ��� ��������: ";
			std::getline(std::cin, str2);
			std::cout << "\n��� ��������: ";
			std::cin >> in1;
			std::cout << "\n����� ����������: ";
			std::getline(std::cin, str3);
			std::cout << "\n����� ������ ��� �����: ";
			std::getline(std::cin,str4);

			readHash.add(*(new reader(str1, str2, in1, str3, str4)));
			
			system("pause");
			break;
		}
		case 2:
		{
			system("cls");
			std::cout << "������ � ������������ ��������:\n";

			break;
		}
		case 3:
		{
			system("cls");
			std::cout << "�������� ���� ������������������ ���������\n";

			break;
		}
		case 4:
		{
			system("cls");
			std::cout << "������� ������ � ���������\n";
			break;
		}
		case 5:
		{
			system("cls");
			std::cout << "����� �������� �� � ������������� ������\n";

			break;
		}
		case 6:
		{
			system("cls");
			std::cout << "����� �������� �� ���\n";

			break;
		}
		case 7:
		{
			system("cls");
			std::cout << "���������� ����� �����!\n";
			break;
		}
		case 8:
		{
			system("cls");
			std::cout << "������� ������ � ������\n";
			break;
		}
		case 9:
		{
			system("cls");
			std::cout << "����� ����� �� �����\n";

			break;
		}
		case 10:
		{
			system("cls");
			std::cout << "����� ����� �� ���������� ��� ������(��) ��� ��������";
			break;
		}
		case 11:
		{
			system("cls");
			std::cout << "����������� ������ ���������� ����� ��������\n";
			break;
		}
		case 12:
		{
			system("cls");
			std::cout << "����������� ������ ���������� ����� �� ��������\n";
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