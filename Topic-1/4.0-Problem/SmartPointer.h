//
//  SmartPointer.h
//  Tema 1 - Exercici Avaluable 5
//
//  Created by Marc Verges on 28/9/23.
//

#pragma once
#include <iostream>
using namespace std;

template <typename T>
class SmartPointer
{
public:
    SmartPointer(): m_pointer(nullptr) {}
    SmartPointer(SmartPointer<T>& e);
    ~SmartPointer() {delete m_pointer;}
    SmartPointer<T>& operator= (T* e);
    SmartPointer<T>& operator=(SmartPointer<T>& e);
    T &operator * ();
    T *operator -> ();
    bool isNull();
private:
    T *m_pointer;
};


template <typename T>
SmartPointer<T> :: SmartPointer (SmartPointer<T>& e)
{
    if (e.m_pointer != nullptr)
    {
        m_pointer = new T;
        m_pointer = e.m_pointer;
    }
    e.m_pointer = nullptr;
}


template <typename T>
SmartPointer<T>& SmartPointer<T> :: operator= (T* e)
{
    if (m_pointer != nullptr)
    {
        delete m_pointer;
    }
    
    m_pointer = e;
    return *this;
}


template <typename T>
SmartPointer<T>& SmartPointer<T> :: operator=(SmartPointer& e)
{
    if (this != &e)
    {
        if (m_pointer != nullptr)
        {
            delete m_pointer;
        }
        
        if (e.m_pointer != nullptr)
        {
            m_pointer = e.m_pointer;
            e.m_pointer = nullptr;
        }
    }
    
    return *this;
}

template <typename T>
T& SmartPointer<T> :: operator * ()
{
    if(m_pointer == nullptr)
    {
        cout << "Error, l'apuntador és igual a null";
    }
    return *m_pointer;
}

template <typename T>
T* SmartPointer <T> :: operator -> ()
{
    if (m_pointer == nullptr)
    {
        cout << "Error, l'apuntador és igual a null";
    }
    return m_pointer;
}

template <typename T>
bool SmartPointer <T>:: isNull()
{
    if (m_pointer == nullptr)
    {
        return true;
    }
    else
    {
        return false;
    }
}
