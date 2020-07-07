#include <bits/stdc++.h>

using namespace std;

class Graph {
private:
	int n=9;
    pair<int,int> graph[15][15] = { { {0,0}, {4,300}, {0,0}, {0,0}, {0,0}, {0,0}, {0,0}, {8,600}, {0,0} },
                             { {4,300}, {0,0}, {8,600}, {0,0}, {0,0}, {0,0}, {0,0}, {11,850}, {0,0} },
                             { {0,0}, {8,600}, {0,0}, {7,550}, {0,0}, {4,300}, {0,0}, {0,0}, {2,150} },
                             { {0,0}, {0,0}, {7,550}, {0,0}, {9,650}, {14,1050}, {0,0}, {0,0}, {0,0} },
                             { {0,0}, {0,0}, {0,0}, {9,650}, {0,0}, {10,750}, {0,0}, {0,0}, {0,0} },
                             { {0,0}, {0,0}, {4,300}, {14,1050}, {10,750}, {0,0}, {2,150}, {0,0}, {0,0} },
                             { {0,0}, {0,0}, {0,0}, {0,0}, {0,0}, {2,150}, {0,0}, {1,75}, {6,450} },
                             { {8,600}, {11,850}, {0,0}, {0,0}, {0,0}, {0,0}, {1,75}, {0,0}, {7,550} },
                             { {0,0}, {0,0}, {2,150}, {0,0}, {0,0}, {0,0}, {6,450}, {7,550}, {0,0} } };

public:

	void displayAdjacencyMatrix()
	{
		cout << "\n\nAdjacency Matrix:";
		for (int i = 0; i < n; ++i) {
			cout << "\n";
			for (int j = 0; j < n; ++j) {
				cout <<graph[i][j].first<<","<<graph[i][j].second<<" ";
			}
			cout<<endl;
		}
	}

	void addAirport()
	{
		n++;
		int i;
		for (i = 0; i < n; ++i) {
			graph[i][n - 1].first= 0;
			graph[n - 1][i].first = 0;
			graph[i][n - 1].second = 0;
			graph[n - 1][i].second = 0;
		}
		cout<<"\nAirport added successfully!";
	}

	void removeAirport(int x)
	{
		if (x > n) {
			cout << "\nAirport not present!";
			return;
		}
		else {
			int i;
			while (x < n) {
				for (i = 0; i < n; ++i) {
					graph[i][x].first = graph[i][x + 1].first;
					graph[i][x].second = graph[i][x + 1].second;
				}

				for (i = 0; i < n; ++i) {
					graph[x][i].first = graph[x + 1][i].first;
					graph[x][i].second = graph[x + 1][i].second;
				}
				x++;
			}
			n--;
		}
		cout<<"\nAirport deleted successfully!";
	}

	void addRoute(int x, int y,int distw,int farew)
    {
        if ((x >= n) || (y >=n)) {
            cout << "Airport does not exists!";
            return;
        }

        if (x == y) {
            cout << "Same Airport!";
            return;
        }
        else {
            graph[y][x].first = distw;
            graph[x][y].first = distw;
            graph[x][y].second=farew;
            graph[y][x].second=farew;
        }
        cout<<"\nRoute added successfully!";
        cout << "\n\nAdjacency Matrix:";
		for (int i = 0; i < n; ++i) {
			cout << "\n";
			for (int j = 0; j < n; ++j) {
				cout <<graph[i][j].first<<","<<graph[i][j].second<<" ";
			}
			cout<<endl;
		}
    }

    void deleteRoute(int x, int y)
    {
        if ((x >= n) || (y >= n)) {
            cout << "Airport does not exists!";
            return;
        }
        if (x == y) {
            cout << "Same Airport!";
            return;
        }
        else {
            graph[y][x].first = 0;
            graph[x][y].first = 0;
            graph[y][x].second=0;
            graph[x][y].second=0;
        }
        cout<<"\nRoute deleted successfully!";
        cout << "\n\nAdjacency Matrix:";
		for (int i = 0; i < n; ++i) {
			cout << "\n";
			for (int j = 0; j < n; ++j) {
				cout <<graph[i][j].first<<","<<graph[i][j].second<<" ";
			}
			cout<<endl;
		}
    }

    void update(int x, int y,int dist_u,int fare_u)
    {
        if ((x >= n) || (y >=n)) {
            cout << "Airport does not exists!";
            return;
        }

        if (x == y) {
            cout << "Same Airport!";
            return;
        }
        else {
            graph[y][x].first = dist_u;
            graph[x][y].first = dist_u;
            graph[x][y].second=fare_u;
            graph[y][x].second=fare_u;
        }
        cout<<"\nRoute updated successfully!";
        cout << "\n\nAdjacency Matrix:";
		for (int i = 0; i < n; ++i) {
			cout << "\n";
			for (int j = 0; j < n; ++j) {
				cout <<graph[i][j].first<<","<<graph[i][j].second<<" ";
			}
			cout<<endl;
		}
    }

    int minDistance(int dist[], bool visited[])
    {
       int minm = INT_MAX, min_index;

       for (int v = 0; v < n; v++){
           if (visited[v] == false && dist[v] <= minm){
               minm = dist[v], min_index = v;
           }
       }
       return min_index;
    }

    void srctoallnodes()
    {
        cout<<"\nEnter source airport: ";
        int src;
        cin>>src;
        if(src>=n){
            cout<<"\nAiport does not exist!";
            return;
        }
        else{
        int dist[n];

        bool visited[n];

        for (int i = 0; i < n; i++){
            dist[i] = INT_MAX, visited[i] = false;
        }
        dist[src] = 0;
        for (int cnt = 0; cnt < n - 1; cnt++) {
            int u = minDistance(dist, visited);

            visited[u] = true;
            for (int v = 0; v < n; v++){
                if (!visited[v] && graph[u][v].first && dist[u] != INT_MAX && dist[u] + graph[u][v].first < dist[v]){
                    dist[v] = dist[u] + graph[u][v].first;
                }
            }
        }
        cout<<"\n\nAirport\t\tMinimum Distance from Source Airport";
        for (int i = 0; i < n; i++){
            cout<<"\n"<<i<<"\t\t"<<dist[i];
        }
        }
    }

    void srctodest()
    {
        cout<<"\nEnter source airport: ";
        int src;
        cin>>src;
        cout<<"\nEnter destination airport: ";
        int dest;
        cin>>dest;
        if((src>=n) || (dest>=n)){
            cout<<"\nAiport does not exist!";
            return;
        }
        else{
        int dist[n];

        bool visited[n];

        for (int i = 0; i < n; i++){
            dist[i] = INT_MAX, visited[i] = false;
        }
        dist[src] = 0;
        for (int cnt = 0; cnt < n - 1; cnt++) {
            int u = minDistance(dist, visited);
            visited[u] = true;
            for (int v = 0; v < n; v++){
                if (!visited[v] && graph[u][v].first && dist[u] != INT_MAX && dist[u] + graph[u][v].first < dist[v]){
                    dist[v] = dist[u] + graph[u][v].first;
                }
            }
        }
        if(src<dest){
           cout<<"\nMinimum distance from Source Airport "<<src<<" to Destination Airport "<<dest<<" is: ";
           for (int i = src; i <= dest; i++)
           {
                if(i==dest){
                cout<<dist[i]<<"\n";
                break;
                }
           }
        }
        else{
           cout<<"\nMinimum distance from Source Airport "<<src<<" to Destination Airport "<<dest<<" is: ";
           for (int i = dest; i <= src; i++)
           {
                if(i==dest){
                cout<<dist[i]<<"\n";
                break;
                }
           }
        }
        }
    }

    void floyydwarshall()
    {

        for(int src=0;src<n;src++){cout<<"\n\n------FOR "<<src<<"th Airport----------\n";

        int dist[n];
        bool visited[n];
        for (int i = 0; i < n; i++){
            dist[i] = INT_MAX, visited[i] = false;
        }
        dist[src] = 0;
        for (int cnt = 0; cnt < n - 1; cnt++) {
            int u = minDistance(dist, visited);

            visited[u] = true;
            for (int v = 0; v < n; v++){
                if (!visited[v] && graph[u][v].first && dist[u] != INT_MAX && dist[u] + graph[u][v].first < dist[v]){
                    dist[v] = dist[u] + graph[u][v].first;
                }
            }
        }
        cout<<"Aiport \t\tDistance from Source Airport\n";
        for (int i = 0; i < n; i++){
            cout<<"\n"<<i<<"\t\t"<<dist[i];
        }
    }}

    int minfare(int fare[], bool visited[])
    {
       int minm = INT_MAX, min_index;

       for (int v = 0; v < n; v++){
           if (visited[v] == false && fare[v] <= minm){
               minm = fare[v], min_index = v;
           }
       }
       return min_index;
    }

    void fares()
    {
        cout<<"\nEnter Source Airport: ";
        int src;
        cin>>src;
        if(src>=n){
            cout<<"\nAiport does not exist!";
            return;
        }
        else{
        int fa[n];

        bool visited[n];

        for (int i = 0; i < n; i++){
            fa[i] = INT_MAX, visited[i] = false;
        }
        fa[src] = 0;
        for (int cnt = 0; cnt < n - 1; cnt++) {
            int u = minfare(fa, visited);

            visited[u] = true;
            for (int v = 0; v < n; v++){
                if (!visited[v] && graph[u][v].second && fa[u] != INT_MAX && fa[u] + graph[u][v].second < fa[v]){
                    fa[v] = fa[u] + graph[u][v].second;
                }
            }
        }
        cout<<"Airport\t\tFare from Source\n";
        for (int i = 0; i < n; i++){
            cout<<"\n"<<i<<"\t\t"<<fa[i];
        }
    }
    }
};

int main()
{
    Graph obj;
    cout<<"\n*************** WELCOME TO FLIGHT MANAGEMENT SYSTEM **************************\n";
    cout<<"\n1. Add an Airport";
    cout<<"\n2. Delete an Airport";
    cout<<"\n3. Add a route";
    cout<<"\n4. Delete a route";
    cout<<"\n5. Update route fare and route distance";
    cout<<"\n6. Calculate source to destination shortest path";
    cout<<"\n7. Calculate single source to all node shortest path";
    cout<<"\n8. Shortest path prediction on basis of minimum distance";
    cout<<"\n9. Shortest path prediction on basis of minimum fare";
    cout<<"\n10. Calculate all airports to all airports shortest path\n\n";

    cout<<"Enter your choice: ";
    int choice;
    cin>>choice;
    while(choice!=-1){
    if(choice==1)
    {
        obj.addAirport();
    }
    else if (choice==2)
    {
        cout<<"\nEnter the airport to remove: ";
        int n;
        cin>>n;
        obj.removeAirport(n);
    }
    else if(choice ==3)
    {
        cout<<"\nTo add a route, please enter the following details:\n";
        cout<<"\nEnter the source airport: ";
        int src;
        cin>>src;
        cout<<"\nEnter the destination airport: ";
        int dest;
        cin>>dest;
        cout<<"\nEnter the distance between them: ";
        int d;
        cin>>d;
        cout<<"\nEnter the fare: ";
        int f;
        cin>>f;
        obj.addRoute(src, dest, d, f);
    }
    else if(choice ==4)
    {
        cout<<"\nTo delete a route, please enter the following details:\n";
        cout<<"\nEnter the source airport: ";
        int src;
        cin>>src;
        cout<<"\nEnter the destination airport: ";
        int dest;
        cin>>dest;
        obj.deleteRoute(src, dest);
    }
    else if(choice ==5)
    {
        cout<<"\nTo update a route, please enter the following details:\n";
        cout<<"\nEnter the source airport: ";
        int src;
        cin>>src;
        cout<<"\nEnter the destination airport: ";
        int dest;
        cin>>dest;
        cout<<"\nEnter the updated distance between them: ";
        int d;
        cin>>d;
        cout<<"\nEnter the updated fare: ";
        int f;
        cin>>f;
        obj.update(src, dest, d, f);
    }
    else if(choice ==6)
    {
        obj.srctodest();
    }
    else if(choice ==7)
    {
        obj.srctoallnodes();
    }
    else if(choice ==8)
    {
        obj.srctoallnodes();
    }
    else if(choice ==9)
    {
        obj.fares();
    }
    else if(choice ==10)
    {
        obj.floyydwarshall();
    }
    else{
        cout<<"\nPlease enter a valid choice";
    }

    cout<<"\n\nEnter your choice(to exit enter -1): ";
    cin>>choice;
}
cout<<"\n*************** THANKS FOR VISITING **************************\n";
}

