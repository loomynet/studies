<?php

interface TextFormatter {
	public function format( string $text ): string;
}

class UpperCaseFormatter implements TextFormatter {
	public function format( string $text ): string {
		return strtoupper( $text );
	}
}

class LowerCaseFormatter implements TextFormatter {
	public function format( string $text ): string {
		return strtolower( $text );
	}
}

class TitleCaseFormatter implements TextFormatter {
	public function format( string $text ): string {
		return ucwords( $text, " \t\r\n\f\v'" );
	}
}

class TextEditor {
	private TextFormatter $formatter;

	public function setFormatter( TextFormatter $formatter ): void {
		$this->formatter = $formatter;
	}

	public function formatText( string $text ): string {
		return $this->formatter->format( $text );
	}
}

$textEditor = new TextEditor();

$text = "Hello World!";

$textEditor->setFormatter( new UpperCaseFormatter() );
echo $textEditor->formatText( $text ) . "\n";

$textEditor->setFormatter( new LowerCaseFormatter() );
echo $textEditor->formatText( $text ) . "\n";

$textEditor->setFormatter( new TitleCaseFormatter() );
echo $textEditor->formatText( $text ) . "\n";
