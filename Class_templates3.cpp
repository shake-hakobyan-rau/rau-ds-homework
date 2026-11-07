#include <iostream>
#include <string>

template <typename T, int N, int M>
class Matrix {
private:
T data[N] [M];
public:
Matrix(){
for(int i = 0; i < N; i++){

    for(int j = 0; j < M; j++){
       data[i] [j] = 0;
     }
     } 
     }
       void set(int row, int col, T value){
        data[row][col] = value;
       }
       T get(int row, int col){
        return data[row][col];
       }
       void print(){
       for(int i = 0; i < N; i++){
            for(int j = 0; j < M; j++){
        std::cout << data[i][j] << " ";
            }
            std::cout << std::endl;
        }
       std::cout << std::endl;
    }
    Matrix<T, N, M> operator+(const Matrix<T, N, M>& other) {
        Matrix<T, N, M> result;
        for(int i = 0; i < N; i++){
        for(int j = 0; j < M; j++){
            result.data[i][j] = this->data[i][j] + other.data[i][j];   
    }
}
    return result;
}
};
int main(){
Matrix <int, 2, 2> A;
Matrix <int, 2, 2> B;
A.set(0, 0, 1); A.set(0, 1, 2);
A.set(1, 0, 3); A.set(1, 1, 4);
B.set(0, 0, 5); B.set(0, 1, 6);
B.set(1, 0, 7); B.set(1, 1, 8);
std::cout << "Matrix A: " << std::endl;
A.print();
std::cout << "Matrix B: " << std::endl;
B.print();
Matrix<int, 2, 2> C = A + B;
std::cout << "Matrix C(A + B): " << std::endl;
C.print();
return 0;   
}