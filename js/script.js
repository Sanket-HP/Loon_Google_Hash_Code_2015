document.getElementById('inputForm').addEventListener('submit', function(event) {
    event.preventDefault();
});

function processInput() {
    const inputData = document.getElementById('inputData').value;
    const parsedData = parseInput(inputData);
    const result = runSimulation(parsedData);
    displayOutput(result);
}

function parseInput(input) {
    const lines = input.split('\n');
    const [R, C, A] = lines[0].split(' ').map(Number);
    const [L, V, B, T] = lines[1].split(' ').map(Number);
    const [startR, startC] = lines[2].split(' ').map(Number);
    
    const targets = [];
    for (let i = 3; i < 3 + L; i++) {
        const [r, c] = lines[i].split(' ').map(Number);
        targets.push({ r, c });
    }
    
    const winds = [];
    let index = 3 + L;
    for (let a = 0; a < A; a++) {
        const altitudeWinds = [];
        for (let r = 0; r < R; r++) {
            const row = [];
            for (let c = 0; c < C; c++) {
                const [dr, dc] = lines[index].split(' ').map(Number);
                row.push({ dr, dc });
                index++;
            }
            altitudeWinds.push(row);
        }
        winds.push(altitudeWinds);
    }
    
    return { R, C, A, L, V, B, T, start: { r: startR, c: startC }, targets, winds };
}

function runSimulation(data) {
    const { R, C, A, L, V, B, T, start, targets, winds } = data;
    const balloons = Array(B).fill(start);
    const altitudes = Array(B).fill(1);
    const isLaunched = Array(B).fill(false);
    let score = 0;
    const coverage = Array.from({ length: R }, () => Array(C).fill(false));
    
    const output = [];

    for (let t = 0; t < T; t++) {
        const turnOutput = [];
        for (let b = 0; b < B; b++) {
            if (!isLaunched[b]) {
                isLaunched[b] = true;
                turnOutput.push(1); // Launch the balloon
            } else {
                turnOutput.push(0); // Maintain altitude
                const altitude = altitudes[b] - 1;
                const { r, c } = balloons[b];
                const { dr, dc } = winds[altitude][r][c];
                const newR = r + dr;
                const newC = (c + dc + C) % C;
                if (newR >= 0 && newR < R) {
                    balloons[b] = { r: newR, c: newC };
                } else {
                    isLaunched[b] = false; // Balloon is lost
                }
            }
        }
        output.push(turnOutput.join(' '));

        // Update coverage
        coverage.forEach(row => row.fill(false));
        for (let b = 0; b < B; b++) {
            if (isLaunched[b]) {
                const { r, c } = balloons[b];
                for (let dr = -V; dr <= V; dr++) {
                    for (let dc = -V; dc <= V; dc++) {
                        const nr = r + dr;
                        const nc = (c + dc + C) % C;
                        if (nr >= 0 && nr < R && dr * dr + dc * dc <= V * V) {
                            coverage[nr][nc] = true;
                        }
                    }
                }
            }
        }

        // Calculate score
        for (const { r, c } of targets) {
            if (coverage[r][c]) {
                score++;
            }
        }
    }

    return { output, score };
}

function displayOutput(result) {
    document.getElementById('outputData').textContent = result.output.join('\n');
    document.getElementById('score').textContent = result.score;
}

