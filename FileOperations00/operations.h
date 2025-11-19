/*------------------------------------------------------
* Filename: operations.h
* Description: declaring the file operations functions
* Author: Golan Ziv
-------------------------------------------------------*/


#include <stdio.h>
#include <ctype.h>
#include <string.h>

void print_file(char *filename);

void copy_file(char *src_filename, char *dest_filename);

void analyze_file(char *filename);

void delete_line_from_file(char* filenmae, char* line_number_s);

int count_string_in_file(char* filename, char* word);
