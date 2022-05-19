# minishell

## Why does the code look weird ?

The 42 curriculum asks us to code according to the `Norme`, this standard forbids us certain control structures (like `do while`, `for`, ...), a limit of 25 lines and 5 variables per function, 5 function max per `.c` and and other constraints.

This project has been coded according to the `NormeV3` standard.

[NormeV3 PDF](https://github.com/Matthew-Dreemurr/Media-Stock/blob/master/norm/en.normV3.pdf) used in this projetc

[Norme repo](https://github.com/42School/norminette)

## Requirements

### Clone with submodule

```
git clone --recurse-submodules git@github.com:fluffy-willa-42-team/minishell.git
```

or if you have `Oh-My-Zsh`

```
gcl git@github.com:fluffy-willa-42-team/minishell.git
```

Need the GNU readline lib

### MacOS

First install Brew
```
/bin/bash -c "$(curl -fsSL https://raw.githubusercontent.com/Homebrew/install/HEAD/install.sh)"
```

Install GNU readline lib
```sh
brew install readline 
```

### Debian/Ubuntu

Install readline lib
```sh
 apt install libreadline-dev
```

## Compile

To compile

```make```

Compile and run

```make exe```

Compile with `fsanitize=address`

```make SANI=1```

---

This work is published under the terms of **[42 Unlicense](https://github.com/gcamerli/42unlicense)**.
