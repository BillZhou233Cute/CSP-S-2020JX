#include<bits/stdc++.h>
using namespace std;

int n,m,c,k,two[70];
long long a[1000010],b[1000010],q,ans;
bool used[1000010],book[1000010];

int main(){
    freopen("zoo.in","r",stdin);
    freopen("zoo.out","w",stdout);
    scanf("%d%d%d%d",&n,&m,&c,&k);
    long long i,j;
    for(i=1;i<=n;i++)scanf("%lld",&a[i]),book[a[i]]=1;
    for(i=1;i<=m;i++)scanf("%lld%lld",&b[i],&q);
    for(i=1;i<=n;i++)
    {
        long long temp=a[i],num=0;
        memset(two,0,sizeof(two));
        while(temp>1)two[++num]=temp%2,temp=temp/2;
        for(j=1;j<=m;j++){
            if(used[j]==0){
                if(two[b[j]]==1)used[j]=1;
            }
        }
    }
    for(i=0;i<pow(2,k);i++){
        if(book[i]==1)continue;
        long long temp=i,num=0;
        memset(two,0,sizeof(two));
        while(temp>1)two[++num]=temp%2,temp=temp/2;
        bool flag=0;
        for(j=1;j<=m;j++)if(two[b[j]]==1&&used[j]==0){flag=1;break;}
        if(flag==0)ans++;
    }
    printf("%lld",ans);
}
