// Matrix.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
using std::cin;
using std::cout;
using std::endl;

#define delimiter "\n-------------------------------------------\n"

class Matrix
{
    int length;
    int width;
    int** matrix;

public:

    const int get_length() const
    {
        return length;
    }

    const int get_width() const
    {
        return width;
    }

    int** get_matrix()
    {
        return matrix;
    }
    Matrix(int length = 2, int width = 2)
    {
        this->length = length;
        this->width = width;
        this->matrix = new int* [length] {};
        for (size_t i = 0; i < length; i++)
            matrix[i] = new int[width] {};
        cout << "DefaultConstructor:\t" << this << endl;
    }
    Matrix(const Matrix& other)
    {
        this->length = other.length;
        this->width = other.width;
        this->matrix = new int* [length] {};
        for (size_t i = 0; i < length; i++)
            matrix[i] = new int[width] {};
        for (size_t i = 0; i < length; i++)
        {
            for (size_t j = 0; j < width; j++)
            {
                matrix[i][j] = other.matrix[i][j];
            }
        }
        cout << "CopyConstructor:\t" << this << endl;
    }
    ~Matrix()
    {
        for (size_t i = 0; i < length; i++)
        {
            delete[]matrix[i];
        }
        delete[]matrix;
    }

    void rand_matrix()
    {
        for (size_t i = 0; i < length; i++)
        {
            for (size_t j = 0; j < width; j++)
            {
                matrix[i][j] = rand()%10;
            }
        }
    }

    void input_matrix()
    {
        for (size_t i = 0; i < length; i++)
        {
            for (size_t j = 0; j < width; j++)
            {
                cin>>matrix[i][j];
            }
        }
    }

    void print()
    {
        for (size_t i = 0; i < length; i++)
        {
            for (size_t j = 0; j < width; j++)
            {
                cout << matrix[i][j]<<" ";
            }
            cout << endl;
        }
    }

    int* operator[](int i)
    {
        return matrix[i];
    }

    const int* operator[](int i)const
    {
        return matrix[i];
    }
};

Matrix operator+(const Matrix& mtr1, const Matrix& mtr2)
{
    Matrix result(mtr1.get_length(), mtr1.get_width());
    for (size_t i = 0; i < mtr1.get_length(); i++)
    {
        for (size_t j = 0; j < mtr1.get_width(); j++)
        {
            result[i][j] = mtr1[i][j] + mtr2[i][j];
        }
    }
    return result;
}

Matrix operator*(const Matrix& mtr1, const Matrix& mtr2)
{
    Matrix result(mtr1.get_length(), mtr1.get_width());
    for (size_t i = 0; i < mtr1.get_length(); i++)
    {
        for (size_t j = 0; j < mtr1.get_width(); j++)
        {
            result[i][j] = mtr1[i][j] * mtr2[i][j];
        }
    }
    return result;
}

Matrix operator-(const Matrix& mtr1, const Matrix& mtr2)
{
    Matrix result(mtr1.get_length(), mtr1.get_width());
    for (size_t i = 0; i < mtr1.get_length(); i++)
    {
        for (size_t j = 0; j < mtr1.get_width(); j++)
        {
            result[i][j] = mtr1[i][j] - mtr2[i][j];
        }
    }
    return result;
}

int main()
{

    Matrix M(2,2);
    M.rand_matrix();
    M.print();
    cout << "\n-------------------------------------------\n" << endl;
    Matrix N(2, 2);
    N.rand_matrix();
    N.print();
    cout << "\n-------------------------------------------\n" << endl;
    Matrix G = M - N;
    G.print();

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
