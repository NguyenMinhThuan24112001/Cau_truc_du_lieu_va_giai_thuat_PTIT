#include <bits/stdc++.h>
#define author "CODE BY KQamazing"
#define faster                    \
    ios_base::sync_with_stdio(0); \
    cin.tie();                    \
    cout.tie()
#define ll long long
#define ld long double
#define pii pair<int, int>
#define pll pair<ll, ll>
#define pld pair<ld, ld>
#define matrix vector<vector<ll>>
#define Modd (ll)(1e9 + 7)

using namespace std;
template <typename T1, typename T2>
T1 Convert(T2 s)
{
    stringstream ss;
    T1 num;
    ss << s;
    ss >> num;
    return num;
}
bool Multitests = 1;
ll test = 1, n, m, k, l, r, x, y;
bool kt;
string str, ans;

void BT(string &s)
{
    if (kt)
        return;
    int I = -1;
    for (int i = 0; i < s.size(); i++)
    {
        if (s[i] == '?')
        {
            I = i;
            break;
        }
    }
    if (I != -1)
    {
        if (I == 3)
        {
            s[I] = '+';
            BT(s);
            s[I] = '-';
            BT(s);
            s[I] = '?';
        }
        else
        {
            for (int i = 0; i < 10; i++)
            {
                if (!i && (I == 0 || I == 5 || I == 10))
                    continue;
                s[I] = '0' + i;
                BT(s);
            }
            s[I] = '?';
        }
    }
    else
    {
        ll v1 = Convert<ll>(s.substr(0, 2));
        ll v2 = Convert<ll>(s.substr(5, 2));
        ll v3 = Convert<ll>(s.substr(10, 2));
        // cout << v1 << " " << v2 << " " << v3 << endl;
        if (s[3] == '+' && v1 + v2 == v3)
        {
            ans = s;
            kt = 1;
        }
        if (s[3] == '-' && v1 - v2 == v3)
        {
            ans = s;
            kt = 1;
        }
    }
}

void Solve()
{
    ans = "WRONG PROBLEM!";
    kt = 0;
    getline(cin, str);
    if (str[3] == '/' || str[3] == '*')
    {
        cout << ans << endl;
        return;
    }
    str[8] = '=';
    BT(str);
    cout << ans << endl;
}

int main()
{
    faster;

    if (Multitests)
        (cin >> test).ignore();
    while (test--)
        Solve();
    return 0;
}
