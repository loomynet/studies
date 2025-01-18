<?php

include_once 'EventChannel.php';

$store = new EventChannel();

$appleSupplier = new Publisher( "Apple Supplier" );
$bananaSupplier = new Publisher( "Banana Supplier" );

$customer1 = new Subscriber( "Sansa" );
$customer2 = new Subscriber( "Arya" );
$customer3 = new Subscriber( "John" );

$customer1->subscribeTo( "Apples", $store );
$customer2->subscribeTo( "Bananas", $store );
$customer3->subscribeTo( "Potatoes", $store );

$appleSupplier->publish( "Apples", $store );
$bananaSupplier->publish( "Bananas", $store );
