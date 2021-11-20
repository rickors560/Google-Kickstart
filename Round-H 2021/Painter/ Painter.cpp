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
#define mp make_pair

ll solve();
ll findMinimumStrokes(string s, ll n, char primaryColor, map<char, string> combinations);

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
    ll n;
    cin >> n;

    string p;
    cin >> p;

    map<char, string> combinations;
    combinations['O'] = {'R', 'Y'};
    combinations['P'] = {'R', 'B'};
    combinations['G'] = {'Y', 'B'};
    combinations['A'] = {'R', 'Y', 'B'};

    ll ans = 0;

    ans += findMinimumStrokes(p, n, 'R', combinations);
    ans += findMinimumStrokes(p, n, 'Y', combinations);
    ans += findMinimumStrokes(p, n, 'B', combinations);

    return ans;
}
ll findMinimumStrokes(string s, ll n, char primaryColor, map<char, string> combinations)
{
    ll res = 0;

    ll lastStrokeIndex = LONG_LONG_MIN;

    for (ll i = 0; i < n; i++)
    {
        if (s[i] == 'U')
            continue;

        if (s[i] == primaryColor || combinations[s[i]].find(primaryColor) != string::npos)
        {
            if (lastStrokeIndex != i - 1)
                res++;
            lastStrokeIndex = i;
        }
    }

    return res;
}