/**
 * @param {number[]} nums
 * @param {number} k
 * @return {boolean}
 */
var containsNearbyDuplicate = function (nums, k) {
  const seen = new Set();

  for (let i = 0; i < nums.length; i++) {
    if (i > k) {
      seen.delete(nums[i - k - 1]);
    }

    if (seen.has(nums[i])) {
      return true;
    }

    seen.add(nums[i]);
  }

  return false;
};

let nums = [1, 2, 3, 1, 2, 3];
let k = 2;
console.log(containsNearbyDuplicate(nums, k));
