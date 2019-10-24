// A Bison parser, made by GNU Bison 3.0.4.

// Skeleton interface for Bison LALR(1) parsers in C++

// Copyright (C) 2002-2015 Free Software Foundation, Inc.

// This program is free software: you can redistribute it and/or modify
// it under the terms of the GNU General Public License as published by
// the Free Software Foundation, either version 3 of the License, or
// (at your option) any later version.

// This program is distributed in the hope that it will be useful,
// but WITHOUT ANY WARRANTY; without even the implied warranty of
// MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
// GNU General Public License for more details.

// You should have received a copy of the GNU General Public License
// along with this program.  If not, see <http://www.gnu.org/licenses/>.

// As a special exception, you may create a larger work that contains
// part or all of the Bison parser skeleton and distribute that work
// under terms of your choice, so long as that work isn't itself a
// parser generator using the skeleton or a modified version thereof
// as a parser skeleton.  Alternatively, if you modify or redistribute
// the parser skeleton itself, you may (at your option) remove this
// special exception, which will cause the skeleton and the resulting
// Bison output files to be licensed under the GNU General Public
// License without this special exception.

// This special exception was added by the Free Software Foundation in
// version 2.2 of Bison.

/**
 ** \file dummyg.hpp
 ** Define the yy::parser class.
 */

// C++ LALR(1) parser skeleton written by Akim Demaille.

#ifndef YY_YY_DUMMYG_HPP_INCLUDED
# define YY_YY_DUMMYG_HPP_INCLUDED
// //                    "%code requires" blocks.
#line 15 "D:\\bednarek\\@SVN\\mlaskal\\public-ro\\mlc\\src\\dummyg.y" // lalr1.cc:377

	// this code is emitted to du6g.hpp

	// allow references to semantic types in %type
#include "dutables.hpp"

	// avoid no-case warnings when compiling du6g.hpp
#pragma warning (disable:4065)

// adjust YYLLOC_DEFAULT macro for our api.location.type
#define YYLLOC_DEFAULT(res,rhs,N)	(res = (N)?YYRHSLOC(rhs, 1):YYRHSLOC(rhs, 0))
// supply missing YY_NULL in bfexpg.hpp
#define YY_NULL	0
#define YY_NULLPTR	0

#line 60 "dummyg.hpp" // lalr1.cc:377

# include <cassert>
# include <cstdlib> // std::abort
# include <iostream>
# include <stdexcept>
# include <string>
# include <vector>
# include "stack.hh"

#include <typeinfo>
#ifndef YYASSERT
# include <cassert>
# define YYASSERT assert
#endif


#ifndef YY_ATTRIBUTE
# if (defined __GNUC__                                               \
      && (2 < __GNUC__ || (__GNUC__ == 2 && 96 <= __GNUC_MINOR__)))  \
     || defined __SUNPRO_C && 0x5110 <= __SUNPRO_C
#  define YY_ATTRIBUTE(Spec) __attribute__(Spec)
# else
#  define YY_ATTRIBUTE(Spec) /* empty */
# endif
#endif

#ifndef YY_ATTRIBUTE_PURE
# define YY_ATTRIBUTE_PURE   YY_ATTRIBUTE ((__pure__))
#endif

#ifndef YY_ATTRIBUTE_UNUSED
# define YY_ATTRIBUTE_UNUSED YY_ATTRIBUTE ((__unused__))
#endif

#if !defined _Noreturn \
     && (!defined __STDC_VERSION__ || __STDC_VERSION__ < 201112)
# if defined _MSC_VER && 1200 <= _MSC_VER
#  define _Noreturn __declspec (noreturn)
# else
#  define _Noreturn YY_ATTRIBUTE ((__noreturn__))
# endif
#endif

/* Suppress unused-variable warnings by "using" E.  */
#if ! defined lint || defined __GNUC__
# define YYUSE(E) ((void) (E))
#else
# define YYUSE(E) /* empty */
#endif

#if defined __GNUC__ && 407 <= __GNUC__ * 100 + __GNUC_MINOR__
/* Suppress an incorrect diagnostic about yylval being uninitialized.  */
# define YY_IGNORE_MAYBE_UNINITIALIZED_BEGIN \
    _Pragma ("GCC diagnostic push") \
    _Pragma ("GCC diagnostic ignored \"-Wuninitialized\"")\
    _Pragma ("GCC diagnostic ignored \"-Wmaybe-uninitialized\"")
# define YY_IGNORE_MAYBE_UNINITIALIZED_END \
    _Pragma ("GCC diagnostic pop")
#else
# define YY_INITIAL_VALUE(Value) Value
#endif
#ifndef YY_IGNORE_MAYBE_UNINITIALIZED_BEGIN
# define YY_IGNORE_MAYBE_UNINITIALIZED_BEGIN
# define YY_IGNORE_MAYBE_UNINITIALIZED_END
#endif
#ifndef YY_INITIAL_VALUE
# define YY_INITIAL_VALUE(Value) /* Nothing. */
#endif

/* Debug traces.  */
#ifndef YYDEBUG
# define YYDEBUG 0
#endif


namespace yy {
#line 137 "dummyg.hpp" // lalr1.cc:377



  /// A char[S] buffer to store and retrieve objects.
  ///
  /// Sort of a variant, but does not keep track of the nature
  /// of the stored data, since that knowledge is available
  /// via the current state.
  template <size_t S>
  struct variant
  {
    /// Type of *this.
    typedef variant<S> self_type;

    /// Empty construction.
    variant ()
      : yytypeid_ (YY_NULLPTR)
    {}

    /// Construct and fill.
    template <typename T>
    variant (const T& t)
      : yytypeid_ (&typeid (T))
    {
      YYASSERT (sizeof (T) <= S);
      new (yyas_<T> ()) T (t);
    }

    /// Destruction, allowed only if empty.
    ~variant ()
    {
      YYASSERT (!yytypeid_);
    }

    /// Instantiate an empty \a T in here.
    template <typename T>
    T&
    build ()
    {
      YYASSERT (!yytypeid_);
      YYASSERT (sizeof (T) <= S);
      yytypeid_ = & typeid (T);
      return *new (yyas_<T> ()) T;
    }

    /// Instantiate a \a T in here from \a t.
    template <typename T>
    T&
    build (const T& t)
    {
      YYASSERT (!yytypeid_);
      YYASSERT (sizeof (T) <= S);
      yytypeid_ = & typeid (T);
      return *new (yyas_<T> ()) T (t);
    }

    /// Accessor to a built \a T.
    template <typename T>
    T&
    as ()
    {
      YYASSERT (*yytypeid_ == typeid (T));
      YYASSERT (sizeof (T) <= S);
      return *yyas_<T> ();
    }

    /// Const accessor to a built \a T (for %printer).
    template <typename T>
    const T&
    as () const
    {
      YYASSERT (*yytypeid_ == typeid (T));
      YYASSERT (sizeof (T) <= S);
      return *yyas_<T> ();
    }

    /// Swap the content with \a other, of same type.
    ///
    /// Both variants must be built beforehand, because swapping the actual
    /// data requires reading it (with as()), and this is not possible on
    /// unconstructed variants: it would require some dynamic testing, which
    /// should not be the variant's responsability.
    /// Swapping between built and (possibly) non-built is done with
    /// variant::move ().
    template <typename T>
    void
    swap (self_type& other)
    {
      YYASSERT (yytypeid_);
      YYASSERT (*yytypeid_ == *other.yytypeid_);
      std::swap (as<T> (), other.as<T> ());
    }

    /// Move the content of \a other to this.
    ///
    /// Destroys \a other.
    template <typename T>
    void
    move (self_type& other)
    {
      build<T> ();
      swap<T> (other);
      other.destroy<T> ();
    }

    /// Copy the content of \a other to this.
    template <typename T>
    void
    copy (const self_type& other)
    {
      build<T> (other.as<T> ());
    }

    /// Destroy the stored \a T.
    template <typename T>
    void
    destroy ()
    {
      as<T> ().~T ();
      yytypeid_ = YY_NULLPTR;
    }

  private:
    /// Prohibit blind copies.
    self_type& operator=(const self_type&);
    variant (const self_type&);

    /// Accessor to raw memory as \a T.
    template <typename T>
    T*
    yyas_ ()
    {
      void *yyp = yybuffer_.yyraw;
      return static_cast<T*> (yyp);
     }

    /// Const accessor to raw memory as \a T.
    template <typename T>
    const T*
    yyas_ () const
    {
      const void *yyp = yybuffer_.yyraw;
      return static_cast<const T*> (yyp);
     }

    union
    {
      /// Strongest alignment constraints.
      long double yyalign_me;
      /// A buffer large enough to store any of the semantic values.
      char yyraw[S];
    } yybuffer_;

    /// Whether the content is built: if defined, the name of the stored type.
    const std::type_info *yytypeid_;
  };


  /// A Bison parser.
  class  mlaskal_parser 
  {
  public:
#ifndef YYSTYPE
    /// An auxiliary type to compute the largest semantic type.
    union union_type
    {
      // FOR_DIRECTION
      char dummy1[sizeof(mlc::DUTOKGE_FOR_DIRECTION)];

      // OPER_MUL
      char dummy2[sizeof(mlc::DUTOKGE_OPER_MUL)];

      // OPER_REL
      char dummy3[sizeof(mlc::DUTOKGE_OPER_REL)];

      // OPER_SIGNADD
      char dummy4[sizeof(mlc::DUTOKGE_OPER_SIGNADD)];

      // IDENTIFIER
      char dummy5[sizeof(mlc::ls_id_index)];

      // UINT
      char dummy6[sizeof(mlc::ls_int_index)];

      // REAL
      char dummy7[sizeof(mlc::ls_real_index)];

      // STRING
      char dummy8[sizeof(mlc::ls_str_index)];

      // token_i
      char dummy9[sizeof(mlc::token_attr_i)];

      // token_n
      char dummy10[sizeof(mlc::token_attr_n)];

      // token_r
      char dummy11[sizeof(mlc::token_attr_r)];

      // token_s
      char dummy12[sizeof(mlc::token_attr_s)];
};

    /// Symbol semantic values.
    typedef variant<sizeof(union_type)> semantic_type;
#else
    typedef YYSTYPE semantic_type;
#endif
    /// Symbol locations.
    typedef  unsigned  location_type;

    /// Syntax errors thrown from user actions.
    struct syntax_error : std::runtime_error
    {
      syntax_error (const location_type& l, const std::string& m);
      location_type location;
    };

    /// Tokens.
    struct token
    {
      enum yytokentype
      {
        DUTOK_EOF = 0,
        DUTOK_PROGRAM = 258,
        DUTOK_LABEL = 259,
        DUTOK_CONST = 260,
        DUTOK_TYPE = 261,
        DUTOK_VAR = 262,
        DUTOK_BEGIN = 263,
        DUTOK_END = 264,
        DUTOK_PROCEDURE = 265,
        DUTOK_FUNCTION = 266,
        DUTOK_ARRAY = 267,
        DUTOK_OF = 268,
        DUTOK_GOTO = 269,
        DUTOK_IF = 270,
        DUTOK_THEN = 271,
        DUTOK_ELSE = 272,
        DUTOK_WHILE = 273,
        DUTOK_DO = 274,
        DUTOK_REPEAT = 275,
        DUTOK_UNTIL = 276,
        DUTOK_FOR = 277,
        DUTOK_OR = 278,
        DUTOK_NOT = 279,
        DUTOK_RECORD = 280,
        DUTOK_IDENTIFIER = 281,
        DUTOK_UINT = 282,
        DUTOK_REAL = 283,
        DUTOK_STRING = 284,
        DUTOK_SEMICOLON = 285,
        DUTOK_DOT = 286,
        DUTOK_COMMA = 287,
        DUTOK_EQ = 288,
        DUTOK_COLON = 289,
        DUTOK_LPAR = 290,
        DUTOK_RPAR = 291,
        DUTOK_DOTDOT = 292,
        DUTOK_LSBRA = 293,
        DUTOK_RSBRA = 294,
        DUTOK_ASSIGN = 295,
        DUTOK_OPER_REL = 296,
        DUTOK_OPER_SIGNADD = 297,
        DUTOK_OPER_MUL = 298,
        DUTOK_FOR_DIRECTION = 299
      };
    };

    /// (External) token type, as returned by yylex.
    typedef token::yytokentype token_type;

    /// Symbol type: an internal symbol number.
    typedef int symbol_number_type;

    /// The symbol type number to denote an empty symbol.
    enum { empty_symbol = -2 };

    /// Internal symbol number for tokens (subsumed by symbol_number_type).
    typedef unsigned char token_number_type;

    /// A complete symbol.
    ///
    /// Expects its Base type to provide access to the symbol type
    /// via type_get().
    ///
    /// Provide access to semantic value and location.
    template <typename Base>
    struct basic_symbol : Base
    {
      /// Alias to Base.
      typedef Base super_type;

      /// Default constructor.
      basic_symbol ();

      /// Copy constructor.
      basic_symbol (const basic_symbol& other);

      /// Constructor for valueless symbols, and symbols from each type.

  basic_symbol (typename Base::kind_type t, const location_type& l);

  basic_symbol (typename Base::kind_type t, const mlc::DUTOKGE_FOR_DIRECTION v, const location_type& l);

  basic_symbol (typename Base::kind_type t, const mlc::DUTOKGE_OPER_MUL v, const location_type& l);

  basic_symbol (typename Base::kind_type t, const mlc::DUTOKGE_OPER_REL v, const location_type& l);

  basic_symbol (typename Base::kind_type t, const mlc::DUTOKGE_OPER_SIGNADD v, const location_type& l);

  basic_symbol (typename Base::kind_type t, const mlc::ls_id_index v, const location_type& l);

  basic_symbol (typename Base::kind_type t, const mlc::ls_int_index v, const location_type& l);

  basic_symbol (typename Base::kind_type t, const mlc::ls_real_index v, const location_type& l);

  basic_symbol (typename Base::kind_type t, const mlc::ls_str_index v, const location_type& l);

  basic_symbol (typename Base::kind_type t, const mlc::token_attr_i v, const location_type& l);

  basic_symbol (typename Base::kind_type t, const mlc::token_attr_n v, const location_type& l);

  basic_symbol (typename Base::kind_type t, const mlc::token_attr_r v, const location_type& l);

  basic_symbol (typename Base::kind_type t, const mlc::token_attr_s v, const location_type& l);


      /// Constructor for symbols with semantic value.
      basic_symbol (typename Base::kind_type t,
                    const semantic_type& v,
                    const location_type& l);

      /// Destroy the symbol.
      ~basic_symbol ();

      /// Destroy contents, and record that is empty.
      void clear ();

      /// Whether empty.
      bool empty () const;

      /// Destructive move, \a s is emptied into this.
      void move (basic_symbol& s);

      /// The semantic value.
      semantic_type value;

      /// The location.
      location_type location;

    private:
      /// Assignment operator.
      basic_symbol& operator= (const basic_symbol& other);
    };

    /// Type access provider for token (enum) based symbols.
    struct by_type
    {
      /// Default constructor.
      by_type ();

      /// Copy constructor.
      by_type (const by_type& other);

      /// The symbol type as needed by the constructor.
      typedef token_type kind_type;

      /// Constructor from (external) token numbers.
      by_type (kind_type t);

      /// Record that this symbol is empty.
      void clear ();

      /// Steal the symbol type from \a that.
      void move (by_type& that);

      /// The (internal) type number (corresponding to \a type).
      /// \a empty when empty.
      symbol_number_type type_get () const;

      /// The token.
      token_type token () const;

      /// The symbol type.
      /// \a empty_symbol when empty.
      /// An int, not token_number_type, to be able to store empty_symbol.
      int type;
    };

    /// "External" symbols: returned by the scanner.
    typedef basic_symbol<by_type> symbol_type;

    // Symbol constructors declarations.
    static inline
    symbol_type
    make_EOF (const location_type& l);

    static inline
    symbol_type
    make_PROGRAM (const location_type& l);

    static inline
    symbol_type
    make_LABEL (const location_type& l);

    static inline
    symbol_type
    make_CONST (const location_type& l);

    static inline
    symbol_type
    make_TYPE (const location_type& l);

    static inline
    symbol_type
    make_VAR (const location_type& l);

    static inline
    symbol_type
    make_BEGIN (const location_type& l);

    static inline
    symbol_type
    make_END (const location_type& l);

    static inline
    symbol_type
    make_PROCEDURE (const location_type& l);

    static inline
    symbol_type
    make_FUNCTION (const location_type& l);

    static inline
    symbol_type
    make_ARRAY (const location_type& l);

    static inline
    symbol_type
    make_OF (const location_type& l);

    static inline
    symbol_type
    make_GOTO (const location_type& l);

    static inline
    symbol_type
    make_IF (const location_type& l);

    static inline
    symbol_type
    make_THEN (const location_type& l);

    static inline
    symbol_type
    make_ELSE (const location_type& l);

    static inline
    symbol_type
    make_WHILE (const location_type& l);

    static inline
    symbol_type
    make_DO (const location_type& l);

    static inline
    symbol_type
    make_REPEAT (const location_type& l);

    static inline
    symbol_type
    make_UNTIL (const location_type& l);

    static inline
    symbol_type
    make_FOR (const location_type& l);

    static inline
    symbol_type
    make_OR (const location_type& l);

    static inline
    symbol_type
    make_NOT (const location_type& l);

    static inline
    symbol_type
    make_RECORD (const location_type& l);

    static inline
    symbol_type
    make_IDENTIFIER (const mlc::ls_id_index& v, const location_type& l);

    static inline
    symbol_type
    make_UINT (const mlc::ls_int_index& v, const location_type& l);

    static inline
    symbol_type
    make_REAL (const mlc::ls_real_index& v, const location_type& l);

    static inline
    symbol_type
    make_STRING (const mlc::ls_str_index& v, const location_type& l);

    static inline
    symbol_type
    make_SEMICOLON (const location_type& l);

    static inline
    symbol_type
    make_DOT (const location_type& l);

    static inline
    symbol_type
    make_COMMA (const location_type& l);

    static inline
    symbol_type
    make_EQ (const location_type& l);

    static inline
    symbol_type
    make_COLON (const location_type& l);

    static inline
    symbol_type
    make_LPAR (const location_type& l);

    static inline
    symbol_type
    make_RPAR (const location_type& l);

    static inline
    symbol_type
    make_DOTDOT (const location_type& l);

    static inline
    symbol_type
    make_LSBRA (const location_type& l);

    static inline
    symbol_type
    make_RSBRA (const location_type& l);

    static inline
    symbol_type
    make_ASSIGN (const location_type& l);

    static inline
    symbol_type
    make_OPER_REL (const mlc::DUTOKGE_OPER_REL& v, const location_type& l);

    static inline
    symbol_type
    make_OPER_SIGNADD (const mlc::DUTOKGE_OPER_SIGNADD& v, const location_type& l);

    static inline
    symbol_type
    make_OPER_MUL (const mlc::DUTOKGE_OPER_MUL& v, const location_type& l);

    static inline
    symbol_type
    make_FOR_DIRECTION (const mlc::DUTOKGE_FOR_DIRECTION& v, const location_type& l);


    /// Build a parser object.
     mlaskal_parser  (mlc::yyscan_t2 yyscanner_yyarg, mlc::MlaskalCtx* ctx_yyarg);
    virtual ~ mlaskal_parser  ();

    /// Parse.
    /// \returns  0 iff parsing succeeded.
    virtual int parse ();

#if YYDEBUG
    /// The current debugging stream.
    std::ostream& debug_stream () const YY_ATTRIBUTE_PURE;
    /// Set the current debugging stream.
    void set_debug_stream (std::ostream &);

    /// Type for debugging levels.
    typedef int debug_level_type;
    /// The current debugging level.
    debug_level_type debug_level () const YY_ATTRIBUTE_PURE;
    /// Set the current debugging level.
    void set_debug_level (debug_level_type l);
#endif

    /// Report a syntax error.
    /// \param loc    where the syntax error is found.
    /// \param msg    a description of the syntax error.
    virtual void error (const location_type& loc, const std::string& msg);

    /// Report a syntax error.
    void error (const syntax_error& err);

  private:
    /// This class is not copyable.
     mlaskal_parser  (const  mlaskal_parser &);
     mlaskal_parser & operator= (const  mlaskal_parser &);

    /// State numbers.
    typedef int state_type;

    /// Generate an error message.
    /// \param yystate   the state where the error occurred.
    /// \param yyla      the lookahead token.
    virtual std::string yysyntax_error_ (state_type yystate,
                                         const symbol_type& yyla) const;

    /// Compute post-reduction state.
    /// \param yystate   the current state
    /// \param yysym     the nonterminal to push on the stack
    state_type yy_lr_goto_state_ (state_type yystate, int yysym);

    /// Whether the given \c yypact_ value indicates a defaulted state.
    /// \param yyvalue   the value to check
    static bool yy_pact_value_is_default_ (int yyvalue);

    /// Whether the given \c yytable_ value indicates a syntax error.
    /// \param yyvalue   the value to check
    static bool yy_table_value_is_error_ (int yyvalue);

    static const signed char yypact_ninf_;
    static const signed char yytable_ninf_;

    /// Convert a scanner token number \a t to a symbol number.
    static token_number_type yytranslate_ (token_type t);

    // Tables.
  // YYPACT[STATE-NUM] -- Index in YYTABLE of the portion describing
  // STATE-NUM.
  static const signed char yypact_[];

  // YYDEFACT[STATE-NUM] -- Default reduction number in state STATE-NUM.
  // Performed when YYTABLE does not specify something else to do.  Zero
  // means the default is an error.
  static const unsigned char yydefact_[];

  // YYPGOTO[NTERM-NUM].
  static const signed char yypgoto_[];

  // YYDEFGOTO[NTERM-NUM].
  static const signed char yydefgoto_[];

  // YYTABLE[YYPACT[STATE-NUM]] -- What to do in state STATE-NUM.  If
  // positive, shift that token.  If negative, reduce the rule whose
  // number is the opposite.  If YYTABLE_NINF, syntax error.
  static const unsigned char yytable_[];

  static const unsigned char yycheck_[];

  // YYSTOS[STATE-NUM] -- The (internal number of the) accessing
  // symbol of state STATE-NUM.
  static const unsigned char yystos_[];

  // YYR1[YYN] -- Symbol number of symbol that rule YYN derives.
  static const unsigned char yyr1_[];

  // YYR2[YYN] -- Number of symbols on the right hand side of rule YYN.
  static const unsigned char yyr2_[];


    /// Convert the symbol name \a n to a form suitable for a diagnostic.
    static std::string yytnamerr_ (const char *n);


    /// For a symbol, its name in clear.
    static const char* const yytname_[];
#if YYDEBUG
  // YYRLINE[YYN] -- Source line where rule number YYN was defined.
  static const unsigned char yyrline_[];
    /// Report on the debug stream that the rule \a r is going to be reduced.
    virtual void yy_reduce_print_ (int r);
    /// Print the state stack on the debug stream.
    virtual void yystack_print_ ();

    // Debugging.
    int yydebug_;
    std::ostream* yycdebug_;

    /// \brief Display a symbol type, value and location.
    /// \param yyo    The output stream.
    /// \param yysym  The symbol.
    template <typename Base>
    void yy_print_ (std::ostream& yyo, const basic_symbol<Base>& yysym) const;
#endif

    /// \brief Reclaim the memory associated to a symbol.
    /// \param yymsg     Why this token is reclaimed.
    ///                  If null, print nothing.
    /// \param yysym     The symbol.
    template <typename Base>
    void yy_destroy_ (const char* yymsg, basic_symbol<Base>& yysym) const;

  private:
    /// Type access provider for state based symbols.
    struct by_state
    {
      /// Default constructor.
      by_state ();

      /// The symbol type as needed by the constructor.
      typedef state_type kind_type;

      /// Constructor.
      by_state (kind_type s);

      /// Copy constructor.
      by_state (const by_state& other);

      /// Record that this symbol is empty.
      void clear ();

      /// Steal the symbol type from \a that.
      void move (by_state& that);

      /// The (internal) type number (corresponding to \a state).
      /// \a empty_symbol when empty.
      symbol_number_type type_get () const;

      /// The state number used to denote an empty symbol.
      enum { empty_state = -1 };

      /// The state.
      /// \a empty when empty.
      state_type state;
    };

    /// "Internal" symbol: element of the stack.
    struct stack_symbol_type : basic_symbol<by_state>
    {
      /// Superclass.
      typedef basic_symbol<by_state> super_type;
      /// Construct an empty symbol.
      stack_symbol_type ();
      /// Steal the contents from \a sym to build this.
      stack_symbol_type (state_type s, symbol_type& sym);
      /// Assignment, needed by push_back.
      stack_symbol_type& operator= (const stack_symbol_type& that);
    };

    /// Stack type.
    typedef stack<stack_symbol_type> stack_type;

    /// The stack.
    stack_type yystack_;

    /// Push a new state on the stack.
    /// \param m    a debug message to display
    ///             if null, no trace is output.
    /// \param s    the symbol
    /// \warning the contents of \a s.value is stolen.
    void yypush_ (const char* m, stack_symbol_type& s);

    /// Push a new look ahead token on the state on the stack.
    /// \param m    a debug message to display
    ///             if null, no trace is output.
    /// \param s    the state
    /// \param sym  the symbol (for its value and location).
    /// \warning the contents of \a s.value is stolen.
    void yypush_ (const char* m, state_type s, symbol_type& sym);

    /// Pop \a n symbols the three stacks.
    void yypop_ (unsigned int n = 1);

    /// Constants.
    enum
    {
      yyeof_ = 0,
      yylast_ = 42,     ///< Last index in yytable_.
      yynnts_ = 8,  ///< Number of nonterminal symbols.
      yyfinal_ = 3, ///< Termination state number.
      yyterror_ = 1,
      yyerrcode_ = 256,
      yyntokens_ = 45  ///< Number of tokens.
    };


    // User arguments.
    mlc::yyscan_t2 yyscanner;
    mlc::MlaskalCtx* ctx;
  };

  // Symbol number corresponding to token number t.
  inline
   mlaskal_parser ::token_number_type
   mlaskal_parser ::yytranslate_ (token_type t)
  {
    static
    const token_number_type
    translate_table[] =
    {
     0,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     1,     2,     3,     4,
       5,     6,     7,     8,     9,    10,    11,    12,    13,    14,
      15,    16,    17,    18,    19,    20,    21,    22,    23,    24,
      25,    26,    27,    28,    29,    30,    31,    32,    33,    34,
      35,    36,    37,    38,    39,    40,    41,    42,    43,    44
    };
    const unsigned int user_token_number_max_ = 299;
    const token_number_type undef_token_ = 2;

    if (static_cast<int>(t) <= yyeof_)
      return yyeof_;
    else if (static_cast<unsigned int> (t) <= user_token_number_max_)
      return translate_table[t];
    else
      return undef_token_;
  }

  inline
   mlaskal_parser ::syntax_error::syntax_error (const location_type& l, const std::string& m)
    : std::runtime_error (m)
    , location (l)
  {}

  // basic_symbol.
  template <typename Base>
  inline
   mlaskal_parser ::basic_symbol<Base>::basic_symbol ()
    : value ()
  {}

  template <typename Base>
  inline
   mlaskal_parser ::basic_symbol<Base>::basic_symbol (const basic_symbol& other)
    : Base (other)
    , value ()
    , location (other.location)
  {
      switch (other.type_get ())
    {
      case 44: // FOR_DIRECTION
        value.copy< mlc::DUTOKGE_FOR_DIRECTION > (other.value);
        break;

      case 43: // OPER_MUL
        value.copy< mlc::DUTOKGE_OPER_MUL > (other.value);
        break;

      case 41: // OPER_REL
        value.copy< mlc::DUTOKGE_OPER_REL > (other.value);
        break;

      case 42: // OPER_SIGNADD
        value.copy< mlc::DUTOKGE_OPER_SIGNADD > (other.value);
        break;

      case 26: // IDENTIFIER
        value.copy< mlc::ls_id_index > (other.value);
        break;

      case 27: // UINT
        value.copy< mlc::ls_int_index > (other.value);
        break;

      case 28: // REAL
        value.copy< mlc::ls_real_index > (other.value);
        break;

      case 29: // STRING
        value.copy< mlc::ls_str_index > (other.value);
        break;

      case 51: // token_i
        value.copy< mlc::token_attr_i > (other.value);
        break;

      case 49: // token_n
        value.copy< mlc::token_attr_n > (other.value);
        break;

      case 52: // token_r
        value.copy< mlc::token_attr_r > (other.value);
        break;

      case 50: // token_s
        value.copy< mlc::token_attr_s > (other.value);
        break;

      default:
        break;
    }

  }


  template <typename Base>
  inline
   mlaskal_parser ::basic_symbol<Base>::basic_symbol (typename Base::kind_type t, const semantic_type& v, const location_type& l)
    : Base (t)
    , value ()
    , location (l)
  {
    (void) v;
      switch (this->type_get ())
    {
      case 44: // FOR_DIRECTION
        value.copy< mlc::DUTOKGE_FOR_DIRECTION > (v);
        break;

      case 43: // OPER_MUL
        value.copy< mlc::DUTOKGE_OPER_MUL > (v);
        break;

      case 41: // OPER_REL
        value.copy< mlc::DUTOKGE_OPER_REL > (v);
        break;

      case 42: // OPER_SIGNADD
        value.copy< mlc::DUTOKGE_OPER_SIGNADD > (v);
        break;

      case 26: // IDENTIFIER
        value.copy< mlc::ls_id_index > (v);
        break;

      case 27: // UINT
        value.copy< mlc::ls_int_index > (v);
        break;

      case 28: // REAL
        value.copy< mlc::ls_real_index > (v);
        break;

      case 29: // STRING
        value.copy< mlc::ls_str_index > (v);
        break;

      case 51: // token_i
        value.copy< mlc::token_attr_i > (v);
        break;

      case 49: // token_n
        value.copy< mlc::token_attr_n > (v);
        break;

      case 52: // token_r
        value.copy< mlc::token_attr_r > (v);
        break;

      case 50: // token_s
        value.copy< mlc::token_attr_s > (v);
        break;

      default:
        break;
    }
}


  // Implementation of basic_symbol constructor for each type.

  template <typename Base>
   mlaskal_parser ::basic_symbol<Base>::basic_symbol (typename Base::kind_type t, const location_type& l)
    : Base (t)
    , value ()
    , location (l)
  {}

  template <typename Base>
   mlaskal_parser ::basic_symbol<Base>::basic_symbol (typename Base::kind_type t, const mlc::DUTOKGE_FOR_DIRECTION v, const location_type& l)
    : Base (t)
    , value (v)
    , location (l)
  {}

  template <typename Base>
   mlaskal_parser ::basic_symbol<Base>::basic_symbol (typename Base::kind_type t, const mlc::DUTOKGE_OPER_MUL v, const location_type& l)
    : Base (t)
    , value (v)
    , location (l)
  {}

  template <typename Base>
   mlaskal_parser ::basic_symbol<Base>::basic_symbol (typename Base::kind_type t, const mlc::DUTOKGE_OPER_REL v, const location_type& l)
    : Base (t)
    , value (v)
    , location (l)
  {}

  template <typename Base>
   mlaskal_parser ::basic_symbol<Base>::basic_symbol (typename Base::kind_type t, const mlc::DUTOKGE_OPER_SIGNADD v, const location_type& l)
    : Base (t)
    , value (v)
    , location (l)
  {}

  template <typename Base>
   mlaskal_parser ::basic_symbol<Base>::basic_symbol (typename Base::kind_type t, const mlc::ls_id_index v, const location_type& l)
    : Base (t)
    , value (v)
    , location (l)
  {}

  template <typename Base>
   mlaskal_parser ::basic_symbol<Base>::basic_symbol (typename Base::kind_type t, const mlc::ls_int_index v, const location_type& l)
    : Base (t)
    , value (v)
    , location (l)
  {}

  template <typename Base>
   mlaskal_parser ::basic_symbol<Base>::basic_symbol (typename Base::kind_type t, const mlc::ls_real_index v, const location_type& l)
    : Base (t)
    , value (v)
    , location (l)
  {}

  template <typename Base>
   mlaskal_parser ::basic_symbol<Base>::basic_symbol (typename Base::kind_type t, const mlc::ls_str_index v, const location_type& l)
    : Base (t)
    , value (v)
    , location (l)
  {}

  template <typename Base>
   mlaskal_parser ::basic_symbol<Base>::basic_symbol (typename Base::kind_type t, const mlc::token_attr_i v, const location_type& l)
    : Base (t)
    , value (v)
    , location (l)
  {}

  template <typename Base>
   mlaskal_parser ::basic_symbol<Base>::basic_symbol (typename Base::kind_type t, const mlc::token_attr_n v, const location_type& l)
    : Base (t)
    , value (v)
    , location (l)
  {}

  template <typename Base>
   mlaskal_parser ::basic_symbol<Base>::basic_symbol (typename Base::kind_type t, const mlc::token_attr_r v, const location_type& l)
    : Base (t)
    , value (v)
    , location (l)
  {}

  template <typename Base>
   mlaskal_parser ::basic_symbol<Base>::basic_symbol (typename Base::kind_type t, const mlc::token_attr_s v, const location_type& l)
    : Base (t)
    , value (v)
    , location (l)
  {}


  template <typename Base>
  inline
   mlaskal_parser ::basic_symbol<Base>::~basic_symbol ()
  {
    clear ();
  }

  template <typename Base>
  inline
  void
   mlaskal_parser ::basic_symbol<Base>::clear ()
  {
    // User destructor.
    symbol_number_type yytype = this->type_get ();
    basic_symbol<Base>& yysym = *this;
    (void) yysym;
    switch (yytype)
    {
   default:
      break;
    }

    // Type destructor.
    switch (yytype)
    {
      case 44: // FOR_DIRECTION
        value.template destroy< mlc::DUTOKGE_FOR_DIRECTION > ();
        break;

      case 43: // OPER_MUL
        value.template destroy< mlc::DUTOKGE_OPER_MUL > ();
        break;

      case 41: // OPER_REL
        value.template destroy< mlc::DUTOKGE_OPER_REL > ();
        break;

      case 42: // OPER_SIGNADD
        value.template destroy< mlc::DUTOKGE_OPER_SIGNADD > ();
        break;

      case 26: // IDENTIFIER
        value.template destroy< mlc::ls_id_index > ();
        break;

      case 27: // UINT
        value.template destroy< mlc::ls_int_index > ();
        break;

      case 28: // REAL
        value.template destroy< mlc::ls_real_index > ();
        break;

      case 29: // STRING
        value.template destroy< mlc::ls_str_index > ();
        break;

      case 51: // token_i
        value.template destroy< mlc::token_attr_i > ();
        break;

      case 49: // token_n
        value.template destroy< mlc::token_attr_n > ();
        break;

      case 52: // token_r
        value.template destroy< mlc::token_attr_r > ();
        break;

      case 50: // token_s
        value.template destroy< mlc::token_attr_s > ();
        break;

      default:
        break;
    }

    Base::clear ();
  }

  template <typename Base>
  inline
  bool
   mlaskal_parser ::basic_symbol<Base>::empty () const
  {
    return Base::type_get () == empty_symbol;
  }

  template <typename Base>
  inline
  void
   mlaskal_parser ::basic_symbol<Base>::move (basic_symbol& s)
  {
    super_type::move(s);
      switch (this->type_get ())
    {
      case 44: // FOR_DIRECTION
        value.move< mlc::DUTOKGE_FOR_DIRECTION > (s.value);
        break;

      case 43: // OPER_MUL
        value.move< mlc::DUTOKGE_OPER_MUL > (s.value);
        break;

      case 41: // OPER_REL
        value.move< mlc::DUTOKGE_OPER_REL > (s.value);
        break;

      case 42: // OPER_SIGNADD
        value.move< mlc::DUTOKGE_OPER_SIGNADD > (s.value);
        break;

      case 26: // IDENTIFIER
        value.move< mlc::ls_id_index > (s.value);
        break;

      case 27: // UINT
        value.move< mlc::ls_int_index > (s.value);
        break;

      case 28: // REAL
        value.move< mlc::ls_real_index > (s.value);
        break;

      case 29: // STRING
        value.move< mlc::ls_str_index > (s.value);
        break;

      case 51: // token_i
        value.move< mlc::token_attr_i > (s.value);
        break;

      case 49: // token_n
        value.move< mlc::token_attr_n > (s.value);
        break;

      case 52: // token_r
        value.move< mlc::token_attr_r > (s.value);
        break;

      case 50: // token_s
        value.move< mlc::token_attr_s > (s.value);
        break;

      default:
        break;
    }

    location = s.location;
  }

  // by_type.
  inline
   mlaskal_parser ::by_type::by_type ()
    : type (empty_symbol)
  {}

  inline
   mlaskal_parser ::by_type::by_type (const by_type& other)
    : type (other.type)
  {}

  inline
   mlaskal_parser ::by_type::by_type (token_type t)
    : type (yytranslate_ (t))
  {}

  inline
  void
   mlaskal_parser ::by_type::clear ()
  {
    type = empty_symbol;
  }

  inline
  void
   mlaskal_parser ::by_type::move (by_type& that)
  {
    type = that.type;
    that.clear ();
  }

  inline
  int
   mlaskal_parser ::by_type::type_get () const
  {
    return type;
  }

  inline
   mlaskal_parser ::token_type
   mlaskal_parser ::by_type::token () const
  {
    // YYTOKNUM[NUM] -- (External) token number corresponding to the
    // (internal) symbol number NUM (which must be that of a token).  */
    static
    const unsigned short int
    yytoken_number_[] =
    {
       0,   256,   257,   258,   259,   260,   261,   262,   263,   264,
     265,   266,   267,   268,   269,   270,   271,   272,   273,   274,
     275,   276,   277,   278,   279,   280,   281,   282,   283,   284,
     285,   286,   287,   288,   289,   290,   291,   292,   293,   294,
     295,   296,   297,   298,   299
    };
    return static_cast<token_type> (yytoken_number_[type]);
  }
  // Implementation of make_symbol for each symbol type.
   mlaskal_parser ::symbol_type
   mlaskal_parser ::make_EOF (const location_type& l)
  {
    return symbol_type (token::DUTOK_EOF, l);
  }

   mlaskal_parser ::symbol_type
   mlaskal_parser ::make_PROGRAM (const location_type& l)
  {
    return symbol_type (token::DUTOK_PROGRAM, l);
  }

   mlaskal_parser ::symbol_type
   mlaskal_parser ::make_LABEL (const location_type& l)
  {
    return symbol_type (token::DUTOK_LABEL, l);
  }

   mlaskal_parser ::symbol_type
   mlaskal_parser ::make_CONST (const location_type& l)
  {
    return symbol_type (token::DUTOK_CONST, l);
  }

   mlaskal_parser ::symbol_type
   mlaskal_parser ::make_TYPE (const location_type& l)
  {
    return symbol_type (token::DUTOK_TYPE, l);
  }

   mlaskal_parser ::symbol_type
   mlaskal_parser ::make_VAR (const location_type& l)
  {
    return symbol_type (token::DUTOK_VAR, l);
  }

   mlaskal_parser ::symbol_type
   mlaskal_parser ::make_BEGIN (const location_type& l)
  {
    return symbol_type (token::DUTOK_BEGIN, l);
  }

   mlaskal_parser ::symbol_type
   mlaskal_parser ::make_END (const location_type& l)
  {
    return symbol_type (token::DUTOK_END, l);
  }

   mlaskal_parser ::symbol_type
   mlaskal_parser ::make_PROCEDURE (const location_type& l)
  {
    return symbol_type (token::DUTOK_PROCEDURE, l);
  }

   mlaskal_parser ::symbol_type
   mlaskal_parser ::make_FUNCTION (const location_type& l)
  {
    return symbol_type (token::DUTOK_FUNCTION, l);
  }

   mlaskal_parser ::symbol_type
   mlaskal_parser ::make_ARRAY (const location_type& l)
  {
    return symbol_type (token::DUTOK_ARRAY, l);
  }

   mlaskal_parser ::symbol_type
   mlaskal_parser ::make_OF (const location_type& l)
  {
    return symbol_type (token::DUTOK_OF, l);
  }

   mlaskal_parser ::symbol_type
   mlaskal_parser ::make_GOTO (const location_type& l)
  {
    return symbol_type (token::DUTOK_GOTO, l);
  }

   mlaskal_parser ::symbol_type
   mlaskal_parser ::make_IF (const location_type& l)
  {
    return symbol_type (token::DUTOK_IF, l);
  }

   mlaskal_parser ::symbol_type
   mlaskal_parser ::make_THEN (const location_type& l)
  {
    return symbol_type (token::DUTOK_THEN, l);
  }

   mlaskal_parser ::symbol_type
   mlaskal_parser ::make_ELSE (const location_type& l)
  {
    return symbol_type (token::DUTOK_ELSE, l);
  }

   mlaskal_parser ::symbol_type
   mlaskal_parser ::make_WHILE (const location_type& l)
  {
    return symbol_type (token::DUTOK_WHILE, l);
  }

   mlaskal_parser ::symbol_type
   mlaskal_parser ::make_DO (const location_type& l)
  {
    return symbol_type (token::DUTOK_DO, l);
  }

   mlaskal_parser ::symbol_type
   mlaskal_parser ::make_REPEAT (const location_type& l)
  {
    return symbol_type (token::DUTOK_REPEAT, l);
  }

   mlaskal_parser ::symbol_type
   mlaskal_parser ::make_UNTIL (const location_type& l)
  {
    return symbol_type (token::DUTOK_UNTIL, l);
  }

   mlaskal_parser ::symbol_type
   mlaskal_parser ::make_FOR (const location_type& l)
  {
    return symbol_type (token::DUTOK_FOR, l);
  }

   mlaskal_parser ::symbol_type
   mlaskal_parser ::make_OR (const location_type& l)
  {
    return symbol_type (token::DUTOK_OR, l);
  }

   mlaskal_parser ::symbol_type
   mlaskal_parser ::make_NOT (const location_type& l)
  {
    return symbol_type (token::DUTOK_NOT, l);
  }

   mlaskal_parser ::symbol_type
   mlaskal_parser ::make_RECORD (const location_type& l)
  {
    return symbol_type (token::DUTOK_RECORD, l);
  }

   mlaskal_parser ::symbol_type
   mlaskal_parser ::make_IDENTIFIER (const mlc::ls_id_index& v, const location_type& l)
  {
    return symbol_type (token::DUTOK_IDENTIFIER, v, l);
  }

   mlaskal_parser ::symbol_type
   mlaskal_parser ::make_UINT (const mlc::ls_int_index& v, const location_type& l)
  {
    return symbol_type (token::DUTOK_UINT, v, l);
  }

   mlaskal_parser ::symbol_type
   mlaskal_parser ::make_REAL (const mlc::ls_real_index& v, const location_type& l)
  {
    return symbol_type (token::DUTOK_REAL, v, l);
  }

   mlaskal_parser ::symbol_type
   mlaskal_parser ::make_STRING (const mlc::ls_str_index& v, const location_type& l)
  {
    return symbol_type (token::DUTOK_STRING, v, l);
  }

   mlaskal_parser ::symbol_type
   mlaskal_parser ::make_SEMICOLON (const location_type& l)
  {
    return symbol_type (token::DUTOK_SEMICOLON, l);
  }

   mlaskal_parser ::symbol_type
   mlaskal_parser ::make_DOT (const location_type& l)
  {
    return symbol_type (token::DUTOK_DOT, l);
  }

   mlaskal_parser ::symbol_type
   mlaskal_parser ::make_COMMA (const location_type& l)
  {
    return symbol_type (token::DUTOK_COMMA, l);
  }

   mlaskal_parser ::symbol_type
   mlaskal_parser ::make_EQ (const location_type& l)
  {
    return symbol_type (token::DUTOK_EQ, l);
  }

   mlaskal_parser ::symbol_type
   mlaskal_parser ::make_COLON (const location_type& l)
  {
    return symbol_type (token::DUTOK_COLON, l);
  }

   mlaskal_parser ::symbol_type
   mlaskal_parser ::make_LPAR (const location_type& l)
  {
    return symbol_type (token::DUTOK_LPAR, l);
  }

   mlaskal_parser ::symbol_type
   mlaskal_parser ::make_RPAR (const location_type& l)
  {
    return symbol_type (token::DUTOK_RPAR, l);
  }

   mlaskal_parser ::symbol_type
   mlaskal_parser ::make_DOTDOT (const location_type& l)
  {
    return symbol_type (token::DUTOK_DOTDOT, l);
  }

   mlaskal_parser ::symbol_type
   mlaskal_parser ::make_LSBRA (const location_type& l)
  {
    return symbol_type (token::DUTOK_LSBRA, l);
  }

   mlaskal_parser ::symbol_type
   mlaskal_parser ::make_RSBRA (const location_type& l)
  {
    return symbol_type (token::DUTOK_RSBRA, l);
  }

   mlaskal_parser ::symbol_type
   mlaskal_parser ::make_ASSIGN (const location_type& l)
  {
    return symbol_type (token::DUTOK_ASSIGN, l);
  }

   mlaskal_parser ::symbol_type
   mlaskal_parser ::make_OPER_REL (const mlc::DUTOKGE_OPER_REL& v, const location_type& l)
  {
    return symbol_type (token::DUTOK_OPER_REL, v, l);
  }

   mlaskal_parser ::symbol_type
   mlaskal_parser ::make_OPER_SIGNADD (const mlc::DUTOKGE_OPER_SIGNADD& v, const location_type& l)
  {
    return symbol_type (token::DUTOK_OPER_SIGNADD, v, l);
  }

   mlaskal_parser ::symbol_type
   mlaskal_parser ::make_OPER_MUL (const mlc::DUTOKGE_OPER_MUL& v, const location_type& l)
  {
    return symbol_type (token::DUTOK_OPER_MUL, v, l);
  }

   mlaskal_parser ::symbol_type
   mlaskal_parser ::make_FOR_DIRECTION (const mlc::DUTOKGE_FOR_DIRECTION& v, const location_type& l)
  {
    return symbol_type (token::DUTOK_FOR_DIRECTION, v, l);
  }



} // yy
#line 1678 "dummyg.hpp" // lalr1.cc:377




#endif // !YY_YY_DUMMYG_HPP_INCLUDED
