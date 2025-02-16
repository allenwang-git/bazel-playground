#!/bin/bash

set -e # Exit on error
cd "$(dirname "${BASH_SOURCE[0]}")" &> /dev/null

# Run the integration tests
echo "Running integration tests"
timeout=$1
rm -f ./tmp/c_sh_test ./tmp/cc_sh_test
mkdir -p ./tmp
touch ./tmp/c_sh_test ./tmp/cc_sh_test

# Run the C tests
timeout ${timeout}s ./c_sub >> ./tmp/c_sh_test &
timeout ${timeout}s ./c_pub >> ./tmp/c_sh_test &
wait
cat ./tmp/c_sh_test | grep "\[Subscriber\] Received : Message (1, Hello World)" # Check if the C tests passed
c_test_return_code=$?

echo "C Integration tests finished."
if [ $c_test_return_code -eq 0 ]; then
    echo "C Integration tests passed."
else
    echo "C Integration tests failed."
    cat ./tmp/c_sh_test
    exit 1
fi

# Run the C++ tests
timeout ${timeout}s ./cc_sub >> ./tmp/cc_sh_test &
timeout ${timeout}s ./cc_pub >> ./tmp/cc_sh_test &
wait
cat ./tmp/cc_sh_test | grep "\[Subscriber\] Message received: \[userID: 1, message: Hello World\]" # Check if the C++ tests passed

cc_return_code=$?
echo "CPP Integration tests finished."

if [ $cc_return_code -eq 0 ]; then
    echo "CPP Integration tests passed."
    exit 0
else
    echo "CPP Integration tests failed."
    cat ./tmp/cc_sh_test
    exit 1
fi
