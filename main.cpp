#include <algorithm>
#include <bit>
#include <chrono>
#include <cmath>
#include <cstdint>
#include <deque>
#include <iomanip>
#include <iostream>
#include <limits>
#include <map>
#include <numeric>
#include <queue>
#include <ranges>
#include <set>
#include <sstream>
#include <stack>
#include <string>
#include <tuple>
#include <utility>
#include <vector>

using namespace std;

using ll = int64_t;
using vl = vector<ll>;
using vs = vector<string>;
using Pos = pair<ll, ll>;
using Data = pair<Pos, vector<Pos>>;

ll r, c;
vs F;

bool solve(ll i) {
  stack<Pos> S{};
  S.push({i, 0});

  while (!S.empty()) {
    auto [fr, fc] = S.top();
    S.pop();

    F[fr][fc] = 'x';

    if (fc == c - 1) {
      return true;
    }

    const auto& nc = fc + 1;
    for (auto dr = 1; -1 <= dr; --dr) {
      const auto& nr = fr + dr;

      if (nr < 0 || r <= nr) continue;
      if (F[nr][nc] == 'x') continue;

      S.push({nr, nc});
    }
  }

  return false;
}

int main() {
  ios::sync_with_stdio(false);
  std::cin.tie(nullptr);

  cin >> r >> c;
  F = vs(r);
  for (auto&& f : F) cin >> f;

  ll ans = 0;
  for (auto i = 0; i < r; ++i) {
    const auto& good = solve(i);
    if (good) ++ans;
  }

  cout << ans;

  return 0;
}