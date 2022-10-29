#include <iostream>
#include <vector>
#include <map>
using namespace std;
typedef long long ll;
typedef vector<ll> vll;
typedef pair<vll, vll> pvv;
const ll N = 1e5 + 10, M = 29;
ll n, a[N], b[N], t;

void sol()
{
    cin >> n;
    for (int i = 1; i <= n; i++)
        cin >> a[i];
    for (int i = 1; i <= n; i++)
        cin >> b[i];
    vector<pvv> vec;
    vll bitc;
    for (int i = 0; i <= M; i++)
    {
        vll tmp1, tmp2;
        for (int j = 1; j <= n; j++)
        {
            if (a[j] & (1ll << i))
                tmp1.push_back(j);
            if ((b[j] & (1ll << i)) == 0)
                tmp2.push_back(j);
        }
        if (tmp1.size() == tmp2.size())
        {
            vec.push_back(pvv(tmp1, tmp2));
            bitc.push_back(i);
        }
    }
    vector<ll> maskx(n + 1), masky(n + 1); // maskx[i] = sets containing a[i];
    ll current_set = -1, ans = 0;

    for (int i = vec.size() - 1; i >= 0; i--)
    {
        current_set ++;
        vector<bool> dx(n + 10), dy(n + 10);
        for (auto& x : vec[i].first)
            dx[x] = true;
        for (auto& y : vec[i].second)
            dy[y] = true;
        auto maskx_tmp = maskx, masky_tmp = masky;
        for (int j = 1; j <= n; j++)
        {
            if (dx[j])
                maskx_tmp[j] |= (1ll << current_set);
            if (dy[j])
                masky_tmp[j] |= (1ll << current_set);
        }
        map<ll, ll> cnt_x, cnt_y;
        for (int j = 1; j <= n; j++)
        {
            cnt_x[maskx_tmp[j]]++;
            cnt_y[masky_tmp[j]]++;
        }
        auto cont = false;
        for (auto& p : cnt_x)
            if (cnt_y[p.first] != p.second)
            {
                cont = true;
                break;
            }
        if (cont)
            continue;

        ans |= 1ll << bitc[i];
        maskx = maskx_tmp;
        masky = masky_tmp;
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
