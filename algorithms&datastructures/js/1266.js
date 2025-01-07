/**
 * @param {number[][]} points
 * @return {number}
 */
var minTimeToVisitAllPoints = function (points) {
  let res = 0;
  let point1 = points.pop();
  let x1 = point1[0];
  let y1 = point1[1];
  while (points.length > 0) {
    let point2 = points.pop();
    let x2 = point2[0];
    let y2 = point2[1];

    res += Math.max(Math.abs(y2 - y1), Math.abs(x2 - x1));
    x1 = x2;
    y1 = y2;
  }
  return res;
};

let points_arr = [
  [1, 1],
  [3, 4],
  [-1, 0],
];
console.log(minTimeToVisitAllPoints(points_arr));
