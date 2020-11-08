#include<bits/stdc++.h>
using namespace std;

long long n,a,b;
int d[13]={0,31,28,31,30,31,30,31,31,30,31,30,31},q;
int main(){
    freopen("julian.in","r",stdin);
    freopen("julian.out","w",stdout);
    int i,j;
    scanf("%d",&q);
    for(i=1;i<=q;i++)
    {
        scanf("%lld",&n);
        n++;
        if(n<=1721424){
            a=4713-n*4/1461;
            long long t=n-(4713-a)*365-(4713-a)/4-1;
            if(a%4==1)d[2]=29;
            for(j=1;j<=12;j++){
                if(d[j]<t)t-=d[j],b++;
                  else{
                    b++;break;
                  }
            }
            printf("%lld %lld %lld BC\n",t,b,a);
            d[2]=28;
        }
          else if(n<=2299161){
            n-=1721424;
            a=n*4/1461+1;
            long long t=n-(a-1)*365-a/4;
            if(a%4==1)d[2]=29;
            for(j=1;j<=12;j++){
                if(d[j]<t)t-=d[j],b++;
                  else{
                    b++;break;
                  }
            }
            printf("%lld %lld %lld\n",t,b,a);
            d[2]=28;
          }
            else{
            n-=2299161;
            if(n<=78){
                d[10]=17,a=1582,b=10;
                for(j=10;j<=12;j++){
                 if(d[j]<n)n-=d[j],b++;
                  else break;
                }
                printf("%lld %lld %lld\n",n,b,a);
                d[10]=31;
            }
              else{
              n-=78;
              a=n*400/146097+1583;
              long long t=n-((a-1583)*365+(a-1581)/4-(a-1501)/100+(a-1201)/400);
              b=1;
              if(a%400==0||(a%4==0&&a%100!=0))d[2]=29;
              for(j=1;j<=12;j++){
                 if(d[j]<t)t-=d[j],b++;
                  else break;
                }
              printf("%lld %lld %lld\n",t,b,a);
              d[2]=28;
              }
            }
    }
}
