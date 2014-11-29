//
//  HuffmanDecoderAlgorithm.cpp
//  HuffmanCodingAlgorithm
//
//  Created by Michal Moskala on 29/11/14.
//  Copyright (c) 2014 Michal Moskala. All rights reserved.
//

#include "HuffmanDecoderAlgorithm.h"
#include <fstream>
#include <iostream>
#include <string>

HuffmanDecoderAlgorithm::HuffmanDecoderAlgorithm() {
	charCodes = map<string, char>();
	ifstream mapFile("/Users/michalmoskala/Programowanie/C++/HuffmanCodingAlgorithm/HuffmanCodingAlgorithm/map.txt", fstream::in);
	string line;
	while (getline(mapFile, line)) {
		char c = line.at(0);
		string key = line.substr(line.find(':')+1);
		cout << key << ":" << c << endl;
		charCodes[key] = c;
	}
	mapFile.close();
}

void HuffmanDecoderAlgorithm::decodeStoredFile() {
	ifstream encodedFile("/Users/michalmoskala/Programowanie/C++/HuffmanCodingAlgorithm/HuffmanCodingAlgorithm/encoded.txt", fstream::in);
	string tmp;
	string content;
	while (getline(encodedFile, tmp)) {
		content += tmp;
	}
	
	string decodedMessage;
	int index = 1;
	int lastKeyEndIndex = 0;
	
	while (lastKeyEndIndex < content.length()) {
		string tmp = content.substr(lastKeyEndIndex, index);
		if (charCodes.count(tmp)) {
			decodedMessage += charCodes[tmp];
			lastKeyEndIndex += index;
			index = 1;
			continue;
		}
		index++;
	}
	
	cout << "Decoded message: " << decodedMessage << endl;
}