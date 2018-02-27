#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef vector <int> vi;

vi a;
int n, u, v;

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    freopen("in.txt", "r", stdin);
    freopen("out.txt", "w", stdout);
    cout << setfill('0');
    while(true){
        a.clear();
        while(cin >> u, u != 0){
            a.push_back(u);
        }
        if(a.empty()) break;
        n = (int)a.size();
        sort(a.begin(), a.end());
        int k = a[0]+1;
        bool flag;
        int val;
        for(int i=k; i<= 5*60*60; i++){
            flag = true;
            for(int j=0; j<n; j++){
                val = i % (2*a[j]);
                if(val >= a[j]-5) flag = false;
            }
            if(flag){
                val = i; break;
            }
        }
        if(flag){
            cout << setw(2) << (val/3600) << ":" << setw(2) << ((val%3600) / 60) << ":" <<
                setw(2) << (val % 60) << "\n";
        }else{
            cout << "Signals fail to synchronise in 5 hours\n";
        }
    }
    return 0;
}