/*------------------------------------------------------
* Filename: dynamic_struct.c
* Description: taking user input of 2 Time struct and adding together
* Author: Golan Ziv
-------------------------------------------------------*/

#include "time.h"


/*------------------------------------------------------
* Function Name - main
*
* Function Purpose - dynamically allocate memory for Time struct, add 2 struct together and print total 
*
* Return Values - 0 
*
* Author - Golan Ziv
-------------------------------------------------------*/
int main(){
    Time *t1, *t2, *sum;
    t1 = (Time *) malloc(sizeof(Time));
    t2 = (Time *) malloc(sizeof(Time));
    sum = (Time *) malloc(sizeof(Time));
    // checking allocations, and initializing structs.
    if(t1 == NULL || t2 == NULL || sum == NULL){
        printf("memoery allocation failed for structs!");
        if(t1 != NULL) free(t1);
        if(t2 != NULL) free(t2);
        if(sum != NULL) free(sum);
        return 1;
    }

    init_time(t1);
    init_time(t2);
    init_time(sum);

    if(create_time(t1) || create_time(t2)){
        printf("Bad Input!");
        return 1;
    }

    printf("\nYou entered:\n");
    print_time(t1);
    print_time(t2);

    sum = add_times(t1, t2);
    printf("\nSum of times:\n");
    print_time(sum);

    // free all structs
    free(t1);
    free(t2);
    free(sum);

    return 0;
}
