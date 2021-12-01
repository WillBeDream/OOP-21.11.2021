// Fraction.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
using namespace std;

class Fraction
{
    int numerator;
    int denominator;
public:
    int get_numerator()const
    {
        return numerator;
    }
    int get_denominator()const
    {
        return denominator;
    }
    void set_numerator(int numerator)
    {
        this->numerator=numerator;
    }
    void set_denominator(int denominator)
    {
        if (denominator==0)
        {
            denominator = 1;
        }
        this->denominator = denominator;

    }

    Fraction()
    {
        numerator = 0;
        denominator = 1;
        cout << "default Constructor:\t" << this << endl;
    }
    Fraction(int numerator)
    {
        this->numerator = numerator;
        this->denominator = 1;
        cout << "1argConstructor:\t" << this << endl;
    }
    Fraction(int numerator, int denominator)
    {
        this->numerator = numerator;
        this->denominator = denominator;
        cout << "Constructor:\t" << this << endl;
    }
    Fraction(const Fraction& fraction)
    {
        this->numerator = fraction.numerator;
        this->denominator = fraction.denominator;
        cout << "copyConstructor:\t" << this << endl;
    }

    ~Fraction()
    {
        cout << "Destructor:\t" << this << endl;
    }

    void print()const
    {
        cout << numerator << "/" << denominator<<endl;
    }

};

Fraction operator*(const Fraction& value, const Fraction& value_2)
{
    Fraction result;
    result.set_numerator(value.get_numerator()*value_2.get_numerator());
    result.set_denominator(value.get_denominator() * value_2.get_denominator());
    return result;

}

Fraction operator*(const Fraction& value, const Fraction& value_2)
{
    Fraction result;
    result.set_numerator(value.get_numerator() * value_2.get_numerator());
    result.set_denominator(value.get_denominator() * value_2.get_denominator());
    return result;

}


int main()
{
    Fraction A;	//Default onstructor
    A.print();
    cout << "-----------------------------------------" << endl;
    Fraction B = 5;
    B.print();
    cout << "-----------------------------------------" << endl;
    Fraction C(1, 2);
    cout << "-----------------------------------------" << endl;
    Fraction F(2, 4);
    C.print();
    cout << "-----------------------------------------" << endl;
    Fraction E = C * F;
    E.print();
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
