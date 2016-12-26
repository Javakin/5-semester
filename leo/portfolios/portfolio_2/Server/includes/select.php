<?php

$servername = "172.17.0.3";

$username   = "phpuser";

$password   = "password";

$dbname     = "abookdb";



// Create connection

$conn = new mysqli($servername, $username, $password, $dbname);



// Check connection

if ($conn->connect_error) {

	die("Connection failed: " . $conn->connect_error);

} 



$sql = "SELECT * FROM addressbook;"; 



$result = $conn->query($sql);



if ($result->num_rows > 0) {

	while($row = $result->fetch_assoc()) {

		echo "ID: " . $row["equip_id"] . " - Name: " . $row["name"] . " - Address: " . $row["address"] . "<br>";

	}

} else {

	echo "0 results";

}



$conn->close();

?>
