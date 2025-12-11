# 📘 Digit DP — Complete Notes & Problem Set

Digit DP is a technique for counting or optimizing over numbers ≤ N where the answer depends on digit properties.  

---

# 🧠 What is Digit DP?

Digit DP is used when the problem is:

- Count numbers in a range  
- With constraints on digits  
- Up to a large number (10¹⁸)  
- Where brute force is impossible  

Examples:

- Count numbers ≤ N with no repeated digits  
- Count numbers ≤ N where digit sum = K  
- Count numbers that are zig-zag / wavy  
- Count numbers divisible by 7  

---

# 🧩 How Digit DP Works

We process the number digit-by-digit from left to right.

### Common DP state parameters:

| State | Meaning |
|-------|---------|
| `pos` | current index in digit array |
| `tight` / `small` | whether we are bound by prefix of N |
| `sum` | sum of digits so far |
| `prev` | previous digit |
| `mask` | bitmask for used digits |
| `nz` | has the number started (to avoid leading zeros) |

---

# 🛠 Step-by-Step Method

## 1. Convert Number → Digit Array

```cpp
vector<int> v;
while (N > 0) { v.push_back(N % 10); N /= 10; }
reverse(v.begin(), v.end());
```

---

## 2. Define the DP function

```cpp
long long solve(int pos, bool small, int sum, int prev);
```

---

## 3. Transition

```cpp
int limit = small ? 9 : v[pos];

for (int d = 0; d <= limit; d++) {
    bool nsmall = small || d < limit_of_N;
    ans += solve(pos + 1, nsmall, newsum, newprev);
}
```

---

## 4. Base Case

When `pos == v.size()`:

```cpp
return (valid ? 1 : 0);
```

---

## 5. Memoization

Use a dp array:

```cpp
long long dp[20][2][200][20];
memset(dp, -1, sizeof(dp));
```

---

## 6. Range Queries [L, R]

Digit DP always answers `count(0…N)`.

So for range:

```cpp
answer = count(R) - count(L - 1);
```

---

# 📦 Full Template (Reusable)

```cpp
vector<int> v;
long long dp[20][2][200][20];

long long solve(int pos, bool small, int sum, int prev) {
    if (pos == v.size())
        return (/* condition */);

    if (dp[pos][small][sum][prev] != -1)
        return dp[pos][small][sum][prev];

    long long ans = 0;
    int limit = small ? 9 : v[pos];

    for (int d = 0; d <= limit; d++) {
        bool nsmall = small || d < v[pos];
        ans += solve(pos + 1, nsmall, sum + d, d);
    }

    return dp[pos][small][sum][prev] = ans;
}

long long count(long long N) {
    v.clear();
    while (N > 0) v.push_back(N % 10), N /= 10;
    reverse(v.begin(), v.end());
    memset(dp, -1, sizeof(dp));
    return solve(0, 0, 0, 0);
}
```

---

# 🧗 Difficulty Ladder — Digit DP Problems

Here are the best problems to practice digit DP from easy → advanced.

---

## 🟢 **Level 1 — Beginners**

1. **Find Count of Numbers with Digit Sum ≤ K →**  
   https://cses.fi/problemset/task/2220/

2. **Numbers Without Adjacent Equal Digits →**  
   https://codeforces.com/problemset/problem/567/D

3. **Count Numbers without digit 3 →**  
   https://leetcode.com/problems/count-integers-without-digit-3/

---

## 🟡 **Level 2 — Intermediate**

4. **Unique Digits / No Repetition →**  
   https://leetcode.com/problems/count-numbers-with-unique-digits/

5. **Digit DP + Modulo (sum modulo m) →**  
   https://atcoder.jp/contests/dp/tasks/dp_s

6. **Count Numbers with Digit Sum = K →**  
   https://www.codechef.com/problems/DISCSUM

7. **Count Numbers with Alternating Digits →**  
   https://leetcode.com/problems/wiggle-subsequence/  
   *(Adaptable to digit DP)*

---

## 🟠 **Level 3 — Hard**


8. **Count Numbers with XOR of digits = K**  
    https://atcoder.jp/contests/abc129/tasks/abc129_f

9. **Digit DP + Bitmask + Modulo**  
    https://www.hackerrank.com/challenges/separate-the-numbers/problem  
    (Adaptable)

10. **Digit DP on two previous digits (like your waviness DP)**  
    Hard-level custom problems (CF/ICPC).

---

# 📚 Extra Reading

- Codeforces Digit DP Tutorial  
  https://codeforces.com/blog/entry/53960

- AtCoder DP “S” problem editorial  
  https://atcoder.jp/contests/dp/tasks/dp_s

- Errichto Digit DP video  
  https://www.youtube.com/watch?v=QPoqx9v1J2c

---

# 🏁 Final Tips

- Always include `small` (tight).
- Always handle leading zeros with a flag (`nz`).
- Avoid storing large DP states if possible.
- Most mistakes come from:
  - wrong tight logic  
  - leading zeros  
  - using `prev` incorrectly  
  - not memoizing boolean values correctly  

