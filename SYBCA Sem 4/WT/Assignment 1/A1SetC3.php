

<!DOCTYPE html>
<html lang="en">
<head>
    <meta charset="UTF-8">
    <meta name="viewport" content="width=device-width, initial-scale=1.0">
    <title>A1SetC3</title>
</head>
<body>
    <form action="A1SetC3.php" method="post">
    <input type="text" name = "n" placeholder = "Enter number">
    <input type="submit" value="Check">
    </form>
</body>
</html>

<?php
$num1 = $_POST["n"];

($num1 > 10) ? ($res = "$num1 is greater than 10.") :
($num1 > 20) ? ($res = "$num1 is greater than 20.") :
($num1 > 30) ? ($res = "$num1 is greater than 30.") : 
$res = "No condition met.";

echo $res;
?>
