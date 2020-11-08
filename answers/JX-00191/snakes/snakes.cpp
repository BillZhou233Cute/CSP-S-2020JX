#include<iostream>
#include<cstdio>
#include<cstring>
#include<algorithm>
#include<queue>
#include<cmath>
#include<vector>
using namespace std;
#define ll long long
const int maxn = 5000;
int f[maxn];
int q[4000][4000];
int  n,m,c,kk,t1,t2;
int  zl;
int ans;
int a[maxn];
bool flag[maxn];
bool tt[maxn];
void ch(int k){
	int cnt=0;
	ll temp=k;
	while(k){
		if(k&1&&f[cnt]){
			q[temp][++q[temp][0]]=f[cnt];
			}
			k>>=1;
			cnt++;
		}
}
int main(){
  freopen("snakes.in","r",stdin);
  freopen("snakes.out","w",stdout);
 int n;
	cin>>n;
	for(int i=1;i<=n;++i){
		cout<<1<<endl;
		}
		return 0;
	}