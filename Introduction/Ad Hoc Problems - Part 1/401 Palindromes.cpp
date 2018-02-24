#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef vector <int> vi;

vi val(128);
string a;

void init(){
    fill(val.begin(), val.end(), -1);
    val['A'] = 'A';
    val['E'] = '3';
    val['H'] = 'H';
    val['I'] = 'I';
    val['J'] = 'L';
    val['L'] = 'J';
    val['M'] = 'M';
    val['O'] = 'O';
    val['S'] = '2';
    val['T'] = 'T';
    val['U'] = 'U';
    val['V'] = 'V';
    val['W'] = 'W';
    val['X'] = 'X';
    val['Y'] = 'Y';
    val['Z'] = '5';
    val['1'] = '1';
    val['2'] = 'S';
    val['3'] = 'E';
    val['5'] = 'Z';
    val['8'] = '8';
}

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    freopen("in.txt", "r", stdin);
    freopen("out.txt", "w", stdout);
    init();
    while(cin >> a){
        bool flag1 = true;
        bool flag2 = true;
        for(int i=0; i<(a.size()+1)/2; i++){
            if(a[i] != val[a[a.size()-1-i]]) flag2 = false;
            if(a[i] != a[a.size()-i-1]) flag1 = false;
        }
        if(flag1 && flag2){
            cout << a << " -- is a mirrored palindrome.\n\n";
        }else if(flag1 && !flag2){
            cout << a << " -- is a regular palindrome.\n\n";
        }else if(!flag1 && flag2){
            cout << a << " -- is a mirrored string.\n\n";
        }else if(!flag1 && !flag2){
            cout << a << " -- is not a palindrome.\n\n";
        }
    }
    return 0;
}