/*
Develop a basic calculator in C Language that allows performing
arithmetic operations(addition, substraction, multiplication, and
division) with decimal numbers. The program should be modular, robust
and easy to use. 

The criteria that will be evaluated are:
1. Code Skill
2. Technical Skill
3. User Friendly
4. Documentation
5. Readeable
*/

#include <stdio.h>
//FOR HUGE NUMBER OF DIGITS PLEASE INSTALL libgmp-dev (GMP LIBRARY).
//#include <gmp.h>


//IF YOUR OS BREAK, CHANGE THIS PART FOR ANSI SEQUENCE '\n' x30 time.
#ifdef _WIN64 //DETECT WINDOWS 64BITS to allow clean the screen
#define CLEAR_SCREEN system("cls")
#else
#define CLEAR_SCREEN system("clear") //IF DONT DETECT WINDOWS 64BITS CONDITION
#endif

enum operations {
EXIT = 0,
ADD = 1,
SUB = 2,
MUL = 3,
DIV = 4};

int home(){
    printf("\n===================\n");
    printf("========HOME=======\n");
    printf("1. Addition.\n");
    printf("2. Substraction.\n");
    printf("3. Multiplication.\n");
    printf("4. Division.\n");
    printf("0. Exit\n");
    printf("===================\n");
}
void cleanscreen(){
    CLEAN_SCREEN;
  //if your OS break the software use the next line of code
  //printf("\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n");
}

float op_Add(){
    float a, b;

    cleanscreen();

    printf("You chose to do an Addition Operation.\n");
    printf("Type the FIRST value: ");
    scanf("%f", &a);
    printf("Type the SECOND value: ");
    scanf("%f", &b);
    return a + b;
}
float op_Sub(){
    float a, b;

    cleanscreen();

    printf("You chose to do an Substraction Operation.\n");
    printf("Type the FIRST value:");
    scanf("%f", &a);
    printf("Type the SECOND value: ");
    scanf("%f", &b);

    return a - b;
}
float op_Mul(){
    float a, b;

    cleanscreen();

    printf("You chose to do an Multiplication Operation.\n");
    printf("Type the FIRST value:");
    scanf("%f", &a);
    printf("Type the SECOND value: ");
    scanf("%f", &b);

    return a * b;
}
float op_Div(){
    float a, b;

    cleanscreen();

    printf("You chose to do an Division Operation.\n");
    printf("Type the FIRST value:");
    scanf("%f", &a);

    printf("Type the SECOND value: ");
    scanf("%f", &b);

    if(a == 0 || b == 0){
        printf("ERROR: Division by zero is not allowed.\n");
        return 0;
    }

    return a / b;
}

int main(){
    int choice = -1;
    long double result;

    while(1){
        home();
        printf("Enter your choice: ");

        //Verificate if the choice is an number, not a char.
        if(scanf("%d", &choice) != 1){
            printf("Invalid input. Please enter a number.");

            //This getchar clean all the buffer.
            while(getchar() != '\n')
            continue;
        }
        switch(choice){
            case EXIT:
                cleanscreen();
                printf("THANKS FOR USE MY SOFTWARE. \nATT: Github.com/Echeq\n\n");
                return 0;
            case ADD:
                printf("The result of the ADDITION is: %0.2f.\n\n", op_Add());
                break;
            case SUB:
                printf("The result of the SUBSTRACTION is: %0.2f.\n\n", op_Sub());
                break;
            case MUL:
                printf("The result of the MULTIPLICATION is: %0.2f.\n\n", op_Mul());
                break;
            case DIV:
                printf("The result of the DIVISION is: %0.2f.\n\n", op_Div());
                break;
            default:
                cleanscreen();
                printf("ERROR. YOUR CHOICE IS NOT IN THE MENU, PLEASE TYPE ONE ON THE MENU.");
                break;
        }
    }
}
