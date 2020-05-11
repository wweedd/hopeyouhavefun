/*
 * Given several boxes with different colors represented by different positive
 * nubmers. You may experience several rounds to remove boxes until there's
 * no box left. Each time you can choose some continuous boxes with the same
 * color (composed of k boxes, k >=1), remove them and get k*k points.
 * Find the maximum points you can get.
 *
 * Date: 05/10/2020
 * Author: Wei Du
 */

# include <vector>

using namespace std;

class Solution {
public:
    int removeBoxes(vector<int>& boxes) {
        int n=boxes.size();
        int memo[100][100][100] = {{{0}}};
        return dfs(boxes,memo,0,n-1,0);
    }
    
    int dfs(vector<int>& boxes,int memo[100][100][100], int l,int r,int k){
        if (l>r) return 0;
        if (memo[l][r][k]!=0) return memo[l][r][k];

        while (r>l && boxes[r]==boxes[r-1]) {r--;k++;}
        memo[l][r][k] = dfs(boxes,memo,l,r-1,0) + (k+1)*(k+1);
        for (int i=l; i<r; i++){
            if (boxes[i]==boxes[r]){
                memo[l][r][k] = max(memo[l][r][k], dfs(boxes,memo,l,i,k+1) + dfs(boxes,memo,i+1,r-1,0));
            }
        }
        return memo[l][r][k];
    }
};
