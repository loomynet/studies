<?php

include_once 'Subscriber.php';
include_once 'Publisher.php';

class EventChannel {
	private $subscribers = [];

	public function subscribe( string $product, Subscriber $subscriber ): void {
		$this->subscribers[ $product ][] = $subscriber;
	}

	public function publish( string $product, Publisher $publisher ): void {
		if ( ! empty( $this->subscribers[ $product ] ) ) {
			foreach ( $this->subscribers[ $product ] as $subscriber ) {
				$subscriber->notify( $product );
			}
		}
	}
}

