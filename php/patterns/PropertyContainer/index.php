<?php

class PropertyContainer {
	protected $properties = [];

	public function addProperty( $property, $value ) {
		if ( isset( $this->properties[ $property ] ) ) {
			throw new Exception( "Property '$property' already exists, to change the value, use updateProperty method." );
		}
		$this->properties[ $property ] = $value;
	}

	public function deleteProperty( $property ) {
		if ( empty( $this->properties[ $property ] ) ) {
			throw new Exception( "Property '$property' does not exist." );
		}
		unset( $this->properties[ $property ] );
	}

	public function getProperty( $property ) {
		return $this->properties[ $property ] ?? null;
	}

	public function updateProperty( $property, $value ) {
		if ( empty( $this->properties[ $property ] ) ) {
			throw new Exception( "Property '$property' does not exist." );
		}
		$this->properties[ $property ] = $value;
	}
}

class Character extends PropertyContainer {
	private $name;
	public function __construct( $name ) {
		$this->name = $name;
	}
	public function displayName() {
		echo "Character name: $this->name\n";
	}
	public function displayProperties() {
		foreach ( $this->properties as $property => $value ) {
			echo "$property: $value \n";
		}
	}

	public function displayInfo() {
		echo "Character name: $this->name\n";
		foreach ( $this->properties as $property => $value ) {
			echo "$property: $value \n";
		}
	}
}

$aboba = new Character( "Aboba" );
$aboba->addProperty( "Health", 500 );
$aboba->addProperty( "Mana", 2 );
$aboba->addProperty( "Strength", 15 );
$aboba->addProperty( "Agility", 3 );
$aboba->addProperty( "Intelligence", -1 );

$aboba->displayInfo();

$aboba->updateProperty( "Health", 432 );
$aboba->deleteProperty( "Intelligence" );

$aboba->displayInfo();

$abobahp = $aboba->getProperty( "Health" );
echo "Character aboba health: $abobahp HP";
