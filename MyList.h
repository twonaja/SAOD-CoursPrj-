
#include "inc.h"
#include "openHashTable.h"

class myList
{
	struct  Node
	{
		std::string str;
		Node* Next;
	};
	Node* Head, * Tail;                                            //������ ������� � ��� ��� ���������
	int size;                                                     //����� ��������� � ������
public:
	myList() :Head(NULL), Tail(NULL), size(0) {};                       //������������� ��������� � ���� � ������� ������������
	~myList();                                                       //�������� ����������: � ����������� ��������� ������
	void Add(std::string x);                                              //�������� ������� ���������� ��������� � ������                                     //�������� ������� ����������� ��������� ������
	void Remove(int num);
	int Count();                                                  //�������� ������� ������������ ����� ��������� � ������
	void Sort();
	void prntBook(std::string tckt); //����� ����� �� ������
	void readerInfo(std::string& book, hashTable& reader);
	//std::string getTicket(std::string tckt);
	int searchBkTicket(std::string tckt, std::string bk);
	friend std::ostream& operator << (std::ostream& os, const myList& lst);
};
