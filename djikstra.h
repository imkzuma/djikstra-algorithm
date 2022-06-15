#include <bits/stdc++.h>
using namespace std;

#define V 18
#define SOURCE 0

const unsigned int Graph[V][V] = { 	{ 0 , 100 , 0 , 0 , 0 , 0 , 0 , 0 , 0 , 0 , 0 , 0 , 0 , 0 , 0 , 0 , 0 , 0 } ,
					{ 100 , 0 , 200 , 0 , 0 , 0 , 0 , 0 , 0 , 0 , 0 , 0 , 0 , 0 , 0 , 0 , 0 , 0 } ,
					{ 0 , 200  , 0 ,  180 , 0 , 0 , 0 , 0 , 0 , 0 , 550 , 0 , 0 , 0 , 0 , 0 , 0 , 0 } ,
					{ 0 , 0 , 180 , 0 , 1500 , 0 , 0 , 0 , 0 , 0 , 0 , 0 , 0 , 0 , 0 , 0 , 0 , 0 } ,
					{ 0 , 0 , 0 , 1500 , 0 , 260 , 0 , 0 , 0 , 0 , 0 , 0 , 0 , 0 , 0 , 0 , 0 , 0 } ,
					{ 0 , 0 , 0 , 0 , 260 , 0 , 835 , 0 , 0 , 0 , 0 , 0 , 0 , 0 , 0 , 0 , 0 , 0 } ,
					{ 0 , 0 , 0 , 0 , 0 , 835 , 0 , 150 , 0 , 0 , 0 , 0 , 0 , 0 , 0 , 0 , 0 , 0 } ,
					{ 0 , 0 , 0 , 0 , 0 , 0 , 150 , 0 , 450 , 0 , 0 , 0 , 0 , 0 , 0 , 0 , 0 , 0 } ,
					{ 0 , 0 , 0 , 0 , 0 , 0 , 0 , 450 , 0 , 250 , 0 , 0 , 0 , 0 , 0 , 0 , 0 , 0 } ,
					{ 0 , 0 , 0 , 0 , 0 , 0 , 0 , 0 , 250 , 0 , 0 , 0 , 0 , 0 , 0 , 0 , 0 , 900 } ,
					{ 0 , 0 , 550 , 0 , 0 , 0 , 0 , 0 , 0 , 0 , 0 , 2170 , 0 , 0 , 0 , 0 , 0 , 0 } ,
					{ 0 , 0 , 0 , 0 , 0 , 0 , 0 , 0 , 0 , 0 , 2170 , 0 , 400 , 0 , 0 , 0 , 0 , 0 } ,
					{ 0 , 0 , 0 , 0 , 0 , 0 , 0 , 0 , 0 , 0 , 0 , 400 , 0 , 375 , 0 , 0 , 0 , 0 } ,
					{ 0 , 0 , 0 , 0 , 0 , 0 , 0 , 0 , 0 , 0 , 0 , 0 , 375 , 0 , 150 , 0 , 0 , 0 } ,
					{ 0 , 0 , 0 , 0 , 0 , 0 , 0 , 0 , 0 , 0 , 0 , 0 , 0 , 150 , 0 , 450 , 0 , 0 } ,
					{ 0 , 0 , 0 , 0 , 0 , 0 , 0 , 0 , 0 , 0 , 0 , 0 , 0 , 0 , 450 , 0 , 250 , 0 } ,
					{ 0 , 0 , 0 , 0 , 0 , 0 , 0 , 0 , 0 , 0 , 0 , 0 , 0 , 0 , 0 , 250 , 0 , 900 } ,
					{ 0 , 0 , 0 , 0 , 0 , 0 , 0 , 0 , 0 , 900 , 0 , 0 , 0 , 0 , 0 , 0 , 900 , 0 } };

const string namaJalan[V] = {"Jl.Gatsu Tengah" , "Jl.Ayani" , "Jl.Kartini" , "Jl.Nakula" , "Jl. Werkudara" , "Jl.Arjuna" ,
			     "Jl.Sumatera" , "Jl. Hasanuddin" , "Jl.Sutoyo" , "Jl.Sudirman"};
 
int minDistance(int dist[], bool sptSet[]){
    int min = INT_MAX, min_index;
 
    for (int v = 0; v < V; v++)
        if (sptSet[v] == false && dist[v] <= min)
            min = dist[v], min_index = v;
 
    return min_index;
}
 

void printSolution(int dist[]){
	int MAX = 0; const unsigned int kecepatan = 40;
	cout <<"Vertex \t    Jarak dari Awal" << endl;
    	
	for (int i = 0; i < V; i++)
    		i == 10 ? cout << endl << i << " \t\t" << dist[i] << endl : cout  << i << " \t\t"<<dist[i]<< endl;
    	
    	cout << endl << "Jalan Terpendek dan Tercepat melalui Rute: ";
    	for(int i = 0; i < V; i++){
		i == 9 ? MAX = dist[i] : MAX = MAX;
    		if(i < 10) {
    			cout << i ; if(i < 9) cout << "->";
		}
    	}cout << endl;
	
	cout << endl << "Nama Jalan yang dilewati adalah : " << endl;
	for(int i = 0; i < V; i++){
    		i == 9 ? MAX = dist[i] : MAX = MAX;
    		if(i < 10) {
    			cout << namaJalan[i]; if(i < 9) cout << " -> ";
		}
	}cout << endl;
	
	const float Kilometer = float(MAX)/ 1000;
	const float Est = MAX / kecepatan;
	
	cout << endl << "Tempat Awal : Lumintang" << endl;
	cout << "Tempat Tujuan : Kampus Unud Sudirman" << endl;
	cout << "Jarak Tempuh : " << Kilometer << " Km" << endl;
	cout << "Estimasi Waktu Sampai : " << Est / 10 << " Menit" << endl;	
}
 
void dijkstra(const unsigned int graph[V][V], int src){
    int dist[V];  bool sptSet[V]; 
 
    for (int i = 0; i < V; i++) dist[i] = INT_MAX, sptSet[i] = false;
 
    dist[src] = 0;
 
   
    for (int count = 0; count < V - 1; count++) {
        int u = minDistance(dist, sptSet);
        sptSet[u] = true;
 
        for (int v = 0; v < V; v++)
            if (!sptSet[v] && graph[u][v] && dist[u] != INT_MAX
                && dist[u] + graph[u][v] < dist[v])
                dist[v] = dist[u] + graph[u][v];
    }
    printSolution(dist);
}
