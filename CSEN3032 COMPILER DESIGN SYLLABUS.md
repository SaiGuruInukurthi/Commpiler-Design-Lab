# CSEN3032 - Compiler Design Syllabus

| L | T | P | S | J | C |
|---|---|---|---|---|---|
| 3 | 0 | 2 | 0 | 0 | 4 |

**Pre-requisite:** None  
**Co-requisite:** None  
**Preferable Exposure:** None

## Course Description

Compilers play a significant role in fulfilling user's computing requirements, specified in terms of programs in a high-level language, which translate into machine-understandable form. The process involved in such a transformation of a program is quite complex. This course enables the students to gain knowledge on various phases involved in designing a compiler. Theory and Formal Languages provides the basis for this course in which several automated tools help construct various phases. Advanced computer architecture, memory management, and operating systems help the compiler designer generate efficient code.

## Course Educational Objectives

- Explore the basic techniques that underlie the principles, algorithms and data structures involved in the Compiler Construction.
- Gain experience in using automated tools that help in transforming various phases of the compiler.

## Syllabus

### UNIT 1 — Introduction & Lexical Analysis (9 Hrs)

Introduction: The Structure of Compiler, The Science of Building a Compiler in Bootstrapping and Cross compiler, Lexical Analysis: The role of the Lexical analyzer, Input Buffering, Specification of Tokens, Recognition of Tokens, The Lexical Analyzer Generator (LEX/FLEX)

### UNIT 2 — Syntax Analysis (Part-I) (9 Hrs)

Syntax Analysis (Part-I): Introduction, Context-Free Grammars, Top-Down parsing: Brute force Parsing, Recursive Descent Parsing, Non-recursive Predictive Parsing, Error Recovery in Predictive Parsing, Bottom-Up parsing - Shift Reduce Parsing.

### UNIT 3 — Syntax Analysis (Part-II) (9 Hrs)

Syntax Analysis (Part-II): Introduction to LR Parsing: Simple LR Parser, More Powerful LR Parsers (CLR & LALR), Using Ambiguous grammars, Error Recovery in LR Parsers, Parser Generator (YACC).

### UNIT 4 — Syntax Directed Translation and Intermediate Code Generation (9 Hrs)

Syntax Directed Translation: Syntax Directed Definitions, Types of attributes, Evaluation Orders for SDD's, Applications of Syntax-Directed Translation, Intermediate Code Generation: Three Address codes, Types & Declarations, Translation of Arithmetic Expressions

### UNIT 5 — Code Optimization & Code Generation (9 Hrs)

Code Optimization: The Principal Sources of Optimization, Basic blocks and Flow Graphs, Optimization of Basic Blocks, Introduction to Data-Flow Analysis: Live Variable Analysis Code, Generation: Issues in designing a code Generator, The Target Language, A Simple Code Generator, Peephole Optimization

## List of Experiments (30 hrs)

| S.No | Topic |
|------|-------|
| 1 | Implement transition diagram for identifying an identifier and classify whether it is variable, array, or function. |
| 2 | Implement transition diagram for identifying constant and classifying whether it is integer or real. |
| 3 | Write a LEX program to count the number of characters, words, lines, and blanks in the given input file. |
| 4 | Write a LEX program to recognize all the tokens in the given input file. Here the input file is having source code. |
| 5 | Write a program which reads CFG and checks for left recursion then display the CFG after elimination of left recursion. |
| 6 | Write a program which reads CFG and if required apply the left factoring then display the resulting CFG. |
| 7 | Write a program to implement Recursive Descent Parser for the given grammar. |
| 8 | Write a program to check if a given expression is valid or not using YACC for the following grammar. `E -> E+E | E-E | E*E | E/E | E%E | (E) | number | id` |
| 9 | Write a program to evaluate the given expression using LEX and YACC for the following grammar. `E -> E+E | E-E | E*E | E/E | E%E | (E) | number | id` |
| 10 | Write a program to convert infix expression to postfix expression using LEX and YACC for the following grammar. `E -> E+T | E-T | T`, `T -> T*F | T/F | F`, `F -> (E) | -F | id` |
| 11 | Write a program to generate Quadruples (Three address code) for the given expression using LEX and YACC for the following grammar. `E -> E+E | E-E | E*E | E/E | E%E | (E) | number | id` |
| 12 | Write a program to implement a simple Code Generator for the given three address code. |

## Textbook(s)

1. Alfred V. Aho, Monica S. Lam, Ravi Sethi, Jeffrey D. Ullman, *Compilers Principles, Techniques and Tools*, 2nd ed., Pearson Education, 2008.

## Reference(s)

1. Alfred V. Aho, J.D. Ullman, *Principles of Compiler Design*, Narosa Publications, 2002.
2. John R. Levine, Tony Mason, Doug Brown, *Lex & Yacc*, O'Reilly, 2/e, 1992.
3. Keith Cooper, Linda Torczon, *Engineering a Compiler*, Morgan Kaufmann, 2/e, 2011.

## Course Outcomes

1. Define and analyse various phases involved in designing a compiler (L1)
2. Compare and contrast between bottom-up and top-down parsers and explore the LL parser (L2)
3. Explore LR parsers and demonstrate how to generate LR parsers using the YACC tool (L3)
4. Illustrate the usage of Syntax Directed Definition in generating intermediate code (L3)
5. Identify several machine-independent methods for optimization and explore techniques for generating the final code (L3)

## Course Articulation Matrix

**B.Tech. Computer Science and Engineering / B.Tech. CSE (AI & ML) / B.Tech. CSE (Cyber Security) / B.Tech. CSE (Data Science)**

| CO | PO1 | PO2 | PO3 | PO4 | PO5 | PO6 | PO7 | PO8 | PO9 | PO10 | PO11 | PO12 | PSO1 | PSO2 | PSO3 |
|----|-----|-----|-----|-----|-----|-----|-----|-----|-----|------|------|------|------|------|------|
| 1  | 1   | 1   | 1   | 1   | 1   | 1   | -   | -   | -   | -    | -    | -    | 1    | -    | -    |
| 2  | 2   | 2   | 2   | 2   | 1   | 1   | -   | -   | -   | -    | -    | -    | -    | -    | -    |
| 3  | 2   | 2   | 3   | 2   | 2   | -   | -   | -   | -   | -    | -    | -    | -    | -    | -    |
| 4  | 1   | 2   | 1   | 2   | 2   | 2   | -   | -   | -   | -    | -    | -    | -    | -    | -    |
| 5  | 2   | 3   | 2   | 2   | 2   | 2   | -   | -   | -   | -    | -    | -    | -    | -    | -    |

*3 – High, 2 – Medium, 1 – Low Correlation*

## Approval

- **BOS:** 20-05-2025
- **Academic Council Number:** 33
- **Academic Council:** 13-06-2025

## SDG

**SDG No(s). & Statement(s):** 8 — *Decent Work and Economic Growth*: Promote sustained, inclusive and sustainable economic growth, full and productive employment and decent work for all.

**SDG Justification:** In an increasingly automated world with computers, writing efficient compilers can help use them to solve several problems such as logistics, planning etc., leading to economic growth.