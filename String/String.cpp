// String.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
using std::cin;
using std::cout;
using std::endl;

#define delimiter "\n-------------------------------------------\n"


class String;
String operator+(const String& str1, const String& str2);

class String
{
    int size;
    char* str;
public:
    char* get_str();
    int get_size()const;
    const char* get_str()const;
    
    explicit String(int size = 80);
    
    String(const char* str);

    String(const String& other);

    ~String();

    void print()const;

    char& operator[](int i);

    const char& operator[](int i)const;

    String& operator=(const String& other);
    String& operator+=(const String& other);
};

char* String::get_str()
{
    return str;
}
int String::get_size()const
{
    return size;
}
const char* String::get_str()const
{
    return str;
}

String::String(int size) :size(size), str(new char[size] {})
{
    /*this->size = size;
    this->str = new char[size] {};*/
    cout << "Constructor:\t" << this << endl;
}

String::String(const char* str) :String(strlen(str) + 1)
{
    /*this->size=strlen(str)+1;
    this->str = new char[size] {};*/
    for (size_t i = 0; i < size; i++)
    {
        this->str[i] = str[i];
    }
    cout << "1argConstructor:\t" << this << endl;
}

String::String(const String& other) :String(other.str)
{
    ///*this->size = other.size;
    //this->str = new char[size] {};*/
    //for (size_t i = 0; i < size; i++)
    //{
    //    this->str[i] = other.str[i];
    //}
    cout << "CopyConstructor" << this << endl;
}

String::~String()
{
    delete[]str;
    cout << "Destructor:\t" << this << endl;
}

void String::print()const
{
    cout << size << endl;
    cout << str << endl;
}

char& String::operator[](int i)
{
    return str[i];
}

const char& String::operator[](int i)const
{
    return str[i];
}

String& String::operator=(const String& other)
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
String& String::operator+=(const String& other)
{
    return *this = *this + other;
}

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

//String& operator+=(String& str1, const String& str2)
//{
//    return str1 = str1 + str2;
//}

std::ostream& operator<<(std::ostream& os, const String& obj)
{
    return os << obj.get_str();
}

std::istream& operator>>(std::istream& os, String& obj)
{
    /*os >> obj.get_str();*/
    const int SIZE = 1024*1000;
    char buffer[SIZE] = {};
    os >> buffer;
    obj = buffer;
    return os;
}

std::istream& getline(std::istream& os, String& obj)
{
    const int SIZE = 1024 * 1000;
    char buffer[SIZE] = {};
    os.getline(buffer, SIZE);
    obj = buffer;
    return os;
}

//#define CONSTRUCTORS_CHECK
#define OPERATORS_CHECK
//#define INPUT_CHECK

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
#ifdef OPERATORS_CHECK
String str1 = "Hello";
String str2 = "World";
cout << delimiter;
str1 += str2;
cout << delimiter;
str1.print();
cout << delimiter;
String str;
cout << "enter words" << endl; 
cin >> str;
cout << str << endl;  
#endif // OPERATORS_CHECK

#ifdef INPUT_CHECK
    String str;
    getline(cin, str);
    cout << str << endl;
#endif // INPUT_CHECK


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
