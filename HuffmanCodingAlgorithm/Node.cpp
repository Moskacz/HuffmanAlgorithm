//
//  Node.cpp
//  HuffmanCodingAlgorithm
//
//  Created by Michal Moskala on 29/11/14.
//  Copyright (c) 2014 Michal Moskala. All rights reserved.
//

#include "Node.h"

Node::Node() {
	this->key = '\0';
	this->value = 0;
	this->leftChild = NULL;
	this->rightChild = NULL;
}

Node::Node(char key, int value) {
	this->key = key;
	this->value = value;
	this->leftChild = NULL;
	this->rightChild = NULL;
}