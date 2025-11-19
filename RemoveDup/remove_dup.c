/*------------------------------------------------------
* Filename: remove_dup.c
* Description: implement 3 version of functions to removing duplicates
* Author: Golan Ziv
-------------------------------------------------------*/

#include <stdio.h>
#include <stdlib.h>

/*
    I implemented the third version of the function first, because this way i can use it 
    to implment the other two.
*/

/*------------------------------------------------------
* Function Name - remove_dup3 
*
* Function Purpose - take a sorted array and create dynmically an array without the duplicates.
*
* Parameters –  [IN src - an array of ints] 
*		        [IN src-len – length of the src array]
*		        [OUT dest_len – pointer to int, the length of the resulted array]
*		        [OUT dest – a pointer to the address of an integer array, where we put the resulted array]
*
* Return Values - void
*
* Author - Golan Ziv
-------------------------------------------------------*/
void remove_dup3(int *src, int src_len, int *dest_len, int **dest){
    int * result = calloc(1, sizeof(int)), *temp;
    int counter = 1;

    if(result == NULL || src == NULL || src_len == 0){ // if malloc failed or the array is empty
        *dest_len = 0;
        *dest = NULL;
        if(result != NULL) free(result);
        return;
    };
    
    result[0] = src[0];

    for(int i = 1, prev = src[0], curr; i < src_len; i++){
        while((curr = src[i]) == prev && i < src_len)
            i++;

        if(i == src_len) break;

        counter++;
        temp = realloc(result, sizeof(int)*counter);

        if(temp == NULL){ // if realloc failed, setting pointer to null and leaving
            *dest_len = 0;
            *dest = NULL;
            free(result);
            return;
        }
        result = temp;

        result[counter-1] = curr;
        prev = curr;
    }

    *dest_len = counter;
    *dest = result;
}


/*------------------------------------------------------
* Function Name - remove_dup1
*
* Function Purpose - take a sorted array and create dynmically an array without the duplicates.
*
* Parameters –  [IN src - an array of ints] 
*		        [IN src-len – length of the src array]
*		        [OUT dest_len – pointer to int, the length of the resulted array]
*
* Return Values - pointer to result int array
*
* Author - Golan Ziv
-------------------------------------------------------*/
int * remove_dup1(int *arr, int length, int *result_length){
    int *result = NULL;
    remove_dup3(arr, length, result_length, &result);
    return result;
}


/*------------------------------------------------------
* Function Name - remove_dup2 
*
* Function Purpose - take a sorted array and create dynmically an array without the duplicates.
*
* Parameters –  [IN src - an array of ints] 
*		        [IN src-len – length of the src array]
*		        [OUT dest – a pointer to the address of an integer array, where we put the resulted array]
*
* Return Values - int, the length of the resulted array
*
* Author - Golan Ziv
-------------------------------------------------------*/
int remove_dup2(int *arr, int length, int **result){
    int result_length;
    remove_dup3(arr, length, &result_length, result);
    return result_length;
}



/*------------------------------------------------------
* Function Name - print_arr
*
* Function Purpose - print an array in nice format
*
* Parameters –  [IN prefix - a string to print before the array like "Array: "] 
*		        [IN arr – pointer to the int array]
*		        [IN len – length of the array, like 0, 1.. ]
*
* Return Values - void
*
* Author - Golan Ziv
-------------------------------------------------------*/
void print_arr(char * prefix, int *arr, int len){
    printf("%s", prefix);
    for (int i = 0; i < len; i++){
        printf("%d ", arr[i]);
    }
}



/*------------------------------------------------------
* Function Name - main
*
* Function Purpose - uses all three remove_dup functions and prints result using print_arr 
*
* Return Values - 0
*
* Author - Golan Ziv
-------------------------------------------------------*/
int main(){
    int arr[] = {1,1,1,1,1,2,2,2,2,2,2,5,5,5,5,5,5};
    int len = sizeof(arr)/sizeof(int);
    int *new_arr, new_len;
    
    print_arr("ORIGINAL ARRAY: ", arr, len);

    new_len = remove_dup2(arr, len, &new_arr);
    if(new_arr == NULL){
        printf("error occured");
        return 1;
    }
    print_arr("\nNO DUPS ARRAY (FUNC 2): ", new_arr, new_len);

    new_arr = remove_dup1(arr, len, &new_len);
    if(new_arr == NULL){
        printf("error occured");
        return 1;
    }
    print_arr("\nNO DUPS ARRAY (FUNC 1): ", new_arr, new_len);
    
    remove_dup3(arr, len, &new_len, &new_arr);
    if(new_arr == NULL){
        printf("error occured");
        return 1;
    }
    print_arr("\nNO DUPS ARRAY (FUNC 3): ", new_arr, new_len);

    free(new_arr);

    return 0;

}