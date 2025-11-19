/*------------------------------------------------------
* Filename: squares.c
* Description: recursively calculate the squares needed to paint a rectangle
* Author: Golan Ziv
-------------------------------------------------------*/

#include <stdio.h>
#include <stdlib.h>

/*------------------------------------------------------
* Function Name - calc_paint
*
* Function Purpose - recursively calculate the squares needed to paint a rectangle
*
* Parameters –  [IN x - rectangle width] 
*		        [IN y - rectangle height]
*
* Return Values - void
*
* Author - Golan Ziv
-------------------------------------------------------*/
void calc_paint(int x, int y){
    if(x == y) printf("%dx%d ", x, y);
    if (x > y){
        calc_paint(x - y, y);
        printf("%dx%d ", y, y);
    }else if (y > x){
        calc_paint(x, y - x);
        printf("%dx%d ", x, x);
    }
}

/*------------------------------------------------------
* Function Name - main
*
* Function Purpose - take user input of rectangle width and height, and print the squares needed to paint it
*
* Return Values - int 0 for success, 1 for failure
*
* Author - Golan Ziv
-------------------------------------------------------*/
int main(){
    int x, y;

    printf("Enter rectangle dimensions (x,y): ");
    if(scanf(" %d,%d", &x, &y) != 2 || x <= 0 || y <= 0){
        printf("Bad Input!");
        return 1;
    }

    printf("\nThe squares needed to paint the rectangle are:\n");
    calc_paint(x, y);

    return 0;
}