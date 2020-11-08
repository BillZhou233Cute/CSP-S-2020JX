#include<iostream>
#include<cstdio>
#include<algorithm>
using namespace std;
int t,n;
struct sn
{
  int id,v;
}s[2005];
sn bf[2005];
bool cmp(sn a,sn b)
{
  if(a.v==b.v) return a.id>b.id;
  return a.v>b.v;
}
int main()
{
  freopen("snakes.in","r",stdin);
  freopen("snakes.out","w",stdout);
  cin>>t;
  t--;
  cin>>n;
  int ans=n; 
int kkk=n;
  for(int i=1;i<=n;i++)
  {
    scanf("%d",&s[i].v);
    s[i].id=i;
    bf[i].id=s[i].id;
    bf[i].v=s[i].v;
  }
  sort(s+1,s+1+n,cmp);
  for(int i=1;i<=n;i++)
  {
    for(int j=n;j!=0;j--)
    {
	if(s[j].v!=-1)
	{
	if(s[i].v-s[j].v>s[i-1].v)
	  {
		s[i].v-=s[j].v;
		s[j].v=-1;
		ans--;
	  }
	else if(s[i].v-s[j].v==s[i-1].v)
	  {
		if(s[i].id>s[i-1].id) 
		{
		  s[i].v-=s[j].v;
		  s[j].v=-1;
		  ans--;
		}	
	  }
	}
    }
    sort(s+1,s+1+ans,cmp);
  }
  for(int i=1;i<=n;i++)
  {
    s[i].id=bf[i].id;
    s[i].v=bf[i].v;
  }
  cout<<ans<<endl;
  while(t--)
  {
	ans=kkk;
	scanf("%d",&n);
	for(int i=1;i<=n;i++)
	{
	  int a,b;
	  scanf("%d%d",&a,&b);
	  s[a].v=b;
	}
	sort(s+1,s+1+kkk,cmp);
  for(int i=1;i<=kkk;i++)
  {
    for(int j=kkk;j!=0;j--)
    {
	if(s[j].v!=-1)
	{
	if(s[i].v-s[j].v>s[i-1].v)
	{
		s[i].v-=s[j].v;
		s[j].v=-1;
		ans--;
	}
	else if(s[i].v-s[j].v==s[i-1].v)
	{
		if(s[i].id>s[i-1].id) 
		{
		  s[i].v-=s[j].v;
		  s[j].v=-1;
		  ans--;
		}	
	}
	}
    }
    sort(s+1,s+1+ans,cmp);
  }
  for(int i=1;i<=kkk;i++)
  {
    s[i].id=bf[i].id;
    s[i].v=bf[i].v;
  }
  printf("%d\n",ans);
  }
  return 0;
}
	  
    
