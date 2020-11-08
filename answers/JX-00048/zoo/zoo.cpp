#include<bits/stdc++.h>
using namespace std;
long long n,m,c,k;
unsigned long long res=0,an[65]={0};
int f[66]={1},hh[66]={0},zh[66]={0};
int ans;
inline long long read(){
    long long w=0; int s=1; char c=getchar();
    while(c<'0' || c>'9'){if(c=='-') s=-1; c=getchar();}
    while(c<='9' && c>='0') w=w*10+c-'0',c=getchar();
    return w*s;
}

void work(unsigned long long x){
    int w=0;
    while(x){
        w++;
        if(x%2==1) hh[w]=1;
        x/=2;
    }
    int y=0;
    while(w){
		if(hh[w]) zh[y]=1;
        y++;w--;
    }
}


int main(){
        freopen("zoo.in","r",stdin);
	freopen("zoo.out","w",stdout);
        an[0]=1;

        for(int i=1;i<64;i++)
            an[i]=an[i-1]*2;
        n=read();m=read();c=read();k=read();	
        ans=k;
        for(int i=1;i<=n;i++){
            unsigned long long x=read();
            res=res|x;
        }
        work(res);int x,y;
        for(int i=1;i<=m;i++){
            x=read();y=read();
            if(!zh[x]) ans--;
        }
        if(ans<64){
            unsigned long long x=an[ans]-n;
            cout<<x;
        }
        if(ans==64){
            if(n>0)
			{unsigned long long x=an[63]-n+an[63];cout<<x;}
            if(n==0)
                cout<<"1844674407379551616";
        }
	fclose(stdin); fclose(stdout);
	return 0;
}

