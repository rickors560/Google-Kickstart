#include <iostream>
#include <cstdio>
#include <string>
#include <bits/stdc++.h>
#include <algorithm>
#include <cmath>
#include <vector>
#include <map>
#include <fstream>
#include <limits>

using namespace std;

#define d double

d solve();

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    d t;
    cin >> t;
    for (d i = 0; i < t; i++)
    {
        d n, k;
        cin >> n >> k;

        vector<d> bananas(n);

        //For Prefix Sum 
        vector<d> pref(n + 1, 0);

        d ans = INFINITY;
        bool ansFound = false;

        for (d i = 0; i < n; i++)
        {
            d b;
            cin >> b;
            pref[i + 1] = pref[i] + b;

            bananas[i] = b;
        }

        //To store best 2nd contiguous section length
        vector<d> best(k+1, INFINITY);
        best[0]=0;

        for (d j = n - 1; j >= 0; j--)
        {
            //This is for 1st contiguous section i.e, (i to j)
            for (d i = j; i >= 0; i--)
            {
                auto s1 = pref[j + 1] - pref[i];
                if (s1 <= k)
                {
                    ans = min(ans, j - i + 1 + best[k - s1]);
                }
            }

            //This is for 2nd contiguous section i.e, (j to i)
            for (d i = j; i < n; i++)
            {
                auto x = pref[i + 1] - pref[j];

                if (x <= k)
                {
                    best[x] = min(best[x], i - j + 1);
                }
            }
        }

        if (ans >= INFINITY)
        {
            ans = -1;
        }

        cout << "Case #" << i + 1 << ": " << ans << endl;
    }
    return 0;
}
