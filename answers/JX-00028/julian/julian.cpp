#include<bits/stdc++.h>
using namespace std;
const int N=15;
int q,i,a,n=-4713,y=1,r=1,j=1;
int main()
{
    freopen("julian.in","r",stdin);
    freopen("julian.out","w",stdout);
    cin>>q;
    for(a=1;a<=q;a++)
     {
       cin>>i;
       if(i<366)
         while(i>0)
	   {
             y++;
	     if(i<=213){
                if(y%2==1)i=i-31;
	        else if(y==2)i=i-29;
	        else i=i-30;
                if(y>2&&i<29)r=r+i;i=0;
	     }
             else if(y%2==1)i=i-30;
	          else i=i-31;
	   }
       else 
	 {
           while(i>0)
	     {
	       if(i>365)
                 if(n==-1)n=1;i=i-366;
		 if((n+1)%4==0){
            	   i=i-366;
                   n++;       
                 }
		 else i=i-365;n++;
	        else if(n<0){
                         while(i>0)
                           y++;
	                   if(i<=213){
                             if(y%2==1)i=i-31;
	                     else if(y==2&&n%4==0)i=i-29;
                             else if(y==2&&n%4!=0)i=i-28;
	                     else i=i-30;
                             if(y>2&&i<29)r=r+i;i=0;
	                     }
                           else if(y%2==1)i=i-30;
	                   else i=i-31;
                           return 0;
                         }
                 }
	     }
         }
     }
     if(n<0)cout<<r<<" "<<y<<" "<<(n*(-1))<<" BC";
     else cout<<r<<" "<<y<<" "<<n;
     return 0; 
}
