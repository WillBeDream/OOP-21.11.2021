// OOP 21.11.2021.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
#include<math.h>
using namespace std;
//#define STRUCT_POINT;

class Point
{
    double x;
    double y;
    double x_2;
    double y_2;
public:
    double get_x()const
    {
        return x;
    }
    double get_y()const
    {
        return y;
    }
    void set_x(double x)
    {
        this->x = x;
    }
    void set_y(double y)
    {
        this->y = y;
    }
    

    Point()
    {
        x = y = 0;
        cout << "default Constructor:\t" << this << endl;
    }
    Point(double x)
    {
        this->x = x;
        this->y = 0;
        cout << "1argConstructor:\t" << this << endl;
    }
    Point(int x, int y, int x_2, int y_2)
    {
        this-> x = x;
        this-> y = y;
        this-> x_2 = x_2;
        this-> y_2 = y_2;
        cout << "Constructor:\t" << this << endl;
    }
    ~Point()
    {
        cout << "Destructor:\t" << this << endl;
    }

    void print()const
    {
        cout << "x = " << x << "\ty = " << y << endl;
    }

    void distance(int x_1, int y_1, int x_2, int y_2)
    {
        double lenght = sqrt((x_2 - x_1) * (x_2 - x_1)) + sqrt((y_2 - y_1) * (y_2 - y_1));
        cout << lenght << endl;
    }
    
};


int main()
{
    setlocale(LC_ALL, "rus");
#ifdef STRUCT_POINT

    Point A;
    A.x = 2;
    A.y = 3;
    cout << A.x << endl << A.y << endl;
    Point* pA = &A;
    cout << pA->x << pA->y << endl;
#endif // STRUCT_POINT

   // Point A;
   ///* A.set_x(2);
   // A.set_y(3);*/
   // A.print();
   // Point B(4, 5);
   // B.print();
   // Point C = 5;
   // C.print();
   // Point D(8);
   // D.print();
    Point D(2, 2, 4, 4);
    D.distance(2,2,4,4);
    


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
