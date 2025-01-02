
<!DOCTYPE html>
<html lang="en">
<head>
    <meta charset="UTF-8">
    <meta name="viewport" content="width=device-width, initial-scale=1.0">
    <title>A1SetC2</title>
</head>
<body>
    
</body>
</html>
<?php
$source_code = file('https://www.google.com/');


foreach ($source_code as $line_number => $last_line)
{
    echo nl2br(htmlspecialchars($last_line). "\n");
}

?>
