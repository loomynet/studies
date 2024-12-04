array = [35,22,67,42,95,29,357,1,23,59,124,2,3,4]

function bubbleSort(array) {
    for(i=0;i<array.length-1;i++) {
        for(j=0;j<array.length-i-1;j++) {
            if (array[j] > array[j+1]) {
                temp = 0;
                temp = array[j+1];
                array[j+1] = array[j];
                array[j] = temp;
            }
        }
    } 
}

array_sorted = bubbleSort(array);
console.log (array);