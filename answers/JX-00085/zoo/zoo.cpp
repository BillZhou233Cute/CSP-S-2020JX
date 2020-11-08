#include<bits/stdc++.h>
using namespace std;
int a[1000001],p[1000001],q[1000001];
int main(){
  freopen("zoo.in","r",stdin);
  freopen("zoo.out","w",stdout);
  int n,m,c,k,sum=1;
  cin>>n>>m>>c>>k;
  for(int i=1;i<=n;i++)
    cin>>a[i];
  for(int i=1;i<=m;i++)
    cin>>p[i]>>q[i];
  for(int i=1;i<=k;i++)
    sum*=2;
  cout<<sum-n;
  return 0;
}
