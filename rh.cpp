#include <iostream>
using namespace std;
typedef long long ll;

ll pr(ll n)
{
    ll res = 1;
    while (n)
    {
        res *= (n % 10);
        n /= 10;
    }
    return res;
}

int main()
{
    ll l, r;
    cin >> l >> r;
    ll res = pr(l);
    for (ll i = l + 1; i <= r; i++)
        res = max(res, pr(i));
    cout << res;
}
