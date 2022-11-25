#include <iostream>
#include <algorithm>
using namespace std;
typedef long long ll;

constexpr ll N = 2e6;
ll t, n, a[200005], pr['9' + 10][200010];

bool check(ll i, ll lt)
{
    ll cnt = 0, mx = -1;
    for (char x = '0'; x <= '9'; x++)
    {
        cnt += (bool)(pr[x][i + lt - 1] - pr[x][i - 1]);
        mx = max(mx, pr[x][i + lt - 1] - pr[x][i - 1]);
    }
    if (mx <= cnt)
        return true;
    return false;
}

void sol()
{
    cin >> n;
    for (int i = 1; i <= n; i++)
    {
        char x;
        cin >> x;
        for (char j = '0'; j <= '9'; j++)
            if (j == x)
                pr[j][i] = pr[j][i - 1] + 1;
            else
                pr[j][i] = pr[j][i - 1];
    }
    ll ans = 0;
    for (int i = 1; i <= n; i++)
    {
        for (int lt = 1; i + lt - 1 <= n && lt <= 100; lt++)
        {
            if (check(i, lt))
                ans++;
        }
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

