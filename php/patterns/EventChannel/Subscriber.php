<?php

class Subscriber {
	private $name;

	public function __construct( string $name ) {
		$this->name = $name;
	}

	public function notify( string $product ): void {
		echo "{$this->name} was notified about: $product\n";
	}

	public function subscribeTo( string $product, EventChannel $channel ): void {
		$channel->subscribe( $product, $this );
		echo "{$this->name} subscribed to $product notifications.\n";
	}
}

