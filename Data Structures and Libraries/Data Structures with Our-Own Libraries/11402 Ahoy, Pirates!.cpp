#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef vector <int> vi;
#define maxn 1024010

int tc, n, m, q;
int a[maxn], lazy[4 * maxn], tree[4 * maxn];
map <char, int> map1;

class SegmentTree{
public:
    SegmentTree(){
        memset(lazy, 0, sizeof lazy);
        build(1, 0, n-1);
    }
    int build(int p, int l, int r){
        if(l == r) return tree[p] = a[l];
        return tree[p] = build(left(p), l, (l+r)/2) + build(right(p), (l+r)/2+1, r);
    }
    void modify(int p, int l, int r, int i, int j, int val){
        slide(p, l, r);
        if(l > j || r < i) return;
        if(l >= i && r <= j) {
            lazy[p] = val;
            slide(p, l, r);
            return;
        }
        modify(left(p), l, (l+r)/2, i, j, val);
        modify(right(p), (l+r)/2+1, r, i, j, val);
        tree[p] = tree[left(p)] + tree[right(p)];
    }
    int query(int p, int l, int r, int i, int j){
        slide(p, l, r);
        if(l > j || r < i) return 0;
        if(l >= i && r <= j) return tree[p];
        int q1 = query(left(p), l, (l+r)/2, i, j);
        int q2 = query(right(p), (l+r)/2+1, r, i, j);
        tree[p] = tree[left(p)] + tree[right(p)];
        return q1 + q2;
    }
    void transfer(int p, int l, int r, int val){
        if(val == 1 || val == 2) lazy[p] = val;
        else if(val == 3) lazy[p] = 3 - lazy[p];
    }
    void slide(int p, int l, int r){
        if(l != r){
            transfer(left(p), l, (l+r)/2, lazy[p]);
            transfer(right(p), (l+r)/2+1, r, lazy[p]);
        }
        switch(lazy[p]){
            case 0: break;
            case 1: tree[p] = r - l + 1; break;
            case 2: tree[p] = 0; break;
            case 3: tree[p] = (r - l + 1) - tree[p]; break;
            default: cerr << "You know what. I am a fool. Not a humble one though!\n";
        }
        lazy[p] = 0;
    }
    int left(int p){return (p<<1);}
    int right(int p){return (p<<1|1);}
};
int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    freopen("in.txt", "r", stdin);
    freopen("out.txt", "w", stdout);
    cin >> tc;
    map1['F'] = 1; map1['E'] = 2; map1['I'] = 3;
    map1['S'] = 4;
    int cas = 1;
    while(tc--){
        cout << "Case " << cas++ << ":\n";
        cin >> m;
        string pirates;
        int t; string temp;
        while(m--){
            cin >> t >> temp;
            while(t--){
                pirates += temp;
            }
        }
        n = pirates.size();
        for(int i=0; i<n; i++){
            a[i] = pirates[i] - '0';
        }
        SegmentTree current;
        cin >> q;
        char cur;
        int u, v;
        int qu = 1;
        while(q--){
            cin >> cur >> u >> v;
            if(cur == 'S'){
                cout << "Q" << qu++ << ": " << current.query(1, 0, n-1, u, v) << "\n";
            }else{
                current.modify(1, 0, n-1, u, v, map1[cur]);
            }
        }
    }
    return 0;
}