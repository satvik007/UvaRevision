#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef vector <int> vi;

int months, k, mon[120];
double down, amount, a[120];

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    freopen("in.txt", "r", stdin);
    freopen("out.txt", "w", stdout);
    while(cin >> months, months > 0){
        cin >> down >> amount >> k;
        for(int i=0; i<k; i++) {
            cin >> mon[i] >> a[i];
        }
        double monthly = amount / months;
        double carval = down + amount;
        int days = 0, l = 0;
        double deprec = a[0]/100.0;
        while(carval <= amount || days == 0){
            if(l < k && mon[l] == days){
                deprec = a[l];
                l++;
            }
            carval -= deprec * carval;
            if(days) amount -= monthly;
            days++;
        }
        cout << days - 1 << (days - 1 == 1 ? " month\n" :  " months\n");
    }
    return 0;
}
