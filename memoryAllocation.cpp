#include<iostream>
using namespace std;

int main(){

    // compile time: allocation + deallocation = done by compiler
    int arr[10]={0};
    cout<<arr<<endl;


    // Dynamic: allocation + deallocation = done by programmer
    int n;
    cin>>n;
    int* ptr=new int[n]{0};
    for (int i = 0; i < n; i++)
    {
        cin>>ptr[i];
    }
    cout<<*(ptr+1)<<endl;
    
    delete[] ptr;


    return 0;
}



