#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef vector <ll> vi;

vi a;
void insertion_sort(){
    for(int i=1; i<a.size(); i++){
        int key = a[i];
        int j = i - 1;
        for(; j>=0 && a[j]>key; j--){
            a[j+1] = a[j];
        }
        a[j+1] = key;
    }
}

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    freopen("in.txt", "r", stdin);
    freopen("out.txt", "w", stdout);
    ll n;
    while(cin >> n){
        a.push_back(n);
        insertion_sort();
        if(a.size() % 2){
            cout << a[a.size()/2] << "\n";
        }else{
            cout << (a[a.size()/2-1]  + a[a.size()/2])/2 << "\n";
        }
    }
    return 0;
}
