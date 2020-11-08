#include<bits/stdc++.h>
using namespace std;
int n,m,k;
long c;
long long t=1;
int a[1000005];
int si[70];
int main(){
  freopen("zoo.in","r",stdin);
  freopen("zoo.out","w",stdout);
  cin>>n>>m>>c>>k;
  for(int i=1;i<=n;i++)cin>>a[i];
  for(int i=1;i<k;i++)
    t*=2;
  cout<<t-n;
  return 0;
}
