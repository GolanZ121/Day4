/*------------------------------------------------------
* Filename: rectangle.c
* Description: implement a point and rectangle structs, calculate rectangle area
* Author: Golan Ziv
-------------------------------------------------------*/

#include <stdio.h>

typedef struct {
    float x;
    float y;
} Point;

typedef struct {
    Point top_left; 
    Point bottom_right; 
} Rectangle;


/*------------------------------------------------------
* Function Name - calc_area 
*
* Function Purpose - calculates the array of a rectangle
*
* Parameters –  [IN r - a Rectangle struct] 
*
* Return Values - float - rectangle area
*
* Author - Golan Ziv
-------------------------------------------------------*/
float calc_area(Rectangle r){
    float dx = r.top_left.x - r.bottom_right.x;
    float dy = r.top_left.y - r.bottom_right.y;
    return (dx * dy >= 0) ? dx * dy : -(dx * dy);
}

/*------------------------------------------------------
* Function Name - main
*
* Function Purpose - take user input to create a Rectangle struct and print its area
*
* Return Values - int 0 for success, 1 for failure
*
* Author - Golan Ziv
-------------------------------------------------------*/
int main(){
    int x, y;
    Rectangle r = {0};

    printf("Enter first point (x,y): ");
    if(scanf(" %f,%f", &r.top_left.x, &r.top_left.y) != 2){
        printf("Bad Input!");
        return 1;
    }

    printf("\nEnter second point (x,y): ");
    if(scanf(" %f,%f", &r.bottom_right.x, &r.bottom_right.y) != 2){
        printf("Bad Input!");
        return 1;
    }

    printf("\nArea: %.2f", calc_area(r));

    return 0;
}
