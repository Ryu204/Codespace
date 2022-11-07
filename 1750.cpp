#pragma GCC target ("avx2")
#pragma GCC optimization ("O3")
#pragma GCC optimization ("unroll-loops")

#include <iostream>
#include <vector>
#include <map>
#include <set>
using namespace std;
typedef long long ll;
typedef pair<ll, ll> pll;

map<ll, vector<ll>> mapp;
map<pll, ll> map2;
set<ll> pri;

bool prime(ll n)
{
    if (pri.count(n))
        return true;
    if (n < 2)
        return false;
    for (ll i = 2; i * i < n; i++)
        if (n % i == 0)
            return false;
    pri.insert(n);
    return true;
}

// n >= 2
inline vector<ll> fact(ll n)
{
    if (mapp.find(n) != mapp.end())
        return mapp[n];
    vector<ll> res;
    ll c = 2;
    while(n > 1)
    {
        if(n % c == 0)
        {
            res.push_back(c);
            while (n % c == 0)
                n /= c;
        }
        else if (c == 2)
            c = 3;
        else
            c += 2;
        if (prime(n))
        {
            res.push_back(n);
            mapp[n] = res;
            return res;
        }
    }
    mapp[n] = res;
    return res;
}

inline ll counter(ll u, ll lim)
// co-prime with u within [1,lim]
{
    if (u == 1)
        return lim;
    if (map2.find(pll(u, lim)) != map2.end())
        return map2[pll(u, lim)];
    auto v = fact(u);
    ll res = 0;
    for (int i = 1; i < (1ll << v.size()); i++)
    {
        ll sig = -1, tmp = 1;
        for (int bit = 0; bit < v.size(); bit++)
        {
            if (i & (1ll << bit))
            {
                sig *= -1;
                tmp *= v[bit];
            }
        }
        res += sig * (lim / tmp);
    }
    map2[pll(u, lim)] = lim - res;
    return lim - res;
}

ll n, t, m, a[200010];
const ll MOD = 998244353;

void sol()
{
    cin >> n >> m;
    for (int i = 1; i <= n; i++)
        cin >> a[i];
    ll res = 1;
    for (int i = 2; i <= n; i++)
    {
        if (a[i - 1] % a[i])
        {
            cout << "0\n";
            return;
        }
        res = res * (counter(a[i - 1] / a[i], m / a[i]) % MOD) % MOD;
    }
    cout << res << '\n';
}

int main()
{
    ios::sync_with_stdio(0); cin.tie(0);
    cin >> t;
    while (t--)
        sol();
}
