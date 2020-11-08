#include<iostream>
#include<cstdio>
using namespace std;
int m[13]={0,31,29,31,30,31,30,31,31,30,31,30,31};
int q,r;
int main()
{
  freopen("julian.in","r",stdin);
  freopen("julian.out","w",stdout);
  cin>>q;
  while(q--)
  {
	int da=1,mo=1;
    cin>>r;
    for(int i=1;i<=12;i++)
    {
	r-=m[i],mo++;
      if(!r) 
{
	r+=m[i];
	mo--;
	printf("%d %d 4713 BC\n",r,mo);
}
 }	
}
  return 0;
}
