#include<bits/stdc++.h>
using namespace std;
int q,ans,n,a[1000005],b[1000005];
bool vis;
inline int read(){
	int x=0;
	bool flag=0;
	char ch;
	do{
		ch=getchar();
		if(ch=='-'){
			flag=1;
		}
	}while(!(ch>='0'&&ch<='9'));
	while(ch>='0'&&ch<='9'){
		x=(x<<1)+(x<<3)+ch-'0';
		ch=getchar();
	}
	if(flag){
		return -x;
	}
	return x;
}
bool cmp(int a,int b){
	return a>b;
}
int main(){
	freopen("snakes.in","r",stdin);
	freopen("snakes.out","w",stdout);
	q=read();
	n=read();
	ans=n;
	q--;
	for(int i=1;i<=n;i++){
		b[i]=read();
	}
	for(int i=1;i<=n;i++){
		a[i]=b[i];
	}
	sort(a+1,a+n+1,cmp);
	int right=n;
	for(int i=1;i<right;i++){
		while((a[i]-a[right]>a[right-1]||a[i]-a[right]>a[i+1])&&a[i]-a[right]>a[i+1]-a[right-1]){
			a[i]-=a[right--];
		}
		if(right==2&&a[1]>a[2]){
			printf("1\n");
			vis=1;
			break;
		}
		for(int j=i+1;j<right;j--){
				if(a[j-1]<a[j]){
					swap(a[i],a[j]);
				}else{
					break;
			}
		}
	}
	if(!vis){
			printf("%d\n",right);
	}
	while(q--){
		for(int i=1;i<=n;i++){
			a[i]=b[i];
		}
		int z=read();
		for(int i=1;i<=z;i++){
			int c=read(),d=read();
			a[c]=d;
		}
		sort(a+1,a+n+1,cmp);
		int right=n;
		for(int i=1;i<right;i++){
			while((a[i]-a[right]>a[right-1]||a[i]-a[right]>a[i+1])&&a[i]-a[right]>a[i+1]-a[right-1]){
				a[i]-=a[right--];
			}
			if(right==2&&a[1]>a[2]){
				printf("1\n");
				vis=1;
				break;
			}
			for(int j=i+1;j<right;j--){
				if(a[j-1]<a[j]){
					swap(a[i],a[j]);
				}else{
					break;
			}
		}
	}
		if(!vis){
			printf("%d\n",right);
		}
	}
	return 0;
}