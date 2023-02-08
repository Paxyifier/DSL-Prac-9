#include <iostream>
using namespace std;
#include <algorithm>
class Edge
{
public:
    int source;
    int dest;
    int weight;
};
bool compare(Edge e1, Edge e2)
{
    return e1.weight < e2.weight;
}
int findParent(int v, int *parent)
{
    if (parent[v] == v)
    {
        return v;
    }
    return findParent(parent[v], parent);
}
void krushkals(Edge *input, int n, int E)
{
    //sort the input array - ascending order based on weights
    sort(input, input + E, compare);
    Edge *output = new Edge[n - 1];
    int *parent = new int[n];
    for (int i = 0; i < n; i++)
    {
        parent[i] = i;
    }
    int count = 0;
    int i = 0;
    while (count != n - 1)
    {
        Edge currentEdge = input[i];
        //check if we can add the current edge in MST or not
        int sourceParent = findParent(currentEdge.source, parent);
        int destParent = findParent(currentEdge.dest, parent);
        if (sourceParent != destParent)
        {
            output[count] = currentEdge;
            count++;
            parent[sourceParent] = destParent;
        }
        i++;
    }
    cout << "Minimum Spanning Tree : -" << endl;
    for (int i = 0; i < n - 1; i++)
    {
        if (output[i].source < output[i].dest)
        {
            cout << output[i].source << " " << output[i].dest << " "
                 << output[i].weight << endl;
        }
        else
        {
            cout << output[i].dest << " " << output[i].source << " "
                 << output[i].weight << endl;
        }
    }
}
int main()
{
    int n, E;
    cout << "KRUSKAL'S ALGORITHM\nENTER NUMBER OF VERTICES : ";
    cin >> n;
    cout << "ENTER NUMBER OF EDGEES : ";
    cin >> E;
    Edge *input = new Edge[E];
    for (int i = 0; i < E; i++)
    {
        int s, d, w;
        cout << "ENTER VERTICES AND WEIGHT OF EDGE " << i + 1 << " : ";
        cin >> s >> d >> w;
        input[i].source = s;
        input[i].dest = d;
        input[i].weight = w;
    }
    krushkals(input, n, E);
}