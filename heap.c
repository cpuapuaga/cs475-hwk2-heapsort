/*
 * heapsort.c
 *
 *  Created on: Jul 1, 2013
 *      Author:
 */
#include <stdio.h>
#include <stdlib.h>
#include "employee.h"
#include "heap.h"

/**
 * Sorts a list of n employees in descending order
 *
 * @param	*A	Pointer to the list of employees
 * @param	n	Size of the heap
 */
void heapSort(Employee *A, int n)
{
	// TODO - BuildHeap on the heap
	buildHeap(A, n);
	// TODO - while n > 0:
	while(n>0){
		// TODO - swap A[n-1] with A[0], since A[0] is the smallest number.
		// TODO - A[n-1] now sorted in place, so decrement n
		swap(&A[n-1], &A[0]);
		n--;
		for(int i = 0; i<n; i++) {
			// TODO - Heapify the elements from A[0] up to A[n-1] (which leaves the newly sorted element alone)
			heapify(A, 0, n);
			}
	}
	
	
	
}

/**
 * Given an array A[], we want to get A[] into min-heap property
 * We only need to run heapify() on internal nodes (there are floor(n/2) of them)
 * and we need to run it bottom up (top-down cannot build a heap)
 *
 * @param	*A	Pointer to the list of employees
 * @param	n	Size of the heap
 */
void buildHeap(Employee *A, int n)
{
	// TODO - heapify() every element from A[n/2] down-to A[0]
	for(int i=(n/2)-1; i>=0; i--){
		heapify(A, i, n);
	}
}

/**
 * We want to start with A[i] and percolate it downward
 * if it is greater than either left or right child.
 *
 * @param	*A	Pointer to the list of employees
 * @param	i	Index of current element to heapify
 * @param	n	Size of the heap
 */
void heapify(Employee *A, int i, int n)
{
	
	// TODO - get index of left child of element i
	int left = 2*(i+1)-1;
	// TODO - get index of right child of element i
	int right = 2*(i+1);
	// TODO - determine which child has a smaller salary. We'll call the index of this
	// element: "smaller"
	if (left < n) {
		int smaller = left;

		if (right < n) {
			if(A[left].salary > A[right].salary){
				smaller = right;
			} 
		}
		// TODO - recursively check if the salary at A[i] > the salary at A[smaller]. If it is, swap the two.
		//			Then recursively heapify A[smaller].
		if(A[i].salary > A[smaller].salary){
			swap(&A[i], &A[smaller]);
			heapify(A, smaller, n);
			
		}
	}
	
	
	// TODO - Continue recursion as long as i is within range AND either right_child and left_child are still within range.
}

/**
 * Swaps the locations of two Employees
 * @param *e1 An Employee
 * @param *e2 Another Employee to swap with
 */
void swap(Employee *e1, Employee *e2)
{
	Employee tmp = *e1;
  	*e1 = *e2;
  	*e2 = tmp;
}

/**
 * Outputs an array of Employees
 * @param	*A	Pointer to the list of employees
 * @param	n	Size of the list
 */
void printList(Employee *A, int n)
{
	printf("\n");
	for(int i=0; i<n; i++){
		printf("[id=%s, sal=%d]  ", A[i].name, A[i].salary);
	}
	printf("\n");
}
