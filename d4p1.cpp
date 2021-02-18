#include <bits/stdc++.h>
#include <cassert>
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

static v<s> required = {
  "byr",
  "iyr",
  "eyr",
  "hgt",
  "hcl",
  "ecl",
  "pid",
};

void eat(s::iterator& it, s::iterator end) {
  while(it != end && isspace(*it)) it++;
}

ostream& operator<<(ostream& os, v<s> const& vv) {
  for(auto e : vv) os << e << ' ';
  return os;
}

v<s> parse(s ss) {
  v<s> vv;
  std::string::iterator it=begin(ss);
  while(it!=end(ss)) {
    eat(it, end(ss));
    s k="";
    while (*it!=':') {
      k += *it++;
    }
    it++;
    while (!isspace(*it)) it++;
    eat(it, end(ss));
    vv.push_back(k);
  }
  return vv;
}

int main() {
  sort(begin(required), end(required));
  s line;
  v<s> strings;
  s ss="";
  while(getline(cin, line)) {
    ss += " " + line;
    if (line.size()==0) {
      strings.push_back(ss);
      ss = "";
    }
  }
  v<v<s>> ans;
  for(auto e : strings) {
    // cout << e << '\n';
    ans.push_back(parse(e));
  }
  int invalid=0;
  for(auto && vv : ans) {
    v<s> diff(vv.size());
    sort(begin(vv), end(vv));
    auto it = set_difference(begin(required), end(required), begin(vv), end(vv), begin(diff));
    diff.resize(it-begin(diff));
    if(diff.size() == 0) continue;
    else if (diff.size() > 1) { invalid++; continue; }
    else if (*it == "cid") continue;
    else invalid++;
    cout << "DIFF: " << diff << "VV: " << vv << '\n';
  }
  cout << ans.size()-invalid << '\n';
  return 0;
}
