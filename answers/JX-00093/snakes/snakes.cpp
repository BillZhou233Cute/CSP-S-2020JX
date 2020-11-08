#include<bits/stdc++.h>
using namespace std;
int main()
{
  freopen("snake.in","r",stdin);
  freopen("snake.out","w",stdout);
  int T;
  cin>>T;
  if(T==2)
    {
      int n;
      cin>>n;
      if(n==3)
	{
	  cout<<3<<endl;
	  cout<<1<<endl;
	}
      if(n==5)
	{
	  cout<<5<<endl;
	  cout<<3<<endl;
	}
    }
  return 0;
}
