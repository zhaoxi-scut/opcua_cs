/**
 * @file argument.cpp
 * @author 赵曦 (535394140@qq.com)
 * @brief
 * @version 1.0
 * @date 2022-09-17
 *
 * @copyright Copyright (c) 2023, zhaoxi
 *
 */

#include "asmpro/opcua_cs/argument.hpp"

using namespace std;
using namespace ua;

Argument::Argument(string name, string description, const UA_DataType *type, UA_UInt32 size) : __size(size)
{
    UA_Argument_init(&__argument);
    __argument.name = UA_STRING(to_c(name));
    __argument.description = UA_LOCALIZEDTEXT(en_US, to_c(description));
    __argument.dataType = type->typeId;
    if (__size == 0)
    {
        __argument.valueRank = UA_VALUERANK_SCALAR;
        __argument.arrayDimensionsSize = 0;
        __argument.arrayDimensions = nullptr;
    }
    else
    {
        __argument.valueRank = 1;
        __argument.arrayDimensionsSize = 1;
        __argument.arrayDimensions = &__size;
    }
}
