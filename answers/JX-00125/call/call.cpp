#include<bits/stdc++.h>
using namespace std;
const int N = 100005;
int a[N];
struct way{
	int x,y,z;
	way(int _x = 0,int _y = 0,int _z = 0) : x(_x),y(_y),z(_z){};
}b[N];
vector <int> e[1005];
int read(){
	int x = 0,f = 1;
	char ch;
	for(ch = getchar();ch > '9' || ch < '0';ch = getchar()) if(ch == '-') f = -1;
	for(;ch >= '0' && ch <= '9';ch = getchar()) x = (x << 1) + (x << 3) + (ch ^ 48);
	return x * f;
}
int n,m,Q,cnt;
void runs(int x){
	if(b[x].z == 1) a[b[x].x] += b[x].y;
	else if(b[x].z == 2) for(int i = 1;i <= n;i++) a[i] *= b[x].x;
	else {
		for(int i = 0;i < b[x].x;i++) runs(e[b[x].y][i]);
	}
}
int main(){
	freopen("call.in","r",stdin);
	freopen("call.out","w",stdout);
	n = read();
	for(int i = 1;i <= n;i++) a[i] = read();
	m = read();	
	int x,y,z;
	for(int i = 1;i <= m;i++){
		z = read();
		if(z == 1){
			x = read(),y = read();
			b[i] = way(x,y,z);
		} 
		else if(z == 2){
			x = read();
			b[i] = way(x,0,z);
		}
		else {
			x = read();
			cnt++;
			for(int i = 1;i <= x;i++) e[cnt].push_back(read());
			b[i] = way(x,cnt,z);
		}
	}
	Q = read();
	for(int i = 1;i <= Q;i++){
		x = read();
		runs(x);
	}
	for(int i = 1;i <= n;i++) printf("%d ",a[i]);
	return 0;
}
