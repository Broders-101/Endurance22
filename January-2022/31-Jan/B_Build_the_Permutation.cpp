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
    ll n, a, b;
    cin >> n >> a >> b;

    if (a + b > n - 2)
    {
        cout << -1 << endl;
    }
    else if (abs(a - b) > 1)
    {
        cout << -1 << endl;
    }
    else
    {
        if (a == 0 && b == 0)
        {
            for (int i = 1; i <= n; i++)
            {
                cout << i << " ";
            }
            cout << endl;
        }
        else if (a == 1 && b == 0)
        {
            for (int i = 1; i <= n - 2; i++)
            {
                cout << i << " ";
            }
            cout << n << " " << n - 1 << endl;
        }
        else if (a == 0 && b == 1)
        {
            cout << "2 1"
                 << " ";
            for (int i = 3; i <= n; i++)
            {
                cout << i << " ";
            }
            cout << endl;
        }
        else
        {
            ll x;
            if (a > b)
            {
                x = a + b + 1;

                for (int i = 1; i <= n - x; i++)
                {
                    cout << i << " ";
                }

                for (int i = n - x + 1; i <= n; i += 2)
                {
                    cout << i + 1 << " " << i << " ";
                }
                cout << endl;
            }
            else if (a < b)
            {
                x = a + b + 1;

                for (int i = 1; i <= x; i += 2)
                {
                    cout << i + 1 << " " << i << " ";
                }

                for (int i = x + 1; i <= n; i++)
                {
                    cout << i << " ";
                }
                cout << endl;
            }
            else
            {
                x = a + b;

                for (int i = 1; i <= x; i += 2)
                {
                    cout << i + 1 << " " << i << " ";
                }

                for (int i = x + 1; i <= n - 2; i++)
                {
                    cout << i << " ";
                }

                cout << n << " " << n - 1 << " ";
                cout << endl;
            }
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