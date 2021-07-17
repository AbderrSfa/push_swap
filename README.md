# Description

The aim of this project is to sort a stack of numbers, using a limited set of instructions, and the lowest possible number of actions. You will have to look into different types of algorithms and choose the most appropriate one for an optimized solution.

## Synopsis
**push_swap** is a straigh-forward and effective algorithm project: There is data. Said data needs to be sorted.
You have a set of integers, 2 stacks (stack a, and stack b) and a set of instructions to manipulate both stacks.

This project contains 2 programs:

The first, called **push_swap** which will receive a list of integers as arguments. The program must display the smallest list of instructions possible to sort the stack a, the smallest number being at the top.

The second one, **checker** (which is a bonus part of the project), also takes a list of integers and will read instructions on the standard input. Once read,checker executes them and displays OK if the entered insturctions result in the integers being properly sorted. Otherwise, it will display KO.

## push_swap instructions
**sa:** swap a - swap the first 2 elements at the top of stack a. Do nothing if there is only one or no elements.

**sb:** swap b - swap the first 2 elements at the top of stack b. Do nothing if there is only one or no elements.

**ss:** sa and sb at the same time.

**pa:** push a - take the first element at the top of b and put it at the top of a. Do nothing if b is empty.

**pb:** push b - take the first element at the top of a and put it at the top of b. Do nothing if a is empty.

**ra:** rotate a - shift up all elements of stack a by 1. The first element becomes the last one.

**rb:** rotate b - shift up all elements of stack b by 1. The first element becomes the last one.

**rr:** ra and rb at the same time.

**rra:** reverse rotate a - shift down all elements of stack a by 1. The last element becomes the first one.

**rrb:** reverse rotate b - shift down all elements of stack b by 1. The last element becomes the first one.

**rrr:** rra and rrb at the same time.

# Compilation
To compile checker, run:

`make checker`

To compile push_swap, run:

`make push_swap`

To compile both, run:

`make`

# Usage
### push_swap
Example: `./push_swap -9 8 3 20 -5`

### checker
Exapmle: `./checker -9 8 3 20 -5` then will wait for your input

### Both
To execute both push_swap and checker: `./push_swap -9 8 3 20 -5 | ./checker -9 8 3 20 -5`

About
This project will make you sort data on a stack, with a limited set of instructions, using the lowest possible number of actions. To succeed you’ll have to manipulate various types of algorithms and choose the one (of many) most appropriate solution for an optimized data sorting

c checker algo 42 1337 pushswap 42cursus sort-data
