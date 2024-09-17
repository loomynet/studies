<?php

function ifString(string $string): string {
    $if = 'if ';

    if($string[0] == 'i' && $string[1] == 'f' ){
        return $string;
    }else{
        $string = $if . $string;
    }

    return $string;
}

$str = 'gol';

$str = ifString($str);
echo $str;