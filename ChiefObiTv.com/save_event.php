<?php
require_once("db.php");
require_once("functions.php");
  $name = mysqli_real_escape_string($connection, $_POST['name']);
  $location = mysqli_real_escape_string($connection, $_POST['location']);
  $phone = mysqli_real_escape_string($connection, $_POST['phone']);
  $email = mysqli_real_escape_string($connection, $_POST['email']);
  $date =mysqli_real_escape_string($connection, $_POST['date']);
  $event = mysqli_real_escape_string($connection, $_POST['events']);
  if(empty($_POST['notes'])){
    $notes = "No Notes";
  }else{
    $notes =mysqli_real_escape_string($connection, $_POST['notes']);
  }
  $to = "imorobebh@gmail.com";
  $subject = "New Booking";
  $body = "A new booking was made on ChiefObiTv. Here are the details.<br><br><br>Client: ".$name."<br>Phone: ".$phone."<br>Email: ".$email."<br>Event Location: ".$location."<br>Title of Event: ".$event."<br>";
  Send_Mail('bookings@chiefobitv.com',$subject,$body);
  $query = "INSERT INTO events(name, phone, email, title, location, event_date, notes) VALUES('{$name}','{$phone}','{$email}','{$event}','{$location}','{$date}','{$notes}')";
  $save_query = mysqli_query($connection, $query);
?>
<h2 class='title'>Thank You, <?php echo $name ?>. Your Booking Has Been Saved.</h2>
