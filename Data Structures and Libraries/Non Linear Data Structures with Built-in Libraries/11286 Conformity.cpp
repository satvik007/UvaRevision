#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef vector <int> vi;

vector <vi> a;
int n;

map <vi, int> map1;

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    freopen("in.txt", "r", stdin);
    freopen("out.txt", "w", stdout);
    while(cin >> n, n){
        a.resize(n);
        map1.clear();
        for(int i=0; i<n; i++){
            a[i].resize(5);
            for(int j=0; j<5; j++) cin >> a[i][j];
            sort(a[i].begin(), a[i].end());
            if(map1.count(a[i])) map1[a[i]]++;
            else map1[a[i]] = 1;
        }
        int max1 = -1;
        for(auto el:map1){
            max1 = max(max1, el.second);
        }
        int cnt = 0;
        for(auto el:map1){
            if(el.second == max1) cnt += el.second;
        }
        cout << cnt << "\n";
    }
    return 0;
}