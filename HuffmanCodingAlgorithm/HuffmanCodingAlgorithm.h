//
//  HuffmanCodingAlgorithm.h
//  HuffmanCodingAlgorithm
//
//  Created by Michal Moskala on 29/11/14.
//  Copyright (c) 2014 Michal Moskala. All rights reserved.
//

#ifndef __HuffmanCodingAlgorithm__HuffmanCodingAlgorithm__
#define __HuffmanCodingAlgorithm__HuffmanCodingAlgorithm__

#include <stdio.h>
#include <iostream>
#include <string>
#include <vector>
#include <map>
#include <queue>
#include "Node.h"
#include "NodeComparator.h"

using namespace std;

class HuffmanCodingAlgorithm {
private:
	string stringToEncode;
	map<char, int> charMap;
	priority_queue<Node*, vector<Node*>, NodeComparator> nodeQueue;
	map<char, string> charCodes;
	
	void countOccurencesOfCharacters();
	void printCharMap();
	void buildTree();
	void createNodeQueue();
	void calculateComputedCodes(Node* head, string str);
	void printComputedCodes();
	void saveCoding();
	
public:
	HuffmanCodingAlgorithm();
	void encodeString(string stringToEncode);
	void decodeStoredFile();
};

#endif /* defined(__HuffmanCodingAlgorithm__HuffmanCodingAlgorithm__) */
