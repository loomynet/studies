function isEven(num) {
  if (num == 1) return "Is odd";
  else if (num == 0) return "Is even";
  else if (num == -1) return "This function works only with positive values";
  return isEven(num - 2);
}

let num = 50;
let num1 = 75;

console.log(isEven(num));

console.log(isEven(num1));

console.log(isEven(-1));
