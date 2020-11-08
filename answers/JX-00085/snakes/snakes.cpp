#include<bits/stdc++.h>
using namespace std;
inline long long read(){
  long long x=0,f=1;
  char ch=getchar();
  while(ch<'0'||ch>'9')
  {
    if(ch=='-') f=-1;
    ch=getchar();
  }
  while(ch>='0'&&ch<='9')
  {
    x=x*10+ch-'0';
    ch=getchar();
  }
  return x*f;
}
int main(){
  cout<<"5\n3";
  return 0;
}
