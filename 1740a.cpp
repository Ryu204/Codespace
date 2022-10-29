#include <iostream>
using namespace std;
typedef long long ll;

ll t, n;

int main()
{
    cin >> t;
    while (t--)
    {
        cin >> n;
        if (n % 2)
            cout << "3\n";
        else
            cout << "2\n";
    }
}
