
// Byron Burdette
// COP2535.0M1


/*********************************************************************************************************************************************************
**********************************************************************************************************************************************************
                                                    CLASS SPECIFICATION FILE FOR THE CLASS EmployeeInfo

The purpose of this class is to be able to create objects that will represent individual employees. With these objects, we can store and reference an
employee's name and ID number.
**********************************************************************************************************************************************************
**********************************************************************************************************************************************************/






/************************************************                 PREPROCESSOR DIRECTIVES                *************************************************/
#pragma once                                //  include guard ensures this file is included, but only once

#include<iostream>                          //  includes the library for standard I/O stream objects
/*********************************************************************************************************************************************************/


using namespace std;                        //  lifts all entities in the standard namespace into the current global namespace





class EmployeeInfo                          //  begin class definition
{
private:
    int ID;                                 //  declare an int variable "ID" for storing the employee's ID number
    string name;                            //  declare a string variable "name" for storing the employee's name

public:
    //  this function sets the values stored in "ID" and "name"
    void setInfo(int id, string n)          //  begin function definition. It will be passed an int for the ID number and a string for the name
    {
        ID = id;                            //  set the ID number equal to the number that was passed into the function
        name = n;                           //  set the name equal to the string that was passed into the function
    }                                       //  end function definition

    int getID() { return ID; }              //  function returns the ID number for the employee

    string getName() { return name;  }      //  function returns the name of the employee
};                                          //  end class definition

/*********************************************************************************************************************************************************
**********************************************************************************************************************************************************
                                                THIS MARKS THE END OF THE CLASS SPECIFICATION FILE
**********************************************************************************************************************************************************
**********************************************************************************************************************************************************/