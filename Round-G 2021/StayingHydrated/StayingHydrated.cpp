#include <iostream>
#include <cstdio>
#include <string>
#include <bits/stdc++.h>
#include <algorithm>
#include <cmath>
#include <vector>
#include <map>
#include <fstream>

using namespace std;

#define ll long long

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    long t;
    cin >> t;
    for (long i = 0; i < t; i++)
    {
        ll k;
        cin >> k;

        ll points[k][4];

        vector<ll> x;
        vector<ll> y;

        ll sx = 0, sy = 0;

        for (ll j = 0; j < k; j++)
        {
            ll x1, y1, x2, y2;
            cin >> x1 >> y1 >> x2 >> y2;
            x.push_back(x1);
            x.push_back(x2);
            y.push_back(y1);
            y.push_back(y2);
        }

        sort(x.begin(), x.end());
        sort(y.begin(), y.end());

        //Optimal Solution will be Median of x and y sorted vectors. (As median will be equidistant from all)
        //And for K furnitures there will 2K points (means 2K x and 2K y, which is even).
        //As we have to choose min optimal solution.

        sx = min(x[k], x[k-1]);
        sy = min(y[k], y[k-1]);

        cout << "Case #" << i + 1 << ": " << sx << " " << sy << endl;
    }
    return 0;
}