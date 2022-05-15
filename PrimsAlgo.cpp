#include <iostream>
using namespace std;


/**********************************
Created on Wed May 05 12:59:26 2022

Name: Gobinath P
Roll No : CS21M501
Prim's Algorithm and Krushkal's Algorithm to Find Minimum Spanning Tree
************************************/

#define Inf 99999


// Set operations to avoid Cycles

// Find operation :
int Find(int m, int set[])
{
    int x = m,y = 0;
 
    while (set[x] > 0)
        x = set[x];
    while (m != x)
    {
        y = set[m];
        set[m] = x;
        m = y;
    }
    return x;
}


// Union operation :
void Union(int a, int b, int set[])
{
    if (set[a] < set[b])
    {
        set[a] += set[b];
        set[b] = a;
    } 
    else 
    {
        set[b] += set[a];
        set[a] = b;
    }
}


//****************************
// Main Program starts here
//****************************

int main() 
{


    cout << "\n*********************************************"<<endl;
    cout << "* Created on Wed May 05 12:59:26 2022       *"<<endl;
    cout << "* Name: Gobinath P                          *"<<endl;
    cout << "* Roll No : CS21M501                        *"<<endl;
    cout << "* Prim's Algorithm and Krushkal's Algorithm *"<<endl;
    cout << "*********************************************"<<endl;


    // Initialization
    int Vert = 0, Vertex = 0,Edge = 0, Fin_edge = 0;
    int u,v,min,k,d;

    // User Input the Number of Vertices

    cout<< "Enter the Number of Vertices : ";
    cin>> Vert;
    cout<< "\n";
    
    // Create matrix leaving First column and row blank
    Vertex = Vert + 1;
    int a[Vertex];

    int weight[Vertex][Vertex];


    // Initialization of weights table with infinity :

   for (int i = 1; i < Vertex; i++)
    {
        for (int j = 1; j < Vertex; j++)
            weight[i][j] = Inf;
    }


    cout<<"\nOnly the Diagonal Elements are enough to get stored \nSince the Undirected Graph Weights are Symmeteric \n"<<endl;


    // Get Weights from User : 
    for (int i = 1; i < Vertex; i++)
    {
        cout<<"Enter values for row : "<<(i)<<endl;
        for (int j = i+1; j < Vertex; j++)
        {int z;
            cout<<"("<<i << " " << j<<") : ";
            cin>>z;
            // Set Infinity for No Edges
            if (z == 0)
                z = Inf;
            else
                Edge++;
            weight[i][j] = z;
            weight[j][i] = z;
            weight[j][i] = weight[i][j];

        }
    }

    cout<<"\n\nArray Table for Storing Edges' weights : \n"<<endl;


 
    cout<<" Destination | \t";
    for (int i = 1; i < Vertex; i++)
        cout<< i << "\t   ";
    cout<<endl;

    for (int i = 1; i < Vertex*9; i++)
        cout<< "-";
    cout<<endl;


    // Display Table
   for (int i = 1; i < Vertex; i++)
    {cout<<"Source Node" << i << " |\t";
        for (int j = 1; j < Vertex; j++)
        {
            cout<<weight[i][j] << "\t";
        }
        cout<<endl;
    }
 
    cout<<"\n\n***********************************************"<<endl;
    cout<<"***********************************************"<<endl;
    cout<<"*              Prim's Algorithm               *"<<endl;
    cout<<"***********************************************"<<endl;
    cout<<"***********************************************"<<endl;
    
    int n = sizeof(weight[0])/sizeof(weight[0][0]) - 1;
    int least = Inf;
    int track [Vertex], table[2][Vertex-2] = {0};
 
    // Initial: Find least weight edge
    for (int i = 1; i<Vertex; i++)
    {
        track[i] = Inf;  // Initialize track array with INFINITY
        for (int j = i; j<Vertex; j++)
        {
            if (weight [i][j] < least)
            {
                least = weight [i][j];
                u = i;
                v = j;
            }
        }
    }
    table[0][0] = u; table[1][0] = v;
    track[u] = track[v] = 0;
 
    // Initialize track array to track least weight edges
    for (int i = 1; i<Vertex; i++)
    {
        if (track[i] != 0)
        {
            if (weight [i][u] < weight [i][v])
                track[i] = u;
            else
                track[i] = v;
        }
    }
 
    // Repeat
    for (int i = 1; i<n-1; i++)
    {
        int k;
        least = Inf;
        for (int j = 1; j<Vertex; j++)
        {
            if (track[j] != 0 && weight [j][track[j]] < least)
            {
                k = j;
                least = weight [j][track[j]];
            }
        }
        table[0][i] = k;
        table[1][i] = track[k];
        track[k] = 0;
 
        // Update track array to track least weight edges
        for (int j = 1; j<Vertex; j++)
        {
            if (track[j] != 0 && weight [j][k] < weight [j][track[j]])
                track[j] = k;
        }
    }

    int total = 0;
    for (int i = 0; i<Vertex-2; i++)
    {
        int w = weight [table[0][i]][table[1][i]];
        cout << "The weight of (" << table[0][i] << "-" << table[1][i] << ") is " << w << endl;
        total += w;
        Fin_edge++;
    }
    cout << endl;
    cout << "Given Vertex : "<< Vert <<endl;
    cout << "Given Edges : "<< Edge <<endl;

    cout << "\n******************************************************************************************"<<endl;
    cout << "* The Total Weight of Min Spanning Tree using Prim's Algorithm is : " << total << endl;
    cout << "* Final Edges after Prim's Algorithm : "<< Fin_edge <<endl;
    cout << "* Time Complexity of the Algorithm is O(V**2)"<<endl;
    cout << "******************************************************************************************"<<endl;


    system("PAUSE");

    return EXIT_SUCCESS;
}