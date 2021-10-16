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

string solve();

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    long t;
    cin >> t;
    for (long i = 0; i < t; i++)
    {
        cout << "Case #" << i+1 << ": " << solve() << endl;
    }
    return 0;
}

string solve()
{
    ll n, d, c, m;

    cin >> n >> d >> c >> m;

    string animals;

    cin >> animals;

    ll dogs = count(animals.begin(), animals.end(), 'D');
    ll cats = count(animals.begin(), animals.end(), 'C');

    bool isAllDogFed = false;

    if (dogs == 0)
    {
        isAllDogFed = true;
    }

    else
    {
        for (ll i = 0; i < n; i++)
        {
            char animal = animals.at(i);

            if (animal == 'C')
            {
                if (c > 0)
                {
                    c--;
                    cats--;
                }
                else if (dogs > 0)
                {
                    isAllDogFed = false;
                    break;
                }
            }
            else if (animal == 'D')
            {
                if (d > 0)
                {
                    d--;
                    dogs--;
                    c = c + m;
                }
                else if (dogs > 0)
                {
                    isAllDogFed = false;
                    break;
                }
            }

            if (i == n - 1 && dogs == 0)
            {
                isAllDogFed = true;
            }
        }
    }

    if (isAllDogFed)
    {
        return "YES";
    }
    else
    {
        return "NO";
    }
}