/**
 * @param {number[][]} matrix
 * @return {number[]}
 */
var spiralOrder = function (matrix) {
  let m = matrix.length; //h
  let n = matrix[0].length; //w
  let arr = [];
  let top = 0;
  let bottom = m;
  let left = n;
  let right = n;
  while (true) {
    for (let i = 0; i < right; i++) {
      arr.push(matrix[0][i]);
    }
    top++;
    for (let i = 1; i < bottom; i++) {
      arr.push(matrix[i][right - 1]);
    }
    right--;
    for (let i = 0; i < array.length; i++) {}
  }

  return arr;
};

matrix = [
  [1, 2, 3, 4],
  [5, 6, 7, 8],
  [9, 10, 11, 12],
];

//
// 1.[0,0] -> [0,n]
// 2.[0,n] -> [m,n]
// 3.[m,n] -> [m,0] ... shift, pop, laps++
// 4.[m,0] -> [0,0]
