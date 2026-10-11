#include <iostream>
#include <random>

# define REP(I,N) for(int I = 0 ; I < (N) ; I++)

using namespace std;

mt19937 rng;

int random_int(int lo, int hi) {
    uniform_int_distribution<int> dist(lo, hi);  // lo and hi are both included
    return dist(rng);
}

int main(int argc, char **argv) {
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(nullptr);
    int cnt = (argc > 1) ? atoi(argv[1]) : 200000;
    int lo   = (argc > 2) ? atoi(argv[2]) : -1000000;
    int hi   = (argc > 3) ? atoi(argv[3]) : 1000000;
    rng.seed(cnt);
    cout << cnt << '\n';
    REP(i, cnt) {
        if (i > 0) cout << ' ';
        cout << random_int(lo, hi);
    }
    cout << '\n';
}