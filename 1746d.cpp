#include <iostream>
#include <vector>
#include <algorithm>
#include <map>
using namespace std;
typedef long long ll;

ll n, t, k, s[200010];
vector<vector<ll>> child;
map<pair<ll, ll>, ll> m;

ll max_val(ll num, ll ver)
{
    pair<ll, ll> pp(num, ver);
    if (m.find(pp) != m.end())
        return m[pp];
    if (child[ver].empty())
        return num * s[ver];
    if (!num)
        return 0;

    ll ans = 0;
    vector<ll> v;

    for (auto& c : child[ver])
    {
        v.push_back(max_val(num / child[ver].size(), c));
        ans += v.back();
    }

    if (num % child[ver].size() == 0)
    {
        m[pp] = ans + num * s[ver];
        return ans + num * s[ver];
    }

    for (ll i = 0; i < v.size(); i++)
        v[i] = max_val(num / child[ver].size() + 1, child[ver][i]) - v[i];
    sort(v.begin(), v.end(), greater<ll>());
    for (ll i = 0; i < num - (num / child[ver].size()) * child[ver].size(); i++)
        ans += v[i];
    m[pp] = ans + num * s[ver];
    return ans + num * s[ver];
}

void sol()
{
    cin >> n >> k;
    child.clear(); child.resize(n + 1); m.clear();
    for (ll i = 2; i <= n; i++)
    {
        ll x;
        cin >> x;
        child[x].push_back(i);
    }
    for (ll i = 1; i <= n; i++)
        cin >> s[i];
    cout << max_val(k, 1) << '\n';
}

int main()
{
    ios::sync_with_stdio(0); cin.tie(0);
    cin >> t;
    while (t--)
        sol();
}


