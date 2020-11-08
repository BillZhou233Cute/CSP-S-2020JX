#include<bits/stdc++.h>
using namespace std;
int main ()
{
    freopen("julian.in","r" ,stdin);
	freopen("julian.out","w",stdout);
    int Q,r;
            //    1  2  3  4  5  6  7  8  9  10 11 12 月 366d
    int s1[13]={0,31,29,31,30,31,30,31,31,30,31,30,31};
            //    1  2  3  4  5  6  7  8  9  10 11 12 月 365d
    int s2[13]={0,31,28,31,30,31,30,31,31,30,31,30,31};
	int s3[13]={0,31,29,31,30,31,30,31,31,30,21,30,31};
    cin>>Q;
    while(Q--!=0)
    {
        int y=-4713,m=1,d=1;
        cin>>r;
		while(r>0)
	   	{	
			if(y<0)
				{
					if((y+1)%4==0)
		            {
		                if(r>=365)
		                {
		                    y++;
		                    if(y==0)
		                    y++;
		                    r-=365;
		                }     
		                else
		                {
		                    for(int i=m;i<=12;i++)
		                    {
		                         if(r>=s2[i])
		                         {
		                            r-=s2[i];
		                            m++;
		                         }
		                          else
		                          {
		                             d+=r;
		                             r=0;
		                             break;
		                          }
		                    }
		                }        
					}
					else
					{
						if(r>=366)
		                {
		                    y++;
		                    if(y==0)
		                    y++;
		                    r-=366;
		                }     
		                else
		                {
		                    for(int i=m;i<=12;i++)
		                    {
		                         if(r>=s1[i])
		                         {
		                            r-=s1[i];
		                            m++;
		                         }
		                          else
		                          {
		                             d+=r;
		                             r=0;
		                             break;
		                          }
		                    }
		                }
					}
		        }   
			if(y>0)
			{
				if(y==1582)
				{
					if(r>=356)
						y++;
					else
					{
						for(int i=m;i<=12;i++)
		                    {
		                         if(r>=s3[i])
		                         {
		                            r-=s3[i];
		                            m++;
		                         }
		                          else
		                          {
		                             d+=r;
		                             r=0;
		                             break;
		                          }
							}
					}		
				}
				if(y%4==0)
				{
					if(r>=365)
		                {
		                    y++;
		                    r-=365;
		                }     
		                else
		                {
		                    for(int i=m;i<=12;i++)
		                    {
		                         if(r>=s2[i])
		                         {
		                            r-=s2[i];
		                            m++;
		                         }
		                          else
		                          {
		                             d+=r;
		                             r=0;
		                             break;
		                          }
		                    }
		                }        
				}
				else
				{
					if(r>=366)
		                {
		                    y++;
		                    r-=366;
		                }     
		                else
		                {
		                    for(int i=m;i<=12;i++)
		                    {
		                         if(r>=s1[i])
		                         {
		                            r-=s1[i];
		                            m++;
		                         }
		                          else
		                          {
		                             d+=r;
		                             r=0;
		                             break;
		                          }
		                    }
		                }		
				}
			}
		}
		if(y>0)
			cout<<d<<" "<<m<<" "<<y<<" "<<endl;
		else
		{
			y=0-y;
			cout<<d<<" "<<m<<" "<<y<<" BC"<<endl;
		}

	}  
    return 0;
}
