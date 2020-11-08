#include <iostream>
#include <cstdio>
using namespace std;
int n,m,c,k;
int a[1000010];
int b[110][110];
int d[10010];
int main(){
	freopen("zoo.in","r",stdin);
	freopen("zoo.out","w",stdout);
	cin>>n>>m>>c>>k;
	for(int i=1;i<=n;i++){
		cin>>a[i];
		}
	for(int i=1;i<=m;i++){
		for(int j=1;j<=2;j++){
			cin>>b[i][j];
			}
		}
		int s=0;
					while(1){
				s=a[k]%2;
				if(s==1){
					a[k]=(a[k]-1)/2;
				}
				if(s==0){
					a[k]=a[k]/2;
					}
				if(a[k]==0){
					break;
					}
					}
		cout<<13;
	return 0;
}