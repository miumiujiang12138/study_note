#include <vector>
#include <string>
#include <iostream>
#include <algorithm>

using std::cout;
using std::endl;
using std::vector;
using std::string;
using std::swap;



template <typename T,typename Compare=std::less<T> >
class HeapSort
{
public:
    HeapSort(T*arr,size_t size,Compare com);
    void heapAdjust(size_t parent, size_t size,Compare &com);
    void sort(Compare &com);
    void print();
private:
    vector<T> vec;
};


template <typename T,typename Compare>
HeapSort<T,Compare>::HeapSort(T* arr,size_t size,Compare com){
    vec.reserve(size);
    for(size_t i=0;i<size;++i){
        vec.push_back(arr[i]);
    }

    for(int i=(vec.size()-2)/2;i>=0;--i){
        heapAdjust(i,vec.size(),com);
    }
    sort(com);
}


template <typename T,typename Compare>
void HeapSort<T,Compare>::heapAdjust(size_t parent,size_t size,Compare &com){
    size_t child;
    child=parent*2+1;
    while (child<size)
    {
        if((size!=child+1)&&(com(vec[child],vec[child+1]))){
            ++child;
        }
        if(com(vec[parent],vec[child])){
            swap(vec[child],vec[parent]);
            parent=child;
            child=parent*2+1;
        }else{
            break;
        }
    }
 
}

template <typename T,typename Compare>
void HeapSort<T,Compare>::sort(Compare &com){
    for(size_t i= vec.size();i>1;--i){
        for(int k=(i-1-2)/2;k>=0;--k){
            heapAdjust(k,i-1,com);
        }
        swap(vec[0],vec[i-1]);
    }
}

template <typename T,typename Compare>
void HeapSort<T,Compare>::print(){
    for(auto &c:vec){
        cout<<c<<" ";
    }
    cout<<endl;
}


void display(int* arr,int len,string msg){
    cout<<msg;
    for(int i=0;i<len;++i){
        cout<<arr[i]<<" ";
    }
    cout<<endl;
}


int main()
{
    std::less<int> cmp;
    int arr[10]={4,5,1,3,11,2,9,8,4,0};
    display(arr,sizeof(arr)/sizeof(int),"arr:");
    HeapSort<int> Hsort(arr,sizeof(arr),cmp);
    Hsort.print();

    return 0;
}

