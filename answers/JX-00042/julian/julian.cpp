#include<iostream>
#include<cstdio>
using namespace std;
int n,ri[100005],yue[13]={31,28,31,30,31,30,31,31,30,31,30,31},bc[2000000],temp1=0,temp2=0,cnt=0,y=0,m=0;
int main()
{
    //freopen("julian.in","r",stdin);
    freopen("julian.out","w",stdout);
	cin>>n;
	bc[0]=365;
	for(int i=0;i<1721386;i++)
		if((i%4==0&&i%100!=0)||i%400==0)
			bc[i+1]=366;
			else
			bc[i+1]=365;
	for(int i=0;i<n;i++)
	{
		cin>>ri[i];
		ri[i]++;
		while(y+bc[temp1]<ri[i])
		{
			y+=bc[temp1];
			temp1++;
			}
		ri[i]-=y;
		while(m+yue[temp2]<ri[i])
		{
			m+=yue[temp2];
			temp2++;
			}
		ri[i]-=m;
		cout<<ri[i]<<" "<<temp2+1<<" "<<4714-temp1<<" BC"<<endl; 
			y=0;m=0;temp1=0;temp2=0;
		}
}