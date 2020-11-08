#include<bits/stdc++.h>
#include<cstdio>
#include<iostream>
#include<deque>

using namespace std;
typedef unsigned long long LL;
#define Mo (998244353)
LL FT[100000];
deque<int> FN[100000];
int N[1000000];
int n,m;
void DF(int a)
{
    //cout<<"a="<<a<<"FT[a]="<<FT[a]<<endl;
    switch(FT[a])
    {
        case 1:
            {
                //cout<<"1FN="<<FN[a][0]<<endl;
                N[FN[a][0]]+=FN[a][1];
                N[FN[a][0]]%=Mo;
                break;
            }
            case 2:
            {
                //cout<<"2FN="<<FN[a][0]<<endl;
                for(int i=1;i<=n;i++)
                {
                    N[i]=(N[i]*FN[a][0])%Mo;
                }
                break;
            }
                case 3:
                {
                    //cout<<"3FN="<<FN[a][0]<<endl;
                    for(int i=1;i<=FN[a][0];i++)
                    {
                        //cout<<FN[a][i]<<endl;
                        DF(FN[a][i]);
                    }
                    break;
                }
    }
}
int main()
{
    freopen("call.in","r",stdin);
    freopen("call.out","w",stdout);
    cin>>n;
    //cout<<n<<endl;
    for(int i=1;i<=n;i++)
    {
        cin>>N[i];  
    }
    cin>>m;
    //cout<<m<<endl;
    for(int i=1;i<=m;i++)
    {
        cin>>FT[i];
        switch(FT[i])
        {
            case 1:{
                    int a,b;
                    cin>>a>>b;
                    FN[i].push_back(a);
                    FN[i].push_back(b%Mo);
                    break;
                }
            case 2:{
                    int a;
                    cin>>a;
                    FN[i].push_back(a%Mo);
                break;
                }
            case 3:{
                    int c;
                    cin>>c;
                    FN[i].push_front(c);
                    for(int j=0;j<c;j++)
                    {
                        int z;cin>>z;
                        FN[i].push_back(z);
                    }
                    break;
                }
        }
    }
    int Q;cin>>Q;
    //cout<<Q<<endl;
    for(int i=1;i<=Q;i++)
    {
        int z;cin>>z;
        //cout<<"z="<<z<<endl;
        DF(z);
    }
    //cout<<Q<<endl;
    for(int i=1;i<=n;i++)
        cout<<N[i]<<' ';
}