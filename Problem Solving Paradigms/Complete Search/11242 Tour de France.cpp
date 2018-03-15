#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef vector <int> vi;
typedef pair <int, int> ii;

int a[110], b[110];
double c[10010];
int n, m;

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    freopen("in.txt", "r", stdin);
    freopen("out.txt", "w", stdout);
    cout << fixed << setprecision(2);
    while(cin >> n >> m){
        for(int i=0; i<n; i++) cin >> a[i];
        for(int i=0; i<m; i++) cin >> b[i];
        int k = 0;
        for(int i=0; i<n; i++){
            for(int j=0; j<m; j++){
                c[k++] = a[i]*1.0/b[j];
            }
        }
        sort(c, c+k);
        double max1 = 1;
        for(int i=0; i<k-1; i++) {
            max1 = max(max1, c[i+1]/c[i]);
        }
        cout << max1 << "\n";
    }
    return 0;
}