#include<iostream>
#include<algorithm>
#include<cstdio>
#include<string>
#include<cmath>
using namespace std;
int main()
{
	freopen("snakes.in","r",stdin);
	freopen("snakes.ans","w",stdout);
	int n;
	cin>>n;
	for(int i=1;i<=n;i++)
	cout<<i%2+1<<endl;
	fclose(stdin);
	fclose(stdout);
	return 0;
}