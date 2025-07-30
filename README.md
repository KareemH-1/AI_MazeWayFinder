# 🧭 Maze Solver (BFS Algorithm)

A C++ console application that reads a maze from a text file and solves it using **Breadth-First Search (BFS)**. The shortest path from **Start (`S`)** to **End (`E`)** is displayed with colored characters directly in the Windows console.

> 🪟 **Note:** This project uses `windows.h` for coloring, so it only works correctly on **Windows** systems.

---

## 📁 Project Structure
AI_MazeWayFinder/
│
├── maze.txt # Input maze file
├── mazeFinderAI.cpp # C++ source code
└── README.md # Project documentation


---

## 🧩 Maze Format

Maze should be a plain text file (`maze.txt`) using the following characters:

- `#` → Wall
- (space) → Walkable path
- `S` → Start point (only one)
- `E` → End point (only one)

---

## ✅ Features

- Loads maze from file
- Solves it using BFS
- Displays the shortest path using `*`
- Color output using `windows.h`:
  - `*` in green
  - `S` in blue
  - `E` in red
- Displays total number of steps
- Shows a warning if no path is found

---

## 💻 Compilation (Windows)

Open your terminal or command prompt:

```bash
g++ main.cpp -o MazeSolver
MazeSolver

Or compile using your preferred IDE (Code::Blocks, Visual Studio, CLion, etc.)
Make sure maze.txt is in the same working directory as your executable.

📥 Example Maze
################## 
#### ##  ##*****E#
#### ## ###*######
#### ## ###***#  #
##   #  #####*## #
#### # #####**   #
#### # ###***#####
#### # ###*  #####
#       ***      #
########*#########
#S*******        #
##################
🧮 Total Steps: 27

⚠️ Important Notes
If either S or E is missing from the input file, the program will exit with an error.

If no path is found from S to E, a message is displayed.

Console color output requires a Windows terminal (e.g., PowerShell, CMD, or Windows Terminal).
