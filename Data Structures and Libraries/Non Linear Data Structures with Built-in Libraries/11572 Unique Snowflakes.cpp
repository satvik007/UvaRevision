#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef vector <int> vi;

map <int, int> map1;
int n;
vi a;

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    freopen("in.txt", "r", stdin);
    freopen("out.txt", "w", stdout);
    int tc; cin >> tc;
    while(tc--){
        cin >> n; a.resize(n);
        for(int i=0; i<n; i++) cin >> a[i];
        map1.clear();
        int last = 0, max1 = 0;
        for(int i=0; i<n; i++){
            if(map1.count(a[i])){
                if(map1[a[i]] < last) ;
                else last = map1[a[i]] + 1;
            }
            map1[a[i]] = i;
            max1 = max(max1, i - last + 1);
        }
        cout << max1 << "\n";
    }
    return 0;
}