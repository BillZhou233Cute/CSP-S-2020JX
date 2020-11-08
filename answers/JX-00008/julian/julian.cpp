#include<bits/stdc++.h>
using namespace std;
int a[]={0,31,28,31,30,31,30,31,31,30,31,30,31};
int n,y,r;
void work()
{
	int data;
	scanf("%d",&data);
	y=1;	
	data++;
	n=0;
	if(data<=1721424)
	{
		n=data/1461*4;
		if(data<1461&&data>365)data--;

		data%=1461;
		n+=data/365;
		data%=365;
		int k=n%4;
		if(!k)a[2]++;
		for(int i=1;i<=12;i++)
			if(data>a[i])
			{
				data-=a[i];
				y=i+1;
			}
			else break;
		if(!k)a[2]--;
		n-=4713;
	}
	else 
	if(data<=2299238)
	{
		data-=1721424;
		n=data/1461*4;
		data%=1461;
		n+=data/365;
		data%=365;
		int k=n%4;
		int w=0;
		if(n==1582)w=1;
		if(w)a[10]=21;
		if(!k)a[2]++;
		for(int i=1;i<=12;i++)
			if(data>a[i])data-=a[i],y=i+1;
				else break;
		if(!k)a[2]--;
		if(w&&y>=10&&data>=5)data+=10;		
		for(int i=y;i<=12;i++)
			if(data>a[i])data-=a[i],y=i+1;
				else break;
		if(w)a[10]=31;
	}
	else 
	{
		data+=10;
		data-=1721424;
		n=(data/146099)*400;
		data%=146099;
		n+=data/1461*4;
		data%=1461;
		n+=data/365;
		data%=365;
		int k=0;
		if(n%4==0&&(n%400)>0)k=1;
		if(k)a[2]++;
		for(int i=1;i<=12;i++)
			if(data>a[i])data-=a[i],y=i+1;
		if(k)a[2]--;
	}
	if(data==0)data=1,y--;
	if(y==0)y=12,n--;
	if(n==0)n=1;
	if(n<0)printf("%d %d %d BC\n",data,y,-n);
	else printf("%d %d %d\n",data,y,n);
}
int main()
{	
	freopen("julian.in","r",stdin);
	freopen("julian.out","w",stdout);
	int q;
	scanf("%d",&q);
	for(int i=1;i<=q;i++)
		work();
  return 0;
}
