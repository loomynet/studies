<?php

abstract class SocialNetworkPoster {
	abstract public function getSocialNetwork(): SocialNetworkConnector;

	public function post( $content ): void {
		$network = $this->getSocialNetwork();
		$network->logIn();
		$network->createPost( $content );
		$network->logout();
	}
}

class FacebookPoster extends SocialNetworkPoster {
	private $login, $password;

	public function __construct( string $login, string $password ) {
		$this->login = $login;
		$this->password = $password;
	}

	public function getSocialNetwork(): SocialNetworkConnector {
		return new FacebookConnector( $this->login, $this->password );
	}
}

class LinkedInPoster extends SocialNetworkPoster {
	private $email, $password;

	public function __construct( string $email, string $password ) {
		$this->email = $email;
		$this->password = $password;
	}

	public function getSocialNetwork(): SocialNetworkConnector {
		return new LinkedInConnector( $this->email, $this->password );
	}
}

interface SocialNetworkConnector {
	public function logIn(): void;

	public function logOut(): void;

	public function createPost( $content ): void;
}

class FacebookConnector implements SocialNetworkConnector {
	private $login, $password;

	public function __construct( string $login, string $password ) {
		$this->login = $login;
		$this->password = $password;
	}

	public function logIn(): void {
		echo "Send HTTP API request to log in user $this->login with " .
			"password $this->password\n<br>";
	}

	public function logOut(): void {
		echo "Send HTTP API request to log out user $this->login\n<br>";
	}

	public function createPost( $content ): void {
		echo "Send HTTP API requests to create a post in Facebook timeline.\n<br>";
	}
}

class LinkedInConnector implements SocialNetworkConnector {
	private $email, $password;

	public function __construct( string $email, string $password ) {
		$this->email = $email;
		$this->password = $password;
	}

	public function logIn(): void {
		echo "Send HTTP API request to log in user $this->email with " .
			"password $this->password\n<br>";
	}

	public function logOut(): void {
		echo "Send HTTP API request to log out user $this->email\n<br>";
	}

	public function createPost( $content ): void {
		echo "Send HTTP API requests to create a post in LinkedIn timeline.\n<br>";
	}
}

function clientCode( SocialNetworkPoster $creator ) {
	$creator->post( "Hello world!" );
	$creator->post( "I had a large hamburger this morning!" );
}

?>

<!DOCTYPE html>
<html lang="en">

<head>
	<meta charset="UTF-8">
	<meta name="viewport">
	<title>Document</title>
</head>

<body>
	<?php
	echo "Testing ConcreteCreator1:\n<br>";
	clientCode( new FacebookPoster( "john_smith", "******" ) );
	echo "\n\n<br><br>";
	echo "Testing ConcreteCreator2:\n<br>";
	clientCode( new LinkedInPoster( "john_smith@example.com", "******" ) );
	?>
</body>

</html>