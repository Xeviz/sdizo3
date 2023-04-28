cmake_minimum_required(VERSION 3.25)
project(sdizo1)

set(CMAKE_CXX_STANDARD 17)

add_executable(sdizo1 main.cpp myArray/MyArray.cpp myArray/MyArray.h helpingTools/HelpingTools.cpp helpingTools/HelpingTools.h helpingTools/MyMenu.cpp helpingTools/MyMenu.h myList/MyList.cpp myList/MyList.h myList/ListNode.cpp myList/ListNode.h myHeap/MyHeap.cpp myHeap/MyHeap.h myTree/TreeNode.cpp myTree/TreeNode.h myTree/MyTree.cpp myTree/MyTree.h)
