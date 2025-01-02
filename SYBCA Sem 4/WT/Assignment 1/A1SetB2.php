<?php
$num = 153;

$temp = $num;
$digits = 0;

while($temp > 0)
{
    $temp /=(int)10;
    $digits++;
    echo $temp." ";
}

$sum = 0;
$temp = $num;

for($i = 0; $i < $digits; $i++)
{
    $digit = $temp % 10;
    $sum +=  pow($digit,$digits);
    $temp /= 10;
}

if($sum == $num)
echo " $num is an Armstrong number $sum.";
else
echo "$num is not an Armstrong number. $sum $digits";
?>
