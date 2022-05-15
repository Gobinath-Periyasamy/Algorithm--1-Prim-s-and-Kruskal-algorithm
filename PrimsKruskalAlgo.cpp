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

// Kruskal's Algorithm :
 
    cout<<"\n\n***********************************************"<<endl;
    cout<<"***********************************************"<<endl;
    cout<<"*          Krushkal's Algorithm               *"<<endl;
    cout<<"***********************************************"<<endl;
    cout<<"***********************************************"<<endl;

    int Edge_table[3][Edge] = {{0}};
    int x = -1,y = 0, cost;

    for (int i = 1; i < Vertex; i++)
    {

        for (int j = i+1; j < Vertex; j++)
        {
            int z = weight[i][j];
            if (z != Inf)
            { x++;
                //cout<<x << " "<<i<<" "<<j<<" "<<z<< " \n";
                Edge_table[0][x] = {i};
                Edge_table[1][x] = {j};
                Edge_table[2][x] = {z};
            }

        }
        //cout<<Edge_table[0][x] << " "<<Edge_table[1][x]<<" "<<Edge_table[2][x]<< " \n";

    }


    cout<<"\nEdge Table : \n\n";
    for (int i = 0; i < Edge; i++)
    {
        {
            cout<< Edge_table[0][i] << "\t";
            cout<< Edge_table[1][i] << "\t";
            cout<< Edge_table[2][i] << "\t";
            //cout<< Edge_table[3][i] << "\t";
        }
        cout<<endl;
    }

    int Vert_k = Vertex - 1, E = Edge;

    // Solution array
    int solution[3][Vert_k-1];

    // Track edges that are included in solution
    int k_trk[E]  {0}; 

    // Array for finding cycle
    int set[Vertex] = {-1, -1, -1, -1, -1, -1, -1, -1};  
 
    int i = 0;
    while (i < Vert_k-1){
        int min = Inf;
        int u = 0, v = 0, k = 0, d =0;
 
        // Find a minimum cost edge
        for (int j = 0; j<E; j++)
        {
            if (k_trk[j] == 0 && Edge_table[2][j] < min)
            {
                min = Edge_table[2][j];
                u = Edge_table[0][j];
                v = Edge_table[1][j];
                d = Edge_table[2][j];
                k = j;
            }
        }
 
        // Check if the selected min cost edge (u, v) forming a cycle or not
        if (Find(u, set) != Find(v, set))
        {
            solution[0][i] = u;
            solution[1][i] = v;
            solution[2][i] = d;
 
            // Perform union
            Union(Find(u, set), Find(v, set), set);
            i++;
        }
        k_trk[k] = 1;
    }
 
    cout << "\nMinimum Cost Spanning Tree Edges\n" << endl;
    cost = 0;
    for (int i = 0; i<Vert_k-1; i++)
    {
        cout << "ACycle Min Edge "<<i+1<<" : (" << solution[0][i] << "," << solution[1][i] << ")" <<"--->\t" << solution[2][i] <<endl;
        cost += solution[2][i];

    }
    cout << endl;

    cout << "\n******************************************************************************************"<<endl;
    cout << "* The Total Weight of Min Spanning Tree using Krushkal's Algorithm is : " << cost << endl;
    cout << "* Final Edges after Krushkal's Algorithm : "<< i <<endl;
    cout << "* Time Complexity of the Algorithm is O(ElogV)"<<endl;
    cout << "******************************************************************************************"<<endl;

    system("PAUSE");

    return EXIT_SUCCESS;
}