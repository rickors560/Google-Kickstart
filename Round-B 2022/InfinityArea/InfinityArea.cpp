#include <bits/stdc++.h>

using namespace std;

#define ll long long

double solve();
double calculateArea(ll r);

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    cout.precision(6);

    long t;
    cin >> t;
    for (long T = 0; T < t; T++)
    {
        cout << "Case #" << T + 1 << ": " << fixed << solve() << endl;
    }
    return 0;
}

double solve()
{
    ll r, a, b;
    cin >> r >> a >> b;
    double result = 0;

    ll radius = r;
    ll i = 0;
    while (radius > 0)
    {
        result += calculateArea(radius);
        if (i % 2 == 0)
        {
            radius *= a;
        }
        else
        {
            radius /= b;
        }
        i++;
    }

    return result;
}

double calculateArea(ll r)
{
    return (M_PI * r * r);
}