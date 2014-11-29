//
//  main.cpp
//  HuffmanCodingAlgorithm
//
//  Created by Michal Moskala on 29/11/14.
//  Copyright (c) 2014 Michal Moskala. All rights reserved.
//

#include <iostream>
#include <fstream>
#include "HuffmanCodingAlgorithm.h"
#include <string>

using namespace std;

int main(int argc, const char * argv[]) {
	HuffmanCodingAlgorithm *algorithm = new HuffmanCodingAlgorithm();
	string stringToEncode = "missipi";
	algorithm->encodeString(stringToEncode);
	
  return 0;
}
