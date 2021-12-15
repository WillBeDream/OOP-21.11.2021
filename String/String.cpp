// String.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
using std::cin;
using std::cout;
using std::endl;

class String
{
    int size;
    char* str;
public:
    char* get_str()
    {
        return str;
    }
    int get_size()
    {
        return size;
    }

    String(int size=80)
    {
        this->size = size;
        this->str[size];
        cout << "Default constructor:\t" << this << endl;
    }
    String(const char* str)
    {
        this->size = strlen(str);
        this->str = new char[size];
        for (size_t i = 0; i < size; i++)
        {
            this->str[i] = str[i];
        }
        cout << "1argConstructor:\t" << this << endl;
    }
    ~String()
    {
        delete[]str;
        cout << "Destructor:\t" << this << endl;
    }
    String operator=(char* str)
    {
        for (size_t i = 0; str[i]!='\0'; i++)
        {
            this->str[i] = str[i];
        }
    }
    void Print()
    {
        for (size_t i = 0; i < size; i++)
        {
            cout << str[i];
        }
        cout << endl;
    }
};

String operator+(String& str1, String& str2)
{
    String result=str1.get_size()+str2.get_size();
    for (size_t i = 0; i < str1.get_size(); i++)
    {
        result.get_str()[i] = str1.get_str()[i];
    }
    for (size_t i = 0; i < str2.get_size(); i++)
    {
        result.get_str()[i + str1.get_size()] = str2.get_str()[i];
    }
    return result;
}

int main()
{
    String str;	//Пустая строка размером 80 Байт
    String str1 = "Hello";
    String str2 = "World";
    str2.Print();
    String str3 = str1 + str2;
    str3.Print();
}

// Run program: Ctrl + F5 or Debug > Start Without Debugging menu
// Debug program: F5 or Debug > Start Debugging menu

// Tips for Getting Started: 
//   1. Use the Solution Explorer window to add/manage files
//   2. Use the Team Explorer window to connect to source control
//   3. Use the Output window to see build output and other messages
//   4. Use the Error List window to view errors
//   5. Go to Project > Add New Item to create new code files, or Project > Add Existing Item to add existing code files to the project
//   6. In the future, to open this project again, go to File > Open > Project and select the .sln file
