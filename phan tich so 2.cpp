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
    out << "(";
    for (int i = 0; i < a.size() - 1; i++)
        out << a[i] << " ";
    out << a.back() << ")";
    return out;
}

bool Multitests = 1;
ll test = 1, n, m, k, l, r, x, y;
matrix ans;
set<multiset<ll>> S;
void Cal(vector<ll> a)
{
    multiset<ll> s(a.begin(), a.end());
    if (S.find(s) == S.end())
    {
        S.insert(s);
        ans.push_back(a);
    }
    ll val = a.back();
    a.pop_back();
    for (int i = 1; i < val; i++)
    {
        a.push_back(val - i);
        a.push_back(i);
        Cal(a);
        a.pop_back();
        a.pop_back();
    }
}

void Solve()
{
    cin >> n;
    ans.clear();
    S.clear();
    Cal({n});
    cout << ans.size() << endl;
    for (auto v : ans)
        cout << v << " ";
    cout << endl;
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
