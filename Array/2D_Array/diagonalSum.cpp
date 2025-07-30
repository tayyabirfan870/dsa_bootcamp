#include<iostream>
using namespace std;
int getDiagonalSum(int matrix[][3], int n) {
    int sum=0;
        for(int i=0; i<n; i++){
        for(int j=0; j<n; j++){
            if(i==j){
                sum+=matrix[i][j];
            }else if(i+j==n-1){
                sum+=matrix[i][j];
            }
            }
        }
        return sum;
    }
    int getDiagonalSumOptimized(int matrix[][3], int n){
            int sum=0;
        for(int i=0; i<n; i++){
                sum+=matrix[i][i];
                 if(i!=n-i-1){
                sum+=matrix[i][n-i-1];
            }
            }
        return sum;

    }
int main(){
    int matrix[3][3]={{1,2,3},{4,5,6},{7,8,9}};
    int n=3;
    cout<<getDiagonalSum(matrix,n)<<endl;
    cout<<getDiagonalSumOptimized(matrix, n)<<endl;
    return 0;
}