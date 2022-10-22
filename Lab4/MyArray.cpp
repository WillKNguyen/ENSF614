//MyArray.cpp
// ENSF 614 Fall 2022 LAB 4 - EXERCISE A
// @author Khoi Nguyen

#include "MyArray.h"

MyArray::MyArray(): sizeM(0), storageM(new EType[0]){}

MyArray::MyArray(const EType *builtin, int sizeA): sizeM(sizeA), storageM(new EType[sizeA])
{
    for (int i = 0; i < sizeM; i++)
    {
        storageM[i] = builtin[i];
    }
}

MyArray::MyArray(const MyArray& source): sizeM(source.sizeM)
{
    storageM = new EType[sizeM];
    for (int i = 0; i < sizeM; i++)
    {
        storageM[i] = source.storageM[i];
    }
}

MyArray& MyArray:: operator=(const MyArray& rhs)
{
    if (this != &rhs)
    {
        delete [] storageM;
        sizeM = rhs.sizeM;
        storageM = new EType[sizeM];
        for (int i = 0; i < sizeM; i++)
        {
            storageM[i] = rhs.storageM[i];
        }
    }
    return *this;
}

MyArray::~MyArray()
{
    delete [] storageM;
    storageM = nullptr;
}

int MyArray::size() const {return sizeM;}

EType MyArray::at(int i) const 
{
    EType& obj = storageM[i];
    return obj;
}

void MyArray::set(int i, EType new_value)
{
    storageM[i] = new_value;
}

void MyArray::resize(int new_size)
{
    EType* old_storageM = storageM;
    storageM = new EType[new_size];
    if (new_size <= sizeM)
    {
        for (int i = 0; i < new_size; i++)
        {
            storageM[i] = old_storageM[i];
        }
    }
    else
    {
        for (int i = 0; i < sizeM; i++)
        {
            storageM[i] = old_storageM[i];
        }
    }
    delete [] old_storageM;
    sizeM = new_size;
}