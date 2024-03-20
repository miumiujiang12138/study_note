#include <termio.h>
#include <stdio.h>
#include <iostream>
#include <sstream>
#include <string>

using std::cout;
using std::cin;
using std::endl;
using std::string;


void test(){
    system("stty -icanon");
    system("stty -isig");
    //system("stty -echoctl");
    //system("stty size");
    //禁用规范输入
    //无需按回车就可以将输入添加到缓冲区
    char buf;
    while(1){
        buf=getchar();
        if(buf=='\n'){
            system("ls -l");
            break;
        }
       cout<<"\b"<<buf<<"|"<<endl; 
    }
    system("stty icanon");
    system("stty isig");
    //启用规范输入
    

}
int scanKeyboard()
{
int in;
struct termios new_settings;
struct termios stored_settings;
tcgetattr(0,&stored_settings);
new_settings = stored_settings;
new_settings.c_lflag &= (~ICANON);
new_settings.c_cc[VTIME] = 0;
tcgetattr(0,&stored_settings);
new_settings.c_cc[VMIN] = 1;
tcsetattr(0,TCSANOW,&new_settings);
 
in = getchar();
 
tcsetattr(0,TCSANOW,&stored_settings);
return in;
}


int main()
{
#if 0
    while(1){
    printf(":%d",scanKeyboard());
    }
#endif 
    test();
    system("stty echoprt");
    string buf;
    cin>>buf;
    cout<<"||"<<buf<<"||\n";

    cin>>buf;
    cout<<"||"<<buf<<"||\n";
    return 0;
}
