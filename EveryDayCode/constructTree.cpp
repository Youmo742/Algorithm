/*
给定二叉树的前序和（中序/后序），重新构造此二叉树
由前序遍历序列，知道根节点
然后，在中序遍历序列中找到根节点的位置，根节点之前的都是左子树，之后的都是右子树
然后，再去前序序列里面找左子树的根节点
以此类推
 */
#include <iostream>
struct Node{
    public:
    Node* lchild;
    Node *rchild;
    int data;
    Node(int mdata){
        data=mdata;
        lchild=nullptr;
        rchild=nullptr;
    }
};
Node *constructCore(int *preorder, int *endpreorder, int *inorder, int *endinorder)
{
    //递归结束的条件，只有一个节点
    int rootvalue = preorder[0];
    Node *root = new Node(rootvalue);
    if (preorder == endpreorder)
    {
        if (*inorder == *preorder)
            return root;
        else
        {
            std::cout << "bad input" << std::endl;
            return nullptr;
        }
    }
    //找根节点在中序序列的位置
    int *rootInorder = inorder;
    while (rootInorder <= endinorder && *rootInorder != rootvalue)
    {
        ++rootInorder;
    }
    if (rootInorder == endinorder && *rootInorder != rootvalue)
    {
        std::cout << "bad input\n";
        return nullptr;
    }
    //递归的构造左右子树
    int leftSubtree = rootInorder - inorder;
    int *endleftSubtree = preorder + leftSubtree;
    if (leftSubtree > 0)
    {
        root->lchild = constructCore(preorder + 1, endleftSubtree, inorder, rootInorder - 1);
    }
    int rigthSubtree = endinorder - rootInorder;
    if (rigthSubtree > 0)
    {
        root->rchild = constructCore(endleftSubtree + 1, endpreorder, rootInorder + 1, endinorder);
    }
    return root;
}
Node* construct(int* preorder,int* inorder,int length){
    if(preorder==nullptr||inorder==nullptr)
        return nullptr;
    return constructCore(preorder,preorder+length-1,
        inorder,inorder+length-1);
}

void inorder_print(Node *root){
    if(root==nullptr)
        return;
    inorder_print(root->lchild);
    std::cout<<root->data<<" ";
    inorder_print(root->rchild);
}
int main(){
    int preorder[]={1,2,4,7,3,5,6,8};
    int inorder[]={4,7,2,1,5,3,8,6};
    Node* root=construct(preorder,inorder,sizeof(preorder)/sizeof(preorder[0]));
    inorder_print(root);
    return 0;
}