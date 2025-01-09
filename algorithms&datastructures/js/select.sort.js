array = [60, 75, 80, 50, 90];

function selectSort(array) {
  len = array.length - 1;
  var minIndex;
  for (var i = 0; i < len; i++) {
    minIndex = i;
    var minValue = array[minIndex];
    for (var j = i; j < len; j++) {
      if (minValue > array[j + 1]) {
        minValue = array[j + 1];
        minIndex = j + 1;
      }
    }
    if (i != minIndex) {
      var temp = array[i];
      array[i] = array[minIndex];
      array[minIndex] = temp;
    }
  }
  return array;
}

console.log(selectSort(array));
