#include <iostream>
#include <cstdio>
#include <cctype>
#define il inline
#define ll long long
#define R register
#define gc getchar
#define int long long
using namespace std;
//------------------------初始函数--------------------------
il int read(){
    R int x=0;R bool f=0;R char ch=gc();
    while(!isdigit(ch)){f|=ch=='-';ch=gc();}
    while(isdigit(ch)){x=(x<<1)+(x<<3)+(ch^48);ch=gc();}
    return f?-x:x;
}

il int min(int a,int b) {return a<b?a:b;}

il int max(int a,int b) {return a>b?a:b;}
//------------------------初始函数--------------------------

const int MAXNQ=1e5+10;
int q,x;
bool flag1,flag2,flag3;      //flag1->判断是公元前还公元后,flag2->判断是否是润年,flag3->判断是否在1582年之后
int ye,mon,da;      //ye->年，mon->月，da->日
int mo[20]={0,31,28,31,30,31,30,31,31,30,31,30,31,1111111111111111111};

//--------------------判断他的具体时间----------------------
il void work_year(){
    if(x>366) x-=366,++ye;
    for(R int i=1;;++i){
        if(!flag3){
            if(!(i%4)&&x<=366) break;
            if(i%4&&x<=365) break;
            if(i%4&&x>365){x-=365;++ye;}
            if(!(i%4)&&x>366) {x-=366;++ye;}
            if(ye>=4713&&!flag1) ye-=4712,flag1=1;
            if(ye==1582&&flag1) flag3=1,x+=10,i-=4712;
        }
        else {
            if(((!(i%4)&&(i%100))||(!(i%400)))&&x<=366) {
                break;
            }
            if(((i%4)||(!(i%100)))&&x<=365) {
                break;
            }
            if((i%4)||(!(i%100))&&x>365) {x-=365;++ye;}
            if(((!(i%4)&&(i%100))||(!(i%400)))&&x>366) {x-=366;++ye;}
        }
    }
    
}


il void work_month(){
    if(flag2) ++mo[2];
    for(R int i=1;i<=12;++i){
        if(x>mo[i]) x-=mo[i];
        else{
            mon=i;
            break;
        }
    }
    if(flag2) --mo[2];
    if((ye==1582&&mon<10)||(ye==1582&&mon==10&&da<=4)) x-=10;
}


//--------------------判断他的具体时间----------------------

signed main(){
    freopen("julian.in","r",stdin);
    freopen("julian.out","w",stdout);
    q=read();
    while(q--){
        x=read();int y=x;
        flag1=0;flag2=0;flag3=0;ye=0;mon=0;da=1;
        work_year();
        if(!flag1) {
            if(!(ye-1)%4) flag2=1;;
            if(!flag1&&ye<=1582&&!(ye%4)) flag2=1;
        }
        if(flag1&&ye<1582) {
            if(!ye%4) flag2=1;
            else flag2=0;
        }
        if(flag1&&ye>1582){
            if(((!(ye%4))&&(ye%100))||!(ye%400)) flag2=1;
            else flag2=0;
        }
        work_month();da+=x;
        if(!flag1) ye=4713-ye;
        //cout<<"flag1="<<flag1<<" "<<"flag2="<<flag2<<endl; 
        //if(flag1&&(ye>1582||(ye==1582&&mon>10)||(ye==1582&&mon==10&&da>4))) da+=10;
        if(da>mo[mon]) da-=mo[mon++];
        if(mon>12) mon-=12,ye++;
        printf("%lld %lld %lld ",da,mon,ye);
        if(!flag1)  printf("BC\n");
        else printf("\n");
    }      
    return 0;
}





















