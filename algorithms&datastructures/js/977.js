/**
 * @param {number[]} nums
 * @return {number[]}
 */
var sortedSquares = function (nums) {
  let squares = [];
  for (i = 0; i < nums.length; i++) {
    squares.push(Math.pow(nums[i], 2));
  }
  return squares.sort((a, b) => a - b);
};

nums = [-4, -1, 0, 3, 10];
console.log(sortedSquares(nums));
