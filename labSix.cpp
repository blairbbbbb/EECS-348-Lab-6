#include <iostream>
#include <fstream>
#include <iomanip> //For std::setw
#include <vector>

using namespace std;

using Matrix = vector<vector<int>>;

//Function to get the size of the matrices by counting the elements in the first row
int getSize(const char* filename) {
    fstream file(filename);
    string line;
    int size = 0;
    if (file.is_open()) {
        //Only read the first line
        if (getline(file, line)) {
            stringstream ss(line);
            int temp;
            while (ss >> temp) {
                ++size; //Count each number in the first row
            }
        }
        file.close();
    } else {
        cout << "Unable to open file to read size." << endl;
    }
    return size; //The size is the number of elements in the first row
}

void readMatrixFromFile(const char* filename, Matrix& matrix1, Matrix& matrix2) {
    int size = getSize(filename); //Determine the size of the matrices first
    fstream file(filename);
    if (file.is_open()) {
        matrix1.resize(size, vector<int>(size));
        matrix2.resize(size, vector<int>(size));

        //Read the first matrix
        for (int i = 0; i < size; ++i) {
            for (int j = 0; j < size; ++j) {
                file >> matrix1[i][j];
            }
        }
        //Read the second matrix
        for (int i = 0; i < size; ++i) {
            for (int j = 0; j < size; ++j) {
                file >> matrix2[i][j];
            }
        }
        file.close();
    } else {
        cout << "Unable to open file for reading matrices." << endl;
    }
}

void printMatrix(const Matrix& matrix) {
    cout << "Printing Matrix...\n";
    for (const auto& row : matrix) {
        for (const auto& elem : row) {
            cout << setw(5) << elem;
        }
        cout << "\n";
    }
}

void addMatrix(const Matrix& matrix1, const Matrix& matrix2) {
    int size = matrix1.size();
    Matrix result(size, vector<int>(size));
    cout << "Adding Matrices...\n";
    for (int i = 0; i < size; ++i) {
        for (int j = 0; j < size; ++j) {
            result[i][j] = matrix1[i][j] + matrix2[i][j];
        }
    }
    printMatrix(result);
}

void multiplyMatrix(const Matrix& matrix1, const Matrix& matrix2) {
    int size = matrix1.size();
    Matrix result(size, vector<int>(size, 0)); //Initialize with 0 for multiplication
    cout << "Multiplying Matrices...\n";
    for (int i = 0; i < size; ++i) {
        for (int j = 0; j < size; ++j) {
            for (int k = 0; k < size; ++k) {
                result[i][j] += matrix1[i][k] * matrix2[k][j];
            }
        }
    }
    printMatrix(result);
}

void subtractMatrix(const Matrix& matrix1, const Matrix& matrix2) {
    int size = matrix1.size();
    Matrix result(size, vector<int>(size));
    cout << "Subtracting Matrices...\n";
    for (int i = 0; i < size; ++i) {
        for (int j = 0; j < size; ++j) {
            result[i][j] = matrix1[i][j] - matrix2[i][j];
        }
    }
    printMatrix(result);
}

void updateElem(Matrix& matrix) {
    int row, col, newVal;
    cout << "Enter the row you want to update: ";
    cin >> row;
    cout << "Enter the column you want to update: ";
    cin >> col;
    cout << "Enter the new number: ";
    cin >> newVal;

    if (row >= 1 && row <= matrix.size() && col >= 1 && col <= matrix[0].size()) {
        matrix[row - 1][col - 1] = newVal;
        printMatrix(matrix);
    } else {
        cout << "Invalid row or column index" << endl;
   
    }
}

int main() {
    Matrix matrix1, matrix2; 

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
