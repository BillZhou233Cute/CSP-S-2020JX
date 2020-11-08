#include<bits/stdc++.h>
using namespace std;

struct node{
    int x;
    int s;
}b[1000100];
int t,n,a[1000100];
int k,x,y,num;
bool cmp(node t1,node t2){
    if(t1.x!=t2.x)return t1.x>t2.x;
      else return t1.s>t2.s;
}

int main(){
    freopen("snakes.in","r",stdin);
    freopen("snakes.out","w",stdout);
    scanf("%d",&t);
    int i,j;
    for(i=1;i<=t;i++){
        //printf("OK!");
        if(i!=1){
            scanf("%d",&k);
            for(j=1;j<=k;j++)scanf("%d%d",&x,&y),a[x]=y;
        }
            else {
            scanf("%d",&num);
            for(j=1;j<=num;j++)scanf("%d",&a[j]);
            }
        for(j=1;j<=num;j++)b[j].x=a[j],b[j].s=j;
        n=num;
        sort(b+1,b+n+1,cmp);
        while(n>1){
            if(b[2].x<b[1].x-b[n].x||(b[2].x<=b[1].x-b[n].x&&b[1].s>b[2].s)||b[1].x-b[n].x>b[n-1].x||(b[1].x-b[n].x>=b[n-1].x&&b[1].s>b[n-1].s)||n==2){
                b[1].x-=b[n].x;n--;
                sort(b+1,b+n+1,cmp);
            }
              else break;
        }
        printf("%d\n",n);
    }
}
