/*************************************************************************************************************************************************************************************
Name	: Indresh Kumar Gupta
Roll 	: B15317
Purpose	: IC-250 Assignment-04 Part-4 : To find transpose of a sparse matrix using its 3-tuple form 
Date	: 6/09/16
************************************************************************************************************************************************************************************/

#include"sparse.h"

//function to find tranformation of matrix (in 3-tuple form) only non zero elements
void Fast_transform(struct sparse* trans, struct sparse p, int row[], int col[]){

	int i;
	int offset;

	trans->row = p.row;
	trans->sp = (int*) malloc(trans->row * 3 * sizeof(int));

	*(trans->sp + 0) = *(p.sp + 1);
	*(trans->sp + 1) = *(p.sp + 0);
	*(trans->sp + 2) = *(p.sp + 2);

	for(i = 3; i < trans->row * 3; i++)
		*(trans->sp + i) = 0;
	
	for(i = 3; i < p.row * 3; i+= 3){
	
		if(*(p.sp + i + 1) == 0)
			offset = 3;
		else
			offset = (3 * (col[*(p.sp + i + 1) - 1] + 1));			
		
		while(*(trans->sp + offset + 2) != 0)
			offset += 3;

		*(trans->sp + offset + 0) = *(p.sp + i + 1);
		*(trans->sp + offset + 1) = *(p.sp + i + 0);
		*(trans->sp + offset + 2) = *(p.sp + i + 2);
	}	
}

//function to print a 2d matrix by using its 3-tuple form
void display2d(struct sparse mat){
	
	//r : row no.
	int i, r = -1;
	
	//offset for current row in 3-tuple form
	int offset = 3;
	for(i = 0; i < *(mat.sp + 0) * *(mat.sp + 1); i++){
		
		if((i%*(mat.sp+0)) == 0){
			printf("\n");
			r++;
		}
	
		//checks whether element for (i,j) is non-zero
		if(*(mat.sp + offset) == r){
			if(*(mat.sp + offset + 1) == (i%*(mat.sp + 0))){
				printf("%d\t", *(mat.sp + offset + 2));
				offset += 3;
				continue;
			}
		}
		
		printf("0\t");
	}

	printf("\n");
}

int main(int argc, char* argv[]){
	//matrices (s1 : sparse matrix), (s2 : 3-tuple form of s1 matrix) and (s3 : 3-tuple form of transpose of s1)
	struct sparse s1, s2, s3 ;
	
	//row and column of s1
	int Row_m;
	int Col_n;

	system("clear");
	
	//checks whether appropriate no. of arguments are provided or not
	if(argc != 3)
 	{
		printf("Usage: Requires two parameters \n \t[a] No of Rows ( > 0),\n \t[b] No of Columns ( > 0)\n");
		exit(0);
	}
	
	Row_m=atoi(argv[1]);
	Col_n=atoi(argv[2]);
	
	int row[Row_m], col[Col_n], i;
	
	for(i = 0; i < Row_m; i++)
		row[i] = 0;
	
	for(i = 0; i < Col_n; i++)
		col[i] = 0;

	printf ( "Please Input the Sparse Matrix element by element : \n") ;
	create_array ( &s1 ,Row_m, Col_n) ;

	printf ( "The Input Sparse Matrix with %d Non-Zero Element is Displayed Below : \n", count ( s1 ,Row_m, Col_n)) ;
	display ( s1 ,Row_m, Col_n) ;

	create_tuple ( &s2, s1, Row_m, Col_n, row, col) ;
	printf ( "Sparse Representation of Non-Zero Elements (in 3-tuple form): \n" ) ;
	display_tuple ( s2 ,Row_m, Col_n , row , col) ;

	Fast_transform(&s3, s2, row, col);
	printf("\nTransformed matrix (in 3-tuple form):\n");
	display_tuple(s3, Row_m, Col_n, row, col);

	printf("\nTranformed matrix : \n");
	display2d(s3);


	return 0 ;
}
