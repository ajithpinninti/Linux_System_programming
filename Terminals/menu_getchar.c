#include<stdio.h>
#include<stdlib.h>

char *menu[]={
    "a - add new",
    "d - delete the queue",
    "q - quit",
    NULL,
} ;

int get_choice(char* greet, char** menu);

int main(void){

    int choice = 0;
    do{
        choice = get_choice("select one from below:",menu);
        printf("your selected choise is %c \n\n",choice);
    }while (choice!='q');
    return 0;
}

int get_choice(char* greet, char** menu){

    printf("%s \n",greet);
    int selected;
    char** option = menu;  
    while (*option)
    {
        printf("%s \n",*option);
        option++;
    }
    option = menu;
    selected = getchar();
    do
    {
        if(selected == **option){
            return **option;
            break;
        }
        option++;
        if(!*option){
            printf("please enter a correct option: \n");
            selected = getchar();
            option = menu;
        }
    }while  (*option);   
}