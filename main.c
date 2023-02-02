#include <stdio.h>
#include "employee.h"
#include "heap.h"

#define MAX_EMPLOYEES 5

int main(int argc, char *argv[])
{
	//TODO
	Employee A[MAX_EMPLOYEES];

	for(int i=0; i<MAX_EMPLOYEES; i++){
		
		printf("\nName: ");
		scanf("%s", A[i].name);
		printf("\nSalary: ");
		scanf("%d", &A[i].salary);
	}
	
	heapSort(A, MAX_EMPLOYEES);
	printList(A, MAX_EMPLOYEES);
	
	return 0;
}
