#include<bits/stdc++.h>
using namespace std;
void paranthesis(int n,int left,int right,vector<string> &ans,string &temp){
    if(left+right==2*n){
        ans.push_back(temp);
        return;
    }
    // left parenthesis
    if(left<n){
        temp.push_back('(');
        paranthesis(n,left+1,right,ans,temp);
        temp.pop_back();
    }
    //right parenthesis
    if(right<left){
         temp.push_back(')');
        paranthesis(n,left,right+1,ans,temp);
        temp.pop_back();
    }
}
int main(){
    int n;
    cout<< "Enter the number of each paranthesis";
    cin>> n;
    vector<string> ans;
    string temp=" ";
    paranthesis(n,0,0,ans,temp);
    for(int i=0;i<ans.size();i++){
        cout<< ans[i]<< " ";
    }


}