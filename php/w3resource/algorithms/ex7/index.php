<?php

function swap(string $string) {
    if(strlen($string) == 1){
        return $string;
    }

    $first = $string[0];
    $last = $string[strlen($string)-1];

    $string = substr($string, 1, strlen($string)-2);

    return $last . $string . $first;
}

$str = 'Java';

$str = swap($str);
echo $str;