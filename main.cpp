//Programmer: Roman Morasco
//Task: Perform a breadth first search on a graph using an adjacency matrix and a queue
//Date: 12/7/2022

#include "queue.h"
#include <iostream>

#define GRAPH_SIZE 7 //number of vertices in the graph

const int rows = GRAPH_SIZE; //number of rows in the graph
const int cols = GRAPH_SIZE; //number of columns in the graph

//Pre-condition: The graph must be defined, the vertex names must be defined, and the start vertex must be defined
//Post-condition: A breadth first search is performed on the graph that returns the distance between the start vertex and all other vertices
void breadthFirstSearch(int Graph[rows][cols], std::string vertexNames[], int startVertex);

//Pre-condition: Start vertex must be intitialized in main
//Post-condition: Start vertex is set to the vertex the user wants to start from
void getUserInput(int &startVertex);

int main(void) {
    int startVertex = 0; //store the vertex we want to start from

    int Graph[rows][cols] = //create the graph using an adjacency matrix
    {
        0, 1, 1, 0, 0, 0, 0,
        1, 0, 0, 0, 1, 0, 0,
        1, 0, 0, 1, 1, 0, 0,
        0, 0, 1, 0, 0, 1, 0,
        0, 1, 1, 0, 0, 1, 0,
        0, 0, 0, 1, 1, 0, 1,
        0, 0, 0, 0, 0, 1, 0,
    };

    std::string vertexNames[GRAPH_SIZE] = {"Joe", "Eva", "Taj", "Chen", "Lily", "Jun", "Ken"}; //create an array of vertex names

    getUserInput(startVertex); //get the vertex we want to start from

    breadthFirstSearch(Graph, vertexNames, startVertex); //perform a breadth first search


    return 0;
}


void breadthFirstSearch(int Graph[rows][cols], std::string vertexNames[], int startVertex) {
    queue q; //create a queue
    bool visited[GRAPH_SIZE] = {false, false, false, false, false, false, false}; //keep track of visited vertices
    int currentVertex; //keep track of the current vertex
    int distanceBetween[GRAPH_SIZE] = {0, 0, 0, 0, 0, 0, 0}; //keep track of distances between vertices

    q.enqueue(startVertex); //enqueue the start vertex
    visited[startVertex] = true; //we just visited the start vertex

    //output distance from start vertex to start vertex as it will always be 0
    std::cout << "Path from " << vertexNames[startVertex] << " to " << vertexNames[startVertex] << " is this long: " <<  distanceBetween[startVertex] << std::endl;

    while (!q.isEmpty()) {
        currentVertex = q.frontOfQueue(); //set current vertex to the most recently found vertex
        q.dequeue(); //dequeue the most recently found vertex, as it's "up next"

        for (int adjacentVertex = 0; adjacentVertex < rows; adjacentVertex++) {
            if (Graph[currentVertex][adjacentVertex] == 1 && !visited[adjacentVertex]) { //if theres an edge to a new vertex that we havent visited yet
                q.enqueue(adjacentVertex); //queue the unvisisted vertex
                visited[adjacentVertex] = true; //then visit it
                distanceBetween[adjacentVertex] = distanceBetween[currentVertex] + 1; /*distance between the new vertex and the start vertex is the distance between the current vertex and 
                the start vertex plus 1*/
                std::cout << "Path from " << vertexNames[startVertex] << " to " << vertexNames[adjacentVertex] << " is this long: " <<  distanceBetween[adjacentVertex] << std::endl; //output distance
            }
        }
    }
}

void getUserInput(int &startVertex) {
    //ask user for the vertex they want to start from and display a list of vertices to choose from
    std::cout << "Enter the name of the person you want to start from using the guidelines below: \n";
    std::cout << "0 for Joe, 1 for Eva, 2 for Taj, 3 for Chen, 4 for Lily, 5 for Jun, 6 for Ken \n\n";

    //get the users input and store it in startVertex, which is passed by reference
    std::cout << "Enter the number here: ";
    std::cin >> startVertex;

    while(startVertex < 0 || startVertex > 6) { //if the user enters a number that is not a vertex
        std::cout << "Invalid input, please try again. \n\n";
        getUserInput(startVertex); //call the function again
    }

    std::cout << std::endl; //add a new line for formatting
}