<?php



// Sanitize $data

function test_input($data) {

  $data = trim($data);

  $data = stripslashes($data);

  $data = htmlspecialchars($data);

  return $data;

}



// define variables and set to empty values

$nameErr = $addressErr = "";

$name = $address = "";



// If submit button has been pushed

if ($_SERVER["REQUEST_METHOD"] == "POST") {

  if (empty($_POST["name"])) {

    $nameErr = "Name is required";

  } else {

    $name = test_input($_POST["name"]);

    // check if name only contains letters and whitespace

    if (!preg_match("/^[a-zA-Z ]*$/",$name)) {

      $nameErr = "Only letters and white space allowed"; 

    }

  }



  if (empty($_POST["address"])) {

    $addressErr = "Address is required";

  } else {

    $address = test_input($_POST["address"]);

    // check if name only contains letters and whitespace

    if (!preg_match("/^[a-zA-Z0-9,. ]*$/", $address)) {

      $addressErr = "Only letters and white space allowed"; 

    }

  }



  if (empty($nameErr) and empty($addressErr)) {

    $servername = "127.0.0.3";

    $username   = "ubuntu";

    $password   = "";
    
    //$servername = "172.17.0.3";
    //$username   = "phpuser";
    //$password   = "password";

    $dbname     = "abookdb";



    // Create connection

    $conn = new mysqli($servername, $username, $password, $dbname);



    // Check connection

    if ($conn->connect_error) {

      die("Connection failed: " . $conn->connect_error);

    }



    $sql = "INSERT INTO addressbook (name, address) VALUES ('" . $_POST["name"] . "', '" . $_POST["address"] . "');";



    if (mysqli_query($conn, $sql)) {

      echo "New record created successfully";

    } else {

      echo "Error: " . $sql . "<br>" . mysqli_error($conn);

    }



    mysqli_close($conn);

    $name = $address = "";

  }

}

?>



<h2>Address book submission form</h2>

<form method="post" action="<?php echo htmlspecialchars($_SERVER["PHP_SELF"]);?>">  

  Name: <input type="text" name="name" value="<?php echo $name;?>">

  <span class="error"> *<?php echo $nameErr;?></span>

  <br><br>

  Address: <input type="text" name="address" value="<?php echo $address;?>">

  <span class="error"> *<?php echo $addressErr;?></span>

  <br><br>

  <input type="submit" name="submit" value="Submit">  

</form>


