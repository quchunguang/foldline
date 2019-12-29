# foldline

Fold lines from stdout that with same prefix.

## usage

```sh
for i in {1..4}; do echo "[out] something $i..."; sleep(0.5); done | foldline 
```

## install

```sh
gcc -c foldline.c -o foldline
sudo ln -s foldline /usr/bin/
```

## arguments

-h | --help: Display usage

-n <size>:   Compare only the first <size> charactors. 4 by default.
