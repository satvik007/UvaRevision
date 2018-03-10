#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef vector <int> vi;

#define maxn 200010

int n;
map <string, int> map1;

class UnionFind{
public:
    vi p, rank, counter;
    UnionFind(){
        p.resize(maxn);
        for(int i=0; i<maxn; i++) p[i] = i;
        rank.assign(maxn, 1);
        counter.assign(maxn, 1);
    }
    int findSet(int i){
        while(i != p[i]) p[i] = p[p[i]], i = p[i];
        return i;
    }
    bool isSameSet(int i, int j) {
        return findSet(i) == findSet(j);
    }
    int unionSet(int i, int j){
        i = findSet(i), j = findSet(j);
        if(i != j){
            if(rank[i] < rank[j]) {
                p[i] = j; counter[j] += counter[i];
            }else{
                p[j] = i; counter[i] += counter[j];
                if(rank[i] == rank[j]) rank[i]++;
            }
        }
        return counter[findSet(i)];
    }
};

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    freopen("in.txt", "r", stdin);
    freopen("out.txt", "w", stdout);
    int tc; cin >> tc;
    string u, v;
    while(tc--){
        int k = 0; map1.clear();
        cin >> n;
        UnionFind satvik;
        for(int i=0; i<n; i++){
            cin >> u >> v;
            if(!map1.count(u)) map1[u] = k++;
            if(!map1.count(v)) map1[v] = k++;
            cout << satvik.unionSet(map1[u], map1[v]) << "\n";
        }
    }
    return 0;
}