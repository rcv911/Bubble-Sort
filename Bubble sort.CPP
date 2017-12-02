# include <stdio.h>
# include <stdlib.h>
# include <alloc.h>

int cp;
int *x,d;
char style;

int swap(int *a, int *b) { // swap elements
  int sw;
  sw=*a;
  *a=*b;
  *b=sw;
  return *a,*b;
}

int forward(int *m1, int *m2) {   // return largest element 
  if(*m1>*m2) {
    return swap(&*m1,&*m2);
  }
}

int backward(int *m1, int *m2) {   // return smallest element 
  if(*m1<*m2) {
    return swap(&*m1,&*m2);
  }
}


int bubble_sort(int *mas1,int *mas2,char *st) {
  if(*st=='f') {
    return forward(&*mas1,&*mas2);
  }
  if(*st=='b') {
    return backward(&*mas1,&*mas2);
  }
}


void main(void) {
  printf("\nChoose the style of bubble sort <'f' or 'b'>: ");
  scanf("%c",&style);
  printf("\n");
  printf("Lenght of arraay: ");
  scanf("%d",&cp);

  printf("Array: \n");
  x=(int *)malloc(cp*sizeof(int)); // allocate a block of size memory
  for(int id=0;id<cp;id++) {    // enter data from keyboard in array
    scanf("%i",&d);
    x[id]=d;
  }

  printf("\nOld array: ");
  for(int j=0;j<cp;j++) { // output array
    printf("%i ",x[j]);
  }
  printf("\n");

  for(int k=0;k<cp;k++) {    // bubble sort
    for(int z=cp-1;z>k;z--) {
      bubble_sort(&x[z-1],&x[z],&style);
    }
  }

  printf("New array: "); // output sort array
  for(int q=0;q<cp;q++) {
    printf("%i ",x[q]);
  }
  free(x); // deallocate memory block 
}
