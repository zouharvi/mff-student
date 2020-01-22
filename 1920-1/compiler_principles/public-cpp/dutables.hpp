/*

DUTABLES.H

DB

Mlaskal's semantic tables

*/

#ifndef __DUTABLES_H
#define __DUTABLES_H

#include "common_types.hpp"
#include "literal_storage.hpp"
#include "flat_icblock.hpp"
#include "labeled_icblock.hpp"
#include "uid_gen.hpp"
#include "duerr.hpp"

#include <vector>
#include <map>
#include <limits>
#include <memory>

namespace mlc {


	// literal storages

	/// integer literal storage type
	typedef mlaskal::lit_storage<int, false> ls_int_type;
	/// real literal storage type
	typedef mlaskal::lit_storage<double, false> ls_real_type;
	/// string literal storage type
	typedef mlaskal::lit_storage<std::string, false> ls_str_type;
	/// identifier storage type
	typedef mlaskal::lit_storage<std::string, true> ls_id_type;

	/*************************************************************************/

	/// stack offset type
	/** this type is used to store addresses of global and local variables **/
	typedef mlaskal::ICRELNUM stack_address;

	/// integer literal index
	typedef ls_int_type::const_pointer ls_int_index;
	/// real literal index
	typedef ls_real_type::const_pointer ls_real_index;
	/// string literal index
	typedef ls_str_type::const_pointer ls_str_index;
	/// identifier index
	typedef ls_id_type::const_pointer ls_id_index;

	/*************************************************************************/

	/// intermediate code label
	typedef mlaskal::labeled_icblock::label_type ic_label;
	/// intermediate code block
	typedef std::shared_ptr< mlaskal::labeled_icblock> icblock_pointer;

	/// creates empty icblock
	inline icblock_pointer icblock_create()
	{
			return std::make_shared< mlaskal::labeled_icblock>();
	}

	/// merge any number of icblocks
	/** source icblocks are emptied **/
	template< typename ... L>
	inline icblock_pointer icblock_merge_and_kill(const L & ... icbl)
	{
		icblock_pointer dicb = std::make_shared< mlaskal::labeled_icblock>();
		dicb->append_and_kill( icbl ...);
		return std::move(dicb);
	}

	/// intermediate code label
	typedef mlaskal::abstract_functions::iterator ic_function_pointer;

	/*************************************************************************/

	class symbol_tables;

	/* symbol entries */

	/// function or procedure parameter modes
	enum parameter_mode {
		PMODE_UNDEF,
		PMODE_BY_VALUE,
		PMODE_BY_REFERENCE
	};

	/*************************************************************************/

	class abstract_type;
	/// pointer to representation of a type 
	typedef mlaskal::dumb_pointer< abstract_type> type_pointer;

	/*************************************************************************/

	class type_entry;
	/// \internal vector of type entries
	typedef std::list< type_entry> type_vector;

	/*************************************************************************/

	/// category of a type
	enum type_category {
		TCAT_UNDEF,
		TCAT_ARRAY,
		TCAT_RECORD,
		TCAT_BOOL,
		TCAT_RANGE,
		TCAT_INT,
		TCAT_REAL,
		TCAT_STR
	};

	/// \internal type_category dumper
	std::ostream &operator<<(std::ostream &os, type_category typecat);

	class array_type;
	class record_type;
	class int_type;
	class range_type;
	class bool_type;
	class real_type;
	class str_type;

	/// pointer to an array_type entry
	typedef mlaskal::dumb_pointer< array_type> array_type_pointer;
	/// pointer to a record_type entry
	typedef mlaskal::dumb_pointer< record_type> record_type_pointer;
	/// pointer to an int_type entry
	typedef mlaskal::dumb_pointer< int_type> int_type_pointer;
	/// pointer to an range_type entry
	typedef mlaskal::dumb_pointer< range_type> range_type_pointer;
	/// pointer to an bool_type entry
	typedef mlaskal::dumb_pointer< bool_type> bool_type_pointer;
	/// pointer to an real_type entry
	typedef mlaskal::dumb_pointer< real_type> real_type_pointer;
	/// pointer to an str_type entry
	typedef mlaskal::dumb_pointer< str_type> str_type_pointer;

	class DumpUniquizer;

	/// abstract entry for a type
	class abstract_type {
	public:
		/// \internal
		virtual ~abstract_type() {}
		/// returns the category of the type
		type_category cat() const { return this ? cat_() : TCAT_UNDEF; }
		/// accesses array_type entry if applicable
		array_type_pointer access_array() { return this ? arrayType_() : array_type_pointer(); }
		/// accesses record_type entry if applicable
		record_type_pointer access_record() { return this ? recordType_() : record_type_pointer(); }
		/// accesses int_type entry if applicable
		int_type_pointer access_int() { return this ? integerType_() : int_type_pointer(); }
		/// accesses range_type entry if applicable
		range_type_pointer access_range() { return this ? rangeType_() : range_type_pointer(); }
		/// accesses bool_type entry if applicable
		bool_type_pointer access_bool() { return this ? booleanType_() : bool_type_pointer(); }
		/// accesses real_type entry if applicable
		real_type_pointer access_real() { return this ? realType_() : real_type_pointer(); }
		/// accesses str_type entry if applicable
		str_type_pointer access_str() { return this ? stringType_() : str_type_pointer(); }
		/// compute the size of the type
		/** the size is returned in stack units **/
		stack_address compute_size() { return this ? compute_size_() : 0; }
		/// compute intermediate code physical type 
		/** returns the innermost element type for arrays

			returns integer for range types
		**/
		mlaskal::physical_type compute_final_ptype() { return this ? compute_final_ptype_() : mlaskal::PTYPE_UNDEF; }
	private:
		size_t get_idx() const { return this ? get_idx_() : std::numeric_limits< size_t>::max(); }
		virtual type_category cat_() const = 0;
		virtual array_type_pointer arrayType_() = 0;
		virtual record_type_pointer recordType_() = 0;
		virtual int_type_pointer integerType_() = 0;
		virtual range_type_pointer rangeType_() = 0;
		virtual bool_type_pointer booleanType_() = 0;
		virtual real_type_pointer realType_() = 0;
		virtual str_type_pointer stringType_() = 0;
		virtual stack_address compute_size_() = 0;
		virtual mlaskal::physical_type compute_final_ptype_() = 0;
		virtual size_t get_idx_() const = 0;
		virtual const type_entry * access_entry() const = 0;
		friend std::ostream & operator<<( std::ostream & o, type_pointer e);
		friend bool identical_type( type_pointer a, type_pointer b);
		friend class DumpUniquizer;
		friend class type_entry;
	};

	/// entry for an (one-dimensional) array type
	class array_type : public virtual abstract_type {
	public:
		virtual ~array_type() {}
		/// type of the array element
		type_pointer element_type() const { return this ? elementType_() : type_pointer(); }
		/// type of the index
		type_pointer index_type() const { return this ? indexType_() : type_pointer(); }
	private:
		virtual type_pointer elementType_() const = 0;
		virtual type_pointer indexType_() const = 0;
	};

	class field_entry;

	/// pointer to an field_entry
	typedef mlaskal::dumb_pointer< const field_entry> field_pointer;

	/// \internal parameter entry vector
	typedef std::vector< field_entry> field_vector;

	/// entry for a record type
	class record_type : public virtual abstract_type {
	public:
		virtual ~record_type() {}

		field_pointer find( ls_id_index idx) const { return this ? record_find_( idx) : field_pointer(); }

		/// iterator type
		typedef field_vector::const_iterator const_iterator;
		/// first element
		const_iterator begin() const { return record_begin_(); }
		/// behind-the-last element
		const_iterator end() const { return record_end_(); }

	private:
		virtual field_pointer record_find_( ls_id_index idx) const = 0;
		virtual field_vector::const_iterator record_begin_() const = 0;
		virtual field_vector::const_iterator record_end_() const = 0;
	};

	/// common base for integer and range type entries
	class integral_type : public virtual abstract_type {
	public:
		virtual ~integral_type() {}
	};

	/// entry for the 'integer' type (singleton)
	class int_type : public virtual integral_type {
	public:
		virtual ~int_type() {}
	};

	/// entry for a range type
	class range_type : public virtual integral_type {
	public:
		virtual ~range_type() {}
		// lower bound (inclusive)
		ls_int_index lowerBound() const { return this ? lowerBound_() : ls_int_index(); }
		// upper bound (inclusive)
		ls_int_index upperBound() const { return this ? upperBound_() : ls_int_index(); }
	private:
		virtual ls_int_index lowerBound_() const = 0;
		virtual ls_int_index upperBound_() const = 0;
	};

	/// entry for the 'boolean' type (singleton)
	class bool_type : public virtual abstract_type {
	public:
		virtual ~bool_type() {}
	};

	/// entry for the 'real' type (singleton)
	class real_type : public virtual abstract_type {
	public:
		virtual ~real_type() {}
	};

	/// entry for the 'string' type (singleton)
	class str_type : public virtual abstract_type {
	public:
		virtual ~str_type() {}
	};

	class field_list_body;

	/// parameter list - owner pointer
	typedef std::shared_ptr< field_list_body> field_list_ptr;
	/// parameter list - read-only observer pointer
	typedef mlaskal::dumb_pointer< const field_list_body> field_list_const_ptr;

	/// \internal ordering functor on literal table indexes
	template< typename T, bool ISID>
	class ls_index_comparator {
	public:
		bool operator() ( 
			typename mlaskal::lit_storage< T, ISID>::const_pointer a, 
			typename mlaskal::lit_storage< T, ISID>::const_pointer b) const
		{
			return * a < * b;
		}
	};

	/// \internal record field index
	typedef std::map< ls_id_index, const field_entry *, ls_index_comparator< std::string, true> > record_cache_type;

	/// \internal implementation of a type entry
	class type_entry :
		public virtual array_type,
		public virtual record_type,
		public virtual int_type,
		public virtual range_type,
		public virtual bool_type,
		public virtual real_type,
		public virtual str_type
	{
	private:
		type_entry();
		type_entry( size_t idx, type_category p);
		type_entry( size_t idx, type_category p, field_list_ptr fldlist);
		type_entry( size_t idx, type_category p, type_pointer t1, type_pointer t2);
		type_entry( size_t idx, type_category p, type_pointer t1, type_pointer t2, ls_int_index s1, ls_int_index s2);
		size_t idx_;
		type_category typecat;
		type_pointer ltype1;
		type_pointer ltype2;
		ls_int_index idx1;
		ls_int_index idx2;
		field_list_ptr fldlist;
		record_cache_type record_cache;

		virtual type_category cat_() const;
		virtual array_type_pointer arrayType_();
		virtual record_type_pointer recordType_();
		virtual int_type_pointer integerType_();
		virtual range_type_pointer rangeType_();
		virtual bool_type_pointer booleanType_();
		virtual real_type_pointer realType_();
		virtual str_type_pointer stringType_();
		virtual type_pointer elementType_() const;
		virtual type_pointer indexType_() const;
		virtual ls_int_index lowerBound_() const;
		virtual ls_int_index upperBound_() const;
		virtual size_t get_idx_() const;
		virtual const type_entry * access_entry() const;
		virtual stack_address compute_size_();
		virtual mlaskal::physical_type compute_final_ptype_();
		virtual field_pointer record_find_( ls_id_index idx) const;
		virtual field_vector::const_iterator record_begin_() const;
		virtual field_vector::const_iterator record_end_() const;
		virtual void fill_record_cache( int line);

		friend class symbol_tables;
		friend class DumpUniquizer;
		template< typename M>
		std::string operator()( std::string & name, std::ostream & oo, DumpUniquizer & uniq, M mode) const;
		template< typename T> friend struct mlaskal::object_traits;
		friend std::ostream & operator<<( std::ostream & o, const type_entry & e);
	};

	/// \internal type_entry dumper
	std::ostream & operator<<( std::ostream & o, const type_entry & e);

	/*************************************************************************/

	/// record field
	/** represents a field '\p idx : \p ltype'
	**/
	class field_entry {
	public:
		type_pointer type() const
		{
			return this ? ltype : type_pointer();
		}
		stack_address offset() const
		{
			return this ? offset_ : 0;
		}
	private:
		field_entry()	// creates a dummy object
			: idx(nullptr), ltype(), offset_(0)
		{}
		/// constructor
		field_entry( ls_id_index i, type_pointer p);
		/// identifier index
		ls_id_index idx;
		/// type
		type_pointer ltype;
		/// offset
		stack_address offset_;

		template< typename M>
		std::string operator()( std::ostream & oo, DumpUniquizer & uniq, M mode) const;

		friend class type_entry;
		friend class field_list_body;
		friend struct flftr;
		template< typename T> friend struct mlaskal::object_traits;

		friend std::ostream & operator<<( std::ostream & o, const field_entry & e);
	};

	/// \internal parameter entry dumper
	std::ostream & operator<<( std::ostream & o, const field_entry & e);

	/// \internal parameter entry vector
	typedef std::vector< field_entry> field_vector;

	/// list of record fields
	class field_list_body {
	public:
		/// iterator type
		typedef field_vector::const_iterator const_iterator;
		/// first element
		const_iterator begin() const;
		/// behind-the-last element
		const_iterator end() const;
		/// appends a field
		void append_field( ls_id_index idx, type_pointer ltype);
		/// appends another list of fields
		/** kills the list \p ll2 **/
		void append_and_kill( const field_list_ptr & ll2);

		/// number of field entries
		field_vector::size_type size() const;

	private:
		void push_back( const field_entry & v);
		void append( field_list_body && l2);
		void assign_offsets();
		std::string operator()( std::ostream & oo, DumpUniquizer & uniq) const;

		field_vector v_;
		stack_address total_size_;
		friend std::ostream & operator<<( std::ostream & o, const field_list_body & e);
		friend class symbol_tables;
		friend class type_entry;
	};

	/*************************************************************************/

	/// function or procedure parameter entry
	/** represents a parameter '\p idx : \p ltype'

		'var' parameters are distinguished by \p partype
	**/
	struct parameter_entry {
		/// constructor
		parameter_entry( parameter_mode s, ls_id_index i, type_pointer p);
		/// by-value or by-reference ('var') parameter
		parameter_mode partype;
		/// identifier index
		ls_id_index idx;
		/// type
		type_pointer ltype;

		template< typename M>
		std::string operator()( std::ostream & oo, DumpUniquizer & uniq, M mode) const;
	};

	/// \internal parameter entry dumper
	std::ostream & operator<<( std::ostream & o, const parameter_entry & e);

	/// \internal parameter entry vector
	typedef std::vector< parameter_entry> parameter_vector;

	class symbol_entry;

	class parameter_list_body;

	/// parameter list - owner pointer
	typedef std::shared_ptr< parameter_list_body> parameter_list_ptr;	
	/// parameter list - read-only observer pointer
	typedef mlaskal::dumb_pointer< const parameter_list_body> parameter_list_const_ptr;

	/// list of function or procedure parameters
	class parameter_list_body {
	public:
		/// iterator type
		typedef parameter_vector::const_iterator const_iterator;
		/// first element
		const_iterator begin() const;
		/// behind-the-last element
		const_iterator end() const;
		/// appends a parameter passed by value
		void append_parameter_by_value( ls_id_index idx, type_pointer ltype);
		/// appends a parameter passed by reference
		void append_parameter_by_reference( ls_id_index idx, type_pointer ltype);
		/// appends another list of parameters
		/** kills the list \p ll2 **/
		void append_and_kill( const parameter_list_ptr & ll2);

		/// number of parameter entries
		parameter_vector::size_type size() const;

	private:
		void push_back( const parameter_entry & v);
		void append( parameter_list_body && l2);
		template< typename M>
		std::string operator()( std::ostream & oo, DumpUniquizer & uniq, M mode) const;

		parameter_vector v_;
		friend std::ostream & operator<<( std::ostream & o, const parameter_list_body & e);
		friend class symbol_entry;
	};

	/// \internal parameter list dumper
	std::ostream & operator<<( std::ostream & o, const parameter_list_body & e);

	/*************************************************************************/

	/// symbol kind
	enum symbol_kind { 
		SKIND_UNDEF,
		SKIND_PROCEDURE,
		SKIND_FUNCTION,
		SKIND_GLOBAL_VARIABLE,
		SKIND_LOCAL_VARIABLE,
		SKIND_PARAMETER_BY_REFERENCE,
		SKIND_TYPE,
		SKIND_CONST
	};

	class typed_symbol;
	class variable_symbol;
	class subprogram_symbol;
	class procedure_symbol;
	class function_symbol;
	class global_variable_symbol;
	class local_variable_symbol;
	class parameter_by_reference_symbol;
	class type_symbol;
	class const_symbol;

	/// pointer to typed_symbol entry
	typedef mlaskal::dumb_pointer< typed_symbol> typed_symbol_pointer;
	/// pointer to variable_symbol entry
	typedef mlaskal::dumb_pointer< variable_symbol> variable_symbol_pointer;
	/// pointer to subprogram_symbol entry
	typedef mlaskal::dumb_pointer< subprogram_symbol> subprogram_symbol_pointer;
	/// pointer to procedure_symbol entry
	typedef mlaskal::dumb_pointer< procedure_symbol> procedure_symbol_pointer;
	/// pointer to function_symbol entry
	typedef mlaskal::dumb_pointer< function_symbol> function_symbol_pointer;
	/// pointer to global_variable_symbol entry
	typedef mlaskal::dumb_pointer< global_variable_symbol> global_variable_symbol_pointer;
	/// pointer to local_variable_symbol entry
	typedef mlaskal::dumb_pointer< local_variable_symbol> local_variable_symbol_pointer;
	/// pointer to parameter_by_reference_symbol entry
	typedef mlaskal::dumb_pointer< parameter_by_reference_symbol> parameter_by_reference_symbol_pointer;
	/// pointer to type_symbol entry
	typedef mlaskal::dumb_pointer< type_symbol> type_symbol_reference;
	/// pointer to const_symbol entry
	typedef mlaskal::dumb_pointer< const_symbol> const_symbol_reference;

	/// abstract symbol representation
	class abstract_symbol
	{
	public:
		virtual ~abstract_symbol() {}
		/// returns the kind of the symbol
		symbol_kind kind() const { return this ? kind_() : SKIND_UNDEF; }
		/// accesses typed_symbol entry if applicable
		typed_symbol_pointer access_typed() { return this ? typedSymbol_() : typed_symbol_pointer(); }
		/// accesses variable_symbol entry if applicable
		variable_symbol_pointer access_variable() { return this ? variableSymbol_() : variable_symbol_pointer(); }
		/// accesses subprogram_symbol entry if applicable
		subprogram_symbol_pointer access_subprogram() { return this ? subprogramSymbol_() : subprogram_symbol_pointer(); }
		/// accesses procedure_symbol entry if applicable
		procedure_symbol_pointer access_procedure() { return this ? procSymbol_() : procedure_symbol_pointer(); }
		/// accesses function_symbol entry if applicable
		function_symbol_pointer access_function() { return this ? fncSymbol_() : function_symbol_pointer(); }
		/// accesses global_variable_symbol entry if applicable
		global_variable_symbol_pointer access_global_variable() { return this ? gVarSymbol_() : global_variable_symbol_pointer(); }
		/// accesses local_variable_symbol entry if applicable
		local_variable_symbol_pointer access_local_variable() { return this ? lVarSymbol_() : local_variable_symbol_pointer(); }
		/// accesses parameter_by_reference_symbol entry if applicable
		parameter_by_reference_symbol_pointer access_parameter_by_reference() { return this ? varParSymbol_() : parameter_by_reference_symbol_pointer(); }
		/// accesses type_symbol entry if applicable
		type_symbol_reference access_type() { return this ? typeSymbol_() : type_symbol_reference(); }
		/// accesses const_symbol entry if applicable
		const_symbol_reference access_const() { return this ? constSymbol_() : const_symbol_reference(); }
	private:
		virtual symbol_kind kind_() const = 0;
		virtual typed_symbol_pointer typedSymbol_() = 0;
		virtual variable_symbol_pointer variableSymbol_() = 0;
		virtual subprogram_symbol_pointer subprogramSymbol_() = 0;
		virtual procedure_symbol_pointer procSymbol_() = 0;
		virtual function_symbol_pointer fncSymbol_() = 0;
		virtual global_variable_symbol_pointer gVarSymbol_() = 0;
		virtual local_variable_symbol_pointer lVarSymbol_() = 0;
		virtual parameter_by_reference_symbol_pointer varParSymbol_() = 0;
		virtual type_symbol_reference typeSymbol_() = 0;
		virtual const_symbol_reference constSymbol_() = 0;
	};

	/// pointer to abstract symbol entry
	typedef mlaskal::dumb_pointer< abstract_symbol> symbol_pointer;

	/// common base of procedure and function entries
	class subprogram_symbol 
		: public virtual abstract_symbol 
	{
	public:
		virtual ~subprogram_symbol() {}
		/// list of parameters
		parameter_list_const_ptr parameters() const { return this ? parList_() : parameter_list_const_ptr(); }
		/// intermediate code representation
		ic_function_pointer code() const { return this ? label_() : ic_function_pointer(); }
	private:
		virtual parameter_list_const_ptr parList_() const = 0;
		virtual ic_function_pointer label_() const = 0;
	};

	/// common base of all symbol entries that have a type
	class typed_symbol 
		: public virtual abstract_symbol 
	{
	public:
		virtual ~typed_symbol() {}
		/// the type of the symbol
		type_pointer type() const { return this ? type_() : type_pointer(); }
	private:
		virtual type_pointer type_() const = 0;
	};

	/// representation of a procedure
	class procedure_symbol 
		: public virtual subprogram_symbol 
	{
	public:
		virtual ~procedure_symbol() {}
	};

	/// representation of a function
	class function_symbol 
		: public virtual subprogram_symbol,
		public virtual typed_symbol
	{
	public:
		virtual ~function_symbol() {}
	};

	/// common base of all variable representations
	class variable_symbol 
		: public virtual typed_symbol
	{
	public:
		virtual ~variable_symbol() {}
		/// address of the variable in intermediate code stack units
		virtual stack_address address() const { return this ? varOffset_() : 0; }
	private:
		virtual stack_address varOffset_() const = 0;
	};

	/// global variable representation
	class global_variable_symbol 
		: public virtual variable_symbol
	{
	public:
		virtual ~global_variable_symbol() {}
	};

	/// local variable representation
	/** also used for parameters passed by value **/
	class local_variable_symbol 
		: public virtual variable_symbol
	{
	public:
		virtual ~local_variable_symbol() {}
	};

	/// representation of a parameter passed by reference ('var')
	class parameter_by_reference_symbol 
		: public virtual variable_symbol
	{
	public:
		virtual ~parameter_by_reference_symbol() {}
	};

	/// representation of a named type
	class type_symbol 
		: public virtual typed_symbol
	{
	public:
		virtual ~type_symbol() {}
	};

	class bool_const_symbol;
	class int_const_symbol;
	class real_const_symbol;
	class str_const_symbol;

	/// pointer to a representation of a named boolean constant
	typedef mlaskal::dumb_pointer< bool_const_symbol> bool_const_symbol_pointer;
	/// pointer to a representation of a named integer constant
	typedef mlaskal::dumb_pointer< int_const_symbol> int_const_symbol_pointer;
	/// pointer to a representation of a named real constant
	typedef mlaskal::dumb_pointer< real_const_symbol> real_const_symbol_pointer;
	/// pointer to a representation of a named string constant
	typedef mlaskal::dumb_pointer< str_const_symbol> str_const_symbol_pointer;

	/// common base of all named constant representations
	class const_symbol 
		: public virtual typed_symbol
	{
	public:
		virtual ~const_symbol() {}

		/// accesses bool_const_symbol entry if applicable
		bool_const_symbol_pointer access_bool_const() { return this ? boolConstSymbol_() : bool_const_symbol_pointer(); }
		/// accesses int_const_symbol entry if applicable
		int_const_symbol_pointer access_int_const() { return this ? integerConstSymbol_() : int_const_symbol_pointer(); }
		/// accesses real_const_symbol entry if applicable
		real_const_symbol_pointer access_real_const() { return this ? realConstSymbol_() : real_const_symbol_pointer(); }
		/// accesses str_const_symbol entry if applicable
		str_const_symbol_pointer access_str_const() { return this ? stringConstSymbol_() : str_const_symbol_pointer(); }
	private:
		virtual bool_const_symbol_pointer boolConstSymbol_() = 0;
		virtual int_const_symbol_pointer integerConstSymbol_() = 0;
		virtual real_const_symbol_pointer realConstSymbol_() = 0;
		virtual str_const_symbol_pointer stringConstSymbol_() = 0;
	};

	/// representation of a named boolean constant
	/** created automatically during initialization for 'false' and 'true' **/
	class bool_const_symbol 
		: public virtual const_symbol
	{
	public:
		virtual ~bool_const_symbol() {}
		bool bool_value() const { return this ? boolValue_() : false; }
	private:
		virtual bool boolValue_() const = 0;
	};

	/// representation of a named integer constant
	class int_const_symbol 
		: public virtual const_symbol
	{
	public:
		virtual ~int_const_symbol() {}
		ls_int_index int_value() const { return this ? integerValue_() : ls_int_index(); }
	private:
		virtual ls_int_index integerValue_() const = 0;
	};

	/// representation of a named real constant
	class real_const_symbol 
		: public virtual const_symbol
	{
	public:
		virtual ~real_const_symbol() {}
		ls_real_index real_value() const { return this ? realValue_() : ls_real_index(); }
	private:
		virtual ls_real_index realValue_() const = 0;
	};

	/// representation of a named string constant
	class str_const_symbol 
		: public virtual const_symbol
	{
	public:
		virtual ~str_const_symbol() {}
		ls_str_index str_value() const { return this ? stringValue_() : ls_str_index(); }
	private:
		virtual ls_str_index stringValue_() const = 0;
	};

	/*************************************************************************/

	class local_symbol_tables;
	class symbol_entry;
	class label_entry;

	/// \internal symbol map
	typedef std::map< ls_id_index, symbol_entry, ls_index_comparator< std::string, true> > symbol_map;
	/// \internal label map
	typedef std::map< ls_int_index, label_entry, ls_index_comparator< int, false> > label_map;

	void final_messsage_symbol(const symbol_map::value_type & e);
	void kill_symbol(symbol_map::value_type & e);

	/// \internal implementation of a symbol
	class symbol_entry
		: public virtual procedure_symbol,
		public virtual function_symbol,
		public virtual global_variable_symbol,
		public virtual local_variable_symbol,
		public virtual parameter_by_reference_symbol,
		public virtual type_symbol,
		public virtual bool_const_symbol,
		public virtual int_const_symbol,
		public virtual real_const_symbol,
		public virtual str_const_symbol
	{
	public:
		void final_message() const;
		void kill();

	private:
		symbol_entry()	// creates a dummy symbol
			: symtype(SKIND_UNDEF), value(false), relnum_(0), ltype(), parlist(), magic(), epilogue_(), local_tables_(nullptr)
		{
		}
		symbol_entry( symbol_kind s, stack_address i, type_pointer p, const ic_function_pointer & m, std::unique_ptr< local_symbol_tables> && lt)
			: symtype( s), value( false), relnum_( i), ltype( p), parlist( nullptr), magic( m), epilogue_( icblock_create()), local_tables_( std::move( lt))
		{
		}
		symbol_entry( symbol_kind s, stack_address i, type_pointer p, ic_label bl, ic_label el)
			: symtype( s), value( false), relnum_( i), ltype( p), parlist( nullptr), magic(), epilogue_( 0), local_tables_( nullptr),
			icip_begin_label( bl), icip_end_label( el)
		{
		}
		symbol_entry( symbol_kind s, type_pointer p)
			: symtype( s), value( false), relnum_( -1), ltype( p), parlist(nullptr), magic(), epilogue_( 0), local_tables_(nullptr)
		{
		}
		symbol_entry( symbol_kind s, bool i, type_pointer p)
			: symtype( s), value( i), relnum_( -1), ltype( p), parlist(nullptr), magic(), epilogue_( 0), local_tables_(nullptr)
		{
		}
		symbol_entry( symbol_kind s, ls_int_index i, type_pointer p)
			: symtype( s), value( false), intidx( i), relnum_( -1), ltype( p), parlist(nullptr), magic(), epilogue_( 0), local_tables_(nullptr)
		{
		}
		symbol_entry( symbol_kind s, ls_real_index i, type_pointer p)
			: symtype( s), value( false), realidx( i), relnum_( -1), ltype( p), parlist(nullptr), magic(), epilogue_( 0), local_tables_(nullptr)
		{
		}
		symbol_entry( symbol_kind s, ls_str_index i, type_pointer p)
			: symtype( s), value( false), stridx( i), relnum_( -1), ltype( p), parlist(nullptr), magic(), epilogue_( 0), local_tables_(nullptr)
		{
		}
		symbol_kind symtype;
		bool value;
		ls_int_index intidx;
		ls_real_index realidx;
		ls_str_index stridx;
		stack_address relnum_;
		type_pointer ltype;
		parameter_list_ptr parlist;
		ic_function_pointer magic;
		mlaskal::abstract_function_vars local_vars_;
		icblock_pointer epilogue_;
		std::unique_ptr< local_symbol_tables> local_tables_;
		ic_label icip_begin_label;
		ic_label icip_end_label;
		virtual symbol_kind kind_() const;
		virtual typed_symbol_pointer typedSymbol_();
		virtual variable_symbol_pointer variableSymbol_();
		virtual subprogram_symbol_pointer subprogramSymbol_();
		virtual procedure_symbol_pointer procSymbol_();
		virtual function_symbol_pointer fncSymbol_();
		virtual global_variable_symbol_pointer gVarSymbol_();
		virtual local_variable_symbol_pointer lVarSymbol_();
		virtual parameter_by_reference_symbol_pointer varParSymbol_();
		virtual type_symbol_reference typeSymbol_();
		virtual const_symbol_reference constSymbol_();
		virtual parameter_list_const_ptr parList_() const;
		virtual type_pointer type_() const;
		virtual stack_address varOffset_() const;
		virtual bool_const_symbol_pointer boolConstSymbol_();
		virtual int_const_symbol_pointer integerConstSymbol_();
		virtual real_const_symbol_pointer realConstSymbol_();
		virtual str_const_symbol_pointer stringConstSymbol_();
		virtual bool boolValue_() const;
		virtual ls_int_index integerValue_() const;
		virtual ls_real_index realValue_() const;
		virtual ls_str_index stringValue_() const;
		virtual ic_function_pointer label_() const;
		template< typename M>
		std::string operator()( const std::string & indent, const std::string & name, std::ostream & o, DumpUniquizer & uniq, M mode) const;

		friend void final_message_symbol(const symbol_map::value_type & e);
		friend void kill_symbol(symbol_map::value_type & e);
		friend class symbol_tables;
		friend class local_symbol_tables;
		template< typename T> friend struct mlaskal::object_traits;
		friend std::ostream & operator<<( std::ostream & o, const symbol_entry & e);
	};

	/*************************************************************************/

	/// label entry
	class label_symbol {
	public:
		virtual ~label_symbol() {}
		/// assigned intermediate code label
		virtual ic_label label() const = 0;
		/// encountered a goto statement
		virtual void goto_found( int line) = 0;
		/// encountered a label:
		virtual bool label_found( int line) = 0;
	};

	/// pointer to a label entry
	typedef mlaskal::dumb_pointer< label_symbol> label_symbol_pointer;

	/*************************************************************************/

	struct check_label;

	/// \internal implementation of label entry
	class label_entry 
		: public virtual label_symbol
	{
	private:
		label_entry()	// creates dummy object
			: id(nullptr), magic(0), have_goto(true), have_label(true), decl_line(0), goto_line(0), label_line(0) {}
		label_entry(int ln, const ls_int_index & i, const ic_label & l)
			: id(i), magic(l), have_goto(false), have_label(false), decl_line(ln), goto_line(0), label_line(0) {}
		ls_int_index id;
		ic_label magic;
		bool have_goto, have_label;
		int decl_line, goto_line, label_line;
		virtual ic_label label() const;
		virtual void goto_found( int line);
		virtual bool label_found( int line);
		void check() const;

		friend class symbol_tables;
		friend struct check_label;
		template< typename T> friend struct mlaskal::object_traits;
	};

	/*************************************************************************/

	class local_symbol_tables {
	public:
		local_symbol_tables();
		void final_message() const;
		~local_symbol_tables();
	private:
		template< typename M>
		std::string dump_locals( std::ostream & oo, DumpUniquizer & uniq, M mode) const;
		template< typename M>
		std::ostream & dump_llabel( std::ostream & o, const label_map::const_iterator & lit, std::ostream & oo, DumpUniquizer & uniq, M mode) const;
		template< typename M>
		std::ostream & dump_local( std::ostream & o, const symbol_map::const_iterator & sit, std::ostream & oo, DumpUniquizer & uniq, M mode) const;

		label_map llabels;
		symbol_map locals;
		stack_address lvarsize;
		stack_address retval_;

		friend class symbol_tables;
		friend class symbol_entry;
	};
	
	/*************************************************************************/
	
	/// all symbol tables together
	class symbol_tables {
	public:

		//ls_id_index translate_id( ls_id_index idx);

		/// integer literal storage
		ls_int_type & ls_int() { return aic_->get_ls_int(); }
		/// real literal storage
		ls_real_type & ls_real() { return aic_->get_ls_real(); }
		/// string literal storage
		ls_str_type & ls_str() { return aic_->get_ls_string(); }
		/// identifier storage
		ls_id_type & ls_id() { return aic_->get_ls_id(); }


		/// creates an array type representation 
		/** creates an array_type entry for 'array [ \p index_type ] of \p element_type' **/
		type_pointer create_array_type( type_pointer index_type, type_pointer element_type);

		/// creates a record type representation 
		/** creates a record_type entry for 'record field_list_body end' **/
		type_pointer create_record_type( field_list_ptr fldlist, int line = 0);

		/// creates a range type representation 
		/** creates a range_type entry for '\p i1 .. \p i2' **/
		type_pointer create_range_type( ls_int_index i1, ls_int_index i2);

		/// finds a label 
		/** finds a label entry identified by integer literal \p idx **/
		label_symbol_pointer find_label( ls_int_index idx);

		/// creates a variable representation
		/** creates a global_variable_symbol or local_variable_symbol entry for 'var \p idx : \p ltype' (based on symbol_tables::nested())

			\p line is a line number
		**/
		variable_symbol_pointer add_var( int line, ls_id_index idx, type_pointer ltype);

		/// creates a representation of boolean constant 
		/** creates a bool_const_symbol entry for 'const \p idx = \p val'

			\p line is a line number
		**/
		bool_const_symbol_pointer add_const_bool( int line, ls_id_index idx, bool val);

		/// creates a representation of integer constant 
		/** creates a int_const_symbol entry for 'const \p idx = \p val'

			\p line is a line number
		**/
		int_const_symbol_pointer add_const_int( int line, ls_id_index idx, ls_int_index symidx);

		/// creates a representation of real constant 
		/** creates a real_const_symbol entry for 'const \p idx = \p symidx'

			\p line is a line number
		**/
		real_const_symbol_pointer add_const_real( int line, ls_id_index idx, ls_real_index symidx);

		/// creates a representation of string constant 
		/** creates a str_const_symbol entry for 'const \p idx = \p symidx'

			\p line is a line number
		**/
		str_const_symbol_pointer add_const_str( int line, ls_id_index idx, ls_str_index symidx);

		/// creates a representation of named type 
		/** creates a type_symbol entry for 'type \p idx = \p symidx'

			\p line is a line number
		**/
		type_symbol_reference add_type( int line, ls_id_index idx, type_pointer ltype);

		/// creates a representation of label 
		/** creates a label_symbol entry for 'label \p idx'

			label is identified by an integer literal \p idx

			\p lbl should be an unique intermediate code label (created by mlc::symbol_tables::new_label())

			\p line is a line number
		**/
		label_symbol_pointer add_label_entry( int line, ls_int_index idx, ic_label lbl);

		/// creates a representation of function 
		/** creates a function_symbol entry for 'function \p idx ( \p parlist ) : \p ltype'

			\p line is a line number
		**/
		function_symbol_pointer add_fnc( int line, ls_id_index idx, type_pointer ltype, parameter_list_ptr parlist);

		/// creates a representation of procedure 
		/** creates a procedure_symbol entry for 'procedure \p idx ( \p parlist )'

			\p line is a line number
		**/
		procedure_symbol_pointer add_proc( int line, ls_id_index idx, parameter_list_ptr parlist);

		/// assign code to a function
		/** defines the code of a function/procedure named \p idx using icblock \p icb

			icblock \p icb is inserted between prologue and epilogue code (including RET)
			automatically generated from local variable declarations
		**/
		bool set_subprogram_code( ls_id_index idx, icblock_pointer icb);

		/// assign code to the main block
		/** defines the code of the main block of a program named \p idx using icblock \p icb

			icblock \p icb is inserted between prologue and epilogue code (including HALT)
			automatically generated from global variable declarations
		**/
		bool set_main_code( ls_id_index idx, icblock_pointer icb);

		/// opens a block of a procedure or function
		/** \p idx must be an identifier of a procedure or a function that already has its entry

			\li opens the block (nested() becomes true) 
			\li creates local_variable_symbol or parameter_by_reference_symbol entries for parameters (as defined by the procedure or function entry)

			\p line is a line number
		**/
		bool enter( int line, ls_id_index idx);

		/// closes a block of a procedure or function
		/** \li discards all symbol and label entries inside the block
			\li closes the block (nested() becomes false) 

			\p line is a line number
		**/
		void leave( int line);

		/// current function
		/** returns the identifier of the current function (as defined by enter())
		**/
		ls_id_index my_function_name() const;

		/// integer literal 1
		/** returns the integer literal '1'
		**/
		ls_int_index one();

		/// place for the returned value
		/** returns the stack offset of the returned value
		**/
		stack_address my_return_address();

		/// undefined type
		/** returns an abstract_type representation of undefined type
		**/
		type_pointer logical_undef();

		/// boolean type
		/** returns a BoolType representation of 'boolean' type
		**/
		type_pointer logical_bool();

		/// integer type
		/** returns an int_type representation of 'integer' type
		**/
		type_pointer logical_integer();

		/// real type
		/** returns a real_type representation of 'real' type
		**/
		type_pointer logical_real();

		/// string type
		/** returns a str_type representation of 'string' type
		**/
		type_pointer logical_string();

		/// checks enter/leave status
		/** returns true if inside a procedure or function block
		**/
		bool nested() const;

		/// finds a symbol
		/** returns an abstract_symbol representation assigned to the identifier \p symidx 

			\li if nested(), searches among local declarations
			\li if not found, searches among global declarations
			\li if not found anywhere, returns undefined (SKIND_UNDEFINED) symbol representation
		**/
		symbol_pointer find_symbol( ls_id_index symidx);

		/// generates unique intermediate code label
		ic_label new_label()
		{
			return mlaskal::uid_all.get_UID();
		}

		symbol_tables(bool debug, mlaskal::abstract_ic * aic);

		void init_builtins();

		template< typename M>
		std::ostream & dump(std::ostream & o, M mode) const;

		void final_message() const;

		~symbol_tables();

	private:
		label_map & llabels() { if ( nested_ ) return my_function_entry()->local_tables_->llabels; return glabels; }
		const label_map & llabels() const { if ( nested_ ) return my_function_entry()->local_tables_->llabels; return glabels; }
		symbol_map & locals() { if ( nested_ ) return my_function_entry()->local_tables_->locals; return globals; }
		const symbol_map & locals() const { if ( nested_ ) return my_function_entry()->local_tables_->locals; return globals; }
		stack_address & lvarsize() { if ( nested_ ) return my_function_entry()->local_tables_->lvarsize; return gvarsize; }
		const stack_address & lvarsize() const { if ( nested_ ) return my_function_entry()->local_tables_->lvarsize; return gvarsize; }
		stack_address & retval_() { return my_function_entry()->local_tables_->retval_; }
		const stack_address & retval_() const { return my_function_entry()->local_tables_->retval_; }

		const symbol_entry * my_function_entry() const;
		symbol_entry * my_function_entry();

		type_vector types;
		label_map glabels;
		symbol_map globals;
		bool nested_;
		stack_address gvarsize;
		ls_id_index myfncname_;
		ls_int_index one_;
		type_pointer bool_;
		type_pointer integer_;
		type_pointer real_;
		type_pointer string_;
		type_pointer undef_;
		bool debug_;
		mlaskal::abstract_ic * aic_;
		mlaskal::abstract_function_vars global_vars_;
		std::shared_ptr< mlaskal::labeled_icblock> global_block_;
		icblock_pointer global_epilogue_;
		
		type_pointer create_atomic_type( type_category ptype);

		ic_function_pointer my_function_code();

		void dump_enter( ls_id_index idx) const;

		void dump_leave() const;

		void dump_builtins() const;

		void dump_main() const;

		void dump_type( const type_vector::const_iterator & tit) const;

		void dump_glabel( const label_map::const_iterator & lit) const;

		void dump_global( const symbol_map::const_iterator & sit) const;

		void dump_llabel( const label_map::const_iterator & lit) const;

		void dump_local( const symbol_map::const_iterator & sit) const;

		std::ostream & dump_type( std::ostream & o, const type_vector::const_iterator & tit) const;

		std::ostream & dump_glabel( std::ostream & o, const label_map::const_iterator & lit) const;

		template< typename M>
		std::ostream & dump_glabel( std::ostream & o, const label_map::const_iterator & lit, std::ostream & oo, DumpUniquizer & uniq, M mode) const;

		std::ostream & dump_global( std::ostream & o, const symbol_map::const_iterator & sit) const;

		template< typename M>
		std::ostream & dump_global( std::ostream & o, const symbol_map::const_iterator & sit, std::ostream & oo, DumpUniquizer & uniq, M mode) const;

		std::ostream & dump_llabel( std::ostream & o, const label_map::const_iterator & lit) const;

		std::ostream & dump_local( std::ostream & o, const symbol_map::const_iterator & sit) const;
	};

	/*************************************************************************/

	/// creates an empty parameter list
	parameter_list_ptr create_parameter_list();

	/// creates an empty field list
	field_list_ptr create_field_list();

	/// compares two types
	/** returns true if types are identical wrt. Mlaskal rules **/
	bool identical_type( type_pointer a, type_pointer b);

	/***************** MAIN FUNCTIONS **************************************/

	std::unique_ptr< mlaskal::abstract_ic> create_ic();

	void dump_ic(const config & c, const std::unique_ptr< mlaskal::abstract_ic> & e);

	std::unique_ptr< symbol_tables> create_tab(const config & c, const std::unique_ptr< mlaskal::abstract_ic> & e);

	void dump_tab(const config & c, const std::unique_ptr< symbol_tables> & f);

	/***************** THE BISON CONTEXT ***************************/

	typedef void * yyscan_t2;	// avoid including bgexpl.hpp = avoid macro pollution

	yyscan_t2 lexer_init(FILE * iff);
	void lexer_shutdown(yyscan_t2 lx);

	struct file_data
	{
		file_data() : iff(nullptr) {}
		file_data(const file_data &) = delete;
		file_data & operator=(const file_data &) = delete;
		file_data(file_data && b)
			: iff(b.iff)
		{
			b.iff = nullptr;
		}
		file_data & operator=(file_data && b)
		{
			iff = b.iff;
			b.iff = nullptr;
			return *this;
		}
		~file_data()
		{
			if (iff)
			{
				fclose(iff);
			}
		}

		FILE * iff;
	};

	file_data open_file(config & c);

	/*************************************************************/

	/// structure for bison context
	class MlaskalCtx {
	public:
		MlaskalCtx(symbol_tables *t)
			: tab(t), curline(1)
		{
		}
		symbol_tables		*tab;
		unsigned curline;
	};

	template< typename bison_parser>
	void parse(const file_data & d, const std::unique_ptr< symbol_tables> & f)
	{
		MlaskalCtx ctx(&*f);
		auto scanner = lexer_init(d.iff);
		bison_parser parser(scanner, &ctx);
		parser.parse();
		lexer_shutdown(scanner);
	}

	/* group elements */
	enum class DUTOKGE_OPER_REL {
		DUTOKGE_LT,	/* < */
		DUTOKGE_LE,	/* <= */
		DUTOKGE_NE,	/* <> */
		DUTOKGE_GE,	/* >= */
		DUTOKGE_GT	/* > */
	};
	enum class DUTOKGE_OPER_SIGNADD {
		DUTOKGE_PLUS,	/* + */
		DUTOKGE_MINUS	/* - */
	};
	enum class DUTOKGE_OPER_MUL {
		DUTOKGE_ASTERISK,	/* * */
		DUTOKGE_SOLIDUS,	/* / */
		DUTOKGE_DIV,	/* div */
		DUTOKGE_MOD,	/* mod */
		DUTOKGE_AND		/* and */
	};
	enum class DUTOKGE_FOR_DIRECTION {
		DUTOKGE_TO,		/* to */
		DUTOKGE_DOWNTO	/* downto */
	};

	/*************************************************************/
	/* dummy grammar token types */

	using token_attr_n = std::string;
	using token_attr_s = std::pair< std::string, std::string>;
	using token_attr_i = std::pair< std::string, int>;
	using token_attr_r = std::pair< std::string, double>;

	/*************************************************************/

	inline void final_message(const std::unique_ptr< symbol_tables> & f)
	{
		f->final_message();
		final_message();
	}
};

namespace mlaskal {

	template<> struct object_traits< mlc::abstract_type> : object_traits< mlc::type_entry> {};
	template<> struct object_traits< mlc::array_type> : object_traits< mlc::type_entry> {};
	template<> struct object_traits< mlc::record_type> : object_traits< mlc::type_entry> {};
	template<> struct object_traits< mlc::int_type> : object_traits< mlc::type_entry> {};
	template<> struct object_traits< mlc::range_type> : object_traits< mlc::type_entry> {};
	template<> struct object_traits< mlc::bool_type> : object_traits< mlc::type_entry> {};
	template<> struct object_traits< mlc::real_type> : object_traits< mlc::type_entry> {};
	template<> struct object_traits< mlc::str_type> : object_traits< mlc::type_entry> {};

	template<> struct object_traits< mlc::typed_symbol> : object_traits< mlc::symbol_entry> {};
	template<> struct object_traits< mlc::variable_symbol> : object_traits< mlc::symbol_entry> {};
	template<> struct object_traits< mlc::subprogram_symbol> : object_traits< mlc::symbol_entry> {};
	template<> struct object_traits< mlc::procedure_symbol> : object_traits< mlc::symbol_entry> {};
	template<> struct object_traits< mlc::function_symbol> : object_traits< mlc::symbol_entry> {};
	template<> struct object_traits< mlc::global_variable_symbol> : object_traits< mlc::symbol_entry> {};
	template<> struct object_traits< mlc::local_variable_symbol> : object_traits< mlc::symbol_entry> {};
	template<> struct object_traits< mlc::parameter_by_reference_symbol> : object_traits< mlc::symbol_entry> {};
	template<> struct object_traits< mlc::type_symbol> : object_traits< mlc::symbol_entry> {};
	template<> struct object_traits< mlc::const_symbol> : object_traits< mlc::symbol_entry> {};
	template<> struct object_traits< mlc::abstract_symbol> : object_traits< mlc::symbol_entry> {};
	template<> struct object_traits< mlc::bool_const_symbol> : object_traits< mlc::symbol_entry> {};
	template<> struct object_traits< mlc::int_const_symbol> : object_traits< mlc::symbol_entry> {};
	template<> struct object_traits< mlc::real_const_symbol> : object_traits< mlc::symbol_entry> {};
	template<> struct object_traits< mlc::str_const_symbol> : object_traits< mlc::symbol_entry> {};

	template<> struct object_traits< mlc::label_symbol> : object_traits< mlc::label_entry> {};

	template<> struct object_traits< const int>
	{
		static const int * get_dummy_object()
		{
			static const int dummy = 0;
			return &dummy;
		}
	};

	template<> struct object_traits< const double>
	{
		static const double * get_dummy_object()
		{
			static const double dummy = 0.0;
			return &dummy;
		}
	};
};

#endif
