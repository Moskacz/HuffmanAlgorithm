//
//  HuffmanCodingAlgorithm.cpp
//  HuffmanCodingAlgorithm
//
//  Created by Michal Moskala on 29/11/14.
//  Copyright (c) 2014 Michal Moskala. All rights reserved.
//

#include "HuffmanCodingAlgorithm.h"
#include <fstream>

HuffmanCodingAlgorithm::HuffmanCodingAlgorithm() {
	charMap = map<char, int>();
	nodeQueue = priority_queue<Node*, vector<Node*>, NodeComparator>();
	charCodes = map<char, string>();
}


void HuffmanCodingAlgorithm::encodeString(std::string stringToEncode) {
	this->stringToEncode = stringToEncode;
	countOccurencesOfCharacters();
	buildTree();
	saveCoding();
}

void HuffmanCodingAlgorithm::countOccurencesOfCharacters() {
	for (char& c : this->stringToEncode) {
		if (charMap.find(c) == charMap.end()) {
			charMap[c] = 1;
		} else {
			charMap[c] = charMap[c] + 1;
		}
	}
}

void HuffmanCodingAlgorithm::printCharMap() {
	for (map<char,int>::iterator it = charMap.begin(); it != charMap.end(); it++) {
		cout << it->first << " : " <<  charMap[it->first] << endl;
	}
}

void HuffmanCodingAlgorithm::printComputedCodes() {
	for (map<char, string>::iterator it = charCodes.begin(); it != charCodes.end(); it++) {
		cout << it->first << " : " << charCodes[it->first] << endl;
	}
}

void HuffmanCodingAlgorithm::buildTree() {
	createNodeQueue();
	Node* ptr1 = NULL;	Node* ptr2 = NULL;
	
	while (nodeQueue.size() > 1) {
		ptr1 = nodeQueue.top();		nodeQueue.pop();
		ptr2 = nodeQueue.top();		nodeQueue.pop();
		
		Node* node = new Node();
		node->value = ptr1->value + ptr2->value;
		node->leftChild = ptr1;
		node->rightChild = ptr2;
		nodeQueue.push(node);
	}
	
	Node* head = nodeQueue.top();	nodeQueue.pop();
	string str;
	calculateComputedCodes(head, str);
}

void HuffmanCodingAlgorithm::createNodeQueue() {
	for (map<char,int>::iterator it = charMap.begin(); it != charMap.end(); it++) {
		char key = it->first;
		int value = charMap[it->first];
		Node* node = new Node(key, value);
		nodeQueue.push(node);
	}
}

void HuffmanCodingAlgorithm::calculateComputedCodes(Node* head, string str) {
	if (head == NULL)
		return;
	
	if (head->leftChild == NULL && head->rightChild == NULL) {		
		charCodes[head->key] = str;
		return;
	}
	
	if (head->leftChild) {
		calculateComputedCodes(head->leftChild, str + "0");
	}
	if (head->rightChild) {
		calculateComputedCodes(head->rightChild, str + "1");
	}
	return;
}

void HuffmanCodingAlgorithm::saveCoding() {
	string str;
	for (char&c : stringToEncode) {
		str += charCodes[c];
	}
	ofstream encodedFile("/Users/michalmoskala/Programowanie/C++/HuffmanCodingAlgorithm/HuffmanCodingAlgorithm/encoded.txt", fstream::out | fstream::trunc);
	encodedFile << str << endl;
	encodedFile.close();
	
	ofstream mapFile("/Users/michalmoskala/Programowanie/C++/HuffmanCodingAlgorithm/HuffmanCodingAlgorithm/map.txt", fstream::out | fstream::trunc);
	for (map<char, string>::iterator it = charCodes.begin(); it != charCodes.end(); it++) {
		mapFile << it->first << ":" << charCodes[it->first] << endl;
	}
	mapFile.close();
}
