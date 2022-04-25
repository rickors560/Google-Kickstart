#include <bits/stdc++.h>

using namespace std;

#define ll long long

ll solve();
bool isPalindrome(ll n);

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

    ll result = 0;

    // If a, b are two factors of N (N = ab), then a <= square_root_of(N) and b = N/a

    for (ll i = 1; i * i <= n; i++)
    {
        if (n % i == 0)
        {
            if (isPalindrome(i))
                result++;
            if (i != n / i && isPalindrome(n / i))
                result++;
        }
    }

    return result;
}

bool isPalindrome(ll n)
{
    string s = to_string(n);
    string rev(s.rbegin(), s.rend());
    return s == rev;
}