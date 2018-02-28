#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef vector <int> vi;

vector <vector <string>> a(3);
int counter[30];

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    freopen("in.txt", "r", stdin);
    freopen("out.txt", "w", stdout);
    int tc; cin >> tc;
    for(int i=0; i<3; i++) a[i].resize(3);
    while(tc--){
        for(int i=0; i<3; i++)
            for(int j=0; j<3; j++)
                cin >> a[i][j];
        memset(counter, 0, sizeof counter);
        for(int i=0; i<3; i++)
            for(int j=0; j<2; j++)
                for(auto el:a[i][j])
                    counter[el-'A'] = 1;
        for(int i=0; i<3; i++)
            if(a[i][2] == "even"){
                for(auto el:a[i][0])
                    counter[el-'A'] = 0;
                for(auto el:a[i][1])
                    counter[el-'A'] = 0;
            }else if(a[i][2] == "down"){
                a[i][2] = "up";
                swap(a[i][1], a[i][0]);
            }
        for(int i=0; i<26; i++){
            char current = (char)('A' + i);
            if(counter[i]){
                bool flag1 = true, flag2 = true;
                for(int j=0; j<3; j++){
                    if(a[j][2] == "up"){
                        if(a[j][1].find(current) == string::npos) flag1 = false;
                        if(a[j][0].find(current) == string::npos) flag2 = false;
                    }
                }
                if(flag1) cout << current << " is the counterfeit coin and it is light.\n";
                if(flag2) cout << current << " is the counterfeit coin and it is heavy.\n";
            }
        }

    }
    return 0;
}