#include<cstdio>
#include<iostream>
#include<fstream>
#include<cmath>
using namespace std;
ifstream fin("zoo.in");
ofstream fout("zoo.out");
int n,m,c,k;
int ans;
int main(){
	 fin>>n>>m>>c>>k;int k01[k];int c01[c+1];int p1[m];int q[c+1];
	     
	    for(int i=1;i<=c;i++) c01[i]=0;  
			
			int p;
			 fin>>p;int k1=0;
			 while(k1<=k){
			    if(p>0) {k01[k1]=p%2;p=p/2;k1++;continue;}
				if(p==0) {k01[k1]=0;k1++;continue;}
			}
	     
			for(int i=1;i<=n-1;i++){
			     int p;
			      fin>>p;int k1=0;
			    while(k1<=k){
			        if(p>0) {
						if(p%2==k01[k1]) {p=p/2;k1++;continue;}
						if(p%2!=k01[k1]) {k01[k1]=1;p=p/2;k1++;continue;}
					}
				    if(p==0) break;
			    }
			} 
	   
	       for(int i=0;i<=m-1;i++) {
				fin>>p1[i]>>q[i];
				if(k01[p1[i]]==1)  c01[q[i]]=1;
			}
	        
			ans=1;long long l=2;
		
			for(int i=1;i<=k-1;i++) 	l=l*2;
	    
		for(int i=1;i<=l-1;i++){
			int ls[k];int p=i;int k1=0;
			 while(k1<=k){
			    if(p>0) {ls[k1]=p%2;k1++;p=p/2;continue;}
			    if(p==0) {ls[k1]=0;k1++;continue;}
			}
		   bool pd=false;
			for(int j=0;j<=m-1;j++){
			   int q1;
			   if(ls[p1[j]]==1){
				   q1=q[j];
				   if(c01[q1]==0) {pd=true;break;}
				}
		    }
		    if(pd==false) ans++;
		}	  
		
		fout<<ans-n;
		
		return 0;
	}