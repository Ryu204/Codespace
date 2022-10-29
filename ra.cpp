#include <iostream>
#include <vector>
using namespace std;
typedef long long ll;
ll n, cw, mw, drawt, draw;
ll p[100];
int main()
{
    cin >> n;
    vector<ll> v;
    ll pr = 1;
    while (pr <= n)
    {
        v.push_back((n / pr + 1) / 2);
        pr *= 2;
    }
//    for (auto& i : v)
//        cout << i << ' ';
//    cout << '\n';
    for (int i = 0; i < v.size(); i += 2)
        mw += v[i] * v[i];
    p[v.size() - 1] = v.back();
    for (int i = v.size() - 2; i >= 0; i--)
        p[i] = p[i + 1] + v[i];
    for (int i = 1; i < v.size(); i += 2)
        cw += 2 * v[i] * p[i + 1] + v[i] * v[i];
    draw = n * n - cw - mw;
    for (int i = 0; i < v.size(); i += 2)
        drawt += 2 * v[i] * p[i + 1];
    cout << cw << endl << draw << endl << mw ;//<< endl << drawt;
}

