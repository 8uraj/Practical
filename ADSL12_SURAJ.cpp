#include <iostream>
#define MAX 20
#include <vector>
using namespace std;

class HeapTree 
{

public:
void heapify (int heap[], int curr, int size) 
  {
    
int largest = curr;
    
int l = 2 * curr + 1;
    
int r = 2 * curr + 2;
    
 
if (l < size && heap[l] > heap[largest])
      
      {
	
largest = l;
      
}
    
if (r < size && heap[r] > heap[largest])
      
      {
	
largest = r;
      
}
    
if (largest != curr)
      
      {
	
int temp = heap[curr];
	
heap[curr] = heap[largest];
	
heap[largest] = temp;
	
heapify (heap, largest, size);
      
}
  
} 
void HeapSort (int heap[], int n) 
  {
    
for (int i = n / 2 - 1; i >= 0; i--)
      
      {
	
heapify (heap, i, n);
    
} 
for (int i = n - 1; i > 0; --i)
      
      {
	
int temp = heap[0];
	
heap[0] = heap[i];
	
heap[i] = temp;
	
 
heapify (heap, 0, i);
  
} 
} 
void inputArray () 
  {
    
int heap[MAX];
    
int n;
    
cout << "ENTER THE SIZE OF THE ARRAY: " << endl;
    
cin >> n;
    
 
cout << "ENTER ARRAY ELEMENTS: " << endl;
    
for (int i = 0; i < n; i++)
      
      {
	
cin >> heap[i];
      
} 
HeapSort (heap, n);
    
cout << "SORTED ELEMENTS ARE: " << endl;
    
for (int i = 0; i < n; i++)
      
      {
	
cout << heap[i] << " ";

} 
} 
};


int
main () 
{
  
HeapTree h;
  
h.inputArray ();

}
