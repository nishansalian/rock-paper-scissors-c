#include <ctype.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

enum Choice { ROCK, PAPER, SCISSORS, INVALID, QUIT };

static enum Choice parse_choice(char *input) {
    size_t length = strlen(input);
    while (length > 0 && isspace((unsigned char)input[length - 1]))
        input[--length] = '\0';

    char *start = input;
    while (*start && isspace((unsigned char)*start)) ++start;

    for (char *p = start; *p; ++p)
        *p = (char)tolower((unsigned char)*p);

    if (strcmp(start, "r") == 0 || strcmp(start, "rock") == 0) return ROCK;
    if (strcmp(start, "p") == 0 || strcmp(start, "paper") == 0) return PAPER;
    if (strcmp(start, "s") == 0 || strcmp(start, "scissors") == 0) return SCISSORS;
    if (strcmp(start, "q") == 0 || strcmp(start, "quit") == 0) return QUIT;
    return INVALID;
}

static const char *choice_name(enum Choice choice) {
    switch (choice) {
        case ROCK: return "Rock";
        case PAPER: return "Paper";
        case SCISSORS: return "Scissors";
        default: return "Unknown";
    }
}

int main(void) {
    int wins = 0;
    int losses = 0;
    int ties = 0;
    char input[128];

    srand((unsigned int)time(NULL));
    puts("Rock, Paper, Scissors!");
    puts("Type rock (r), paper (p), scissors (s), or quit (q).\n");

    for (;;) {
        printf("Your choice: ");
        fflush(stdout);

        if (!fgets(input, sizeof(input), stdin)) {
            putchar('\n');
            break;
        }
        if (!strchr(input, '\n') && !feof(stdin)) {
            int ch;
            while ((ch = getchar()) != '\n' && ch != EOF) {}
            puts("That choice is too long. Try again.\n");
            continue;
        }

        enum Choice player = parse_choice(input);
        if (player == QUIT) break;
        if (player == INVALID) {
            puts("Please enter rock, paper, scissors, or q to quit.\n");
            continue;
        }

        enum Choice computer = (enum Choice)(rand() % 3);
        printf("You chose %s. Computer chose %s.\n",
               choice_name(player), choice_name(computer));

        if (player == computer) {
            ++ties;
            puts("It's a tie!");
        } else if ((player == ROCK && computer == SCISSORS) ||
                   (player == PAPER && computer == ROCK) ||
                   (player == SCISSORS && computer == PAPER)) {
            ++wins;
            puts("You win!");
        } else {
            ++losses;
            puts("Computer wins this round.");
        }
        printf("Score: You %d - Computer %d (ties: %d)\n\n", wins, losses, ties);
    }

    printf("Final score: You %d - Computer %d (ties: %d)\n", wins, losses, ties);
    puts("Thanks for playing!");
    return 0;
}
