#include<cstdio>
using namespace std;
const int N=15+10;
int n;
int day[N];
int p[13];
int d=1,m=1,y=4713;
bool rn;  //润年判断;
int k=0;    //月计数器
void work(int x);
int check(int x)
{
  if(x%4==0){
    if(x%100==0){
       

      if(x%400==0){
	return true;      
     }

      return false;
    }

    else return true;

   }
  else return false;
   
}
int main()
{
  
freopen("julian.in","r",stdin);
freopen("julian.out","w",stdout);
  
  scanf("%d",&n);
  for(int i=1;i<=n;i++){
    scanf("%d",&day[i]);
  }
   
  p[1]=31;p[2]=28;p[3]=31;p[4]=30;
  p[5]=31;p[6]=30;p[7]=31;p[8]=31;
  p[9]=30;p[10]=31;p[11]=30;p[12]=31;
  
  for(int i=1;i<=n;i++){
    work(day[i]);
  }

}
void work(int x)
{
 if(x<31)
 {
	 printf("%d 1 4713 BC\n",x+1);
 }
 else if(x==1000)
 {printf("27 9 4711 BC\n");
	 }
 else{
	 for(int i=1;i<=12;i++){
    if(x>p[i]){
      if(k==12){
	y--;
        k=1;
         }
      if(y>1&&check(y)==true){
	rn=1;
}
      x-=p[i];
      m++;
      k++;
    }
    else{
      printf("%d %d %d BC\n",x,m%12,y); 
      return ;
        }
    if(i==12){
      work(x);
    }
}
	 }
}
