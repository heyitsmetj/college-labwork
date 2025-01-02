<?php
$num1 = 30;
$num2 = 40;
$num3 = 10;

if($num1 > $num2 && $num1 > $num3)
    echo "$num1 is greater than $num2 & $num3";
elseif($num2 > $num1 && $num2 > $num3)
echo "$num2 is greater than $num1 & $num3";
elseif($num3 > $num1 && $num3 > $num2)
echo "$num3 is greater than $num1 & $num2";
else
    echo "$num1,$num2,$num3 are Equal.";

?>
