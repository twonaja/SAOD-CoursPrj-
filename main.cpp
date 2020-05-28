#include "avl.h"
#include "book.h"
#include "MyList.h"
#include "openHashTable.h"
#include "avl.h"


int main()
{
	setlocale(LC_ALL, "Russian");

	std::string str1 = "\0"; //��� �������� ����� ������  --- ��� ����� ����
	std::string str2 = "\0"; //��� �������� ������� �������� ��� --- ��� ����� ��� ������ // ������ ���� �����
	std::string str3 = "\0"; //����� ����������  ��������  --- �������� �����
	std::string str4 = "\0"; //����� ������ ��� ����� �������� --- ������������

	unsigned int in1 = 0; // ��� �������� �������� --- ��� ����������
	unsigned int in2 = 0; //��� ����� ����� �����������  
	unsigned int in3 = 0; //��� ����� ���������� � ������� 


	myList hoTakeWhatTake; //������ � ������� �������� ���� ���� � ����� ������ 
	AVL<book> bookTree; //��� ������ � �������
	hashTable readHash; //��� ������� � ���������� 

	int choice = 0;
	int uchce = 0;
	int delShfrTckt = -1;
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
			"8 - �������� �������� � �����\n" 
			"9 - �������� ���� ��������� ����\n"
			"10 - ������� ������ � ������\n"
			"11 - ����� ����� �� �����\n"
			"12 - ����� ����� �� ���������� ��� ������(��) ��� ��������\n"
			"13 - ����������� ������ ���������� ����� ��������\n"
			"14 - ����������� ������ ���������� ����� �� ��������\n"
			"20 - �����\n";

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
			std::cout << "����� ������������� ������: ";
			std::cin >> str1;
			std::cout << "\n������� ��� ��������: ";
			std::getline(std::cin, str2);
			readHash.remove(str1, str2);
			break;
		}
		case 3:
		{
			system("cls");
			std::cout << "�������� ���� ������������������ ���������\n";
			std::cout << readHash;
			system("pause");
			break;
		}
		case 4:
		{
			system("cls");
			std::cout << "������� ������ � ���������\n";
			readHash.�lear();
			break;
		}
		case 5:
		{
			system("cls");
			std::cout << "����� �������� �� � ������������� ������\n";

			std::cout << "����� ������������� ������: ";
			std::cin >> str1;
			if (readHash.searchShf(str1) == false)
			{
				std::cout << "����� ������������� ������ �� ������!\n";
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
			std::cout << "����� �������� �� ���\n";

			std::cout << "\n������� ��� ��������: ";
			std::getline(std::cin, str2);
			readHash.searchNM(str2);
			break;
		}
		case 7:
		{
			system("cls");
			std::cout << "���������� ����� �����\n";

			std::cout << "���� �����: ";
			std::cin >> str1;
			std::cout << "\n������� �.�. ������: ";
			std::getline(std::cin, str2);
			std::cout << "\n�������� �����: ";
			std::getline(std::cin, str3);
			std::cout << "\n������������: ";
			std::getline(std::cin, str4);
			
			std::cout << "\n��� ����������: ";
			std::cin >> in1;
			std::cout << "\n����� �����������: ";
			std::cin >> in2;
			std::cout << "\n����������� � �������: ";
			std::cin >> in3;
			bookTree.insert(book(str1, str2, str3, str4, in1, in2, in3));
			break;
		}
		case 8:
		{
			system("cls");
			std::cout << "�������� �������� � �����\n";


			bookTree.deleteKey(str1);
			break;
		}
		case 9:
		{
			system("cls");
			std::cout << "�������� ���� ��������� ����\n";
			bookTree.printBalance();
			system("pause");
			break;
		}
		case 10:
		{
			system("cls");
			std::cout << "������� ������ � ������\n";

			break;
		}
		case 11:
		{
			system("cls");
			std::cout << "����� ����� �� �����\n";
			bookTree.searchShfr(str1, uchce);
			break;
		}
		case 12:
		{
			system("cls");
			std::cout << "����� ����� �� ���������� ��� ������(��) ��� ��������";
			break;
		}
		case 13:
		{
			system("cls");
			std::cout << "����������� ������ ���������� ����� ��������\n";
			std::cout << "������������ �����: ";
			std::cin >> str1;
			std::cout << "���� �����: ";
			std::cin >> str2;
			hoTakeWhatTake.Add(str1 + str2);
			uchce = 1;
			bookTree.retGetBook(str2, uchce);
			break;
		}
		case 14:
		{
			system("cls");
			std::cout << "����������� ������ ���������� ����� �� ��������\n";
			std::cout << "������������ �����: ";
			std::cin >> str1;
			std::cout << "���� �����: ";
			std::cin >> str2;
			delShfrTckt = hoTakeWhatTake.searchBkTicket(str1, str2);
			if (delShfrTckt == -1)
			{
				break;
			}
			uchce = 2;
			bookTree.retGetBook(str2, uchce);
			system("cls");
			std::cout << "����� �������!";
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
			std::cout << "\n������������ ����!\n";
			system("pause");
			break;
		}
		}
	}
	return 0;
}