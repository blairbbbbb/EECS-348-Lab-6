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

//Function to read the two matrices from a file.
void readMatrixFromFile(const char* filename, Matrix& matrix1, Matrix& matrix2) {
    int size = getSize(filename); //Determine the size of the matrices first.
    fstream file(filename);
    if (file.is_open()) {
        matrix1.resize(size, vector<int>(size));
        matrix2.resize(size, vector<int>(size));

        //Read the first matrix.
        for (int i = 0; i < size; ++i) {
            for (int j = 0; j < size; ++j) {
                file >> matrix1[i][j];
            }
        }
        //Read the second matrix.
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

//Function to print a matrix.
void printMatrix(const Matrix& matrix) {
    cout << "Printing Matrix...\n";
    for (const auto& row : matrix) {
        for (const auto& elem : row) {
            cout << setw(5) << elem;
        }
        cout << "\n";
    }
}

//Function to add two matrices. 
void addMatrix(const Matrix& matrix1, const Matrix& matrix2) {
    int size = matrix1.size();
    Matrix result(size, vector<int>(size));
    cout << "\nAdding Matrices...\n";
    for (int i = 0; i < size; ++i) {
        for (int j = 0; j < size; ++j) {
            result[i][j] = matrix1[i][j] + matrix2[i][j];
        }
    }
    printMatrix(result);
}

//Function to multiply two matrices. 
void multiplyMatrix(const Matrix& matrix1, const Matrix& matrix2) {
    int size = matrix1.size();
    Matrix result(size, vector<int>(size, 0)); //Initialize with 0 for multiplication
    cout << "\nMultiplying Matrices...\n";
    for (int i = 0; i < size; ++i) {
        for (int j = 0; j < size; ++j) {
            for (int k = 0; k < size; ++k) {
                result[i][j] += matrix1[i][k] * matrix2[k][j];
            }
        }
    }
    printMatrix(result);
}

//Function to subtract the second matrix from the first matrix. 
void subtractMatrix(const Matrix& matrix1, const Matrix& matrix2) {
    int size = matrix1.size();
    Matrix result(size, vector<int>(size));
    cout << "\nSubtracting Matrices...\n";
    for (int i = 0; i < size; ++i) {
        for (int j = 0; j < size; ++j) {
            result[i][j] = matrix1[i][j] - matrix2[i][j];
        }
    }
    printMatrix(result);
}

//Function to update an element in the matrix specified by the user. 
void updateElem(Matrix& matrix) {
    int row, col, newVal;
    cout << "\nEnter the row you want to update: ";
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

//Function to print the max value in matrix 1
void printMaxValue(Matrix& matrix){
    //Initialize max with the first element of the matrix.
    int max = matrix[0][0];
    //Iterate through the matrix to find the max value.
    for (const auto& row : matrix){
        for (const auto& elem : row){
            if(elem>max){
                max = elem; //Update the max if a larger value is found.
            }
        }
    }
    cout << "\nMaximum value in the first matrix: "<< max << endl;
}

//Function to transpose matrix 1. 
void transposeMatrix(const Matrix& matrix){
    size_t rows = matrix.size();
    Matrix transpose(rows, vector<int>(rows));

    for (size_t i = 0; i < rows; ++i){
        for (size_t j = 0; j < rows; ++j){
            transpose[j][i]=matrix[i][j];
        }
    }
    cout << "\nTransposing Matrix...\n";
    printMatrix(transpose);
}

int main() {
    Matrix matrix1, matrix2; 

    readMatrixFromFile("matrix_input.txt", matrix1, matrix2);
    
    printMatrix(matrix1);
    printMatrix(matrix2);

    addMatrix(matrix1, matrix2);

    multiplyMatrix(matrix1, matrix2);

    subtractMatrix(matrix1, matrix2);

    updateElem(matrix1);

    printMaxValue(matrix1);

    transposeMatrix(matrix1);

    return 0;
}
