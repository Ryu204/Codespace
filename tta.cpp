#include <iostream>
using namespace std;
int n, a[500010], o;
int main()
{
    int t;
    cin >> t;
    while (t--)
    {
        o = 0;
        bool con = false;
        cin >> n;
        int s = 0;
        for (int i = 1; i <= n; i++)
        {
            cin >> a[i];
            s += a[i];
            o += (a[i] == -1);
            if (a[i] == -1 && a[i - 1] == -1)
                con = true;
        }
        if (con)
            cout << s + 4 << '\n';
        else if (o > 0)
            cout << s << '\n';
        else
            cout << n - 4 << '\n';
    }
}
