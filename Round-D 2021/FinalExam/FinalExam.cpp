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

void solve(ll t);

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    ll t;
    cin >> t;
    for (ll i = 0; i < t; i++)
    {
        solve(i);
    }
    return 0;
}
void solve(ll t)
{
    ll n, m;
    cin >> n >> m;
    map<ll, ll> problems;
    ll students[m];
    ll result[m];

    //Taking Input
    for (ll i = 0; i < n; i++)
    {
        ll a, b;
        cin >> a >> b;
        problems[a] = b;
    }

    for (ll i = 0; i < m; i++)
    {
        ll s;
        cin >> s;
        students[i] = s;
    }

    //Solution Starts Here
    for (ll i = 0; i < m; i++)
    {
        auto student = students[i];

        auto ub = problems.upper_bound(student);

        if (ub == problems.begin())
        {
            auto first = ub->first;
            auto second = ub->second;
            result[i] = first;

            if (first + 1 > second)
            {
                problems.erase(first);
            }
            else
            {
                problems.erase(first);
                problems[first + 1] = second;
            }
        }

        else if (ub == problems.end())
        {
            auto prev = problems.upper_bound(student);
            prev--;

            auto first = prev->first;
            auto second = prev->second;

            if (student >= second)
            {
                result[i] = second;

                if (first + 1 > second)
                    problems.erase(first);
                else
                    problems[first] = second - 1;
            }
            else
            {
                result[i] = student;

                problems.erase(first);

                if (first <= student - 1)
                    problems[first] = student - 1;
                if (student + 1 <= second)
                    problems[student + 1] = second;
            }
        }

        else
        {
            auto prev = problems.upper_bound(student);
            prev--;

            if (student >= prev->second && student < ub->first)
            {
                if (abs(student - prev->second) <= abs(student - ub->first))
                {
                    auto first = prev->first;
                    auto second = prev->second;
                    result[i] = second;

                    if (first + 1 > second)
                    {
                        problems.erase(first);
                    }
                    else
                    {
                        problems[first] = second - 1;
                    }
                }

                else
                {
                    auto first = ub->first;
                    auto second = ub->second;
                    result[i] = first;

                    if (first + 1 > second)
                    {
                        problems.erase(first);
                    }
                    else
                    {
                        problems.erase(first);
                        problems[first + 1] = second;
                    }
                }
            }

            else
            {
                auto prev = problems.upper_bound(student);
                prev--;

                auto first = prev->first;
                auto second = prev->second;
                result[i] = student;

                problems.erase(first);

                if (first <= student - 1)
                    problems[first] = student - 1;
                if (student + 1 <= second)
                    problems[student + 1] = second;
            }
        }
    }

    cout << "Case #" << t + 1 << ":";

    for (ll i = 0; i < m; i++)
    {
        cout << " " << result[i];
    }
    cout << endl;
}