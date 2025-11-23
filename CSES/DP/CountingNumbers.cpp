#include <bits/stdc++.h>
using namespace std;

vector<int> v;
long long dp[20][2][11][2];

long long solve(int pos, bool small, int prev, int nz) {
  if (pos == v.size())
    return 1;

  if (dp[pos][small][prev][nz] != -1)
    return dp[pos][small][prev][nz];

  long long ans = 0;
  int limit = small ? 9 : v[pos];

  for (int d = 0; d <= limit; d++) {
    bool nsmall = small || d < v[pos];
    int nnz = nz || (d > 0);
    if (nnz) {
      if (d == prev)
        continue;
      ans += solve(pos + 1, nsmall, d, nnz);
    } else {
      ans += solve(pos + 1, nsmall, prev, nnz);
    }
  }

  return dp[pos][small][prev][nz] = ans;
}

long long count(long long N) {
  if (N < 0)
    return 0;
  v.clear();
  while (N >= 0) {
    v.push_back(N % 10), N /= 10;
    if (N == 0)
      break;
  }
  reverse(v.begin(), v.end());
  memset(dp, -1, sizeof(dp));
  return solve(0, 0, 10, 0);
}

int main() {
  long long L, R;
  cin >> L >> R;
  cout << count(R) - count(L - 1) << endl;
  return 0;
}
