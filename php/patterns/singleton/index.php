<?

class Logger {
	private static $instance = null;
	private $logs = [];

	private function __construct() {
	}

	private function __clone() {
	}

	private function __wakeup() {
	}

	public static function getInstance(): Logger {
		if ( self::$instance === null ) {
			self::$instance = new Logger();
		}
		return self::$instance;
	}

	public function log( $message ) {
		$this->logs[] = $message;
	}

	public function getLogs(): array {
		return $this->logs;
	}
}

$logger1 = Logger::getInstance();
$logger1->log( "This is the first log message." );

$logger2 = Logger::getInstance();
$logger2->log( "This is the second log message." );

echo "Logger 1 Logs: " . implode( ", ", $logger1->getLogs() ) . "\n";
echo "Logger 2 Logs: " . implode( ", ", $logger2->getLogs() ) . "\n";

?>

<!DOCTYPE html>
<html lang="en">

<head>
	<meta charset="UTF-8">
	<meta name="viewport">
	<title>Document</title>
</head>

<body>
	<?

	?>
</body>

</html>