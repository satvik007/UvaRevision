#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef vector <int> vi;

double h, u, d, f;

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    freopen("in.txt", "r", stdin);
    freopen("out.txt", "w", stdout);
    while(cin >> h, h){
        cin >> u >> d >> f;
        double dec = f/100*u;
        int days = 0;
        double current = 0;
        bool flag = false;
        while(current >= 0){
            days++;
            if(u > 0) current += u;
            u -= dec;
            if(current > h){
                flag = true;
                break;
            }
            current -= d;
            if(current < 0) {
                break;
            }
        }
        if(flag) cout << "success on day " << days << "\n";
        else cout << "failure on day " << days << "\n";
    }
    return 0;
}
