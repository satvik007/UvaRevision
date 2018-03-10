#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef vector <int> vi;

int tc, n;

class UnionFind{
public:
    vi p, rank;
    UnionFind(int n){
        p.resize(n);
        rank.assign(n, 0);
        for(int i=0; i<n; i++) p[i] = i;
    }
    int findSet(int i){
        while(i != p[i]) p[i] = p[p[i]], i = p[i];
        return i;
    }
    bool isSameSet(int i, int j){
        return findSet(i) == findSet(j);
    }
    void unionSet(int i, int j){
        i = findSet(i), j = findSet(j);
        if(i != j){
            if(rank[i] < rank[j]) p[i] = j;
            else{
                p[j] = i;
                if(rank[i] == rank[j]) rank[i]++;
            }
        }
    }
};

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    freopen("in.txt", "r", stdin);
    freopen("out.txt", "w", stdout);
    cin >> tc;
    while(tc--){
        cin >> n; cin.ignore();
        string s;
        int cnt1 = 0, cnt2 = 0;
        char cur;
        int u, v;
        UnionFind satvik(n+1);
        while(cin.peek() != EOF && cin.peek() != '\n'){
            getline(cin, s);
            stringstream sin(s);
            sin >> cur >> u >> v;
            if(cur == 'c'){
                satvik.unionSet(u, v);
            }else{
                if(satvik.isSameSet(u, v)) cnt1++;
                else cnt2++;
            }
        }
        cout << cnt1 << "," << cnt2 << "\n";
        if(tc) cout << "\n";
    }
    return 0;
}