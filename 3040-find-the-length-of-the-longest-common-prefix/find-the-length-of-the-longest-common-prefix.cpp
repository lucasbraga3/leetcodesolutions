struct TrieNode{
    TrieNode* child[10];
    bool end;

    TrieNode(){
        end = false;
        for (int i = 0; i < 10; i++) {
            child[i] = nullptr;
        }
    }
};

void inserTrie(string n, TrieNode* root){
    int hold;
    for(int i = 0;i<n.size();i++){
        hold = n[i] - '0';
        if(root->child[hold] == nullptr){
            TrieNode* Newnode = new TrieNode();
            root->child[hold] = Newnode;
            root = root->child[hold];
        }
        else{
            root = root->child[hold];
        }
    }
    root->end = true;
}

int searchTrie(string n, TrieNode* root){
    int hold;
    int i;
    for(i = 0;i<n.size();i++){
        hold = n[i] - '0';
        if(root->child[hold] == nullptr){
            return i;
        }
        else{
            root = root->child[hold];
        }
    }
    return i;
}

class Solution {
public:
    int longestCommonPrefix(vector<int>& arr1, vector<int>& arr2) {
        TrieNode* skeletor = new TrieNode();
        string a;
        int biggest = 0;
        int temp;
        for(int i=0;i<arr1.size();i++){
            a = to_string(arr1[i]);
            inserTrie(a,skeletor);
        }
        for(int j=0;j<arr2.size();j++){
            a = to_string(arr2[j]);
            temp = searchTrie(a,skeletor);
            if(temp>biggest){
                biggest = temp;
            }          
        }
        return biggest;
    }
};
