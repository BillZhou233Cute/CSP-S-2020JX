#include<bits/stdc++.h>
using namespace std;
int main()
{
	//freopen("snakes.in","r","stdin");
	//freopen("snakes.out","w","stdout");
	int t,n,m,k;
	int no[100005],ni[100005],nj[100005];
	int i,j,x,y;
	cin>>t;
	cin>>n;
	m=n;
	for(i=0;i<n;i++)
	{
		cin>>no[i];
		ni[i]=no[i];
		nj[i]=i;
	}
	while(t>1)
	{
		if(m==1)
		cout<<m;
		else
		{
		for(i=0;i<n;i++)
		{
			for(j=i;j<n;j++)
			{
				if(ni[i]<=ni[j]&&nj[i]>nj[j])
				{
					swap(ni[i],ni[j]);
					swap(nj[i],nj[j]);
				}
			}
		}
		while(ni[0]-ni[m-1]>=ni[1]&&nj[0]>nj[m-1])
		{
			ni[0]-=ni[m-1];
			no[nj[m-1]]=-1;
			m--;
		}
		cout<<m;
		cin>>k;
		for(i=0;i<k;i++)
		{
			cin>>x>>y;
			if(no[x]!=-1)
			no[x]=y;
		}
		for(i=0;i<n;i++)
		{
			ni[i]=no[i];
		}
		for(i=0;i<n;i++)
		{
			for(j=i;j<n;j++)
			{
				if(ni[i]<ni[j])
				{
					swap(ni[i],ni[j]);
					swap(nj[i],nj[j]);
				}
			}
		}
		}
		t--;
	}
	cout<<m;
	//fclose("stdin");
	//fclose("stdout");
	return 0;
}