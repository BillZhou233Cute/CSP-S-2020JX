#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
const int maxn=5550000;
struct node{
    ll l,r;
    bool isr;
    int year;
}allnodes[maxn];
void init(){
    int nowyear=-4713;
    allnodes[0].r=0;
    for(int i=1;i<maxn;i++){
        allnodes[i].l=allnodes[i-1].r+1;
        allnodes[i].year=nowyear;
        if(nowyear<1582){
            if(nowyear<0){
                if((abs(nowyear)-1)%4==0){
                    allnodes[i].isr=true;
                    allnodes[i].r=allnodes[i].l+366-1;
                }else{
                    allnodes[i].isr=false;
                    allnodes[i].r=allnodes[i].l+365-1;
                }
            }else{
                if(abs(nowyear)%4==0){
                allnodes[i].isr=true;
                allnodes[i].r=allnodes[i].l+366-1;    
                }else{
                    allnodes[i].isr=false;
                    allnodes[i].r=allnodes[i].l+365-1;
                }
            }
        }else if(nowyear==1582){
            allnodes[i].r=allnodes[i].l+365-10-1;
        }else{
            if(abs(nowyear)%400==0||(abs(nowyear)%4==0&&abs(nowyear)%100!=0)){
                allnodes[i].isr=true;
                allnodes[i].r=allnodes[i].l+366-1;
            }else{
                allnodes[i].r=allnodes[i].l+365-1;
            }
        }
        nowyear++;
        if(nowyear==0)nowyear=1;
    }
}
int findpos(ll x){
    int l=1,r=maxn-1;
    while(l<=r){
        int mid=(l+r)>>1;
        if(x>=allnodes[mid].l&&x<=allnodes[mid].r)return mid;
        if(x<allnodes[mid].l){
            r=mid-1;
        }else{
            l=mid+1;
        }
    }
    while(true){}
    return 0;
}
int main(){
    freopen("julian.in","r",stdin);
    freopen("julian.out","w",stdout);
    ios::sync_with_stdio(false);
    init();
    int T;
    cin>>T;
    while(T--){
        ll x;
        cin>>x;
        x++;
        int xpos=findpos(x);
        if(allnodes[xpos].year==1582){
            x-=allnodes[xpos].l;
                x++;
                if(x<=31){
                    x-=0;
                    
                    cout<<x<<" "<<1<<" "<<abs(allnodes[xpos].year);
                }else if(x<=31+28){
                    x-=31;
                    
                    cout<<x<<" "<<2<<" "<<abs(allnodes[xpos].year);
                }else if(x<=31+28+31){
                    x-=31+28;
                    
                    cout<<x<<" "<<3<<" "<<abs(allnodes[xpos].year);
                }else if(x<=31+28+31+30){
                    x-=31+28+31;
                    
                    cout<<x<<" "<<4<<" "<<abs(allnodes[xpos].year);
                }else if(x<=31+28+31+30+31){
                    x-=31+28+31+30;
                    
                    cout<<x<<" "<<5<<" "<<abs(allnodes[xpos].year);
                }else if(x<=31+28+31+30+31+30){
                    x-=31+28+31+30+31;
                    
                    cout<<x<<" "<<6<<" "<<abs(allnodes[xpos].year);
                }else if(x<=31+28+31+30+31+30+31){
                    x-=31+28+31+30+31+30;
                    
                    cout<<x<<" "<<7<<" "<<abs(allnodes[xpos].year);
                }else if(x<=31+28+31+30+31+30+31+31){
                    x-=31+28+31+30+31+30+31;
                    
                    cout<<x<<" "<<8<<" "<<abs(allnodes[xpos].year);
                }else if(x<=31+28+31+30+31+30+31+31+30){
                    x-=31+28+31+30+31+30+31+31;
                    
                    cout<<x<<" "<<9<<" "<<abs(allnodes[xpos].year);
                }else if(x<=31+28+31+30+31+30+31+31+30+21){
                    x-=31+28+31+30+31+30+31+31+30;
                    
                    cout<<x<<" "<<10<<" "<<abs(allnodes[xpos].year);
                }else if(x<=31+28+31+30+31+30+31+31+30+21+30){
                    x-=31+28+31+30+31+30+31+31+30+21;
                    
                    cout<<x<<" "<<11<<" "<<abs(allnodes[xpos].year);
                }else{
                    x-=31+28+31+30+31+30+31+31+30+21+30;
                    
                    cout<<x<<" "<<12<<" "<<abs(allnodes[xpos].year);
                }
        }else{
            if(allnodes[xpos].isr){
                x-=allnodes[xpos].l;
                x++;
                if(x<=31){
                    x-=0;
                    
                    cout<<x<<" "<<1<<" "<<abs(allnodes[xpos].year);
                }else if(x<=31+29){
                    x-=31;
                    
                    cout<<x<<" "<<2<<" "<<abs(allnodes[xpos].year);
                }else if(x<=31+29+31){
                    x-=31+29;
                    
                    cout<<x<<" "<<3<<" "<<abs(allnodes[xpos].year);
                }else if(x<=31+29+31+30){
                    x-=31+29+31;
                    
                    cout<<x<<" "<<4<<" "<<abs(allnodes[xpos].year);
                }else if(x<=31+29+31+30+31){
                    x-=31+29+31+30;
                    
                    cout<<x<<" "<<5<<" "<<abs(allnodes[xpos].year);
                }else if(x<=31+29+31+30+31+30){
                    x-=31+29+31+30+31;
                    
                    cout<<x<<" "<<6<<" "<<abs(allnodes[xpos].year);
                }else if(x<=31+29+31+30+31+30+31){
                    x-=31+29+31+30+31+30;
                    
                    cout<<x<<" "<<7<<" "<<abs(allnodes[xpos].year);
                }else if(x<=31+29+31+30+31+30+31+31){
                    x-=31+29+31+30+31+30+31;
                    
                    cout<<x<<" "<<8<<" "<<abs(allnodes[xpos].year);
                }else if(x<=31+29+31+30+31+30+31+31+30){
                    x-=31+29+31+30+31+30+31+31;
                    
                    cout<<x<<" "<<9<<" "<<abs(allnodes[xpos].year);
                }else if(x<=31+29+31+30+31+30+31+31+30+31){
                    x-=31+29+31+30+31+30+31+31+30;
                    
                    cout<<x<<" "<<10<<" "<<abs(allnodes[xpos].year);
                }else if(x<=31+29+31+30+31+30+31+31+30+31+30){
                    x-=31+29+31+30+31+30+31+31+30+31;
                    
                    cout<<x<<" "<<11<<" "<<abs(allnodes[xpos].year);
                }else{
                    x-=31+29+31+30+31+30+31+31+30+31+30;
                    
                    cout<<x<<" "<<12<<" "<<abs(allnodes[xpos].year);
                }    
            }else{
                x-=allnodes[xpos].l;
                x++;
               
                if(x<=31){
                    x-=0;
                    
                    cout<<x<<" "<<1<<" "<<abs(allnodes[xpos].year);
                }else if(x<=31+28){
                    x-=31;
                    
                    cout<<x<<" "<<2<<" "<<abs(allnodes[xpos].year);
                }else if(x<=31+28+31){
                    x-=31+28;
                    
                    cout<<x<<" "<<3<<" "<<abs(allnodes[xpos].year);
                }else if(x<=31+28+31+30){
                    x-=31+28+31;
                    
                    cout<<x<<" "<<4<<" "<<abs(allnodes[xpos].year);
                }else if(x<=31+28+31+30+31){
                    x-=31+28+31+30;
                    
                    cout<<x<<" "<<5<<" "<<abs(allnodes[xpos].year);
                }else if(x<=31+28+31+30+31+30){
                    x-=31+28+31+30+31;
                    
                    cout<<x<<" "<<6<<" "<<abs(allnodes[xpos].year);
                }else if(x<=31+28+31+30+31+30+31){
                    x-=31+28+31+30+31+30;
                    
                    cout<<x<<" "<<7<<" "<<abs(allnodes[xpos].year);
                }else if(x<=31+28+31+30+31+30+31+31){
                    x-=31+28+31+30+31+30+31;
                    
                    cout<<x<<" "<<8<<" "<<abs(allnodes[xpos].year);
                }else if(x<=31+28+31+30+31+30+31+31+30){
                    x-=31+28+31+30+31+30+31+31;
                    
                    cout<<x<<" "<<9<<" "<<abs(allnodes[xpos].year);
                }else if(x<=31+28+31+30+31+30+31+31+30+31){
                    x-=31+28+31+30+31+30+31+31+30;
                    
                    cout<<x<<" "<<10<<" "<<abs(allnodes[xpos].year);
                }else if(x<=31+28+31+30+31+30+31+31+30+31+30){
                    x-=31+28+31+30+31+30+31+31+30+31;
                    
                    cout<<x<<" "<<11<<" "<<abs(allnodes[xpos].year);
                }else{
                    x-=31+28+31+30+31+30+31+31+30+31+30;
                    
                    cout<<x<<" "<<12<<" "<<abs(allnodes[xpos].year);
                }
            }
        }
        if(allnodes[xpos].year<0){
                  cout<<" BC"<<endl;
         }else{
                        cout<<endl;
                    }
    }
    return 0;
}
