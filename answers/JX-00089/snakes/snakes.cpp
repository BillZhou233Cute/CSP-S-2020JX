#include<iostream>
#include<cstdio>
#include<algorithm>
using namespace std;
int n , m , i , j , o , al , ar , ans ,  h,v;

struct qq
{
	int bian;
	int t;
}a[300005],b[300005];

bool    cmp   (qq   x   ,qq   	y)
{
if(x.t==y.t)return x.bian<y.bian;
	return		x.t	<y.t;

}	

int main()
{
	freopen("snakes.in","r",stdin);
	freopen("snakes.out","w",stdout);
	
	
	cin>>m;
	for(o=1;o<=m;o++)
	{
		cin>>n;
		int c=0,d=0;
		if(	o	==	1	)
		{
			for(int u=1;u<=n;u++)
			{
				cin>>b[u].t;
				b[u].bian=u;
			}
			sort(b+1,b+n,cmp);
		}
		else
		for(i=1;i<=n;i++)
		{
			cin>>c>>d;
			b[c].t=d;
		}
		
		for(i=1;i<=n;i++)
			{
				a[i].t=b[i].t;
				a[i].bian=b[i].bian;
			}
		sort(a+1,a+n,cmp);

		
		
		ans=n;
		int k=1;
		int 	l	=	1	,r	=	n;
		while(k==1)
		{
			if(r-l==1&&a[r].t>a[l].t  )
			{
				ans--;
				k=2;
			}
			else
			if	(a[r].t -a[l].t>a[l+1].t		||	(a[r].t-a[l].t==a[l+1].t&&a[r].bian>a[l+1].bian))
			{
				ans--;
				ar=a[r].t-a[l].t;
				al=a[r].bian;
				h=r-1;
				while (a[h].t>ar&&h>=l);
				{
					
					a[h+1].t=a[h].t;
					a[h+1].bian=a[h].bian;
					h--;
				}
				  h+=2;
					a[h].t=ar;
				    a[h].bian=al;
				
				
				
				l++;//cout<<l<<endl;
			}
			else k=2;
		}
		cout<<ans<<endl;
	}
	
}

