#include <bits/stdc++.h>
#include<windows.h>
HANDLE hConsole = GetStdHandle(STD_OUTPUT_HANDLE);
using namespace std;
#define GREEN 10
#define BLUE 9
#define WHITE 15
#define RED 12


class Node {
public:
    int x, y;
    bool isVisited;
    char val;
    Node* prev;

    Node(int x = 0, int y = 0, char val = ' ') {
        this->x = x;
        this->y = y;
        this->val = val;
        this->isVisited = false;
        this->prev = nullptr;
    }
};

int main() {
    ifstream file("maze.txt");
    string line;
    int steps =0;
    int row = 0;

    vector<vector<Node*>> maze;
    Node* start = nullptr;
    Node* end = nullptr;

    while (getline(file, line)) {
        vector<Node*> mazeRow;
        for (int col = 0; col < line.size(); col++) {
            char c = line[col];
            Node* node = new Node(row, col, c);
            mazeRow.push_back(node);
            if (c == 'S') start = node;
            else if (c == 'E') end = node;
        }
        maze.push_back(mazeRow);
        row++;
    }

    if (!start) {

        SetConsoleTextAttribute(hConsole, RED);
        cout << "Start is not found, please put a 'S' to symbolize start" << endl;
        return 1;
    }
    else if (!end) {
        SetConsoleTextAttribute(hConsole, RED);
        cout << "End is not found, please put an 'E' to symbolize end" << endl;
        return 1;
    }

    queue<Node*> q;
    q.push(start);
    start->isVisited = true;

    int dx[] = {-1, 0, 1, 0};
    int dy[] = {0, 1, 0, -1};

    while (!q.empty()) {
        Node* curr = q.front(); q.pop();

        if (curr == end) break;

        for (int i = 0; i < 4; i++) {
            int nx = curr->x + dx[i];
            int ny = curr->y + dy[i];

            if (nx >= 0 && nx < maze.size() && ny >= 0 && ny < maze[nx].size()){
                Node* neighbor = maze[nx][ny];
                if (!neighbor->isVisited && neighbor->val != '#') {
                    neighbor->isVisited = true;
                    neighbor->prev = curr;
                    q.push(neighbor);
                }
            }
        }
    }

    Node* curr = end;
    if (end->prev == nullptr) {
        SetConsoleTextAttribute(hConsole, RED);
        cout << "No path found from S to E." << endl;
    } else {
        Node* curr = end;
        while (curr != start) {
            steps++;
            if (curr->val != 'E') curr->val = '*';
            curr = curr->prev;
        }
        steps--;
        for (auto& row : maze) {
            for (auto& node : row) {
                if (node->val == '*') {
                    SetConsoleTextAttribute(hConsole, GREEN);
                    cout << node->val;
                } else if (node->val == 'S') {
                    SetConsoleTextAttribute(hConsole, BLUE);
                    cout << node->val;
                } else if (node->val == 'E') {
                    SetConsoleTextAttribute(hConsole, BLUE);
                    cout << node->val;
                } else {
                    SetConsoleTextAttribute(hConsole, WHITE);
                    cout << node->val;
                }
            }
            cout << endl;
        }
        cout << "total steps: " << steps << endl;
    }

    for (auto& row : maze) {
        for (auto& node : row) {
            delete node;
        }
    }

}
