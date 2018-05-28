#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef vector <int> vi;

map <char, int> map1;

void init(){
    for(int i=2; i<=9; i++){
        map1['0'+i] = i;
        map1['T'] = map1['J'] = map1['Q'] = map1['K'] = map1['A'] = 10;
    }
}
vector <string> a(52);

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    freopen("in.txt", "r", stdin);
    freopen("out.txt", "w", stdout);
    init();
    int tc; cin >> tc;
    int cas = 1;
    while(tc--){
        cout << "Case " << cas++ << ": ";
        for(int i=0; i<52; i++) cin >> a[i];
        int current = 51;
        current -= 25;
        int x, y = 0;
        for(int k=0; k<3; k++){
            x = map1[a[current][0]];
            y += x;
            current -= (10 - x + 1);
        }
        if(y <= current) cout << a[y] << "\n";
        else cout << a[51-25+y - current - 1] << "\n";
    }
    return 0;
}
