/**
 * @param {number[]} nums
 * @return {number[]}
 */
var smallerNumbersThanCurrent = function (nums) {
  const sorted = [...nums].sort((a, b) => a - b);
  const map = new Map();

  sorted.forEach((num, index) => {
    if (!map.has(num)) {
      map.set(num, index);
    }
  });

  return nums.map((num) => map.get(num));
};

nums = [8, 1, 2, 2, 3];
console.log(smallerNumbersThanCurrent(nums));
