<?php

function tripleSum(int $a, int $b): int {
    if ($a==$b){
        $c = ($a+$b)*3;
    }else{
        $c = $a+$b;
    }
    return $c;
}

$c = tripleSum(3,3);

var_dump($c);