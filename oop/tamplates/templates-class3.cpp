#include <iostream>
#include <string>
template <typename T, int N, int M>
 class Matrix{
    T mat[N][M];
    
 public:
    Matrix(){
        for(int i = 0; i < N; i++){
            for(int j = 0; j < M; j++){
                mat[i][j] = T();
            }
        }
    }
    
    void set (int row, int col, T value){
        if(row < 0 || row >= N || col < 0 || col >= M){
            std:: cout << "Error";
            return;
        }
        mat[row][col] = value;
    }
    
    T get(int row, int col){
        if(row < 0 || row >= N || col < 0 || col >= M){
            std:: cout << "Error";
            return T();
        }
        return mat[row][col];
    }
    
    void print(){
        for(int i = 0; i < N; i++){
            for(int j = 0; j < M; j++){
                std:: cout << mat[i][j] << " ";
            }
        }
        std:: cout << std:: endl;
    }
    
    Matrix operator+(const Matrix& other){
        Matrix result;
        for(int i = 0; i < N; i++){
            for(int j = 0; j < M; j++){
                result.mat[i][j] = mat[i][j] + other.mat[i][j];
            }
        }
        return result;
    }
};

int main()
{
    Matrix<int, 2, 3> A;
    A.set(0, 0, 1);
    A.set(0, 1, 2);
    A.set(0, 2, 3);
    A.set(1, 0, 4);
    A.set(1, 1, 5);
    A.set(1, 2, 6);
    A.print();
    

Matrix<int, 2, 3> B;
    B.set(0, 0, 10);
    B.set(0, 1, 20);
    B.set(0, 2, 30);
    B.set(1, 0, 40);
    B.set(1, 1, 50);
    B.set(1, 2, 60);
    B.print();
    
    
    Matrix<int, 2, 3> C = A + B;
    C.print();
    return 0;
}
