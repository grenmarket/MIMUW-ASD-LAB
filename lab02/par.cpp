#include <iostream>
#include <vector>

#define REP(I,N) for(int I = 0 ; I < (N) ; I++)

using namespace std;

vector<pair<int, int>> read_input() {
    int cnt, start, stop;
    vector<pair<int, int>> times;
    cin >> cnt;
    REP(i,cnt) {
        cin >> start;
        cin >> stop;
        times.push_back(make_pair(start, 1));
        times.push_back(make_pair(stop, -1));
    }
    sort(times.begin(), times.end());
    return times;
}

pair<int, int> compute(vector<pair<int, int>> times) {
    int max = 0;
    int t = 0;
    int size = static_cast<int>(times.size());
    int sum = 0;
    for (int i = 0; i < size; i++) {
        sum += times[i].second;
        if (sum > max) {
            max = sum;
            t = times[i].first;
        }
    }
    return make_pair(max, t);
}

int main() {
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(nullptr);
    vector<pair<int, int>> v = read_input();
    const pair<int, int> res = compute(v);
    cout << res.first << " " << res.second << '\n';
}