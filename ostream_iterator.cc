#include <head.h>
#include <iostream>
#include <sstream>
#include <iterator>
#include <vector>
#include <string>
#include <algorithm>

using std::cout;
using std::cin;
using std::endl;
using std::iterator;
using std::vector;
using std::string;
using std::ostream_iterator;
using std::istream_iterator;
using std::istringstream;
using std::copy;

int main()
{
    vector<int> v1={1,2,3,4,5};
    vector<string>v2;
    system("stty -icanon");
    char arr[2]={'a','b'};
    string str(arr);
    cout<<str<<endl;
    ostream_iterator<string> osi{cout,"|"};
    
    istream_iterator<string> isi{cin};
    
    //copy(v1.begin(),v1.end(),osi);

    copy(isi,istream_iterator<string>(),osi);
    


    return 0;
}

