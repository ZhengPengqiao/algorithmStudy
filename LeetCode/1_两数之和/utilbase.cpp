#include "utilbase.h"

UtilBase::UtilBase()
{

}

/**
 * @brief utilbase::showVector
 * 向量内容打印格式，[num1,num2,num3]
 * @param tag:打印出变量的标记信息
 * @param nums:需要打印的向量变量
 * @return: 0:OK other:Error
 */
int UtilBase::showVector(string tag, vector<int>& nums)
{
    unsigned long length =  nums.size();
    cout << tag << "=[";
    for(unsigned long i = 0; i < length-1; i++)
    {
        cout << nums[i] << ",";
    }

    if( length > 0 )
    {
        cout << nums[length-1];
    }
    cout << "]" << endl;

    return 0;
}
