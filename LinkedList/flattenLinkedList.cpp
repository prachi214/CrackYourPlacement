//Flattening a Linked List

class Solution
{
public:
  Node *merge(Node *list1, Node *list2)
  {
    Node *dummyNode = new Node(-1);
    Node *res = dummyNode;
    while (list1 != NULL && list2 != NULL)
    {
      if (list1->data < list2->data)
      {
        // bottom for child node
        res->bottom = list1;
        res = list1;
        list1 = list1->bottom;
      }
      else
      {
        res->bottom = list2;
        res = list2;
        list2 = list2->bottom;
      }
      // each child node next
      res->next = NULL;
    }
    if (list1)
      res->bottom = list1;
    else
      res->bottom = list2;
    // make child node next all null
    if (dummyNode->bottom)
    {
      // parent node ke next ko null, bcoz LL ko vertical connect krna h
      dummyNode->bottom->next = NULL;
    }
    return dummyNode->bottom;
  }
  Node *flatten(Node *root)
  {
    if (root == NULL || root->next == NULL)
    {
      return root;
    }

    Node *mergedHead = flatten(root->next);
    root = merge(root, mergedHead);

    return root;
  }
};