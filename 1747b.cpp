#include <iostream>
using namespace std;
typedef long long ll;

constexpr ll N = 2e6;
ll t, n, a;

void sol()
{
    cin >> n;
    cout << (n + 1) / 2 << '\n';
    for (int i = 1; i <= (n + 1) / 2; i++)
    {
        cout << 3 * i - 2 << ' ' << 3 * (n - i + 1) << '\n';
    }
    return;
}

int main()
{
    ios::sync_with_stdio(0); cin.tie(0);
    cin >> t;
    while (t--)
        sol();
}

