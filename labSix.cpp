#include <iostream>
#include <fstream>
#include <iomanip> //For std::setw

#define N 3

using namespace std;

void readMatrixFromFile(const char* filename, int matrix1[N][N], int matrix2[N][N]) {
    ifstream file(filename);
    if (file.is_open()) {
        //Read the first matrix (first 3 rows)
        for (int i = 0; i < N; ++i) {
            for (int j = 0; j < N; ++j) {
                file >> matrix1[i][j];
            }
        }
        //Read the second matrix (next 3 rows)
        for (int i = 0; i < N; ++i) {
            for (int j = 0; j < N; ++j) {
                file >> matrix2[i][j];
            }
        }
        file.close();
    } else {
        cout << "Unable to open file." << endl;
    }
}

void printMatrix(int matrix[N][N]) {
    cout << "Printing Matrix...\n";
    for (int i = 0; i < N; ++i) {
        for (int j = 0; j < N; ++j) {
            cout << setw(5) << matrix[i][j];
        }
        cout << endl;
    }
}

int main() {
    int matrix1[N][N], matrix2[N][N], resultMatrix[N][N];
    
    //Assuming matrix_input.txt format is valid and contains 2*N*N integers
    readMatrixFromFile("matrix_input.txt", matrix1, matrix2);
    
    printMatrix(matrix1);
    printMatrix(matrix2);

    return 0;
}
