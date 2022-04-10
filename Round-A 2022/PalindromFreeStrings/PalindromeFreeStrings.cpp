#include <bits/stdc++.h>

using namespace std;

#define ll long long

void solve();
bool checkPalindromeFreeString(ll index, string lastSuffix);
bool checkStringIsPalindrome(string &str);
bool isPalindrome(string str);

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
    }
    return 0;
}

map<pair<ll, string>, bool> cache;
string s;

void solve()
{
    cache.clear();

    ll n;
    cin >> n;

    string str;
    cin >> str;

    if (n < 5)
    {
        cout << "POSSIBLE" << endl;
        return;
    }

    s = str;

    bool ans = checkPalindromeFreeString(0, "");
    if (ans)
    {
        cout << "POSSIBLE" << endl;
        return;
    }
    cout << "IMPOSSIBLE" << endl;
    return;
}

bool checkPalindromeFreeString(ll index, string lastSuffix)
{
    if (cache.find({index, lastSuffix}) != cache.end())
        return cache[{index, lastSuffix}];

    if (checkStringIsPalindrome(lastSuffix))
        return false;

    if (index == s.size())
        return true;

    // Always pass last 5 characters string not whole, as previous characters are already checked.
    if (lastSuffix.size() > 5)
        lastSuffix = lastSuffix.substr(lastSuffix.size() - 5, 5);

    bool ans;
    if (s[index] == '?')
    {
        string t1 = lastSuffix + '0';
        string t2 = lastSuffix + '1';
        ans = checkPalindromeFreeString(index + 1, t1) || checkPalindromeFreeString(index + 1, t2);
    }
    else
    {
        string t = lastSuffix + s[index];
        ans = lastSuffix.size() < 5 ? checkPalindromeFreeString(index + 1, t) : checkPalindromeFreeString(index + 1, t);
    }

    cache[{index, lastSuffix}] = ans;
    return ans;
}

bool checkStringIsPalindrome(string &str)
{
    if (str.length() < 5)
        return false;

    if (str.length() == 5)
        return isPalindrome(str);

    // for n == 6
    //  Check if string is pallindrome, also check for it sub-strings
    return (isPalindrome(str) || isPalindrome(str.substr(0, 5)) || isPalindrome(str.substr(1, 5)));
}

bool isPalindrome(string str)
{
    if (str.size() < 5)
        return true;

    int l = 0;
    int r = str.size() - 1;

    while (l < r)
    {
        if (str[l] != str[r])
            return false;

        l++;
        r--;
    }

    return true;
}