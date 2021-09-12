//
// Created by styxw on 9/1/2021.
//

#ifndef CSE310PROJECT1_INSERTION_H
#define CSE310PROJECT1_INSERTION_H

#include <iostream>
#include <cstring>

void reverse(char A[]){
    int i, c;
    for (i=strlen(A)-1; i>=0; i--){ //i working backwards
        std::cout << A[i] << " "; //space for desired format in output
    }
}

char* charcount(char str[]){ //unused now --reverse and count have been combined
    int sum = 0;
    for (int i=0; i<127; i++){ //i=0 ascii begin 'NULL', i=127 ascii end 'DEL'
        sum = 0;
        for (int j=0; j<sizeof(str); j++){
            if((int)str[j] == i){
                sum = sum+1;
            }
        }
        if (sum>0){
            std::cout<<sum<<" "<<(char)i<<" ";
        }
    }
}

char* reversecount(char in[]){ //prototype of previous two combined
    unsigned short int i, j,sum;
    for (j=0; j<strlen(in); j++)
        for (i=strlen(in)-1; i>=0; i--){ //reverseing string
            //std::cout<<in;
            for (int a=32; a<126; a++){ //going through ascii 32='space'
                int sum=0;
                for (int b=0; b<sizeof(in); b++){ //was b=0; b>sizeof(in); b--
                    if((int)in[b] == a){
                    sum=sum+1;
                    }
                }
            if (sum==1){
                std::cout <<sum; //sum here seems to bug out
            }
        }
    std::cout<<" "<<in[i-j]<<" "; //combination of indices [i-j] results in co-lexicographic string
    break;

    }
}

void insertion_sort(char array[]){ //
    std::cout << "Sorting..." << std::endl; //self check
    int i=0, j, key=0; //iterators
    for (j=1; j< strlen(array); j++){ //starting at 1 instead of 0
        key = unsigned (array[j]); //insert array[j] into sorted sequence array[1...j-1]
        //std::cout << "for loop array[j]=" << array[j] << ", array[j-1]=" << array[j-1] << ", array[i]=" << array[i] << std::endl; //self check
        i = j-1;
        while (i >= 0 && array[i] > key){
            array[i+1] = array[i];
            i = i-1;
            //std::cout << "while loop array[i]=" << array[i] << ", array[j]=" << array[j] << std::endl; //self check
        array[i+1] = key;}
    }
    //series of print statement self checks to reorient
    std::cout << "lexicographic sorted array =" << array << std::endl; //now lexicographic  -- reverse array
    std::cout << "Reversing..." << std::endl;
    std::cout << "co-lexicographic sorted array =";
    reverse(array); //used as self check to confirm reversecount works.
    std::cout << std::endl;
    reversecount(array); //implementation of combination of reverse and counting algorithm
    std::cout << std::endl;
}
//using ASCII, co-lexicographical order


#endif //CSE310PROJECT1_INSERTION_H
