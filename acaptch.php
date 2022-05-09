<?php

error_reporting(1);

$arr=range(99,9);

$brr=range(99,9);

$randa=array_rand($arr);

$randb=array_rand($brr); 

$a=$arr[$randa];

$b=$brr[$randb];

$r=$a+$b; 

$cap=$a."+".$b;

if(isset($_POST['b1']))

 {

    if($_POST['t2']==$_POST['t3'])

    {

    echo '<center>'.'<font color="blue" size="5">'."Welcome user".'</font>'.'</center>';

    }

   else

   {

   echo '<center>'.'<font color="red" size="5">'."Please fill the correct answer".'</font>'.'</center>';

   }

}

?>


   <html>

    <center>

    <form method="post">

<?php

error_reporting(1);

echo $cap."=";

?>

<input type="hidden" name="t3" value="<?php echo $r; ?>">

<input type="text" name="t2" autofocus><br>

<input type="submit" name="b1" value="match">

</form>

</center>

</html>