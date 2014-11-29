//
//  NodeComparator.h
//  HuffmanCodingAlgorithm
//
//  Created by Michal Moskala on 29/11/14.
//  Copyright (c) 2014 Michal Moskala. All rights reserved.
//

#ifndef __HuffmanCodingAlgorithm__NodeComparator__
#define __HuffmanCodingAlgorithm__NodeComparator__

#include <stdio.h>
#include "Node.h"

class NodeComparator {
public:
	bool operator()(Node* firstNode, Node* secondNode);
};

#endif /* defined(__HuffmanCodingAlgorithm__NodeComparator__) */
