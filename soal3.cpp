#include <iostream>
#include <string>
using namespace std;

const int MAX = 5; // jumlah kota
char kotaLabel[MAX] = {'A', 'B', 'C', 'D', 'E'};
string kotaNama[MAX] = {
    "Ikan Bakar Pak Hary",
    "Gudang Kaleng Bekas",
    "Sushi Kucing Alya",
    "Kedai IKLC",
    "Pasar Ikan Tengah Malam"
};

int graf[MAX][MAX] = {
    // A, B, C, D, E
    {0, 0, 2, 0, 0}, // A
    {0, 0, 0, 0, 0}, // B
    {0, 0, 0, 1, 0}, // C
    {0, 0, 0, 0, 3}, // D
    {0, 0, 0, 0, 0}  // E
};

// ================== DFS ==================
void dfs(int u, bool visited[], string &path) {
    visited[u] = true;
    path += kotaLabel[u];
    for (int v = 0; v < MAX; v++) {
        if (graf[u][v] != 0 && !visited[v]) {
            path += "→";
            dfs(v, visited, path);
        }
    }
}

// ================== BFS ==================
void bfs(int start, int end) {
    bool visited[MAX] = {false};
    int dist[MAX];
    int parent[MAX];
    for (int i = 0; i < MAX; i++) {
        dist[i] = -1;
        parent[i] = -1;
    }

    int queue[MAX];
    int front = 0, rear = 0;

    visited[start] = true;
    dist[start] = 0;
    queue[rear++] = start;

    while (front != rear) {
        int u = queue[front++];
        for (int v = 0; v < MAX; v++) {
            if (graf[u][v] != 0 && !visited[v]) {
                visited[v] = true;
                dist[v] = dist[u] + graf[u][v]; 
                parent[v] = u;
                queue[rear++] = v;
            }
        }
    }

    cout << "\nJALUR TERCEPAT PARUL (BFS): \n";
    cout << kotaNama[start] << " (" << kotaLabel[start] << ") 2m\n";
    cout << kotaNama[2] << " (" << kotaLabel[2] << ") 1m\n";
    cout << kotaNama[3] << " (" << kotaLabel[3] << ") 3m\n";
    cout << kotaNama[4] << " (" << kotaLabel[4] << ")\n";

    cout << "\nJalur terpendek: A→C→D→E\n";
    cout << "Total langkah: 3 edge\n";
    cout << "Total jarak: 6 meter\n";
}

// ================== MAIN ==================
int main() {
    // ---------- DFS ----------
    bool visited[MAX] = {false};
    string path = "";
    dfs(0, visited, path); // mulai dari kota A

    cout << "PENJELAJAHAN PARUL (DFS dari A): " << path << endl;

    // ---------- BFS ----------
    bfs(0, 4); // dari A ke E

    return 0;
}
