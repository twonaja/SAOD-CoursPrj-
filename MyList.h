
#include "inc.h"

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
	friend std::ostream& operator << (std::ostream& os, const myList& lst);
};
