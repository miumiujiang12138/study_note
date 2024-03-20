#include <iostream>
#include <queue>
#include <vector>
#include <functional>
#include <complex>


using std::cout;
using std::endl;
using std::priority_queue;
using std::vector;

void test(){

    priority_queue<int> pq1;
    pq1.push(5);
    cout<<"pq1.size()="<<pq1.size()<<endl;

    priority_queue<int> pq2{pq1};
    cout<<"pq2.size()="<<pq2.size()<<endl;

    vector<int> vec{3,1,4,1,5};
    priority_queue<int> pq3{std::less<int>(),vec};
    cout<<"pq3.size()="<<pq3.size()<<endl;



}



int main()
{
    test();
    return 0;
}

