//深度优先算法
class Solution {
public:
    /**
     * 代码中的类名、方法名、参数名已经指定，请勿修改，直接返回方法规定的值即可
     *
     * 
     * @param str string字符串 
     * @return string字符串vector
     */
    void dfs(vector<string> &res,vector<int> &visited,string temp,string str){
        if(temp.size()==str.size()){
            res.push_back(temp);
            return;
        }
        for(int i=0;i<str.size();i++){
            if(visited[i])
                continue;
            if(i>0&&str[i-1]==str[i]&&!visited[i-1])
                continue;
            visited[i]=1;
            temp.push_back(str[i]);
            dfs(res, visited, temp, str);
            visited[i]=0;
            temp.pop_back();
        }
    }
    vector<string> Permutation(string str) {
        vector<string> res;
        sort(str.begin(), str.end());
        vector<int> visited(str.size(),0);
        string temp;
        dfs(res, visited,temp, str);
        return res;
    }
};
//遍历，交换的方法
class Solution {
public:
    /**
     * 代码中的类名、方法名、参数名已经指定，请勿修改，直接返回方法规定的值即可
     *
     * 
     * @param str string字符串 
     * @return string字符串vector
     */
    bool ok(string str,int index,int i){
        if(i>index){
            for(int j=index;j<i;j++){
                if(str[j]==str[i])
                    return false;
            }
        }
        return true;
    }
    void recursion(vector<string>&res, string str,int index){
        if(index==str.size())
            res.push_back(str);
        for(int i=index;i<str.size();i++){
            if(ok(str,index,i)){
                swap(str[i],str[index]);
                recursion(res, str,index+1);
                swap(str[i],str[index]);
            }
        }
    }
    vector<string> Permutation(string str) {
        vector<string> res;
        sort(str.begin(), str.end());
        recursion(res,str,0);
        return res;
    }
};