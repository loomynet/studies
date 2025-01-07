/**
 * @param {number[][]} matrix
 * @return {number[]}
 */
var spiralOrder = function (matrix) {
  let m = matrix.length; //h
  let n = matrix[0].length; //w
  let arr = [];
  let top = 0;
  let bottom = m - 1;
  let left = 0;
  let right = n - 1;
  while (top <= bottom && left <= right) {
    for (let i = left; i <= right; i++) {
      arr.push(matrix[top][i]);
    }
    top++;

    for (let i = top; i <= bottom; i++) {
      arr.push(matrix[i][right]);
    }
    right--;

    if (top <= bottom) {
      for (let i = right; i >= left; i--) {
        arr.push(matrix[bottom][i]);
      }
      bottom--;
    }

    if (left <= right) {
      for (let i = bottom; i >= top; i--) {
        arr.push(matrix[i][left]);
      }
      left++;
    }
  }

  return arr;
};

matrix = [
  [1, 2, 3, 4],
  [5, 6, 7, 8],
  [9, 10, 11, 12],
];

console.log(spiralOrder(matrix));
