#include <iostream>
#include <string>
using namespace std;

typedef long long ll;

ll t, n, x, y;
string a, b;

void solv()
{
    cin >> n >> x >> y;
    cin >> a >> b;
    ll d = 0, lst = -10, ye = false;
    for (int i = 0; i < n; i++)
    {
        if (a[i] != b[i])
        {
            d++;
            if (lst == i - 1)
                ye = true;
            lst = i;
        }
    }
    if (d % 2 != 0)
    {
        cout << "-1\n";
        return;
    }

    if (d >= 4)
        cout << (d/2) * y << '\n';
    else if (d == 0)
            cout << "0\n";
    else
        if (ye)
        {
            if (x <= 2 * y)
                cout << x << '\n';
            else
                cout << 2*y << '\n';
        }
        else
            cout << y << '\n';
}


int main()
{
    ios::sync_with_stdio(0); cin.tie(0);
    cin >> t;
    while (t --)
        solv();
}
