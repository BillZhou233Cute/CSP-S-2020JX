#include<iostream>
#include<cstdio>
#include<cstring>
#include<vector>
using namespace std;
int n,m,q,c,x;
int num[20005];
struct han
{
  int ty;
  int p,v;
  vector<int>id;
}h[20005];
void cz3(int f)
{
    if(h[f].ty==1)
    {
	num[h[f].p]+=h[f].v;
    }
    else if(h[f].ty==2)
    {
	for(int i=1;i<=n;i++)
	{
	  num[i]*=h[f].v;
	}
    }
    else if(h[f].ty==3)
    {
	for(int i=0;i<h[f].id.size();i++)
	cz3(h[f].id[i]);
    }
    return;
}
int main()
{
  freopen("T3.in","r",stdin);
  freopen("T3.out","w",stdout);
  cin>>n;
  for(int i=1;i<=n;i++)
  scanf("%d",&num[i]);
  cin>>m;
  for(int i=1;i<=m;i++)
  {
    int opt;
    scanf("%d",&opt);
    if(opt==1) {scanf("%d%d",&h[i].p,&h[i].v);h[i].ty=1;}
    else if(opt==2) {scanf("%d",&h[i].v);h[i].ty=2;}
    else if(opt==3) 
    {
	scanf("%d",&c);
	for(int j=1;j<=c;j++)
	{
	  scanf("%d",&x);
	  h[i].id.push_back(x);
	}
	h[i].ty=3;
    }
  }
  cin>>q;
  for(int i=1;i<=q;i++)
  {
    int f;
    scanf("%d",&f);
    if(h[f].ty==1)
    {
	num[h[f].p]+=h[f].v;
    }
    else if(h[f].ty==2)
    {
	for(int i=1;i<=n;i++)
	{
	  num[i]*=h[f].v;
	}
    }
    else if(h[f].ty==3)
    {
	for(int i=0;i<h[f].id.size();i++)
	cz3(h[f].id[i]);
    }
  }
  for(int i=1;i<=n;i++)
  {
  	printf("%d ",num[i]);
  }
  return 0;
}
	  




    
	
