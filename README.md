# CSEN3032 - Compiler Design Lab

Implementations for the Compiler Design (CSEN3032) lab course, Semester 7. Each experiment lives in its own directory with standalone C (or LEX/YACC) source, a transition-diagram image, and a PDF lab record.

## Repository layout

```
Experiment_N/
  Exp_N_x.c          standalone program for sub-experiment x (a, b, c, ...)
  Exp_N_x.png        transition diagram / illustration
  Exp_N_x.exe        compiled binary (Windows, committed)
  Experiment N.pdf   original lab record
  Experiment N.md    markdown companion (converted from the PDF)
CSEN3032 COMPILER DESIGN SYLLABUS.pdf   full syllabus
CSEN3032 COMPILER DESIGN SYLLABUS.md    syllabus (markdown)
run.txt                                canonical compile command
test.c / test.exe                      one-off C sanity check (not a lab program)
AGENTS.md                              guidance for AI coding assistants
```

## Toolchain

- **Compiler:** MinGW-W64 `gcc` 15.2.0 (UCRT POSIX build), available on PATH as `gcc`.
- Experiments 1-2 are pure C. Experiments 3-12 require `flex` and `yacc`/`bison`, which are **not on PATH** in this environment - install them before working on those experiments.

## Compile & run any program

Every program is standalone with its own `main()`. From an experiment directory:

```powershell
# compile (canonical command from run.txt)
gcc -Wall -Wextra -o Exp_N_x.exe Exp_N_x.c

# run (programs read the test string from stdin via scanf)
"abb" | .\Exp_N_x.exe
```

PowerShell note: these programs use `scanf("%s", ...)`, so the input must be **piped** to stdin - argument passing and `<<<` here-strings are not supported on Windows PowerShell 5.1. Use `"input" | .\program.exe` as shown above.

You can also run the binary directly and type a string, then press Enter.

## Experiment 1 - Recognition of Strings using Finite Automata

All four programs accept a string over `{a, b}` and report whether it is **accepted** or **rejected** by the DFA. Pipe the test string via stdin.

| Sub | File | Language accepted | Accept state | Example accept | Example reject |
|-----|------|------------------|--------------|----------------|----------------|
| a | `Exp_1_a.c` | ends with `abb` | state 3 | `"abb"` | `"aba"` |
| b | `Exp_1_b.c` | begins with `aa` | state 2 | `"aab"`, `"aabbb"` | `"bab"` |
| c | `Exp_1_c.c` | begins with `a` AND ends with `b` | state 2 | `"ab"`, `"aab"` | `"ba"`, `"aa"` |
| d | `Exp_1_d.c` | contains the substring `bab` | state 3 | `"bab"`, `"ababb"` | `"abb"` |

### Run Experiment 1

```powershell
cd Experiment_1
gcc -Wall -Wextra -o Exp_1_a.exe Exp_1_a.c
"abb" | .\Exp_1_a.exe        # String accepted
"aaba" | .\Exp_1_a.exe       # (a) does not end in abb -> rejected

gcc -Wall -Wextra -o Exp_1_b.exe Exp_1_b.c
"aab" | .\Exp_1_b.exe        # String accepted

gcc -Wall -Wextra -o Exp_1_c.exe Exp_1_c.c
"aab" | .\Exp_1_c.exe        # String accepted

gcc -Wall -Wextra -o Exp_1_d.exe Exp_1_d.c
"bab" | .\Exp_1_d.exe        # String accepted
```

See `Experiment 1.md` for the lab record (aim, algorithm, transition diagram reference, and full source).

## Upcoming experiments

Per the syllabus (see `CSEN3032 COMPILER DESIGN SYLLABUS.md`), the course has 12 experiments. Experiments 2-12 are not yet implemented. Expected per-experiment commands once added:

- **Pure C (Exp 1-2, 5-7):** `gcc -Wall -Wextra -o Exp_N_x.exe Exp_N_x.c`, then `.\Exp_N_x.exe`.
- **LEX (Exp 3-4):** `flex Exp_N_x.l && gcc -o Exp_N_x.exe lex.yy.c`, then `.\Exp_N_x.exe`.
- **LEX + YACC (Exp 8-11):** `yacc -d Exp_N_x.y && flex Exp_N_x.l && gcc -o Exp_N_x.exe lex.yy.c Exp_N_x.tab.c`, then `.\Exp_N_x.exe`.

Toolchain setup (`flex`/`bison`) is the user's call; see `AGENTS.md` for details.

## Verifying a change

There is no test runner. After editing any `.c` file:

```powershell
gcc -Wall -Wextra -o <name>.exe <name>.c    # must compile with no warnings
"<sample input>" | .\<name>.exe             # confirm stdout matches expected output
```

`test.c` / `test.exe` at the repo root is a one-off C language sanity check - it is not part of any experiment. Don't touch it unless explicitly asked.

## Lab records

Each experiment's PDF lab record is being converted to a markdown companion (`.md` with the same base name) for easier diffing and reading. Conversions use `pymupdf` (installed), since `pandoc` cannot read PDFs. Flattened tables in the course PDFs are reshaped into proper markdown tables during conversion.

## Git conventions

- `.exe` binaries are committed alongside source, matching existing history. The `.gitignore` ignores `*.exe` going forward, so newly added binaries need `git add -f`.
- Commit messages: lowercase, imperative-ish prose, no conventional-commits prefix. Example: `add implementation of DFA for string recognition in Exp_1_c.c and include executable file`.
- Single-branch `master` repo; no PR flow configured.