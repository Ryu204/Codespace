#include <iostream>
using namespace std;
typedef long long ll;

constexpr ll N = 2e5 + 10;
ll t, n, a[N];

bool sol()
{
    cin >> n;
    int o = 0, e = 0;
    for (int i = 1; i <= n; i++)
    {
        cin >> a[i];
        if (a[i] % 2 == 0)
            e++;
        else
            o++;
    }
    if (e % 2 == 0)
    {
        if (o % 4 == 0 || o % 4 == 3)
            return true;
        else
            return false;
    }
    else
    {
        if (o % 4 == 2)
            return false;
        else
            return true;
    }
}

int main()
{
    ios::sync_with_stdio(0); cin.tie(0);
    cin >> t;
    while (t --)
        if (sol())
            cout << "Alice\n";
        else
            cout << "Bob\n";
}

