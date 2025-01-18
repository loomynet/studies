<?php

include_once 'EventChannel.php';

class Publisher {
	private $name;

	public function __construct( string $name ) {
		$this->name = $name;
	}

	public function publish( string $product, EventChannel $channel ): void {
		echo "{$this->name} published: $product\n";
		$channel->publish( $product, $this );
	}
}

