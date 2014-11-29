//
//  Node.h
//  HuffmanCodingAlgorithm
//
//  Created by Michal Moskala on 29/11/14.
//  Copyright (c) 2014 Michal Moskala. All rights reserved.
//

#ifndef __HuffmanCodingAlgorithm__Node__
#define __HuffmanCodingAlgorithm__Node__

#include <stdio.h>

class Node {
public:
	char key;
	int value;
	Node* leftChild;
	Node* rightChild;
	Node();
	Node(char key, int value);
};

#endif /* defined(__HuffmanCodingAlgorithm__Node__) */
