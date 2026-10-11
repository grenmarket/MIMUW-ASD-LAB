#include <iostream>
#include <vector>
#include <tuple>

# define REP(I,N) for(int I = 0 ; I < (N) ; I++)

using namespace std;

struct Mint {
    static constexpr long long MOD = 1'000'000'007;
    long long v;  // niezmiennik: 0 <= v < MOD
    Mint(long long x = 0) : v(x % MOD) { if (v < 0) v += MOD; }
    Mint operator+(Mint o) const { return v + o.v; }
    Mint operator-(Mint o) const { return v - o.v; }
    Mint operator*(Mint o) const { return v * o.v; }
};

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
    Mint res = Mint(0);
    Mint sum = Mint(0);
    for (int i = 0; i < n; i++) {
        long long x = v[i];
        sum = sum + Mint(x);
        res = res + Mint(x * x);
    }
    return (Mint(n) * res - sum * sum).v;
}

int main() {
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(nullptr);
    auto [n, v] = read_input();
    cout << compute_result(n, v) << '\n';
}