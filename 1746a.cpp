#include <iostream>
#include <vector>
using namespace std;
typedef long long ll;

ll n, t, k;

void sol()
{
    cin >> n >> k;
    bool y = false;
    for (int i = 1; i <= n; i++)
    {
        int x;
        cin >> x;
        if (x == 1)
            y = true;
    }
    if (y)
        cout << "YES\n";
    else
        cout << "NO\n";
}

int main()
{
    ios::sync_with_stdio(0); cin.tie(0);
    cin >> t;
    while (t--)
        sol();
}
