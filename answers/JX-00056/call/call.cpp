#include<bits/stdc++.h>
using namespace std;


long long n,a[100010],b[100010][1010],q,c[100010];
int m,t;
int main(){
    freopen(".in","r",stdin);
    freopen(".out","w",stdout);
    int i,j;
    scanf("%lld",&n);
    for(i=1;i<=n;i++)scanf("%lld",&a[i]);
    scanf("%d",&m);
    for(i=1;i<=m;i++){
        int t;
        scanf("%d",&b[i][1]);
        if(b[i][1]==1)scanf("%d%d",&b[i][2],&b[i][3]);
        if(b[i][1]==2)scanf("%d",&b[i][2]);
        if(b[i][1]==3){
            scanf("%d",&b[i][2]);
            for(j=1;j<=b[i][2];j++)scanf("%d",&b[i][2+j]);
        }  
    }
    scanf("%d",&q);
    for(i=1;i<=q;i++){
        scanf("%d",&c[i]);
        if(b[c[i]][1]==1)a[b[c[i]][2]]=(a[b[c[i]][2]]+b[c[i]][3])%998244353;
        if(b[c[i]][1]==2){
            for(j=1;j<=n;j++)a[i]=a[i]*b[c[i]][2]%998244353;
        }
        if(b[c[i]][2]==3){
            for(j=3;j<=2+b[c[i]][2];j++){
                int x=b[c[i]][j];
                if(b[x][1]==1)a[b[c[i]][2]]=(a[b[x][2]]+b[x][3])%998244353;
                if(b[x][1]==2){
                    for(j=1;j<=n;j++)a[i]=a[i]*b[x][2]%998244353;
                }
            }
        }
    }
}
