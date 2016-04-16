
// Byron Burdette
// COP2535.0M1


/*********************************************************************************************************************************************************
**********************************************************************************************************************************************************
                                                CLASS SPECIFICATION FILE FOR THE CLASS EmployeeList

The purpose of this class is to be able to create a binary tree where each node in the tree represents an employee, including their employee ID number
and name
**********************************************************************************************************************************************************
**********************************************************************************************************************************************************/






/************************************************                 PREPROCESSOR DIRECTIVES                *************************************************/
#pragma once                                //  include guard ensures this file is included, but only once

#include"EmployeeInfo.h"                    //  include the file for employee objects
#include<iostream>                          //  includes the library for standard I/O stream objects
#include<String>                            //  include the library for string objects
#include<sstream>                           //  include the library for string stream objects
#include<fstream>                           //  include the library for file stream objects
/*********************************************************************************************************************************************************/


using namespace std;                        //  lifts all entities in the standard namespace into the current global namespace





class EmployeeList                          //  begin class declaration
{
private:
    //  TreeNode class is used to create new nodes that will make up the tree
    class TreeNode                          //  begin class definition
    {
        friend class EmployeeList;          //  declare EmployeeList a friend of TreeNode to give EmployeeList acces to members of TreeNode

        EmployeeInfo employee;              //  create and employee object that will hold the employee's name and ID number
        TreeNode* left;                     //  pointer keeps track of the left child of the node
        TreeNode* right;                    //  pointer keeps track of the right child of the node

        /*  constructor is used to set the name and ID number of the employee object created earlier as well as to initialize
            the left and right child pointers. New nodes have no children, so the pointers are set to null  */
        TreeNode(int id, string name, TreeNode* left1 = NULL, TreeNode* right1 = NULL)  //  begin constructor definition. It is passed the employee's ID number and name
        {
            employee.setInfo(id, name);     //  set the employee's ID number and name equal to the values passed into the constructor
            left = left1;                   //  set the left child pointer
            right = right1;                 //  set the right child pointer
        }                                   //  end constructor definition
    };                                      //  end TreeNode class definition

    TreeNode* root = NULL;                  //  create the root node of the tree. 
    ifstream inFile;                        //  create an input file object. This is where we'll get the data for each employee
    
    void insert(TreeNode *&, int, string);  //  function for inserting new nodes into the tree
    void destroySubtree(TreeNode*);         //  function for destroying the tree
    void displayInOrder(TreeNode*) const;   //  function for displaying all the nodes in the tree in ascending order by employee ID number
    string getName(TreeNode*, int) const;   //  function for retrieving the name of an employee with the specified ID number


public:
    EmployeeList();                                                 //  default constructor will be used to read the input file and create the binary tree with all the employee information
    ~EmployeeList() { destroySubtree(root); }                       //  destructor calls destroySubtree() to destroy the tree

    /*  public function showInOrder() used as an interface for private function displayInOrder() to display all the nodes in the tree in ascending
        order by employee ID number. Seperate public interface serves to facilitate the use of recursion in private function displayInOrder()  */
    void showInOrder(void) const { displayInOrder(root); }
    void searchNameByID() const;                                    //  function used to search for an EmployeeInfo node containing a specified employee ID number and display the corresponding employee's name
};                                                                  //  end EmployeeList class declaration

/*********************************************************************************************************************************************************
**********************************************************************************************************************************************************
                                                    THIS MARKS THE END OF THE CLASS SPECIFICATION FILE
**********************************************************************************************************************************************************
**********************************************************************************************************************************************************/