# AGENTS.md

Compact guidance for OpenCode sessions working in this Compiler Design lab repo.

## Repo shape

Academic lab repository for **CSEN3032 - Compiler Design** (Semester 7). One directory per experiment:

```
Experiment_N/
  Exp_N_x.c       standalone C program (DFA / parser / codegen)
  Exp_N_x.png     transition diagram (manually authored)
  Experiment N.pdf lab record (converted to .md)
  Exp_N_x.exe     compiled binary (committed alongside source)
```

There is **no monorepo, no package manager, no shared build system.** Each `.c` file is a standalone program with its own `main()` and is compiled individually. Filenames contain spaces (`Experiment 1.md`) - always quote paths in shell commands.

## Toolchain

- **Compiler:** MinGW-W64 `gcc` 15.2.0 (WinLibs UCRT POSIX build). On PATH as `gcc`.
- **Compile command (canonical, from `run.txt`):**
  ```
  gcc -Wall -Wextra -o <name>.exe <name>.c
  ```
  Run from the experiment's directory. Output is an `.exe` in the same folder.
- **No test runner, no linter, no formatter.** "Verification" = compile + run the binary and inspect stdout against the experiment's acceptance criteria.
- `test.c` / `test.exe` at repo root is a one-off C language sanity check, not part of any experiment. Don't touch it unless asked.

## Not yet installed (watch for this)

`flex`, `yacc`, and `bison` are **not currently on PATH.** Experiments 3-12 (per the syllabus) require LEX/YACC. Before working on those:
- Check `where.exe flex` / `where.exe bison`
- If missing, flag it to the user rather than guessing install steps - toolchain setup is their call.

## Git conventions

- `.exe` binaries **are committed** alongside their source (historical pattern in this repo). The `.gitignore` ignores `*.exe` going forward, so newly added binaries won't be tracked unless you `git add -f`. Match existing experiment behavior: commit the `.exe`.
- Commit message style is lowercase, imperative-ish prose (e.g. `add implementation of DFA for string recognition in Exp_1_c.c and include executable file`). No conventional-commits prefix.
- Branch / PR flow is not configured - this looks like a single-branch (`master`) personal repo. Don't create branches unless asked.

## Lab record conventions

Each experiment has a PDF lab record; these are being converted to `.md` companion files (see `Experiment 1.md` for the template). When converting:
- Use `pymupdf` (already installed) via a throwaway Python script - `pandoc` cannot read PDFs and `pdfplumber` is not installed.
- PDFs from this course have flattened tables (matrix columns become vertical number stacks); reshape them into proper markdown tables, don't preserve the raw columnar extraction.
- Output the `.md` beside the source `.pdf` with the same base name.

## Syllabus reference

`CSEN3032 COMPILER DESIGN SYLLABUS.md` lists all 12 experiments and their grammars. Treat it as the source of truth for what each experiment should implement when the lab record is ambiguous.