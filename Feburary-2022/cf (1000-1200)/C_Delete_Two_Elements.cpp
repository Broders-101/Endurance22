#include <bits/stdc++.h>
using namespace std;
#define fast_io                       \
    ios_base::sync_with_stdio(false); \
    cin.tie(NULL);                    \
    cout.tie(0);
#define endl "\n"
#define ull unsigned long long
#define pb push_back
typedef long long ll;
typedef pair<int, int> pii;
const int MOD = 1000000007;
const int N = 1e3 + 2;
const int MAXN = 2e5 + 5;

const int M = 1e9 + 7;
long long mod(long long x)
{
    return ((x % M + M) % M);
}
long long add(long long a, long long b)
{
    return mod(mod(a) + mod(b));
}
long long mul(long long a, long long b)
{
    return mod(mod(a) * mod(b));
}

ll modPow(ll a, ll b)
{
    if (b == 0)
        return 1LL;
    if (b == 1)
        return a % M;
    ll res = 1;
    while (b)
    {
        if (b % 2 == 1)
            res = mul(res, a);
        a = mul(a, a);
        b = b / 2;
    }
    return res;
}

void sieve(int n, bool isPrime[])
{
    isPrime[0] = isPrime[1] = false;
    for (int i = 2; i * i <= n; i++)
    {
        if (isPrime[i])
        {
            for (int j = i * i; j <= n; j += i)
            {
                isPrime[j] = false;
            }
        }
    }
}

int lcm(int a, int b)
{
    int c = __gcd(a, b);
    return (a / c) * b;
}

int calc(int n)
{
    int res = 0;
    while (n)
    {
        res += n % 10;
        n /= 10;
    }
    return res;
}

void solve()
{
    int n;
    cin >> n;
    vector<ll> a(n);
    map<ll, ll> m;

    ll sum = 0;
    for (auto &x : a)
    {
        cin >> x;
        sum += x;
        m[x]++;
    }

    if ((2 * sum) % n != 0)
    {
        cout << 0 << endl;
        return;
    }

    ll res = 0;

    ll temp = (2 * sum) / n;

    for (int i = 0; i < n; i++)
    {
        ll x = a[i];
        ll y = temp - x;
        if (m.count(y))
        {
            res += m[y];
        }

        if (x == y)
        {
            res--;
        }
    }

    cout << res / 2 << endl;
}

int32_t main()
{
    fast_io;

    int t;
    cin >> t;
    while (t--)
    {
        solve();
    }

    return 0;
}

// using upper and lower bound

/*
int main() {
  ios::sync_with_stdio(false);
  cin.tie(0);
  #ifdef _DEBUG
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
  #endif
  int tt;
  cin >> tt;
  while (tt--) {
    int n;
    cin >> n;
    vector<int> a(n);
    long long sum = 0;
    for (int i = 0; i < n; i++) {
      cin >> a[i];
      sum += a[i];
    }
    long long two_sum = (sum + sum) / n;
    if (two_sum * n != sum + sum) {
      cout << 0 << '\n';
      continue;
    }
    sort(a.begin(), a.end());
    long long ans = 0;
    for (int i = 0; i < n - 1; i++) {
      int x = two_sum - a[i];
      int l = lower_bound(a.begin() + i + 1, a.end(), x) - a.begin();
      if (l >= n || a[l] != x) continue;
      int r = upper_bound(a.begin(), a.end(), x) - a.begin();
      ans += r - l;
    }
    cout << ans << '\n';
  }
  return 0;
}


*/