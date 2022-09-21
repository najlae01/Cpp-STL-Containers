/*
*  File:        main.cpp
*  Author: 		Najlae ABARGHACHE
*  Description: Client program to test modifications to the unorderedSetType template class.
*
*
*  Date: 2022-05-05 20:45
*
*/
#include <iostream>
#include <string>
#include "unorderedArrayListType.h"
#include "unorderedSetType.h"


using namespace std;

int main()
{
  int integerArray1[7]={2, 3, 4, 1, 5, 6};
  int integerArray2[7]={9, 4, 5, 2, 7, 8};
  string strval1[5] = {"The", "cat", "in", "the", "hat"};
  string strval2[5] = {"met", "the dog", "in", "the", "boat"};
  unorderedSetType<int> iList;
  unorderedSetType<string> sList;

  int length=7;
   //--------------Inserting into the set of integers the distinct elements of the integerArray1------------------------ 
  int i=0;
  for(i=0; i < length-1; i++ )
  {   
    int item=integerArray1[i];
    iList.insertEnd(item);
  }
   //--------------Printing the elements of the set of integers ------------------------ 
  cout << "\n----------------Printing the elements of the set of integers after inserting the distinct elements of the integerArray1 array--------------\n" << endl;
  iList.print();  
  
    //--------------Inserting into the set of strings the distinct elements of the strval1 array------------------------
  length=5;
  for(i=0; i <length-1; i++ )
  {   
    string item2=strval1[i];
    sList.insertEnd(item2);
  }
    //--------------Printing the elements of the set of strings ------------------------ 
  cout << "\n----------------Printing the elements of the set of strings after inserting the distinct elements of the strval1 array--------------\n" << endl;
  sList.print();  


    //--------------Inserting at the end of the set of integers a duplicate integer 2------------------------
  cout << "\nAttempting to insert duplicate integer at the end of the set." << endl;
  int duplicate=2;
  iList.insertEnd(duplicate);
    //--------------Printing the elements of the set of integers ------------------------ 
  cout << "\n----------------Printing the elements of the set of integers after attempting to insert a duplicate integer 2 at the end of the set.--------------\n" << endl;
  iList.print(); 

    //--------------Inserting at the end of the set of strings a duplicate string 'The'------------------------
  cout << "\nAttempting to insert duplicate string at the end of the set." << endl;
  string duplicate2="The";
  sList.insertEnd(duplicate2);
    //--------------Printing the elements of the set of strings ------------------------ 
  cout << "\n----------------Printing the elements of the set of strings after attempting to insert a duplicate string 'The' at the end of the set.--------------\n" << endl;
  sList.print();  


  int unique=99;
  int uniquelocation=3;
   //--------------Inserting into the set of integers a non duplicate integer 99------------------------
  iList.insertAt(uniquelocation, unique);
  cout << "\nInserted " << unique << " , which is a unique number, into the list at location " << uniquelocation << "." << endl;
    //--------------Printing the elements of the set of integers ------------------------ 
  cout << "\n----------------Printing the elements of the set of integers after inserting a non duplicate integer 99--------------\n" << endl;
  iList.print(); 
  
    //--------------Inserting into the set of strings a non duplicate string 'Cookie'------------------------
  int uniquelocation2=4;
  string unique2="Cookie";
  sList.insertAt(uniquelocation2, unique2);
  cout << "\nInserted " << unique2 << " , which is a unique word, into the list at location " << uniquelocation2 << "." << endl;
    //--------------Printing the elements of the set of strings ------------------------ 
  cout << "\n----------------Printing the elements of the set of strings after inserting a non duplicate string 'Cookie'--------------\n" << endl;
  sList.print();  
  
  
   //--------------Inserting into the set of integers a duplicate integer 99 since we already inserted it------------------------
  uniquelocation=2;
  iList.insertAt(uniquelocation, unique);
  cout << "\nAttempted insertion " << unique << " , which is a duplicate number, into the list at location " << uniquelocation << "." << endl;
    //--------------Printing the elements of the set of integers ------------------------ 
  cout << "\n----------------Printing the elements of the set of integers after attempting to insert a duplicate integer 99--------------\n" << endl;
  iList.print(); 

    //--------------Inserting into the set of strings a duplicate string 'Cookie' since we already inserted it------------------------
  uniquelocation2=4;
  sList.insertAt(uniquelocation2, unique2);
  cout << "\nAttempted insertion " << unique2 << " , which is a duplicate word, into the list at location " << uniquelocation2 << "." << endl;
    //--------------Printing the elements of the set of strings ------------------------ 
  cout << "\n----------------Printing the elements of the set of strings after attempting to insert a duplicate string 'Cookie'--------------\n" << endl;
  sList.print();  




  
    //--------------Replacing an element at the location 3 of the set of integers with a non duplicate integer 22------------------------
  int unique3=22;
  int uniquelocation3=3;
  iList.replaceAt(uniquelocation3, unique3);
  cout << "\nReplaced " << unique3 << " , which is a unique number, into the list at location " << uniquelocation3 << "." << endl;
    //--------------Printing the elements of the set of integers ------------------------ 
  cout << "\n----------------Printing the elements of the set of integers after replacing the element at the location 3 of the set of integers with a non duplicate integer 22--------------\n" << endl;
  iList.print(); 

    //--------------Replacing an element at the location 4 of the set of strings with a non duplicate string 'Cake'------------------------
  int uniquelocation4=4;
  string unique4="Cake";
  sList.replaceAt(uniquelocation4, unique4);
  cout << "\nReplaced " << unique4 << " , which is a unique word, into the list at location " << uniquelocation4 << "." << endl;
    //--------------Printing the elements of the set of strings ------------------------ 
  cout << "\n----------------Printing the elements of the set of strings after replacing an element at the location 4 of the set of strings with a non duplicate string 'Cake'--------------\n" << endl;
  sList.print();  
  

    //--------------Replacing an element at the location 3 of the set of integers with a duplicate integer 22, since we already inserted it------------------------
  iList.replaceAt(uniquelocation3, unique3);
  cout << "\nAttempted replacement " << unique3 << " , which is a duplicate number, into the list at location " << uniquelocation3 << "." << endl;
    //--------------Printing the elements of the set of integers ------------------------ 
  cout << "\n----------------Printing the elements of the set of integers after attempting to replace the element at the location 3 of the set of integers with a duplicate integer 22--------------\n" << endl;
  iList.print(); 

    //--------------Replacing an element at the location 4 of the set of strings with a duplicate string 'Cake', since we already inserted it------------------------
  sList.insertAt(uniquelocation4, unique4);
  cout << "\nAttempted replacement " << unique4 << " , which is a duplicate word, into the list at location " << uniquelocation4 << "." << endl;
    //--------------Printing the elements of the set of strings ------------------------ 
  cout << "\n----------------Printing the elements of the set of strings after attempting to replace an element at the location 4 of the set of strings with a duplicate string 'Cake'--------------\n" << endl;
  sList.print();  



  int integerArray3[7]={11, 4, 5, 16, 19, 13};

  unorderedSetType<int> rightobject;
  unorderedSetType<int> integerobject; 

  length=7;
     //--------------Inserting into the set of integers the distinct elements of the integerArray3------------------------ 
  i=0;
  for(i=0; i < length-1; i++ )
  {   
    int item=integerArray3[i];
    rightobject.insertEnd(item);
  }
   //--------------Printing the elements of the set of integers rightobject------------------------ 
  cout << "\n----------------Printing the elements of the set of integers rightobject after inserting the distinct elements of the integerArray3 array--------------\n" << endl;
  rightobject.print();
  
    //--------------Printing the elements of the set of integers iList------------------------ 
  cout << "\n----------------Printing the elements of the set of integers iList.--------------\n" << endl;
  iList.print();
  
    //--------------Testing the union operator and with the two set of integers rightobject and iList-----------------------   
  integerobject=iList+rightobject;
   //--------------Printing the elements of the set of integers integerobject------------------------ 
  cout << "\n----------------Printing the elements of the set of integers integerobject, the union of the two sets iList and rightobject--------------\n" << endl;
  integerobject.print();



  string strval3[5] = {"why", "the dog", "cat", "the"};

  unorderedSetType<string> rightobjects;
  unorderedSetType<string> stringobjects; 
  
   //--------------Inserting into the set of strings the distinct elements of the strval3 array------------------------
  length=5;
  i=0;
  for(i=0; i < length-1; i++ )
  {   
    string items=strval3[i];
    rightobjects.insertEnd(items);
  }
  
   //--------------Printing the elements of the set of strings rightobjects------------------------ 
  cout << "\n----------------Printing the elements of the set of strings rightobjects after inserting the distinct elements of the strval3 array--------------\n" << endl;
  rightobjects.print();
  
      //--------------Printing the elements of the set of strings sList------------------------ 
  cout << "\n----------------Printing the elements of the set of strings sList.--------------\n" << endl;
  sList.print();

    //--------------Testing the union operator and with the two set of strings rightobjects and sList-----------------------   
  stringobjects=sList+rightobjects;
   //--------------Printing the elements of the set of strings stringobjects------------------------ 
  cout << "\n----------------Printing the elements of the set of strings stringobjects, the union of the two sets sList and rightobjects--------------\n" << endl;
  stringobjects.print();
  
    //--------------Testing the intersection operator and with the two set of integers rightobject and iList-----------------------   
  integerobject=iList-rightobject;
    //--------------Printing the elements of the set of integers integerobject------------------------ 
  cout << "\n----------------Printing the elements of the set of integers integerobject, the intersection of the two sets iList and rightobject--------------\n" << endl;
  integerobject.print();

    //--------------Testing the intersection operator and with the two set of strings rightobjects and sList-----------------------   
  stringobjects=sList-rightobjects;
   //--------------Printing the elements of the set of strings stringobjects------------------------ 
  cout << "\n----------------Printing the elements of the set of strings stringobjects, the intersection of the two sets sList and rightobjects--------------\n" << endl;
  stringobjects.print();


  return 0;
}
