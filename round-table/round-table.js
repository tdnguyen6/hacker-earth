const readline = require("readline");
const rl = readline.createInterface({ input: process.stdin });
let inputs = [];

rl.on("line", function (line) {
  line
    .trim()
    .split(/[ ,]+/)
    .forEach((e) => inputs.push(e));
});

rl.on("close", function () {
  main();
});

function main() {
  let N = inputs.splice(0, 1);
  let Q = inputs.splice(0, 1);
  const arr = inputs.splice(0, N);
  let mapIndexes = {};
  for (let i = 0; i < N; i++) {
    const e = +arr[i];
    if (!(e in mapIndexes)) mapIndexes[e] = [];
    if (!mapIndexes[e].includes(i)) mapIndexes[e].push(i);
  }

  let min, x, y, start, searchRes, left, right;

  while (Q--) {
    min = Number.MAX_SAFE_INTEGER;
    x = inputs.splice(0, 1);
    y = inputs.splice(0, 1);
    extendedIndexes = mapIndexes[y]
      .map((x) => x - N)
      .concat(mapIndexes[y])
      .concat(mapIndexes[y].map((x) => x + +N));
    for (let i = 0; i < mapIndexes[x].length; i++) {
      start = mapIndexes[x][i];

      searchRes = customBinSearch(extendedIndexes, start);
      left = searchRes[0];
      right = searchRes[1];
      distance1 = Math.ceil((Math.abs(left - start) - 1) / 2);
      distance2 = Math.ceil((Math.abs(right - start) - 1) / 2);
      min = Math.min(distance1, distance2, min);
    }
    console.log(min.toFixed(0).replace('-0', '0'));
  }
}

function customBinSearch(list, val) {
  let low = 0;
  let high = list.length - 1;
  let mid = Math.floor((high + low) / 2);
  while (low < high) {
    if (list[mid] > val) high = mid;
    else low = mid + 1;
    mid = Math.floor((high + low) / 2);
  }
  return list[mid] > val
    ? [list[mid - 1 >= 0 ? mid - 1 : 0], list[mid]]
    : [list[mid], list[mid + 1 < list.length ? mid + 1 : list.length - 1]];
}
