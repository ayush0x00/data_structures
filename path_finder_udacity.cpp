#include <iostream>
#include <vector>
#include <fstream>
#include <string>
#include <sstream>
#include <cstdlib>
#include <algorithm>
using namespace std;
enum class State {kEmpty,kObstacles,kClosed,kPath,kStart,kFinish};
// directional deltas
const int delta[4][2]{{-1, 0}, {0, -1}, {1, 0}, {0, 1}};
bool CheckValidCell(int x, int y,vector<vector<State>> &grid);

vector<State> ParseLine(string str){
  vector<State> parse;
  istringstream my_stream(str);
  char c;
  int n;
  while(my_stream>>n>>c){
    if (n==0){
      parse.push_back(State::kEmpty);
    }
    else
      parse.push_back(State::kObstacles);
  }
  return parse;
}

vector<vector<State>> ReadBoardFile(string path){ //we can use auto keyword if we arent sure of return type of function
  ifstream my_file(path);
  vector<vector<State>> board;
  if (my_file){
    string line;
    while(getline(my_file,line)){
      board.push_back(ParseLine(line));
    }
    //std::cout << my_file.rdbuf() << '\n';
  }
  return board;
}

bool Compare(vector<int> node1,vector<int> node2){
  if (node1[2]+node1[3]>node2[2]+node2[3])
    return true;
  else
    return false;
}

void CellSort(vector<vector<int>> *v) {
  sort(v->begin(), v->end(), Compare);
}

int Heuristic(int x1,int y1,int x2,int y2){
  return abs(x2-x1)+abs(y2-y1);
}


void AddToOpen(int x,int y,int g, int h, vector<vector<int>> &open_nodes,vector<vector<State>> &grid){
  vector<int> node={x,y,g,h};//x and y are cordinates and g is value and h is heuristic value
  open_nodes.push_back(node);
  grid[x][y]=State::kClosed;
}

void ExpandNeighbors(const vector<int> &current, int goal[2],vector<vector<int>> &open, vector<vector<State>> &grid)
{
  int x=current[0];
  int y=current[1];
  int g=current[2];
  // TODO: Get current node's data.
  // TODO: Loop through current node's potential neighbors.
	for(int i=0;i<4;i++){
      int x2=x+delta[i][0];
      int y2=y+delta[i][1];
    // TODO: Check that the potential neighbor's x2 and y2 values are on the grid and not closed.
      if(CheckValidCell(x2,y2,grid)){
        int g2=g+1;
        int h2=Heuristic(x2,y2,goal[0],goal[1]);
        AddToOpen(x2,y2,g2,h2,open,grid);
      }
    }
  }





vector<vector<State>> Search(vector<vector<State>> grid, int init[2], int goal[2]) {
  // Create the vector of open nodes.
  vector<vector<int>> open {};
  // TODO: Initialize the starting node.
  int x1=init[0]; int x2=goal[0];
  int y1=init[1]; int y2=goal[1];
  int g=0;
  int h= Heuristic(x1,y1,x2,y2);
  // TODO: Use AddToOpen to add the starting node to the open vector.
  AddToOpen(x1,y1,g,h,open,grid);
  while (open.size()!=0){
   // TODO: Sort the open list using CellSort, and get the current node.
   CellSort(&open);
   auto current = open.back();
   open.pop_back(); //remove visited node
   int x = current[0];
   int y = current[1];
   grid[x][y] = State::kPath;
   // TODO: Check if you've reached the goal. If so, return grid.
     if (x==goal[0] && y==goal[1]){
       grid[init[0]][init[1]]=State::kStart;
       grid[goal[0]][goal[1]]=State::kFinish;
       return grid;
     }
   // If we're not done, expand search to current node's neighbors.
   ExpandNeighbors(current,goal,open,grid);
 //// TODO: End while loop
 }
  cout << "No path found!" << "\n";
  return grid;
}

bool CheckValidCell(int x, int y,vector<vector<State>> &grid){
  if (x<grid.size() && y<grid[0].size() && grid[x][y]==State::kEmpty)
    return true;
  else
    return false;
}

string CellString(State cell) {
  switch(cell) {
    case State::kObstacles: return "⛰️   ";
    case State::kPath: return "🚗   ";
    case State::kStart: return "🚦";
    case State::kFinish: return "🏁 ";
    default: return "0   ";
  }
}
void PrintBoard(vector<vector<State>> board){
  for (int i=0; i<board.size();i++){
    for(int j=0;j<board[i].size();j++)
      std::cout << CellString(board[i][j]);
    std::cout <<'\n';
  }
}

int main(){
  int init[2]={0,0};
  int goal[2]={2,5};
vector<vector<State>> board=ReadBoardFile("1.board");
auto solution=Search(board,init,goal);
PrintBoard(solution);
return 0;
}
