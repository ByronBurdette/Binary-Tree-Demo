
// Byron Burdette
// COP2535.0M1


/*********************************************************************************************************************************************************
**********************************************************************************************************************************************************
                                                MEMBER FUNCTION DEFINITIONS FOR THE CLASS EmployeeList
**********************************************************************************************************************************************************
**********************************************************************************************************************************************************/





#include"EmployeeList.h"                                            //  include the file for EmployeeList objects







/*********************************************************************************************************************************************************
                                                THIS MARKS THE BEGINNING OF THE DEFAULT CONSTRUCTOR

The purpose of this function is to read the input file and create the binary tree with all the employee information. Each line in the input file has a
single employee's ID number followed by their first and last names. The function goes through the input file line-by-line, first, storing the entire line
in a string. Then it creates a stringstream from the line so that we can read the line as input and capture each individual piece of employee information.
The function then reads each part of the line. The first bit will be stored as the employee ID number while the last two bits will be stored as a single
string containing the employee's name. After a single employee's information has been captured and stored, the function passes off the employee ID number
and name along with the pointer to the root node of the tree to insert() in order to create a new node in the tree with the employee information. Each line
in the input file is processed in this way until the entire input file has been read.
**********************************************************************************************************************************************************/
EmployeeList::EmployeeList()                                        //  begin constructor definition
{
    string empInfo;                                                 //  create a string for storing an employee's ID and name

    inFile.open("employee.txt");                                    //  open the input file

    while (getline(inFile, empInfo))                                //  get the next line in the input file and do the following. Repeat until the EOF is reached
    {
        int id = NULL;                                              //  create a null integer variable to hold the employee ID number
        string name = "";                                           //  create an empty string to hold the employee's name

        stringstream ss(empInfo);                                   //  create a stringstream from the current line in the file so we can read the string as input and capture each individual piece of employee information
        string str;                                                 //  create a string for storing each individual piece of info in the stringstream

        while (ss >> str)                                           //  store the next value from the stringstream in "str" and do the following. Repeat until EOF is reached
        {
            if (!id)                                                //  if id == NULL, then the first thing to do is store the employee ID
                id = stoi(str);                                     //  convert the value read in from the stream to an int and store it in "id"
            else                                                    //  otherwise, it's time to store the employee's name
            {
                if (name.empty())                                   //  if "name" is empty, then we just need to store the name directly
                    name = str;                                     //  store the name
                else                                                //  otherwise, we've already read the first name, so we'll need to include a space with the last name
                    name += " " + str;                              //  add a space along with the last name to "name"
            }
        }                                                           //  end of the loop

        insert(root, id, name);                                     //  insert a new employee node into our binary tree
    }                                                               //  end of the loop
}                                                                   //  end function definition
/*********************************************************************************************************************************************************
                                                    THIS MARKS THE END OF THE DEFAULT CONSTRUCTOR
**********************************************************************************************************************************************************/









/*********************************************************************************************************************************************************
                                                THIS MARKS THE BEGINNING OF THE FUNCTION insert()

The purpose of this function is to insert new nodes with employee information into our binary tree. The default constructor will pass an employee's ID
number and name along with the pointer to the root node of the tree to this function. This function proceeds by first checking to see if the pointer to
the node is not pointing to anything, in which case a new node will be created using the pointer. If the pointer IS pointing to a node, then we must
proceed down the tree until we reach a pointer at the bottom of the tree which is not currently pointing to a node. This function insert() will be
recursively called with the pointer to either the left or right child node. The function decides based on the employee ID number whether to proceed
down a nodes left or right child. This function will continue to call itself until it reaches a null pointer, at which point a new node can be created
with the employee ID number and name. Nodes will be stored in ascending order by employee ID number.
**********************************************************************************************************************************************************/
void EmployeeList::insert(TreeNode* &tree, int id, string name)     //  begin function definition
{
    if (!tree)                                                      //  if the TreeNode pointer is empty, then we need to create a new node using this TreeNode pointer
    {
        tree = new TreeNode(id, name);                              //  create a new node with the employee's ID number and name, and store its location in the TreeNode pointer "tree"
        return;                                                     //  terminate execution of the function
    }
    else if (tree->employee.getID() == id)                          //  check if a node already exists for this employee
        return;                                                     //  terminate execution of the function if the node already exists
    else if (id < tree->employee.getID())                           //  if the new employee ID number is smaller than the employee ID number in the current node
        insert(tree->left, id, name);                               //  travel further down the tree through the left child node by recursively calling this function and passing it the pointer to the left child node
    else                                                            //  otherwise the new employee ID number must be greater than the employee ID number in the current node
        insert(tree->right, id, name);                              //  travel further down the tree through the right child node by recursively calling this function and passing it the pointer to the right child node
}                                                                   //  end function definition
/*********************************************************************************************************************************************************
                                                    THIS MARKS THE END OF THE FUNCTION insert()
**********************************************************************************************************************************************************/









/*********************************************************************************************************************************************************
                                            THIS MARKS THE BEGINNING OF THE FUNCTION displayInOrder()

This function (and its public interface counterpart showInOrder()) was written soley for debugging purposes and is not required for running the program.

The purpose of this function is to display the employee ID number and name of every employee in ascending order by ID number.

This function can only be called by first calling its public interface counterpart showInOrder() which will then call this function displayInOrder(),
passing in the pointer to the root node. The use of a public interface function showInOrder() was done to allow the function displayInOrder() to use
recursion to step through the entire binary tree. Without the interface function showInOrder() passing the pointer to the root node to displayInOrder()
upon its initial execution, a pointer to the root node would have had to have been initialized directly inside of displayInOrder(), causing subsequent
recursive calls to displayInOrder() to always reset the pointer back to the root node, causing an infinite loop and, consequently, a stack overflow.

This function starts by continuing to call itself, passing in the pointer to the left child node each time until the pointer no longer points to a node,
signaling that a leaf of the tree has been reached. In this way, we will have reached the employee node with the smallest ID number. The employee's
information will be displayed. Then the function proceeds to call itself, only this time passing in the pointer to the right child node. This results in
the function recursively calling itself again, using the pointer to the left child node each time until another leaf is reached and the employee information
displayed. The function continues in this fashion, resulting in each employee's information being displayed in ascending order by ID number.
**********************************************************************************************************************************************************/
void EmployeeList::displayInOrder(TreeNode* tree) const             //  begin function definition
{
    if (tree)                                                       //  if the current TreeNode pointer is pointing to a node
    {
        displayInOrder(tree->left);                                 //  recursively call this function, passing it the pointer to the left child node
        cout << tree->employee.getID() << " " << tree->employee.getName()   //  display the employee information in the current node
             << endl;                                                       //  display a newline for formatting
        displayInOrder(tree->right);                                //  recursively call this function, passing it the pointer to the right child node
    }
}                                                                   //  end function definition
/*********************************************************************************************************************************************************
                                                    THIS MARKS THE END OF THE FUNCTION displayInOrder()
**********************************************************************************************************************************************************/









/*********************************************************************************************************************************************************
                                            THIS MARKS THE BEGINNING OF THE FUNCTION searchNameByID()

The purpose of this function is to search for an EmployeeInfo node containing a specified employee ID number and display the corresponding employee's name.
This function starts by prompting the user to enter an employee ID number. This function then passes the function getName() the pointer to the root node
of the tree as well as the employee ID number. The function getName() is a recursive function which searches the tree for a node containing the specified
employee ID number, and it returns a string containing the name of the employee. In the event that no match was found, getName() will return an empty
string. The results of getName() are stored. If getName() returned an empty string, and error message is displayed, otherwise, the employee's ID number
and name will be displayed.
**********************************************************************************************************************************************************/
void EmployeeList::searchNameByID() const                           //  begin function definition
{
    int id;                                                         //  integer variable to hold the employee ID number
    string name;                                                    //  string variable to hold the employee's name

    cout << " Enter the ID number of the employee you would like to search for: ";      //  prompt the user to enter an employee ID number
    cin >> id;                                                      //  store the ID number
    cout << endl;                                                   //  display a newline

    name = getName(root, id);                                       //  search the tree for the node containing the ID number. If a match is found, store the employee name (otherwise, it will store a blank string as the name)

    if (name.empty())                                               //  if the name came back as a blank string, then no match was found
        cout << " Employee not found";                              //  display an error message
    else                                                            //  otherwise, a match was found
        cout << "   ID: " << id << endl                             //  display the employee ID number
             << " name: " << name;                                  //  display the employee's anme

    cout << endl << endl << endl << endl;                           //  display a few newlines for formatting
}                                                                   //  end function definition
/*********************************************************************************************************************************************************
                                                    THIS MARKS THE END OF THE FUNCTION searchNameByID()
**********************************************************************************************************************************************************/









/*********************************************************************************************************************************************************
                                                THIS MARKS THE BEGINNING OF THE FUNCTION getName()

The purpose of this function is to search for an EmployeeInfo node containing a specified employee ID number and return a string containing the employee's
name. This function is called inside of the function searchNameByID(). The function searchNameByID() passes getName() the pointer to the root node of the
tree as well as the employee ID number to be searched for. If the pointer is pointing to a node, the function compares the employee ID number in question
against the employee ID number stored in the node. If the ID numbers match, the function will return the name of the employee. If the ID number in question
is a smaller number than the ID stored in the node, then getName() is recursively called with the pointer to the left child node. Otherwise, the function is
recursively called with the pointer to the right child node. The function continues in this fashion until either it finds and returns a matching name, or
it reaches a leaf (a null pointer), signaling that no match could be found and forcing the function to return an empty string.
**********************************************************************************************************************************************************/
string EmployeeList::getName(TreeNode* tree, int id) const          //  begin function definition
{
    while (tree)                                                    //  while the current TreeNode pointer is pointing to a node
    {
        if (id == tree->employee.getID())                           //  check and see if the employee ID number stored in this node matches the ID number in question
            return tree->employee.getName();                        //  return the name of this employee
        else if (id < tree->employee.getID())                       //  if they dont match, check and see if the employee ID number in question is smaller than the ID number stored in the current node
            tree = tree->left;                                      //  move down to the left child node by setting the current TreeNode pointer equal to the address of the left child node
        else                                                        //  otherwise, the ID in question must be larger than the ID of the current node
            tree = tree->right;                                     //  move down to the right child node by setting the current TreeNode pointer equal to the address of the right child node
    }

    return("");                                                     //  execution of this line signifies that no match could be found. Return an empty string
}                                                                   //  end function definition
/*********************************************************************************************************************************************************
                                                    THIS MARKS THE END OF THE FUNCTION getName()
**********************************************************************************************************************************************************/









/*********************************************************************************************************************************************************
                                                THIS MARKS THE BEGINNING OF THE FUNCTION destroySubtree()

The purpose of this function is to delete all nodes in the tree. This function is called by the destructor. This function starts by continuing to call
itself, passing in the pointer to the left child node each time until the pointer no longer points to a node, signaling that a leaf of the tree has been
reached. Then the function proceeds to call itself, only this time passing in the pointer to the right child node. This results in the function recursively
calling itself again, using the pointer to the left child node until another leaf is reached. When the function finds that both the left and right child
nodes are empty, the node is deleted. The function continues in this fashion until the entire tree is deleted.
**********************************************************************************************************************************************************/
void EmployeeList::destroySubtree(TreeNode* tree)                   //  begin function definition
{
    if (!tree) return;                                              //  if the TreeNode pointer no longer points to a node, then we've successfully deleted the entire tree. Terminate execution of this function
    else                                                            //  otherwise, we need to keep traversing the tree and deleting the nodes
    {
        destroySubtree(tree->left);                                 //  recursively call this function, passing in the address of the current nodes left child node
        destroySubtree(tree->right);                                //  recursively call this function, passing in the address of the current nodes right child node
        delete tree;                                                //  delete the node
    }
}                                                                   //  end function definition
/*********************************************************************************************************************************************************
                                                THIS MARKS THE END OF THE FUNCTION destroySubtree()
**********************************************************************************************************************************************************/

/*********************************************************************************************************************************************************
**********************************************************************************************************************************************************
                                            THIS MARKS THE END OF THE MEMBER FUNCTION DEFINITIONS
**********************************************************************************************************************************************************
**********************************************************************************************************************************************************/