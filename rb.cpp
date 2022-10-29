#include <iostream>
#include <vector>
#include <string>
using namespace std;
typedef long long ll;

struct vec3
{
    ll x;
    ll y;
    ll z;
    ll dist(vec3& o)
    {
        return (x - o.x) * (x - o.x) + (y - o.y) * (y - o.y) + (z - o.z) * (z - o.z);
    };
};

vector<vec3> v = {
vec3{ 255, 255, 255 }, vec3{ 192, 192, 192 }, vec3{ 128, 128, 128 }, vec3{ 0, 0 , 0},
vec3{ 255, 0, 0 }, vec3{ 128, 0, 0 }, vec3{ 255, 255, 0 }, vec3{128, 128, 0 }, vec3{0, 255, 0},
vec3{0, 128, 0}, vec3{ 0, 255, 255 }, vec3{0, 128, 128 }, vec3{0, 0, 255 },
vec3{0, 0, 128 }, vec3{255, 0, 255 }, vec3{ 128, 0, 128 }};
vector<string> na = {"White", "Silver", "Gray", "Black", "Red", "Maroon",
"Yellow", "Olive", "Lime", "Green", "Aqua", "Teal", "Blue", "Navy", "Fuchsia", "Purple" };

int main()
{
    ll x, y, z;
    cin >> x >> y >> z;
    // cout << x << ' ' << y << ' ' << z << endl;
    while (x != -1)
    {
        string ans;
        vec3 color;
        color.x = x; color.y = y; color.z = z;
        ll d = v[0].dist(color);
        for (int i = v.size() - 1; i >= 0; i--)
            if (v[i].dist(color) <= d)
            {
                d = v[i].dist(color);
                ans = na[i];
            }
        cout << ans << endl;
        cin >> x >> y >> z;
    }
}
