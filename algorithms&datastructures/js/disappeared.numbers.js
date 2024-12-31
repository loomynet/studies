/*
  size = nums.length;
  const set1 = new Set(nums);
  set2 = (Array.from({ length: size }, (_, i) => i + 1));
  return set2.filter((num) => !set1.has(num)); 
*/

/**
 * @param {number[]} nums
 * @return {number[]}
 */
var findDisappearedNumbers = function (nums) {
  size = nums.length;
  set1 = new Set(nums);
  set2 = new Set(Array.from({ length: size }, (_, i) => i + 1));
  return set2.difference(set1);
};

nums = [4, 3, 2, 7, 8, 2, 3, 1];
set = findDisappearedNumbers(nums);
console.log(set);
