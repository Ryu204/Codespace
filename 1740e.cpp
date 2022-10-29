#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;
typedef long long ll;

ll t, n, p[200010], c[200020];
vector<vector<ll>> v;

void sol()
{
    cin >> n;
    for (int i = 1; i <= n; i++)
        c[i] = 0;
    v.resize(n + 1);
    vector<ll> f(n + 1);
    for (auto& i : v)
        i.clear();
    for (int i = 2; i <= n; i++)
    {
        cin >> p[i];
        v[p[i]].push_back(i);
    }
    for (int i = n; i >= 1; i--)
    {
        f[i] = 1;
        if (v[i].size() == 1)
            f[i] += f[v[i][0]];
        else if (v[i].size() > 1)
        {
            for (auto& ch : v[i])
                f[i] += max<ll>(f[ch] - 1, 0);
            f[i]++;
        }
        // cout << f[i] << ' ';
    }

    cout << f[1] << endl;
}

int main()
{
    t = 1;
    while (t--)
        sol();
}
