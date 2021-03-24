//LEVEL ORDER TRAVERSAL+VERTICAL ORDER TRAVERSAL

vector<int> topView(struct Node *root)
{
    vector <int> ans;
    map <int,int>mp;

    if(root==NULL)
    return ans;
    int level=0,hd=0;

    queue <tuple<Node *,int,int>> q;
    q.push(make_tuple(root,level,hd));
    while(!q.empty())
    {
      tuple<Node*,int,int> tp=q.front();
      Node *ptr=get<0>(tp);
      level=get<1>(tp);
      hd=get<2>(tp);
      if (mp.count(hd) == 0)
        mp[hd] = ptr->data;
      if(ptr->left!=NULL)
      q.push(make_tuple(ptr->left,level+1,hd-1));
      if(ptr->right!=NULL)
      q.push(make_tuple(ptr->right,level+1,hd+1));
      q.pop();
    }

    for(auto &it: mp)
    {
        ans.push_back(it.second);
    }
    mp.clear();

    return ans;
}
