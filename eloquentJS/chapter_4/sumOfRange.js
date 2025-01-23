function range(start, end) {
  let arr = [];
  while (start <= end) {
    arr.push(start);
    start++;
  }
  return arr;
}

function sum(arr) {
  let sum = 0;
  for (element of arr) {
    sum += element;
  }
  return sum;
}

function stepRange(start, end, step = 1) {
  try {
    let arr = [];
    if ((start < end && step < 0) || (start > end && step > 0)) {
      throw new Error();
    }
    if (step > 0) {
      while (start != end + 1) {
        arr.push(start);
        start += step;
      }
    } else {
      while (start != end - 1) {
        arr.push(start);
        start += step;
      }
    }
    return arr;
  } catch (Error) {
    console.log("Invalid arguments");
  }
}

console.log(sum(stepRange(1, 10, 2)));

console.log(stepRange(1, 10, 2));
