#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef vector <int> vi;

int n, m;
vi a;

class SegmentTree{
public:
    vi tree;
    SegmentTree(){
        tree.resize(4*n);
        build(1, 0, n-1);
    }
    int build(int p, int l, int r){
        if(l == r) return tree[p] = a[l];
        return tree[p] = (build(left(p), l, (l+r)/2) * build(right(p), (l+r)/2+1, r));
    }
    int query(int p, int l, int r, int i, int j){
        if(l > j || r < i) return 1;
        if(l >= i && r <= j) return tree[p];
        return query(left(p), l, (l+r)/2, i, j) * query(right(p), (l+r)/2+1, r, i, j);
    }
    int update(int p, int l, int r, int u, int v){
        if(l == r && l == u) return tree[p] = v;
        if(r < u || l > u) return tree[p];
        return tree[p] = update(left(p), l, (l+r)/2, u, v) * update(right(p), (l+r)/2+1, r, u, v);
    }
    int left(int p){return (p << 1);}
    int right(int p){return (p<<1|1);}
};

int sign(int p){
    if(p == 0) return 0;
    return p / abs(p);
}

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    freopen("in.txt", "r", stdin);
    freopen("out.txt", "w", stdout);
    int u, v;
    while(cin >> n >> m){
        a.resize(n);
        for(int i=0; i<n; i++){
            cin >> u;
            a[i] = sign(u);
        }
        SegmentTree satvik;
        char cur;
        string final;
        while(m--){
            cin >> cur >> u >> v;
            if(cur == 'C'){
                v = sign(v);
                a[u-1] = v;
                satvik.update(1, 0, n-1, u-1, sign(v));
            }else{
                int ans = satvik.query(1, 0, n-1, u-1, v-1);
                if(ans > 0) final += '+';
                else if(ans < 0) final += '-';
                else final += '0';
            }
        }
        cout << final << "\n";
    }
    return 0;
}