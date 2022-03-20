#include <bits/stdc++.h>

using namespace std;

#define ll long long

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
    string i, p;
    cin >> i >> p;

    if (p.length() < i.length())
    {
        cout << "IMPOSSIBLE";
        return;
    }

    stack<char> st;

    int t = 0;
    for (int x = 0; x < p.length(); x++)
    {
        if (t < i.length() && p[x] == i[t])
        {
            st.push(p[x]);
            t++;
        }
    }

    if (t != i.length())
    {
        cout << "IMPOSSIBLE";
        return;
    }

    cout << p.length() - i.length();
}