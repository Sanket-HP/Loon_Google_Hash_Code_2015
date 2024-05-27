#include "hashcode.h"

Position balloons[MAX_B];
int balloon_altitudes[MAX_B];
bool is_launched[MAX_B];
bool covered[MAX_R][MAX_C];
int score = 0;

bool in_grid(int r, int c) {
    return r >= 0 && r < R && c >= 0 && c < C;
}

void simulate_turn(int turn) {
    for (int b = 0; b < B; b++) {
        if (!is_launched[b]) {
            balloons[b] = start;
            balloon_altitudes[b] = 1;
            is_launched[b] = true;
        } else {
            int altitude = balloon_altitudes[b] - 1;
            int r = balloons[b].r;
            int c = balloons[b].c;
            int dr = winds[altitude][r][c].dr;
            int dc = winds[altitude][r][c].dc;
            int new_r = r + dr;
            int new_c = (c + dc + C) % C;
            if (in_grid(new_r, new_c)) {
                balloons[b].r = new_r;
                balloons[b].c = new_c;
            } else {
                is_launched[b] = false;
            }
        }
    }

    memset(covered, 0, sizeof(covered));
    for (int b = 0; b < B; b++) {
        if (is_launched[b]) {
            int r = balloons[b].r;
            int c = balloons[b].c;
            for (int dr = -V; dr <= V; dr++) {
                for (int dc = -V; dc <= V; dc++) {
                    int nr = r + dr;
                    int nc = (c + dc + C) % C;
                    if (in_grid(nr, nc) && dr * dr + dc * dc <= V * V) {
                        covered[nr][nc] = true;
                    }
                }
            }
        }
    }

    for (int i = 0; i < L; i++) {
        int tr = targets[i].r;
        int tc = targets[i].c;
        if (covered[tr][tc]) {
            score++;
        }
    }
}
