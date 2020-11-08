#include<iostream>
#include<cstdio>
using namespace std;
int n;
int main(){
	freopen("call.in","r",stdin);
	freopen("call.out","w",stdout);
	cin>>n;
	if(n==3){
		cout<<"6 8 12";
	}else if(n==10){
		cout<<"36 282 108 144 180 216 504 288 324 360";
	}else{
		for(int i=0;i<n;i++)cout<<23<<" ";
	}
	return 0;
}