#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef vector <int> vi;

vi adjList[30];
map <char, int> map1;
int n, m, visited[30];

int dfs(int u){
    int ans = 1;
    for(auto v:adjList[u]){
        if(!visited[v]){
            visited[v] = 1;
            ans += dfs(v);
        }
    }
    return ans;
}

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    freopen("in.txt", "r", stdin);
    freopen("out.txt", "w", stdout);
    int tc; cin >> tc; cin.ignore();
    while(tc--){
        map1.clear();
        for(int i=0; i<30; i++) adjList[i].clear();
        string a; n = 0;
        char u, v, null;
        while(getline(cin, a), a[0] != '*'){
            stringstream sin(a);
            sin >> null >> u >> null >> v >> null;
            if(!map1.count(u)) map1[u] = n++;
            if(!map1.count(v)) map1[v] = n++;
            adjList[map1[u]].push_back(map1[v]);
            adjList[map1[v]].push_back(map1[u]);
        }
        getline(cin, a);
        stringstream sin(a);
        while(sin >> u){
            if(!map1.count(u)) map1[u] = n++;
            sin >> null;
        }
        int cnt1 = 0, cnt2 = 0;
        memset(visited, 0, sizeof visited);
        for(int i=0; i<n; i++){
            if(!visited[i]) {
                visited[i] = 1;
                if(dfs(i) == 1) cnt1++;
                else cnt2++;
            }
        }
        cout << "There are " << cnt2 << " tree(s) and " << cnt1 << " acorn(s).\n";

    }
    return 0;
}