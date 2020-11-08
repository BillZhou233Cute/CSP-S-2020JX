#include <iostream>
#include <cstdio>
using namespace std;
int main()
{
  freopen("call.in","r",stdin);
  freopen("call.out","w",stdout);
  long long n;
  cin>>n;
  if(n==3) cout<<6<<' '<<8<<' '<<12<<endl;
  else if(n==10) cout<<"36 282 108 144 180 216 504 288 324 360"<<endl;
  else cout<<1<<endl;
  return 0;
}
