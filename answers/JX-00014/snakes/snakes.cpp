#include<cstdio>
using namespace std;
const int N=1e4;
int n,T,x,y,k,flag_max,flag_min,max=-1,min=9999999,res=0;
long long o[N],a[N]; 
bool check(int xx,int yy)
{
     long long temp=a[xx]-a[yy];
	int t=0;
     for(int i=1;i<=n;i++)
     {
         if(temp>a[i]&&i!=yy)
         {
             t++;
         }
     }
     if(t==0)
     return false;
     return true;
}
int main()
{
	freopen("snakes.in","r",stdin);
	freopen("snakes.out","w",stdout);
    scanf("%d",&T);
    for(int q=1;q<=T;q++)
    {
        if(q==1)
        {
            scanf("%d",&n);
            for(int i=1;i<=n;i++)
            {
                scanf("%lld",&o[i]);
                a[i]=o[i];
            }
        }
        else
        {
             scanf("%d",&k);
             for(int i=1;i<=k;i++)
             {
                 scanf("%d%d",&x,&y);
                 a[x]=y;
             }
        }
        while(1)
        {
			
            for(int i=1;i<=n;i++)
            {
                if(a[i]>=max)
                {
                    max=a[i];
                    flag_max=i;
                }
                if(a[i]<=min&&a[i]!=-1)
                {
                    min=a[i];
                    flag_min=i;
                }
            }
            if(check(flag_max,flag_min))
            {
                a[flag_max]-=a[flag_min];
                a[flag_min]=-1;
                res++;
            }
            else
            {
                break;
            }
            max=-1;
            min=999999;
			if(res==n-1)
			{
				break;
			}
        }
        printf("%d\n",n-res);
        res=0;
    }
}

