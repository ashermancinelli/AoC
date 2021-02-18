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

auto create_checker(int right, int down, char tree='#') {
  return [=] (int const i, v<s> const& data, int& tot) {
    int r = (down*i), c = (right*i)%data[0].size();
    if(r >= data.size()) return;
    tot += (data[r][c]==tree?1:0);
    // cout << (data[r][c]==tree?"YES":"NO") << " (" << right << ", " << down << "): " << r << ' ' << c << '\n';
  };
}

int main() {
  v<s> data;
  s line;
  constexpr char tree='#', notree='.';
  while(getline(cin, line)) data.push_back(line);
  int sz = data.size(), w = data[0].size();
  auto fs = {
    create_checker(1, 1),
    create_checker(3, 1),
    create_checker(5, 1),
    create_checker(7, 1),
    create_checker(1, 2),
  };
  ll ttot=1;
  for(auto f : fs) {
    int tot=0;
    for(int i=0;i<sz;i++) {
      f(i, data, tot);
    }
    ttot = ttot * tot;
    cout << tot << ' ' << ttot << '\n';
  }
  cout << ttot << '\n';
  return 0;
}
