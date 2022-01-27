// Method - 2

#include <iostream>
#include <math.h>
using namespace std;

int main()
{
    int n, m, last;
    double t, max(0);
    cin >> n >> m;

    for (int i = 1; i <= n; i++)
    {
        cin >> t;
        if (ceil(t / m) >= max)
        {
            last = i;
            max = ceil(t / m);
        }
    }

    cout << last << endl;
    return 0;
}

// #include <bits/stdc++.h>
// using namespace std;
// #define fast_io                       \
//     ios_base::sync_with_stdio(false); \
//     cin.tie(NULL);                    \
//     cout.tie(0);
// #define endl "\n"
// #define ull unsigned long long
// #define pb push_back
// typedef long long ll;
// typedef pair<int, int> pii;
// const int MOD = 1000000007;
// const int N = 1e3 + 2;
// const int MAXN = 2e5 + 5;

// const int M = 1e9 + 7;
// long long mod(long long x)
// {
//     return ((x % M + M) % M);
// }
// long long add(long long a, long long b)
// {
//     return mod(mod(a) + mod(b));
// }
// long long mul(long long a, long long b)
// {
//     return mod(mod(a) * mod(b));
// }

// ll modPow(ll a, ll b)
// {
//     if (b == 0)
//         return 1LL;
//     if (b == 1)
//         return a % M;
//     ll res = 1;
//     while (b)
//     {
//         if (b % 2 == 1)
//             res = mul(res, a);
//         a = mul(a, a);
//         b = b / 2;
//     }
//     return res;
// }

// void sieve(int n, bool isPrime[])
// {
//     isPrime[0] = isPrime[1] = false;
//     for (int i = 2; i * i <= n; i++)
//     {
//         if (isPrime[i])
//         {
//             for (int j = i * i; j <= n; j += i)
//             {
//                 isPrime[j] = false;
//             }
//         }
//     }
// }

// int lcm(int a, int b)
// {
//     int c = __gcd(a, b);
//     return (a / c) * b;
// }

// int calc(int n)
// {
//     int res = 0;
//     while (n)
//     {
//         res += n % 10;
//         n /= 10;
//     }
//     return res;
// }

// void solve()
// {

//     int n, m;
//     cin >> n >> m;
//     queue<pii> q;
//     int i = 0;
//     while (n--)
//     {
//         int x;
//         cin >> x;
//         q.push({i + 1, x});
//         i++;
//     }
//     int res;
//     while (!q.empty())
//     {
//         res = q.front().first;
//         pii top = q.front();
//         q.pop();
//         if (top.second > m)
//         {

//             top.second -= m;
//             q.push(top);
//         }
//     }

//     cout << res << endl;
// }

// int32_t main()
// {
//     fast_io;

//     int t = 1;
//     // cin >> t;
//     while (t--)
//     {
//         solve();
//     }

//     return 0;
// }