# Data Structures and Algorithms 

# Introduction
 In computer science, data structures and algorithms is an extremely topic useful to learn and is most often separates a good programmer from a great one. Admittedly, I am far from the latter, but hopefully this project helps both you and me learn a lot.

 ## What will this repository contain?

 This repository will contain implementations and explanations (if I'm bothered) of common data structures and alogorithms. The implementations will be mostly in C++ and possibly other languages that I enjoy such as C, JavaScript or maybe even Python. 

# Data Structures

## Linked List

A linked list is a data structure that consists of a linear collection of nodes where a single node will point to one other node, sort of like a chain. Every linked list has a special node, called the **head**, which indicates the first node of the list. Occasionally, some implementations of linked lists might also include a **tail** node, which indicates the last node of the list.

### What is a node?

A node can be thought of as a box that contains a value. If we were to take this literally, we could imagine a physical box, with an item inside of it, and the only way to see what our box contains is if we were to look inside of it. These are the building blocks of our linked list.

### Traversing 

Due to how linked lists are formed, if you wanted to reach a specific node in the list, you would have to traverse starting from the head to each node, until the node you are on is the one you were looking for.

This can be thought of as a long line of boxes with rope connecting each of them. The first box in the chain would be considered as the head. If you thought that one of the boxes contained an item you were looking for then in order find your item, you would have to:

1. Start from the first box
2. Open it to see if it has the item your were looking for
3. If not, follow the rope that leads out of it to the next box
4. Repeat steps 2 and 3 until you find the item you were looking for.

Of course there is also the possibility that none of the boxes contained what you were looking for, but by that point, you would have needed to search every box. In order words, if you have *n* boxes, then the worst possible outcome when looking for an item would be when its in the last box in the chain, which is the *n*th box. This can also be summarised as O(n).