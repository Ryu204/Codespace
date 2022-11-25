#include <iostream>
#include <algorithm>
#include <set>
#include <vector>
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
        for (int i = 0; i < n; i++)
            cin >> a[i];
        set<int> s;
        vector<int> v;
        for (int i = 0; true; i = (i + 2) % n)
        {
            if (s.count(i))
                break;
            else
            {
                s.insert(i);
                v.push_back(i);
            }
        }
        int k = v.size();
        int mx = v[k - 1];
        for (int i = k - 1; i >= 0; i--)
            if (a[v[i]] <= a[mx])
                mx = v[i];
        cout << mx << '\n';
    }
}


