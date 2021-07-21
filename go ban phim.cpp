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

bool Multitests = 0;
ll test = 1, n, m, k, l, r, x, y;

void Solve()
{
    string str;
    cin >> str;
    string s1, s2;
    for (auto c : str)
    {
        if (c == '<')
        {
            if (s1.size())
            {
                s2.push_back(s1.back());
                s1.pop_back();
            }
        }
        else if (c == '>')
        {
            if (s2.size())
            {
                s1.push_back(s2.back());
                s2.pop_back();
            }
        }
        else if (c == '-')
        {
            if (s1.size())
                s1.pop_back();
        }
        else
        {
            s1.push_back(c);
        }
    }
    reverse(s2.begin(), s2.end());
    cout << s1 << s2 << endl;
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
