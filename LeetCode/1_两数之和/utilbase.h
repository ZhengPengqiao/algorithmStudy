#ifndef UTILBASE_H
#define UTILBASE_H

#include <iostream>
#include <vector>
#include <string>

using namespace std;

class UtilBase
{
public:
    UtilBase();

public:
    static int showVector(string tag, vector<int>& nums);
};

#endif // UTILBASE_H
