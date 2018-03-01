#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef vector <ll> vi;

string line;

int problem[120][12];
int penalty[120][12];
int part[120];

struct Data{
    int id, solved, penalty;
    bool operator < (Data x){
        if(solved == x.solved){
            if(penalty == x.penalty) return id < x.id;
            return penalty < x.penalty;
        }
        return solved > x.solved;
    }
};

vector <Data> b;

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    freopen("in.txt", "r", stdin);
    freopen("out.txt", "w", stdout);
    int tc; cin >> tc; cin.ignore();
    int cn, prob, tim;
    char type;
    while(tc--){
        cin.ignore();
        memset(part, 0, sizeof part); memset(penalty, 0, sizeof penalty);
        memset(problem, 0, sizeof problem); b.clear();
        while(cin.peek() != '\n' && cin.peek() != EOF){
            getline(cin, line);
            stringstream sin(line);
            sin >> cn >> prob >> tim >> type;
            part[cn] = 1;
            if(type == 'C' && !problem[cn][prob]){
                problem[cn][prob] = 1;
                penalty[cn][prob] = penalty[cn][prob] * 20 + tim;
            }else if(type == 'I'){
                if(!problem[cn][prob]) penalty[cn][prob]++;
            }
        }
        for(int i=0; i<101; i++){
            if(!part[i]) continue;
            int pen = 0;
            int solved = 0;
            for(int j=0; j<11; j++){
                if(problem[i][j]){
                    solved++;
                    pen += penalty[i][j];
                }
            }
            b.push_back({i, solved, pen});
        }
        sort(b.begin(), b.end());
        for(int i=0; i<b.size(); i++){
            cout << b[i].id << " " << b[i].solved << " " << b[i].penalty << "\n";
        }
        if(tc) cout << "\n";
    }
    return 0;
}
