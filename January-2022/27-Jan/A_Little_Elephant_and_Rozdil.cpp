#include <bits/stdc++.h>
using namespace std;

int main()
{
    int n;
    cin >> n;
    int time;
    int min_time = 1e9 + 1;
    int min_index = 0;
    int count = 1;

    for (int i = 1; i <= n; i++)
    {
        cin >> time;
        if (time < min_time)
        {
            min_time = time;
            min_index = i;
            count = 1;
        }
        else if (time == min_time)
        {
            count++;
        }
    }

    if (count == 1)
    {
        cout << min_index << endl;
    }
    else
    {
        cout << "Still Rozdil" << endl;
    }
}