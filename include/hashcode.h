#ifndef HASHCODE_H
#define HASHCODE_H

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>
#include <math.h>

#define MAX_R 1000
#define MAX_C 1000
#define MAX_A 10
#define MAX_L 1000
#define MAX_B 1000
#define MAX_T 1000

typedef struct {
    int r, c;
} Position;

typedef struct {
    int dr, dc;
} WindVector;

extern int R, C, A;
extern int L, V, B, T;
extern Position start;
extern Position targets[MAX_L];
extern WindVector winds[MAX_A][MAX_R][MAX_C];
extern Position balloons[MAX_B];
extern int balloon_altitudes[MAX_B];
extern bool is_launched[MAX_B];
extern bool covered[MAX_R][MAX_C];
extern int score;

void read_input();
void simulate_turn(int turn);
void output_solution();

#endif // HASHCODE_H
