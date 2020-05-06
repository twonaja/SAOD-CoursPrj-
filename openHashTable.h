#pragma once
#include "reader.h"


class myList
{
private:
    class myNode
    {
    public:
        myNode* pPrev = nullptr; // ��������� �� ���������� �������
        myNode* pNext = nullptr; // ��������� �� ��������� �������
        std::list<reader> lData; // ��������� �� ����� ��� ��������� �����������
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

