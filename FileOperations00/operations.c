/*------------------------------------------------------
* Filename: operations.c
* Description: Implemeting 5 file operations: printing a file to stdin, 
        copying a file to another file, printing a files number of lines, words, and letters,
        deleting a line in a file, getting the number of occurences of a string in a file. 
* Author: Golan Ziv
-------------------------------------------------------*/

#include "operations.h"

/*------------------------------------------------------
* Function Name - print_file
*
* Function Purpose - opens file by file name and prints to console 
*
* Parameters –  [IN filename - a.txt] 
*
* Return Values - void
*
* Author - Golan Ziv
-------------------------------------------------------*/
void print_file(char *filename){
    FILE *fp;
    int c; 

    if(filename == NULL){
        printf("invalid filename\n");
        return;
    }

    fp = fopen(filename, "r");
    if(fp == NULL){
        printf("error with file %s\n", filename);
        return;
    }

    while((c = fgetc(fp)) != EOF)
        putchar(c); //printing every char to stdin

    fclose(fp);
}

/*------------------------------------------------------
* Function Name - copy_file 
*
* Function Purpose - copy contents between 2 files 
*
* Parameters –  [IN src_filename - a.txt] 
*		        [INOUT dest_filename - b.txt]

* Return Values - void
*
* Author - Golan Ziv
-------------------------------------------------------*/
void copy_file(char *src_filename, char *dest_filename){
    FILE *src_fp;
    FILE *dest_fp;
    int c; 

    if(src_filename == NULL || dest_filename == NULL) return;

    src_fp = fopen(src_filename, "r");
    
    if(src_fp == NULL){
        printf("error with file %s\n", src_filename);
        return;
    }
    
    dest_fp = fopen(dest_filename, "w");
    if(dest_fp == NULL){
        printf("error with file %s\n", dest_filename);
        fclose(src_fp);
        return;
    }

    while((c = fgetc(src_fp)) != EOF){
        if(fputc(c, dest_fp) != c){ // putting every char to thte destination file
            fclose(src_fp);    
            fclose(dest_fp);
            return;
        } 
    }
    

    fclose(src_fp);
    fclose(dest_fp);
}   

/*------------------------------------------------------
* Function Name - analyze_file
*
* Function Purpose - opens file and counts how many newlines, chars and words and prints 
*
* Parameters –  [IN filename - a.txt.] 
*
* Return Values - void
*
* Author - Golan Ziv
-------------------------------------------------------*/
void analyze_file(char *filename){
    FILE *fp;
    int in_word = 0;
    int newline_counter = 0, char_counter = 0, word_counter = 0;
    int c, read_non_whitespace = 0; 


    fp = fopen(filename, "r");
    if(fp == NULL){
        printf("error with file %s\n", filename);
        return;
    }

    while((c = fgetc(fp)) != EOF){
        if(c == (int)'\n'){ 
            if(read_non_whitespace) newline_counter++;

            read_non_whitespace = 0;
        }
        else read_non_whitespace = 1;

        if(!isalpha((unsigned char)c)){ // if the char is not from the ABC, that means we are currently not in a word
            in_word = 0;
        }else { //if it is in the ABC
            char_counter++; // we count it as a letter
            if(!in_word){ // if we werent in a word before it means we are now
                word_counter++; // we count the word
                in_word = 1; // we mark that we are in a word
            }
        }
    }
    if(read_non_whitespace) newline_counter++;

    printf("%d\n%d\n%d\n", newline_counter, word_counter, char_counter);

    fclose(fp);
}

/*------------------------------------------------------
* Function Name - delete_line_from_file
*
* Function Purpose - deletes a specific line from file 
*
* Parameters –  [IN filename - a.txt] 
*		        [IN line_number_s - "1", "123"] 

* Return Values - void
*
* Author - Golan Ziv
-------------------------------------------------------*/
void delete_line_from_file(char* filename, char* line_number_s){
    int line_n;
    int line_counter = 1;
    int c;
    char tmp[] = "temp.txt";
    FILE* fp, *tempfp;

    if(filename == NULL || line_number_s == NULL){
        printf("invalid input\n");
        return;
    }

    if(sscanf(line_number_s, "%d", &line_n) != 1 || line_n <= 0){
        printf("invalid line number\n");
        return;
    }

    fp = fopen(filename, "r");
    if(fp == NULL){
        printf("error with file %s\n", filename);
        return;
    }

    tempfp = fopen(tmp, "w");
    if(tempfp == NULL){
        printf("error while deleting line\n");
        fclose(fp);
        return;
    }


    // copy all contents of the file to the temp file 
    // except the specific line 
    while((c = fgetc(fp)) != EOF){
        if (line_counter != line_n){
            if(fputc(c, tempfp) != c){ 
                fclose(tempfp);
                fclose(fp);
                return;
            } 
        } 
        if (c == (int) '\n') line_counter++;        
    } 
    
    if (c != (int) '\n') line_counter++;        
    
    // close and open in different mode
    fclose(fp);
    fclose(tempfp);
    fp = fopen(filename, "w");
    tempfp = fopen(tmp, "r");

    if(fp == NULL || tempfp == NULL){
        printf("error reopening files\n");
        if(tempfp) fclose(tempfp);
        if(fp) fclose(fp);
        remove(tmp);
        return;
    }


    // copy back the contents of the temp file to the original file
    while((c = fgetc(tempfp)) != EOF){
        if(fputc(c, fp) != c){ 
            fclose(tempfp);
            fclose(fp);
            remove(tmp);
            return;
        } 
        
    }
    
    fclose(fp);
    fclose(tempfp);

    remove(tmp); // delete the temporary file
    return;
}

/*------------------------------------------------------
* Function Name - count_word_in_file
*
* Function Purpose - counts the amount of times a string is in a file 
*
* Parameters –  [IN filename - a.txt] 
*               [IN word - "some sentence"] 
*
* Return Values - void
*
* Author - Golan Ziv
-------------------------------------------------------*/
int count_string_in_file(char* filename, char* word){
    int count = 0;
    FILE* fp;
    int word_len = strlen(word);
    int c, i = 0;

    if(filename == NULL)
        return -1;
    

    fp = fopen(filename, "r");
    if(fp == NULL)
        return -1;
    
    while((c = fgetc(fp)) != EOF){
        if(c == word[i]){
            i++;
            if(i == word_len){
                count++;
                i=0;
            }
        }
        else
            i = 0;
    }

    fclose(fp);
    return count;
}
