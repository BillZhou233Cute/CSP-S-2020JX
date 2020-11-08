#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
const int NN=1e5+5;
const int maxn=1e6+5;
const ll mod=998244353;
struct segtree{
    ll sum[NN<<2],add[NN<<2],mul[NN<<2];
    segtree(){
        for(int i=0;i<(NN<<2);i++){
            mul[i]=1;
        }
    }
    int lson(int x){
        return x<<1;
    }
    int rson(int x){
        return x<<1|1;
    }
    void pushup(int x){
        sum[x]=sum[lson(x)]+sum[rson(x)];
    }
    void doadd(int x,int l,int r,ll v){
        sum[x]+=v*(r-l+1)%mod;
        sum[x]%=mod;
        add[x]+=v;
        add[x]%=mod;
    }
    void domul(int x,ll v){
        sum[x]*=v;
        sum[x]%=mod;
        mul[x]*=v;
        mul[x]%=mod;
        add[x]*=v;
        add[x]%=mod;
    }
    void pushdown(int x,int l,int r,int mid){
        if(mul[x]!=1){
            domul(lson(x),mul[x]);
            domul(rson(x),mul[x]);
            mul[x]=1;
        }
        if(add[x]){
            doadd(lson(x),l,mid,add[x]);
            doadd(rson(x),mid+1,r,add[x]);
            add[x]=0;
        }
    }
    void updateadd(int x,int l,int r,int p,ll v){
        if(l==r){
            doadd(x,l,l,v);
            return;
        }
        int mid=(l+r)>>1;
        pushdown(x,l,r,mid);
        if(p<=mid){
            updateadd(lson(x),l,mid,p,v);    
        }else{
            updateadd(rson(x),mid+1,r,p,v);    
        }
        pushup(x);
    }
    void updatemul(int x,int l,int r,int sl,int sr,ll v){
        if(sl<=l&&sr>=r){
            domul(x,v);
            return;
        }
        int mid=(l+r)>>1;
        pushdown(x,l,r,mid);
        if(sl<=mid){
            updatemul(lson(x),l,mid,sl,sr,v);    
        }
        if(mid+1<=sr){
            updatemul(rson(x),mid+1,r,sl,sr,v);
        }
        pushup(x);
    }
    ll query(int x,int l,int r,int p){
        if(l==r){
            return sum[x];
        }
        int mid=(l+r)>>1;
        pushdown(x,l,r,mid);
        if(p<=mid){
            return query(lson(x),l,mid,p);    
        }else{
            return query(rson(x),mid+1,r,p);
        }
    }
}seg;
struct node{
    int opt;
    int p;
    ll v;
    vector<int> fucks;
}allnodes[maxn];
int n,m;
void callfuck(int p){
    if(allnodes[p].opt!=3){
        if(allnodes[p].opt==1){
            seg.updateadd(1,1,n,allnodes[p].p,allnodes[p].v);    
        }else{
            seg.updatemul(1,1,n,1,n,allnodes[p].v);
        }
        return;
    }
    int sz=allnodes[p].fucks.size();
    for(int i=0;i<sz;i++){
        callfuck(allnodes[p].fucks[i]);
    }
}
int main(){
    freopen("call.in","r",stdin);
    freopen("call.out","w",stdout);
    ios::sync_with_stdio(false);
    cin>>n;
    for(int i=1;i<=n;i++){
        ll x;
        cin>>x;
        seg.updateadd(1,1,n,i,x);
    }
    cin>>m;
    for(int i=1;i<=m;i++){
        cin>>allnodes[i].opt;
        if(allnodes[i].opt==1){
            cin>>allnodes[i].p>>allnodes[i].v;    
        }else if(allnodes[i].opt==2){
            cin>>allnodes[i].v;
        }else{
            int c;
            cin>>c;
            while(c--){
                int x;
                cin>>x;
                allnodes[i].fucks.push_back(x);
            }
        }
    }
    int q;
    cin>>q;
    while(q--){
        int x;
        cin>>x;
        callfuck(x);
    }
    for(int i=1;i<=n;i++){
        cout<<seg.query(1,1,n,i);
        if(i==n){
            cout<<endl;
        }else{
            cout<<" ";
        }
    }
    return 0;
}
