<?php
function following($string): bool {
    $counter = 0;

    for ($i = 0; $i < strlen($string) - 1; $i++) {
        if (substr($string, $i, 1) == 'a') {
            $counter++;
        }

        if ((substr($string, $i, 2) == 'aa') && $counter < 2) {
            return true;
        }
    }

    return false;
}

var_dump(following("caabb"));
var_dump(following("babaaba"));
var_dump(following("aaaaa"));