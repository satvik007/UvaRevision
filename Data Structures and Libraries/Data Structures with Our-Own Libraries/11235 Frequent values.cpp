#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef vector <int> vi;
#define maxn 100010

int n, q;
int a[maxn], pre[maxn], mid[maxn], post[maxn];

class SegmentTree{
public:
    vi tree;
    SegmentTree(){
        tree.resize(4*n);
        build(1, 0, n-1);
    }
    int build(int p, int l, int r){
        if(l == r) return tree[p] = mid[l];
        return tree[p] = max(build(left(p), l, (l+r)/2), build(right(p), (l+r)/2+1, r));
    }
    int query(int p, int l, int r, int i, int j){
        if(l > r) return 0;
        if(l > j || r < i) return 0;
        if(l >= i && r <= j) return tree[p];
        return max(query(left(p), l, (l+r)/2, i, j), query(right(p), (l+r)/2+1, r, i, j));
    }
    int left(int p){return (p<<1);}
    int right(int p){return (p<<1|1);}
};

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    freopen("in.txt", "r", stdin);
    freopen("out.txt", "w", stdout);
    while(cin >> n >> q){
        for(int i=0; i<n; i++) cin >> a[i];
        int cur = 0, cnt = 1;
        for(int i=0; i<n; i++){
            if(a[cur] != a[i]) cur = i, cnt = 1;
            else cnt++;
            pre[i] = cur;
            mid[i] = cnt;
        }
        SegmentTree satvik;
        int u, v;
        while(q--){
            cin >> u >> v; u--; v--;
            int ind = upper_bound(a, a+n, a[u]) - a;
            int v1 = min(v-u+1, ind-u);
            int v2 = satvik.query(1, 0, n-1, ind, v);
            cout << max(v1, v2) << "\n";
        }
    }
    return 0;
}