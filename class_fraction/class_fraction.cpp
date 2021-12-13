// class_fraction.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
using std::cin;
using std::cout;
using std::endl;

class Fraction;
Fraction operator*(Fraction left, Fraction right);
Fraction operator/ (Fraction left, Fraction right);
Fraction operator+(Fraction left, Fraction right);
Fraction operator-(Fraction left, Fraction right);
bool operator==(Fraction left, Fraction right);
bool operator!=(Fraction left, Fraction right);
bool operator>(Fraction left, Fraction right);
bool operator<(Fraction left, Fraction right);
bool operator>=(Fraction left, Fraction right);
bool operator<=(Fraction left, Fraction right);


class Fraction
{
    int integer;
    int numerator;
    int denominator;
public:
    int get_integer()const
    {
        return integer;
    }
    int get_numerator()const
    {
        return numerator;
    }
    int get_denominator()const
    {
        return denominator;
    }
    void set_integer(int integer)
    {
        this->integer = integer;
    }
    void set_numerator(int numerator)
    {
        this->numerator = numerator;
    }
    void set_denominator(int denominator)
    {
        if (denominator == 0)
        {
            denominator = 1;
        }
        this->denominator = denominator;
    }
    Fraction()
    {
        this->integer = 0;
        this->numerator = 0;
        this->denominator = 1;
        cout << "Default cinstructor:\t" << this << endl;
    }
    explicit Fraction(int integer)
    {
        this->integer = integer;
        this->numerator = 0;
        this->denominator = 1;
        cout << "1argConstructor:\t" << this << endl;
    }
    Fraction(double decimal)
    {
        decimal += 1e-11;
        integer = decimal;
        denominator = 1e+9;
        decimal -= integer;
        numerator = decimal * denominator;
        reduce();
    }
    Fraction(int numerator, int denominator)
    {
        this->integer = 0;
        this->numerator = numerator;
        set_denominator(denominator);
        cout << "Constructor:\t" << this << endl;
    }
    Fraction(int integer, int numerator, int denominator)
    {
        this->integer = integer;
        this->numerator = numerator;
        set_denominator(denominator);
        cout << "Constructor:\t" << this << endl;
    }
    ~Fraction()
    {
        cout << "Destructor:\t" << this << endl;
    }

    Fraction& to_improper()
    {
        numerator += integer * denominator;
        integer = 0;
        return *this;
    }

    Fraction& to_proper()
    {
        integer += numerator / denominator;
        numerator %= denominator;
        return *this;
    }

    Fraction& reduce()
    {
        if (numerator==0)
        {
            return*this;
        }
        int more, less, rest;
        if (numerator>denominator)
        {
            more = numerator;
            less = denominator;
        }
        else
        {
            more = denominator;
            less = numerator;
        }
        do
        {
            rest = more % less;
            more = less;
            less = rest;
        } while (rest);
        int GCD = more;
        numerator /= GCD;
        denominator /= GCD;
        return *this;
    }
    
    Fraction inverted()
    {
        to_improper();
        return Fraction(this->denominator, this->numerator);
    }
    
    std::ostream& print(std::ostream& os = cout)const
    {
        if (integer)os << integer;
        if (numerator)
        {
            if (integer)os << "(";
            os << numerator << "/" << denominator;
            if (integer)os << ")";
        }
        else if (integer == 0)os << 0;
        os << endl;
        return os;
    }

    Fraction& operator=(const Fraction& other)
    {
        this->integer = other.integer;
        this->numerator = other.numerator;
        this->denominator = other.denominator;
        cout << "CopyAssigment:\t" << this << endl;
        return *this;
    }
    Fraction& operator*= (const Fraction& other)
    {
        return *this = *this*other;
    }
    Fraction& operator/=(const Fraction& other)
    {
        return *this = *this / other;
    }
    Fraction& operator +=(const Fraction& other)
    {
        return *this = *this + other;
    }
    Fraction& operator -=(const Fraction& other)
    {
        return *this = *this - other;
    }
    explicit operator int()const
    {
        return integer;
    }
    explicit operator double()const
    {
        return integer + (double)numerator / denominator;
    }

    friend std::istream& operator>>(std::istream& os, Fraction& obj);
};

Fraction operator*(Fraction left, Fraction right)
{
    left.to_improper();
    right.to_improper();
    return Fraction
    (
        left.get_numerator()*right.get_numerator(),
        left.get_denominator()*right.get_denominator()
    ).to_proper().reduce();
   /* result.set_numerator(left.get_numerator() * right.get_numerator());
    result.set_denominator(left.get_denominator() * right.get_denominator());*/
    /*result.to_proper();
    result.reduce();*/
    /*return result;*/
}

Fraction operator/ (Fraction left, Fraction right)
{
    return left * right.inverted();
}

int NOD(Fraction left, Fraction right)
{
    int more, less, rest;
    if (left.get_denominator() > right.get_denominator())
    {
        more = left.get_denominator();
        less = right.get_denominator();
    }
    else
    {
        more = right.get_denominator();
        less = left.get_denominator();
    }
    do
    {
        rest = more % less;
        more = less;
        less = rest;
    } while (rest);
    return more;
}

Fraction operator+(Fraction left, Fraction right)
{
    int NOK = (left.get_denominator() * right.get_denominator()) / NOD( left, right);
    int del_1 = NOK / left.get_denominator();
    int del_2 = NOK / right.get_denominator();
    left.to_improper();
    right.to_improper();
    return Fraction
    (
        (left.get_numerator()*del_1) + (right.get_numerator()*del_2),
        (left.get_denominator() * del_1)
    ).to_proper().reduce();
}

Fraction operator-(Fraction left, Fraction right)
{
    int NOK = (left.get_denominator() * right.get_denominator()) / NOD(left, right);
    int del_1 = NOK / left.get_denominator();
    int del_2 = NOK / right.get_denominator();
    left.to_improper();
    right.to_improper();
    return Fraction
    (
        (left.get_numerator() * del_1) - (right.get_numerator() * del_2),
        (left.get_denominator() * del_1)
    ).to_proper().reduce();
}


bool operator==(Fraction left, Fraction right)
{
    left.to_improper();
    right.to_improper();
    if (left.get_numerator() * right.get_denominator() == left.get_denominator() * right.get_numerator())
    {
        return true;
    }
    else
        return false;
}

bool operator!=(Fraction left, Fraction right)
{
    return !(left == right);
}

bool operator>(Fraction left, Fraction right)
{
    left.to_improper();
    right.to_improper();
    if (left.get_numerator() * right.get_denominator() > left.get_denominator() * right.get_numerator())
    {
        return true;
    }
    else
        return false;
}

bool operator<(Fraction left, Fraction right)
{
    return !(left > right);
}

bool operator>=(Fraction left, Fraction right)
{
    left.to_improper();
    right.to_improper();
    if (left.get_numerator() * right.get_denominator() >= left.get_denominator() * right.get_numerator())
    {
        return true;
    }
    else
        return false;
}

bool operator<=(Fraction left, Fraction right)
{
    return !(left >= right);
}

std::ostream& operator<<(std::ostream& os, const Fraction& obj)
{
    /*if (obj.get_integer())os << obj.get_integer();
    if (obj.get_numerator())
    {
        if (obj.get_integer())os << "(";
        os << obj.get_numerator() << "/" << obj.get_denominator();
        if (obj.get_integer())os << ")";
    }
    else if (obj.get_integer() == 0)os << 0;
    os << endl;
    return os;*/
    return obj.print(os);

}

std::istream& operator>>(std::istream& os, Fraction& obj)
{
    os >> obj.integer;
    os >> obj.numerator;
    os >> obj.denominator;
    return os;
}


//#define CONSTRUCTORS_CHECK
//#define OPERATORS_CHECK
//#define TYPE_CONVERSION_BASIC
//#define CONVERSIONS_FROM_OTHER_TO_CLASS

int main()
{
    setlocale(LC_ALL, "");
#ifdef CONSTRUCTORS_CHECK
    
    Fraction A;
    A.print();
    cout << "-----------------------------------------" << endl;
    Fraction B = 5;
    B.print();
    cout << "-----------------------------------------" << endl;
    Fraction C(3, 4);
    C.print();
    cout << "-----------------------------------------" << endl;
    Fraction D(2, 3, 4);
    D.print();
#endif // CONSTRUCTORS_CHECK
#ifdef OPERATORS_CHECK
    double a = 2.5;
    double b = 3.4;
    Fraction A(2, 1, 2);
    cout << "-----------------------------------------" << endl;
    Fraction B(2, 3, 5);
    cout << "-----------------------------------------" << endl;
    Fraction C = B + A;
    C.print();
    /*B -= A;
    B.print();*/
    cout << "-----------------------------------------" << endl;
#endif // OPERATORS_CHECK
#ifdef TYPE_CONVERSION_BASIC
    int a = 2;
    double b = 3;
    int c = b;
    int d = 4.5;
#endif // TYPE_CONVERSION_BASIC
#ifdef CONVERSIONS_FROM_OTHER_TO_CLASS
    double a = 2;
    Fraction A = (Fraction)5;
    A.print();

    Fraction B;
    cout << "-----------------------------------------" << endl;
    B = Fraction(8);
    cout << "-----------------------------------------" << endl;
    B.print();

    Fraction C(12);
    Fraction D{ 13 };
#endif // CONVERSIONS_FROM_OTHER_TO_CLASS

    /*Fraction A(2);
    int a (A);
    cout << a << endl;
    int i = (int)A;*/

    /*Fraction A(2, 3, 4);
    double a = A;
    cout << a << endl;
    
    double b = 2.75;
    Fraction B = b;
    B.print();*/
   
    Fraction A;
    cout<< "введите простую дробь" << endl;
    cin >> A;
    cout << A << endl;
    
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
