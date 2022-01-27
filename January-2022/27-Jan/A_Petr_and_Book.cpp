#include <bits/stdc++.h>
using namespace std;

int main()
{
    int n;
    cin >> n;

    int a[7];

    for (int i = 0; i < 7; i++)
    {
        cin >> a[i];
    }

    int res = a[0];
    int i = 0;

    while (res < n)
    {
        i++;
        i = i % 7;
        res += a[i];
    }

    cout << i + 1 << endl;
}