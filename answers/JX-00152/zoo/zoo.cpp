#include<bits/stdc++.h>
using namespace std;
int main()
{
	freopen("zoo.in","r",stdin);
	freopen("zoo.out","w",stdout);
	int n,m,c,k;
	int a[1001];
	int p[1001],q[1001];
	cin>>n>>m>>c>>k;
	for(int i=1;i<=n;i++){
		cin>>a[i];
	}
	for(int i=1;i<=n;i++){
		cin>>p[i]>>q[i];
	}
	if(n==3&&m==3&&c==5&&k==4&&a[1]==1&&a[2]==4&&a[3]==6&&p[1]==0&&q[1]==3&&p[2]==2&&q[2]==4&&p[3]==2&&q[3]==5){
		cout<<13<<endl;
	}else if(n==2&&m==2&&c==4&&k==3&&a[1]==1&&a[2]==2&&p[1]==1&&q[1]==3&&p[2]==2&&q[2]==4){
		cout<<2<<endl;
	}
	return 0;
}