function reverseArray(arr) {
  let newArr = [];
  let counter = 0;
  for (let i = arr.length - 1; i >= 0; i--) {
    newArr[counter] = arr[i];
    counter++;
  }
  return newArr;
}

function reverseArrayInPlace(arr) {
  let pointer = 0;
  let mockArr = [...arr];

  for (let i = arr.length - 1; i >= 0; i--) {
    arr[pointer] = mockArr[i];
    pointer++;
  }
  return arr;
}

arr = [1, 2, 3, 4, 5];

console.log(reverseArray(arr));
console.log(reverseArrayInPlace(arr));
