#!/bin/bash

function test() {
  input=$1
  # expected
  echo $input | bash 1> ./expected/output

  # actual
  echo $input | ../minishell 1> ./actual/tmp
  cat ./actual/tmp | grep -v 'nukishell' > ./actual/output

  diff ./expected/output ./actual/output &> /dev/null
  result=$?
  if [ $result -eq 0 ]; then
    echo "OK: $input"
  else
    echo "KO: $input"
    diff ./expected/output ./actual/output > ./diff/diff
  fi
}

# init
rm -rf expected
rm -rf actual
rm -rf diff
mkdir expected
mkdir actual
mkdir diff

# test case
echo ---------------------------------------

test 'ls'
test '/bin/ls'
test '/bin/ls -a'

test 'echo hello'
test 'echo hello world'
echo ---------------------------------------
