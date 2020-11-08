#include<bits/stdc++.h>
using namespace std;
int d[13];
int n,a,ans1=1,ans2=1,ans3=4713;
int main()
{
	d[1]=31;d[3]=31;d[4]=30;d[5]=31;d[6]=30;d[7]=31;d[8]=31;d[9]=30;d[10]=31;d[11]=30;d[12]=31;
	freopen("julian.in","r",stdin);
	freopen("julian.out","w",stdout);
	cin>>n;
	for(int i=1;i<=n;i++)
	{
       cin>>a;
		if(a<1721424){ans1=1;ans2=1;ans3=4713;
									 ans3=ans3-4*(a/1461);a=a%1461;
								     if(a>366&&a<=731)
										 {ans3-=1;a=a-366;}
										 if(a>731&&a<=1096)
										 {ans3-=2;a=a-731;}
										 if(a>1096&&a<=1461)
										 {ans3-=3;a=a-1096;}
										 //cout<<a<<" ";
										 if((ans3-1)%4==0)d[2]=29;
                                     else d[2]=28;
								for(int i1=1;i1<=12;i1++)
									if(a-d[i1]<0)break;
										else {ans2++;a=a-d[i1];}
									 ans1=a+1;
									 cout<<ans1<<" "<<ans2<<" "<<ans3<<" "<<"BC"<<endl;
										continue;
								}
		if(a>=1721424&&a<=2299160){
			                            ans1=1;ans2=1;ans3=1;
			                           a=a-1721424;
			                            ans3=ans3+4*(a/1461);a=a%1461;
								     if(a>365&&a<=730)
										 {ans3+=1;a=a-365;}
										 if(a>730&&a<=1095)
										 {ans3+=2;a=a-730;}
										 if(a>1095&&a<=1461)
										 {ans3+=3;a=a-1095;}
										 //cout<<a<<" ";
										 if(ans3%4==0)d[2]=29;
                                     else d[2]=28;
								for(int i1=1;i1<=12;i1++)
									if(a-d[i1]<0)break;
										else {ans2++;a=a-d[i1];}
									 ans1=a+1;
									 cout<<ans1<<" "<<ans2<<" "<<ans3<<endl;
										continue;
		                          }
		if(a>2299160){a=a-2299160;
			                          ans1=15;ans2=10;ans3=1582;
			                          ans3=ans3+400*(a/146097);a=a%146097;
			                         /* while(a>d[ans2])
									  {
										    if(ans2==2){if(ans3%4==0||ans3%100!=0||ans3%400==0)a=a-29;
											else a=a-28;}
											else a=a-d[ans2];
											if(ans2+1>12){ans3++;ans2=1;}
											else ans2++;
									  }*/
			                          // cout<<ans3<<" "<<a<<" ";
			                           if(a>36525&&a<=73049)
			                           {ans3+=100;a=a-36525;}
										 if(a>73049&&a<=109573)
										 {ans3+=200;a=a-73049;}
										 if(a>109573&&a<=146097)
										 {ans3+=300;a=a-109573;}
										// cout<<ans3<<" ";
			                           if(4*(a/1461)>=18&&ans3/100%4!=3){ans3=ans3+4*(a/1461);a=a%1461+1;}
										   else  {ans3=ans3+4*(a/1461);a=a%1461;}
										   if((ans3+2)%400!=0&&(ans3+2)%100==0)
										   { if(a>365&&a<=730)
										 {ans3+=1;a=a-365;}
										 if(a>730&&a<=1095)
										 {ans3+=2;a=a-730;}
										 if(a>1095&&a<=1460)
										 {ans3+=3;a=a-1095;}
									 }
									 else {if(a>365&&a<=731)
										 {ans3+=1;a=a-365;}
										 if(a>731&&a<=1096)
										 {ans3+=2;a=a-731;}
										 if(a>1096&&a<=1461)
										 {ans3+=3;a=a-1096;}}
										 //cout<<a<<" ";
										 //if(ans3%4==0&&ans3%100!=0||a%400==0)a=a-366;
											 //else a=a-365;
												// ans3++;
										 if(((ans3+1)%4==0&&(ans3+1)%100!=0)||((ans3+1)%400==0))d[2]=29;
                                     else d[2]=28;
										//cout<<ans3<<" "<<a<<" ";
								for(int i1=9;i1<=20;i1++)
								{if(a-d[i1%12+1]<0)break;
										else {if(ans2+1>12){ans3++;ans2=1;a=a-d[i1%12+1];}
											else {ans2++;a=a-d[i1%12+1];}
											}
											//cout<<a<<" ";
										}
										ans1=ans1+a-1;
										if(ans1>d[ans2]){ans1=ans1-d[ans2];
											if(ans2+1>12){ans2=1;ans3++;}
											else ans2++;}
									 cout<<ans1<<" "<<ans2<<" "<<ans3<<endl;
										continue;
		                       }
	}
	return 0;
}