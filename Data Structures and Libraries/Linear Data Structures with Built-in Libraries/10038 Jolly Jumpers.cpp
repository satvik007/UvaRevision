#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef vector <int> vi;

vi a;
int n;

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    freopen("in.txt", "r", stdin);
    freopen("out.txt", "w", stdout);
    while(cin >> n){
        int last, u; a.clear();
        for(int i=0; i<n; i++){
            cin >> u;
            if(i){
                a.push_back(abs(u - last));
            }
            last = u;
        }
        sort(a.begin(), a.end());
        bool flag = true;
        for(int i=0; i<n-1; i++) {
            if (a[i] != i + 1) flag = false;
        }
        if(flag) cout << "Jolly\n";
        else cout << "Not jolly\n";
    }
    return 0;
}