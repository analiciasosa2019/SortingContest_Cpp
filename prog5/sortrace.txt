# Analicia Sosa
# CECS325-02
# Prog5 Threads
# 04/06/2023
#
# I certify that this program is my own original work. I did not copy any part of this program from
# any other source. I further certify that I typed each and every line of code in this program.

############################################################
#include <fstream>
#include <iostream>
#include <thread>
# this file should be called sortrace.sh Please rename it
# it must have execute privilege set to run
# run it as a background task like this:
# $ rm sortrace.log # start with fresh log file
# $ sortrace.sh >> sortrace.log & # run in the background
############################################################
echo My machine has this many processors
nproc # this is for windows machines
echo Generating 1000000 random numbers
sleep 1
generate 1000000 100000 999999 # you have to write generate.cpp
sleep 1
echo Starting system sort
sleep 1
{ time sort numbers.dat > systemsort.out; } 2>> sortrace.log
sleep 1
echo Starting my sort
sleep 1
{ time mysort numbers.dat > mysort.out; } 2>> sortrace.log # you have to
sleep 1
sort -c mysort.out 2>> sortrace.log # verify file is sorted
echo All done
