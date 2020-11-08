#include<iostream>
#include<algorithm>
using namespace std;
int T,n,k,x,y,c,head,tail;
int a[10005];
void xy()
{
int j;
		for(j=head;j<=(tail+head)/2;j++)
	{
		c=a[j];
		a[j]=a[tail-j+1];
		a[tail-j+1]=c;
	}
}
void xx()
{
int i;
		for(i=1;i<=n/2;i++)
	{
		c=a[i];
		a[i]=a[n-i+1];
		a[n-i+1]=c;
	}
}
int solve()
{
	int j;
	int bj=0;
	head=1,tail=n;
	while(bj==0)
	{
		if(a[head]-a[tail]>=a[head+1])
		{
			a[tail]=a[head]-a[tail];
			head++;
		}
		
		else
			bj=1;
		//cout<<head;
		sort(a+head+1,a+tail+1);
		xy();
		//for(j=1;j<=n;j++)
			//cout<<a[j]<<" ";
	}
	cout<<tail-head+1<<" ";
}
void read()
{
	int i;
	cin>>k;
	for(i=1;i<=k;i++)
	{
		cin>>x>>y;
		a[x]=y;
	}
	xx();
	//for(j=1;j<=n;j++)
		//	cout<<a[j]<<" ";
}

int main()
{

	//freopen("snakes.in","r",stdin);
	//freopen("snakes.out","w",stdout);
	
	cin>>T>>n;
	for(int i=n;i>=1;i--)
		cin>>a[i];
		//for(j=1;j<=n;j++)
			//cout<<a[j]<<" ";
	solve();
	T--;
	while(T>0){
		T--;
		read();
		solve();
	}
	return 0;
}
