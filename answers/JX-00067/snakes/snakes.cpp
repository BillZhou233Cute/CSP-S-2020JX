#include<bits/stdc++.h>
#include<cstdio>
#include<iostream>
#include<deque>

using namespace std;
typedef unsigned long long LL;
#define Ds (1000000)
LL T;int n;
LL A[Ds];
LL F()
{
    int _A[Ds],Ans=n;
    for(int i=1;i<=n;i++)
        {
            _A[i]=A[i];
        }
        
    while(1)
    {
        int max=1,min=1,max2=1;
        for(int i=1;i<=n;i++)
        {
            if(_A[i]!=-1)
            {
                if(_A[i]>_A[max])
                {
                    max2=max;max=i;
                }
                else if(_A[i]>_A[max2]) 
                {max2=i;}
                    
                if(_A[i]<_A[min]) min=i;
            }
        }
        if(max2==min) 
        {
           if( _A[max2]<_A[max]) return 1;
               else return 2;
        }
        if(Ans==1)return 1;
        if((_A[max2]<(_A[max]-_A[min]))||(_A[max2]==(_A[max]-_A[min])&&max<max2))
        {
            _A[max]=_A[max]-_A[min];
            _A[min]=-1;
            Ans--;
        }else return Ans;
    }
}
int main()
{
    freopen("snakes0.in","r",stdin);
    freopen("snakes.out","w",stdout);
    cin>>T>>n;
    for(int i=1;i<=n;i++)
    {
        cin>>A[i];
    }
    cout<<F()<<endl;
    while(--T)
    {
        int k;cin>>k;
        for(int i=0;i<k;i++)
        {
            int aa,ba;cin>>aa>>ba;
            A[aa]=ba;
        }
        /*
        for(int i=1;i<=n;i++)
                cout<<A[i]<<' ';
            cout<<endl;
        */
        cout<<F()<<endl;
    }
}