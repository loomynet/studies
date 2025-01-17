<?php
class Meal {
	private $items = [];

	public function addItem( $item ) {
		$this->items[] = $item;
	}
	public function showItems() {
		foreach ( $this->items as $item ) {
			echo $item . "\n";
		}
	}
}

interface MealBuilder {
	public function addMainItem();
	public function addDrink();
	public function addDessert();
	public function getMeal(): Meal;
}

class VegetarianMealBuilder implements MealBuilder {
	private $meal;

	public function __construct() {
		$this->meal = new Meal();
	}

	public function addMainItem() {
		$this->meal->addItem( "Vegetarian Burger" );
	}

	public function addDrink() {
		$this->meal->addItem( "Orange Juice" );
	}

	public function addDessert() {
		$this->meal->addItem( "Fruit Salad" );
	}

	public function getMeal(): Meal {
		return $this->meal;
	}
}

class NonVegetarianMealBuilder implements MealBuilder {
	private $meal;

	public function __construct() {
		$this->meal = new Meal();
	}

	public function addMainItem() {
		$this->meal->addItem( "Chicken Burger" );
	}

	public function addDrink() {
		$this->meal->addItem( "Coca Cola" );
	}

	public function addDessert() {
		$this->meal->addItem( "Ice Cream" );
	}

	public function getMeal(): Meal {
		return $this->meal;
	}
}

class MealDirector {
	private $builder;

	public function __construct( MealBuilder $builder ) {
		$this->builder = $builder;
	}
	public function buildMeal() {
		$this->builder->addMainItem();
		$this->builder->addDrink();
		$this->builder->addDessert();
	}
	public function getMeal(): Meal {
		return $this->builder->getMeal();
	}
}

echo "Vegetarian Meal:\n";
$vegBuilder = new VegetarianMealBuilder();
$vegDirector = new MealDirector( $vegBuilder );
$vegDirector->buildMeal();
$vegMeal = $vegDirector->getMeal();
$vegMeal->showItems();

echo "\nNon-Vegetarian Meal:\n";
$nonVegBuilder = new NonVegetarianMealBuilder();
$nonVegDirector = new MealDirector( $nonVegBuilder );
$nonVegDirector->buildMeal();
$nonVegMeal = $nonVegDirector->getMeal();
$nonVegMeal->showItems();

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