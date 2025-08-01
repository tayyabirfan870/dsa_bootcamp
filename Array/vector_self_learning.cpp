#include<iostream>
using namespace std;
#include<vector>
#include<list>
int main(){
    // vector<int>vec;
    // cout<<"size before push back function = "<<vec.size()<<endl;
    // vec.push_back(25);
    // vec.push_back(50);
    // cout<<"size after push back function = "<<vec.size()<<endl;
    // cout<<"print staring value by front function vec.front(): "<<vec.front()<<endl;
    // cout<<"print last index value by back function vec.back() : "<<vec.back()<<endl;
    // cout<<"element at 1st index of vector  by syntax 1 vec[0] "<<vec[0]<<endl;
    // cout<<"alternate function of print value by syntax2 at index 2 vec.at(1) "<<vec.at(1)<<endl;
    // vec.pop_back();
    // cout<<"last element delete by vec.pop_back fuction so now ventor element "<<vec[0]<<endl;
    // cout<<"size after pop_back function = "<<vec.size()<<endl;
    // vector<char>vec_char(5,'A');
    // for(char i: vec_char){
    //     cout<<i<<endl;
    // }
    // vector<int>vec_int={1,2,3,4,5};
    // cout<<*vec_int.begin();
    // cout<<*(vec_int.end()-1);
    // cout<<vec_int.at(1)<<endl;
    // for(int i:vec_int){
    //     cout<<i<<endl;
    // }

    // vector<int>vec={1,2,3,4,5};
    // vector<int>:: iterator itr;
    // for(itr=vec.begin(); itr!=vec.end(); itr++){
    //     cout<<*(itr)<<" ";
    // }

    // for(vector<int>:: iterator itr=vec.begin(); itr!=vec.end(); itr++){
    //     cout<<*(itr)<<" ";
    // }

    // for(auto itr=vec.begin(); itr!=vec.end(); itr++){
    //     cout<<*(itr)<<" ";
    // }
    vector<int>vec={1,2,3,4,5};
       cout<<vec[3];
       list<int>l={1,2,3,4,5};

    l.push_front(0);
    l.pop_front();
        list<int>:: reverse_iterator itr;
    for(itr=l.rbegin(); itr!=l.rend(); itr++){
        cout<<*(itr)<<" ";
    }
    return 0;
}