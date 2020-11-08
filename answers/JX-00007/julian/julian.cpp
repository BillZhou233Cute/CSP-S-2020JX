#include<bits/stdc++.h>
using namespace std;
int dd[2][13];
inline int read(){
  int f=1,ans=0;
  char c=getchar();
  while(c<'0'||c>'9'){
    if(c=='-')f=-1;
    c=getchar();}
  while(c>='0'&&c<='9')
    ans=ans*10+c-'0',c=getchar();
  return f*ans;
}
int main(){
  freopen("julian.in","r",stdin);
  freopen("julian.out","w",stdout);
  int Q=read();
  dd[0][1]=dd[1][1]=31;
  dd[0][2]=28,dd[1][2]=29;
 dd[0][3]=dd[1][3]=31;
 dd[0][4]=dd[1][4]=30;
 dd[0][5]=dd[1][5]=31;
 dd[0][6]=dd[1][6]=30;
 dd[0][7]=dd[1][7]=31;
 dd[0][8]=dd[1][8]=31;
 dd[0][9]=dd[1][9]=30;
 dd[0][10]=dd[1][10]=31;
 dd[0][11]=dd[1][11]=30;
 dd[0][12]=dd[1][12]=31;
  while(Q--){
    int n=read(),y=0,nn=n,f=0;
    /* for(int i=-4712;i<=1581;i++){
      if(abs(i)%4==0)nn-=366,f=1;
      else nn-=365,f=0;
      if(nn<=0){
	y=i>0?i:i-1;
	break;}
    }*/
   if(nn>=2298884)nn-=2298884,y=1582;
   else {
     if(nn%1461==0)y=(nn/1461)*4,nn=0;
     else y=(nn/1461)*4,nn%=1461;
     if(nn>=366)y++,nn-=366;
     if(nn>=365)y++,nn-=365;
     if(nn>=365)y++,nn-=365;
     y=-4713+y;
     if(y>=0)y++;
     if(y>0&&y%4==0)f=1;
     if(y<0&&abs(y+1)%4==0)f=1;
   }
 if(y!=0){
    for(int i=1;i<=12;i++){
      if(nn-dd[f][i]>=0)nn-=dd[f][i];
      else {
        cout<<nn+1<<" "<<i<<" "<<abs(y);
	if(y<0)cout<<" BC\n";
        else cout<<"\n";
        break;}}
  }
 else if(nn<=355){
   for(int i=1;i<=9;i++){
      if(nn-dd[f][i]>=0)nn-=dd[f][i];
      else {
        cout<<nn+1<<" "<<i<<" "<<abs(y);
	if(y<0)cout<<" BC\n";
        else cout<<"\n";
	break;}}
   if(nn<=21){
   cout<<(nn+1<5?nn+1:nn+11)<<" 10 "<<abs(y);
	if(y<0)cout<<" BC\n";
        else cout<<"\n";
	break;
 }
 for(int i=11;i<=12;i++)
      if(nn-dd[f][i]>=0)nn-=dd[f][i];
      else {
        cout<<nn+1<<" "<<i<<" "<<abs(y);
	if(y<0)cout<<" BC\n";
        else cout<<"\n";
        break;}
  }
 /* else  for(int j=1583;;j++){
    if((j%4==0&&j%100!=0)||(j%400==0))nn-=366,f=1;
      else nn-=365,f=0;
    if(nn<=0){
 if(f)nn+=366;
 else nn+=365;*/
 else{
if(nn>=146097){
 if(nn%146097==0)y+=(nn/146097)*400,nn=0;
     else y+=(nn/146097)*400,nn%=146097;
   }
   if(nn>=36524){
 if(nn%36524==0)y+=(nn/36524)*100,nn=0;
     else y+=(nn/36524)*100,nn%=36524;
   }
     if(nn>=1461){
     if(nn%1461==0)y+=(nn/1461)*4,nn=0;
     else y+=(nn/1461)*4,nn%=1461;
     if(nn>=366)y++,nn-=366;
     if(nn>=365)y++,nn-=365;
     if(nn>=365)y++,nn-=365;
     if(y>0&&y%4==0)f=1;
     if(y<0&&abs(y+1)%4==0)f=1;
     }
 for(int i=1;i<=12;i++)
      if(nn-dd[f][i]>=0)nn-=dd[f][i];
      else {
        cout<<nn+1<<" "<<i<<" "<<y;
       cout<<"\n";
       break;}
}
  }
  return 0;//g++ julian.cpp -o julian
}
