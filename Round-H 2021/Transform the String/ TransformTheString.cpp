#include <iostream>
#include <cstdio>
#include <string>
#include <bits/stdc++.h>
#include <algorithm>
#include <cmath>
#include <vector>
#include <map>
#include <fstream>
#include <iomanip>

using namespace std;

#define ll long long

ll solve();
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    long t;
    cin >> t;
    for (long T = 0; T < t; T++)
    {
        ll result = solve();
        cout << "Case #" << T + 1 << ": " << result << endl;
    }
    return 0;
}
ll solve()
{
    string s, f;
    cin >> s >> f;

    ll ans = 0;

    if (s == f)
    {
        return ans;
    }

    if (f.length() == 26)
    {
        return ans;
    }

    map<char, ll> seq;
    for (auto c : s)
    {
        seq[c]++;
    }

    for (auto c : seq)
    {
        ll rep = c.second;
        char letter = c.first;
        ll temp = LLONG_MAX;

        for (auto compare : f)
        {
            ll t1 = abs(long(letter) - long(compare));
            ll t2 = abs(long(letter) - long(compare));
            t2 = abs(t2 - 26);

            if (letter == compare)
            {
                temp = 0;
                break;
            }

            else if (t1 <= temp || t2 <= temp)
            {
                temp = min(min(t1, t2), temp);
            }
        }

        if (temp > 0 && temp != LLONG_MAX)
            ans += temp * rep;
    }

    return ans;
}