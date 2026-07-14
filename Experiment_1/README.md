# Experiment 1 Folder Guide

This folder contains the complete material for Experiment 1. The files are kept flat so the original lab record references and run commands stay intact, but this guide groups them by purpose.

## Programs

- [Exp_1_a.c](Exp_1_a.c) - DFA for strings that end with `abb`
- [Exp_1_b.c](Exp_1_b.c) - DFA for strings that begin with `aa`
- [Exp_1_c.c](Exp_1_c.c) - DFA for strings that begin with `a` and end with `b`
- [Exp_1_d.c](Exp_1_d.c) - DFA for strings that contain `bab`

## Binaries

- [Exp_1_a.exe](Exp_1_a.exe)
- [Exp_1_b.exe](Exp_1_b.exe)
- [Exp_1_c.exe](Exp_1_c.exe)
- [Exp_1_d.exe](Exp_1_d.exe)

## Transition Diagrams

- [Exp_1_a.png](Exp_1_a.png)
- [Exp_1_b.png](Exp_1_b.png)
- [Exp_1_c.png](Exp_1_c.png)
- [Exp_1_d.png](Exp_1_d.png)

## Lab Records

- [Experiment 1.md](Experiment%201.md) - markdown lab record
- [Experiment 1.pdf](Experiment%201.pdf) - original PDF lab record

## Sample Outputs

- [outputs.md](outputs.md) - one example output for each program

## Quick Run

From this folder, compile and run any program like this:

```powershell
gcc -Wall -Wextra -o Exp_1_a.exe Exp_1_a.c
"abb" | .\Exp_1_a.exe
```