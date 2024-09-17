<?php
include('index.php');
?>
<!DOCTYPE html>
<head>
    <title>

        <?php
        $var = 'PHP Tutorial';
        echo $var;
        ?>

    </title>
</head>

<body>

<h3> <?php echo $var; ?> </h3>

<p>PHP, an acronym for Hypertext Preprocessor, is a widely-used open source general-purpose scripting language. It is a cross-platform, HTML embedded server-side scripting language and is especially suited for web development.</p>
<a href='#'><?php echo $var; ?></a>

</body>
