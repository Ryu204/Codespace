#include <iostream>
using namespace std;

typedef long long ll;

ll n, t, x, y;

void sol()
{
    cin >> n >> x >> y;
    if (min(x, y) > 0 || max(x, y) < 1)
    {
        cout << "-1\n";
        return;
    }

    if (y == 0)
        swap(x, y);
    if ((n - 1) % y == 0)
    {
        for (int i = 1; i + y <= n; i += y)
        {
            for (int j = 1; j <= y; j++)
                    cout << i + 1 << ' ';
        }
        cout << '\n';
    }
    else
        cout << "-1\n";
}

int main()
{
    ios::sync_with_stdio(0); cin.tie(0);
    cin >> t;
    while (t --)
        sol();
}
