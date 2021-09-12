#include <iostream>
#include <cstdio>
#include <cstring>
#include "insertion.h"
#include "merge.h"


void rotation(char *input[]){ //used in part of circular_rotation
    unsigned long int n = strlen(reinterpret_cast<const char *>(input));
    char tmp[2*n+1]; //form temp string to combine & compare to indices
    strcpy(tmp, reinterpret_cast<const char *>(input)); //copy input onto tmp
    strcat(tmp, reinterpret_cast<const char *>(input)); //append input onto tmp
    unsigned long int i;
    for (i =n; i > 0 ; --i){ //backwards index
        for (int j=0; j < n ; j++){ //forwards index
            std::printf("%c", tmp[i+j]); //self check to print
        }
        std::cout << std::endl; //endline after loop to give each permutation a line
    }
}




int main(int argc, char *argv[]) {
    FILE* standardin = stdin; //set stream
    std::string *user_in;//using string pointer
    if (argc<2){ //if no insertion or merge
        std::cout << "Parameter Format error"; //simple error protocol for self check
    }
    switch (argv[1][0]) { //grabbing first letter of parameter
        case 'i': //insertion
            std::cout << "case 'i' read" << std::endl; //self check
            while (!std::feof(stdin)){ //while not EOF char --read stdin
                std::cout << "reading stdin" << std::endl;  //--self check
                std::scanf("%[^\t]" /*"%c"*/ , user_in); //[^t] should work with multiple lines instead of [^\n] which breaks
                rotation(reinterpret_cast<char**>(user_in)); //rotation uses char** input
                std::cout << "insertion sorting" << std::endl; //self check
                insertion_sort(reinterpret_cast<char *>(user_in)); //insertion uses char* array
                //index of permutation and counting str[0] chars handled in insertion.h
                break;
        case 'm':
            std::cout << "case 'm' read" << std::endl; //self check
            while (!std::feof(stdin)){ //while not EOF char --read stdin
                std::cout << "reading stdin" << std::endl;  //--self check
                std::scanf("%[^\t]", user_in); //[^t] should work with multiple lines instead of [^\n] which breaks
                rotation(reinterpret_cast<char**>(user_in)); //rotation uses char** input
                std:: cout << "merge sorting" << std::endl; //self check
                mergeSort(); //merge sort empty for now, but present to set up next chunk of code
                //index of permutation and counting str[0] chars to be handled in merge.h
                break;
            }
            }
    }
    return 0; //by normal convention
}
