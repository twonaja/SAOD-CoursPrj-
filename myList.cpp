#include "myList.h"

myList::~myList()
{
	while (size != 0)                        //���� ����������� ������ �� ������ �������
	{
		Node* temp = Head->Next;
		delete Head;                           //����������� ������ �� ��������� ��������
		Head = temp;                           //����� ������ ������ �� ����� ���������� ��������
		size--;                                //���� ������� ����������. ������������ ����� ���������
	}
}

int myList::Count()
{
	return size;                             //���������� ����� ��������� ������
}

void myList::Add(std::string x)
{
	size++;                                    //��� ������ ���������� �������� ����������� ����� ��������� � ������
	Node* temp = new Node;
	temp->Next = Head;                         //��������� �������. ��������� ������� - ��� ������ ������
	temp->str = x;                               //���������� � ���������� ������ ������ �������� x

	if (Head != NULL)                       //� ��� ������ ���� ������ �� ������
	{
		Tail->Next = temp;                    //������ ������ � ��������� �� ��������� ��������� ����
		Tail = temp;                          //��������� �������� �������=������ ��� ���������.
	}
	else
	{
		Head = Tail = temp;	//���� ������ ���� �� ��������� ������ �������.
	}                
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
	
	 

}

std::ostream& operator<<(std::ostream& os, const myList& lst)
{
	myList::Node* temp = lst.Head;
	for (size_t i = 0; i < lst.size; i++)
	{
		os << temp->str << std::endl;
		temp = temp->Next;
	}
	return os;
}