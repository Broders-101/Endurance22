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
    int n, q;
    cin >> n >> q;
    string s;
    cin >> s;

    int ans = 0;
    for (int i = 0; i < n - 2; i++)
    {
        if (s[i] == 'a' && s[i + 1] == 'b' && s[i + 2] == 'c')
        {
            ans++;
        }
    }

    for (int j = 0; j < q; j++)
    {
        int pos;
        char hell;
        cin >> pos >> hell;
        pos--;

        if (s[pos] == hell)
        {
            cout << ans << endl;
            continue;
        }
        else
        {
            int i = pos;
            if (s[pos] == 'a')
            {
                if (s[i] == 'a' && s[i + 1] == 'b' && s[i + 2] == 'c')
                {
                    ans--;
                }
            }
            else if (s[pos] == 'b')
            {
                if (s[i - 1] == 'a' && s[i] == 'b' && s[i + 1] == 'c')
                {
                    ans--;
                }
            }
            else
            {
                if (s[i - 2] == 'a' && s[i - 1] == 'b' && s[i] == 'c')
                {
                    ans--;
                }
            }

            s[pos] = hell;

            if (hell == 'a')
            {
                if (i + 2 >= n)
                {
                    cout << ans << endl;
                    continue;
                }
                else if (s[i] == 'a' && s[i + 1] == 'b' && s[i + 2] == 'c')
                {
                    ans++;
                    cout << ans << endl;
                }
                else
                {
                    cout << ans << endl;
                }
            }
            else if (hell == 'b')
            {
                if (i + 1 >= n && i - 1 < 0)
                {
                    cout << ans << endl;
                    continue;
                }
                else if (s[i - 1] == 'a' && s[i] == 'b' && s[i + 1] == 'c')
                {
                    ans++;
                    cout << ans << endl;
                }
                else
                {
                    cout << ans << endl;
                }
            }
            else
            {
                if (i - 2 < 0)
                {
                    cout << ans << endl;
                    continue;
                }
                else if (s[i - 2] == 'a' && s[i - 1] == 'b' && s[i] == 'c')
                {
                    ans++;
                    cout << ans << endl;
                }
                else
                {
                    cout << ans << endl;
                }
            }
        }
    }
}

int32_t main()
{
    fast_io;

    // int t = 1;
    // cin >> t;
    // while (t--)
    // {
    solve();
    // }

    return 0;
}