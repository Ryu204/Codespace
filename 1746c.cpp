#include <iostream>
using namespace std;
typedef long long ll;

ll n, t, a[100010], b[100010];

void sol()
{
    cin >> n;
    for (int i = 1; i <= n; i++)
        cin >> a[i];
    for (int i = 1; i <= n - 1; i++)
        b[a[i]] = i + 1;
    b[a[n]] = 1;
    for (int i = 1; i <= n; i++)
        cout << b[i] << ' ';
    cout << '\n';
}

int main()
{
    ios::sync_with_stdio(0); cin.tie(0);
    cin >> t;
    while (t--)
        sol();
}


