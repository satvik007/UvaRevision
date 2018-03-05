#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef vector <int> vi;
typedef pair <int, int> ii;

priority_queue <ii, vector <ii>, greater <ii>> pq;
map <int, int> map1;
int n;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    freopen("in.txt", "r", stdin);
    freopen("out.txt", "w", stdout);
    int u, v;
    string a;
    while(getline(cin, a), a != "#"){
        stringstream sin(a);
        sin >> a >> u >> v;
        pq.push({v, u});
        map1[u] = v;
    }
    cin >> n;
    for(int i=0; i<n; i++){
        ii current = pq.top(); pq.pop();
        cout << current.second << "\n";
        current.first += map1[current.second];
        pq.push(current);
    }
    return 0;
}