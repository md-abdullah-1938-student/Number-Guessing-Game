#include <stdio.h>
#include <stdlib.h>
#include <time.h>
int main() {
    int difficulty,limit,min=1,max,number, guess, attempts;
    printf("%d",time(NULL));
    printf("\nChoose Difficulty,\n1.Easy\n2.Medium\n3.Hard\nEnter Your Choice(1/2/3): ");
    scanf(" %d",&difficulty);
    srand((unsigned)time(NULL));
    switch (difficulty)
    {
    case 1:
        max=100;
        attempts=10;
        limit=10; 
        break;
    case 2:
        max=1000;
        attempts=20;
        limit=20;
        break;
    case 3:
        max=10000;
        attempts=30;
        limit=30;
        break; 
    default:
        printf("Invalid Choice!!");
        return 0;
    }
    number=(rand()%(max-min+1)+min);
    printf("\nThe Number that You Should guess is between %d and %d",min,max);
    for (int i=0;i<limit;i++){
        printf("\nEnter the Number you have guessed(attempts left=%d):",attempts);
        scanf(" %d",&guess);
        if(i==limit){
            printf("You have lost,The number is %d",number);
            return 0;
        }    
        else if (guess==number){
            printf("You have guessed the number correctly!!\n");
            printf("Your Score is %d",attempts/difficulty);
            break;
        }
        else if((guess>max) || (guess<min)){
            printf("The number you guessed is wrong,It's beyond the defined limit.");
            attempts--;
        }
        else if(guess<number){
            printf("The number you guessed is wrong,It's a little bit higher.");
            attempts--;
        }
        else if(guess>number){
            printf("The number you guessed is wrong,It's a little bit lower.");
            attempts--;
        }
        
    }
    return 0;

    
}