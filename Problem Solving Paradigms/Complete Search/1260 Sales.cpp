#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef vector <int> vi;
typedef pair <int, int> ii;

#define maxn 1010

int tc, n;
int a[maxn];

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    freopen("in.txt", "r", stdin);
    freopen("out.txt", "w", stdout);
    cin >> tc;
    while(tc--){
        cin >> n;
        for(int i=0; i<n; i++){
            cin >> a[i];
        }
        int cnt = 0;
        for(int i=1; i<n; i++){
            for(int j=0; j<i; j++){
                if(a[j] <= a[i]) cnt++;
            }
        }
        cout << cnt << "\n";
    }
    return 0;
}