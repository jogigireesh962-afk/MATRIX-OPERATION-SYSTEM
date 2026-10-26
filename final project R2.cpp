#include <iostream>
using namespace std;

#define MAX 10

// MODULE 1: MATRIX CLASS
class Matrix
{
private:
    int data[MAX][MAX];
    int rows, cols;

public:
    // Constructor
    Matrix(int r = 0, int c = 0)
    {
        rows = r;
        cols = c;
    }

    // MODULE 2: INPUT MATRIX
    void input()
    {
        cout << "Enter matrix elements:\n";

        for (int i = 0; i < rows; i++)
        {
            for (int j = 0; j < cols; j++)
            {
                cin >> data[i][j];
            }
        }
    }

    // MODULE 3: DISPLAY MATRIX
    void display() const
    {
        for (int i = 0; i < rows; i++)
        {
            for (int j = 0; j < cols; j++)
            {
                cout << data[i][j] << "\t";
            }
            cout << endl;
        }
    }

    // MODULE 4: MATRIX ADDITION
    Matrix addition(const Matrix &B) const
    {
        Matrix result(rows, cols);

        for (int i = 0; i < rows; i++)
        {
            for (int j = 0; j < cols; j++)
            {
                result.data[i][j] = data[i][j] + B.data[i][j];
            }
        }

        return result;
    }

    // MODULE 5: MATRIX MULTIPLICATION
    Matrix multiplication(const Matrix &B) const
    {
        Matrix result(rows, B.cols);

        for (int i = 0; i < rows; i++)
        {
            for (int j = 0; j < B.cols; j++)
            {
                result.data[i][j] = 0;

                for (int k = 0; k < cols; k++)
                {
                    result.data[i][j] +=
                        data[i][k] * B.data[k][j];
                }
            }
        }

        return result;
    }

    // MODULE 6: MATRIX TRANSPOSE
    Matrix transpose() const
    {
        Matrix result(cols, rows);

        for (int i = 0; i < rows; i++)
        {
            for (int j = 0; j < cols; j++)
            {
                result.data[j][i] = data[i][j];
            }
        }

        return result;
    }

    // MODULE 7: VALIDATION
    bool sameSize(const Matrix &B) const
    {
        return rows == B.rows && cols == B.cols;
    }

    bool canMultiply(const Matrix &B) const
    {
        return cols == B.rows;
    }
};

// MODULE 8: MAIN CONTROL MODULE
int main()
{
    int r1, c1, r2, c2, choice;

    cout << "   MATRIX OPERATIONS SYSTEM (OOP)   \n";

    cout << "\nEnter rows and columns of Matrix A: ";
    cin >> r1 >> c1;

    if (r1 <= 0 || c1 <= 0 || r1 > MAX || c1 > MAX)
    {
        cout << "Invalid Matrix A size!\n";
        return 0;
    }

    Matrix A(r1, c1);
    A.input();

    cout << "\nEnter rows and columns of Matrix B: ";
    cin >> r2 >> c2;

    if (r2 <= 0 || c2 <= 0 || r2 > MAX || c2 > MAX)
    {
        cout << "Invalid Matrix B size!\n";
        return 0;
    }

    Matrix B(r2, c2);
    B.input();

    do
    {
        cout << "\n========== MENU ==========\n";
        cout << "1. Matrix Addition\n";
        cout << "2. Matrix Multiplication\n";
        cout << "3. Transpose of Matrix A\n";
        cout << "4. Transpose of Matrix B\n";
        cout << "5. Display Matrices\n";
        cout << "6. Exit\n";
        cout << "Enter your choice: ";

        cin >> choice;

        switch (choice)
        {
            case 1:
                if (A.sameSize(B))
                {
                    Matrix C = A.addition(B);
                    cout << "\nAddition Result:\n";
                    C.display();
                }
                else
                {
                    cout << "Addition is not possible!\n";
                    cout << "Both matrices must have the same size.\n";
                }
                break;

            case 2:
                if (A.canMultiply(B))
                {
                    Matrix C = A.multiplication(B);
                    cout << "\nMultiplication Result:\n";
                    C.display();
                }
                else
                {
                    cout << "Multiplication is not possible!\n";
                    cout << "Columns of A must equal rows of B.\n";
                }
                break;

            case 3:
            {
                Matrix T = A.transpose();
                cout << "\nTranspose of Matrix A:\n";
                T.display();
                break;
            }

            case 4:
            {
                Matrix T = B.transpose();
                cout << "\nTranspose of Matrix B:\n";
                T.display();
                break;
            }

            case 5:
                cout << "\nMatrix A:\n";
                A.display();

                cout << "\nMatrix B:\n";
                B.display();
                break;

            case 6:
                cout << "\nProgram Ended Successfully!\n";
                break;

            default:
                cout << "\nInvalid choice! Please try again.\n";
        }

    } while (choice != 6);

    return 0;
}

