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
    vector<ll> v(n);
    for (ll &x : v)
    {
        cin >> x;
    }

    int minn = *min_element(v.begin(), v.end());

    for (int i = 0, k = 0; k < n / 2; i++)
    {
        if (v[i] != minn)
        {
            cout << v[i] << " " << minn << endl;
            k++;
        }
    }
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

// this sol gives memory limit exceeded

/*

void solve()
{
    ll n;
    cin >> n;
    vector<ll> v(n);
    map<ll, ll> m;
    for (ll &x : v)
    {
        cin >> x;
        m[x] = 1;
    }

    vector<pll> res;

    for (int i = 0; i < n - 1; i++)
    {
        for (int j = i + 1; j < n; j++)
        {
            if (v[i] != v[j])
            {
                res.pb({v[i], v[j]});
                res.pb({v[j], v[i]});
            }
        }
    }

    int count = floor(n / 2);

    int len = res.size();

    for (int i = 0; i < len; i++)
    {
        int x = res[i].first;
        int y = res[i].second;

        if (count)
        {
            if (!m[x % y])
            {
                cout << x << " " << y << endl;
                count--;
            }
        }
        else
        {
            break;
        }
    }
}

*/