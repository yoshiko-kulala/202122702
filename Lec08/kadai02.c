#include <stdio.h>
#include <stdlib.h>
#include <math.h>

#define N 3        /* Board size */
#define DEPTH 4    /* Max-depth to search the game tree */
#define MAXSCORE 3 /* Maximum absolute value of score */

int search(int player, int depth, int B[][N], int *r, int *c);
void next_move(int step, int B[][N]);
int calc_score(int B[][N], int sign);
int get_board_score(int B[][N]);
void print_instruction(int B[][N]);
void print_board(int B[][N]);
void read_input(int B[][N]);
int array_count(int B[][N], int val, int axis, int index); 
int any(int B[][N], int val, int axis, int index);
int get_winner(int B[][N]);
int min(int a, int b);
int max(int a, int b);

/* -------------------------------------------------- */
/* Recursive function to search the game tree         */
/* Argument:                                          */
/*   int player: +1 (user), -1 (CPU)                  */
/*   int depth: Depth to search                       */
/*   int B[][N]: Board (3x3)                          */
/*   int *r: Set the selected row (0-2)               */
/*   int *c: Set the selected column (0-2)            */
/* Output: Score                                      */
/* -------------------------------------------------- */
int search(int player, int depth, int B[][N], int *r, int *c) {

    int i, j;
    int score;     /* Temporary score */
    int best_score; /* Best score */
    int r_dummy, c_dummy; /* Dummy */

    best_score = -player*(MAXSCORE+1); /* initialize by the worst score */

/* -------------------------------------------------- */
/*  Write your code here                              */
/*  (check the current score and depth)               */
/* -------------------------------------------------- */
    //my_code0
    score=get_board_score(B);
    if(depth==0||abs(score)==3){
        return score;
    }
    //my_code0 end
    
    for(i = 0; i < N; ++i) {
        for(j = 0; j < N; ++j) {
            if(B[i][j] == 0) {
                B[i][j] = player; // player select (i,j)

/* -------------------------------------------------- */
/*  Write your code here (recursive call of 'search') */
/*  score = search(???, ???, B, &r_dummy, &c_dummy);  */
/* -------------------------------------------------- */
                //my_code1
                score = search(player*-1, depth-1, B, &r_dummy, &c_dummy);
                //my_code1 end

                if((player*score) >= (player*best_score)) {  // larger 'player*score' means a better selection

/* -------------------------------------------------- */
/*  Write your code here (Set r, c, and score_opt)    */
/* -------------------------------------------------- */

                    //my_code2
                    best_score=score;
                    *r=i;
                    *c=j;
                    //my_code2 end

                }   
                B[i][j] = 0; // reset the board
            }
        }    
    }
    // return 0;
    //my_code3
    return best_score;
    //my_code3 end
    // return score_opt;
}

/* -------------------------------------------------- */
/* Determine next move through 'search' function      */
/* Argument:                                          */
/*   int step: Iteration of game (0-8)                */
/*   int B[][N]: Board (3x3)                          */
/* -------------------------------------------------- */
void next_move(int step, int B[][N]) {

    int depth = min(N*N-step, DEPTH); // tree depth to search
    int score;
    int r, c;

    score = search(-1, depth, B, &r, &c);
    printf("CPU selected (%d, %d) with score = %d\n", r+1, c+1, score);
    B[r][c] = -1;

}

/* -------------------------------------------------- */
/* Main                                               */
/* -------------------------------------------------- */
int main() {

    int i, j;

    int B[N][N];    // Board 
    int player = 1; // 1: CPU, -1: User
    int winner;

    for(i = 0; i < N; ++i) {
        for(j = 0; j < N; ++j) {
            B[i][j] = 0;
        }    
    }

    // Print board with input instruction
    print_instruction(B);

    // Main loop
    for(i = 0; i < N*N; ++i) {

        if(player > 0) {
            printf("--------------------------------------------------\n");
            printf("Turn: you\n");
            printf("--------------------------------------------------\n");
            read_input(B);
        } else {
            printf("--------------------------------------------------\n");
            printf("Turn: CPU\n");
            printf("--------------------------------------------------\n");
            next_move(i, B);
        }
        player *= -1;

        print_board(B);

        winner = get_winner(B);
        if(winner == 1) {
            printf("Player wins!\n");
            break;
        } else if (winner == -1) {
            printf("CPU wins!\n");
            break;
        }
    }  

    if(winner == 0) printf("Draw!\n");

    return 0;

}


/* ================================================== */
/* Other auxiliary functions                          */
/* ================================================== */


int calc_score(int B[][N], int sign) {
    int i,j;
    int s;
    int s_max = 0;

    // row
    for(i = 0; i < N; ++i) {
        if(!any(B, -sign, 1, i)) {
            s = 0;
        } else {
            s = array_count(B, sign, 1, i);
        }
        s_max = max(s, s_max);
    }

    // column
    for(i = 0; i < N; ++i) {
        if(!any(B, -sign, 0, i)) {
            s = 0;
        } else {
            s = array_count(B, sign, 0, i);
        }
        s_max = max(s, s_max);
    }

    // diagonal
    if(any(B, -sign, 2, 0)) {
        s = array_count(B, sign, 2, 0);
        s_max = max(s, s_max);
    }
    if(any(B, -sign, 3, 0)) {
        s = array_count(B, sign, 3, 0);
        s_max = max(s, s_max);
    }

    return s_max;
}

int get_board_score(int B[][N]) {

    int cpu_score, user_score;

    user_score = calc_score(B,1);
    cpu_score = calc_score(B,-1);
    if (user_score == MAXSCORE && cpu_score == MAXSCORE) {
        printf("Error: Invalid board state\n");
        exit(1);
    }

    if (cpu_score == MAXSCORE) {
        return - cpu_score;
    }
    if (user_score == MAXSCORE) {
        return user_score;
    }

    return user_score - cpu_score;
}


int get_winner(int B[][N]) {

    if(calc_score(B,1) == MAXSCORE) return 1;
    if(calc_score(B,-1) == MAXSCORE) return -1;

    return 0;
}

void print_instruction(int B[][N]) {

    int i,j;

    printf("Tic Tac Toe Program\n\n");

    printf("Please choose a position by the following code\n");

    printf(" ---- ---- ----\n");
    for(i = 0; i < N; ++i) {
        for(j = 0; j < N; ++j) {
            printf("| %d%d ", i+1, j+1);
        }
        printf("|\n");
        printf(" ---- ---- ----");
        printf("\n");
    }

}

void print_board(int B[][N]) {

    int i,j;

    printf(" --- --- ---\n");
    for(i = 0; i < N; ++i) {
        for(j = 0; j < N; ++j) {
            if(B[i][j] > 0) 
                printf("| o ");
            else if (B[i][j] < 0) 
                printf("| x ");
            else 
                printf("|   ");
        }
        printf("|\n");
        printf(" --- --- ---");
        printf("\n");
    }

}

/* -------------------------------------------------- */
/* Read user input                                    */
/* -------------------------------------------------- */
void read_input(int B[][N]) {

    int input;
    int r, c;

    printf("Input: ");
    scanf("%d", &input);

    r = input / 10 - 1;
    c = (input % 10) - 1;

    if(r < 0 || r > 2 || c < 0 || c > 2) {
        printf("Error: Unknown input\n");
        exit(1);
    }

    if(B[r][c] != 0) {
        printf("Error: Invalid input (occupied)\n");
        exit(1);
    }

    B[r][c] = 1;

}

/* -------------------------------------------------- */
/* Count frequency of val in specified axis and index */
/* -------------------------------------------------- */
int array_count(int B[][N], int val, int axis, int index) {
    int i;
    int sum = 0;

    if(axis == 0) { // index-th column
        for(i = 0; i < N; ++i) {
            if(B[i][index] == val) sum++;
        }
    } else if(axis == 1) { // index-th row
        for(i = 0; i < N; ++i) {
            if(B[index][i] == val) sum++;
        }
    } else if(axis == 2) { // diagonal
        for(i = 0; i < N; ++i) {
            if(B[i][i] == val) sum++;
        }
    } else if(axis == 3) { // anti-diagonal
        for(i = 0; i < N; ++i) {
            if(B[i][N-i-1] == val) sum++;
        }
    } else {
        printf("array_count: Unknown axis\n");
        exit(1);
    }

    return sum;
}

/* -------------------------------------------------- */
/* Search val in specfied axis and index              */
/* -------------------------------------------------- */
int any(int B[][N], int val, int axis, int index) {
    int i;

    if(axis == 0) { // index-th column
        for(i = 0; i < N; ++i) {
            if(B[i][index] == val) return 0;
        }
    } else if(axis == 1) { // index-th row
        for(i = 0; i < N; ++i) {
            if(B[index][i] == val) return 0;
        }
    } else if(axis == 2) { // diagonal
        for(i = 0; i < N; ++i) {
            if(B[i][i] == val) return 0;
        }
    } else if(axis == 3) { // anti-diagonal
        for(i = 0; i < N; ++i) {
            if(B[i][N-i-1] == val) return 0;
        }
    } else {
        printf("any: Unknown axis\n");
        exit(1);
    }
    return 1;

}


int min(int a, int b) {
    return a <= b ? a : b;
}

int max(int a, int b) {
    return a >= b ? a : b;
}
