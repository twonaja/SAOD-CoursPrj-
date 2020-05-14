
#include "inc.h"

class myList
{
	struct  Node
	{
		std::string str;
		Node* Next;
	};
	Node* Head, * Tail;                                            //Первый элемент и тот что последний
	int size;                                                     //Число элементов в списке
public:
	myList() :Head(NULL), Tail(NULL), size(0) {};                       //Инициализация элементов в ноль с помощью конструктора
	~myList();                                                       //Прототип деструктор: в деструкторе освободим память
	void Add(std::string x);                                              //Прототип функции добавления элементов в списов                                     //Прототип функции отображения элементов списка
	void Remove(int num);
	int Count();                                                  //Прототип функции возвращающей число элементов в списке
	void Sort();
	friend std::ostream& operator << (std::ostream& os, const myList& lst);
};
