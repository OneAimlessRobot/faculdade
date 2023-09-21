#!/bin/bash

numLines=120
thisdate="$(date -u +"%d-%m-%y")"

mkdir $thisdate

cd $thisdate

nano  -r $numLines -l -J $numLines -b "notas"
