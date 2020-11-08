#include <iostream>
#include <cstdio>
using namespace std;
int T;
int a[100010];

int main(){
	freopen("snakes.in","r",stdin);
	freopen("sankes.out","w",stdout);
	cin>>T;
	for(int i=1;i<=T;i++){
		cin>>a[i];
		}
		int n;
		for(int j=1;j<=n;j++){
			cin>>b[j];
			}
		int max=0;
		for(int i=1;i<=n;i++){
			if(a[i]>max)
				max=a[i];
			}
			if(max==a[i+1]){
				max=a[i+1];
				}
			}
			int min=999999;
		for(int i=1;i<=n;i++){
			if(a[i]<min){
				min=a[i];
			}
			if(min=a[i+1]0{
				min=a[i];
				}
			}
			for(int i=1;i<=n;i++){
				if(max-min>=a[i]){
					cout<<n;
					}
				}
				
	return 0;
	}