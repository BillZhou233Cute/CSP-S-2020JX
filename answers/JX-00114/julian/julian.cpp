#include <cstdio>
#include <cmath>
#include <iostream>

using namespace std;

int Q, r, yr, mt, dy;

bool Judge(int Y) {
  if (Y < 1582) {
    if (Y % 4 == 0) return 1;
    return 0;
  }
  else {
    if ((Y % 4 == 0 and Y % 100) or (Y % 400 == 0)) return 1;
    return 0;
  }
}

void Month() {
  for (int i = 1; i <= 12; ++i) {
    int tmp = 0;
    if (i == 1 or i == 3 or i == 5 or i == 7 or i == 8 or i == 10 or i == 12) tmp = 31;
    else if (i != 2) tmp = 30;
    else {
      tmp = 28 + Judge(yr);
    }
    //cerr << i << ": " << tmp << ' ' << yr << ' ' << r << endl;
    if (r < tmp) { 
      //cerr << i << ": " << tmp << ' ' << yr << ' ' << r << endl;
      mt = i, dy = r + 1; break; 
    }
    r -= tmp;
  }
  if (!mt) cerr << "???" << endl;
}

void _4Year(int ty) {
  if (yr > 1582 and yr % 100 == 0 and yr % 400) {
    yr += (r / 365);
    r -= r / 365 * 365;
    Month();
  }
  else {
    if (r < 366) Month();
    else {
      r -= 366, ++yr;
      yr += (r / 365);
      r -= r / 365 * 365;
      Month();
    }
  }
}

void _400Year() {
  yr = 1600 + (r / 146097) * 400;
  r -= (r / 146097) * 146097;
  if (r < 36525) {
    yr = yr + (r / 1461) * 4;
    r -= (r / 1461) * 1461;
    _4Year(1);
  }
  else {
    r -= 36525;
    yr += 100;
    yr += (r / 36524) * 100;
    r -= (r / 36524) * 36524;
    if (r < 1460) { _4Year(1); return; }
    yr += 4;
    r -= 1460;
    yr += (r / 1461) * 4;
    r -= (r / 1461) * 1461;
    _4Year(1);
  }
}

void _1580Y() {
  if (r < 366) yr = 1580;
  else {
    r -= 366;
    if (r < 365) yr = 1581;
    else {
      r -= 365;
      if (r < 355) yr = 1582;
      else {
	r -= 355;
	yr = 1583;
      }
    }
  }
  Month();
}

void Run() {
  yr = mt = dy = 0;
  int tmp = (r / 1461) * 4 - 4712;
  if (tmp < 1580) {
    yr = tmp;
    r -= (r / 1461) * 1461;
    _4Year(0);
    return;
  }
  r -= (1580 + 4712) / 4 * 1461;
  yr = 1580;
  if (r < 1451) { _1580Y(); return; }
  r -= 1451;
  yr = 1584;
  if (yr + (r / 1461) * 4 < 1600) {
    yr += (r / 1461) * 4;
    r -= (r / 1461) * 1461;
    _4Year(1);
    return;
  }
  r -= (1600 - 1584) / 4 * 1461;
  yr = 1600;
  _400Year();
}

void Print() {
  int tmp = yr <= 0 ? -(yr - 1) : yr;
  printf("%d %d %d ", dy, mt, tmp);
  if (yr < 0) printf("BC\n");
  else printf("\n");
}

int main() {
  freopen("julian.in", "r", stdin);
  freopen("julian.out", "w", stdout);
  cin >> Q;
  for (int cas = 1; cas <= Q; ++cas) {
    scanf("%d", &r);
    Run();
    Print();
  }
  return 0;
}
