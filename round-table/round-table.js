process.stdin.resume();
process.stdin.setEncoding("utf-8");

let inputs = [];

process.stdin.on("data", function (data) {
  let lines = data.split("\n");
  lines.forEach((line) =>
    line
      .trim()
      .split(" ")
      .forEach((e) => inputs.push(e))
  );
});

process.stdin.on("end", function () {
  main();
});

function solve(query = [], arr = [], mapIndexes = {}) {
  const x = +query[0];
  const y = +query[1];

  let min = Number.MAX_SAFE_INTEGER;

  for (let i = 0; i < mapIndexes[x].length; i++) {
    for (let j = 0; j < mapIndexes[y].length; j++) {
      let start, end;
      if (mapIndexes[x][i] < mapIndexes[y][j]) {
        start = mapIndexes[x][i];
        end = mapIndexes[y][j];
      } else {
        end = mapIndexes[x][i];
        start = mapIndexes[y][j];
      }

      const distance1 = +Math.ceil((end - start - 1) / 2)
        .toFixed(0)
        .replace("-0", "0");
      const distance2 = +Math.ceil((start + arr.length - end - 1) / 2)
        .toFixed(0)
        .replace("-0", "0");
      const distance = distance1 < distance2 ? distance1 : distance2;
      min = distance < min ? distance : min;
    }
  }

  console.log(+min);

  return;
}

function main() {
  let N = inputs.splice(0, 1);
  let Q = inputs.splice(0, 1);
  const arr = inputs.slice(0, inputs.length - 2 * Q);
  let mapIndexes = {};
  for (let i = 0; i < arr.length; i++) {
    const e = +arr[i];
    if (!(e in mapIndexes)) mapIndexes[e] = [];
    if (!mapIndexes[e].includes(i)) mapIndexes[e].push(i);
  }

  while (Q--) {
    solve(inputs.splice(0, 2), arr, mapIndexes);
  }
}
