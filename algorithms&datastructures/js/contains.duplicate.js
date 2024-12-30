/**
 * @param {number[]} nums
 * @return {boolean}
 */
var containsDuplicate = function (nums) {
  set = new Set(nums);

  if (set.size == nums.length) {
    return false;
  }
  return true;
};

nums = [1, 2, 3, 1];
bool = containsDuplicate(nums);
console.log(bool);
