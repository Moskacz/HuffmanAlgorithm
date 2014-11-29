//
//  NodeComparator.cpp
//  HuffmanCodingAlgorithm
//
//  Created by Michal Moskala on 29/11/14.
//  Copyright (c) 2014 Michal Moskala. All rights reserved.
//

#include "NodeComparator.h"

bool NodeComparator::operator()(Node *firstNode, Node *secondNode) {
	return (firstNode->value) > (secondNode->value);
}