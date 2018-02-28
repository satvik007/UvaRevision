#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef vector <int> vi;

void print(int d, int m){
    if(m == 1 && d>=21 || m==2 && d<=19) cout << "aquarius" << "\n";
    if(m == 2 && d>=20 || m==3 && d<=20) cout << "pisces" << "\n";
    if(m == 3 && d>=21 || m==4 && d<=20) cout << "aries" << "\n";
    if(m == 4 && d>=21 || m==5 && d<=21) cout << "taurus" << "\n";
    if(m == 5 && d>=22 || m==6 && d<=21) cout << "gemini" << "\n";
    if(m == 6 && d>=22 || m==7 && d<=22) cout << "cancer" << "\n";
    if(m == 7 && d>=23 || m==8 && d<=21) cout << "leo" << "\n";
    if(m == 8 && d>=22 || m==9 && d<=23) cout << "virgo" << "\n";
    if(m == 9 && d>=24 || m==10 && d<=23) cout << "libra" << "\n";
    if(m == 10 && d>=24 || m==11 && d<=22) cout << "scorpio" << "\n";
    if(m == 11 && d>=23 || m==12 && d<=22) cout << "sagittarius" << "\n";
    if(m == 12 && d>=23 || m==1 && d<=20) cout << "capricorn" << "\n";
}

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    freopen("in.txt", "r", stdin);
    freopen("out.txt", "w", stdout);
    int tc; cin >> tc;
    int n, cas = 1;
    cout << setfill('0');
    while(tc--){
        tm curr; mktime(&curr);
        cin >> n;
        curr.tm_mon = n / 1000000 - 1;
        curr.tm_mday = (n % 1000000)/10000 + 280;
        curr.tm_year = n % 10000 - 1900;
        mktime(&curr);
        cout << cas++ << " " << setw(2) << curr.tm_mon + 1<< "/" << setw(2) << curr.tm_mday
             << "/" << setw(4) << curr.tm_year + 1900 << " ";
        print(curr.tm_mday, curr.tm_mon + 1);
    }
    return 0;
}