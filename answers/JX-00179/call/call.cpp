#include <iostream>
#include <cstdio>
using namespace std;
int n;
int a[10100];
int b[10100];
int c[10100];
int d[10100];
int m;
int Q;
int q[1010];
int main(){
	freopen("call.in","r",stdin);
	freopen("call.out","w",stdout);
	cin>>n;
for(int i=1;i<=n;i++){
	cin>>a[i];
	}
	cin>>m;
	for(int j=1;j<=m;j++){
		cin>>b[j];
		}
		for(int j=1;j<=m-1;j++){
			cin>>c[j];
			}
			for(int k=1;k<=m+1;k++){
				cin>>d[k];
				}
				cin>>Q;
	for(int i=1;i<=Q;i++){
		cin>>q[i];
		if(q[i]==1){
			a[b[2]]=a[b[2]]+b[3];
			continue;
			}
		if(q[i]==2){
			for(int j=1;j<=n;j++){
			a[j]=a[j]*c[2];
				}
				continue;
			}
		if(q[i]==3){
				a[b[2]]++;
			for(int l=1;l<=n;l++){
				a[l]=a[l]*c[2];
				}
				}
				
	for(int i=1;i<=n;i++){
				cout<<a[i]<<' ';			
				}	
			}
	return 0;
}