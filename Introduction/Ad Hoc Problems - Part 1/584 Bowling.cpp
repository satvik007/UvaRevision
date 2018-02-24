#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef vector <int> vi;

string a;

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    freopen("in.txt", "r", stdin);
    freopen("out.txt", "w", stdout);
    while(cin.peek() != EOF){
        getline(cin, a);
        if(a == "Game Over") break;
        int points = 0;
        for(int i=0, k=0; k<10; k++){
            if(a[i] == 'X'){
                points += 10;
                if(a[i+2] == 'X') points += 10;
                else points += a[i+2] - '0';
                if(a[i+4] == 'X') points += 10;
                else if(a[i+4] == '/') points += (10 - (a[i+2] -'0'));
                else points += a[i+4] - '0';
                i += 2;
            }else{
                if(a[i+2] == '/'){
                    points += 10;
                    if(a[i+4] == 'X') points += 10;
                    else points += (a[i+4] - '0');
                }else{
                    points += (a[i] - '0' + a[i+2] - '0');
                }
                i += 4;
            }
        }
        cout << points << "\n";
    }
    return 0;
}