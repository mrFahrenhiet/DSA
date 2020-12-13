The number of steps to the target is rows+cols-2.
The number of obstacles is 1 less, since the last cell must be empty
```cpp
0 0 0 0
1 0 0 0
1 1 1 0

rows=3, cols=4, steps = (2 down + 3 right) = 5
which is equal to rows-cols-2 = 5 steps
Number of obstacles: steps-1 = 4 obstacles
```
We can take a shortcut anytime (not just on start as @StefanPochmann mentioned) when we know that k can cover all possible obstacles:
```cpp
if(obstacles<=k) return minSteps;                   // on start

if(stepsToTarget-1<=kk) return steps+stepsToTarget; // on each step
```
On the optimal way, we might use up some k so we can jump only from the point closest to the target. Otherwise, we might stop on sub-optimal solution without used k. Example:
```cpp
[[0,1,1,1,1,1,0,0,0,0,0,1,1,0],[0,0,0,0,0,0,0,1,1,1,0,0,0,0]]
4

0 1 2 3 4 5 6 7 8 910111213
---------------------------
0 1 1 1 1 1 0 0 0 0 * 1 1 0  <-- at * we are at suboptimal path, steps=11, k=4, 
0 0 0 0 0 0 0 1 1 1 0 0 0 0      stepToTarget=4, so we would take a jump with 16
                                 while optimal is 14
// To avoid this, jump only from the point closest to the target
if(stepsToTarget-1<=kk && stepsToTarget==minSteps-1) return steps+stepsToTarget; // on each step
```
Since we need the minimal number of steps, we should use BFS.
Note, that we need to track k when maintaining visited since we might use up all k too early. E.g. the shortest path to (0,5) will eat up all k's:
```cpp
0 1 0 0 0 1
0 0 0 1 1 0
Test:
[[0,1,0,0,0,1],[0,0,0,1,1,0]]
1
```
On the other hand, there is no point in checking the same cell with less (and worse) k than previously.
Otherwise, we would go from (0,0,k=1) to (1,0,k=0) and then back to (0,0,k=0).
Optimization: track k for each cell and never reduce it. Start with negative:
```cpp
vector<int> visited(rows*cols, -1); // position -> k remaining
```
##### *C++, 0ms:*
```cpp
        int rows=grid.size(), cols=grid[0].size();
        int minSteps = max(0,rows+cols-2), obstacles=minSteps-1, minStepsNextRound=minSteps;
        if(obstacles<=k) return minSteps; // take a shortcut if we can afford it

        vector<vector<int>> dirs = {{1,0},{0,1},{-1,0},{0,-1}};
        list<vector<int>> togo; togo.push_back({0,0,k}); // BFS: {row, col, remaining k}
        vector<int> visited(rows*cols, -1); // position -> k remaining
        visited[0]=k;
        int steps=0;
        
        while(togo.size()) {
            steps++;
			minSteps=minStepsNextRound;
            for(int sz=togo.size();sz>0;sz--) {
                int r=togo.front()[0], c=togo.front()[1], k=togo.front()[2];
                togo.pop_front();
                for(auto& d:dirs) {
                    int rr=r+d[0], cc=c+d[1];
                    if(rr<0 || rr>=rows || cc<0 || cc>=cols) continue;
                    int kk = k-grid[rr][cc];
                    if(visited[rr*cols+cc]>=kk) continue; // have been here passing less obstacles

                    // maybe we can take a shortcut and go straight to the goal
					// but jump only from the point closest to the target
                    int stepsToTarget = rows-rr-1+cols-cc-1;
                    if(stepsToTarget-1<=kk && stepsToTarget==minSteps-1) return steps+stepsToTarget;
                    togo.push_back({rr,cc,kk});
                    visited[rr*cols+cc]=kk;
					minStepsNextRound=min(minStepsNextRound,stepsToTarget);
                }
            }
        }
        return -1;
    }
```