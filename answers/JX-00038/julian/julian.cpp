#include<iostream>
#include<cstdio>
using namespace std;
int q;
int sz[100010];
int res[100010];
int kk[13][2]={1,31,2,29,3,31,4,30,5,31,6,30,7,31,8,31,9,30,10,31,11,30,12,31};

int k2[13][3]={1,31,2,28,3,31,4,30,5,31,6,30,7,31,8,31,9,30,10,31,11,30,12,31};
void ys(int x)
{
	int num;
	int year;
	int a=x/1461;
	if(x<1721424)
	{
		
		if(a>0)
		{
			year=4713-a*4;
			num=x-a*1461;
			int r=num;
			if(num<366)
			{
				int i=0,sum;
				while(r<=0)
				{
					r-=kk[i][1];
					sum=i;
					if(r<0)
					{
						cout<<kk[i][1]<<" ";
					}
					i++;
				}
				cout<<kk[sum][0]<<" "<<year;
			}
			else if(num==366)
			{
				cout<<1<<" "<<1<<" "<<year<<endl; 
				}
		}
		else
		{
			year=4713-1-a*4;
			num=x-a*1461;
			int b=num/365;
			int r=num;
			if(b<0)
			{
				int i=0,sum;
				while(r<=0)
				{
					r-=k2[i][1];
					sum=i;
					if(r<0)
					{
						cout<<k2[i][1]<<" ";
					}
					i++;
				}
				cout<<k2[sum][0]<<" "<<year<<" ";
			}
			else
			{
				r-=b*365;
				int i=0,sum;
				while(r<=0)
				{
					r-=k2[i][1];
					sum=i;
					if(r<0)
					{
						cout<<k2[i][1]<<" ";
					}
					i++;
				}
				cout<<k2[sum][0]<<" "<<year+b<<" ";
				}
		}
		cout<<"BC"<<endl;
		}
	else if(x==1721424)
	{
		cout<<1<<" "<<1<<" "<<1<<endl;
	}
	else if(x-1721424<577736)
	{
		
	}

}
int main()
{
	freopen("julian.in","r",stdin);
	freopen("julian.out","w",stdout);
	scanf("%d",&q);
	for(int i=0;i<q;i++)
	{
		scanf("%d",&sz[i]);
	}
	cout<<kk[1][1];
	for(int i=0;i<q;i++)
	{
		ys(sz[i]);
	}
	cin>>q;
	fclose(stdin);
	fclose(stdout);
	return 0;
}