#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef vector <int> vi;
typedef pair <int, int> ii;

#define maxn 1010

int tc, n;
int a[maxn], b[maxn*maxn];

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    freopen("in.txt", "r", stdin);
    freopen("out.txt", "w", stdout);
    int cas = 1;
    while(cin >> n, n) {
        cout << "Case " << cas++ << ":\n";
        for(int i=0; i<n; i++) cin >> a[i];
        int k = 0, u, v;
        for(int i=0; i<n; i++){
            for(int j=i+1; j<n; j++) b[k++] = a[i] + a[j];
        }
        sort(b, b+k);
        int q; cin >> q;
        while(q--){
            cin >> u;
            cout << "Closest sum to "<< u << " is ";
            v = lower_bound(b, b+k, u) - b;
            if(v == k) cout << b[k-1] << ".\n";
            else if(v == 0) cout << b[0] << ".\n";
            else{
                if(abs(b[v] - u) <= abs(b[v-1] - u)){
                    cout << b[v] << ".\n";
                }else cout << b[v-1] << ".\n";
            }
        }
    }
    return 0;
}