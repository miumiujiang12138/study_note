#include <iostream>
#include <vector>

using std::cout;
using std::endl;
using std::vector;



void test(){
    vector<int> number={1,4,5,2,9};
    for(auto &c:number){
        cout<<c<<" ";
    }
    cout<<endl;

    auto rit=number.rbegin();
    while(rit!=number.rend()){
        cout<<*rit<<" ";
        ++rit;
    }
    cout<<endl;
}



int main()
{
    test();
    return 0;
}

