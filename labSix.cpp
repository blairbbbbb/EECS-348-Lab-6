#include <iostream>
#include <fstream>
#include <iomanip> //For std::setw

#define N 3

using namespace std;

void readMatrixFromFile(const char* filename, int matrix1[N][N], int matrix2[N][N]) {
    fstream file(filename);
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

void addMatrix (const int matrix1[N][N],const int matrix2[N][N]){
    int result[N][N];
    cout << "Adding Matrices...\n";
    for (int i = 0; i<N; ++i){
        for (int j=0; j<N; ++j){
            result[i][j] = matrix1[i][j] + matrix2[i][j];
        }
    }
    printMatrix (result);
}

void multiplyMatrix (const int matrix1[N][N], const int matrix2[N][N]){
    int result[N][N];
    cout << "Multiplying Matrices...\n";
    for (int i = 0; i<N; ++i){
        for (int j=0; j<N; ++j){
            result[i][j] = matrix1[i][j] * matrix2[i][j];
        }
    }
    printMatrix (result);
}

void subtractMatrix(const int matrix1[N][N], const int matrix2[N][N]){
    int result[N][N];
    cout << "Subtracting Matrices...\n";
    for (int i = 0; i<N; ++i){
        for (int j=0; j<N; ++j){
            result[i][j] = matrix1[i][j] - matrix2[i][j];
        }
    }
    printMatrix (result);
}

void updateElem(int matrix[N][N]){
    int row;
    int col;
    int newVal;

    cout << "Enter the row you want to update: ";
    cin >> row;

    cout << "Enter the column you want to update: ";
    cin >> col;

    cout << "Enter the new number: ";
    cin >> newVal;

    if (row>= 0 && row < N && col>= 0 && col < N){
        matrix[row-1][col-1] = newVal; //should i keep the -1??
        printMatrix(matrix);
    }else{
        cout << "Invalid row or column index" <<endl;
    }
}



int main() {
    int matrix1[N][N], matrix2[N][N]; //, resultMatrix[N][N];

    //Assuming matrix_input.txt format is valid and contains 2*N*N integers
    readMatrixFromFile("matrix_input.txt", matrix1, matrix2);
    
    printMatrix(matrix1);
    printMatrix(matrix2);

    addMatrix(matrix1, matrix2);

    multiplyMatrix(matrix1, matrix2);

    subtractMatrix(matrix1, matrix2);

    updateElem(matrix1);

    return 0;
}
