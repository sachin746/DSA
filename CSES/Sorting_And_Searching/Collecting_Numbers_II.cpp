#include <bits/stdc++.h>
using namespace std;

int dp[100005][100][2][2];
const int MOD = 1e9 + 7;

int main() {
  int n, m;
  cin >> n >> m;
  vector<int> a(n + 1);
  vector<int> mp(n + 1);
  for (int i = 1; i <= n; i++) {
    cin >> a[i];
    mp[a[i]] = i;
  }
  int ans = 0;
  vector<int> freq(n + 1, 0);
  for (int i = 1; i <= n; i++) {
    freq[a[i]]++;
    if (!freq[a[i] - 1]) {
      ans++;
    }
  }
  while (m--) {
    int x, y;
    cin >> x >> y;
    x--, y--;
    int mnIdx = min(a[x + 1], a[y + 1]);
    int mxIdx = max(a[x + 1], a[y + 1]);
    if (mnIdx + 1 == mxIdx) {
    } else {
    }

    cout << ans << endl;
  }
}
// 4 2 1 5 3 -> 3
// 1 2
// 4 1 2 5 3 ->
// 0 4
// 3 1 2 5 4  -1+1
// 2 3
// 3 2 1 5 4
