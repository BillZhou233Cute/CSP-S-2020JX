#include<iostream>
#include<cstring>
#include<cstdio>
#include<cmath>
using namespace std;
int q,monthr[13]={0,31,29,31,30,31,30,31,31,30,31,30,31},
		monthp[13]={0,31,28,31,30,31,30,31,31,30,31,30,31},
		year[401]={366,365,365,365,366,365,365,365,366,365,
						    365,365,366,365,365,365,366,365,365,365,
			                366,365,365,365,366,365,365,365,366,365,
							365,365,366,365,365,365,366,365,365,365,
			                366,365,365,365,366,365,365,365,366,365,
			                365,365,366,365,365,365,366,365,365,365,
			                366,365,365,365,366,365,365,365,366,365,
			                365,365,366,365,365,365,366,365,365,365,
			                366,365,365,365,366,365,365,365,366,365,
			                365,365,366,365,365,365,366,365,365,365,//
			                365,365,365,365,366,365,365,365,366,365,
						    365,365,366,365,365,365,366,365,365,365,
			                366,365,365,365,366,365,365,365,366,365,
							365,365,366,365,365,365,366,365,365,365,
			                366,365,365,365,366,365,365,365,366,365,
			                365,365,366,365,365,365,366,365,365,365,
			                366,365,365,365,366,365,365,365,366,365,
			                365,365,366,365,365,365,366,365,365,365,
			                366,365,365,365,366,365,365,365,366,365,
			                365,365,366,365,365,365,366,365,365,365,//
			                365,365,365,365,366,365,365,365,366,365,
						    365,365,366,365,365,365,366,365,365,365,
			                366,365,365,365,366,365,365,365,366,365,
							365,365,366,365,365,365,366,365,365,365,
			                366,365,365,365,366,365,365,365,366,365,
			                365,365,366,365,365,365,366,365,365,365,
			                366,365,365,365,366,365,365,365,366,365,
			                365,365,366,365,365,365,366,365,365,365,
			                366,365,365,365,366,365,365,365,366,365,
			                365,365,366,365,365,365,366,365,365,365,//
			                365,365,365,365,366,365,365,365,366,365,
						    365,365,366,365,365,365,366,365,365,365,
			                366,365,365,365,366,365,365,365,366,365,
							365,365,366,365,365,365,366,365,365,365,
			                366,365,365,365,366,365,365,365,366,365,
			                365,365,366,365,365,365,366,365,365,365,
			                366,365,365,365,366,365,365,365,366,365,
			                365,365,366,365,365,365,366,365,365,365,
			                366,365,365,365,366,365,365,365,366,365,
			                365,365,366,365,365,365,366,365,365,365,
			                366};
int main()
{int i,j;
 freopen("julian.in","r",stdin);
 freopen("julian.out","w",stdout);
  scanf("%d",&q);
  for(j=1;j<=q;j++)
  {int r,y=0,m=0,d=0;
	scanf("%d",&r);
	r+=1;
	if(r<=1721424)
  	  {y=4713-(r/1461)*4;
	    r%=1461;
	    if(r<=366)
		     {for(i=1;i<=12;i++)
				  {m++; d=r; r-=monthr[i];
				    if(r<=0) break;
				  }
			   printf("%d %d %d BC\n",d,m,y);
			   continue;
		     }
	    r-=366;
		if(r<=1095)
		  {y-=r/365+1;
		    r%=365;
		    for(i=1;i<=12;i++)
				    {m++; d=r; r-=monthp[i];
				      if(r<=0) break;
				    }
		  printf("%d %d %d BC\n",d,m,y);
		  continue;
	     }
	   r-=1095;
	   y-=1;
       for(i=1;i<=12;i++)
				  {m++; d=r; r-=monthr[i];
				    if(r<=0) break;
				  }
			   printf("%d %d %d BC\n",d,m,y);
			   continue;
	   
	  }
   if(1721424<r&&r<2299161)
      {r=r-1721424;
		y=1+(r/1461)*4;
	    r%=1461;
	    if(r<=365*3)
		     {y+=r/365;
			   r%=365;
			   for(i=1;i<=12;i++)
				  {m++; d=r; r-=monthp[i];
				    if(r<=0) break;
				  }
			   printf("%d %d %d\n",d,m,y);
			   continue;
		     }
	    r-=3*365;
	    y+=3;
		for(i=1;i<=12;i++)
				  {m++; d=r; r-=monthr[i];
				    if(r<=0) break;
				  }
		printf("%d %d %d\n",d,m,y);
		continue;
	  }
	if(r>=2299161)
	  {r=r-2299161;
		y=1582;
		if(r<=17) 
		  {m=10;
			d=14+r;
			printf("%d %d %d\n",d,m,y);
			continue;
		  }
		 r-=17;
		if(r<=61)
		    {m=10;
			  for(i=11;i<=12;i++)
				  {m++; d=r; r-=monthp[i];
				    if(r<=0) break;
				  }
			   printf("%d %d %d\n",d,m,y);
			   continue;
			}
		r-=61;
		y=1583;
		 if(r<=365)
		    {for(i=1;i<=12;i++)
				  {m++; d=r; r-=monthp[i];
				    if(r<=0) break;
				  }
			   printf("%d %d %d\n",d,m,y);
			   continue;
			}
		r-=365;
		for(i=0;i<=400;i++)
     		{y++; 
			  if(r-year[i]<=0) break;
			  r-=year[i];
			  if(i==400) i=0;
			}
		if((i%4==0&&i%100!=0)||i%400==0){
		for(i=1;i<=12;i++)
				  {m++; d=r; r-=monthr[i];
				    if(r<=0) break;
				  }
			   printf("%d %d %d\n",d,m,y);
			   continue;}
		else 		for(i=1;i<=12;i++)
				  {m++; d=r; r-=monthp[i];
				    if(r<=0) break;
				  }
			   printf("%d %d %d\n",d,m,y);
			   continue;
	  }
  }
 // j=0;for(i=0;i<=400;i++)  j+=year[i];cout<<j;
 return 0;
}
