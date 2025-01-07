/**
 * @param {number[][]} matrix
 * @return {number[]}
 */
var spiralOrder = function (matrix) {
  let m = matrix.length; //h
  let n = matrix[0].length; //w
  let arr = [];
  let top = 0;
  let bottom = m-1;
  let left = 0;
  let right = n-1;
  while (bottom != top || left != right) {
    for (let i = 0; i <= right; i++) {
      arr.push(matrix[top][i]);
    }
    top++;
    for (let i = top; i <= bottom; i++) {
      arr.push(matrix[i][right]);
    }
    right--;
    for (let i = right; i >= right - left; i--) {
      arr.push(matrix[bottom][i]);
    }
    bottom--;
    for (let i = bottom; i > top; i--) {
      arr.push(matrix[0][i]);
    }
    left++;
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
