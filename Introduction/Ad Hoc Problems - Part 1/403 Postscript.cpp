#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef vector <int> vi;

string test1 =
".***.. ****.. .****. ****.. *****. *****. .****. *...*. *****.\
 *...*. *...*. *...*. *...*. *..... *..... *..... *...*. ..*...\
 *****. ****.. *..... *...*. ***... ***... *..**. *****. ..*...\
 *...*. *...*. *..... *...*. *..... *..... *...*. *...*. ..*...\
 *...*. ****.. .****. ****.. *****. *..... .***.. *...*. *****.\
 ..***. *...*. *..... *...*. *...*. .***.. ****.. .***.. ****..\
 ...*.. *..*.. *..... **.**. **..*. *...*. *...*. *...*. *...*.\
 ...*.. ***... *..... *.*.*. *.*.*. *...*. ****.. *...*. ****..\
 *..*.. *..*.. *..... *...*. *..**. *...*. *..... *..**. *..*..\
 .**... *...*. *****. *...*. *...*. .***.. *..... .****. *...*.\
 .****. *****. *...*. *...*. *...*. *...*. *...*. *****. ......\
 *..... *.*.*. *...*. *...*. *...*. .*.*.. .*.*.. ...*.. ......\
 .***.. ..*... *...*. .*.*.. *.*.*. ..*... ..*... ..*... ......\
 ....*. ..*... *...*. .*.*.. **.**. .*.*.. ..*... .*.... ......\
 ****.. .***.. .***.. ..*... *...*. *...*. ..*... *****. ......";

stringstream test(test1);
vector <vector <string> > rep(27, vector <string> (5));
vector <string> a(60);

void init() {
    for(int i=0; i<60; i++) a[i].resize(60);
    for (int t = 0; t < 3; t++)
        for (int i = 0; i < 5; i++)
            for (int j = 0; j < 9; j++)
                test >> rep[9 * t + j][i];
    //for (int i = 0; i < 26; i++) { for (int j = 0; j < 5; j++) { cout << rep[i][j] << "\n"; }cout << "\n"; }
}

void read(){
    string line;
    string align, font, message;
    int row, col;
    while(true){
        getline(cin, line);
        if(line == ".EOP") return;
        stringstream sin(line);
        sin >> align >> font >> row; row--;
        if(align == ".P"){
            sin >> col; col--;
        }
        sin.ignore(); sin.ignore();
        getline(sin, message, '|');
        if(align == ".L") col = 0;
        else if(align == ".R") {
            if(font == "C1") col = 60 - (int)message.size();
            else col = 60 - 6*(int)message.size();
        }else if(align == ".C"){
            if(font == "C1") col = 30-(int)message.size()/2;
            else col = 30 - 6*(int)message.size()/2;
        }
        if(font == "C1" && row <60 && row >= 0){
            for(int i=0; i<message.size() && i + col < 60; i++){
                if(col+i >= 0 && col+i < 60){
                    if(message[i] == ' ') continue;
                    a[row][col+i] = message[i];
                }
            }
        }
        else if(font == "C5"){
            for(int i=0; i<message.size(); i++){
                if(message[i] != ' '){
                    for(int k = 0; k <5; k++){
                        for(int m=0; m<6; m++){
                            if(row+k<60 && col+m<60 && row + k >= 0 && col+m >= 0){
                                if(rep[message[i]-'A'][k][m] == '.');
                                else{
                                    a[row+k][col+m] = rep[message[i]-'A'][k][m];
                                }
                            }
                        }
                    }
                }
                col += 6;
            }
        }

    }
}

void write(){
    for(int i=0; i<60; i++){
        cout << a[i] << "\n";
    }
    cout << "\n";
    for(int i=0; i<60; i++) cout << "-";
    cout << "\n\n";
}

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    freopen("in.txt", "r", stdin);
    freopen("out.txt", "w", stdout);
    init();
    while(cin.peek() != EOF){
        for(int i=0; i<60; i++) for(int j=0; j<60; j++) a[i][j] = '.';
        read();
        write();
    }
    return 0;
}