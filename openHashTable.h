#pragma once
#include "reader.h"


class myList
{
private:
    class myNode
    {
    public:
        myNode* pPrev = nullptr; // указатель на предыдущий элемент
        myNode* pNext = nullptr; // указатель на следующий элемент
        std::list<reader> lData; // указатель на класс где храняться сотрудникик
        myNode() = default;
        myNode(myNode*, const reader& tmp);
        ~myNode();
        std::string shfr;
    };
    myNode Head, Tail;
    size_t m_size = 0;
public:
    myList() :m_size(0) { Head.pNext = &Tail; Tail.pNext = &Head; }
    int search(const std::string shfr);

    ~myList();

    void add(const reader&);
    
    //void AddToTail(const reader&);
    //bool RemoveOne(char name, char patrnym, std::string serName);

    //void Sort();

    
    //bool SearchAndChange(char name, char patrnym, std::string serName);



    void Clear();

    size_t GetSize() { return this->m_size; }

    void print();

    void AddToBD();

    void chExp(int Exp);
};

