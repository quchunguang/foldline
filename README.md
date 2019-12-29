# foldline

Fold lines from stdout that with same prefix.

## One line usage

```sh
for i in {1..4}; do echo "[out] something $i..."; sleep(0.5); done | foldline 
```

## Install

[Download the release tarball](https://github.com/quchunguang/foldline/releases), extract it, and,

```sh
./configure
make
sudo make install
```

## Command line arguments

-h | --help: Display usage

-n <size>:   Compare only the first <size> charactors. 4 by default.

## Development

### Dependence

* glibc

### Build on ubuntu latest

gcc foldline.c -o foldline

### Usage of autotool

```sh
# Tested on ubuntu latest
sudo apt-get install autotools-dev autoconf

# On the maintainer’s system:
aclocal
autoconf
automake --add-missing
./configure
make distcheck

# On the end-user’s system:
./configure
make
make install
```
