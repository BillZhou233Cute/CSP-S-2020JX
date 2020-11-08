#include<cstdio>
#include<iostream>
using namespace std;
int month[15]={0,31,28,31,30,31,30,31,31,30,31,30,31},month_[15]={0,31,29,31,30,31,30,31,31,30,31,30,31};//1721058
int y,m=1,d;
int main(){
    freopen("julian.in","r",stdin);
    freopen("julian.out","w",stdout);
    int q,x;
    int four_year_days=1461;
    scanf("%d",&q);
    for(int i=1;i<=q;i++){
        m=0;
        scanf("%d",&x);
        int a,b,c;
        a=(x+1)/four_year_days;
        b=(x+1)%four_year_days;
        if(x<1721058) {
            int y_;
            if(b<=366) y_=0;
            else if((b-366)%365==0) y_=(b-366)/365; else y_=(b-366-1)/365+1;
            //printf("%d %d %d\n",a,b,y_);
            y=4713-a*4-y_;
            if(b<366) {while(b>=month_[m]){b-=month_[m++];} d=b;}
            else {b-=366+(y_-1)*365; while(b>=month_[m]){b-=month[m++];} d=b;} 
            
            printf("%d %d %d BC\n",d,m,y);
            continue;
        }
        if(x>=1721058||x<=577737+1721058){
            x-=1721057;
            a=x/four_year_days;
            b=x%four_year_days;
            int y_;
            if(b<1095) y_=b/365;
            else y_=3;
            y=a*4+y_;
            if(b<1095) {b-=y_*365; while(b>=month[m]){b-=month[m++];} d=b;}
            else {b-=1095;{b-=366+y_*365; while(b>=month_[m]){b-=month[m++];} d=b;}}
            printf("%d %d %d\n",d,m,y);
        }
    }

    return 0;
}
