#include<iostream>
#include<cstdio>
#include<algorithm>
using namespace std;
int n;
int k;
int t;
int b[10000];
int a[10000];
int main()
{
	/*
  freopen("snakes.in","r",stdin);
  freopen("snakes.out","w".stdout);
	*/
	scanf("%d",&n);
	if(n==1)
	{
		scanf("%d",&t);
		for(int j=1;j<=t;j++){
			scanf("%d",&a[j]);
		}
			sort(a+1,a+t+1);
			
			if(t==3){
			if(a[3]-a[1]>a[2])
			    {
				cout<<"1"<<endl;
					return 0;
	
				}	
			else{
				cout<<"3"<<endl;
				return 0;
			
				 }
			if(a[1]==a[2]&&a[2]==a[3])
			{
				cout<<"3"<<endl;
				return 0;
			
				}
	    	}
			return 0;
		}
	
		else{	
			
			
			
			
		scanf("%d",&t);
		for(int j=1;j<=t;j++){
			scanf("%d",&a[j]);
		}
			sort(a+1,a+t+1);
			
			if(t==3){
			if(a[3]-a[1]>a[2])
			    {
				cout<<"1"<<endl;
		
				}	
			else{
				cout<<"3"<<endl;
				
			
				 }
			if(a[1]==a[2]&&a[2]==a[3])
			{
				cout<<"3"<<endl;

			
				}
	    	}
			
			for(int i=1;i<=n-1;i++){

			
		scanf("%d",&k);
			for(int m=1;m<=k;m++){
				int p,q;
				scanf("%d %d",&q,&p);
				a[q]=p;
				}
			sort(a+1,a+k+1);
			if(t==3){
			if(a[3]-a[1]>a[2])
			    {
				cout<<"1"<<endl;
				continue;
				}	
			else{
				cout<<"3"<<endl;
				continue;
				 }
			if(a[1]==a[2]&&a[2]==a[3])
			{
				cout<<"3"<<endl;
				continue;
				}
	    	}
		}
			}

		

	}
	
