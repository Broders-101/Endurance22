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
typedef pair<long, long> pll;
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
    ll n;
    cin >> n;
    vector<pll> v(n);

    for (int i = 0; i < n; i++)
    {
        int x;
        cin >> x;
        v.pb({x, i});
    }

    sort(v.rbegin(), v.rend());

    vector<ll> ans(n);
    int mid = (n + 2) / 2;
    int left = mid - 1, right = mid + 1;
    bool isLeft = 1;

    ll res = 0;

    for (int i = 0; i < n; i++)
    {
        ll count = v[i].first;
        ll index = v[i].second;

        if (isLeft)
        {
            ans[index] = left;
            ll cost = 2 * abs(left - mid);
            res += count * cost;
            isLeft = 0;
            left--;
        }
        else
        {
            ans[index] = right;
            ll cost = 2 * abs(right - mid);
            res += count * cost;
            isLeft = 1;
            right++;
        }
    }

    cout << res << endl;

    cout << mid << " ";

    for (auto x : ans)
    {
        cout << x << " ";
    }
    cout << endl;
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