#include<bits/stdc++.h>

using namespace std;

class Solution {
public:
    bool isValidSudoku(vector<vector<char>>& board) {
        unordered_set<string> ans;

        
        for ( int i=0; i<9;i++){
            for(int j=0; j<9; j++){
                if(board[i][j]!='.'){
                    string one(1,board[i][j]);
                    one += " is in row "+to_string(i);
                    string two(1,board[i][j]);
                    two += " is in column "+to_string(j);
                    string three(1,board[i][j]);
                    three+= " is in box "+to_string(i/3*3+j/3);
                    
                    cout<< one<<endl;
                    cout<< two<<endl;
                    cout<< three<<endl;

                    if(ans.find(one)==ans.end() && ans.find(two)==ans.end() && ans.find(three)==ans.end()){
                        ans.insert(one);
                        ans.insert(two);
                        ans.insert(three);
                    }else{
                        cout<<to_string((i+1)*9+j+1);
                        return false;
                    }
                }
            }
        }
        return true;
    }
};

int main(){
    vector<vector<char>> input{
        {'5','3','.','.','7','.','.','.','.'},
        {'6','.','.','1','9','5','.','.','.'},
        {'.','9','8','.','.','.','.','6','.'},
        {'8','.','.','.','6','.','.','.','3'},
        {'4','.','.','8','.','3','.','.','1'},
        {'7','.','.','.','2','.','.','.','6'},
        {'.','6','.','.','.','.','2','8','.'},
        {'.','.','.','4','1','9','.','.','5'},
        {'.','.','.','.','8','.','.','7','9'}
    };

    Solution s;
    if(s.isValidSudoku(input))
        cout<< "yes";

}