<?php
require 'PHPMailerAutoload.php';
function Send_Mail($to,$subject,$body)
{
$from       = "bookings@Chiefobitv.com";
$mail       = new PHPMailer();
$mail->IsHTML(true);
$mail->SMTPAuth   = false;                  // enable SMTP authentication
$mail->Host       = "localhost"; // SMTP host
$mail->Port       = 25;                    // set the SMTP port
$mail->SetFrom($from, 'ChiefObiTv');
$mail->AddReplyTo($from,'ChiefObiTv');
$mail->Subject    = $subject;
$mail->MsgHTML($body);
$address = $to;
$mail->AddAddress($address, $to);
if (!$mail->send()) {
    echo "Mailer Error: " . $mail->ErrorInfo;
}
}
 ?>
