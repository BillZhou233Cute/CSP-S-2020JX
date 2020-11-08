#include<bits/stdc++.h>
using namespace std;
long long n,a[1000001],b[100001];
bool c[10001]={true};
long long t;
bool p=0;
int main()
{
	cin>>t;
	cin>>n;
	while(t>0)
	{
		if(p==0)
		{
			for(int i=1;i<=n;i++)
			{
				cin>>a[i];
			}
			p=1;
		}else {
			int k;
			cin>>k;
			for(int i=1;i<=k;i++)
			{
				int u,v;
				cin>>u>>v;
				a[u]=v;
			}
			sort(a+1,a+n+1);
			for(int i=n;i>=1;i--)
			{
				for(int j=1;j<=n;j++)
				{
					if(c[i]!=0&&c[j]!=0&&i!=j)
					{	
						if(a[i]-a[j]<a[i-1])
						{
							break;
						}else
							{
								a[i]=a[i]-a[j];
								c[j]=0;
							}
					}
				}
			}
			int l=0;
			for(int i=1;i<=n;i++)
			{
				
				if(c[i])
				l++;
			}
			cout<<l<<endl;
		}
	}
}