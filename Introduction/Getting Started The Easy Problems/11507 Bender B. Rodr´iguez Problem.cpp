#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef vector <int> vi;

int n;
string a[100010];
map <pair<string, string>, string> map1;

void init(){
    map1[{"+x", "+y"}] = "+y";
    map1[{"+x", "+z"}] = "+z";
    map1[{"+x", "-y"}] = "-y";
    map1[{"+x", "-z"}] = "-z";
    map1[{"-x", "+y"}] = "-y";
    map1[{"-x", "+z"}] = "-z";
    map1[{"-x", "-y"}] = "+y";
    map1[{"-x", "-z"}] = "+z";

    map1[{"+y", "+y"}] = "-x";
    map1[{"+y", "+z"}] = "+y";
    map1[{"+y", "-y"}] = "+x";
    map1[{"+y", "-z"}] = "+y";
    map1[{"-y", "+y"}] = "+x";
    map1[{"-y", "+z"}] = "-y";
    map1[{"-y", "-y"}] = "-x";
    map1[{"-y", "-z"}] = "-y";

    map1[{"+z", "+y"}] = "+z";
    map1[{"+z", "+z"}] = "-x";
    map1[{"+z", "-y"}] = "+z";
    map1[{"+z", "-z"}] = "+x";
    map1[{"-z", "+y"}] = "-z";
    map1[{"-z", "+z"}] = "+x";
    map1[{"-z", "-y"}] = "-z";
    map1[{"-z", "-z"}] = "-x";
}
int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    freopen("in.txt", "r", stdin);
    freopen("out.txt", "w", stdout);
    init();
    while(cin >> n, n){
        for(int i=0; i<n-1; i++) cin >> a[i];
        string current = "+x";
        for(int i=0; i<n-1; i++){
            if(a[i] == "No");
            else current = map1[{current, a[i]}];
        }
        cout << current << "\n";
    }
    return 0;
}
