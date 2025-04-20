#!/bin/bash

EXEC=./bin/push_swap

GREEN="\033[0;32m"
RED="\033[0;31m"
YELLOW="\033[1;33m"
RESET="\033[0m"

pass() {
    echo -e "${GREEN}✔ PASS${RESET}"
}

valgrind_check() {
    echo -e "$YELLOW[VALGRIND CHECK]$RESET '$*'"
    valgrind --leak-check=full --error-exitcode=42 $EXEC "$@" > /dev/null 2>&1
    if [ $? -eq 42 ]; then
        echo -e "${RED}✘ MEMORY LEAK DETECTED${RESET}"
        fail
    else
        echo -e "${GREEN}✔ NO MEMORY LEAK${RESET}"
        pass
    fi
}

fail() {
    echo -e "${RED}✘ FAIL${RESET}"
}

error_expected() {
    OUTPUT=$($EXEC "$@" 2>&1)
    if [ "$OUTPUT" == "Error" ]; then
        pass
    else
        echo -e "$YELLOW[UNEXPECTED OUTPUT]$RESET '$*' → Got: '$OUTPUT'"
        fail
    fi
}

error_expected_blank() {
    OUTPUT=$($EXEC "$@" 2>&1)
    if [ -z "$OUTPUT" ]; then
        pass
    else
        echo -e "$YELLOW[UNEXPECTED NON-BLANK OUTPUT]$RESET '$*' → Got: '$OUTPUT'"
        fail
    fi
}

success_expected() {
    if $EXEC "$@" > /dev/null 2>&1; then
        echo -e "$YELLOW[VALID INPUT]$RESET '$*'"
        pass
    else
        echo -e "$YELLOW[UNEXPECTED ERROR]$RESET '$*'"
        fail
    fi
}

echo -e "\n${YELLOW}=== TESTING VALID INPUTS ===${RESET}"
echo -e "\n${YELLOW}=== VALGRIND MEMORY LEAK CHECK ===${RESET}"
success_expected 3 2 1
valgrind_check 3 2 1
success_expected 1 0 -1
valgrind_check 1 0 -1
success_expected -5 42 0 13 -999
valgrind_check -5 42 0 13 -999
success_expected 2147483647 -2147483648
valgrind_check 2147483647 -2147483648
success_expected 001 002 -003
valgrind_check 001 002 -003

echo -e "\n${YELLOW}=== TESTING INVALID FORMATS ===${RESET}"
error_expected 3 '' 4
error_expected 3 ' ' 4
error_expected 3 4 " "
error_expected " " 3 ' ' 4
error_expected " " 3 '' " " 4
error_expected 3 2 1 --1
error_expected 2 3 4 --42
error_expected 3 2 4 ++42
error_expected 2 4 3 -+42
error_expected 3 2 4 +-42
error_expected 32 1 2 42-
error_expected 3.14 2
error_expected 42a 33
error_expected "  " 3 5 4
error_expected - 42
error_expected 42 - 43

echo -e "\n${YELLOW}=== TESTING DUPLICATES ===${RESET}"
error_expected 2 3 2

echo -e "\n${YELLOW}=== TESTING INT LIMITS ===${RESET}"
success_expected 2147483647 2 3
valgrind_check 2147483647 2 3
success_expected -2147483648 2 3
valgrind_check -2147483648 2 3
error_expected_blank 2147483648
error_expected_blank -2147483649

echo -e "\n${YELLOW}=== TESTING SPLIT ARGS ===${RESET}"
success_expected 1 3 2 4 5
valgrind_check 1 3 2 4 5
success_expected 1 3 "9 7 8"
valgrind_check 1 3 "9 7 8"
success_expected "3 2" "4 5" 6 7
valgrind_check "3 2" "4 5" 6 7
success_expected "1" "2" "3"
valgrind_check "1" "2" "3"
error_expected 1 ++3 4

echo -e "\n${YELLOW}=== ALL TESTS DONE ===${RESET}"
