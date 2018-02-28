#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef vector <int> vi;

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    freopen("in.txt", "r", stdin);
    freopen("out.txt", "w", stdout);
    tm curr;
    mktime(&curr);
    int n, d, m, y;
    while(cin >> n >> d >> m >> y, n||d||m||y){
        curr.tm_mday = d+n;
        curr.tm_mon = m-1;
        curr.tm_year = y-1900;
        mktime(&curr);
        cout << (curr.tm_mday) << " " << (curr.tm_mon+1) << " " << (curr.tm_year+1900) << endl;
    }
    return 0;
}