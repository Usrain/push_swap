_This project has been created as part of the 42 curriculum by malebrun._

# Description

Push swap is a program that sorts a stack using a limited set of instructions.

# Instructions

To compile the project :

```make
make
```
To use the program :

```bash
./push_swap <number> [<number>] [<"number [number]">] [...]
```
# Technical choice

This push_swap uses first search for the longest increasing sequence in every circular rotation of the stack then calculate the cost to push every value that is not in the LIS to sort in the most efficient way, see more in [resource section](#rescources)

# Resources

https://www.geeksforgeeks.org/c/implement-stack-in-c/ was used to understand how stacks works

# Understand the return

The instrucitons are :

sa (swap a): Swap the first 2 elements at the top of stack a.
    Do nothing if there is only one element or none.

sb (swap b): Swap the first 2 elements at the top of stack b.
    Do nothing if there is only one element or none.https://www.geeksforgeeks.org/c/implement-stack-in-c/

ss : sa and sb at the same time.

pa (push a): Take the first element at the top of b and put it at the top of a.
    Do nothing if b is empty.

pb (push b): Take the first element at the top of a and put it at the top of b.
    Do nothing if a is empty.

ra (rotate a): Shift up all elements of stack a by 1.
    The first element becomes the last one.

rb (rotate b): Shift up all elements of stack b by 1.
    The first element becomes the last one.

rr : ra and rb at the same time.

rra (reverse rotate a): Shift down all elements of stack a by 1.
    The last element becomes the first one.

rrb (reverse rotate b): Shift down all elements of stack b by 1.
    The last element becomes the first one.

rrr : rra and rrb at the same time

# checker (bonus)

Checker is a program that allow you to verify ./push_swap return value

To compile the program :
```make
make bonus
```
To use the program :

```bash
./checker <number> [<number>] [<"number [number]">] [...]
```

it will then open you the prompt to enter your instruction, each instruction need to be on its own line, then press ctrl + D to test your instructions
