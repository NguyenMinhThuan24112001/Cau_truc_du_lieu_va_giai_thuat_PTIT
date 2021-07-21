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
template <typename type>
istream &operator>>(istream &in, vector<type> &a)
{
    for (int i = 0; i < a.size(); i++)
        in >> a[i];
    return in;
}
template <typename type>
ostream &operator<<(ostream &out, const vector<type> &a)
{
    for (int i = 0; i < a.size(); i++)
        out << a[i] << " ";
    return out;
}
bool Multitests = 0;
ll test = 1, n, m, k, l, r, x, y;

void Solve()
{
    cin >> n;
    vector<ll> a(n), index(n);
    for (int i = 0; i < n; i++)
    {
        cin >> a[i];
        index[a[i] - 1] = i;
    }
    ll max_len, count;
    max_len = count = 1;
    for (int i = 1; i < n; i++)
    {
        if (index[i] > index[i - 1])
            count++, max_len = max(max_len, count);
        else
            count = 1;
    }
    cout << n - max_len << endl;
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
