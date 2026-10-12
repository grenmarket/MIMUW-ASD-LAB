#include <iostream>

#define REP(I,N) for(int I = 0 ; I < (N) ; I++)

using namespace std;

struct Event {
    int time;
    int count;
    Event(int t, int c) : time(t), count(c) {}
};

vector<Event> read_input() {
    int cnt, start, stop;
    vector<Event> times;
    cin >> cnt;
    REP(i,cnt) {
        cin >> start;
        cin >> stop;
        times.push_back(Event(start, 1));
        times.push_back(Event(stop, -1));
    }
    sort(times.begin(), times.end(), [](Event a, Event b) {
        if (a.time != b.time) {
            return a.time < b.time;
        }
        return a.count < b.count;
    } );
    return times;
}

pair<int, int> compute(vector<Event> times) {
    int max = 0;
    int t = 0;
    int size = static_cast<int>(times.size());
    int sum = 0;
    for (int i = 0; i < size; i++) {
        sum += times[i].count;
        if (sum > max) {
            max = sum;
            t = times[i].time;
        }
    }
    return make_pair(max, t);
}

int main() {
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(nullptr);
    vector<Event> v = read_input();
    const pair<int, int> res = compute(v);
    cout << res.first << " " << res.second << '\n';
}