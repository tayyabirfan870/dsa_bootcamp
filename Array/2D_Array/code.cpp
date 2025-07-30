#include<iostream>
using namespace std;
int main(){
    int matrix[2][3]={{1,2,3},{4,5,6}};
    int rows=2;
    int columns=3;
    for(int i=0; i<rows; i++){
        for(int j=0; j<columns; j++){
            cout<<matrix[i][j]<<" ";
        }
        cout<<endl;
    }
    return 0;
}