// OOP 21.11.2021.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
#include<math.h>
using namespace std;
//#define STRUCT_POINT;
//#define DISTANCE_CHECK
//#define CONSTRUCTORS_CHECK
//#define ASSIGMENT_CHECK

class Point
{
	double x;
	double y;
	
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


	/*Point()
	{
		x = y = 0;
		cout << "default Constructor:\t" << this << endl;
	}
	Point(double x)
	{
		this->x = x;
		this->y = 0;
		cout << "1argConstructor:\t" << this << endl;
	}*/
	Point(int x = 0, int y = 0)
	{
		this->x = x;
		this->y = y;
		cout << "Constructor:\t" << this << endl;
	}
	Point(const Point& other)
	{
		this->x = other.x;
		this->y = other.y;
		cout << "copyConstructor:\t" << this << endl;

	}
	~Point()
	{
		cout << "Destructor:\t" << this << endl;
	}

	Point& operator =(const Point& other)
	{
		this-> x = other.x;
		this-> y = other.y;
		cout << "CopyAssigment:\t" << this << endl;
		return *this;
	}

	Point& operator++()//префиксный
	{
		this->x++;
		this->y++;
		return *this;
	}
	Point operator++(int)//постфиксный
	{
		Point old = *this;
		x++;
		y++;
		return old;
	}

	void print()const
	{
		cout << "x = " << x << "\ty = " << y << endl;
	}

	double distance(const Point& other)const
	{
		double x_distance = this->x - other.x;
		double y_distance = this->y - other.y;
		double distance = sqrt((x_distance * x_distance)) + sqrt((y_distance * y_distance));
		return distance;
	}

};

double distance(const Point& A, const Point& B)
{
	double x_distance = A.get_x() - B.get_x();
	double y_distance = A.get_y() - B.get_y();
	return sqrt(x_distance * x_distance + y_distance * y_distance);
}

Point operator+(const Point& left, const Point& right)
{
	Point result;
	result.set_x(left.get_x() + right.get_x());
	result.set_y(left.get_y() + right.get_y());
	return result;
}


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

#ifdef CONSTRUCTORS_CHECK
	Point A;
	/* A.set_x(2);
	 A.set_y(3);*/
	A.print();
	Point B(4, 5);
	B.print();
	Point C = 5;
	C.print();
	Point D(8);
	D.print();
	Point E = D;
	E.print();

	Point F(B);
	F.print();
	Point G;
	G = F;

#endif // CONSTRUCTORS_CHECK

#ifdef DISTANCE_CHECK
	Point A(2, 3);
	Point B(3, 4);
	cout << "-----------------------------------------" << endl;
	cout << A.distance(B) << endl;
	cout << "-----------------------------------------" << endl;
	cout << B.distance(A) << endl;
	cout << "-----------------------------------------" << endl;
	cout << distance(A, B) << endl;
	cout << "-----------------------------------------" << endl;
	cout << distance(B, A) << endl;
	cout << "-----------------------------------------" << endl;
#endif // DISTANCE_CHECK

#ifdef ASSIGMENT_CHECK
	Point A, B, C;
	cout << "-----------------------------------------" << endl;
	A = B = C = Point(2,3);
	cout << "-----------------------------------------" << endl;
	A.print();
	B.print();
	C.print();


#endif // ASSIGMENT_CHECK
	Point A(2, 3);
	cout << "-----------------------------------------" << endl;
	Point B(4, 5);
	cout << "-----------------------------------------" << endl;
	/*Point C = A + B;
	cout << "-----------------------------------------" << endl;
	C.print();
	cout << "-----------------------------------------" << endl;
	C++;
	cout << "-----------------------------------------" << endl;
	C.print();*/
	B = A++;
	B.print();
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
