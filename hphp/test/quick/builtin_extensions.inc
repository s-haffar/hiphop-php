<?php

function test($cls) {
  echo $cls . "\n";
  $a = new $cls;
  var_dump($a);
  if ($a instanceof Closure || $a instanceof Continuation) {
    continue;
  }
  // serialize and unserialize
  $b = serialize($a);
  var_dump($b);
  $c = unserialize($b);
  var_dump($c);
  if ($a != $c) {
    echo "bad serialization/deserialization\n";
    exit(1);
  }
  // get class methods
  var_dump(get_class_methods($a));

  echo "================\n";

  $cls = 'A_' . $cls;
  echo $cls . "\n";
  $a = new $cls;
  var_dump($a);
  if ($a instanceof Closure || $a instanceof Continuation) {
    continue;
  }
  // serialize and unserialize
  $b = serialize($a);
  var_dump($b);
  $c = unserialize($b);
  var_dump($c);
  if ($a != $c) {
    echo "bad serialization/deserialization\n";
    exit(1);
  }
  // get class methods
  var_dump(get_class_methods($a));
}
