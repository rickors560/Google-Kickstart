#include <bits/stdc++.h>

using namespace std;

#define ll long long int

void solve();

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    long t;
    cin >> t;
    for (long T = 0; T < t; T++)
    {
        cout << "Case #" << T + 1 << ": ";
        solve();
        cout << endl;
    }
    return 0;
}

void solve()
{
    string n;
    cin >> n;

    ll sum = 0;
    for (ll i = 0; i < n.size(); i++)
    {
        sum += n[i] - '0';
    }

    ll numToBeAdded = 9 - (sum % 9);
    numToBeAdded = numToBeAdded == 9 ? 0 : numToBeAdded;

    bool isAdded = false;
    for (ll i = 0; i < n.size(); i++)
    {
        if (numToBeAdded == 0 && i == 0 && !isAdded)
        {
            cout << n[i] << numToBeAdded;
            isAdded = true;
            continue;
        }

        // Optimal position will be just be before the digit greater than numToBeAdded
        if (n[i] - '0' > numToBeAdded && !isAdded)
        {
            cout << numToBeAdded;
            isAdded = true;
        }
        cout << n[i];
    }
    if (!isAdded)
        cout << numToBeAdded;
}