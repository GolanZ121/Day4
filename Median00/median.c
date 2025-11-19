/*------------------------------------------------------
* Filename: median.c
* Description: find median of unknown amount of numbers
* Author: Golan Ziv
-------------------------------------------------------*/

#include <stdio.h>
#include <stdlib.h>

/*------------------------------------------------------
* Function Name - compare
*
* Function Purpose - compare to integers (for the qsort function)
*
* Parameters –  [IN a - pointer to integer (its void for qsort) but we know its for int *] 
*               [IN b - same] 
*
* Return Values - 1 if the value a points to is greater that the value b points to, else 0
*
* Author - Golan Ziv
-------------------------------------------------------*/
int compare(const void * a, const void * b){
    return *((int*) a) > *((int*) b);
}


/*------------------------------------------------------
* Function Name - main
*
* Function Purpose - read integers until a non number is entered, than sort to get the median
*
* Return Values - 0 for success, 1 for error
*
* Author - Golan Ziv
-------------------------------------------------------*/
int main(){
    int counter = 0, curr, median;
    int *numbers = NULL;
    int *temp;
    

    printf("Enter numbers to find median (enter non number to stop)");    
    while(1){
        if(scanf(" %d", &curr) != 1){
            if(counter == 0){
                printf("\nNo numbers entered");
                return 1;
            }
            else break;
        };

        counter++;
        if(counter == 1){
            numbers = (int *) calloc(counter, sizeof(int));
            if(numbers == NULL){
                printf("Error calloc allocation memory");
                return 1;
            }
        }
        else{ 
            temp = (int *)realloc(numbers, sizeof(int)*counter);
            if(temp == NULL){
                printf("Error realloc allocation memory");
                free(numbers);
                return 1;
            }
            numbers = temp;
        }
        numbers[counter-1] = curr;
    }

    qsort((void *) numbers, counter, sizeof(int), compare);

    median = (counter % 2 == 0) ? 
                (numbers[(counter / 2) - 1] + numbers[counter / 2]) / 2:
                (numbers[counter / 2]);

    printf("\nThe median is %d", median);
    free(numbers);
    return 0;

}