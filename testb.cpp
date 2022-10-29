#include <iostream>
using namespace std;
typedef long long ll;

constexpr ll N = 2e5 + 10;
ll t, n, k, a[N];

bool sol()
{
    cin >> n >> k;
    k = n - k + 1;
    for (int i = k; i <= n; i++)
        cin >> a[i];
    if (k == n)
        return true;
    for (int i = n; i >= k + 1; i--)
        a[i] -= a[i - 1];
    for (int i = k + 1; i <= n - 1; i++)
        if (a[i] > a[i + 1])
            return false;
    if (a[k] > k * a[k + 1])
        return false;
    return true;
}

int main()
{
    ios::sync_with_stdio(0); cin.tie(0);
    cin >> t;
    while (t --)
        if (sol())
            cout << "YES\n";
        else
            cout << "No\n";
}
