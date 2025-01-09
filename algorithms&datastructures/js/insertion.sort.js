array = [50, 45, 60, 85, 90, 33, 1, 21, 67];

function insertionSort(array) {
  for (i = 1; i < array.length; i++) {
    temp = array[i];
    j = i - 1;

    while (j >= 0 && array[j] > temp) {
      array[j + 1] = array[j];
      j--;
    }
    array[j + 1] = temp;
  }
  return array;
}

console.log(insertionSort(array));
