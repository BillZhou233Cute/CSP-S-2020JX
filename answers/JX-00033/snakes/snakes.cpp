#include<queue>
#include<cmath>
#include<cstdio>
#include<cstring>
#include<iostream>
#include<algorithm>
using namespace std;
const int N=1000001;
struct Data{
	int str,id;
}s[N];
int n,tot;
int read(){
	int x=0,f=1;char ch=getchar();
	while(ch<'0'||ch>'9'){if(ch=='-')f=-1;ch=getchar();}
	while(ch>='0'&&ch<='9'){x=x*10+ch-'0';ch=getchar();}
	return x*f;
}
bool cmp(Data x,Data y){
	return x.str>y.str;
}
int main(){
	freopen("snakes.in","r",stdin);
	freopen("snakes.out","w",stdout);
	int S=read();
	for(int H=1;H<=S;H++){
		n=read();
		if(H==1){tot=n;for(int i=1;i<=n;i++){s[i].str=read();s[i].id=i;}}
		else for(int i=1;i<=n;i++){
			int idd=read(),add=read();
			for(int j=1;j<=n;j++) if(s[j].id==idd) 
			s[idd].str=add;
		}
		sort(s+1,s+tot+1,cmp);
		while(s[1].str-s[tot].str>=s[2].str){
			s[1].str-=s[tot].str;
			s[tot].str=0;tot--;
			sort(s+1,s+tot+1,cmp);
		}
		printf("%d\n",tot);
	}
	fclose(stdin);
	fclose(stdout);
	return 0;
}