#include <iostream>

using namespace std;

typedef long long ll;

ll t, n, a[100010];

void sol()
{
    cin >> n;
    for (int i = 1; i <= n; i++)
        cin >> a[i];
    if (n == 1)
    {
        cout << "0\n";
        return;
    }
    cout << n - 1 << "\n1 " << n << '\n';
    for (int i = 2; i <= n - 1; i++)
    {
        if ((a[i] + a[1]) % 2 == 0)
            cout << i << ' ' << n;
        else
            cout << 1 << ' ' << i;
        cout << '\n';
    }
}

int main()
{
    ios::sync_with_stdio(0); cin.tie(0);
    cin >> t;
    while (t --)
        sol();
}
