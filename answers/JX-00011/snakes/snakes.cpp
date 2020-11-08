#include<iostream>
#include<cstdio>
#include<cstring>
#include<cmath>
#include<algorithm>
using namespace std;
int t,n,a,c[1000010],s,l,r,g,h,k;
struct node{
	int x,y,z;
}f[1000010];
int read(){
	int s1=1,s2=0;
	char ch=getchar();
	while(!isdigit(ch)){
		if(ch=='-')
		s1=-1;
		ch=getchar();
	}
	while(isdigit(ch)){
		s2=s2*10+(ch-'0');
		ch=getchar();
	}
	return s1*s2;
}
bool cmd(node a.x,b.x){
	return a.x>b.x;
	return a.y>b.y;
	return a.z>b.z;
}
void eat(int m){
	sort(f+1,f+m+1,cmd);
	if(f[1].x-f[m].x>f[m-1].x){
		if(f[m].y>0){
			r=f[m].z;
			return;
		}
		f[m].x=-9999;
		f[1].x-=f[m].x;
		f[1].y++;
		eat(m-1);
		if(r>0&&l=1){
			if(f[1].z==r){
			s=m+1;
			l=0;
			return;
			}
		}
	}
	else{
		l=0;
		s=m;
		return; 
	}
	if(l==0)
	return;
}
int main(){
	freopen("snakes.in","r",stdin);
	freopen("snakes.out","w",stdout);
	t=read();
	t--;
	n=read();
	for(a=1;a<=n;a++){
		c[a]=read();
		f[a].x=c[a];
		f[a].z=a;
	}
	l=1;
	r=0;
	eat(n);
	cout<<s<<endl;
	while(t>0){
		t--;
		k=read();
		for(a=1;a<=k;a++){
			g=read();
			h=read();
			c[g]=h;
		}
		for(a=1;a<=n;a++){
			c[a]=read();
			f[a].x=c[a];
			f[a].z=a;
		}
		l=1;
		r=0;
		eat(n);
		cout<<s<<endl;
	}
	fclose(stdin);
	fclose(stdout);
	return 0;
}
