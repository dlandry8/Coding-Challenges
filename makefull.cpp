/*
From Daily Coding Problem
(dailycodingproblem.com)
6/11/2020

Good morning!
Here's a solution to yesterday's problem.
This is your coding interview problem for today.
This problem was asked by Yahoo.
Recall that a full binary tree is one in which each node is either a leaf node, or has two children. Given a binary tree, convert it to a full one by removing nodes with only one child.
For example, given the following tree:
         0
      /     \
    1         2
  /            \
3                 4
  \             /   \
    5          6     7
You should convert it to:
     0
  /     \
5         4
        /   \
       6     7
We will be sending the solution tomorrow, along with tomorrow's question. As always, feel free to shoot us an email if there's anything we can help with.
Have a great day!

************************* My Solution ***************************************
Traverse the tree via post-order traversal (left, right, current). At each current node, check if it only has one child. If so, make the parent point to the child, then delete the current node.
Here's a tracing of the above example:
At 0.
	Go to left child.
At 1.
	Go to left child.
At 3.
	No left child.
	Go to right child.
At 5.
	No children.
At 3.
	No right child.
	Only one child (5).
	Parent (1) now points to child (5).
	Delete current node.
	     0
      /     \
    1         2
  /            \
5                 4
                /   \
               6     7
At 1.
	No right child.
	Only one child (5).
	Parent (0) now points to child (5).
	Delete current node.
	     0
      /     \
    5         2
               \
                 4
               /   \
              6     7
At 0.
	Go to right child.
At 2.
	No left child.
	Go to right child.
At 4.
	Go to left child.
At 6.
	No children.
At 4.
	Go to right child.
At 7.
	No children.
At 4.
	2 children (6, 7).
At 2.
	Only one child (4).
	Parent (0) now points to child (4).
	Delete current node.
	     0
      /     \
    5        4
           /  \
         6     7
At 0.
	2 children (5, 4).

*/

// Code for my solution.
// Preconditions:
//		There exists a data structure, BST, containing a collection of node data types.
//		The node data types contain at least pointers to left child, right child, and parent.
void make_full(BST& input, node* current)
{
	if (current->left != NULL)
		make_full(input, current->left);
	if (current->right != NULL)
		make_full(input, current->right);
	if ( (current->left == NULL && current->right != NULL) || (current->left != NULL && current->right == NULL) )
	// i.e., if current only has one child.
	{
		if (current->parent->left == current)
		{
			if (current->left != NULL)
			{
				current->parent->left = current->left;
				current->left->parent = current->parent;
			}
			else
			{
				current->parent->left = current->right;
				current->right->parent = current->parent;
			}
		}
		else
		{
			if (current->left != NULL)
			{
				current->parent->right = current->left;
				current->left->parent = current->parent;
			}
			else
			{
				current->parent->right = current->right;
				current->right->parent = current->parent;
			}
		}	
	}
	delete current;
}

// Total time of completion: 45 minutes.