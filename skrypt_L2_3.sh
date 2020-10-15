#!/bin/bash
maska=$1
czas=$2
nazwa=$3
while [ $czas -gt 0 ]
do
	find ./ -name "*.$maska" -mtime -$czas -exec tar -rvf $nazwa.tar {} \;
	czas=$((czas-1))
done  