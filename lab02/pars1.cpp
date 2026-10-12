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
    sort(v.second.begin(), v.second.end());
    int c_start = 0;
    int c_stop = 0;
    int count_start = 0;
    int count_stop = 0;
    int t = 0;
    int max = 0;
    const int t_end = std::max(v.first.back(), v.second.back());
    for (int i = 0; i <= t_end; i++) {
        while (c_stop < static_cast<int>(v.second.size()) && v.second[c_stop] == i) {
            count_stop++;
            c_stop++;
        }
        while (c_start < static_cast<int>(v.first.size()) && v.first[c_start] == i) {
            count_start++;
            c_start++;
        }
        if (count_start - count_stop > max) {
            max = count_start - count_stop;
            t = i;
        }
    }
    return make_pair(max, t);
}

int main() {
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(nullptr);
    pair<vector<int>, vector<int>> v = read_input();
    const pair<int, int> res = compute(v);
    cout << res.first << " " << res.second << '\n';
}