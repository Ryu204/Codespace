#include <iostream>
#include
using namespace std;
typedef long long ll;

constexpr ll N = 2e6;
bool check[N + 1];
int prime[100005], cnt = 0, l, h;
string p;

void sieve() {
    for(int i = 2; i < N; ++ i) if(!check[i]) {
        prime[++ cnt] = i;
        for(int j = i; j < N; j += i) check[j] = 1;
    }
}

void sol()
{
    cin >> l >> h >> p;
    if(l > h) swap(l, h);
    int len = p.size(), res = 0;
    for(int i = l; i <= h; ++ i) {
        string cur = "";
        int x = prime[i];
        while(x) {
            cur = cur + char(x % 10 + '0');
            x /= 10;
        }
        reverse(cur.begin(), cur.end());
        for(int j = 0; j + len - 1 < cur.size(); ++ j) {
            if(cur.substring(j, len) == p) {
                res ++;
                break;
            }
        }
    }
    cout << res << "\n";
}

int main()
{
    sieve();
    sol();
}
