#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef vector <int> vi;

/*
 * The first line of input consists of four integers: 1 ≤ N ≤ 200,
 * the number of participants, 1 ≤ B ≤
500000, the budget, 1 ≤ H ≤ 18, the number of hotels to consider,
 and 1 ≤ W ≤ 13, the number
of weeks you can choose between. Then follow two lines for each of
 the H hotels. The first gives
1 ≤ p ≤ 10000, the price for one person staying the weekend at the
 hotel. The second contains W
integers, 0 ≤ a ≤ 1000, giving the number of available beds for each
 weekend at the hotel.
 */

int n, budget, hotels, weeks;

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    freopen("in.txt", "r", stdin);
    freopen("out.txt", "w", stdout);
    while(cin >> n >> budget >> hotels >> weeks){
        int price, beds;
        bool flag;
        int ans = INT_MAX;
        for(int i=0; i<hotels; i++){
            cin >> price;
            flag = false;
            for(int j=0; j<weeks; j++){
                cin >> beds;
                if(beds >= n)
                    flag = true;
            }
            if(flag){
                ans = min(ans, price*n);
            }
        }
        if(ans <= budget) cout << ans << "\n";
        else cout << "stay home\n";
    }
    return 0;
}
