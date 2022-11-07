#include <iostream>
using namespace std;
typedef long long ll;

constexpr ll N = 2e6;
ll t, n;
char a[200010];

void sol()
{
    cin >> n;
    for (int i = 1; i <= n; i++)
        cin >> a[i];
    a[n + 1] = 'z';
    a[0] = 'z';
    char val = a[1];
    ll cnt = 0, res = 0, oc = 0, zc = 0;
    for (int i = 1; i <= n + 1; i++)
    {
        if (a[i] == val)
            cnt++;
        else
        {
            res = max(res, cnt * cnt);
            cnt = 1;
            val = a[i];
        }
        oc += (a[i] == '1');
        zc += (a[i] == '0');
    }
    cout << max(res, zc * oc) << '\n';
}
int main()
{
    ios::sync_with_stdio(0); cin.tie(0);
    cin >> t;
    while (t--)
        sol();
}

