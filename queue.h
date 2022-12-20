#include <iostream>

#define SIZE 7 //size of the queue

class queue{
    private:
        int arr[SIZE]; //array to hold the queue
        int front; //keep track of the front of the queue
        int rear; //keep track of the rear of the queue
        int count; //keep track of the number of elements in the queue
    public:
        queue(); //default constructor
        void enqueue(int value); //add an element to the queue
        void dequeue(); //remove an element from the queue
        bool isEmpty(); //check if the queue is empty
        void printQueue(); //print the queue
        void advance(int &index); //used to increment the index of the queue to help with circular array
        int frontOfQueue(); //return the front of the queue, but don't remove it
};