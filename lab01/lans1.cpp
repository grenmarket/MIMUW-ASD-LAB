#include <iostream>

#define REP(I,N) for(int I = 0 ; I < (N) ; I++)
#define MODULO 1000000007

using namespace std;

tuple<int, vector<int>> read_input() {
    int cnt, el;
    vector<int> v;
    cin >> cnt;
    REP(i,cnt) {
        cin >> el;
        v.push_back(el);
    }
    return make_tuple(cnt, v);
}

long long compute_result(int n, const vector<int>& v) {
    long long res = 0;
    for (int i = 0; i < n-1; i++) {
        for (int j = i+1; j < n; j++) {
            long long t = v[i] - v[j];
            long long square = t * t;
            long long interm = (square % MODULO);
            long long temp_res = (res + interm) % MODULO;
            res = (temp_res + MODULO) % MODULO;
        }
    }
    return (res + MODULO) % MODULO;
}

int main() {
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(nullptr);
    auto [n, v] = read_input();
    cout << compute_result(n, v) << endl;
}
