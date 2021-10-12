#include <iostream>
#include <cstdio>
#include <string>
#include <bits/stdc++.h>
#include <algorithm>
#include <cmath>
#include <vector>
#include <map>
#include <fstream>
#include <utility>
#include <map>
#include <string>
#include <numeric>
#include <iostream>
#include <utility>
#include <iterator>
#include <algorithm>

using namespace std;

long solve()
{
    long n;
    cin >> n;

    char houses[n];
    cin >> houses;

    map<long, long> mp;

    long pb = -1;

    for (long i = 0; i < n; i++)
    {
        long h = (long)houses[i] - 48;

        if (h == 1)
        {

            if (mp.size() > 0)
            {
                for (long j = pb; j < i; j++)
                {
                    long key = j;
                    long value = mp[j];
                    if (value > abs(key - i) || value == -1)
                    {
                        mp[key] = abs(key - i);
                    }
                }
            }

            pb = i;
        }
        else
        {
            if (pb == -1)
            {
                mp[i] = -1;
            }
            else
            {
                mp[i] = abs(i - pb);
            }
        }
    }

    long r = 0;
    for (auto const &kp : mp)
    {
        r += kp.second;
    }

    return r;
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    long t;
    cin >> t;
    for (long i = 0; i < t; i++)
    {
        long r = solve();
        cout << "Case #" << i + 1 << ": " << r << endl;
    }
    return 0;
}