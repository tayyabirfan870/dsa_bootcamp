#include<iostream>
using namespace std;
void changeA(int* ptr){
    *ptr=20;
}
int main(){
// // // // // //     int a=19;
// // // // // //     int* ptr=&a;
// // // // // //     int** parptr=&ptr;
// // // // // //     // cout<<ptr<<endl;
// // // // // //     // cout<<&a<<endl;
// // // // // //     // cout<<&ptr<<endl;
// // // // // //     // cout<<parptr<<endl;
// // // // // // cout<<*(&a)<<endl;
// // // // // // cout<<*ptr<<endl;
// // // // // // cout<<ptr<<endl;//adress print hoga a ka
// // // // // // cout<<*(parptr)<<endl;// parptr ki value print hogi jo k ptr ka address store h
// // // // // // cout<<parptr<<endl;
// // // // // // cout<<**parptr<<endl;
// // // // // int* ptr=NULL;
// // // // // cout<<ptr<<endl;
// // // // int a=5;
// // // // int *p=&a;
// // // // int** q=&p;
// // // // cout<<*p<<endl;
// // // // cout<<**q<<endl;
// // // // cout<<p<<endl;
// // // // cout<<*q<<endl;
// // // // cout<<&a<<endl;
// // // int a =10;
// // // cout<<a<<endl;
// // // changeA(&a);
// // // cout<<a<<endl;
// // int arr[5]={1,2,3,4,5};
// // cout<<arr<<endl;
// // cout<<*arr<<endl;
// int a=10;
// int* ptr=&a;
// cout<<ptr<<endl;
// //ptr+2;
// ptr++;
// cout<<ptr<<endl;
// ptr--;
// cout<<ptr<<endl;
// ptr=ptr+1;
// cout<<ptr<<endl;
int* ptr1;
int* ptr2=ptr1;
cout<<ptr1<<endl;
cout<<ptr2<<endl;
cout<<(ptr1 !=ptr2)<<endl;
    return 0;
}