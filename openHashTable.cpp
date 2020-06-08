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

bool hashTable::searchShf(const std::string tmpShfr)
{
    myNode* tmp = Head.pNext;
    for (size_t i = 0; i < m_size; i++)
    {
        if (tmp->shfr == tmpShfr)
        {
            int sz = tmp->lData.size();
            for (size_t i = 0; i < sz; i++)
            {
                std::cout << tmp->lData[i];
            }
            return true;
        }
        tmp = tmp->pNext;
    }
    return false;
}

void hashTable::searchNM(const std::string tmpSurname, const std::string tmpName, const std::string tmpPatr)
{
	if (m_size != 0)
	{
		myNode* tmp = Head.pNext;
		for (size_t i = 0; i < m_size; i++)
		{
			int sz = tmp->lData.size();
			for (size_t i = 0; i < sz; i++)
			{
				if ((tmp->lData[i].getSur() == tmpSurname) && (tmp->lData[i].getName() == tmpName) && (tmp->lData[i].getPatr() == tmpPatr))
				{
					std::cout <<"Ф.И.О: " << tmp->lData[i].getSur() << " " << tmp->lData[i].getName() << " " 
                        << tmp->lData[i].getPatr() << "\nНомер билета: " << tmp->lData[i].getTN() << std::endl;
				}
			}
			tmp = tmp->pNext;
		}
	}
}

void hashTable::сlear()
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


bool hashTable::remove(std::string& shfr)
{
    int numReader = -1;
    myNode* tmp = this->search(shfr);
    if (tmp != nullptr)
    {
        int lstSize = tmp->lData.size();
        if (lstSize == 0)
        {
            return false;
        }
        else
        {
            for (int i = 0; i < lstSize; i++)
            {
                std::cout << i+1 << ") " << tmp->lData[i].getSur() << " " << tmp->lData[i].getName() 
                    << " " << tmp->lData[i].getPatr() << std::endl;
            }
            std::cout << "Введите номер пользователя из списка для его удаления: ";
            std::cin >> numReader;
            tmp->lData.erase(tmp->lData.begin() + (numReader-1));
            if (tmp->lData.size() == 0)
            {
                delete tmp;
                this->m_size--;
            }
            return true;
        }
               
    }
    return false;

}

std::ostream& operator<<(std::ostream& os, const hashTable& myTable)
{
    hashTable::myNode* tmp = myTable.Head.pNext;
    for (size_t i = 0; i < myTable.m_size; i++)
    {
        int sz = tmp->lData.size();
        for (int i = 0; i < sz; i++)
        {
            os << tmp->lData[i] << std::endl;
        }
        tmp = tmp->pNext;
    }
    return os;
}
