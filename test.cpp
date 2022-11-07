#include <iostream>
using namespace std;
typedef long long ll;

constexpr ll N = 2e6;
ll t, n, a[100005];

void sol()
{
    cin >> n;
    for (int i = 1; i <= n; i++)
        cin >> a[i];
    if (a[1] != 1)
        cout << "NO\n";
    else
        cout << "YES\n";
}
int main()
{
    ios::sync_with_stdio(0); cin.tie(0);
    cin >> t;
    while (t--)
        sol();
}
