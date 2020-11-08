#include<bits/stdc++.h>
using namespace std;
int i,j,k,t,m,n,s,x,y,a[1000001],b[1000001],f[1000000],ma,mi;
char c[1000000];
void et(int x){
m=0; s=n; 
	while (m==0){
	mi=1000000000; ma=-1;
   for(j=1; j<=n; j++){
	 if (mi>a[i] && a[i]>0) mi=a[i];
	if (ma<a[i]) {
		k=ma; x=y; ma=a[i]; y=i;
    }
}
  for (j=1; j<=n; j++) if (a[i]==k) x=i;
if (k<ma-mi) { cout<<s<<endl; m=1;}
if (k==ma-mi && y>x) { s--; a[y]=k; a[x]=-1; } else  { cout<<s<<endl; m=1;}
if (k<ma-mi) { s--; a[y]=ma-mi; a[x]=-1; }
if (s==1) { cout<<s<<endl; m=1; }
}
}
int main(){
//freopen("snakes1.in","r",stdin);
//freopen("snakes.out","w",stdout);
cin>>t;  
	cin>>n;
			for (j=1; j<=n; j++) cin>>a[j]; et(n);
	for (i=1;i<=t-1; i++){
	   scanf("%d",&k);
			for (j=1; j<=k; j++) { scanf("%d%d",&x,&a[x]); 
			}
			et(n);
	}	
	return 0;
}