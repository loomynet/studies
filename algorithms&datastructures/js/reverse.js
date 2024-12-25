array = [50,60,70,80,90,100,110,120,130,140,150,160,170,180,190,200];

function reverse(array) {
    for (i=0;i<=array.length/2;i++) {
        temp = array[array.length-i-1];
        array[array.length-i-1] = array[i];
        array[i] = temp;
    }
    return array;
}

console.log(reverse(array));