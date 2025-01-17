<?php
interface Button {
	public function render();
}

interface Checkbox {
	public function check();
}

class LightButton implements Button {
	public function render() {
		echo "Light Button Rendered\n";
	}
}

class LightCheckbox implements Checkbox {
	public function check() {
		echo "Light Checkbox Checked\n";
	}
}

class DarkButton implements Button {
	public function render() {
		echo "Dark Button Rendered\n";
	}
}

class DarkCheckbox implements Checkbox {
	public function check() {
		echo "Dark Checkbox Checked\n";
	}
}

interface UIFactory {
	public function createButton(): Button;
	public function createCheckbox(): Checkbox;
}

class LightThemeFactory implements UIFactory {
	public function createButton(): Button {
		return new LightButton();
	}

	public function createCheckbox(): Checkbox {
		return new LightCheckbox();
	}
}

class DarkThemeFactory implements UIFactory {
	public function createButton(): Button {
		return new DarkButton();
	}

	public function createCheckbox(): Checkbox {
		return new DarkCheckbox();
	}
}

function renderUI( UIFactory $factory ) {
	$button = $factory->createButton();
	$checkbox = $factory->createCheckbox();
	$button->render();
	$checkbox->check();
}

$lightFactory = new LightThemeFactory();
$darkFactory = new DarkThemeFactory();

echo "Using Light Theme: ";
renderUI( $lightFactory );
echo "\nUsing Dark Theme: ";
renderUI( $darkFactory );
