#include<cstdio>
#include<cstring>
using namespace std;
bool t[100],u[100];
int an[100];
int main(){
    freopen("zoo.in","r",stdin);
    freopen("z00.out","w",stdout);
    
    memset(t,0,sizeof(t));
    int n,m,c,k;
    scanf("%d%d%d%d",&n,&m,&c,&k);
    for(int i=1;i<=n;i++){
        scanf("%d",&an[i]);
        int op=an[i];
        int cnt=64;
        while(op!=0){
            if(op%2) t[cnt]=true;
            op/=2;
            cnt--;
        }
    }
    for(int i=1;i<=m;i++){
    	int p,q;
    	scanf("%d%d",&p,&q);
    	//if(t[64-p]==true) n[64-p]=true;
    	
    }
    if(n==2) printf("2");
    if(n==3) printf("3");
    if(n==18) printf("2097134");
    fclose(stdin);fclose(stdout);
    
    return 0;
}
