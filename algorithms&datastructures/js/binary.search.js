function binarySearch(arr, x, start, end) {
  if (start > end) return "Element not found!";

  let mid = Math.floor((start + end) / 2);

  if (arr[mid] === x) return "Element " + arr[mid] + " found at index: " + mid;

  if (arr[mid] > x) {
    return binarySearch(arr, x, start, mid - 1);
  } else {
    return binarySearch(arr, x, mid + 1, end);
  }
}

let arr = [1, 2, 5, 7, 9, 10, 12, 43, 53, 78];

console.log(binarySearch(arr, 53, 0, arr.length - 1));
