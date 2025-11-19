/*------------------------------------------------------
* Filename: file_operations.c
* Description: a file operations console command, with 5 functions.
* Author: Golan Ziv
-------------------------------------------------------*/

#include "operations.h"

/*------------------------------------------------------
* Function Name - main
*
* Function Purpose - imitate a console command, with 4 commands.
*   analyze 
*   print file
*   copy file
*   delete line from file
*   count string in file 
*
* Parameters –  [IN argc - amount of arguments passed] 
*		        [IN argv - arguments array, can be copy s1 d1 OR del s 2]
*
* Return Values - 0
*
* Author - Golan Ziv
-------------------------------------------------------*/
int main(int argc, char* argv[]){
    int count;
    if(argc == 3){ //  If 2 parameters were given we will check the first string
        if(strcmp(argv[1], "display") == 0){
            printf("\n\nShowing file: %s\n\n", argv[2]);
            print_file(argv[2]);
        }
        else if(strcmp(argv[1], "analyze") == 0)
            analyze_file(argv[2]);
    }
    else if(argc == 4){ // If 3 parameters were given we will check the first string
        if(strcmp(argv[1], "copy") == 0)
            copy_file(argv[2], argv[3]);
        else if(strcmp(argv[1], "del") == 0)
            delete_line_from_file(argv[2], argv[3]);
        else if(strcmp(argv[1], "count") == 0){
            count = count_string_in_file(argv[2], argv[3]);
            if(count == -1) 
                printf("error with file %s", argv[2]);
            else 
                printf("The word: %s appears %d times in %s", argv[3], count , argv[2]);}
        else{
            printf("Unknown command <%s>", argv[1]);
        }
    }
    else{
        printf("Invalid parametres!\nexamples:\n");
        printf("\t display <filename> \n");
        printf("\t copy <src> <dest>\n");
        printf("\t analyze <filename> \n");
        printf("\t del <filename> <line-number>\n");
        printf("\t count <filename> <string>\n");
    }            

    return 0;
}