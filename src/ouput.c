#include "hashcode.h"

void output_solution() {
    for (int t = 0; t < T; t++) {
        for (int b = 0; b < B; b++) {
            if (t == 0) {
                printf("1 ");
            } else {
                printf("0 ");
            }
        }
        printf("\n");
    }
}
