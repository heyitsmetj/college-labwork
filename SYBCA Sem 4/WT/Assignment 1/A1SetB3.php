
<!DOCTYPE html>
<html lang="en">
<head>
    <meta charset="UTF-8">
    <meta name="viewport" content="width=device-width, initial-scale=1.0">
    <title>A1SetB3</title>
</head>
<body>
    <form action="A1SetB3.php" method="post">
    <input type="text" name = "n" placeholder = "Prime Number">
    <input type="submit" value="Check">
    </form>
</body>
</html>
<?php

$num = null;
$flag = false;
$num = $_POST["n"];

for($i = 2; $i < $num; $i++)
{
    if($num % $i == 0)
    {
        $flag = true;
        break;
    }
}

if($flag)
echo " $num is NOT a Prime number.";
else
echo "$num is a Prime number.";

?>
