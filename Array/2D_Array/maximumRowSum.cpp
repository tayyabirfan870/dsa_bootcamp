#include<iostream>
using namespace std;
int MaxRowSum(int matrix[][3], int rows, int columns) {
    int maxRowSum =INT32_MIN;
        for(int i=0; i<rows; i++){
            int sum=0;
        for(int j=0; j<columns; j++){
                sum+=matrix[i][j];
            }
            if(sum>maxRowSum){
                maxRowSum=sum;
            }
        }
        return maxRowSum;
    }
int main(){
    int matrix[2][3]={{1,2,18},{4,5,6}};
    int rows=2;
    int columns=3;
    cout<<MaxRowSum(matrix,rows, columns)<<endl;
    return 0;
}