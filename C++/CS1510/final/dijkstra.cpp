//Programmer: DAVID GARDINER               Date: 5/9/2017
//File: dijkstra.cpp                       Class: 1510 C
//Purpose: Use Dijkstra's algorithm to solve the minimum number of tokens to
//         travel between the airport and the robotbar.

#include <iostream>
#include <vector>
#include <map>
#include <list>
#include <queue>
using namespace std;

// Class that holds adjacency matrix and solves dijkstra's algorithm
class graph
{
  short vertices;                           // Number of vertices
  list< pair<short, short> > *adj_list;     // Holds vertex and weight

public:
  // Constructor
  graph(short v)
  {
    vertices = v;
    adj_list = new list< pair<short, short> >[vertices];
  }

  ~graph()
  {
    delete[] adj_list;
  }

  // Add an edge to the adjacency list
  void add_vertex(short u, short v, short w)
  {
    adj_list[u].push_back(make_pair(v, w));
  }

  // Solves shortest path (least tokens) from start to end
  void dijkstra_solver(short start, short end)
  {
    // Priority Queue that holds vertices and all their weights
    priority_queue< pair<short, short> > q;

    // Holds distances of vertices, assign all to 999 (infinity) to start
    vector<short> distance(vertices, 999);

    q.push(make_pair(start, 0)); // Add start into the queue
    distance[start] = 0;         // Set distance to be 0

    while (!q.empty()) // While still vertices to check
    {
        short u = q.top().first;  // Get vertex with smallest weight
        q.pop();                // Remove from the queue

        // For all vertices connected to u
        for (list< pair<short, short> >::iterator i = adj_list[u].begin();
             i != adj_list[u].end(); ++i)
        {
            short v = i->first;         // Get vertex
            short weight = i->second;   // Get weight of edge

            if (distance[v] > distance[u] + weight) // If shorter path
            {
                distance[v] = distance[u] + weight; // Updated weight of v
                q.push(make_pair(v, distance[v]));  // Add updated to the queue
            }
        }
    }

    cout << distance[end]; // Print distance to end (robotbar)
  }
};


int main()
{
  map <string, short> name_to_num; // Used to convert names to numbers
  string city_name;                // Name of the current city (graph)
  string stop_name;                // Name of current stop
  string connection_name;          // Name of connected stop
  short num_graphs;                // Number of graphs to check
  short num_stops;                 // Number of stops in each city
  short connections;               // Number of connections from stop
  short map_count;                 // To keep track of name conversion
  short distance;                  // Weight to next stop
  short airport;                   // Vertex number of the airport
  short robotbar;                  // Vertex number of the robotbar

  cin >> num_graphs;
  for(int i=0; i<num_graphs; i++)
  {
    map_count = 1; // Reset map_count
    cin >> city_name;
    cin >> num_stops;
    graph g(num_stops); // Create new graph
    for(int j=0; j<num_stops; j++)
    {
      cin >> stop_name;
      cin >> connections;
      if(!j) // If on first stop
        name_to_num[stop_name] = 0; // Set vertex number to be 0
      else
        // Check if name already found
        if(name_to_num.find(stop_name) == name_to_num.end())
          name_to_num[stop_name] = map_count++;
      if(stop_name == "airport") // Locate airport vertex number
        airport = name_to_num.find(stop_name)->second;
      else if(stop_name == "robotbar") // Locate robotbar vertex number
        robotbar = name_to_num.find(stop_name)->second;

      for(int k=0; k<connections; k++)
      {
        cin >> connection_name;
        cin >> distance;
        // Check if name already found
        if(name_to_num.find(connection_name) == name_to_num.end())
          name_to_num[connection_name] = map_count++;
        if(connection_name == "airport") // Locate airport vertex number
          airport = name_to_num.find(connection_name)->second;
        else if(connection_name == "robotbar") // Locate robotbar vertex number
          robotbar = name_to_num.find(connection_name)->second;
        // Add the vertex to the adjacency list
        g.add_vertex(name_to_num.find(stop_name)->second,
          name_to_num.find(connection_name)->second, distance);
      }
    }
    // Output minimum number of tokens to get from airport to robotbar in city
    cout << "#" << i+1 << " : " << city_name << ", ";
    g.dijkstra_solver(airport, robotbar);
    cout << " tokens." << endl;
    // Clear name-checking map for next graph
    name_to_num.clear();
  }
  return 0;
}
