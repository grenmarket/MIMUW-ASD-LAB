#include <iostream>

#define REP(I,N) for(int I = 0 ; I < (N) ; I++)

using namespace std;

pair<vector<int>, vector<int>> read_input() {
    int cnt, start, stop;
    vector<int> starts;
    vector<int> stops;
    cin >> cnt;
    REP(i,cnt) {
        cin >> start;
        cin >> stop;
        starts.push_back(start);
        stops.push_back(stop);
    }
    return make_pair(starts, stops);
}

pair<int, int> compute(pair<vector<int>, vector<int>> v) {
    sort(v.first.begin(), v.first.end());
    int cnt = static_cast<int>(v.first.size());
    int max = 0;
    int t_min = 0;
    for (int i = 0; i < cnt; i++) {
        int t_start = v.first[i];
        int count = 0;
        for (int j = 0; j < cnt; j++) {
            if (v.second[j] <= t_start) {
                count++;
            }
        }
        int res = i - count + 1;
        if (res > max) {
            max = res;
            t_min = t_start;
        }
    }
    return make_pair(max, t_min);
}

int main() {
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(nullptr);
    pair<vector<int>, vector<int>> v = read_input();
    const pair<int, int> res = compute(v);
    cout << res.first << " " << res.second << '\n';
}