#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef vector <int> vi;

struct Data{
    string name;
    int u, v;
};
Data a[10010];
int n, q;

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    freopen("in.txt", "r", stdin);
    freopen("out.txt", "w", stdout);
    int tc; cin >> tc;
    while(tc--){
        cin >> n;
        for(int i=0; i<n; i++){
            cin >> a[i].name >> a[i].u >> a[i].v;
        }
        cin >> q;
        int w;
        string nam;
        while(q--){
            int cnt = 0;cin >> w;
            for(int i=0; i<n; i++){
                if(a[i].u <= w && a[i].v >= w) cnt++, nam = a[i].name;
            }
            if(cnt == 1) cout << nam << "\n";
            else cout << "UNDETERMINED\n";
        }
        if(tc) cout << "\n";
    }
    return 0;
}
