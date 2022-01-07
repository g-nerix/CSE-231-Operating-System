#!/bin/bash

# Write a bash script to print the calendar for the entire month, given a date.

# How to use:
# - Nagivate to the folder containing Q1.sh in the terminal
# - Type "chmod +x Q1.sh" in terminal.
# - Type "./Q2.sh" and press Enter.

read -p "Enter Date : " dd 
read -p "Enter Month: " mm
read -p "Enter Year : " yy

ncal -31 -m $mm $yy
