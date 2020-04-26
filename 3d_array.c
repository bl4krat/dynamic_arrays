// demo 3-dimensional dynamically-allocated array

#include <stdio.h>
#include <stdlib.h>


void print_3d_int_array(int*** array, int pages, int cols, int rows){
  for(int p = 0; p < pages; p++){

    // print top row
    printf("[p:%02d] ", p); //page label
    for(int c = 0; c < cols; c++){
      printf("[c:%02d] ", c);
    }
    printf ("\n");

    for(int r = 0; r < rows; r++){
      //print data row
      printf ("[r:%02d]  ", r); //label
      for (int c = 0; c < cols; c++){
        c == cols - 1 ? printf("%04d\n", array[p][c][r]) : printf("%04d   ", array[p][c][r]);
      }
    }
    printf("\n");
  }
}

void free_3d_array(int*** array, int pages, int cols){
    for(int p = 0; p < pages; p++){
        for(int c = 0; c < cols; c++){
          free(array[p][c]);
        }
        free(array[p]);
    }
    free(array);
}

int main(){
  int*** array;
  int array_pages =  8;
  int array_cols  =  6;
  int array_rows  =  5;

  array = malloc(array_pages * sizeof (*array));
  
  for(int p = 0; p < array_pages; p++){
    array[p] = malloc(array_cols * sizeof(**array));
    for(int c = 0; c < array_cols; c++){
      array[p][c] = malloc(array_rows * sizeof (***array));
      for(int r = 0; r < array_rows; r++){
        array[p][c][r] = (p * 100) + (c * 10) + r;
      }
    }
  }

  print_3d_int_array(array, array_pages, array_cols, array_rows);
  
  free_3d_array(array, array_pages, array_cols);
  return 0;
}
