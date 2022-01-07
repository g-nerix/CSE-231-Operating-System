#!/bin/bash

# PROBLEM STATEMENT :

# Write a bash script that takes two arguments as command-line arguments 
# for the above arithmetic operations (add, sub, mul, div and exp). 
# The first argument should be the name of the operations, 
# ie. -- ‘add’, ‘sub’, ‘div’, and ‘exp’. The subsequent arguments should 
# be two (or more) operands. Thus, depending upon the operations requested, 
# you may call the appropriate function (bash subroutine), which should 
# perform the corresponding arithmetic operation, using the supplied arguments. 

# How to use:
# - Nagivate to the folder containing Q1.sh in the terminal
# - Type "chmod +x Q2.sh" in terminal.
# - Type "./Q2.sh [operator] [argument 1] [argument 2]".
    # EXAMPLE : 
        # ./Q2.sh add 1 2
        # ./Q2.sh sub 1 2
        # ./Q2.sh mul 1 2
        # ./Q2.sh div 4 2
        # ./Q2.sh exp 8 2

case "$1" in
    #case 1
    "add") echo "[Sum] = $2 + $3 = $(($2+$3))";;
      
    #case 2
    "sub") echo "[Difference] = $2 - $3 = $(($2-$3))";;
      
    #case 3
    "mul") echo "[Product] = $2 * $3 = $(($2*$3))";;
    
    #case 4
    "div") echo "[Quotient] = $2 / $3 = $(($2/$3))";;
    
    #case 5
    "exp") echo "[Exponent] = $2 ^ $3 = $(($2**$3))";;

esac
