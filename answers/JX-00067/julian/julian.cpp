#include<bits/stdc++.h>
#include<cstdio>
#include<iostream>
#include<deque>
using namespace std;
#define _B 0
#if _B
    #define _Bdo(args...) {args}
#else
    #define _Bdo(args...)  
#endif
//1459
//576305 576582
//1718702
//2295007
int M[13]={31,28,31,30,31,30,31,31,30,31,30,31};
typedef unsigned long long LL;
void pds(LL A)
{
    //cout<<A<<endl;
    if(A<=1718702)
    {
        LL Y=0;
        while(A>=1459) {A-=1459;Y+=4;}
       // cout<<A<<endl;
        if(A<=364)
        {
            LL i=1;
            while(A>=(M[i]+((1)&&(i==2)))){A-=(M[ i++ ]+((1)&&(i==2)));}
            //cout<<A<<endl;
            cout<<A+1<<' '<<i<<' '<<4713-Y<<" BC"<<endl;
        }
        else
        {
            A-=364,Y++;LL i=1;
            while(A>=365) {A-=365;Y++;}
            while(A>=(M[i]+(0)&&(i==2))){A-=(M[ i++ ]+((0)&&(i==2)));}
            cout<<A+1<<' '<<i<<' '<<4713-Y<<" BC"<<endl;
        }
    }
    else
    {
        A-=1718702;
        LL Y=0;
        if(A<=576582)
        {
            while(A<=1459) {A-=1459;Y++;}
            
        }
        else
        {
            
        }
    }
}
int main()
{
    freopen("julian.in","r",stdin);
    freopen("julian.out","w",stdout);
    int T;
    cin>>T;
    while(T--)
    {
        int A;cin>>A;
        pds(A);
    }
}