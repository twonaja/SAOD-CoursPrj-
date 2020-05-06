#include "openHashTable.h"

hashTable::myNode::~myNode()
{
    if (pPrev)
    {
        pPrev->pNext = pNext;
    }
    if (pNext)
    {
        pNext->pPrev = pPrev;
    }
}


hashTable::myNode::myNode(hashTable::myNode* pPrev, reader& tmp)
{
    myNode* pNext = pPrev->pNext;
    this->pPrev = pPrev;
    this->pNext = pNext;
    pPrev->pNext = this;
    pNext->pPrev = this;
    this->lData.push_back(tmp);
    this->shfr = tmp.getTN();
}

hashTable::myNode* hashTable::search(const std::string tmpShfr)
{
    myNode* tmp = Head.pNext;
    for (size_t i = 0; i < m_size; i++)
    {
        if (tmp->shfr == tmpShfr)
        {
            return tmp;
        }
        tmp = tmp->pNext;
    }
    return nullptr;
}

void hashTable::ñlear()
{
    for (size_t i = 0; i < m_size; i++)
    {
        delete Head.pNext;
    }
    m_size = 0;
}

hashTable::~hashTable()
{
    for (size_t i = 0; i < m_size; i++)
    {
        delete Head.pNext;
    }
}


void hashTable::add(reader& data)
{
    if(m_size != 0)
    { 
        myNode* tmp = this->search(data.getTN());
        if(tmp != nullptr)
        {
            tmp->lData.push_back(data);
        }
        else
        {
            new myNode(&Head, data);
            m_size++;
        }
    }
    else
    {
        new myNode(&Head, data);
        m_size++;
    }
}


bool hashTable::remove(std::string shfr, std::string tmpSPN)
{
    myNode* tmp = this->search(shfr);
    if (tmp != nullptr)
    {
        int lstSize = tmp->lData.size();
        for (int i = 0; i < lstSize; i++)
        {
            if (tmp->lData[i].getSPN = tmpSPN)
            {
                delete tmp;
                m_size--;
                return true;
            }
        }
    }
    return false;

}
