#include<iostream>
#include<cstdio>
#include<cmath>
#include<cstring>
#include<string>
using namespace std;
int rq[20]={0,1,1,4713};
void julian(int a)
{
  for(int i=1;i<=a;i++)
    {
      if(rq[3]>-1582){
	      if(rq[3]%4!=0)
	      {
	        if(rq[2]==1||rq[2]==3||rq[2]==5||rq[2]==7||rq[2]==8||rq[2]==10||rq[2]==12){
				if(rq[1]>=31){ 
					rq[1]=1;
	               rq[2]++;
					continue;
				}
	            else
		        rq[1]++;
		        if(rq[2]>12){
		           rq[2]=1;
	    	       rq[3]--;
	            } continue;
	        }  
	    else if(rq[2]==2){
	        if(rq[1]>=28){
			rq[1]=1;
	         rq[2]++;
	        continue;
			}
	       else{
		   rq[1]++;
		   }
		if(rq[2]>12){
		  rq[2]=1;
		  rq[3]--;
		}continue;
		}
	    else
	      {
		 if(rq[1]>=30){
		  rq[1]=1;
		  rq[2]++;
			 continue;
		 }
		else
		  rq[1]++;
		if(rq[2]>12){
		  rq[2]=1;
		  rq[3]--;
		}continue;
		}
          } 
       else{
		     if(rq[2]==1||rq[2]==3||rq[2]==5||rq[2]==7||rq[2]==8||rq[2]==10||rq[2]==12){
	           if(rq[1]<31)
		       rq[1]++;
	          else{
		       rq[1]=1,
	           rq[2]++;
		       if(rq[2]>12){
		         rq[2]=1;
	    	     rq[3]--;
	 	       }continue;
	           }
	        }
	         else if(rq[2]==2){
	        if(rq[1]<29)
		    rq[1]++;
	        else
		    rq[1]=1,
	        rq[2]++;
	    	if(rq[2]>12){
		     rq[2]=1;
		     rq[3]--;
        	}continue;
	       }	
		   else
	      {
		   if(rq[1]<30){
		   rq[1]++;
		    }
	    	else
		  rq[1]=1,
		  rq[2]++;
		   if(rq[2]>12){
		    rq[2]=1;
		   rq[3]--;
		   }continue;
	      } 
	    }
      }
    }
  if(rq[3]>0)
    cout<<rq[1]<<" "<<rq[2]<<" "<<rq[3]<<" "<<"BC"<<endl;
  else
    cout<<rq[1]<<" "<<rq[2]<<" "<<-rq[3]+1<<" "<<endl;
}
int main()
{
  int day,q;
  freopen("julian.in","r",stdin);
  freopen("julian.out","w",stdout);
  cin>>q;
  for(int i=1;i<=q;i++)
    {
      cin>>day;
      julian(day);
	  rq[1]=1;rq[2]=1;rq[3]=4713;
    }
}
