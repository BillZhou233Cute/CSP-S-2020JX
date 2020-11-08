#include<iostream>
#include<algorithm>
#include<cstdio>
#include<string>
#include<cmath>
using namespace std;
int hs[11401][501],num1[30000],n,m;
void jf(int x,int y)
{num1[x]=num1[x]+y;}
void cf(int z)
{for(int i=1;i<=n;i++)
	num1[i]=num1[i]*z;}
int main()
{
	freopen("call.in","r",stdin);
	freopen("call.ans","w",stdout);
	cin>>n;
	for(int i=1;i<=n;i++)
	{
		cin>>num1[i];
	}
	cin>>m;
	int jj=1,cc=1,hd=1;
	for(int i=1;i<=m;i++)
	{
		int f;
		cin>>f;
		if(f==1)
		{
			cin>>hs[i][1]>>hs[i][2];
			hs[i][0]=1;

		}
		if(f==2)
		{
			cin>>hs[i][1];
			hs[i][0]=2;
		}
		if(f==3)
		{int xxx;
			cin>>xxx;
			for(int j=2;j<=xxx+1;j++)
			{
				cin>>hs[i][j];
			}
			hs[i][1]=xxx;hs[i][0]=3;
		}
	}
	int gb,ph;
	cin>>gb;
	for(int i=1;i<=gb;i++)
	{cin>>ph;
	if(hs[i][0]==1)jf(hs[i][1],hs[i][2]);
	if(hs[i][0]==2)cf(hs[i][1]);
	if(hs[i][0]==3)
	for(int j=1;j<=hs[i][1];j++)
	{if(hs[hs[i][j+1]][0]==1)
		jf(hs[hs[i][j+1]][1],hs[hs[i][j+1]][2]);
	if(hs[hs[i][j+1]][0]==2)
		cf(hs[hs[i][j+1]][1]);
	}
	}
	for(int i=1;i<=n;i++)
	cout<<num1[i]<<" ";
   fclose(stdin);
	fclose(stdout);
	return 0;
}
