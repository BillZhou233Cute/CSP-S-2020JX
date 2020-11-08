#include<iostream>
#include<cstdio>
#include<cstring>
using namespace std;
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
int n,m,a,b,c[100010],d[20010][2010],q,e;
void search(int f){
	for(a=2;a<=d[f][1]+1;a++){
		if(d[f][0]==1)
		c[d[f][1]]+=d[e][2];
		if(d[f][0]==2)
		for(b=1;b<=n;b++)
		c[b]*=d[f][1];
		if(d[f][0]==3)
		search(d[f][a]);
	}
	return;
}
int main(){
	freopen("call.in","r",stdin);
	freopen("call.out","w",stdout);
	n=read();
	for(a=1;a<=n;a++)
	c[a]=read();
	m=read();
	for(a=1;a<=m;a++){
		d[a][0]=read();
		if(d[a][0]==1)
		d[a][1]=read();d[a][2]=read();
		if(d[a][0]==2);
		d[a][1]=read();
		if(d[a][0]==3){
			d[a][1]=read();
			for(b=2;b<=d[a][1]+1;a++)
			d[a][b]=read();
		}
	}
	q=read();
	for(a=1;a<=q;a++){
		e=read();
		if(d[e][0]==1)
		c[d[e][1]]+=d[e][2];
		if(d[e][0]==2)
		for(b=1;b<=n;b++)
		c[b]*=d[e][1];
		if(d[e][0]==3)
		search(e);
	}
	fclose(stdin);
	fclose(stdout);
	return 0;
}
