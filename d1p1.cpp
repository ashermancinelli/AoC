#include <bits/stdc++.h>
using l = long;
using ll = long long;
using lu = long unsigned;
using llu = long long unsigned;
using namespace std;

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
  vector<int> v;
  std::copy(istream_iterator<int>(cin), istream_iterator<int>(), back_inserter(v));
  for(auto e : v) cout << e << ' ';
  sort(begin(v), end(v));
  for(auto e : v) cout << e << ' ';

  for(auto i=0;i<v.size()-1;i++) {
    for(auto j=i+1;j<v.size();j++) {
      if (v[i]+v[j]==2020) {
        cout << v[i]*v[j] << '\n';
        return 0;
      }
    }
  }
  return 1;
}
