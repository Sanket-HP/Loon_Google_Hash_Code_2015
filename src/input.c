#include "hashcode.h"

int R, C, A;
int L, V, B, T;
Position start;
Position targets[MAX_L];
WindVector winds[MAX_A][MAX_R][MAX_C];

void read_input() {
    scanf("%d %d %d", &R, &C, &A);
    scanf("%d %d %d %d", &L, &V, &B, &T);
    scanf("%d %d", &start.r, &start.c);
    
    for (int i = 0; i < L; i++) {
        scanf("%d %d", &targets[i].r, &targets[i].c);
    }
    
    for (int a = 0; a < A; a++) {
        for (int r = 0; r < R; r++) {
            for (int c = 0; c < C; c++) {
                scanf("%d %d", &winds[a][r][c].dr, &winds[a][r][c].dc);
            }
        }
    }
}
