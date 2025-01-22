function countBs(string) {
  if (!(typeof string === "string")) {
    return console.log("This function accepts only strings");
  }
  let counter = 0;
  for (let i = 0; i < string.length; i++) {
    if (string[i] == "B") {
      counter++;
    }
  }
  return counter;
}

function countChar(string, char) {
  if (!(typeof string === "string")) {
    return console.log("This function accepts only strings");
  }
  let counter = 0;
  for (let i = 0; i < string.length; i++) {
    if (string[i] == char) {
      counter++;
    }
  }
  return counter;
}

console.log(countBs("BOB"));
console.log(countChar("kakkerlak", "k"));
