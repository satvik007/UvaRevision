#define BZ
#include <bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/detail/standard_policies.hpp>
using ll = int64_t;
using ld = long double;
using ull = uint64_t;
using namespace std;
using namespace __gnu_pbds;
typedef vector <int> vi;
typedef pair <int, int> ii;

const int INF = 1 << 30;



int main() {
#ifdef BZ
    freopen("in.txt", "r", stdin); freopen("out.txt", "w", stdout);
#endif
    ios_base::sync_with_stdio(false); cin.tie(nullptr); cout.tie(nullptr); cout.setf(ios::fixed); cout.precision(20);

    set <vi> perm;
    set <vi> comb;

    int n;
    while(cin >> n, n > 0) {
        int a, b, c;

        perm.clear();
        comb.clear();

        vi cur;
        for(int i = 0; i <= 21; i++) {
            for(int p = 1; p <= 3; p++) {
                if(i == 21) a = 50;
                else a = i * p;

                for(int j = 0; j <= 21; j++) {
                    for(int q = 1; q <= 3; q++) {
                        if(j == 21) b = 50;
                        else b = j * q;

                        for(int k = 0; k <= 21; k++) {
                            for(int r = 1; r <= 3; r++) {
                                if(k == 21) c = 50;
                                else c = k * r;

                                if(a + b + c == n) {
                                    cur.resize(3);
                                    cur[0] = a, cur[1] = b, cur[2] = c;
                                    perm.insert(cur);
                                    sort(cur.begin(), cur.end());
                                    comb.insert(cur);
                                }

                            }
                        }
                    }
                }
            }
        }

        if(comb.empty()) {
            cout << "THE SCORE OF " << n << " CANNOT BE MADE WITH THREE DARTS.\n";
        } else {
            cout << "NUMBER OF COMBINATIONS THAT SCORES " << n << " IS " << comb.size() << ".\n";
            cout << "NUMBER OF PERMUTATIONS THAT SCORES " << n << " IS " << perm.size() << ".\n";
        }


        cout << "**********************************************************************\n";
    }

    cout << "END OF OUTPUT\n";

}