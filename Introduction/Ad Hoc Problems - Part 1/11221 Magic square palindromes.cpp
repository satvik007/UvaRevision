#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef vector <int> vi;

string a, b;
string p, q, r, s;
char x[100][100];

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    freopen("in.txt", "r", stdin);
    freopen("out.txt", "w", stdout);
    int tc; cin >> tc; cin.ignore();
    int cas = 1;
    while(tc--){
        getline(cin, b); a.clear();
        for(int i=0; i<b.size(); i++){
            if(b[i] >= 'a' && b[i] <= 'z') a += b[i];
        }
        cout << "Case #" << cas++ << ":\n";
        int m = (int)sqrt(a.size());
        if(m*m == (int)a.size()){
            bool flag = true;
            int k = 0;
            for(int i=0; i<m; i++){
                for(int j=0; j<m; j++){
                    x[i][j] = a[k++];
                }
            }
            for(int i=0; i<m; i++){
                for(int j=0; j<m; j++){
                    if(x[i][j] != x[m-i-1][m-j-1] || x[i][j] != x[m-j-1][m-i-1] || x[i][j] != x[j][i]) flag = false;
                }
            }
            if(flag) cout << m << "\n";
            else cout << "No magic :(\n";
        }else{
            cout << "No magic :(\n";
        }
    }
    return 0;
}