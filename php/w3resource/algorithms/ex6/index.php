<?php

function removeChar(string $string, int $pos): string {
    $first = substr($string, 0, $pos);
    $second = substr($string, $pos+1, strlen($string)-$pos);
    return $first . $second;
}

$str = removeChar("Python",4);
echo $str;