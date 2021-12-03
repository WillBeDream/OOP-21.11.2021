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
    Fraction(int integer)
    {
        this->integer = integer;
        this->numerator = 0;
        this->denominator = 1;
        cout << "1argConstructor" << this << endl;
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
    
    void print()const
    {
        if (integer)cout << integer;
        if (numerator)
        {
            if (integer)cout << "(";
            cout << numerator << "/" << denominator;
            if (integer)cout << ")";
        }
        else if (integer == 0)cout << 0;
        cout << endl;
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

Fraction operator+(Fraction left, Fraction right)
{
    int more, less, rest;
    if (left.get_denominator()>right.get_denominator())
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
    int NOK = (left.get_denominator() * right.get_denominator()) / more;
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
    int NOK = (left.get_denominator() * right.get_denominator()) / more;
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

//#define CONSTRUCTORS_CHECK

int main()
{
#ifdef CONSTRUCTORS_CHECK
    setlocale(LC_ALL, "");
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
    double a = 2.5;
    double b = 3.4;
    Fraction A(2, 1, 2);
    cout << "-----------------------------------------" << endl;
    Fraction B(2, 3, 5);
    cout << "-----------------------------------------" << endl;
   /* Fraction C = B-A;
    C.print();*/
    B -= A;
    B.print();
    cout << "-----------------------------------------" << endl;
    
   

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
