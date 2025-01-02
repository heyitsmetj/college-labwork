
<!DOCTYPE html>
<html lang="en">
<head>
    <meta charset="UTF-8">
    <meta name="viewport" content="width=device-width, initial-scale=1.0">
    <title>A1SetC1</title>
</head>
<body>
    <form action="A1SetC1.php" method="post">
    <input type="text" name = "n" placeholder = "Floyd's Triangle">
    <input type="submit" value="Check">
    </form>
</body>
</html>
<?php

$num = null;
$num = $_POST["n"];
$count = 1;

for ($i = 0; $i <= $num; $i++)
    {
        
        for ($j = 0; $j < $i; $j++)
        {
            echo "$count"."\t";
            $count++;
        }
        echo "<br>";
    }


?>
