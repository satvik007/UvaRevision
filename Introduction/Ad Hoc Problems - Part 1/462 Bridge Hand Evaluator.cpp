#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef vector <int> vi;

vector <string> a(13);
int b[4], c[4];
map <char, int> map1;

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    freopen("in.txt", "r", stdin);
    freopen("out.txt", "w", stdout);
    map1['S'] = 0; map1['H'] = 1; map1['D'] = 2; map1['C'] = 3;
    while(cin.peek() != EOF){
        for(int i=0; i<13; i++) cin >> a[i];
        cin.ignore();
        int points = 0;
        memset(b, 0, sizeof b);
        memset(c, 0, sizeof c);
        for(int i=0; i<13; i++){
            if(a[i][1] == 'S') b[0]++;
            else if(a[i][1] == 'H') b[1]++;
            else if(a[i][1] == 'D') b[2]++;
            else if(a[i][1] == 'C') b[3]++;
        }
        for(int i=0; i<13; i++){
            if(a[i][0] == 'A') points += 4, c[map1[a[i][1]]] = 1;
            else if(a[i][0] == 'K'){
                points += 3;
                if(b[map1[a[i][1]]] == 1) points--;
                else c[map1[a[i][1]]] = 1;
            }
            else if(a[i][0] == 'Q'){
                points += 2;
                if(b[map1[a[i][1]]] <= 2) points--;
                else c[map1[a[i][1]]] = 1;
            }
            else if(a[i][0] == 'J'){
                points += 1;
                if(b[map1[a[i][1]]] <= 3) points--;
            }
        }
        if(points >= 16 && c[0] && c[1] && c[2] && c[3]){
            cout << "BID NO-TRUMP\n";
            continue;
        }
        for(int i=0; i<4; i++){
            if(b[i] == 2) points++;
            else if(b[i] <= 1) points+=2;
        }
        if(points < 14) {
            cout << "PASS\n";
        }else{
            int index = max_element(b, b+4) - b;
            switch(index){
                case 0: cout << "BID S\n"; break;
                case 1: cout << "BID H\n"; break;
                case 2: cout << "BID D\n"; break;
                case 3: cout << "BID C\n"; break;
                default: cout << "It should never reach here.\n"; break;
            }
        }
    }
    return 0;
}