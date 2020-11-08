#include<bits/stdc++.h>
using namespace std;
int day=1;
int day2=15;
int mon=1;
int mon2=10;
int year=-4713;
int year2=1582;
int main()
{
	freopen("julian.in","r",stdin);
	freopen("julian.out","w",stdout);
int n;
int a,b,c;
int nowy,nowm,nowd;
cin>>n;
int lnd=1,lnm=1,lny=-4713;
for(int i=1;i<=n;i++)
{
	
	cin>>a;
	c=a/1461;
	nowy=year+c*4;

	if(nowy>=0) nowy++;
		if(nowy>=1583)
		{
			int ans=10;
			for(int i=1583;i<=nowy;i++)
			{
				if(i%400!=0&&i%4==0&&i%100==0)
					ans++;
			}
			a+=ans;
			}
	int b=a%1461;
	int x=0;
	if(b<365) {x=0;}
	if(b>=365&&b<731) {x=1;b=b-365;}
	if(b>=731&&b<1096) {x=2;b=b-731;}
	if(b>=1096&&b<1461) {x=3;b=b-1096;}
	if(nowy==1582&&b>=280)
	{
		int ans=10;
		b+=ans;
		}
	nowy=nowy+x;	
	
	if(x==1)
	{
		if(b-31<0)
			{
				nowd=b+day;
				nowm=mon;
				
				
			}
			else
			{
					if(b-60<0)
					{
						nowd=b-31+day;
						nowm=mon+1;
					
					}
					else
					{
							if(b-91<0)
						{
							nowd=b-60+day;
							nowm=mon+2;
							
							
						}
							else
						{
								if(b-121<0)
							{
								nowd=b-91+day;
								nowm=mon+3;
								
								
							}
								else
							{
								if(b-152<0)
								{
									nowd=b-121+day;
									nowm=mon+4;
								
									
								}
									else
								{
									if(b-182<0)
									{
										nowd=b-152+day;
										nowm=mon+5;
										
										
									}
										else
									{
										if(b-213<0)
										{
											nowd=b-182+day;
											nowm=mon+6;
											
											
										}
											else
										{
											if(b-244<0)
											{
												nowd=b-213+day;
												nowm=mon+7;
												
												
											}
											else
										{
											if(b-273<0)
											{
												nowd=b-243+day;
												nowm=mon+8;
												
												
											}
											else
										{
											if(b-305<0)
											{
												nowd=b-274+day;
												nowm=mon+9;
												
											}
											else
											{
												if(b-335<0)
												{
													nowd=b-305+day;
													nowm=mon+10;
												
												}
												else
												{
													if(b-366<0)
													{
														nowd=b-335+day;
														nowm=mon+11;
														
														}
													}

												}
											}
										}
									}		
								}
							}
						}
				}
			}
		
			
		}
	}
else
{
	if(b-31<0)
			{
				nowd=b+day;
				nowm=mon;
				
			}
			else
			{
					if(b-59<0)
					{
						nowd=b-31+day;
						nowm=mon+1;
						
					}
					else
					{
							if(b-90<0)
						{
							nowd=b-59+day;
							nowm=mon+2;
							
						}
							else
						{
								if(b-120<0)
							{
								nowd=b-90+day;
								nowm=mon+3;
							
							}
								else
							{
								if(b-151<0)
								{
									nowd=b-120+day;
									nowm=mon+4;
									
								}
									else
								{
									if(b-181<0)
									{
										nowd=b-151+day;
										nowm=mon+5;
										
									}
										else
									{
										if(b-212<0)
										{
											nowd=b-181+day;
											nowm=mon+6;
											
										}
											else
										{
											if(b-243<0)
											{
												nowd=b-212+day;
												nowm=mon+7;
												
											}
											else
										{
											if(b-273<0)
											{
												nowd=b-243+day;
												nowm=mon+8;
												
											}
											else
										{
											if(b-304<0)
											{
												nowd=b-273+day;
												nowm=mon+9;
											
											}
											else
											{
												if(b-334<0)
												{
													nowd=b-304+day;
													nowm=mon+10;
													
												}
												else
												{
													if(b-365<0)
													{
														nowd=b-334+day;
														nowm=mon+11;
														
														}
													}

												}
											}
										}
									}		
								}
							}
						}
				}
			}
		
			
		}
		}
		if(nowy<0)
			cout<<nowd<<" "<<nowm<<" "<<abs(nowy)<<" "<<"BC"<<endl;
			else
				cout<<nowd<<" "<<nowm<<" "<<abs(nowy)<<endl;
}
return 0;
}

