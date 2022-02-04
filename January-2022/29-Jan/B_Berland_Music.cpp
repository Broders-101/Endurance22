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
    int p[n + 1], q[n + 1];
    map<int, int> m;
    for (int i = 0; i < n; i++)
    {
        cin >> p[i];
        q[i] = p[i];
        m[p[i]] = i;
    }

    string s;
    cin >> s;
    vector<int> zeroes, ones;
    for (int i = 0; i < s.length(); i++)
    {
        if (s[i] == '0')
        {
            zeroes.pb(p[i]);
        }
        else
        {
            ones.pb(p[i]);
        }
    }

    sort(zeroes.rbegin(), zeroes.rend());
    sort(ones.rbegin(), ones.rend());

    sort(p, p + n);
    reverse(p, p + n);

    int i;
    for (i = 0; i < ones.size(); i++)
    {
        q[m[ones[i]]] = p[i];
    }
    for (int j = 0; j < zeroes.size(); j++)
    {
        q[m[zeroes[j]]] = p[i];
        i++;
    }

    for (int hell = 0; hell < n; hell++)
    {
        cout << q[hell] << " ";
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