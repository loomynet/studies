<?php

function lastThreeToUpperCase(string $string): string {
    if(strlen($string) <= 3){
        return strtoupper($string);
    }

    return substr($string,0,-3) . strtoupper(substr($string,strlen($string)-3,3));
}

echo lastThreeToUpperCase("Javascript");