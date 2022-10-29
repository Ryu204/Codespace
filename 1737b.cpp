#include <iostream>
#include <cmath>
using namespace std;

typedef long long ll;

ll t, l, r;

ll check(ll n)
{
    if (n == 0)
        return 0;
    ll x = sqrtl(n);
    if (n - x < x * x)
        return 3 * x -  2;
    if (n - 2 * x < x * x)
        return 3 * x - 1;
    return 3 * x;
}

void sol()
{
    cin >> l >> r;
    cout << check(r) - check(l - 1) << '\n';
}

int main()
{
    ios::sync_with_stdio(0); cin.tie(0);
    cin >> t;
    while (t--)
        sol();
}

