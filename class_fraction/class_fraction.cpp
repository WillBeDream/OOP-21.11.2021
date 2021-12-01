// class_fraction.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
using std::cin;
using std::cout;
using std::endl;

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

    void to_improper()
    {
        numerator += integer * denominator;
        integer = 0;
    }

    void to_proper()
    {
        integer += numerator / denominator;
        numerator %= denominator;
    }

    int NOD()
    {
        while (numerator > 0 && denominator > 0)

            if (numerator > denominator)
                numerator %= denominator;

            else
                denominator %= numerator;
        //непонимаю как вернуть наименьший делитель это либо denominator либо numerator после if, потому что ретюрн может прервать цикл раньше положенного.
    }
    Fraction& reduce()
    {
        numerator /= NOD();
        denominator /= NOD();
        return *this;
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
};


Fraction operator*(Fraction left, Fraction right)
{
    left.to_improper();
    right.to_improper();
    Fraction result
    (
        left.get_numerator()*right.get_numerator(),
        left.get_denominator()*right.get_denominator()
    );
   /* result.set_numerator(left.get_numerator() * right.get_numerator());
    result.set_denominator(left.get_denominator() * right.get_denominator());*/
    result.to_proper();
    return result;

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
    /*double a = 2.5;
    double b = 3.4;
    Fraction A(2, 1, 2);
    Fraction B(3, 2, 5);
    Fraction C = A * B;
    C.print();*/
    Fraction C(0, 4, 10);
    C.reduce();
    C.print();


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
