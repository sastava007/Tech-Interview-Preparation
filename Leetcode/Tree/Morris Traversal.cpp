/* TC: O(N) and O(1) space */

public void inorder(Node root) 
{
    Node current = root;
    while(current != null) 
    {
        if (current.left == null) {     //left is null then print the node and go to right
            System.out.print(current.data + " ");
            current = current.right;
        }
        else {
            //find the predecessor.
            Node predecessor = current.left;
            //To find predecessor keep going right till right node is not null or right node is not current.
            while(predecessor.right != current && predecessor.right != null){
                predecessor = predecessor.right;
            }
            //if right node is null then go left after establishing link from predecessor to current.
            if(predecessor.right == null){
                predecessor.right = current;
                current = current.left;
            }else{ //left is already visit. Go rigth after visiting current.
                predecessor.right = null;
                System.out.print(current.data + " ");
                current = current.right;
            }
        }
    }
}

public void preorder(Node root) 
{
    Node current = root;
    while (current != null) 
    {
        if(current.left == null) {
            System.out.print(current.data + " ");
            current = current.right;
        }
        else {
            Node predecessor = current.left;
            while(predecessor.right != current && predecessor.right != null) {
                predecessor = predecessor.right;
            }
            if(predecessor.right == null){
                predecessor.right = current;
                System.out.print(current.data + " ");
                current = current.left;
            }else{
                predecessor.right = null;
                current = current.right;
            }
        }
    }
}