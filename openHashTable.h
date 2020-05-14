#pragma once
#include "reader.h"


class hashTable
{
private:
    class myNode
    {
    public:
        myNode* pPrev = nullptr; // ��������� �� ���������� �������
        myNode* pNext = nullptr; // ��������� �� ��������� �������
        std::vector<reader> lData; // ��������� �� ����� ��� ��������� �����������
        myNode() = default;
        myNode(myNode*, reader& tmp);
        ~myNode();
        std::string shfr;
    };
    myNode Head, Tail;
    size_t m_size = 0;
public:
    hashTable() :m_size(0) { Head.pNext = &Tail; Tail.pNext = &Head; }
    myNode* search(std::string shfr);
    void �lear();
    bool remove(std::string& shfr, std::string& tmpSPN);
    ~hashTable();

    void add(reader&);
    
    //void AddToTail(const reader&);
    //bool RemoveOne(char name, char patrnym, std::string serName);

    //void Sort();

    
    //bool SearchAndChange(char name, char patrnym, std::string serName);



    

    size_t GetSize() { return this->m_size; }

    //void print();

    //void AddToBD();

    //void chExp(int Exp);
};

