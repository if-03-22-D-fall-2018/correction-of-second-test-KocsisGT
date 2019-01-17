/*----------------------------------------------------------
 *				HTBLA-Leonding / Klasse: 2DHIF
 * ---------------------------------------------------------
 * Exercise Number: 0
 * Title:			dictionary.cpp
 * Author:			Kocsis Patrik
 * Due Date:		January 10. 2019
 * ----------------------------------------------------------
 * Description:
 * Implementation of dictionary.h.
 * ----------------------------------------------------------
 */
#include <stdlib.h>
#include "dictionary.h"
#include "general.h"
#include <ctype.h> //new implementation
#include <string.h> //new implementation

#define WORD_COUNT 45

typedef struct Node* NodeStruct;

struct Node
{
  const char* word;
  Dictionary dict;
  struct Node* next;
};

struct DictionaryImplementation
{
  int length;
  NodeStruct head;
  NodeStruct butt; //
  NodeStruct iterat; //
};

Dictionary new_dictionary()
{
  Dictionary dictionary = (Dictionary)malloc(sizeof(struct DictionaryImplementation));
  dictionary->length = 0;
  dictionary->head = 0;
  dictionary->butt = 0; // added this line
  dictionary->iterat = 0; // added this line
  return dictionary;
}

void delete_dictionary(Dictionary dictionary)
{
  NodeStruct current = dictionary->head;

  while(current != 0)
  {
    NodeStruct to_be_deleted = current;
    current = current->next;
    sfree(to_be_deleted);
  }

  sfree(dictionary);
}

void add(Dictionary dict, const char* word)
{
  if(word != 0)
  {
    NodeStruct current = dict->head;
    NodeStruct node_to_add = (NodeStruct)malloc(sizeof(struct Node));
    node_to_add->word = word; //added this line
    node_to_add->next = 0;

    if(dict->head == 0)
    {
      dict->head = node_to_add;
      dict->length++; //new implementation
      return; //new implementation
    }
    else
    {
      while (current->word != word && current->next != 0) //added "current->word != word && "
      {
        //delete what was here
        current = current->next;
      }
      //added an enter/empty line here
      if(current->word == word){ //added "{"
        return;  //moved it and added ";" to the end
      } //added "}"
      else //new implementation
      { //new implementation
        current->next = node_to_add; //moved it here
        dict->length++; //moved it here
      } //new implementation
    }
    dict->butt = node_to_add; //new implementation
    //deleted
  }
}

int get_size(Dictionary dict)
{
  return dict->length;
}


bool is_in_dict(Dictionary dict, const char* word)
{
  if(dict->head == 0) //new implementation
  { //new implementation
    return false; //new implementation
  } //new implementation
  NodeStruct current = dict->head; //new implementation

  while(strcasecmp(current->word, word) != 0 && current->next != 0) //new implementation
  { //new implementation
    current = current->next;  //new implementation
  } //new implementation
  if(strcasecmp(current->word, word) == 0)  //new implementation
  { //new implementation
    return true;  //new implementation
  } //new implementation
  else  //new implementation
  { //new implementation
    return false; //new implementation
  } //new implementation
  return false; //new implementation
  //deleted some lines
}

void start_iterating(Dictionary dict)
{
  dict->iterat = dict->head;  //new implementation
}

bool has_next(Dictionary dict)
{
  if(dict->iterat != 0) //new implementation
  { //new implementation
    return true;  //new implementation
  } //new implementation
  return false;   //new implementation
}

const char* get_next_entry(Dictionary dict)
{
  if(has_next(dict))  //new implementation
  { //new implementation
    const char* word = dict->iterat->word;  //new implementation
    dict->iterat = dict->iterat->next;  //new implementation

    return word;  //new implementation
  } //new implementation

  return 0; //new implementation
}

void insert_sorted(Dictionary dict, const char* word)
{
  NodeStruct current = dict->head;  //new implementation
  NodeStruct new_node = (NodeStruct) malloc(sizeof(struct Node)); //new implementation
  new_node->word = word;  //new implementation
  new_node->next = 0; //new implementation
  if(dict->head == 0) //new implementation
  { //new implementation
    add(dict, word);  //new implementation
  } //new implementation
  else  //new implementation
  { //new implementation
    if(is_in_dict(dict, word))  //new implementation
    { //new implementation
      return; //new implementation
    } //new implementation

    if(strcasecmp(dict->head->word, word) > 0)  //new implementation
    { //new implementation
      new_node->next = dict->head;  //new implementation
      dict->head = new_node;  //new implementation
      dict->length++; //new implementation
    } //new implementation
    else  //new implementation
    { //new implementation
      while(current->next != 0 && strcasecmp(current->next->word, word) < 0)  //new implementation
      { //new implementation
        current = current->next;  //new implementation
      } //new implementation
      if(current->next == 0)  //new implementation
      { //new implementation
        add(dict, word);  //new implementation
      } //new implementation

      if(strcasecmp(current->next->word, word) > 0) //new implementation
      { //new implementation
        new_node->next = current->next; //new implementation
        current->next = new_node; //new implementation
        dict->length++; //new implementation
      } //new implementation
    } //new implementation
  } //new implementation
}
