#include<bits/stdc++.h>
using namespace std;
int n;
int s=1;
int main()
{
	freopen("julian.in","r",stdin);
	freopen("julian.out","w",stdout);
	cin>>n;
	for(int i=1;i<=n;i++)
	if(n%4==0||n%100!=0&&n%400==0)
	{
		s++;
	}
	cout<<s;
	return 0;
}