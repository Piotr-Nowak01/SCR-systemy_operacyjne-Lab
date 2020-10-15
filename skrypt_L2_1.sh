#!/bin/bash
LC_ALL=C
if [ $(date+%u) -gt 5 ]
then
	echo "Dzien wolny"
else
	echo "Dzien pracujacy"
fi