#include<bits/stdc++.h>
using namespace std;
int a[100001],zx[10001];
int m,n,q;
struct call{
    int lx,v,p,g[1001],j;
}f[100001];
void fe(call u){
    if(u.lx==1) a[u.p]+=u.v;
    if(u.lx==2) for(int k=1;k<=n;k++) a[k]*=u.v;
    //for(int i=1;i<=n;i++) cout<<a[i]<<endl;
    if(u.lx==3) for(int q=1;q<=u.j+1;q++) fe(f[u.g[q]]);
}
int mod=998244353;
int main(){
    freopen("call.in","r",stdin);
    freopen("call.out","w",stdout);
    scanf("%d",&n);
    for(int i=1;i<=n;i++) scanf("%d",&a[i]);
    scanf("%d",&m);
    for(int i=1;i<=m;i++){
        scanf("%d",&f[i].lx);
        if(f[i].lx==1) scanf("%d%d",&f[i].p,&f[i].v);
        if(f[i].lx==2) scanf("%d",&f[i].v);
        if(f[i].lx==3){
            scanf("%d",&f[i].j);
            for(int k=1;k<=f[i].j;k++) scanf("%d",&f[i].g[f[i].j]);
        }
    }
    scanf("%d",&q);
    for(int i=1;i<=q;i++){
        scanf("%d",&zx[i]);
        fe(f[zx[i]]);
    }
    for(int i=1;i<=n;i++) cout<<a[i]%mod<<" ";
    return 0;
}
