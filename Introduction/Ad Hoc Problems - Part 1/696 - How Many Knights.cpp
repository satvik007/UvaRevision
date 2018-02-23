#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef vector <int> vi;

int main(){
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
	freopen("in.txt", "r", stdin);
	freopen("out.txt", "w", stdout);
	int n, m;
	while(cin >> n >> m, n||m){
		int a = min(n, m), b = max(n, m);
		if(a == 0) cout << 0 << " knights may be placed on a " << n << " row " << m << " column board.\n";
		else if (a == 1)  cout << b << " knights may be placed on a " << n << " row " << m << " column board.\n";
		else if(a == 2) {
			if(b%4 == 1) cout << (b+1) << " knights may be placed on a " << n << " row " << m << " column board."<< "\n";
			else cout << ((b+2)/4*4) << " knights may be placed on a " << n << " row " << m << " column board."<< "\n";
		}
		else cout << (n * m + 1) / 2 << " knights may be placed on a " << n << " row " << m << " column board.\n";
	}
	return 0;
}