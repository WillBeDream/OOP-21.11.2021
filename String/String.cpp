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
    int get_size()const
    {
        return size;
    }
    const char* get_str()const
    {
        return str;
    }
    

    explicit String(int size=80)
    {
        this->size = size;
        this->str = new char[size] {};
        cout <<  "Constructor:\t" << this << endl;
    }
    
    String(const char* str)
    {
        this->size=strlen(str)+1;
        this->str = new char[size] {};
        for (size_t i = 0; i < size; i++)
        {
            this->str[i] = str[i];
        }
        cout << "1argConstructor:\t" << this << endl;
    }

    String(const String& other)
    {
        this->size = other.size;
        this->str = new char[size] {};
        for (size_t i = 0; i < size; i++)
        {
            this->str[i] = other.str[i];
        }
        cout << "CopyConstructor" << this << endl;
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
    void print()const
    {
        cout << size << endl;
        cout << str << endl;
    }

    char& operator[](int i)
    {
        return str[i];
    }

    const char& operator[](int i)const
    {
        return str[i];
    }

    String& operator=(const String& other)
    {
        if (this == &other)return *this;
        delete[] this->str;
        this->size = other.size;
        this->str = new char[size] {};
        for (size_t i = 0; i < size; i++)
        {
            this->str[i] = other.str[i];
        }
        cout << "CopyAssigment" << this << endl;
        return *this;
    }

};

String operator+(const String& str1, const String& str2)
{
    String result(str1.get_size() + str2.get_size()-1);
    for (size_t i = 0; i < str1.get_size(); i++)
    {
        result[i] = str1[i];
    }
    for (size_t i = 0; i < str2.get_size(); i++)
    {
        result[i + str1.get_size()-1] = str2[i];
    }
    return result;
}

String& operator+=(String& str1, const String& str2)
{
    return str1 = str1 + str2;
}

std::ostream& operator<<(std::ostream& os, const String& obj)
{
    return os << obj.get_str();
}

std::istream& operator>>(std::istream& os, String& obj)
{
    os >> obj.get_str();
    return os;
}


//#define CONSTRUCTORS_CHECK

int main()
{
#ifdef CONSTRUCTORS_CHECK
    String str;
    str.print();
    String str2 = "Hello";
    cout << str2 << endl;
    String str4 = str2;
    cout << str4 << endl;
    String str5;
    str5 = str2;
    cout << str5 << endl;
    str2 = str2;
    cout << str2 << endl;
#endif // CONSTRUCTORS_CHECK
    /*String str1 = "Hello";
    String str2 = "World";
    str1 += str2;
    str1.print();*/

    String str;
    cout << "enter words" << endl; 
    cin >> str;
    cout << str << endl;

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
