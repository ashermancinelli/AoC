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

int main() {
  v<s> data;
  s line;
  constexpr int right = 3, down = 1;
  constexpr char tree='#', notree='.';
  while(getline(cin, line)) data.push_back(line);
  int sz = data.size(), w = data[0].size();
  int tot=0;
  for(int i=0;i<sz/down;i++) {
    int r = (down*i), c = (right*i)%w;
    cout << r << ' ' << c << '\n';
    tot += (data[r][c]==tree?1:0);
  }
  cout << tot << '\n';
  return 0;
}
