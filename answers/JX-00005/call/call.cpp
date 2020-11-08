#include<iostream>
#include<fstream>
#include<cstdio>
#include<string>
#include<algorithm>
#include<stack>
#include<queue>
#include<cmath>
#include<vector>
using namespace std;

int a[10000];
int n,m;

struct C{
	int node;
	int k;
	int v;
	int b[10000];
}c[10000];


int main(){
	ifstream cin("call1.in");
	ofstream cout("call.out");
    cin>>n;
    for (int i=1;i<=n;i++) cin>>a[i];
	//					for (int i=1;i<=n;i++) cout<<a[i]<<' ';cout<<'\n';
		cin>>m;
	for (int i=1;i<=m;i++){
		int t;
		cin>>t;
		c[i].node=t;
		if (t==3){
			cin>>c[i].k;
			for (int j=1;j<=c[i].k;j++) cin>>c[i].b[j];
			
		}
		else if (t==2) cin>>c[i].k;
        else cin>>c[i].k>>c[i].v;
		
		}
	int q;
		cin>>q;
	for (int i=1;i<=q;i++){
	    int d;
		cin>>d;//cout<<d<<'\n';
;		if (c[d].node==1) {
			 a[c[d].k]+=c[d].v;
		}
		else if (c[d].node==2){
			for (int j=1;j<=n;j++) a[j]*=c[d].k;
				//for (int i=1;i<=n;i++) cout<<a[i]<<' ';cout<<'\n';
			}
	    else{
			for (int u=1;u<=c[d].k;u++){
				if (c[c[d].b[u]].node==1) {
			      a[c[c[d].b[u]].k]+=c[c[d].b[u]].v;
		           }
		       else{
		           	for (int j=1;j<=n;j++)  a[j]*=c[c[d].b[u]].k;
			   }
			
				
				}
			
			
			}
	
	}	
	
	for (int i=1;i<=n;i++) cout<<a[i]<<' ';cout<<'\n';
		
		
		
		
	cin.close();
	cout.close();
	return 0;
}