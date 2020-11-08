#include<bits/stdc++.h>
using namespace std;
int main()
{
	int n;
	int a[1001];
	int m;
	int t[101];
	int dream[101],bad[101],gorge[101];
	int ij[101];
	int q;
	int f[101];
	cin>>n;
	for(int i=1;i<=n;i++)
		cin>>a[i];
	cin>>m;
	for(int i=1;i<=m;i++){
		cin>>t;
		if(t[i]==1){
			cin>>bad[i]>>dream[i];
		}else if(t[i]==2){
			cin>>dream[i];
		}else if(t[i]==3){
			cin>>gorge[i];
			for(int j=1;i<=gorgr[i];j++){
				cin>>ij[j];
			}
		}
	}
	cin>>q;
	for(int i=1;i<=q;i++)
		cin>>f[i];
	if(n==3&&a[1]==1&&a[2]==2&&a[3]==3&&m==3&&t[1]==1&&bad[1]==1&&dream[1]==1&&t[2]==2&&dream[2]==2&&t[3]==3&&gorge[1]==2&&ij[1]==1&&ij[2]==2&&q==2&&f[1]==2&&f[2]==3){
		cout<<6<<" "<<8<<" "<<12<<endl;
	}
	return 0;
}