#include <iostream>

using namespace std;
//create a graph
int graph[5][5] = {
    {0, 1, 1, 0, 0},
    {1, 0, 0, 1, 1},
    {1, 0, 0, 0, 1},
    {0, 1, 0, 0, 1},
    {0, 1, 1, 1, 0}
};

//print the graph
void printGraph(int graph[5][5]) {
    for (int i = 0; i < 5; i++) {
        for (int j = 0; j < 5; j++) {
            cout << graph[i][j] << " ";
        }
        cout << endl;
    }
}

//insert a node into the graph
void insertNode(int graph[][5], int node) {
    for (int i = 0; i < 5; i++) {
        graph[node][i] = 0;
        graph[i][node] = 0;
    }
}
//delete a node from the graph
void deleteNode(int graph[][5], int node) {
    for (int i = 0; i < 5; i++) {
        graph[node][i] = 0;
        graph[i][node] = 0;
    }
}

//search for a node in the graph
void searchNode(int graph[][5], int node) {
    for (int i = 0; i < 5; i++) {
        if (graph[node][i] == 1) {
            cout << "Node " << node << " is connected to node " << i << endl;
        }
    }
}

//depth first traversal
void depthFirstTraversal(int graph[][5], int node, int visited[]) {
    visited[node] = 1;
    cout << node << " ";
    for (int i = 0; i < 5; i++) {
        if (graph[node][i] == 1 && visited[i] == 0) {
            depthFirstTraversal(graph, i, visited);
        }
    }
}

//breadth first traversal
void breadthFirstTraversal(int graph[][5], int node, int visited[]) {
    int queue[5];
    int front = 0;
    int rear = 0;
    visited[node] = 1;
    queue[rear] = node;
    rear++;
    while (front != rear) {
        int current = queue[front];
        front++;
        cout << current << " ";
        for (int i = 0; i < 5; i++) {
            if (graph[current][i] == 1 && visited[i] == 0) {
                queue[rear] = i;
                rear++;
                visited[i] = 1;
            }
        }
    }
}

//find path from a vertex to another vertex
void findPath(int graph[][5], int node, int visited[], int destination) {
    visited[node] = 1;
    cout << node << " ";
    if (node == destination) {
        return;
    }
    for (int i = 0; i < 5; i++) {
        if (graph[node][i] == 1 && visited[i] == 0) {
            findPath(graph, i, visited, destination);
        }
    }
}

//find minimum spanning tree
void minimumSpanningTree(int graph[][5], int node, int visited[]) {
    visited[node] = 1;
    for (int i = 0; i < 5; i++) {
        if (graph[node][i] == 1 && visited[i] == 0) {
            cout << node << " " << i << endl;
            minimumSpanningTree(graph, i, visited);
        }
    }
}

//find subgraph given vertices
void subgraph(int graph[][5], int vertices[], int size) {
    for (int i = 0; i < size; i++) {
        for (int j = 0; j < size; j++) {
            cout << graph[vertices[i]][vertices[j]] << " ";
        }
        cout << endl;
    }
}
int main (){
    //select option
    int option;
    cout << "Select an option: " << endl;
    cout << "1. Print Graph" << endl;
    cout << "2. Insert Node" << endl;
    cout << "3. Delete Node" << endl;
    cout << "4. Search Node" << endl;
    cout << "5. Depth First Traversal" << endl;
    cout << "6. Breadth First Traversal" << endl;
    cout << "7. Find Path" << endl;
    cout << "8. Minimum Spanning Tree" << endl;
    cout << "9. Subgraph" << endl;
    cin >> option;
    //print graph
    if (option == 1) {
        printGraph(graph);
    }
    //insert node
    else if (option == 2) {
        int node;
        cout << "Enter node to insert: ";
        cin >> node;
        insertNode(graph, node);
    }
    //delete node
    else if (option == 3) {
        int node;
        cout << "Enter node to delete: ";
        cin >> node;
        deleteNode(graph, node);
    }
    //search node
    else if (option == 4) {
        int node;
        cout << "Enter node to search: ";
        cin >> node;
        searchNode(graph, node);
    }
    //depth first traversal
    else if (option == 5) {
        int node;
        cout << "Enter node to start traversal: ";
        cin >> node;
        int visited[5] = {0, 0, 0, 0, 0};
        depthFirstTraversal(graph, node, visited);
    }
    //breadth first traversal
    else if (option == 6) {
        int node;
        cout << "Enter node to start traversal: ";
        cin >> node;
        int visited[5] = {0, 0, 0, 0, 0};
        breadthFirstTraversal(graph, node, visited);
    }
    //find path
    else if (option == 7) {
        int node;
        cout << "Enter node to start traversal: ";
        cin >> node;
        int visited[5] = {0, 0, 0, 0, 0};
        int destination;
        cout << "Enter destination node: ";
        cin >> destination;
        findPath(graph, node, visited, destination);
    }
    //minimum spanning tree
    else if (option == 8) {
        int node;
        cout << "Enter node to start traversal: ";
        cin >> node;
        int visited[5] = {0, 0, 0, 0, 0};
        minimumSpanningTree(graph, node, visited);
    }
    //subgraph
    else if (option == 9) {
        int size;
        cout << "Enter number of vertices: ";
        cin >> size;
        int vertices[size];
        cout << "Enter vertices: ";
        for (int i = 0; i < size; i++) {
            cin >> vertices[i];
        }
        subgraph(graph, vertices, size);
    }
    return 0;

}
