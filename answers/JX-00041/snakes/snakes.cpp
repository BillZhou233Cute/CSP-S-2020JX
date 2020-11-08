#include<cstdio>
#include<cstring>
#include<cmath>
#include<iostream>
#include<ctime>
#include<algorithm>
#include<cstdlib>
using namespace std;
const int MAXN=3000005;
int a[MAXN],n,T,b[MAXN];

int main(){
  freopen("snakes.in","r",stdin);
  freopen("snakes.out","w",stdout);
  scanf("%d%d",&T,&n);
  for(int i=1;i<=n;i++) scanf("%d",&a[i]),b[i]=a[i];
  int ans=n,min=1;
  while(ans>0){
    if(b[n]-b[min]>b[n-1]) ans--,b[n]-=b[1],min++;
    else break;
  }
  printf("%d\n",ans);
  T--;
  while(T--){
    int x,y,k;
    scanf("%d",&k);
    for(int i=1;i<=n;i++)
      b[i]=a[i];
    for(int i=1;i<=k;i++)
      scanf("%d%d",&x,&y),b[x]=y;
      while(ans!=1){
        if(b[n]-b[min]>=b[n-1]) ans--,b[n]-=b[1],min++;
        else break;
  }
    printf("%d\n",ans);
  }
  return 0;
}
