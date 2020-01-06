#ifndef __DU12SEM_H
#define __DU12SEM_H

#include <string>
#include <cmath>
#include <optional>
#include "literal_storage.hpp"
#include "flat_icblock.hpp"
#include "dutables.hpp"
#include "abstract_instr.hpp"
#include "gen_ainstr.hpp"

namespace mlc
{
bool checkNumber(std::string input, int &result);
int divideBignum(std::vector<int> &bignum, bool &overflow);

struct exprConst
{
	mlc::icblock_pointer code;
	mlc::type_category lastType;
};

struct argsCode
{
	mlc::icblock_pointer code;
	std::vector<mlc::icblock_pointer> argCodes;
	std::vector<mlc::type_category> argTypes;
};

int totalArrayDimension(mlc::type_pointer arrType);

void store_variable(mlc::icblock_pointer block, mlc::typed_symbol_pointer tsp);
void load_variable(mlc::icblock_pointer block, mlc::typed_symbol_pointer tsp);
void ref_variable(mlc::icblock_pointer block, mlc::typed_symbol_pointer tsp);
void load_array(mlc::MlaskalCtx *ctx, mlc::icblock_pointer block, mlc::icblock_pointer src, mlc::type_pointer arrType);
void store_array(mlc::MlaskalCtx *ctx, mlc::icblock_pointer block, int arrLine, mlc::type_pointer arrType, mlc::exprConst &arr, mlc::exprConst &expr);
} // namespace mlc

#endif