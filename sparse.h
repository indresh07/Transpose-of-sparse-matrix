#include <stdio.h>
#include <malloc.h>
#include <stdlib.h>


struct sparse
{
	int *sp ;
	int row ;
} ;


void create_array ( struct sparse * ,int Row_m, int Col_n) ;
void display ( struct sparse, int Row_m, int Col_n ) ;
int count ( struct sparse ,int Row_m, int Col_n) ;
void create_tuple ( struct sparse *, struct sparse,int Row_m, int Col_n, int row[], int col[] ) ;
void display_tuple ( struct sparse ,int Row_m, int Col_n, int row[], int col[]) ;
