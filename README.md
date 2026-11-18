# Rock, Paper, Scissors

A simple terminal game written in C. Play as many rounds as you like against the computer, keep score, and quit when you're done.

## Build

You need a C compiler such as GCC or Clang and Make.

```sh
make
```

This creates the `rps` program in the project directory. You can also compile it directly:

```sh
cc -std=c11 -Wall -Wextra -Wpedantic -O2 -o rps rps.c
```

## Play

```sh
./rps
```

Enter `rock`, `paper`, or `scissors` (or just `r`, `p`, or `s`). The game shows the computer's choice, tells you who won the round, and updates the score. Enter `q` or `quit` to end the game and see the final score.

## License

MIT. See [LICENSE](LICENSE).
