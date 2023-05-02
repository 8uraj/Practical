class Node:
    def __init__(self, key):
        self.key = key
        self.left = None
        self.right = None
        self.height = 1
        
class AVLTree:
    def insert(self, root, key):
        
        # Step 1 - Perform normal BST insertion
        if not root:
            return Node(key)
        elif key < root.key:
            root.left = self.insert(root.left, key)
        else:
            root.right = self.insert(root.right, key)
            
        # Step 2 - Update the height of the ancestor node
        root.height = 1 + max(self.get_height(root.left),
                              self.get_height(root.right))
        
        # Step 3 - Get the balance factor of this ancestor node
        balance = self.get_balance(root)
        
        # Step 4 - If the node is unbalanced, then try out the 4 cases
        # Case 1 - Left Left
        if balance > 1 and key < root.left.key:
            return self.right_rotate(root)
        
        # Case 2 - Right Right
        if balance < -1 and key > root.right.key:
            return self.left_rotate(root)
        
        # Case 3 - Left Right
        if balance > 1 and key > root.left.key:
            root.left = self.left_rotate(root.left)
            return self.right_rotate(root)
        
        # Case 4 - Right Left
        if balance < -1 and key < root.right.key:
            root.right = self.right_rotate(root.right)
            return self.left_rotate(root)
        
        # return the (unchanged) node pointer
        return root
    
    def left_rotate(self, z):
        y = z.right
        T2 = y.left
        
        # Perform rotation
        y.left = z
        z.right = T2
        
        # Update heights
        z.height = 1 + max(self.get_height(z.left),
                           self.get_height(z.right))
        y.height = 1 + max(self.get_height(y.left),
                           self.get_height(y.right))
        
        # Return the new root
        return y
    
    def right_rotate(self, z):
        y = z.left
        T3 = y.right
        
        # Perform rotation
        y.right = z
        z.left = T3
        
        # Update heights
        z.height = 1 + max(self.get_height(z.left),
                           self.get_height(z.right))
        y.height = 1 + max(self.get_height(y.left),
                           self.get_height(y.right))
        
        # Return the new root
        return y
    
    def get_height(self, root):
        if not root:
            return 0
        return root.height
    
    def get_balance(self, root):
        if not root:
            return 0
        return self.get_height(root.left) - self.get_height(root.right)
    
    def inorder_traversal(self, root):
        if root:
            self.inorder_traversal(root.left)
            print(root.key, end=' ')
            self.inorder_traversal(root.right)
            
if __name__ == '__main__':
    avl = AVLTree()
    root = None
    
    n = int(input("Enter number of elements to be inserted: "))
    for i in range(n):
        key = int(input("Enter element: "))
        root = avl.insert(root, key)
    
    print("Inorder traversal of the constructed AVL tree is:")
    avl.inorder_traversal(root)
