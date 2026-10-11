struct Mint {
    static constexpr long long MOD = 1'000'000'007;
    long long v;  // niezmiennik: 0 <= v < MOD
    Mint(long long x = 0) : v(x % MOD) { if (v < 0) v += MOD; }
    Mint operator+(Mint o) const { return v + o.v; }
    Mint operator-(Mint o) const { return v - o.v; }
    Mint operator*(Mint o) const { return v * o.v; }
};