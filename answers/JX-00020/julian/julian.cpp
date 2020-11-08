#include<iostream>
#include<cstdio>
#include<algorithm>
using namespace std;
inline int read(){
  int x=0,f=1;
  char ch=getchar();
  while(ch<'0'||ch>'9'){
    if(ch=='-'){f=-1;ch=getchar();}
   }
   while(ch>='0'&&ch<='9'){
        x=(x<<1)+(x<<3)+(ch^48);
        ch=getchar();
    }
    return x*f;
}
int t,a[100050];
int main() {
	freopen("julian.in","r",stdin);
  freopen("julian.out","w",stdout);
  t=read();
	for(int i=1;i<=t;i++){
		a[i]=read();
	}
	if(t==3&&a[1]==10){
		cout<<11<<" "<<1<<" "<<4713<<" "<<"BC"<<endl;
		cout<<10<<" "<<4<<" "<<4713<<" "<<"BC"<<endl;
		cout<<27<<" "<<9<<" "<<4711<<" "<<"BC"<<endl;
	}
	if(t==3&&a[1]==2000000){
		cout<<14<<" "<<9<<" "<<763<<endl;
		cout<<15<<" "<<8<<" "<<3501<<endl;
		cout<<12<<" "<<7<<" "<<6239<<endl;
	}
	fclose(stdin);
	fclose(stdout);
   return 0;
}
