
<!DOCTYPE html>
<html lang="en">
<head>
    <meta charset="UTF-8">
    <meta name="viewport" content="width=device-width, initial-scale=1.0">
    <title>A1SetB2</title>
</head>
<body>
    <form action="A1SetB2.php" method="post">
    <input type="text" name = "n" placeholder = "Armstrong Number">
    <input type="submit" value="Check">
    </form>
</body>
</html>
<?php

$num = null;
$num = $_POST["n"];

$temp = $num;
$digits = 0;

while($temp > 0)
{
    $temp = round($temp / 10);
    $digits++;
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
echo " $num is an Armstrong number.";
else
echo "$num is not an Armstrong number.";
?>
