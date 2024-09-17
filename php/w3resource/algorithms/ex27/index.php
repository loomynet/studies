<?php

function countStrings(string $string): int {
    $strCounter = 0;
    $strlen = strlen($string);

    for ($i=0; $i<$strlen; $i++) {
        if(substr($string,$i,2) == 'aa') {
            $strCounter++;
        }elseif(substr($string,$i,3) == 'aaa') {
            $strCounter+=2;
        }
    }
    return $strCounter;
}

$str = 'aaJSaaakoiaaa';

echo countStrings($str);



