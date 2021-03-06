#include <iostream>
#define ROW 3
#define COL 3
using namespace std;

int cost[ROW][COL] = {
    {1, 2, 3},
    {4, 8, 2},
    {1, 5, 3}};

int min(int a, int b, int c)
{
  return (a < b) ? ((a < c) ? a : c) : ((b < c) ? b : c);
}

int minCostPath(int x, int y)
{
  int totalCost[ROW][COL];

  totalCost[0][0] = cost[0][0];

  for (int i = 1; i <= x; i++)
    totalCost[i][0] = totalCost[i - 1][0] + cost[i][0]; //set first col of totalCost array

  for (int j = 1; j <= y; j++) //set first row of totalCost array
    totalCost[0][j] = totalCost[0][j - 1] + cost[0][j];

  for (int i = 1; i <= x; i++) //for second row and column to all
    for (int j = 1; j <= y; j++)
      totalCost[i][j] = min(totalCost[i - 1][j - 1], totalCost[i - 1][j], totalCost[i][j - 1]) + cost[i][j];
  return totalCost[x][y];
}

int main()
{
  cout << "Minimum Cost: " << minCostPath(2, 2); //destination (2, 2)
  return 0;
}