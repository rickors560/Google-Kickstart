#include <bits/stdc++.h>

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
        cout << "Case #" << T + 1 << ": " << solve() << endl;
    }
    return 0;
}

ll solve()
{
    ll a, b;
    cin >> a >> b;

    map<ll, pair<ll, ll>> cache;

    ll ans = 0;

    for (ll i = a; i <= b; i++)
    {
        ll t = i;
        ll sum = 0;
        ll multiply = 1;

        while (t > 0)
        {

            ll x = t % 10;
            sum += x;
            multiply *= x;

            t = t / 10;
        }

        if (multiply % sum == 0)
            ans++;
    }

    return ans;
}