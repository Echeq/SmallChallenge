/*
Develop a basic game in C Language that the machine will storage a  random
number and the user needs guess which is the most closest number, the machine
will give a feedback if the number who typed the user is close or far.

The criteria that will be evaluated are:
1. Code Skill
2. Technical Skill
3. User Friendly
4. Documentation
5. Readeable
*/
#include <stdio.h>
#include <stdbool.h>
#include <time.h>

unsigned int num;

/*This functions is to make the code more clean and readable.
    Options:
    1. Divisors.
    2. Clean Screen, i prefer to use ascii jump, because the
    system() has problem in my machine.
*/
void extra(int options){
    switch(options){
        case 1:
            for(int i = 1; i <= 40; i++){
                printf("=");
            }
            printf("\n");
            break;
        case 2:
            //ANSI sequence for cleaning the screen
            printf("\033[H\033[J");
            break;
        default:
            printf("THE EXTRA OPTIONS IS NOT IN THE MENU.");
    }
}


void intro(){
    extra(1);
    printf("Welcome to Guess the Closest Number Game!\n");
    printf("Rules:\n");
    printf("1. Only type numbers, no letter.\n");
    printf("2. The number will be chose randomly.\n");
    printf("3. The least step you take to guess, better score you will get.\n");
    printf("4. Type from 1 to 100.");
    printf("This software was code by: github.com/Echeq\n");
    extra(1);
}

//RANDOMIZER NUM
int get_num(){
    //instance
    srand(time(NULL));
    //from 1 to 100, you can change the 100 to make it more bigger or smaller
    num = rand() % 100;
}

int start(){
    printf("Type down your first guess\n");
    int i = 1;
    int input;

    char again;
    char choice;

    //Debugging feature
    //printf("%d\n", num);

    while(true){
        printf("Attemp #%d: ", i++);

        //Conditioner control the input, won't accept char and will repeat
        if(scanf(" %d", &input) != 1){
            printf("Invalid input. Please enter a valid interger. \n");
            //clean the buffer
            while(getchar() != '\n');
            i--;
            continue;
        }

        if(input > num)
                printf("Bigger\n");
            else if(input < num)
                printf("Smaller\n");
            else if(input == num){
                extra(2);
                printf("Congratulation!! You win\n");
                break;
        }
    }
    printf("Do you want to play again?\nY for YES, N for NO\n");

    scanf(" %c", &again);
    if(again == 'Y'){
        //This 'i = 1' will reset the count, sometimes get buggy
        i = 1;
        get_num();
        extra(2);
        return 0;
    } else if(again == 'N'){
        extra(2);
        extra(1);
        printf("Thank you for using my software!\n");
        printf("ATT: github.com/Echeq\n");
        extra(1);
        exit(1);
    }else{
        printf("Invalid choice");
    }
}

int main(void){
    get_num();
    while(true){
        intro();
        start();
    }
    return 0;
}
