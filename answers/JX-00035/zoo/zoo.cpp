#include<bits/stdc++.h>
using namespace std;
typedef unsigned long long ull;
map<int,bool> fooduse;
int n,m,c,k;
bool g[100];
vector<int> foodli[100];
bool check(int p){
    int sz=foodli[p].size();
    for(int i=0;i<sz;i++){
        if(!fooduse[foodli[p][i]])return false;
    }
    return true;
}
int main(){
    freopen("zoo.in","r",stdin);
    freopen("zoo.out","w",stdout);
    ios::sync_with_stdio(false);
    cin>>n>>m>>c>>k;
    for(int i=1;i<=n;i++){
        ull x;
        cin>>x;
        for(int i=0;i<=63;i++){
            if(x&(1ll<<i)){
                g[i]=true;
            }
        }
    }
    for(int i=1;i<=m;i++){
        int p,q;
        cin>>p>>q;
        if(g[p]){
            fooduse[q]=true;
        }
        foodli[p].push_back(q);
    }
    int cnt=0;
    for(int i=0;i<k;i++){
        if(check(i))cnt++;
    }
    cout<<(1ull<<cnt)-n<<endl;
    return 0;
}
