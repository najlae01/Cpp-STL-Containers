/*
*  File:        arrayListType.h
*  Author: 		
*  Description: Definition of the arrayListType template class.
*
*
*  Date: 2022-05-05 20:45
*
*/
#ifndef H_arrayListType
#define H_arrayListType 
 
/*
*  arrayListType template class: represents a dynamic array of any data type with a maximum size
*  determined by the user while instantiating. It performs flexible functions that a static array
*  can not.
*  Those functions involve inserting an elemnet at a specified position or at the end of the array,
*  deleting an element at a specified location from the array, searching for an element, replacing
*  an element, retrieving an element at a specific position, as well as removing all the occurences
*  of an element from the array.
*
* The arrayListType template class is an abstract class since it contains pure virtual functions
* that need to be implemented in its derived classes.
*
*
*/
template <class elemType>
class arrayListType 
{
public: 

	/*
    *  Overloads the = operator so we can use it
    *   to assign an arrayListType instance to another
    *    				one.
    *
	* RETURN: A pointer to the current object.
	*
	*  PARAM: otherList - arrayListType<elemType> 
	* 	the arrayListType's object to get the attributes
	*   			values from.
	* 
    */
    const arrayListType<elemType>& operator=(const arrayListType<elemType>& otherList);

	/*
    *  Determines if the array is empty.
    *
    *  RETURN: true if the array is empty,
    *          false otherwise.
    * 
    */
    bool isEmpty() const;

	/*
    *  Determines if the array is full.
    *
    *  RETURN: true if the array is full,
    *          false otherwise.
    * 
    */
    bool isFull() const;

	/*
    *  Determines the current number of 
    *		items in the array.
    *
    *  RETURN: the value of the
    *		attribute length.
    * 
    */
    int listSize() const;

	/*
    *  Determines the maximum size of 
    *			the array.
    *
    *  RETURN: the value of the
    *		attribute maxSize.
    * 
    */
    int maxListSize() const;

	/*
    *  Prints the items of the array.
    *
    *  POST : The array's elements
    *		are printed on the standard 
	*			output device.
    * 
    */
    void print() const;

	/*
    *  Determines if the given item's index
	*  position in the array is the same as
	*  the given position in parameters 
	*			'location'.
	*
    * PRE: The given location isn't out of
    *  range, and the item's index position
	* in the array is equal to location value.	 
    *
    * RETURN: true if the PRE condition is verified,
    *          false otherwise.
    *
    * EXCEPTION: If the given location is out of
    * range, an appropriate message is displayed.
	*
	*  PARAM: item - elemType(Generic Type)
	*           the item to check if it's position 
	*			is equal to a given position.
	*		  location - int the given index position 
	*   		to compare with the item's index position.
	* 
    */
    bool isItemAtEqual(int location, const elemType& item) const;

	/*
    *  Starting at the given parameter 'location',
	*  it shifts the items of the array down,
	*	and inserts the given item insertItem
	*  	at the specified position 'location'
	*  	in the array, and then increments the
	*   'length' value, which represents the
	*    number of elements in the array,
	*				 by one.
	*
	* NOTE: This is a pure virtual function !
	*
    * PRE: The given location isn't out of
    * 	range, and the array isn't full.
    *
	* POST: The given insertItem is inserted
	* in the array at the specified position location.		 
    * 
    * EXCEPTION: If the given location is out of
    *  range or if the array is full,
	*  an appropriate message is displayed.
	*
	*  PARAM: insertItem - elemType(Generic Type)
	*           the item to be inserted in the array.
	*		  location - int the index position 
	*   		where to insert the item.
	* 
    */
    virtual void insertAt(int location, const elemType& insertItem) = 0;

	/*
    *  Inserts the given item insertItem
	*  	at the end of the array, i.e where 
	*   the array's index is equal to
	*	length value, and then increments
	*   'length' value, which represents the
	*    number of elements in the array,
	*				 by one.
	*
	* NOTE: This is a pure virtual function !
	*
	* POST: The given insertItem is inserted
	* 			at the end of the array.		 
    * 
    * EXCEPTION: If the array is full,
	*  an appropriate message is displayed.
	*
	*  PARAM: insertItem - elemType(Generic Type)
	*			 the item to be inserted at the
	*				end of the array.
	* 
    */
    virtual void insertEnd(const elemType& insertItem) = 0;

	/*
    *  Removes the item at the given position
    *  'location' from the array, and then
	*	decrements the'length' value,
	*   which represents the number of 
	*         elements in the array,
	*				 by one.
	*
    * PRE: The given location isn't out of
    * 				range.
    *
	* POST: The item at the given
	* location is removed from the array.		 
    * 
    * EXCEPTION: If the given location is out of
    * range, an appropriate message is displayed.
	*
	*  PARAM: location - elemType(Generic Type)
	*		 the index position of the item to
	*			 remove from the array.
	* 
    */
    void removeAt(int location);

	/*
    *  Retrieves the item at the given position
    *  'location' from the array, and returns it.
	*
    * PRE: The given location isn't out of
    * 				range.
    *
	* RETURN: The retrieved item at the specified
	*			position location. 
    * 
    * EXCEPTION: If the given location is out of
    * range, an appropriate message is displayed,
    * and the function is asserted to end.
	*
	*  PARAM: location - elemType(Generic Type)
	*    the index position of the item to retrieve.
	* 
    */
    elemType retrieveAt(int location) const;

	/*
    *  Replaces the item at the given position
    *  'location' in the array by the value
	* 		of the given item repItem.
	*
	* NOTE: This is a pure virtual function !
	*
    * PRE: The given location isn't out of
    * 				range.
    *
	* POST: The item at the given
	* location in the array is replaced by
	* 		the given item repItem.	 
    * 
    * EXCEPTION: If the given location is out of
    * range, an appropriate message is displayed.
	*
	*  PARAM: repItem - elemType(Generic Type)
	*           the item to be inserted in
	*   		 		the array.
	*		  location - int the index position 
	*   		where to insert the item.
	* 
    */
    virtual void replaceAt(int location, const elemType& repItem) = 0;

	/*
    *  Removes the items from the array by assigning
	*   the value 0 to the attribute 'length',
	*    which represents the number of 
	*         elements in the array.
	*
	* POST: The array is empty.		 
    * 
    */
    void clearList();

	/*
    *  Searches for the index position of
	*   the given item searchItem in the
	* 				array.
	*
	* NOTE: This is a pure virtual function !
	*
	* PRE: The given item is found within 
	*  			the array items.
	*
	* RETURN: The index position of
	*   the given item searchItem in the
	* 	 	array if it's found. 
	*  	   Otherwise, returns -1.
	*
	*  PARAM: searchItem - elemType(Generic Type) 
	* 	the item to be searched for in the array.
	* 
    */
    virtual int seqSearch(const elemType& searchItem) const = 0;

	/*
    *  Removes the given item removeItem from
	* the array, and then decrements the'length'
	* value, which represents the number of
	* elements in the array, by one.
	*
	* NOTE: This is an abstract function !
	*
	* PRE: The given item is found within 
	*  			the array items.
	*
	* POST: The given item removeItem is 
	*		 removed from the array.	
	*	 
	*  PARAM: removeItem - elemType(Generic Type)
	* 	the item to be removed from the array.
    */
    virtual void remove(const elemType& removeItem) = 0;

    /*
    *  Parameterized constructor
    *
    *  Creates an arrayListType instance.
    *
    *  Initializes length to 0.
    *  Initializes maxSize to the supplied value
	*  of size if an argument was passed to the
	*  parameters. 
	*  If no argument was passed, or if the 
	*  supplied value was less than or equal
	*  than 0, it initializes maxSize to the
	*      default value 100.
	*  Creates an array of integers which size
	*  is equal to maxSize.
	*
	*  PARAM: size - elemType(Generic Type) to
	*	 initialize the maxSize attribute.
    */
    arrayListType(int size = 100);

	/*
    *  Copy constructor
    *
    *  Creates an arrayListType instance copy
	*   of the given arrayListType in parameters.
	*
    *  Initializes length to the otherList's length.
    *  Initializes maxSize to the otherList's maxSize.
	*  Creates an array of integers which size
	*  is equal to maxSize.
	*  Fill all the elements of the array list by
	*  the otherList's elements values.
	*
	*  PARAM: otherList - arrayListType<elemType> from
	*  which the attributes will be taken to create an 
	*  arrayListType instance.
    */
    arrayListType (const arrayListType<elemType>& otherList);

    /*
    *  Destructor
    *  Deallocate the memory occupied by the array.
    */
    virtual ~arrayListType();

protected:
    elemType *list; // pointer to the array of the generic type 'elemType' holding the list's items
    int length;     // current number of items strored in the the array
    int maxSize;    // maximum size of the array
};


#include "arrayListType.cpp"

#endif
