#include <iostream>
#include <fstream>
using namespace std;
typedef struct DATE{
  long long Y;
  unsigned M;
  unsigned D;
}DATE;
DATE a,b,s;
unsigned dpm[13] = {0, 31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};
inline bool isry(long long Y){
  return Y > 0 ? ((Y > 1582 && (Y % 4 == 0 && (Y % 100 != 0 || Y % 400 == 0))) || (Y <= 1582 && Y % 4 == 0)) : ((-(Y + 1)) % 4 == 0);
}
inline unsigned cdpm(long long Y, unsigned M){
  return M == 2 ? 28 + isry(Y) : (M == 10 && Y == 1582 ? 21 : dpm[M]);
}
inline unsigned cdpy(long long Y){
  return 306 + cdpm(Y, 2) + cdpm(Y, 10);
}

DATE cal(unsigned long long R){
  DATE result = s;
  unsigned o1 = R / 1461;
  if(o1 > 1573)
    o1 = 1573;
  R -= o1 * 1461;
  o1 *= 4;
  result.Y += o1;
  if(result.Y >= 0) ++result.Y;// 1580.1.1

  while((result.Y < 1600 || (result.Y == 1600 && R < 366)) && R != 0) {
    if(R >= cdpy(result.Y)) {
      R -= cdpy(result.Y);
      ++result.Y;
    }else{
      for(unsigned m = 1;m < 12;++m) {
	unsigned dfm = cdpm(result.Y, m);
	if(R >= dfm){
	  R -= dfm;
	  ++result.M;
	}else{
	  result.D += R;
	  R = 0;
	  break;
	}
      }
    }
  }
  if(R == 0) return result;//1600.1.1

  unsigned o2 = R / 146097;
  R -= o2 * 146097;
  o2 *= 400;
  result.Y += o2;// 400s
  while(R != 0) {
    if(R >= cdpy(result.Y)) {
      R -= cdpy(result.Y);
      ++result.Y;
    }else{
      for(unsigned m = 1;m < 12;++m) {
	unsigned dfm = cdpm(result.Y, m);
	if(R >= dfm){
	  R -= dfm;
	  ++result.M;
	}else{
	  result.D += R;
	  R = 0;
	  break;
	}
      }
    }
  }
  return result;
}

int main(){
  ios::sync_with_stdio(false);
  cin.tie(0);
  s.Y = -4713LL;
  s.M = 1U;
  s.D = 1U;
  ifstream fin("julian.in");
  ofstream fout("julian.out");

  unsigned Q;
  fin >> Q;
  unsigned long long R;
  for(unsigned i = 1;i <= Q;++i) {
    fin >> R;
    DATE date = cal(R);
    fout << date.D << ' ' << date.M << ' ' << (date.Y < 0 ? -date.Y : date.Y);
    if(date.Y < 0)
      fout << ' ' << "BC";
    fout << endl;
  }

  return 0;
}
