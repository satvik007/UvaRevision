#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef vector <int> vi;

int tc, n, m;
char type;

int main(){
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
	freopen("in.txt", "r", stdin);
	freopen("out.txt", "w", stdout);
	cin >> tc;
	while(tc--){
		cin >> type >> n >> m;
		if(type == 'r') cout << min(n, m) << "\n";
		else if(type == 'k') cout << (n*m+1)/2 << "\n";
		else if(type == 'Q') cout << min(n, m) << "\n";
		else if(type == 'K') cout << (((n+1)/2) * ((m+1)/2)) << "\n";
	}

	return 0;
}