#include <random>
using namespace std;

int main(int argc, char **argv) {
    unsigned seed = (argc > 1) ? (unsigned) atoi(argv[1]) : 0;
    mt19937 rng(seed);
    int n = 1 + rng() % 30;
    printf("%d\n", n);
    for (int i = 0; i < n; i++) {
        int start = (int) (rng() % 10);
        int stop = (int) (rng() % 10) + start + 1;
        printf("%d %d\n", start, stop);
    }
    return 0;
}