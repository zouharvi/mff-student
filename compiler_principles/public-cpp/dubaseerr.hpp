/*

	DUBASEERR.H

	JY

	Error definition for DU6

*/

#ifndef DUBASEERR_H_
#define DUBASEERR_H_

namespace mlc {

	enum err_code {
		DUERR_OK,									/* everything is OK */
		DUERR_NOK,									/* nearly OK */
		DUERR_ERRS,									/* there were some errors */

		DUERR_WARNING=1000,
		DUERR_INTOUTRANGE,							/* integer number is out of range */
		DUERR_REALOUTRANGE,							/* real number is out of range */
		DUERR_CONVERSION,							/**< conversion of real to integer */
		DUERR_NOLABELUSE,							/**< label declared but never used */
		DUERR_NOLABELGOTO,							/**< label declared but never jumped */

		DUERR_SEMWARN=2000,

		DUERR_ERROR=5000,
		DUERR_UNKCHAR,									/* unknown character on the input */
		DUERR_EOFINCMT,									/* EOF in comment */
		DUERR_EOLINSTRCHR,							/* EOL in string or char */
		DUERR_EOFINSTRCHR,							/* EOF in string or char */
		DUERR_UNEXPENDCMT,							/* unexpected end of comment */
		DUERR_BADINT,									/* malformed integer number */
		DUERR_BADREAL,									/* malformed real number */
		DUERR_SYNTAX,									/* syntax error */

		DUERR_SEMERROR=6000,							/* start of semantic errors */
		DUERR_DUPSYM,										/**< symbol \%s already declared (in the same scope) */
		DUERR_DUPLABEL,									/**< label \%d already declared (in the same scope) */
		DUERR_NOTTYPE,									/**< symbol \%d does not denote a type */
		DUERR_NOTORDINAL,							/**< type is not a range */
		DUERR_NOTLABEL,									/**< label \%d is not declared */
		DUERR_NOTMINE,									/**< assigning return value to another function \%s */
		DUERR_NOTLVALUE,							/**< not an l-value on the left of := */
		DUERR_NOTPARAMVAR,							/**< actual of a parameter passed by reference is not an object */
		DUERR_TYPEMISMATCH,							/**< type mismatch in a parameter passed by reference */
		DUERR_NOTPROC,									/**< calling non-procedure symbol \%s */
		DUERR_NOTARRAY,									/**< subscript operator applied to non-array symbol \%s */
		DUERR_NOTRECORD,							/**< dot operator applied to non-record */
		DUERR_NOTSCALAR,							/**< function return type \%s is not a scalar */
		DUERR_PARNUM,									/**< wrong number of actual parameters in call to \%s */
		DUERR_NOTVAR,									/**< symbol \%s is not a variable, constant or function */
		DUERR_NOTFNC,									/**< symbol \%s is not a function */
		DUERR_NOTCONST,									/**< symbol \%s is not a constant */
		DUERR_NOTINTEGRAL,							/**< symbol \%s is not an integral constant */
		DUERR_CANNOTCONVERT,							/**< incompatible operand, parameter or assigned value */
		DUERR_FORNOTLOCAL,							/**< for-loop control variable \%s is not a variable */
		DUERR_FORNOTINTEGER,							/**< for-loop control variable \%s is not integral */
		DUERR_BADRANGE,									/**< Invalid range definition (lower > upper) */
		DUERR_DUPLABELDEF,							/**< label defined twice */
		DUERR_MISLABELDEF,							/**< label jumped but not defined */
		DUERR_NOTFIELD,									/**< no field named \%s */
		DUERR_FATAL=10000,
		DUERR_NOINFILE,									/* unable to open input file %s */
		DUERR_NOOUTFILE									/* unable to open output file %s */
	};

}

#endif
