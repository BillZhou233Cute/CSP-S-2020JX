#include<iostream>
#include<cstdio>
using namespace std;
int s[50050],n,T,a[50050];
void f(int n2){
	while(1){
		if(n2==2){
			n2=1;
			break;
		}
		if(a[n-1]-a[n-n2]>=a[n-n2+1]){
			a[n-1]-=a[n-n2];
			n2--;
			for(int i=n-n2;i<n;i++){
				if(a[i]>a[n-1]){
					int k=a[n-1];
					for(int j=n-1;j>i;j--)a[j]=a[j-1];
					a[i]=k;
				}
			}
		}else break;
	}
	cout<<n2<<endl;
}
int main(){
	freopen("snakes.in","r",stdin);
	freopen("snakes.out","w",stdout);
	scanf("%d",&T);
	for(int i=1;i<=T;i++){
		if(i==1){
			scanf("%d",&n);
			for(int i=0;i<n;i++){
				scanf("%d",&s[i]);
				a[i]=s[i];
			}
		}else{
			int k;
			scanf("%d",&k);
			for(int i=0;i<k;i++){
				int x,y;
				scanf("%d%d",&x,&y);
				s[x-1]=y;
			}
			for(int i=0;i<n;i++)a[i]=s[i];
		}
		f(n);
	}
	return 0;
}