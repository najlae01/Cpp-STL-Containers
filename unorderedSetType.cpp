/*
*  File:        unorderedSetType.cpp
*  Author: 		Najlae ABARGHACHE
*  Description: Implementation of the unorderedSetType template class.
*
*
*  Date: 2022-05-05 20:45
*
*/
 
#include "unorderedArrayListType.h"  
#include "arrayListType.h"

using namespace std; 

template <class elemType>
void unorderedSetType <elemType>::insertAt(int location, 
                                         const elemType& insertItem)
{
  	int status=0;

 	status = this -> seqSearch(insertItem); /* Calling the base class unorderedArrayListType's method
	 										 seqSearch to check wether the element insertItem already 
											  exists in the array or not. If it exists the seqSearch
											  method must return the index position of this item in the 
											  array. Otherwise, it returns -1.*/


  	if(status==-1)
  	{											/* If the return's value of the seqSearch method is -1, 
	  												means the insertItem isn't already in the list, then
												  	we call the unorderedArrayListType's method insertAt
												 	by passing to its parameters the item to be inserted
												  	insertItem and the index position location. */

    	unorderedArrayListType<elemType>::insertAt(location, insertItem);

  	}

  	else
  	{											/* If the return's value of the seqSearch method is
	  											 different than -1, means the insertItem is already 
												   in the list, then an appropriate message is displayed. */
												  
    	cout << "The item, " << insertItem << " , is already in the list and cannot be inputed." << endl; 
  	}

}

template <class elemType>
void unorderedSetType<elemType>::insertEnd
                                 (const elemType& insertItem)
{
 	int status=0;

 	status=unorderedArrayListType<elemType>::seqSearch(insertItem);/* Calling the base class unorderedArrayListType's method
	 										 						seqSearch to check wether the element insertItem already 
											  						exists in the array or not. If it exists the seqSearch
											  						method must return the index position of this item in the 
											  						array. Otherwise, it returns -1.*/

  	if(status==-1)
  	{																/* If the return's value of the seqSearch method is -1, 
	  																means the insertItem isn't already in the list, then
												  					we call the unorderedArrayListType's method insertEnd
												  					by passing to its parameters the item to be inserted
												  					insertItem at the end of the array. */
		unorderedArrayListType<elemType>::insertEnd(insertItem);
	}
	else
  	{																/* If the return's value of the seqSearch method is
	  											 					different than -1, means the insertItem is already 
												   					in the list, then an appropriate message is displayed. */
    	cout << "The item, " << insertItem << " , is already in the list and cannot be inputed." << endl; 
  	} 
} //end insertEnd

template <class elemType>
void unorderedSetType<elemType>::replaceAt(int location, 
                                       const elemType& repItem)
{
  	int status=0;
  	status=unorderedArrayListType<elemType>::seqSearch(repItem);/* Calling the base class unorderedArrayListType's method
	 										 					seqSearch to check wether the element repItem already 
											  					exists in the array or not. If it exists the seqSearch
											 					 method must return the index position of this item in the 
											 					 array. Otherwise, it returns -1.*/
  	
	if(status==-1)
  	{															/* If the return's value of the seqSearch method is -1, 
				  												means the insertItem isn't already in the list, then
															  	we call the unorderedArrayListType's method replaceAt
															 	by passing to its parameters the item to be replaced with
															  	repItem and the index position location. */
		unorderedArrayListType<elemType>::replaceAt(location, repItem);
	}
	else
  	{															/* If the return's value of the seqSearch method is
	  											 				different than -1, means the insertItem is already 
												   				in the list, then an appropriate message is displayed. */
    	cout << "The item, " << repItem << " , is already in the list and cannot be inputed." << endl; 
  	}
} //end replaceAt

template <class elemType>
unorderedSetType<elemType> unorderedSetType<elemType>::operator+(unorderedSetType<elemType> rightObject)
{
 	unorderedSetType<elemType> unionGroup; /* Creates an unorderedSetType instance to store the union group of items of this 
	 														object set and the rightObject set passed in parameters*/
  	int status=0;
  	int i=0;
  	for(i=0; i < rightObject.length; i++)
  	{															/*  For each item of the unorderedSetType instance
																rightObject we call the base class unorderedArrayListType's
																 method seqSearch to check wether the item already 
											  					 exists in the rightObject's array or not. If it exists the
																  seqSearch method must return the index position of this 
																  item in the array. Otherwise, it returns -1.*/
    	auto item=rightObject.list[i];
    	status=rightObject.seqSearch(item);
    	if(status!=-1)
	    {														/* If the return's value of the seqSearch method is
	    															different than -1, means that the item exists in the array,
												  					we call then the unorderedSetType's method insertEnd
												  					by passing to its parameters the item to be inserted
												  					 at the end of the array. By calling the unorderedSetType's
																	    method insertEnd, we guarantee that the item won't be 
																		inserted in the set if it already exists. */
	      unionGroup.insertEnd(item);
	    }
  	} 
  	for(i=0; i < this->length; i++) /* We do the same for this current object. */
  	{
    	auto item=this->list[i];
    	status=unorderedArrayListType<elemType>::seqSearch(item);
	    if(status!=-1)
	    {
	      unionGroup.insertEnd(item);
	    }
  	} 
  	return unionGroup;  
}
//Union


template <class elemType>
unorderedSetType<elemType> unorderedSetType<elemType>::operator-(unorderedSetType<elemType> rightObject)
{
 	unorderedSetType<elemType> intersectionGroup; /* Creates an unorderedSetType instance to store the intersection group of 
	 													items of this object set and the rightObject set passed in parameters*/
	int status=0;
	int i=0;
	for(i=0; i < rightObject.length; i++)
	{   									                 /*  For each item of the unorderedSetType instance
																rightObject we call the base class unorderedArrayListType's
																 method seqSearch to check wether the item already 
											  					 exists in the current object's array or not.
																 If it exists the seqSearch method must return the index 
																 position of this item in the array. Otherwise, it returns -1.*/
  	
		auto item=rightObject.list[i];
	    status=unorderedArrayListType<elemType>::seqSearch(item);
	    
	    if(status!=-1)
    	{														/* If the return's value of the seqSearch method is
	    															different than -1, means that the item exists in the array,
												  					we call then again the base class unorderedArrayListType's
																 method seqSearch to check if the item exists in the otherObject 
																 set's array. If it does then we call the unorderedSetType's method
																   insertEnd by passing to its parameters the item to be inserted
												  					 at the end of the array. By calling the unorderedSetType's
																	    method insertEnd, we guarantee that the item won't be 
																		inserted in the set if it already exists. */
      		status=rightObject.seqSearch(item);
  				if(status!=-1)
      			{
        			intersectionGroup.insertEnd(item);
      			}
    	}
	}
	for(i=0; i < this-> length; i++) /* We do the same for this current object. */
    {
    	auto item=this->list[i];
    	status=rightObject.seqSearch(item);
  
		if(status!=-1)
      	{
	        status=unorderedArrayListType<elemType>::seqSearch(item);
	        if(status!=-1)
	        {
	          intersectionGroup.insertEnd(item);
	        }
      	}
    } 
  	return intersectionGroup;
}
//Intersection


template <class elemType>
unorderedSetType<elemType>::unorderedSetType(int size)
                       : unorderedArrayListType<elemType>(size)
{
}
