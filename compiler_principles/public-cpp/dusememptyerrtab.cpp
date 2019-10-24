/*

	DUSEMEMPTYERRTAB.CPP

	JY

	Empty semantic error table

*/

#include "duerr.hpp"

using namespace mlaskal;
using namespace mlc;

namespace {

	struct errs base_errors_int_[] = {
		{ DUERR_OK,								DUERRT_VOID,			"Everything is OK" },
		{ DUERR_NOK,								DUERRT_I,			"Everything is nearly OK, although there were %d warnings" },
		{ DUERR_ERRS,								DUERRT_II,			"There were some errors %d and warnings %d" },
		{ DUERR_INTOUTRANGE,						DUERRT_S,			"Integer number '%s' is out of range, will be truncated" },
		{ DUERR_REALOUTRANGE,						DUERRT_S,			"Real number '%s' is out of range, will be truncated" },
		{ DUERR_UNKCHAR,						DUERRT_CI,			"Unknown character '%c'(%#02x) on the input" },
		{ DUERR_EOFINCMT,						DUERRT_VOID,			"EOF in comment" },
		{ DUERR_EOLINSTRCHR,						DUERRT_VOID,			"EOL in string" },
		{ DUERR_EOFINSTRCHR,						DUERRT_VOID,			"EOF in string" },
		{ DUERR_UNEXPENDCMT,						DUERRT_VOID,			"Unexpected end of comment" },
		{ DUERR_BADINT,								DUERRT_S,			"Integer number '%s' is malformed" },
		{ DUERR_BADREAL,						DUERRT_S,			"Real number '%s' is malformed" },
		{ DUERR_SYNTAX,								DUERRT_S,			"Encountered %s" },
		{ DUERR_NOINFILE,						DUERRT_S,			"Unable to open input file '%s'" },
		{ DUERR_NOOUTFILE,						DUERRT_S,			"Unable to open output file '%s'" },
		{ DUERR_DUPSYM,								DUERRT_S,			"Duplicated symbol '%s'" },
		{ DUERR_DUPLABEL,						DUERRT_I,			"Duplicated label '%d' declaration" },
		{ DUERR_DUPLABELDEF,						DUERRT_I,			"Duplicated label '%d' definition" },
		{ DUERR_MISLABELDEF,						DUERRT_I,			"Missing label '%d' definition" },
		{ DUERR_NOLABELUSE,						DUERRT_I,			"Label '%d' declared but never used" },
		{ DUERR_NOLABELGOTO,						DUERRT_I,			"Label '%d' defined but never used" },
		{ DUERR_CONVERSION,						DUERRT_VOID,			"Conversion loses significancy" },
		{ DUERR_CANNOTCONVERT,						DUERRT_VOID,			"Incompatible operand" },
		{ DUERR_FORNOTLOCAL,						DUERRT_S,			"Control variable '%s' must be local" },
		{ DUERR_FORNOTINTEGER,						DUERRT_S,			"Control variable '%s' must be of type integer" },
		{ DUERR_NOTMINE,						DUERRT_S,			"'%s' is not the current function" },
		{ DUERR_NOTLVALUE,						DUERRT_VOID,			"Left expression may not be assigned" },
		{ DUERR_NOTPARAMVAR,						DUERRT_VOID,			"Expression may not be passed by reference" },
		{ DUERR_NOTPROC,						DUERRT_S,			"'%s' is not a procedure" },
		{ DUERR_NOTARRAY,						DUERRT_S,			"'%s' is not an array" },
		{ DUERR_NOTRECORD,						DUERRT_VOID,			"Expression is not a record" },
		{ DUERR_NOTSCALAR,						DUERRT_S,			"'%s' is not a scalar type" },
		{ DUERR_PARNUM,								DUERRT_S,			"Wrong number of parameters in call to '%s'" },
		{ DUERR_NOTVAR,								DUERRT_S,			"'%s' is not a variable, function, or constant" },
		{ DUERR_NOTFNC,								DUERRT_S,			"'%s' is not a function" },
		{ DUERR_NOTTYPE,						DUERRT_S,			"'%s' is not a type" },
		{ DUERR_TYPEMISMATCH,						DUERRT_VOID,			"Type mismatch" },
		{ DUERR_NOTORDINAL,						DUERRT_VOID,			"Not an ordinal type" },
		{ DUERR_NOTLABEL,						DUERRT_I,			"'%d' is not a label" },
		{ DUERR_NOTCONST,						DUERRT_S,			"'%s' is not a constant" },
		{ DUERR_NOTINTEGRAL,						DUERRT_S,			"'%s' is not integral" },
		{ DUERR_BADRANGE,						DUERRT_VOID,			"Invalid range" },
		{ DUERR_NOTFIELD,						DUERRT_S,			"No field named '%s'" },
	};

}

namespace mlc {

	carray<errs> base_errors(base_errors_int_);
}
