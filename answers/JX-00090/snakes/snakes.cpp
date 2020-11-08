#include<cstdio>
#include<algorithm>
#include<cstring>
using namespace std;
struct snake{
  int x,y;
}s[3000005];
bool cmp(snake e,snake f){
  if(e.y==f.y) return e.x>f.x;
  return e.y>f.y;
}
int main()
{
  freopen("snakes.in","r",stdin);
  freopen("snakes.out","w",stdout);
  int t,n;
  scanf("%d",&t);
  while(t){
    t--;
    scanf("%d",&n);
    for(int i=1;i<=n;++i){
      s[i].x=i;
      scanf("%d",&s[i].y);
    }
    sort(s+1,s+n+1,cmp);
    while(n>1){
      if((s[1].y>s[n].y||(s[1].y==s[n].y&&s[1].x>s[n].x))&&(s[1].y-s[n].y>s[2].y||(s[1].y-s[n].y==s[2].y&&s[1].x>s[2].x)))
	s[1].y-=s[n].y;
	else break;
	sort(s+1,s+n+1,cmp);
	n--;
      }
    }
    printf("%d\n",n);
  }
  return 0;
}
