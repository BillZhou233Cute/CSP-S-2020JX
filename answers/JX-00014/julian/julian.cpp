#include<cstdio>
using namespace std;
const int N=1e6;
int q,m[13]={0,31,28,31,30,31,30,31,31,30,31,30,31};
long long a[N];
struct s
{
     long long year;
     int month;
     int day;
}ans[N];
void work()
{
    scanf("%d",&q);
    for(int i=1;i<=q;i++)
    {
        scanf("%lld",&a[i]);
        ans[i].year=-4713;
        ans[i].month=1;
        ans[i].day=1;
        while(a[i])
        {
            if(ans[i].year==0)
            {
                ans[i].year=1;
            }
            if(ans[i].year<1852||(ans[i].year==1852&&ans[i].month<10)||(ans[i].year==1852&&ans[i].month==10&&ans[i].day<=4))//julian
            {
                if((ans[i].year+1)%4==0)
                {
                    m[2]=29; 
                }
                else
                {
                    m[2]=28;
                }
                for(int j=1;j<=12;j++)
                {
                    if(a[i]>=m[j])
                    {
                       a[i]-=m[j];
                       ans[i].month++; 
                    }
                    else
                    {
                       ans[i].day+=a[i];
                       a[i]=0;
                    }
                }
                if(ans[i].month>12)
                { 
                    ans[i].year++;
                    ans[i].month-=12;
                }
            }
            else if(ans[i].year==1852&&(ans[i].month==10&&ans[i].day>=4&&ans[i].day<=14))//断开天数
            {
                ans[i].day+=11;
            }
            else//格里高历
            {
                if(((ans[i].year)%4==0&&(ans[i].year)%100!=0)||ans[i].year%400==0)
                {
                    m[2]=29;
                }
                else
                {
                    m[2]=28;
                }
                for(int j=1;j<=12;j++)
                {
                    if(a[i]>=m[j])
                    {
                        a[i]-=m[j];
                        ans[i].month++;
                    }
                    else
                    {
                        ans[i].day+=a[i];
                        a[i]=0;
                    }
                }
                if(ans[i].month>12)
                {
                    ans[i].year++;
                    ans[i].month-=12;
                }
            }
        }
        if(ans[i].year>0)
        printf("%d %d %lld\n",ans[i].day,ans[i].month,ans[i].year);
        else
        printf("%d %d %lld BC\n",ans[i].day,ans[i].month,-ans[i].year);
    }
}
int main()
{
   freopen("julian.in","r",stdin);
   freopen("julian.out","w",stdout);
    work();
    return 0;
}


