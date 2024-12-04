array = [136,50,95,80,10];
temp = 0;

function max(array) {
    for (i = 0; i < array.length-1; i++) {
        if (array[i]>array[i+1]) {
            temp = array[i+1];
            array[i+1] = array[i];
            array[i] = temp;
        }
    }
}

max_array = max(array);

console.log(array[array.length-1]);