#include"bits/stdc++.h"
using namespace std;
#define ri register int
#define ll long long
inline ll rd(){
    ll x=0,flg=1;
    char ch=getchar();
    while(ch<'0'||ch>'9') {if(ch=='-') flg=-1;ch=getchar();}
    while(ch>='0'&&ch<='9') {x=x*10+(ch^48);ch=getchar();}
    return x*flg;
}
#define N 6000005
ll t,len[N],ok[N],top,r=1,mon[2][15]={0,31,28,31,30,31,30,31,31,30,31,30,31,0,0,
                                       0,31,29,31,30,31,30,31,31,30,31,30,31,0,0};
ll x,day,l[N];
int main(){
    freopen("julian.in","r",stdin);
    freopen("julian.out","w",stdout);
    for(ri i=-4713;i<=5990000;++i){
        if(i==0) continue;
        if(i>1582){
            if((i%400==0)||((i%4==0)&&(i%100!=0))) r=1;
            else r=0;
        }
        else{
            if((-i-1)%4==0) r=1;
            else r=0;
        }
        l[++top]=day;
        if(i==1582) len[top]=355;
        else len[top]=365+r;
        day+=len[top];
        ok[top]=r;
    }
    t=rd();
    while(t--){
        x=rd();if(x==0) {printf("1 1 4713 BC\n");continue;}
        int pos=upper_bound(l+1,l+1+top,x)-l;
        pos--;
        int real_year,real_month,real_day;
        if(pos<=4713) real_year=-(4713-pos+1); else real_year=pos-4713;
        ll res_day=x-l[pos];
        for(ri i=1;i<=12;++i){
            if(real_year==1582&&i==10){
                if(1+res_day>21) res_day-=21;
                else if(1+res_day<=4) {real_month=10,real_day=1+res_day;break;}
                else {real_month=10,real_day=1+res_day+10;break;}
                continue;
            }
            if(1+res_day>mon[ok[pos]][i]) res_day-=mon[ok[pos]][i];
            else {real_month=i,real_day=1+res_day;break;}
        }
        if(real_year<0) printf("%d %d %d BC\n",real_day,real_month,-real_year);
        else printf("%d %d %d\n",real_day,real_month,real_year);
    }
    return 0;
}
