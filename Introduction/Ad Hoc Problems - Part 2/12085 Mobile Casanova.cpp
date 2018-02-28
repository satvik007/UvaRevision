#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef vector <int> vi;

int n;
vector <string> a;

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    freopen("in.txt", "r", stdin);
    freopen("out.txt", "w", stdout);
    int cas = 1;
    while(cin >> n, n){
        cout << "Case " << cas++ << ":\n";
        a.resize(n);
        for(int i=0; i<n; i++) cin >> a[i];
        string last = a[0];
        int cnt = 0;
        string past, future;
        for(int i=1; i<n; i++){
            if(stoll(a[i]) != stoll(a[i-1]) + 1) {
                past = last;
                future = a[i-1];
                if(past != future){
                    int k = -1;
                    for(int j=0; j<past.size(); j++){
                        if(past[j] != future[j] && k == -1) k = j;
                        cout << past[j];
                    }
                    cout << "-";
                    for(int j=k; j<future.size(); j++) cout << future[j];
                    cout << "\n";
                }else{
                    cout << past << "\n";
                }
                last = a[i];
            }
        }
        {
            past = last;
            future = a[n-1];
            if(past != future){
                int k = -1;
                for(int j=0; j<past.size(); j++){
                    if(past[j] != future[j] && k == -1) k = j;
                    cout << past[j];
                }
                cout << "-";
                for(int j=k; j<future.size(); j++) cout << future[j];
                cout << "\n";
            }else{
                cout << past << "\n";
            }
        }
        cout << "\n";
    }
    return 0;
}