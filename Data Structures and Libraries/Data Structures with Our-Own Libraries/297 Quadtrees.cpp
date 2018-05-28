#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef vector <int> vi;

#define maxn 50010

string x, y;

int a[40][40];
int b[40][40];
int n = 32;

class SegmentTree {
public:
    int index;
    SegmentTree () {
        index = 0;
        solve1(0, n - 1, 0, n - 1);
        index = 0;
        solve2(0, n - 1, 0, n - 1);
    };
    void solve1(int u, int d, int l, int r) {
        if(x[index] == 'p') {
            index++;
            solve1(u, (u + d) / 2, (l + r) / 2 + 1, r);
            solve1(u, (u + d) / 2, l, (l + r) / 2);
            solve1((u + d) / 2 + 1, d, l, (l + r) / 2);
            solve1((u + d) / 2 + 1, d, (l + r) / 2 + 1, r);
        } else if(x[index] == 'e') {
            index++;
            fill1(u, d, l, r, 0);
        } else if(x[index] == 'f') {
            index++;
            fill1(u, d, l, r, 1);
        }
    }
    void solve2(int u, int d, int l, int r) {
        if(y[index] == 'p') {
            index++;
            solve2(u, (u + d) / 2, (l + r) / 2 + 1, r);
            solve2(u, (u + d) / 2, l, (l + r) / 2);
            solve2((u + d) / 2 + 1, d, l, (l + r) / 2);
            solve2((u + d) / 2 + 1, d, (l + r) / 2 + 1, r);
        } else if(y[index] == 'e') {
            index++;
            fill2(u, d, l, r, 0);
        } else if(y[index] == 'f') {
            index++;
            fill2(u, d, l, r, 1);
        }
    }
    void fill1(int u, int d, int l, int r, int type) {
        for(int i = u; i <= d; i++) {
            for(int j = l; j <= r; j++) {
                a[i][j] = type;
            }
        }
    }
    void fill2(int u, int d, int l, int r, int type) {
        for(int i = u; i <= d; i++) {
            for(int j = l; j <= r; j++) {
                b[i][j] = type;
            }
        }
    }
    int left(int p) {
        return (p << 1);
    }
    int right(int p) {
        return (p << 1 | 1);
    }
};


int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    freopen("in.txt", "r", stdin);
    freopen("out.txt", "w", stdout);

    int n;
    cin >> n;


    while(n--) {
        cin >> x >> y;
        SegmentTree cur;
        int cnt = 0;
        for(int i = 0; i < 32; i++) {
            for(int j = 0; j < 32; j++) {
                if((a[i][j] | b[i][j]) == 1) cnt++;
            }
        }
        cout << "There are " << cnt << " black pixels.\n";
    }


    return 0;
}