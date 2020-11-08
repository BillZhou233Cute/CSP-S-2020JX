#include<iostream>
using namespace std;
int q,n,m,a;
int solve1()
{

	n=a/31+1;
	m=a%31+1;
	cout<<m<<" "<<n<<" "<<4713<<" "<<"BC";
}
int main()
{
	
	//freopen("julian.in","r",stdin);
	//freopen("julian.out","w",stdout);
    cin>>q;
	while(q>0)
	{
		cin>>a;
		if(a<=365)
		solve1();
		q--;
	}
}