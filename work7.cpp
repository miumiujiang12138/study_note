#include <iostream>
#include <vector>

using std::cout;
using std::endl;
using std::vector;

int missing_N(int* arr,int len){
   vector<int> v1(len,0);
    for(int i=0;i<len;++i){
        if(arr[i]>0&&arr[i]<len){
            v1[(arr[i]-1)]+=1;
        }
    }
    for(int i=0;i<len;++i){
        if(v1[i]==0){
           return i+1; 
        }
    }
    return len;
}


int main(int argc, char const *argv[])
{
    //获取下列数组所缺失的第一个正数
    int nums1[3]={1,2,0};
    int nums2[4]={3,4,-1,1};
    int nums3[5]={7,8,9,11,12};

    cout<<missing_N(nums1,3)<<endl;
    cout<<missing_N(nums2,4)<<endl;
    cout<<missing_N(nums3,5)<<endl;

    return 0;
}
