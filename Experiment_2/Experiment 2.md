# Experiment 2: Identifying an Identifier and Classify It as Variable, Array, or Function

**Aim:** To design and implement a transition diagram that recognizes identifiers and classifies them into variable, array, or function.

## Design

> *Draw the transition diagram for identifying identifiers and classifying them as variable, array, or function.*

## Algorithm

1. Read first character.

2. If it is letter or `_`, go to S1.
   Else, reject.

3. Read remaining letters/digits/_.

4. Stay in S2.

5. When a delimiter is reached:

   - if next symbol is `[` , Array
   - else if next symbol is `(` , Function
   - else, Variable

## Program

> *Write the program here.*

## Output

> *Write the output here.*

## Result

The transition diagram for identifying identifiers was successfully designed and implemented using a finite automaton. The automaton correctly recognized valid identifiers and classified them as variables, arrays, or functions based on the subsequent symbol (`[`, `(`, or other delimiters). Invalid identifiers that did not satisfy the lexical rules were rejected successfully.