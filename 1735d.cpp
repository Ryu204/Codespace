#include <iostream>
#include <vector>
#include <map>
using namespace std;
typedef long long ll;
ll n, k, t;

vector<vector<ll>> type;

vector<ll> get(vector<ll>& x, vector<ll>& y)
{
    vector<ll> tmp(k);
    for (int i = 0; i < k; i++)
        if (x[i] != y[i])
            tmp[i] = 3 - x[i] - y[i];
        else
            tmp[i] = x[i];
    return tmp;
}

void sol()
{
    cin >> n >> k;
    vector<vector<ll>> vec(n);
    for (auto& v  : vec)
        v.resize(k);
    for (int i = 0; i < n; i++)
        for (int j = 0; j < k; j++)
            cin >> vec[i][j];
    map<vector<ll>, int> m;
    for (auto& v : vec)
        m.emplace(v, 0);
    for (int i = 0; i < n; i++)
        for (int j = i + 1; j < n; j++)
        {
            vector<ll> re = get(vec[i], vec[j]);
            if (m.find(re) != m.end())
                m[re]++;
        }
    ll ans = 0;
    for (auto& p : m)
        ans += p.second * (p.second - 1) / 2;
    cout << ans << '\n';
}

int main()
{
    ios::sync_with_stdio(0); cin.tie(0);
    t = 1;
    while (t --)
        sol();
}

