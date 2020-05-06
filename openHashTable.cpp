#include "openHashTable.h"

myList::myNode::~myNode()
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

myList::myNode::myNode(myList::myNode* pPrev, const reader& tmp)
{
    myNode* pNext = pPrev->pNext;
    this->pPrev = pPrev;
    this->pNext = pNext;
    pPrev->pNext = this;
    pNext->pPrev = this;
    this->lData.push_back(tmp);
    
}


myList::~myList()
{
    for (size_t i = 0; i < m_size; i++)
    {
        delete Head.pNext;
    }
}


void myList::add(const reader& data)
{
    if(m_size != 0)
    { 
        int counter = this->search(data.getTN());
        if(counter != 0)
        {
            myNode* tmp = Head.pNext;

            for (size_t i = 0; i <= counter; i++)
            {
                tmp = tmp->pNext;
            }
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

void myList::AddToTail(const workers* data)
{
    new myNode(Tail.pPrev, data);
    m_size++;
}

bool myList::RemoveOne(char name, char patrnym, std::string serName)
{
    myNode* p = Head.pNext;
    while (p != &Tail)
    {
        if ((name == p->pData->getName()) && (patrnym == p->pData->getPatrnym())
            && (serName == p->pData->getSurName()))
        {
            delete p;
            m_size--;
            return true;
        }
        p = p->pNext;
    }
    return false;

}



void myList::Clear()
{
    for (size_t i = 0; i < m_size; i++)
    {
        delete Head.pNext;
    }
    m_size = 0;
}

void myList::print()
{
    myNode* tmp = Head.pNext;
    std::cout << " Worker" << std::setw(20) << " year" << std::setw(20) << " position" << std::endl;
    for (size_t i = 0; i < m_size; i++)
    {
        std::cout << tmp->pData << std::endl;
        tmp = tmp->pNext;
    }
}

void myList::Sort()
{
    if (m_size > 1)
    {
        for (size_t i = 0; i < m_size; i++) // сортировка пузырьком 2 цикла 
        {
            myNode* tmp = Head.pNext; // заводим первый временный указаетль на голову списка (если что у меня данные храняться 
            //в отельном классе и получаю к ним доступ с помощью указателя)
            myNode* tmp2 = tmp->pNext; // заводим второй указатель на следующий элемент списка
            for (size_t i = 0; i < m_size - 1; i++)
            {
                if (tmp->pData->getYear() > tmp2->pData->getYear()) // у меня сравнение идет по году устройства на работу сотрудника
                {
                    //обычный swap заводим временный указатель на класс в котором хранятся данные о сотруднике
                    workers* forAwh = tmp->pData; // ну и обычный swap
                    tmp->pData = tmp2->pData;
                    tmp2->pData = forAwh;
                }
                tmp = tmp->pNext; // идем дальше
                tmp2 = tmp2->pNext;
            }
        }
    }
}

int myList::search(const std::string tmpShfr)
{
    myNode* tmp = Head.pNext;
    for (size_t i = 0; i < m_size; i++)
    {
        if (tmp->shfr == tmpShfr)
        {
            return i;
        }
        tmp = tmp->pNext;
    }
    return 0;
}

bool myList::SearchAndChange(char name, char patrnym, std::string serName)
{
    myNode* tmp = Head.pNext;
    for (size_t i = 0; i < m_size; i++)
    {
        if ((name == tmp->pData->getName()) && (patrnym == tmp->pData->getPatrnym()) && (serName == tmp->pData->getSurName()))
        {
            std::cout << "\nEmployee " << name << "." << patrnym << " " << serName << "found!";
            std::cout << "\nChange Surname - 1\nChange Position - 2\nback - any key!\n";

            std::string tmpStr;
            int tmpSwitch;

            std::cin >> tmpSwitch;

            switch (tmpSwitch)
            {
            case 1:
            {
                std::cout << "Enter new employee surname: ";
                std::cin >> tmpStr;
                tmp->pData->setSurName(tmpStr);
                system("cls");
                std::cout << "Employee surname is changed!\n";
                system("pause");
                break;
            }
            case 2:
            {
                std::cout << "Enter new employee position: ";
                std::cin >> tmpStr;
                tmp->pData->setPosition(tmpStr);
                system("cls");
                std::cout << "Employee position is changed!\n";
                system("pause");
                break;
            }
            default:
                break;
            }
            return true;
        }
        tmp = tmp->pNext;
    }
    return false;
}

void myList::chExp(int Exp)
{
    myNode* tmp = Head.pNext;
    std::cout << "Size = " << m_size << std::endl;
    for (size_t i = 0; i < m_size; i++)
    {
        tmp->pData->Exp(Exp);
        tmp = tmp->pNext;
    }
}
//
//void myList::AddToBD()
//{
//    if (this->m_size != 0)
//    {
//        std::ofstream File;
//        File.open("BD.txt");
//        myNode* tmp = Head.pNext;
//
//        for (size_t i = 0; i < m_size; i++)
//        {
//            File << tmp->pData->getSurName() << " " << tmp->pData->getName() << " " << tmp->pData->getPatrnym()
//                << " " << tmp->pData->getYear() << " " << tmp->pData->getPosition();
//            if (i != (m_size - 1))
//            {
//                File << "\n";
//            }
//            tmp = tmp->pNext;
//        }
//        File.close();
//    }
//}