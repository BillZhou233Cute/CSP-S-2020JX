#include<bits/stdc++.h>
using namespace std;
const int mod=998244353;
int n,m,q,t[20005][1005];
long long a[100005];
inline long long read(){
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
void dfs(int z){
	for(int i=2;i<=t[z][1]+1;i++){
		if(t[t[z][i]][0]==1){
			a[t[t[z][i]][1]]+=t[t[z][i]][2];
			a[t[t[z][i]][1]]%=mod;
		}else{
			if(t[t[z][i]][0]==2){
				for(int j=1;j<=n;j++){
					a[j]*=t[t[z][i]][1];
					a[j]%=mod;
				}
			}else{
				dfs(i);
			}
		}
	}
}
int main(){
	freopen("call.in","r",stdin);
	freopen("call.out","w",stdout);
	n=read();
	for(int i=1;i<=n;i++){
		a[i]=read();
	}
	m=read();
	if(m>20000){
		int  r[100005][3];
		for(int i=1;i<=m;i++){
			r[i][0]=read();
			if(r[i][0]==1){
				r[i][1]=read();
				r[i][2]=read();
			}else{
				r[i][1]=read();
			}
		}
		q=read();
		for(int i=1;i<=q;i++){
			int z=read();
			if(r[z][0]==1){
				a[r[z][1]]+=r[z][2];
				a[r[z][1]]%=mod;
			}else{
				for(int j=1;j<=n;j++){
					a[i]*=r[z][1];
					a[i]%=mod;
				}
			}
		}
		for(int i=1;i<=n;i++){
			cout<<a[i]<<" ";
		}
		return 0;
	}
	for(int i=1;i<=m;i++){
		t[i][0]=read();
		if(t[i][0]==1){
			t[i][1]=read();
			t[i][2]=read();
		}else{
			if(t[i][0]==2){
				t[i][1]=read();
			}else{
				t[i][1]=read();
				for(int j=2;j<=t[i][1]+1;j++){
					t[i][j]=read();
				}
			}
		}
	}
	q=read();
	while(q--){
		int z=read();
		if(t[z][0]==1){
			a[t[z][1]]+=t[z][2];
			a[t[z][1]]%=mod;
		}else{
			if(t[z][0]==2){
				for(int j=1;j<=n;j++){
					a[j]*=t[z][1];
					a[j]%=mod;
				}
			}else{
				dfs(z);
			}
		}
	}
	for(int i=1;i<=n;i++){
		cout<<a[i]<<" ";
	}
	return 0;
}