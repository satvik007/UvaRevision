#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef vector <int> vi;
typedef pair <int, int> ii;

int n;
int a[20];

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    freopen("in.txt", "r", stdin);
    freopen("out.txt", "w", stdout);
    int cas = 1;
    while(cin >> n, n){
        if(cas != 1) cout << "\n"; cas++;
        for(int i=0; i<n; i++) cin >> a[i];
        sort(a, a+n);
        for(int i=0; i<n-5; i++){
            for(int j=i+1; j<n-4; j++){
                for(int k=j+1; k<n-3; k++){
                    for(int m=k+1; m<n-2; m++){
                        for(int l=m+1; l<n-1; l++){
                            for(int p=l+1; p<n; p++){
                                cout << a[i] << " " << a[j] << " " << a[k] << " " << a[m]
                                 << " " << a[l] << " " << a[p] << "\n";
                            }
                        }
                    }
                }
            }
        }
    }
    return 0;
}