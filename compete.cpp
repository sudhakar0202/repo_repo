#include <iostream>
#include <stack>
#include <algorithm>
#include <math.h>
#include <vector>
#include <unordered_map>
#include <cstdlib>
// This constant can be avoided by explicitly
// calculating height of Huffman Tree
#define MAX_TREE_HT 100
using namespace std;


int maxWater(int arr[], int n)
{
    // To store the maximum water
    // that can be stored
    int res = 0;
 
    // For every element of the array
    for (int i = 1; i < n - 1; i++) {
 
        // Find the maximum element on its left
        int left = arr[i];
        for (int j = 0; j < i; j++)
            left = max(left, arr[j]);
 
        // Find the maximum element on its right
        int right = arr[i];
        for (int j = i + 1; j < n; j++)
            right = max(right, arr[j]);
 
        // Update the maximum water
        res = res + (min(left, right) - arr[i]);
    }
 
    return res;
}

// A Huffman tree node
struct MinHeapNode {

	// One of the input characters
	char data;

	// Frequency of the character
	unsigned freq;

	// Left and right child of this node
	struct MinHeapNode *left, *right;
};

// A Min Heap: Collection of
// min-heap (or Huffman tree) nodes
struct MinHeap {

	// Current size of min heap
	unsigned size;

	// capacity of min heap
	unsigned capacity;

	// Array of minheap node pointers
	struct MinHeapNode** array;
};

// A utility function allocate a new
// min heap node with given character
// and frequency of the character
struct MinHeapNode* newNode(char data, unsigned freq)
{
	struct MinHeapNode* temp
		= (struct MinHeapNode*)malloc
(sizeof(struct MinHeapNode));

	temp->left = temp->right = NULL;
	temp->data = data;
	temp->freq = freq;

	return temp;
}

// A utility function to create
// a min heap of given capacity
struct MinHeap* createMinHeap(unsigned capacity)

{

	struct MinHeap* minHeap
		= (struct MinHeap*)malloc(sizeof(struct MinHeap));

	// current size is 0
	minHeap->size = 0;

	minHeap->capacity = capacity;

	minHeap->array
		= (struct MinHeapNode**)malloc(minHeap->
capacity * sizeof(struct MinHeapNode*));
	return minHeap;
}

// A utility function to
// swap two min heap nodes
void swapMinHeapNode(struct MinHeapNode** a,
					struct MinHeapNode** b)

{

	struct MinHeapNode* t = *a;
	*a = *b;
	*b = t;
}

// The standard minHeapify function.
void minHeapify(struct MinHeap* minHeap, int idx)

{

	int smallest = idx;
	int left = 2 * idx + 1;
	int right = 2 * idx + 2;

	if (left < minHeap->size && minHeap->array[left]->
freq < minHeap->array[smallest]->freq)
		smallest = left;

	if (right < minHeap->size && minHeap->array[right]->
freq < minHeap->array[smallest]->freq)
		smallest = right;

	if (smallest != idx) {
		swapMinHeapNode(&minHeap->array[smallest],
						&minHeap->array[idx]);
		minHeapify(minHeap, smallest);
	}
}

// A utility function to check
// if size of heap is 1 or not
int isSizeOne(struct MinHeap* minHeap)
{

	return (minHeap->size == 1);
}

// A standard function to extract
// minimum value node from heap
struct MinHeapNode* extractMin(struct MinHeap* minHeap)

{

	struct MinHeapNode* temp = minHeap->array[0];
	minHeap->array[0]
		= minHeap->array[minHeap->size - 1];

	--minHeap->size;
	minHeapify(minHeap, 0);

	return temp;
}

// A utility function to insert
// a new node to Min Heap
void insertMinHeap(struct MinHeap* minHeap,
				struct MinHeapNode* minHeapNode)

{

	++minHeap->size;
	int i = minHeap->size - 1;

	while (i && minHeapNode->freq < minHeap->array[(i - 1) / 2]->freq) {

		minHeap->array[i] = minHeap->array[(i - 1) / 2];
		i = (i - 1) / 2;
	}
}
int main()
{
	int arr[5]={1,2,3,4,5};
	char arr1[] = { 'a', 'b', 'c', 'd', 'e', 'f' };
	int freq[] = { 5, 9, 12, 13, 16, 45 };

	int size = sizeof(arr1) / sizeof(arr1[0]);

	HuffmanCodes(arr1, freq, size);
	
	return 0;
}
