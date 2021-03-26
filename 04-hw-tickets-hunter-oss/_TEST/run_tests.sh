#!/bin/bash

echo '\033[0;33m'"###################################################################" '\033[m'
echo '\033[0;33m'"The following should produce the correct output" '\033[m'
echo '\033[0;33m'"###################################################################" '\033[m'
echo _TEST/violations.txt ab112233| _TEST/a.out
echo
echo _TEST/violations.txt aB112233| _TEST/a.out
echo
echo _TEST/violations.txt Ty123456| _TEST/a.out
echo
echo _TEST/violations.txt cd987098| _TEST/a.out
echo
echo _TEST/violations.txt AB987098| _TEST/a.out
echo
echo '\033[0;33m'"###################################################################" '\033[m'
echo '\033[0;33m'"The following should produce errors" '\033[m'
echo '\033[0;33m'"###################################################################" '\033[m'
echo doesNotExist.txt ab112233| _TEST/a.out
echo
echo _TEST/violations.txt ccd987098| _TEST/a.out
echo
echo _TEST/violations.txt cd97098| _TEST/a.out
echo
echo _TEST/violations.txt 987098| _TEST/a.out
echo
echo _TEST/violations.txt AB9870984| _TEST/a.out
echo
echo _TEST/violations.txt 123| _TEST/a.out
echo


