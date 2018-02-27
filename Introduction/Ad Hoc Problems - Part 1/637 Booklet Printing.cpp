#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef vector <int> vi;

int n;
int a[4][1000];

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    freopen("in.txt", "r", stdin);
    freopen("out.txt", "w", stdout);
    while(cin >> n, n){
        cout << "Printing order for " << n << " pages:\n";
        int k = (n+3) / 4;
        for(int i=0; i<k; i++){
            a[1][i] = i*2 + 1;
            a[2][i] = (i*2 + 2 <= n ? (i*2+2) : -1);
            a[3][k-i-1] = (k*2 + i*2 + 1 <= n) ? (k*2 + i*2 + 1) : -1;
            a[0][k-i-1] = (k*2 + i*2 + 2 <= n) ? (k*2 + i*2 + 2) : -1;
        }
        for(int i=0; i<k; i++){
            cout << "Sheet " << (i+1) << ", front: ";
            if(a[0][i] == -1) cout << "Blank";
            else cout << a[0][i];
            cout << ", " << a[1][i] << "\n";
            if(a[2][i] == -1 && a[3][i] == -1) continue;
            cout << "Sheet " << (i+1) << ", back : ";
            if(a[2][i] == -1) cout << "Blank";
            else cout << a[2][i];
            cout << ", ";
            if(a[3][i] == -1) cout << "Blank";
            else cout << a[3][i];
            cout << "\n";
        }
    }
    return 0;
}