#include <bits/stdc++.h>
using l = long;
using ll = long long;
using lu = long unsigned;
using llu = long long unsigned;
using namespace std;

using s = string;
template<typename T>
using v = vector<T>;
template<typename T, int N>
using ar = array<T, N>;

ll aaaaaaaa=0;
#define REP(i, n) for(lu i=0; i<(lu)n; i++)
#define endl '\n'
#define DBG(v) { cout << aaaaaaaa++ << " " << (v) << endl; }
#define _ xxxxxxxxx
#define __ yyyyyyyyy
#define ___ zzzzzzzzz

#if 0

#endif

int isValid(s dat) {
  int mi, ma;
  char c;
  char p[256];
  sscanf(dat.c_str(), "%d-%d %c: %s", &mi, &ma, &c, p);
  mi--; ma--;
  s pa; pa.assign(p);
  if (pa[mi] == c && pa[ma] == c) {
    return false;
  }
  if (pa[mi] == c || pa[ma] == c) {
    return true;
  }
  return false;
}

int main() {
  v<s> dat;
  s line;
  while(getline(cin, line)) {
    dat.push_back(line);
  }
  
  int i=0;
  for(auto e : dat) {
    i += isValid(e);
    cout << (isValid(e)?"YES ":"NO ") << e << '\n';
  }
  cout << i << '\n';
  return 0;
}
