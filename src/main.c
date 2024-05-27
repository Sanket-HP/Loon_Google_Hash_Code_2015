#include "hashcode.h"

int main() {
    read_input();
    for (int t = 0; t < T; t++) {
        simulate_turn(t);
    }
    output_solution();
    printf("Score: %d\n", score);
    return 0;
}
