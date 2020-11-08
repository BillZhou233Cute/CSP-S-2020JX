#include <iostream>
#include <cstdio>
#include <string>
#include <cmath>
using namespace std;

inline bool bget(int x){//to check the number in B
	int tmp=x;
	tmp=tmp>>1;
	return x-(tmp<<1);
}

inline int read(){//quick read
	char ch;
	int x=0;
	ch=getchar();
	while(ch>='0'&&ch<='9'){
		x=(x<<3)+(x<<1)+(ch^48);
		ch=getchar();
	}
	return x;
}

//---------main function---------//
int main(){
	freopen("zoo.in","r",stdin);
	freopen("zoo.out","w",stdout);
	int n,m,c,k,ans=0;
	
	n=read();//quick read
	m=read();
	c=read();
	k=read();
	
	int ki=pow(2,k);//how many the animals in wild
	
	int a[n],que[m][2];
	bool ch[n];//have or haven't this kind of animal
	bool list[m];//which kinds of food to buy
	
	for(int i=0;i<n;i++){
		a[i]=read();
		ch[a[i]]=1;//tag the animal which the zoo has
	}
	for(int i=0;i<m;i++){//<<law of feed>>
		que[i][0]=read();
		que[i][1]=read();
	}
	
//----------food to buy-----------
	for(int i=0;i<n;i++){
		for(int j=0;j<m;j++){
			if(bget(a[i]>>que[j][0]))
			list[j]=1;
		}
	}
//------------------------------------
	
	for(int i=0;i<ki;i++){
		int flag=true;
		if(ch[i])continue;
		for(int j=0;j<m;j++){
			if(bget(i>>(que[j][0]))==list[i])
				flag=false;
		}
		if(!flag)ans++;
	}
	cout<<ans;
	return 0;	
}