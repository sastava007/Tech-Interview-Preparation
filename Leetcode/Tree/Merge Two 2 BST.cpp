/*  TC: O(m+n) and Space: O(height of the first tree + height of the second tree) 

    The idea is to use iterative inorder traversal. We use two auxiliary stacks for two BSTs. Since we need to print the elements in sorted form, whenever we get a smaller element from any of the trees, we print it. If the element is greater, then we push it back to stack for the next iteration.
*/

void merge(node *root1, node *root2)  
{   
    snode *s1 = NULL;   
    node *current1 = root1;    
    snode *s2 = NULL;    
    node *current2 = root2;  

    if (root1 == NULL)  
    {  
        inorder(root2);  
        return;  
    }  
    if (root2 == NULL)  
    {  
        inorder(root1);  
        return ;  
    }  
  
    while (current1 != NULL || !isEmpty(s1) || current2 != NULL || !isEmpty(s2))  
    {  
        // Following steps follow iterative Inorder Traversal  
        if (current1 != NULL || current2 != NULL )  
        {  
            // Reach the leftmost node of both BSTs and push ancestors of  
            // leftmost nodes to stack s1 and s2 respectively  
            if (current1 != NULL)  
            {  
                push(&s1, current1);  
                current1 = current1->left;  
            }  
            if (current2 != NULL)  
            {  
                push(&s2, current2);  
                current2 = current2->left;  
            }  
  
        }  
        else
        {  
            // If we reach a NULL node and either of the stacks is empty,  
            // then one tree is exhausted, ptint the other tree  
            if (isEmpty(s1))  
            {  
                while (!isEmpty(s2))  
                {  
                    current2 = pop (&s2);  
                    current2->left = NULL;     // So instead of modifying structure of tree we can go for current2=current2->right
                    inorder(current2);
                }  
                return ;  
            }  
            if (isEmpty(s2))  
            {  
                while (!isEmpty(s1))  
                {  
                    current1 = pop (&s1);  
                    current1->left = NULL;  
                    inorder(current1);  
                }  
                return ;  
            }  
  
            // Pop an element from both stacks and compare the  
            // popped elements  
            current1 = pop(&s1);  
            current2 = pop(&s2);  
  
            // If element of first tree is smaller, then print it  
            // and push the right subtree. If the element is larger,  
            // then we push it back to the corresponding stack.  
            if (current1->data < current2->data)  
            {  
                cout<<current1->data<<" ";  
                current1 = current1->right;  
                push(&s2, current2);  
                current2 = NULL;  
            }  
            else
            {  
                cout<<current2->data<<" ";  
                current2 = current2->right;  
                push(&s1, current1);  
                current1 = NULL;  
            }  
        }  
    }  
} 