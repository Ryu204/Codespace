#include <iostream>
using namespace std;
typedef long long ll;

constexpr ll N = 2e6;
ll t, n, a[N];

void sol()
{
    cin >> n;
    ll s = 0;
    for (int i = 1; i <= n; i++)
        cin >> a[i];
    ll mx = a[2];
    for (int i = 2; i <= n; i++)
        mx = min(mx, a[i]);
    if (a[1] > mx)
        cout << "Alice\n";
    else
        cout << "Bob\n";
}

int main()
{
    ios::sync_with_stdio(0); cin.tie(0);
    cin >> t;
    while (t--)
        sol();
}


