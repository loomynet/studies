array = [1,53,-12,1111,455,-24];

function minValue(array) {
    min = array[0];
    for(i=1;i<array.length;i++) {
        if (array[i]<min) {
            min = array[i];
        }
    }
    return min;
}

console.log(minValue(array));