#include<iostream>
#include<algorithm>
using namespace std;
typedef long long ll;
constexpr ll N = 2e5 + 10;
ll a[N];

void sol()
{
    int n;
    cin >> n;
    for (int i = 1; i <= n; i++)
        cin >> a[i];
    ll u = *min_element(a + 1, a + n + 1), mx = 2 * u - 1, t = 0;
    for (int i = 1; i <= n; i++)
    {
        t += (a[i] + mx - 1) / mx - 1;
    }
    cout << t << '\n';
}

int main()
{
    int t;
    cin >> t;
    while (t --)
        sol();
}
