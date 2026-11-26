#include <iostream>
#include <algorithm>
#include <vector>
#include <queue>
#include <deque>

using namespace std;

#define pii pair<int, int>
#define INF 2e9

int N, M;
int ans = INF;
pii S, C[2];
char room[50][50];
int check[3][4][50][50];

int dy[] = { 0, 0, 1, -1 };
int dx[] = { 1, -1, 0, 0 };

int ccnt;

typedef struct {
    int dir;
    pii pos;
}node;

void bfs_c(int dim, queue<node>& q) {
    while (q.size()) {
        node cur = q.front();
        q.pop();
        for (int i = 0; i < 4; i++) {
            if (cur.dir == i) continue;
            int dm = cur.pos.first + dy[i];
            int dn = cur.pos.second + dx[i];

            if (dm >= N || dm < 0 || dn >= M || dn < 0)
                continue;
            if (room[dm][dn] == '#')
                continue;
            if (check[dim][i][dm][dn] <= check[dim][cur.dir][cur.pos.first][cur.pos.second] + 1)
                continue;

            pii next = { dm, dn };
            check[dim][i][dm][dn] = check[dim][cur.dir][cur.pos.first][cur.pos.second] + 1;
            if (next != C[(dim + 1) % 2])
                q.push({ i, next });
            else {
                for (int j = 0; j < 2; j++)
                    if (j == dim) continue;
                    else if (next == C[j])
                        ans = min(ans, check[dim][i][dm][dn]);
            }
        }
    }
}

void bfs_s(pii start) {
    queue<node> q, c[2];
    for (int i = 0; i < 4; i++)
        q.push({ i, start }), check[2][i][start.first][start.second] = 0;
    
    while (q.size()) {
        node cur = q.front();
        q.pop();
        for (int i = 0; i < 4; i++) {
            if (cur.dir == i) continue;
            int dm = cur.pos.first + dy[i];
            int dn = cur.pos.second + dx[i];

            if (dm >= N || dm < 0 || dn >= M || dn < 0)
                continue;
            if (room[dm][dn] == '#')
                continue;
            if (check[2][i][dm][dn] <= check[2][cur.dir][cur.pos.first][cur.pos.second] + 1)
                continue;

            pii next = { dm, dn };
            check[2][i][dm][dn] = check[2][cur.dir][cur.pos.first][cur.pos.second] + 1;
            if (room[dm][dn] != 'C')
               q.push({ i, next });
            else {
                for (int j = 0; j < 2; j++)
                    if (next == C[j]) {
                        check[j][i][dm][dn] = check[2][i][dm][dn];
                        c[j].push({ i, next });
                    }
            }
        }
    }

    //for (int k = 0; k < 4; k++) {
    //    for (int i = 0; i < N; i++) {
    //        for (int j = 0; j < M; j++) {
    //            cout << check[2][k][i][j] << " ";
    //        }
    //        cout << "\n";
    //    }
    //    cout << "\n\n";
    //}

    for (int i = 0; i < 2; i++)
        bfs_c(i, c[i]);
}

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    cin >> N >> M;

    for (int i = 0; i < N; i++) {
        for (int j = 0; j < M; j++) {
            cin >> room[i][j];

            if (room[i][j] == 'S')
                S = { i, j };
            if (room[i][j] == 'C')
                C[ccnt++] = { i, j };

            for (int k = 0; k < 3; k++)
            for (int l = 0; l < 4; l++)
                check[k][l][i][j] = INF;
        }
    }

    bfs_s(S);

    cout << ((ans == INF) ? -1 : ans);
}