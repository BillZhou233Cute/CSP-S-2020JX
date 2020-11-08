#include<bits/stdc++.h>
using namespace std;
long long int n,m,l,ans,countt=1;
int a[100001],b[64],c[100001][2];
int find(int x,int s)
{
	int k;
	for(k=1;k<=s;k++)
	x=x/2;
	return x%2;
}
int search(int x)
{
	int k;
	for(k=1;k<=m;k++)
		{
			if(c[k][0]==x&&b[c[k][1]]==0)
			{return 0;}
		}
		return 1;
}
int main()
{	
	freopen("zoo.in","r",stdin);
	freopen("zoo.out","w",stdout);
	int i,j;
	cin>>n>>m>>l>>ans;
	for(i=1;i<=n;i++)
	{
		cin>>a[i];
	}
	for(i=1;i<=m;i++)
	{
		cin>>c[i][0]>>c[i][1];
	}

	for(i=1;i<=n;i++)
        for(j=1;j<=m;j++)
	{
  
		if(find(a[i],c[j][0])==1)
		b[c[j][1]]=1;
	}
	
	for(i=1;i<=ans;i++)
	{
		if(search(i)==1)
                {                                               
                        countt=countt*2;	
				}
			else
				countt=countt;
	}
        cout<<countt-n;
	fclose(stdin);
	fclose(stdout);
	return 0;
}



















