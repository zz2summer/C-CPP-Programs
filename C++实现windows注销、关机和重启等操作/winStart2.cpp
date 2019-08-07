#include <iostream>
#include <string>
 
using namespace std;
 
void print()
{
     system( "CLS" );
     system( "title C++ 关机程序" );            //设置cmd窗口标题
     system( "mode con cols=52 lines=17" );     //窗口宽度高度
     cout << " **********************************************\n"
          << " *               C++实现win开始菜单           *\n"
          << " **********************************************\n"
          << " *      1.实现定时关闭计算机                  *\n"
          << " *      2.立即关闭计算机                      *\n"
          << " *      3.注销计算机                          *\n"
          << " *      4.重新启动计算机                      *\n"
          << " *      5.取消关机或注销操作(留意右下角提示)  *\n"
          << " *      0.退出系统                            *\n"
          << " **********************************************\n";
}
int main()
{
    string c;
    char cmds[ 25 ] = "shutdown -s -t 000000000";
    print();
    cin >> c;
    while( c != "0" )
    {
           while( c == "1" )
           {
                  int num;
                  cout << "Please enter the time: " << endl;
                  cin >> num;
                  for( int i = 0; i < 9; i++ )
                  {
                       cmds[ 23 - i ] = static_cast< char >( num % 10 + 48 );
                       num = num / 10;
                  }
                  system( cmds );
                  break;
           }
           while( c == "2" )
           {
                  system( "shutdown -p" );
                  break;
           }
           while( c == "3" )
           {
                  system( "shutdown -l" );
                  break;
           }
           while( c == "4" )
           {
                  system( "shutdown -r -t 0" );
                  break;
           }
           while( c == "5" )
           {
                  system( "shutdown -a" );
                  break;
           }
           print();
           cin >> c;
    }
    return 0;
}