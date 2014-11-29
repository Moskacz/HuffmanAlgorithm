//
//  HuffmanDecoderAlgorithm.h
//  HuffmanCodingAlgorithm
//
//  Created by Michal Moskala on 29/11/14.
//  Copyright (c) 2014 Michal Moskala. All rights reserved.
//

#ifndef __HuffmanCodingAlgorithm__HuffmanDecoderAlgorithm__
#define __HuffmanCodingAlgorithm__HuffmanDecoderAlgorithm__

#include <stdio.h>
#include <map>
#include <string>

using namespace std;

class HuffmanDecoderAlgorithm {
private:
	map<string, char> charCodes;
public:
	HuffmanDecoderAlgorithm();
	void decodeStoredFile();
};

#endif /* defined(__HuffmanCodingAlgorithm__HuffmanDecoderAlgorithm__) */
