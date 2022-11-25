#include <iostream>
#include <algorithm>
using namespace std;

int t, n, a[100010];

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    cin >> t;
    while (t--)
    {
        cin >> n;
        int s = 0;
        for (int i = 1; i <= n; i++)
        {
            cin >> a[i];
            s += a[i];
        }
        sort(a + 1, a + n + 1);
        bool cant = false;
        for (int i = n; i >= 0; i--)
        {
            if (i < 3)
                cant = true;
            if (a[i] * 2 < s)
                break;
            else
                s -= a[i];
        }
        if (cant)
            cout << "0\n";
        else
            cout << s << '\n';
    }
}

