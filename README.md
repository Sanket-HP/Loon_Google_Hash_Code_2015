# Loon_Google_Hash_Code_2015

The HashCode 2015 Final Round problem centers on Project Loon, which aims to provide universal Internet access via high-altitude balloons equipped with LTE transmitters. These balloons adjust their altitude to catch the right wind currents and move to target areas for providing internet coverage. 

## Problem Description

- Earth Grid
1. The Earth is modeled as a rectangular 2D grid with dimensions R (rows) by C (columns).
2. The grid is cyclic horizontally, meaning that the cells at the edges of each row wrap around, but it is not cyclic vertically.

- Wind
1. The wind is represented by movement grids at different altitudes.
2. Each movement grid is a grid of vectors. A vector in a cell indicates how the balloon will move from that cell at that altitude.
3. The movement caused by the wind does not change the altitude of the balloons.
   
- Balloons
1. At the beginning, all balloons are positioned in a single starting cell.
2. The simulation proceeds in turns. Each turn, balloons can adjust their altitude by -1, 0, or +1.
3. Once launched, balloons cannot be brought back to the ground.

- Internet Coverage
1. Each balloon provides coverage in a circular area with a given radius V.
2. The goal is to cover target cells with Internet access.
3. A target cell covered by at least one balloon at the end of a turn contributes one point to the final score, regardless of the number of balloons covering it.

## Task
Given the wind data at different altitudes and other parameters, plan altitude adjustments for a fleet of balloons to maximize Internet coverage of target cells over a series of turns.

- Input Data
The input data includes:
1. Dimensions of the grid: R, C and the number of Altitufes A.
2. Number of target cells L, coverage radius V, number of boolans B, and the number of turns T.
3. Starting cell coordinates for the balloons.
4. Coordinates of the target cells.
5. Movement grids for each altitude.

- Output Data
Your submission must be a plain text file with:

1. 𝑇 lines (one for each turn), each containing 𝐵 integers (-1, 0, or 1) indicating the altitude adjustments for each balloon.

- Example
Consider an example where:

1. The grid is 3x5 with 3 altitudes.
2. There are 2 target cells, a coverage radius of 1, 1 balloon, and 5 turns.
3. The starting cell is (1, 2).
4. Target cells are at (0, 2) and (0, 4).
5. The wind vectors move the balloon east at altitude 1, north at altitude 2, and east again at altitude 3.

- Example Input
3 5 3
2 1 1 5
1 2
0 2
0 4
0 1 0 1 0 1 0 1 0 1
0 1 0 1 0 1 0 1 0 1
0 1 0 1 0 1 0 1 0 1
-1 0 -1 0 -1 0 -1 0 -1 0
-1 0 -1 0 -1 0 -1 0 -1 0
-1 0 -1 0 -1 0 -1 0 -1 0
0 1 0 1 0 1 0 2 0 1
0 2 0 1 0 2 0 3 0 2
0 1 0 1 0 1 0 2 0 1

- Example Outpt
1
1
1
0
0

- This means:

1. The balloon is launched immediately, reaching altitude 1 in turn 0.
2. It reaches altitude 2 in turn 1, altitude 3 in turn 2, and stays at altitude 3 for turns 3 and 4.

## Scoring
The final score is the total number of turns during which each target cell is covered by at least one balloon. Each target cell can contribute at most one point per turn, regardless of the number of balloons covering it.

## Validation
Ensure that:

1. The file format matches the specified requirements.
2. Altitude adjustments are valid (balloons cannot be adjusted below 1 or above A).
3. Balloons not launched cannot have their altitude decreased.

