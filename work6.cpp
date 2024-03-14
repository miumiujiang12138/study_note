#include <iostream>
#include <vector>   

using std::cout;
using std::endl;
using std::vector;


void sort_t(int * arr,int len){
    vector<int> v1;
    for(int i=0;i<len;++i){
        if(arr[i]%2==0){
            v1.push_back(arr[i]);
        }else{
            v1.insert(v1.begin(),arr[i]);
        }
    }
    int i=0;
    for(auto &num:v1){
        arr[i]=num;
        ++i;
    }
}

void display(int * arr,int len){
    for(int i=0;i<len;++i){
        cout<<arr[i]<<" ";
    }
    cout<<endl;
}


int main(int argc, char const *argv[])
{
    int arr[10]={1,7,2,3,13,29,48,28,32,10};
    display(arr,10);
    sort_t(arr,10);
    display(arr,10);
    return 0;
}
