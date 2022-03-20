#include <bits/stdc++.h>

using namespace std;

#define ll long long int

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
    ll n;
    cin >> n;
    vector<int> nums;
    ll temp = n;

    ll sum = 0;
    while (temp > 0)
    {
        nums.push_back(temp % 10);
        sum += temp % 10;
        temp = temp / 10;
    }

    ll numToBeAdded = 9 - (sum % 9);
    if (numToBeAdded % 9 == 0)
        numToBeAdded = 0;

    ll ans = LONG_LONG_MAX;
    for (ll i = nums.size() - 1; i >= 0; i--)
    {
        ll x = 0;
        for (ll j = nums.size() - 1; j >= 0; j--)
        {
            if (numToBeAdded == 0 && i == nums.size() - 1)
            {
                x = LONG_LONG_MAX;
                break;
            }

            if (i == j)
            {
                x = x * 10 + numToBeAdded;
            }

            x = x * 10 + nums[j];
        }

        ans = min(ans, x);
    }

    ll x = 0;
    for (ll j = nums.size() - 1; j >= 0; j--)
    {
        x = x * 10 + nums[j];
    }
    x = x * 10 + numToBeAdded;
    ans = min(ans, x);

    return ans;
}