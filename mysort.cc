#include <iostream>
#include <vector>
#include <functional>
#include <algorithm>


using std::cout;
using std::endl;
using std::vector;
using std::sort;

//有误，如果a==b,a^=b为0
#define SWAP(a, b) do{a^=b;b^=a;a^=b;}while(0)

template <typename T,typename Compare=std::less<T> >
class MyQsort{
public:
    MyQsort(T *arr,size_t size,Compare com);
    void quick(int left,int right,Compare &com);
    int partition(int left,int right,Compare &com);
    void print();
private:
    vector<T> _vec;
};

template <typename T ,typename Compare >
MyQsort<T,Compare>::MyQsort(T*arr,size_t size,Compare com)
:_vec()
{
    _vec.clear();
    for(int i=0;i<size;++i){
        _vec.push_back(arr[i]);
    }
    quick(0,size-1,com);

}
template <typename T ,typename Compare>
void MyQsort<T,Compare>::quick(int left,int right,Compare &com){
    int pivot;
    if(left<right){
        pivot=partition(left,right,com);
        quick(left,pivot-1,com);
        quick(pivot+1,right,com);
    }
}

inline void SWAP2(int &a,int &b){int tmp=a;a=b;b=tmp;}


//无法完成值交换
inline void SWAP3(int a,int b){int tmp=a;a=b;b=tmp;}

template <typename T ,typename Compare>
int MyQsort<T,Compare>::partition(int left,int right,Compare &com){
    int i;
    int k=left;
    int tmp;
    for(i=left;i<right;++i){
        if(com(_vec[i],_vec[right])){
            print();
            //cout<<k<<"(k)"<<_vec[k]<<","<<_vec[i]<<"(i)"<<i<<endl;
#if 0
            tmp=_vec[k];
            _vec[k]=_vec[i];
            _vec[i]=tmp;
#endif
            SWAP2(_vec[k],_vec[i]);
            
            ++k;
        }
    }
    print();
    //cout<<k<<"(k)"<<_vec[k]<<","<<_vec[right]<<"(r)"<<right<<endl;
#if 0
    tmp=_vec[right];
    _vec[right]=_vec[k];
    _vec[k]=tmp;
#endif
    SWAP2(_vec[k],_vec[right]);

    return  k;

}


template <typename T ,typename Compare>
void MyQsort<T,Compare>::print(){
    for(auto &c:_vec){
        cout<<c<<" ";
    }
    cout<<endl;
}

int main(){

    std::less<int> cmp;
    int arr[10]={4,2,8,3,5,2,7,1,3,13};

    MyQsort<int> sq1(arr,10,cmp);
    sq1.print();
#if 0
    cout<<cmp(3,0)<<endl;
    cout<<cmp(0,3)<<endl;
    cout<<cmp(0,0)<<endl;
    //cmp(a,b)->a<b
#endif
    return 0;
}
