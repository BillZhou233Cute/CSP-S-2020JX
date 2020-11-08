#include<iostream>
#include<cstdio>
#include<vector>
#include<algorithm>
#include<bitset>
using namespace std;
int T,n,a[1000001],k;
void rd(int &x)
{
	char ch=getchar();
	x=0;
	while(ch<'0'||ch>'9')
		ch=getchar();
	while(ch>='0'&&ch<='9')
	{
		x=x*10+ch-48;
		ch=getchar();
	}
	return ;
}
struct Snake
{
	int ps;
	int vl;
}nw;
bool operator <(const Snake &as,const Snake &bs)
{
	if(as.vl!=bs.vl)
		return as.vl<bs.vl;
	return as.ps<bs.ps;
}
vector<Snake> vc;
vector<Snake>::iterator it;
bitset<1000001> bt;
int del_tp,b[1000001],cnt,lst;
bool dfs(int x)
{
	bool flg=true;
	while(true)
	{
		if(del_tp==vc.size()-2)
			return false;
		//cout<<"QAL"<<vc[del_tp+1].ps<<" "<<vc[vc.size()-1].ps<<endl;
		if(!flg)
			if(b[vc[del_tp+1].ps]!=0)
			{
				if(dfs(vc[vc.size()-1].ps))
					return false;
				if(vc[del_tp+1].ps==x)
					return true;
				return false;
			}
		lst=vc.size()-1;
		b[vc[lst].ps]=cnt;
		vc[lst].vl-=vc[(++del_tp)].vl;
		nw=vc[lst]; vc.pop_back();
		vc.insert(lower_bound(vc.begin()+del_tp+1,vc.end(),nw),nw);
		flg=false;
	}
	return false;
}
int main()
{
	freopen("snakes.in","r",stdin);
	freopen("snakes.out","w",stdout);
	scanf("%d",&T);
	for(int w=1;w<=T;w++)
	{
		if(w==1)
		{
			scanf("%d",&n);
			for(int i=1;i<=n;i++)
				rd(a[i]);
		}
		if(w!=1)
		{
			scanf("%d",&k);
			while(k--)
			{
				int x,y;
				rd(x); rd(y);
				a[x]=y;
			}
		}
		vc.clear();
		del_tp=-1;
		bt.reset();
		for(int i=1;i<=n;i++)
			b[i]=0;
		for(int i=1;i<=n;i++)
		{
			nw.ps=i;
			nw.vl=a[i];
			vc.push_back(nw);
		}
		sort(vc.begin(),vc.end());
		cnt=0;
		for(int i=1;i<=800;i++)
		//while(true)
		{
			cnt++;
			//cout<<"R "<<cnt<<" "<<vc[del_tp+1].ps<<" "<<vc[vc.size()-1].ps<<endl;
			if(del_tp==vc.size()-2)
			{
				printf("1\n");
				break;
			}
			if(b[vc[del_tp+1].ps]!=0)
			{
				int ttl=b[vc[del_tp+1].ps];
				bool vl=dfs(vc[vc.size()-1].ps);
				//cout<<"vlrt"<<vl<<endl;
				if(vl==true)
				{
					//cout<<n<<" "<<cnt<<endl;
					printf("%d\n",n-cnt+1);
					break;
				}
				printf("%d\n",n-ttl+1);
				break;
			}
			lst=vc.size()-1;
			b[vc[lst].ps]=cnt;
			vc[lst].vl-=vc[(++del_tp)].vl;
			nw=vc[lst]; vc.pop_back();
			vc.insert(lower_bound(vc.begin()+del_tp+1,vc.end(),nw),nw);
		}
	}
	return 0;
}