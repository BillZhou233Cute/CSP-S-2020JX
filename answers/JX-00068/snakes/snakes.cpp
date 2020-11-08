#include<bits/stdc++.h>
using namespace std;
int n;
int a[3000005];
int t;
int q;
int kkn(int k){
  if(a[3]-a[1]>=a[2])return 1;
  if(a[3]-a[2]>=a[1])return 1;
  if(a[2]-a[3]>=a[1])return 1;
  if(a[2]-a[1]>a[3])return 1;
  if(a[1]-a[2]>a[3])return 1;
  if(a[1]-a[3]>a[2])return 1;
  return 3;
}
int main(){
  freopen("snakes.in","r",stdin);
  freopen("snakes.out","w",stdout);
  cin>>t;
  cin>>n;
  for(int i=1;i<n;i++)
    cin>>a[i];
  cout<<kkn(n)<<endl;
  for(int d=2;d<=t;d++){
    cin>>q;
    for(int i=1;i<=q;i++){
      int l,r;
      cin>>l>>r;
      a[l]=r;
    }
    cout<<kkn(n)<<endl;
  }
  return 0;
}
