<?php

interface Shape {
	public function clone(): Shape;
	public function getType(): string;
}

class Circle implements Shape {
	private $radius;

	public function __construct( $radius ) {
		$this->radius = $radius;
	}

	public function setRadius( $radius ) {
		$this->radius = $radius;
	}

	public function clone(): Shape {
		return new Circle( $this->radius );
	}

	public function getType(): string {
		return "Circle with radius {$this->radius}";
	}
}

class Rectangle implements Shape {
	private $width;
	private $height;

	public function __construct( $width, $height ) {
		$this->width = $width;
		$this->height = $height;
	}

	public function setDimensions( $width, $height ) {
		$this->width = $width;
		$this->height = $height;
	}

	public function clone(): Shape {
		return new Rectangle( $this->width, $this->height );
	}

	public function getType(): string {
		return "Rectangle with dimensions {$this->width}x{$this->height}";
	}
}

$circlePrototype = new Circle( 5 );
$rectanglePrototype = new Rectangle( 10, 20 );

$circle1 = $circlePrototype->clone();
$circle2 = $circlePrototype->clone();

$rectangle1 = $rectanglePrototype->clone();

echo $circle1->getType() . "\n";
echo $circle2->getType() . "\n";
echo $rectangle1->getType() . "\n";


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