unordered_map <string,int> um;
string findDup(Node *root)
{
    if(root==NULL)
    return "";
    string s=to_string(root->data);
    s+='$';
    s+=findDup(root->left);
    s+=findDup(root->right);

    um[s]++;
    return s;
}
void printAllDups(Node* root)
{
    um.clear();
    findDup(root);

    set<int> s;
    for(auto it: um)
    {
        if(it.second>=2)
        {
            int x=0;
            string str="";
            while(it.first[x]!='$')
            {
              str+=it.first[x++];
            }
            int dat=stoi(str);
              s.insert(dat);
        }
        // cout<<it.first<<" "<<it.second<<endl;
    }
    if(s.empty())
    cout<<"-1";
    else{
    for(auto i:s)
    cout<<i<<" ";
    }
}
