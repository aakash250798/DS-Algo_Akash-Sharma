#include <bits/stdc++.h>
#include<cstdio>
#include<iostream>
using namespace std;

class Graph {
private:
	int n=9;
	int distance[9][9];
	int fare[9][9];

public:
template<typename T, int height, int width>
std::ostream& writemap(std::ostream& os, T (&map)[height][width])
{
    for (int i = 0; i < height; ++i)
    {
        for (int j = 0; j < width; ++j)
        {
            os << map[i][j]<<" ";
        }
        os<<"\n";
    }
    cout<<"------\n";
    return os;
}
	void displayAdjacencyMatrix()
	{
		cout << "\n\nAdjacency Matrix for distance:";
		for (int i = 0; i < n; ++i) {
			cout << "\n";
			for (int j = 0; j < n; ++j) {
				cout <<distance[i][j]<<" ";
			}
			cout<<endl;
		}

		cout << "\n\n Adjacency Matrix for fare:";
		for (int i = 0; i < n; ++i) {
			cout << "\n";
			for (int j = 0; j < n; ++j) {
				cout << fare[i][j]<<" ";
			}
			cout<<endl;
		}
	}

    void addAirport()
	{
	    ifstream myfile2; //for reading records
        myfile2.open("dist.txt");
        ifstream myfile1; //for reading records
        myfile1.open("fare.txt");

        ofstream temp;
        temp.open("temp.txt");
        ofstream temp1;
        temp1.open("temp1.txt");
        for(int row = 0; row < 9; row++){
        for(int column = 0; column < 9; column++){
            myfile2 >> distance[row][column];
            // from fp we read the characters
        }
    }
         for(int row = 0; row < 9; row++){
        for(int column = 0; column < 9; column++){
            myfile1 >> fare[row][column];
            // from fp we read the characters
        }
    }
		n++;
		int i;
		for (i = 0; i < n; ++i) {
			distance[i][n - 1] = 0;
			distance[n - 1][i] = 0;
			fare[i][n - 1] = 0;
			fare[n - 1][i] = 0;
		}
		cout<<"\nAirport added successfully!";
		std::fstream of("temp.txt", std::ios::out | std::ios::app);

    if (of.is_open())
    {
        writemap(of, distance);
        writemap(std::cout, distance);
        of.close();
    }
    myfile2.close();
    temp.close();
    remove("dist.txt");
    char oldname[]="temp.txt";
    char newname[]="dist.txt";
    rename(oldname, newname);

    std::fstream of1("temp1.txt", std::ios::out | std::ios::app);

    if (of1.is_open())
    {
        writemap(of1, fare);
        writemap(std::cout, fare);
        of1.close();
    }
    myfile1.close();
    temp1.close();
    remove("fare.txt");
    char oldname1[]="temp1.txt";
    char newname1[]="fare.txt";
    rename(oldname1, newname1);
	}



	void removeAirport(int x)
	{
	    ifstream myfile2; //for reading records
        myfile2.open("dist.txt");
        ifstream myfile1; //for reading records
        myfile1.open("fare.txt");

        ofstream temp;
        temp.open("temp.txt");
        ofstream temp1;
        temp1.open("temp1.txt");
        for(int row = 0; row < 9; row++){
        for(int column = 0; column < 9; column++){
            myfile2 >> distance[row][column];
            // from fp we read the characters
        }
    }
         for(int row = 0; row < 9; row++){
        for(int column = 0; column < 9; column++){
            myfile1 >> fare[row][column];
            // from fp we read the characters
        }
    }
		if (x > n) {
			cout << "\nAirport not present!";
			return;
		}
		else {
			int i;
			while (x < n) {
				for (i = 0; i < n; ++i) {
					distance[i][x] = distance[i][x + 1];
					fare[i][x] = fare[i][x + 1];
				}

				for (i = 0; i < n; ++i) {
					distance[x][i] = distance[x + 1][i];
					fare[x][i] = fare[x + 1][i];
				}
				x++;
			}
			n--;
		}
		cout<<"\nAirport deleted successfully!";
		std::fstream of("temp.txt", std::ios::out | std::ios::app);

    if (of.is_open())
    {
        writemap(of, distance);
        writemap(std::cout, distance);
        of.close();
    }
    myfile2.close();
    temp.close();
    remove("dist.txt");
    char oldname[]="temp.txt";
    char newname[]="dist.txt";
    rename(oldname, newname);

    std::fstream of1("temp1.txt", std::ios::out | std::ios::app);

    if (of1.is_open())
    {
        writemap(of1, fare);
        writemap(std::cout, fare);
        of1.close();
    }
    myfile1.close();
    temp1.close();
    remove("fare.txt");
    char oldname1[]="temp1.txt";
    char newname1[]="fare.txt";
    rename(oldname1, newname1);
	}




	void addRoute(int x, int y,int distw,int farew)
    {

	    ifstream myfile2; //for reading records
        myfile2.open("dist.txt");
        ifstream myfile1; //for reading records
        myfile1.open("fare.txt");

        ofstream temp;
        temp.open("temp.txt");
        ofstream temp1;
        temp1.open("temp1.txt");
        for(int row = 0; row < 9; row++){
        for(int column = 0; column < 9; column++){
            myfile2 >> distance[row][column];
            // from fp we read the characters
        }
    }
         for(int row = 0; row < 9; row++){
        for(int column = 0; column < 9; column++){
            myfile1 >> fare[row][column];
            // from fp we read the characters
        }
    }
        if ((x >= n) || (y > n)) {
            cout << "Airport does not exists!";
        }

        if (x == y) {
            cout << "Same Airport!";
        }
        else {
            distance[y][x] = distw;
            distance[x][y] = distw;
            fare[x][y]=farew;
            fare[y][x]=farew;
        }
        cout<<"\nRoute added successfully!";
        std::fstream of("temp.txt", std::ios::out | std::ios::app);

    if (of.is_open())
    {
        writemap(of, distance);
        writemap(std::cout, distance);
        of.close();
    }
    myfile2.close();
    temp.close();
    remove("dist.txt");
    char oldname[]="temp.txt";
    char newname[]="dist.txt";
    rename(oldname, newname);

    std::fstream of1("temp1.txt", std::ios::out | std::ios::app);

    if (of1.is_open())
    {
        writemap(of1, fare);
        writemap(std::cout, fare);
        of1.close();
    }
    myfile1.close();
    temp1.close();
    remove("fare.txt");
    char oldname1[]="temp1.txt";
    char newname1[]="fare.txt";
    rename(oldname1, newname1);
    }




    void deleteRoute(int x, int y)
    {

         ifstream myfile2; //for reading records
        myfile2.open("dist.txt");
        ifstream myfile1; //for reading records
        myfile1.open("fare.txt");

        ofstream temp;
        temp.open("temp.txt");
        ofstream temp1;
        temp1.open("temp1.txt");
        for(int row = 0; row < 9; row++){
        for(int column = 0; column < 9; column++){
            myfile2 >> distance[row][column];
            // from fp we read the characters
        }
    }
         for(int row = 0; row < 9; row++){
        for(int column = 0; column < 9; column++){
            myfile1 >> fare[row][column];
            // from fp we read the characters
        }
    }
        if ((x >= n) || (y > n)) {
            cout << "Airport does not exists!";
        }
        if (x == y) {
            cout << "Same Airport!";
        }
        else {
            distance[y][x] = 0;
            distance[x][y] = 0;
            fare[y][x]=0;
            fare[x][y]=0;
        }
        cout<<"\nRoute deleted successfully!";
        std::fstream of("temp.txt", std::ios::out | std::ios::app);

    if (of.is_open())
    {
        writemap(of, distance);
        writemap(std::cout, distance);
        of.close();
    }
    myfile2.close();
    temp.close();
    remove("dist.txt");
    char oldname[]="temp.txt";
    char newname[]="dist.txt";
    rename(oldname, newname);

    std::fstream of1("temp1.txt", std::ios::out | std::ios::app);

    if (of1.is_open())
    {
        writemap(of1, fare);
        writemap(std::cout, fare);
        of1.close();
    }
    myfile1.close();
    temp1.close();
    remove("fare.txt");
    char oldname1[]="temp1.txt";
    char newname1[]="fare.txt";
    rename(oldname1, newname1);
    }


    void update(int x, int y,int dist_u,int fare_u)
    {
        ifstream myfile2; //for reading records
        myfile2.open("dist.txt");
        ifstream myfile1; //for reading records
        myfile1.open("fare.txt");

        ofstream temp;
        temp.open("temp.txt");
        ofstream temp1;
        temp1.open("temp1.txt");
        for(int row = 0; row < 9; row++){
        for(int column = 0; column < 9; column++){
            myfile2 >> distance[row][column];
            // from fp we read the characters
        }
    }
         for(int row = 0; row < 9; row++){
        for(int column = 0; column < 9; column++){
            myfile1 >> fare[row][column];
            // from fp we read the characters
        }
    }
        if ((x >= n) || (y >=n)) {
            cout << "Airport does not exists!";
            return;
        }

        if (x == y) {
            cout << "Same Airport!";
            return;
        }
        else {
            distance[y][x] = dist_u;
            distance[x][y] = dist_u;
            fare[x][y]=fare_u;
            fare[y][x]=fare_u;
        }
        cout<<"\nRoute & Fare updated successfully!";
        std::fstream of("temp.txt", std::ios::out | std::ios::app);

    if (of.is_open())
    {
        writemap(of, distance);
        writemap(std::cout, distance);
        of.close();
    }
    myfile2.close();
    temp.close();
    remove("dist.txt");
    char oldname[]="temp.txt";
    char newname[]="dist.txt";
    rename(oldname, newname);

    std::fstream of1("temp1.txt", std::ios::out | std::ios::app);

    if (of1.is_open())
    {
        writemap(of1, fare);
        writemap(std::cout, fare);
        of1.close();
    }
    myfile1.close();
    temp1.close();
    remove("fare.txt");
    char oldname1[]="temp1.txt";
    char newname1[]="fare.txt";
    rename(oldname1, newname1);
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
        ifstream myfile2; //for reading records
        myfile2.open("dist.txt");
        ifstream myfile1; //for reading records
        myfile1.open("fare.txt");

        ofstream temp;
        temp.open("temp.txt");
        ofstream temp1;
        temp1.open("temp1.txt");
        for(int row = 0; row < 9; row++){
        for(int column = 0; column < 9; column++){
            myfile2 >> distance[row][column];
            // from fp we read the characters
        }
    }
         for(int row = 0; row < 9; row++){
        for(int column = 0; column < 9; column++){
            myfile1 >> fare[row][column];
            // from fp we read the characters
        }
    }
        int src;
        cout<<"\nEnter source airport:";
        cin>>src;
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
                if (!visited[v] && distance[u][v] && dist[u] != INT_MAX && dist[u] + distance[u][v] < dist[v]){
                    dist[v] = dist[u] + distance[u][v];
                }
            }
        }
        cout<<"\n\nAirport\t\tMinimum Distance from Source Airport";
        for (int i = 0; i < n; i++){
            cout<<"\n"<<i<<"\t\t"<<dist[i];
        }
         myfile2.close();
          myfile1.close();
    }

    void srctodest_distance()
    {
        ifstream myfile2; //for reading records
        myfile2.open("dist.txt");
        ifstream myfile1; //for reading records
        myfile1.open("fare.txt");

        ofstream temp;
        temp.open("temp.txt");
        ofstream temp1;
        temp1.open("temp1.txt");
        for(int row = 0; row < 9; row++){
        for(int column = 0; column < 9; column++){
            myfile2 >> distance[row][column];
            // from fp we read the characters
        }
    }
         for(int row = 0; row < 9; row++){
        for(int column = 0; column < 9; column++){
            myfile1 >> fare[row][column];
            // from fp we read the characters
        }
    }
        int src;
        cout<<"\nEnter source airport:";
        cin>>src;
        int dest;
        cout<<"\nEnter destination airport:";
        cin>>dest;
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
                if (!visited[v] && distance[u][v] && dist[u] != INT_MAX && dist[u] + distance[u][v] < dist[v]){
                    dist[v] = dist[u] + distance[u][v];
                }
            }
        }
        if(src< dest)
    {
        cout<<"\nDistance from Source: "<<src<<" to destination: "<<dest<<" is: ";
        for (int i = src; i <= dest; i++)
       {
           if(i==dest){
            cout<<dist[i]<<"\n";}
        }
    }
    else
    {
        cout<<"\nDistance from Source: "<<src<<" to destination: "<<dest<<" is: ";
        for (int i = dest; i <= src; i++)
       {
           if(i==dest){
            cout<<dist[i]<<"\n";}
        }
    }

         myfile2.close();
          myfile1.close();
    }
    void srctodest_fare()
    {
        ifstream myfile2; //for reading records
        myfile2.open("dist.txt");
        ifstream myfile1; //for reading records
        myfile1.open("fare.txt");

        ofstream temp;
        temp.open("temp.txt");
        ofstream temp1;
        temp1.open("temp1.txt");
        for(int row = 0; row < 9; row++){
        for(int column = 0; column < 9; column++){
            myfile2 >> distance[row][column];
            // from fp we read the characters
        }
    }
         for(int row = 0; row < 9; row++){
        for(int column = 0; column < 9; column++){
            myfile1 >> fare[row][column];
            // from fp we read the characters
        }
    }
        int src;
        cout<<"\nEnter source airport:";
        cin>>src;
        int dest;
        cout<<"\nEnter destination airport:";
        cin>>dest;

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
                if (!visited[v] && fare[u][v] && dist[u] != INT_MAX && dist[u] + fare[u][v] < dist[v]){
                    dist[v] = dist[u] + fare[u][v];
                }
            }
        }

    if(src< dest)
    {
        cout<<"\nMinimum fare from Source Airport: "<<src<<" to destination Airport: "<<dest<<" is: ";
        for (int i = src; i <= dest; i++)
       {
           if(i==dest){
            cout<<dist[i]<<"\n";}
        }
    }
    else
    {
        cout<<"\nMinimum fare from Source Airport: "<<src<<" to destination Airport: "<<dest<<" is: ";
        for (int i = dest; i <= src; i++)
       {
           if(i==dest){
            cout<<dist[i]<<"\n";}
        }
    }

         myfile2.close();
          myfile1.close();
    }


    void srctodest()
    {
        ifstream myfile2; //for reading records
        myfile2.open("dist.txt");
        ifstream myfile1; //for reading records
        myfile1.open("fare.txt");

        ofstream temp;
        temp.open("temp.txt");
        ofstream temp1;
        temp1.open("temp1.txt");
        for(int row = 0; row < 9; row++){
        for(int column = 0; column < 9; column++){
            myfile2 >> distance[row][column];
            // from fp we read the characters
        }
    }
         for(int row = 0; row < 9; row++){
        for(int column = 0; column < 9; column++){
            myfile1 >> fare[row][column];
            // from fp we read the characters
        }
    }
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
                if (!visited[v] && distance[u][v] && dist[u] != INT_MAX && dist[u] + distance[u][v] < dist[v]){
                    dist[v] = dist[u] + distance[u][v];
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
        myfile2.close();
          myfile1.close();
    }



    void floyydwarshall()
    {

        ifstream myfile2; //for reading records
        myfile2.open("dist.txt");
        ifstream myfile1; //for reading records
        myfile1.open("fare.txt");

        ofstream temp;
        temp.open("temp.txt");
        ofstream temp1;
        temp1.open("temp1.txt");
        for(int row = 0; row < 9; row++){
        for(int column = 0; column < 9; column++){
            myfile2 >> distance[row][column];
            // from fp we read the characters
        }
    }
         for(int row = 0; row < 9; row++){
        for(int column = 0; column < 9; column++){
            myfile1 >> fare[row][column];
            // from fp we read the characters
        }
    }
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
                if (!visited[v] && distance[u][v] && dist[u] != INT_MAX && dist[u] + distance[u][v] < dist[v]){
                    dist[v] = dist[u] + distance[u][v];
                }
            }
        }
        cout<<"Aiport \t\tDistance from Source Airport\n";
        for (int i = 0; i < n; i++){
            cout<<"\n"<<i<<"\t\t"<<dist[i];
        }
    }
    myfile2.close();
          myfile1.close();
    }

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
        ifstream myfile2; //for reading records
        myfile2.open("dist.txt");
        ifstream myfile1; //for reading records
        myfile1.open("fare.txt");

        ofstream temp;
        temp.open("temp.txt");
        ofstream temp1;
        temp1.open("temp1.txt");
        for(int row = 0; row < 9; row++){
        for(int column = 0; column < 9; column++){
            myfile2 >> distance[row][column];
            // from fp we read the characters
        }
    }
         for(int row = 0; row < 9; row++){
        for(int column = 0; column < 9; column++){
            myfile1 >> fare[row][column];
            // from fp we read the characters
        }
    }
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
                if (!visited[v] && fare[u][v] && fa[u] != INT_MAX && fa[u] + fare[u][v]< fa[v]){
                    fa[v] = fa[u] + fare[u][v];
                }
            }
        }
        cout<<"Airport\t\tFare from Source\n";
        for (int i = 0; i < n; i++){
            cout<<"\n"<<i<<"\t\t"<<fa[i];
        }
    }
    myfile2.close();
          myfile1.close();
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
