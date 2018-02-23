#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef vector <int> vi;

int n, m;

struct Data{
    string name;
    double price;
    int req, id;
    bool operator < (Data x){
        if(req == x.req){
            if(price == x.price){
                return id < x.id;
            }
            return price < x.price;
        }
        return req > x.req;
    }
};

vector <Data> b;

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    freopen("in.txt", "r", stdin);
    freopen("out.txt", "w", stdout);
    int cas = 1;
    while(cin >> n >> m, n||m){
        if(cas != 1) cout << "\n";
        string u, v;
        cin.ignore();
        for(int i=0; i<n; i++){
            getline(cin, u);
        }
        b.resize(m);
        for(int i=0; i<m; i++){
            getline(cin, b[i].name);
            cin >> b[i].price >> b[i].req; b[i].id = i;
            cin.ignore();
            for(int j=0; j<b[i].req; j++){
                getline(cin, u);
            }
        }
        cout << "RFP #" << cas++ << "\n";
        cout << min_element(b.begin(), b.end()) -> name << "\n";
    }
    return 0;
}
