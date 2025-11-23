
# 2D Difference Array Algorithm

## Update Formula (Rectangle Add)

To add `val` to all cells in rectangle  
`(r1, c1)` → `(r2, c2)`:

- `diff[r1][c1] += val`
- `diff[r1][c2 + 1] -= val`
- `diff[r2 + 1][c1] -= val`
-  `diff[r2 + 1][c2+1] += val`

## C++ Template

```cpp
vector<vector<int>> diff(n+2, vector<int>(m+2, 0));

auto update = [&](int r1, int c1, int r2, int c2, int val){
    diff[r1][c1] += val;
    diff[r1][c2+1] -= val;
    diff[r2+1][c1] -= val;
    diff[r2+1][c2+1] += val;
};

for (int i = 0; i < n; i++) {
    for (int j = 0; j < m; j++) {
        int up   = (i > 0 ? diff[i-1][j] : 0);
        int left = (j > 0 ? diff[i][j-1] : 0);
        int diag = (i > 0 && j > 0 ? diff[i-1][j-1] : 0);
        diff[i][j] += up + left - diag;
    }
}

