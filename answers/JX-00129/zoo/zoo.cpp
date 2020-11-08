#include<cstdio>
#define maxn 1000005
#define ri register int
int a[maxn],p[maxn],q[maxn];
int f[1<<20],flag[20],flag1[20];
int ans;
inline int read(){
	ri x=0,f=1;
	char ch=getchar();
	while(ch<'0'||ch>'9'){
		if(ch=='-') f=-1;
		ch=getchar();
	}
	while(ch>='0'&&ch<='9'){
		x=x*10+ch-'0';
		ch=getchar();
	}
	return x*f;
}
int main(){
	freopen("zoo.in","r",stdin);
	freopen("zoo.out","w",stdout);
	ri n=read(),m=read(),c=read(),k=read();
	for(ri i=1;i<=n;++i) a[i]=read(),f[i]=1;
	for(ri i=1;i<=m;++i){
		p[i]=read(),q[i]=read();
		for(ri j=1;j<=n;++j)
			if(a[j]>>p[i]&1) flag[q[i]]=1;
	}
	for(ri i=0;i<1<<k;++i){
		if(!f[i]){
			for(ri j=1;j<=c;++j) flag1[j]=flag[j];
			for(ri j=1;j<=m;++j){
				if((i>>p[j]&1)) flag1[q[j]]=1;
			}
			ri s=0;
			for(ri j=1;j<=c;++j){
				if(flag1[j]==flag[j]) s++;
			}
			if(s==c) ans++;
		}
	}
	printf("%d",ans);
	fclose(stdin);
	fclose(stdout);
	return 0;
}