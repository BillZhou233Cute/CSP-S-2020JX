//
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
#define Ds (1000001)
typedef unsigned long long LL;
LL n,m,c;int k;
map<LL,pair<bool,LL> > qp;
deque<LL> pq[65];
LL now;
LL able;
int main()
{
    
    freopen("zoo.in","r",stdin);
    freopen("zoo.out","w",stdout);
    _Bdo(printf("start\n"););
    scanf("%lld %lld %lld %d",&n,&m,&c,&k);
    {
        
        LL Get;
        for(LL i=0;i<n;i++)
        {
            cin>>Get;
            _Bdo(printf("start- %lld\n",Get););
            now|=Get;
        }
    }_Bdo(printf("start\n"););
    _Bdo(printf("start\n"););
    {
         LL Gp,Gq;
        for(LL i=0;i<m;i++)
        {
            _Bdo(printf("start- %lld\n",i););
           
             _Bdo(printf("start- %lld\n",i););
            cin>>Gp;
            _Bdo(printf("starta%lld\n",Gp););
            cin>>Gq;
            _Bdo(printf("%lld %lld\n",Gp,Gq););
            if(qp.find(Gq)!=qp.end())
            {
                qp[Gq].second|=1<<Gp;
            }
            else
            {
                qp.insert(pair<LL,pair<bool,LL> > (Gq,pair<bool,LL>(0,1<<Gp)));
            }
            pq[Gq].push_back(Gq);
        }
    }
    _Bdo(printf("start\n"););
    {
        map<LL,pair<bool,LL> >::iterator iter=qp.begin();
        while(iter!=qp.end())
        {
            _Bdo(
                printf("it:%lld %lld %lld %lld\n",iter->first,iter->second.second,now,((now)&(iter->second.second)));
            )
            if(((now)&(iter->second.second))!=0)
            {
                _Bdo(printf("s\n"););
                iter->second.first=1;
                _Bdo(
                    printf("%lld 1\n",iter->first);
                )
            }   
            _Bdo(printf("s\n"););
            iter++;
            _Bdo(printf("s\n"););
        }
            
    }
    
    {
        deque<LL>::iterator iter;
        bool Y=0;
        for(int i=0;i<63;i++)
        {
            Y=1;
            iter=pq[i].begin();
            while(iter!=pq[i].end())
            {
                if(qp[*iter].first==0) {Y=0;break;}
            }
            if(Y==1)
            {
                able|=1<<k;
            }
        }
    }
    cout<<able-n;
    
}
