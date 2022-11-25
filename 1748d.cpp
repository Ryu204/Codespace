#include <iostream>
#include <algorithm>
using namespace std;
typedef long long ll;

constexpr ll N = 2e6;
ll a, b, d;

void sol()
{
    cin >> a >> b >> d;
    if (d == 1)
    {
        if (a == 1 && b == 1)
            cout << "1\n";
        else
            cout << "-1\n";
        return;
    }
    bool dpr = true;
    for (ll i = 2; i * i <= d; i++)
    {
        if (d % i)
            continue;

    }
    if (dpr)
    {

    }
}
int main()
{
    ios::sync_with_stdio(0); cin.tie(0);
    cin >> t;
    while (t--)
        sol();
}


