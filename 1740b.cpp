#include <iostream>
#include <algorithm>
#include <map>
using namespace std;
typedef long long ll;
typedef pair<ll, ll> pll;
#define fi first
#define se second

ll t, n;
pll a[200010];

void sol()
{
    cin >> n;
    for (int i = 1; i <= n; i++)
    {
        cin >> a[i].fi >> a[i].se;
        if (a[i].fi < a[i].se)
            swap(a[i].fi, a[i].se);
    }
    sort(a + 1, a + n + 1);
    ll res = 0, mx = a[1].fi;
    for (int i = 1; i <= n; i++)
    {
        res += 2 * a[i].se;
        mx = max(mx, a[i].fi);
    }
    cout << res + 2 * mx << endl;
}

int main()
{
    ios::sync_with_stdio(0); cin.tie(0);
    cin >> t;
    while (t--)
        sol();
}
