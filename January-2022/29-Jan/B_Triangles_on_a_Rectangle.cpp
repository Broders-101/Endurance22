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

    long long int w, h;
    cin >> w >> h;

    long long int k1, k2, k3, k4;

    cin >> k1;
    long long int a[k1];
    for (int i = 0; i < k1; i++)
    {
        cin >> a[i];
    }

    k1 = h * (a[k1 - 1] - a[0]);

    cin >> k2;
    long long int b[k2];
    for (int i = 0; i < k2; i++)
    {
        cin >> b[i];
    }

    k2 = h * (b[k2 - 1] - b[0]);

    cin >> k3;
    long long int c[k3];
    for (int i = 0; i < k3; i++)
    {
        cin >> c[i];
    }

    k3 = w * (c[k3 - 1] - c[0]);

    cin >> k4;
    long long int d[k4];
    for (int i = 0; i < k4; i++)
    {
        cin >> d[i];
    }

    k4 = w * (d[k4 - 1] - d[0]);

    cout << max({k1, k2, k3, k4}) << endl;
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