#include <iostream>
#include <algorithm>
#include <map>
#include <vector>
using namespace std;
typedef long long ll;

constexpr ll N = 2e6;
ll t, n, a[200005], p[200010];

ll check(ll i1, ll i2)
{
    ll ans = 0;
    map<ll, ll> m;
    for (int i = i1; i <= i2; i++)
        m[p[i]] = m[p[i]] + 1;
    for (auto& pr : m)
        ans = max(ans, pr.second);
    return ans;
}

void sol()
{
    cin >> n;
    for (int i = 1; i <= n; i++)
    {
        cin >> a[i];
        p[i] = p[i - 1] + a[i];
    }
    vector<ll> pos;
    for (int i = 1; i <= n; i++)
        if (!a[i])
            pos.push_back(i);
    ll ans = 0;
    if (pos.empty())
    {
        for (int i = 1; i <= n; i++)
            if (!p[i])
                ans ++;
    }
    else
    {
        for (int i = 1; i < pos[0]; i++)
            if (!p[i])
                ans ++;
        for (int i = 0; i < pos.size() - 1; i++)
            ans += check(pos[i], pos[i + 1] - 1);
        ans += check(pos[pos.size() - 1], n);
    }
    cout << ans << '\n';
}
int main()
{
    ios::sync_with_stdio(0); cin.tie(0);
    cin >> t;
    while (t--)
        sol();
}


