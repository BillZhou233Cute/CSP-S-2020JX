#include<bits/stdc++.h>
using namespace std;
int main()
{
	freopen("julian.in","r",stdin);
	freopen("julian.out","w",stdout);
	int q;
	cin>>q;
	int a[13]={0,30,58,89,119,150,180,211,242,272,303,333,364};
	while(q--)
	{
		int r;
		cin>>r;
		if(r<=365)
		{
			if(r<=a[1])
				cout<<r+1<<" "<<1<<" "<<4713<<" "<<"BC"<<endl;
			for(int i=1;i<=11;i++)
					if(a[i]<r&&r<=a[i+1])
						cout<<r-a[i]-1<<" "<<i+1<<" "<<4713<<" "<<"BC"<<endl;
			if(r>a[12])
				cout<<r-a[11]-1<<" "<<12<<" "<<4713<<" "<<"BC"<<endl;
		}
		if(r>365&&r<2324311)
		{
			int w,y,m,d;
			w=r%1461;
			y=(r-w)/365+4713;
			m=r-(r-w)/365*365-w;
			for(int i=1;i<=11;i++)
					if(a[i]<m&&m<=a[i+1])
						cout<<m-a[i]-1<<" "<<i+1<<" ";
			if(m>a[12])
				cout<<m-a[11]-1<<" "<<12<<" ";
			if(m<=a[1])
				cout<<m+1<<" "<<1<<" ";
			if(y<=0)
			{
				y--;
				cout<<y<<" "<<"BC"<<endl;
			}
			else
				cout<<y<<endl;
		}
	}
	return 0;
}