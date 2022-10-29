#include <iostream>
using namespace std;
typedef long long ll;

ll t, n, k, m, a[1000010], ST[4*1000010];

// Truy vấn: A(i) ++
// Hàm cập nhật trên cây ST, cập nhật cây con gốc id quản lý đọan [l, r]
void update(int id, int l, int r, int i) {
    if (i < l || r < i) {
        // i nằm ngoài đoạn [l, r], ta bỏ qua nút i
        return ;
    }
    if (l == r) {
        // Đoạn chỉ gồm 1 phần tử, không có nút con
        ST[id]++;
        return ;
    }

    // Gọi đệ quy để xử lý các nút con của nút id
    int mid = (l + r) / 2;
    update(id*2, l, mid, i);
    update(id*2 + 1, mid+1, r, i);

    // Cập nhật lại giá trị max của đoạn [l, r] theo 2 nút con:
    ST[id] = ST[id*2] + ST[id*2 + 1];
}

// Truy vấn: tìm max đoạn [u, v]
// Hàm tìm max các phần tử trên cây ST nằm trong cây con gốc id - quản lý đoạn [l, r]
int get(int id, int l, int r, int u, int v) {
    if (v < l || r < u) {
        // Đoạn [u, v] không giao với đoạn [l, r], ta bỏ qua đoạn này
        return 0;
    }
    if (u <= l && r <= v) {
        // Đoạn [l, r] nằm hoàn toàn trong đoạn [u, v] mà ta đang truy vấn, ta trả lại
        // thông tin lưu ở nút id
        return ST[id];
    }
    int mid = (l + r) / 2;
    // Gọi đệ quy với các con của nút id
    return get(id*2, l, mid, u, v) + get(id*2 + 1, mid+1, r, u, v);
}

bool sol()
{
    cin >> n >> m >> k;
    for (int i = 1; i <= 4 * k; i++)
        ST[i] = 0;
    for (int i = 1; i <= k; i++)
        cin >> a[i];
    ll x = m * n - 4;
    for (int i = 1; i <= k; i++)
    {
        // h = a[i]? so we need cnt[h + 1] + cnt[h + 2] + ... + c[n]
        ll sum;
        if (a[i] == 1)
            sum = 0;
        else
            sum = get(1, 1, k, 1, a[i] - 1);
        if (sum > x)
        {
            // cout << "fail at " << a[i] << '\n';
            return false;
        }
        update(1, 1, k, a[i]);
    }
    return true;
}

int main()
{
    cin >> t;
    while (t--)
    {
        if (sol())
            cout << "YA\n";
        else
            cout << "TIDAK\n";
    }
}
