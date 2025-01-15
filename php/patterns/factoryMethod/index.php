<?php
interface Notification {
	public function send( $message );
}

class EmailNotification implements Notification {
	public function send( $message ) {
		echo "Email sent: $message\n";
	}
}

class SMSNotification implements Notification {
	public function send( $message ) {
		echo "SMS sent: $message\n";
	}
}

abstract class NotificationFactory {
	abstract public function createNotification(): Notification;
}

class EmailNotificationFactory extends NotificationFactory {
	public function createNotification(): Notification {
		return new EmailNotification();
	}
}

class SMSNotificationFactory extends NotificationFactory {
	public function createNotification(): Notification {
		return new SMSNotification();
	}
}

function notifyUser( NotificationFactory $factory, $message ) {
	$notification = $factory->createNotification();
	$notification->send( $message );
}

$emailFactory = new EmailNotificationFactory();
$smsFactory = new SMSNotificationFactory();

?>

<!DOCTYPE html>
<html lang="en">

<head>
	<meta charset="UTF-8">
	<meta name="viewport">
	<title>Test</title>
	<link rel="icon" type="image/jpg" href="img/photo_2025-01-14_21-09-58.jpg">
</head>

<body>
	<?php notifyUser( $emailFactory, "Hello via Email!" ); ?>
	<br>
	<?php notifyUser( $smsFactory, "Hello via SMS!" ); ?>
</body>

</html>