#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef vector <int> vi;
typedef pair <int, int> ii;
#define maxn 20010

int n;
ii a[maxn];

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    freopen("in.txt", "r", stdin);
    freopen("out.txt", "w", stdout);
    while(cin >> n){
        int k = 0;
        for(int i=n+1; i<=2*n; i++){
            if(n*i % (i - n) == 0){
                a[k++] = {n*i/(i-n), i};
            }
        }
        cout << k << "\n";
        for(int i=0; i<k; i++){
            cout << "1/" << n << " = 1/" << a[i].first << " + 1/" << a[i].second << "\n";
        }
    };
    return 0;
}
