#!/bin/bash
# RPN tester. Put it next to your RPN binary and run: bash test.sh
# Valid cases:  stdout must match exactly, stderr must be empty.
# Error cases:  stdout must be empty, stderr must contain "Error".

BIN=./RPN
PASS=0
FAIL=0
GREEN='\033[32m'; RED='\033[31m'; YELLOW='\033[33m'; RESET='\033[0m'

if [ ! -x "$BIN" ]; then
    echo "No executable $BIN here. Run make first."
    exit 1
fi

# ok "<expression>" "<expected stdout>"
ok() {
    local out err
    out=$("$BIN" "$1" 2>/tmp/rpn_err)
    err=$(cat /tmp/rpn_err)
    if [ "$out" == "$2" ] && [ -z "$err" ]; then
        PASS=$((PASS + 1))
        printf "${GREEN}OK${RESET}   %-45s → %s\n" "\"$1\"" "$out"
    else
        FAIL=$((FAIL + 1))
        printf "${RED}FAIL${RESET} %-45s expected '%s', got stdout '%s' stderr '%s'\n" "\"$1\"" "$2" "$out" "$err"
    fi
}

# ko <args...>   (expects an error; takes raw args so we can test argc too)
ko() {
    local out err label
    out=$("$BIN" "$@" 2>/tmp/rpn_err)
    err=$(cat /tmp/rpn_err)
    label=$(printf '"%s" ' "$@")
    [ $# -eq 0 ] && label="(no argument)"
    if [ -z "$out" ] && [[ "$err" == *Error* ]]; then
        PASS=$((PASS + 1))
        printf "${GREEN}OK${RESET}   %-45s → stderr: %s\n" "$label" "$err"
    else
        FAIL=$((FAIL + 1))
        printf "${RED}FAIL${RESET} %-45s expected Error on stderr, got stdout '%s' stderr '%s'\n" "$label" "$out" "$err"
    fi
}

echo "=== should work ==="
ok "8 9 * 9 - 9 - 9 - 4 - 1 +" "42"
ok "7 7 * 7 -"                  "42"
ok "1 2 * 2 / 2 * 2 4 - +"      "0"
ok "5"                          "5"
ok "0"                          "0"
ok "1 2 -"                      "-1"
ok "7 2 -"                      "5"
ok "2 7 /"                      "0"
ok "7 2 /"                      "3"
ok "1 2 - 3 /"                  "0"
ok "3 4 2 * +"                  "11"
ok "   1    2   +   "           "3"
ok "9 9 * 9 * 9 * 9 * 9 * 9 * 9 * 9 * 9 *" "3486784401"

echo
echo "=== must be Error ==="
ko ""
ko "    "
ko "+"
ko "1 +"
ko "+ 1 2"
ko "1 2"
ko "1 2 3 +"
ko "1 0 /"
ko "5 1 1 - /"
ko "1 2 ++"
ko "-1 2 +"
ko "1.5 2 +"
ko "(1 + 1)"
ko "1 2 x"
ko $'1\t2 +'
ko
ko "1" "2"

echo
echo "=== your decision (no pass/fail) ==="
BIG="9"; for i in $(seq 1 20); do BIG="$BIG 9 *"; done
printf "${YELLOW}INFO${RESET} 9^21 (overflows long): stdout '%s' stderr '%s'\n" \
    "$("$BIN" "$BIG" 2>/tmp/rpn_err)" "$(cat /tmp/rpn_err)"

rm -f /tmp/rpn_err
echo
echo "passed: $PASS   failed: $FAIL"
[ $FAIL -eq 0 ]