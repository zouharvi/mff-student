// A Bison parser, made by GNU Bison 3.0.4.

// Skeleton implementation for Bison LALR(1) parsers in C++

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


// First part of user declarations.

#line 37 "dummyg.cpp" // lalr1.cc:404

# ifndef YY_NULLPTR
#  if defined __cplusplus && 201103L <= __cplusplus
#   define YY_NULLPTR nullptr
#  else
#   define YY_NULLPTR 0
#  endif
# endif

#include "dummyg.hpp"

// User implementation prologue.

#line 51 "dummyg.cpp" // lalr1.cc:412
// Unqualified %code blocks.
#line 38 "D:\\bednarek\\@SVN\\mlaskal\\public-ro\\mlc\\src\\dummyg.y" // lalr1.cc:413

	// this code is emitted to du6g.cpp

	// declare yylex here 
	#include "bisonflex.hpp"
	YY_DECL;

	// other user-required contents
	#include <assert.h>
	#include <stdlib.h>

    /* local stuff */
    using namespace mlc;


#line 69 "dummyg.cpp" // lalr1.cc:413


#ifndef YY_
# if defined YYENABLE_NLS && YYENABLE_NLS
#  if ENABLE_NLS
#   include <libintl.h> // FIXME: INFRINGES ON USER NAME SPACE.
#   define YY_(msgid) dgettext ("bison-runtime", msgid)
#  endif
# endif
# ifndef YY_
#  define YY_(msgid) msgid
# endif
#endif

#define YYRHSLOC(Rhs, K) ((Rhs)[K].location)
/* YYLLOC_DEFAULT -- Set CURRENT to span from RHS[1] to RHS[N].
   If N is 0, then set CURRENT to the empty location which ends
   the previous symbol: RHS[0] (always defined).  */

# ifndef YYLLOC_DEFAULT
#  define YYLLOC_DEFAULT(Current, Rhs, N)                               \
    do                                                                  \
      if (N)                                                            \
        {                                                               \
          (Current).begin  = YYRHSLOC (Rhs, 1).begin;                   \
          (Current).end    = YYRHSLOC (Rhs, N).end;                     \
        }                                                               \
      else                                                              \
        {                                                               \
          (Current).begin = (Current).end = YYRHSLOC (Rhs, 0).end;      \
        }                                                               \
    while (/*CONSTCOND*/ false)
# endif


// Suppress unused-variable warnings by "using" E.
#define YYUSE(E) ((void) (E))

// Enable debugging if requested.
#if YYDEBUG

// A pseudo ostream that takes yydebug_ into account.
# define YYCDEBUG if (yydebug_) (*yycdebug_)

# define YY_SYMBOL_PRINT(Title, Symbol)         \
  do {                                          \
    if (yydebug_)                               \
    {                                           \
      *yycdebug_ << Title << ' ';               \
      yy_print_ (*yycdebug_, Symbol);           \
      *yycdebug_ << std::endl;                  \
    }                                           \
  } while (false)

# define YY_REDUCE_PRINT(Rule)          \
  do {                                  \
    if (yydebug_)                       \
      yy_reduce_print_ (Rule);          \
  } while (false)

# define YY_STACK_PRINT()               \
  do {                                  \
    if (yydebug_)                       \
      yystack_print_ ();                \
  } while (false)

#else // !YYDEBUG

# define YYCDEBUG if (false) std::cerr
# define YY_SYMBOL_PRINT(Title, Symbol)  YYUSE(Symbol)
# define YY_REDUCE_PRINT(Rule)           static_cast<void>(0)
# define YY_STACK_PRINT()                static_cast<void>(0)

#endif // !YYDEBUG

#define yyerrok         (yyerrstatus_ = 0)
#define yyclearin       (yyla.clear ())

#define YYACCEPT        goto yyacceptlab
#define YYABORT         goto yyabortlab
#define YYERROR         goto yyerrorlab
#define YYRECOVERING()  (!!yyerrstatus_)


namespace yy {
#line 155 "dummyg.cpp" // lalr1.cc:479

  /* Return YYSTR after stripping away unnecessary quotes and
     backslashes, so that it's suitable for yyerror.  The heuristic is
     that double-quoting is unnecessary unless the string contains an
     apostrophe, a comma, or backslash (other than backslash-backslash).
     YYSTR is taken from yytname.  */
  std::string
   mlaskal_parser ::yytnamerr_ (const char *yystr)
  {
    if (*yystr == '"')
      {
        std::string yyr = "";
        char const *yyp = yystr;

        for (;;)
          switch (*++yyp)
            {
            case '\'':
            case ',':
              goto do_not_strip_quotes;

            case '\\':
              if (*++yyp != '\\')
                goto do_not_strip_quotes;
              // Fall through.
            default:
              yyr += *yyp;
              break;

            case '"':
              return yyr;
            }
      do_not_strip_quotes: ;
      }

    return yystr;
  }


  /// Build a parser object.
   mlaskal_parser :: mlaskal_parser  (mlc::yyscan_t2 yyscanner_yyarg, mlc::MlaskalCtx* ctx_yyarg)
    :
#if YYDEBUG
      yydebug_ (false),
      yycdebug_ (&std::cerr),
#endif
      yyscanner (yyscanner_yyarg),
      ctx (ctx_yyarg)
  {}

   mlaskal_parser ::~ mlaskal_parser  ()
  {}


  /*---------------.
  | Symbol types.  |
  `---------------*/



  // by_state.
  inline
   mlaskal_parser ::by_state::by_state ()
    : state (empty_state)
  {}

  inline
   mlaskal_parser ::by_state::by_state (const by_state& other)
    : state (other.state)
  {}

  inline
  void
   mlaskal_parser ::by_state::clear ()
  {
    state = empty_state;
  }

  inline
  void
   mlaskal_parser ::by_state::move (by_state& that)
  {
    state = that.state;
    that.clear ();
  }

  inline
   mlaskal_parser ::by_state::by_state (state_type s)
    : state (s)
  {}

  inline
   mlaskal_parser ::symbol_number_type
   mlaskal_parser ::by_state::type_get () const
  {
    if (state == empty_state)
      return empty_symbol;
    else
      return yystos_[state];
  }

  inline
   mlaskal_parser ::stack_symbol_type::stack_symbol_type ()
  {}


  inline
   mlaskal_parser ::stack_symbol_type::stack_symbol_type (state_type s, symbol_type& that)
    : super_type (s, that.location)
  {
      switch (that.type_get ())
    {
      case 44: // FOR_DIRECTION
        value.move< mlc::DUTOKGE_FOR_DIRECTION > (that.value);
        break;

      case 43: // OPER_MUL
        value.move< mlc::DUTOKGE_OPER_MUL > (that.value);
        break;

      case 41: // OPER_REL
        value.move< mlc::DUTOKGE_OPER_REL > (that.value);
        break;

      case 42: // OPER_SIGNADD
        value.move< mlc::DUTOKGE_OPER_SIGNADD > (that.value);
        break;

      case 26: // IDENTIFIER
        value.move< mlc::ls_id_index > (that.value);
        break;

      case 27: // UINT
        value.move< mlc::ls_int_index > (that.value);
        break;

      case 28: // REAL
        value.move< mlc::ls_real_index > (that.value);
        break;

      case 29: // STRING
        value.move< mlc::ls_str_index > (that.value);
        break;

      case 51: // token_i
        value.move< mlc::token_attr_i > (that.value);
        break;

      case 49: // token_n
        value.move< mlc::token_attr_n > (that.value);
        break;

      case 52: // token_r
        value.move< mlc::token_attr_r > (that.value);
        break;

      case 50: // token_s
        value.move< mlc::token_attr_s > (that.value);
        break;

      default:
        break;
    }

    // that is emptied.
    that.type = empty_symbol;
  }

  inline
   mlaskal_parser ::stack_symbol_type&
   mlaskal_parser ::stack_symbol_type::operator= (const stack_symbol_type& that)
  {
    state = that.state;
      switch (that.type_get ())
    {
      case 44: // FOR_DIRECTION
        value.copy< mlc::DUTOKGE_FOR_DIRECTION > (that.value);
        break;

      case 43: // OPER_MUL
        value.copy< mlc::DUTOKGE_OPER_MUL > (that.value);
        break;

      case 41: // OPER_REL
        value.copy< mlc::DUTOKGE_OPER_REL > (that.value);
        break;

      case 42: // OPER_SIGNADD
        value.copy< mlc::DUTOKGE_OPER_SIGNADD > (that.value);
        break;

      case 26: // IDENTIFIER
        value.copy< mlc::ls_id_index > (that.value);
        break;

      case 27: // UINT
        value.copy< mlc::ls_int_index > (that.value);
        break;

      case 28: // REAL
        value.copy< mlc::ls_real_index > (that.value);
        break;

      case 29: // STRING
        value.copy< mlc::ls_str_index > (that.value);
        break;

      case 51: // token_i
        value.copy< mlc::token_attr_i > (that.value);
        break;

      case 49: // token_n
        value.copy< mlc::token_attr_n > (that.value);
        break;

      case 52: // token_r
        value.copy< mlc::token_attr_r > (that.value);
        break;

      case 50: // token_s
        value.copy< mlc::token_attr_s > (that.value);
        break;

      default:
        break;
    }

    location = that.location;
    return *this;
  }


  template <typename Base>
  inline
  void
   mlaskal_parser ::yy_destroy_ (const char* yymsg, basic_symbol<Base>& yysym) const
  {
    if (yymsg)
      YY_SYMBOL_PRINT (yymsg, yysym);
  }

#if YYDEBUG
  template <typename Base>
  void
   mlaskal_parser ::yy_print_ (std::ostream& yyo,
                                     const basic_symbol<Base>& yysym) const
  {
    std::ostream& yyoutput = yyo;
    YYUSE (yyoutput);
    symbol_number_type yytype = yysym.type_get ();
    // Avoid a (spurious) G++ 4.8 warning about "array subscript is
    // below array bounds".
    if (yysym.empty ())
      std::abort ();
    yyo << (yytype < yyntokens_ ? "token" : "nterm")
        << ' ' << yytname_[yytype] << " ("
        << yysym.location << ": ";
    YYUSE (yytype);
    yyo << ')';
  }
#endif

  inline
  void
   mlaskal_parser ::yypush_ (const char* m, state_type s, symbol_type& sym)
  {
    stack_symbol_type t (s, sym);
    yypush_ (m, t);
  }

  inline
  void
   mlaskal_parser ::yypush_ (const char* m, stack_symbol_type& s)
  {
    if (m)
      YY_SYMBOL_PRINT (m, s);
    yystack_.push (s);
  }

  inline
  void
   mlaskal_parser ::yypop_ (unsigned int n)
  {
    yystack_.pop (n);
  }

#if YYDEBUG
  std::ostream&
   mlaskal_parser ::debug_stream () const
  {
    return *yycdebug_;
  }

  void
   mlaskal_parser ::set_debug_stream (std::ostream& o)
  {
    yycdebug_ = &o;
  }


   mlaskal_parser ::debug_level_type
   mlaskal_parser ::debug_level () const
  {
    return yydebug_;
  }

  void
   mlaskal_parser ::set_debug_level (debug_level_type l)
  {
    yydebug_ = l;
  }
#endif // YYDEBUG

  inline  mlaskal_parser ::state_type
   mlaskal_parser ::yy_lr_goto_state_ (state_type yystate, int yysym)
  {
    int yyr = yypgoto_[yysym - yyntokens_] + yystate;
    if (0 <= yyr && yyr <= yylast_ && yycheck_[yyr] == yystate)
      return yytable_[yyr];
    else
      return yydefgoto_[yysym - yyntokens_];
  }

  inline bool
   mlaskal_parser ::yy_pact_value_is_default_ (int yyvalue)
  {
    return yyvalue == yypact_ninf_;
  }

  inline bool
   mlaskal_parser ::yy_table_value_is_error_ (int yyvalue)
  {
    return yyvalue == yytable_ninf_;
  }

  int
   mlaskal_parser ::parse ()
  {
    // State.
    int yyn;
    /// Length of the RHS of the rule being reduced.
    int yylen = 0;

    // Error handling.
    int yynerrs_ = 0;
    int yyerrstatus_ = 0;

    /// The lookahead symbol.
    symbol_type yyla;

    /// The locations where the error started and ended.
    stack_symbol_type yyerror_range[3];

    /// The return value of parse ().
    int yyresult;

    // FIXME: This shoud be completely indented.  It is not yet to
    // avoid gratuitous conflicts when merging into the master branch.
    try
      {
    YYCDEBUG << "Starting parse" << std::endl;


    /* Initialize the stack.  The initial state will be set in
       yynewstate, since the latter expects the semantical and the
       location values to have been already stored, initialize these
       stacks with a primary value.  */
    yystack_.clear ();
    yypush_ (YY_NULLPTR, 0, yyla);

    // A new symbol was pushed on the stack.
  yynewstate:
    YYCDEBUG << "Entering state " << yystack_[0].state << std::endl;

    // Accept?
    if (yystack_[0].state == yyfinal_)
      goto yyacceptlab;

    goto yybackup;

    // Backup.
  yybackup:

    // Try to take a decision without lookahead.
    yyn = yypact_[yystack_[0].state];
    if (yy_pact_value_is_default_ (yyn))
      goto yydefault;

    // Read a lookahead token.
    if (yyla.empty ())
      {
        YYCDEBUG << "Reading a token: ";
        try
          {
            symbol_type yylookahead (yylex (yyscanner, ctx));
            yyla.move (yylookahead);
          }
        catch (const syntax_error& yyexc)
          {
            error (yyexc);
            goto yyerrlab1;
          }
      }
    YY_SYMBOL_PRINT ("Next token is", yyla);

    /* If the proper action on seeing token YYLA.TYPE is to reduce or
       to detect an error, take that action.  */
    yyn += yyla.type_get ();
    if (yyn < 0 || yylast_ < yyn || yycheck_[yyn] != yyla.type_get ())
      goto yydefault;

    // Reduce or error.
    yyn = yytable_[yyn];
    if (yyn <= 0)
      {
        if (yy_table_value_is_error_ (yyn))
          goto yyerrlab;
        yyn = -yyn;
        goto yyreduce;
      }

    // Count tokens shifted since error; after three, turn off error status.
    if (yyerrstatus_)
      --yyerrstatus_;

    // Shift the lookahead token.
    yypush_ ("Shifting", yyn, yyla);
    goto yynewstate;

  /*-----------------------------------------------------------.
  | yydefault -- do the default action for the current state.  |
  `-----------------------------------------------------------*/
  yydefault:
    yyn = yydefact_[yystack_[0].state];
    if (yyn == 0)
      goto yyerrlab;
    goto yyreduce;

  /*-----------------------------.
  | yyreduce -- Do a reduction.  |
  `-----------------------------*/
  yyreduce:
    yylen = yyr2_[yyn];
    {
      stack_symbol_type yylhs;
      yylhs.state = yy_lr_goto_state_(yystack_[yylen].state, yyr1_[yyn]);
      /* Variants are always initialized to an empty instance of the
         correct type. The default '$$ = $1' action is NOT applied
         when using variants.  */
        switch (yyr1_[yyn])
    {
      case 44: // FOR_DIRECTION
        yylhs.value.build< mlc::DUTOKGE_FOR_DIRECTION > ();
        break;

      case 43: // OPER_MUL
        yylhs.value.build< mlc::DUTOKGE_OPER_MUL > ();
        break;

      case 41: // OPER_REL
        yylhs.value.build< mlc::DUTOKGE_OPER_REL > ();
        break;

      case 42: // OPER_SIGNADD
        yylhs.value.build< mlc::DUTOKGE_OPER_SIGNADD > ();
        break;

      case 26: // IDENTIFIER
        yylhs.value.build< mlc::ls_id_index > ();
        break;

      case 27: // UINT
        yylhs.value.build< mlc::ls_int_index > ();
        break;

      case 28: // REAL
        yylhs.value.build< mlc::ls_real_index > ();
        break;

      case 29: // STRING
        yylhs.value.build< mlc::ls_str_index > ();
        break;

      case 51: // token_i
        yylhs.value.build< mlc::token_attr_i > ();
        break;

      case 49: // token_n
        yylhs.value.build< mlc::token_attr_n > ();
        break;

      case 52: // token_r
        yylhs.value.build< mlc::token_attr_r > ();
        break;

      case 50: // token_s
        yylhs.value.build< mlc::token_attr_s > ();
        break;

      default:
        break;
    }


      // Compute the default @$.
      {
        slice<stack_symbol_type, stack_type> slice (yystack_, yylen);
        YYLLOC_DEFAULT (yylhs.location, slice, yylen);
      }

      // Perform the reduction.
      YY_REDUCE_PRINT (yyn);
      try
        {
          switch (yyn)
            {
  case 5:
#line 120 "D:\\bednarek\\@SVN\\mlaskal\\public-ro\\mlc\\src\\dummyg.y" // lalr1.cc:859
    { 
		if (yystack_[0].location)
		{
			std::cout << yystack_[0].location << ": ";
		}
		std::cout << yystack_[0].value.as< mlc::token_attr_n > () << std::endl; 
	}
#line 681 "dummyg.cpp" // lalr1.cc:859
    break;

  case 6:
#line 127 "D:\\bednarek\\@SVN\\mlaskal\\public-ro\\mlc\\src\\dummyg.y" // lalr1.cc:859
    {
		if (yystack_[0].location)
		{
			std::cout << yystack_[0].location << ": ";
		}
		std::cout << yystack_[0].value.as< mlc::token_attr_s > ().first;
		if (!yystack_[0].value.as< mlc::token_attr_s > ().second.empty())
		{
			std::cout << " " << yystack_[0].value.as< mlc::token_attr_s > ().second;
		}
		std::cout << std::endl;
	}
#line 698 "dummyg.cpp" // lalr1.cc:859
    break;

  case 7:
#line 139 "D:\\bednarek\\@SVN\\mlaskal\\public-ro\\mlc\\src\\dummyg.y" // lalr1.cc:859
    {
		if (yystack_[0].location)
		{
			std::cout << yystack_[0].location << ": ";
		}
		std::cout << yystack_[0].value.as< mlc::token_attr_i > ().first << " " << yystack_[0].value.as< mlc::token_attr_i > ().second << std::endl;
	}
#line 710 "dummyg.cpp" // lalr1.cc:859
    break;

  case 8:
#line 146 "D:\\bednarek\\@SVN\\mlaskal\\public-ro\\mlc\\src\\dummyg.y" // lalr1.cc:859
    {
		if (yystack_[0].location)
		{
			std::cout << yystack_[0].location << ": ";
		}
		std::cout << yystack_[0].value.as< mlc::token_attr_r > ().first << " " << yystack_[0].value.as< mlc::token_attr_r > ().second << std::endl;
	}
#line 722 "dummyg.cpp" // lalr1.cc:859
    break;

  case 9:
#line 156 "D:\\bednarek\\@SVN\\mlaskal\\public-ro\\mlc\\src\\dummyg.y" // lalr1.cc:859
    { yylhs.value.as< mlc::token_attr_n > () = "program"; }
#line 728 "dummyg.cpp" // lalr1.cc:859
    break;

  case 10:
#line 157 "D:\\bednarek\\@SVN\\mlaskal\\public-ro\\mlc\\src\\dummyg.y" // lalr1.cc:859
    { yylhs.value.as< mlc::token_attr_n > () = "label"; }
#line 734 "dummyg.cpp" // lalr1.cc:859
    break;

  case 11:
#line 158 "D:\\bednarek\\@SVN\\mlaskal\\public-ro\\mlc\\src\\dummyg.y" // lalr1.cc:859
    { yylhs.value.as< mlc::token_attr_n > () = "const"; }
#line 740 "dummyg.cpp" // lalr1.cc:859
    break;

  case 12:
#line 159 "D:\\bednarek\\@SVN\\mlaskal\\public-ro\\mlc\\src\\dummyg.y" // lalr1.cc:859
    { yylhs.value.as< mlc::token_attr_n > () = "type"; }
#line 746 "dummyg.cpp" // lalr1.cc:859
    break;

  case 13:
#line 160 "D:\\bednarek\\@SVN\\mlaskal\\public-ro\\mlc\\src\\dummyg.y" // lalr1.cc:859
    { yylhs.value.as< mlc::token_attr_n > () = "var"; }
#line 752 "dummyg.cpp" // lalr1.cc:859
    break;

  case 14:
#line 161 "D:\\bednarek\\@SVN\\mlaskal\\public-ro\\mlc\\src\\dummyg.y" // lalr1.cc:859
    { yylhs.value.as< mlc::token_attr_n > () = "begin"; }
#line 758 "dummyg.cpp" // lalr1.cc:859
    break;

  case 15:
#line 162 "D:\\bednarek\\@SVN\\mlaskal\\public-ro\\mlc\\src\\dummyg.y" // lalr1.cc:859
    { yylhs.value.as< mlc::token_attr_n > () = "end"; }
#line 764 "dummyg.cpp" // lalr1.cc:859
    break;

  case 16:
#line 163 "D:\\bednarek\\@SVN\\mlaskal\\public-ro\\mlc\\src\\dummyg.y" // lalr1.cc:859
    { yylhs.value.as< mlc::token_attr_n > () = "procedure"; }
#line 770 "dummyg.cpp" // lalr1.cc:859
    break;

  case 17:
#line 164 "D:\\bednarek\\@SVN\\mlaskal\\public-ro\\mlc\\src\\dummyg.y" // lalr1.cc:859
    { yylhs.value.as< mlc::token_attr_n > () = "function"; }
#line 776 "dummyg.cpp" // lalr1.cc:859
    break;

  case 18:
#line 165 "D:\\bednarek\\@SVN\\mlaskal\\public-ro\\mlc\\src\\dummyg.y" // lalr1.cc:859
    { yylhs.value.as< mlc::token_attr_n > () = "array"; }
#line 782 "dummyg.cpp" // lalr1.cc:859
    break;

  case 19:
#line 166 "D:\\bednarek\\@SVN\\mlaskal\\public-ro\\mlc\\src\\dummyg.y" // lalr1.cc:859
    { yylhs.value.as< mlc::token_attr_n > () = "of"; }
#line 788 "dummyg.cpp" // lalr1.cc:859
    break;

  case 20:
#line 167 "D:\\bednarek\\@SVN\\mlaskal\\public-ro\\mlc\\src\\dummyg.y" // lalr1.cc:859
    { yylhs.value.as< mlc::token_attr_n > () = "goto"; }
#line 794 "dummyg.cpp" // lalr1.cc:859
    break;

  case 21:
#line 168 "D:\\bednarek\\@SVN\\mlaskal\\public-ro\\mlc\\src\\dummyg.y" // lalr1.cc:859
    { yylhs.value.as< mlc::token_attr_n > () = "if"; }
#line 800 "dummyg.cpp" // lalr1.cc:859
    break;

  case 22:
#line 169 "D:\\bednarek\\@SVN\\mlaskal\\public-ro\\mlc\\src\\dummyg.y" // lalr1.cc:859
    { yylhs.value.as< mlc::token_attr_n > () = "then"; }
#line 806 "dummyg.cpp" // lalr1.cc:859
    break;

  case 23:
#line 170 "D:\\bednarek\\@SVN\\mlaskal\\public-ro\\mlc\\src\\dummyg.y" // lalr1.cc:859
    { yylhs.value.as< mlc::token_attr_n > () = "else"; }
#line 812 "dummyg.cpp" // lalr1.cc:859
    break;

  case 24:
#line 171 "D:\\bednarek\\@SVN\\mlaskal\\public-ro\\mlc\\src\\dummyg.y" // lalr1.cc:859
    { yylhs.value.as< mlc::token_attr_n > () = "while"; }
#line 818 "dummyg.cpp" // lalr1.cc:859
    break;

  case 25:
#line 172 "D:\\bednarek\\@SVN\\mlaskal\\public-ro\\mlc\\src\\dummyg.y" // lalr1.cc:859
    { yylhs.value.as< mlc::token_attr_n > () = "do"; }
#line 824 "dummyg.cpp" // lalr1.cc:859
    break;

  case 26:
#line 173 "D:\\bednarek\\@SVN\\mlaskal\\public-ro\\mlc\\src\\dummyg.y" // lalr1.cc:859
    { yylhs.value.as< mlc::token_attr_n > () = "repeat"; }
#line 830 "dummyg.cpp" // lalr1.cc:859
    break;

  case 27:
#line 174 "D:\\bednarek\\@SVN\\mlaskal\\public-ro\\mlc\\src\\dummyg.y" // lalr1.cc:859
    { yylhs.value.as< mlc::token_attr_n > () = "until"; }
#line 836 "dummyg.cpp" // lalr1.cc:859
    break;

  case 28:
#line 175 "D:\\bednarek\\@SVN\\mlaskal\\public-ro\\mlc\\src\\dummyg.y" // lalr1.cc:859
    { yylhs.value.as< mlc::token_attr_n > () = "for"; }
#line 842 "dummyg.cpp" // lalr1.cc:859
    break;

  case 29:
#line 176 "D:\\bednarek\\@SVN\\mlaskal\\public-ro\\mlc\\src\\dummyg.y" // lalr1.cc:859
    { yylhs.value.as< mlc::token_attr_n > () = "or"; }
#line 848 "dummyg.cpp" // lalr1.cc:859
    break;

  case 30:
#line 177 "D:\\bednarek\\@SVN\\mlaskal\\public-ro\\mlc\\src\\dummyg.y" // lalr1.cc:859
    { yylhs.value.as< mlc::token_attr_n > () = "not"; }
#line 854 "dummyg.cpp" // lalr1.cc:859
    break;

  case 31:
#line 178 "D:\\bednarek\\@SVN\\mlaskal\\public-ro\\mlc\\src\\dummyg.y" // lalr1.cc:859
    { yylhs.value.as< mlc::token_attr_n > () = "record"; }
#line 860 "dummyg.cpp" // lalr1.cc:859
    break;

  case 32:
#line 179 "D:\\bednarek\\@SVN\\mlaskal\\public-ro\\mlc\\src\\dummyg.y" // lalr1.cc:859
    { yylhs.value.as< mlc::token_attr_n > () = ";"; }
#line 866 "dummyg.cpp" // lalr1.cc:859
    break;

  case 33:
#line 180 "D:\\bednarek\\@SVN\\mlaskal\\public-ro\\mlc\\src\\dummyg.y" // lalr1.cc:859
    { yylhs.value.as< mlc::token_attr_n > () = "."; }
#line 872 "dummyg.cpp" // lalr1.cc:859
    break;

  case 34:
#line 181 "D:\\bednarek\\@SVN\\mlaskal\\public-ro\\mlc\\src\\dummyg.y" // lalr1.cc:859
    { yylhs.value.as< mlc::token_attr_n > () = ","; }
#line 878 "dummyg.cpp" // lalr1.cc:859
    break;

  case 35:
#line 182 "D:\\bednarek\\@SVN\\mlaskal\\public-ro\\mlc\\src\\dummyg.y" // lalr1.cc:859
    { yylhs.value.as< mlc::token_attr_n > () = "="; }
#line 884 "dummyg.cpp" // lalr1.cc:859
    break;

  case 36:
#line 183 "D:\\bednarek\\@SVN\\mlaskal\\public-ro\\mlc\\src\\dummyg.y" // lalr1.cc:859
    { yylhs.value.as< mlc::token_attr_n > () = ":"; }
#line 890 "dummyg.cpp" // lalr1.cc:859
    break;

  case 37:
#line 184 "D:\\bednarek\\@SVN\\mlaskal\\public-ro\\mlc\\src\\dummyg.y" // lalr1.cc:859
    { yylhs.value.as< mlc::token_attr_n > () = "("; }
#line 896 "dummyg.cpp" // lalr1.cc:859
    break;

  case 38:
#line 185 "D:\\bednarek\\@SVN\\mlaskal\\public-ro\\mlc\\src\\dummyg.y" // lalr1.cc:859
    { yylhs.value.as< mlc::token_attr_n > () = ")"; }
#line 902 "dummyg.cpp" // lalr1.cc:859
    break;

  case 39:
#line 186 "D:\\bednarek\\@SVN\\mlaskal\\public-ro\\mlc\\src\\dummyg.y" // lalr1.cc:859
    { yylhs.value.as< mlc::token_attr_n > () = ".."; }
#line 908 "dummyg.cpp" // lalr1.cc:859
    break;

  case 40:
#line 187 "D:\\bednarek\\@SVN\\mlaskal\\public-ro\\mlc\\src\\dummyg.y" // lalr1.cc:859
    { yylhs.value.as< mlc::token_attr_n > () = "["; }
#line 914 "dummyg.cpp" // lalr1.cc:859
    break;

  case 41:
#line 188 "D:\\bednarek\\@SVN\\mlaskal\\public-ro\\mlc\\src\\dummyg.y" // lalr1.cc:859
    { yylhs.value.as< mlc::token_attr_n > () = "]"; }
#line 920 "dummyg.cpp" // lalr1.cc:859
    break;

  case 42:
#line 189 "D:\\bednarek\\@SVN\\mlaskal\\public-ro\\mlc\\src\\dummyg.y" // lalr1.cc:859
    { yylhs.value.as< mlc::token_attr_n > () = ":="; }
#line 926 "dummyg.cpp" // lalr1.cc:859
    break;

  case 43:
#line 193 "D:\\bednarek\\@SVN\\mlaskal\\public-ro\\mlc\\src\\dummyg.y" // lalr1.cc:859
    { 
		yylhs.value.as< mlc::token_attr_s > ().first = "identifier"; 
		yylhs.value.as< mlc::token_attr_s > ().second = !! yystack_[0].value.as< mlc::ls_id_index > () ? "[" + *yystack_[0].value.as< mlc::ls_id_index > () + "]" : ""; 
	}
#line 935 "dummyg.cpp" // lalr1.cc:859
    break;

  case 44:
#line 197 "D:\\bednarek\\@SVN\\mlaskal\\public-ro\\mlc\\src\\dummyg.y" // lalr1.cc:859
    { 
		yylhs.value.as< mlc::token_attr_s > ().first = "string"; 
		yylhs.value.as< mlc::token_attr_s > ().second = !!yystack_[0].value.as< mlc::ls_str_index > () ? "[" + *yystack_[0].value.as< mlc::ls_str_index > () + "]" : "";
	}
#line 944 "dummyg.cpp" // lalr1.cc:859
    break;

  case 45:
#line 201 "D:\\bednarek\\@SVN\\mlaskal\\public-ro\\mlc\\src\\dummyg.y" // lalr1.cc:859
    { 
		yylhs.value.as< mlc::token_attr_s > ().first = "rel oper"; 
		switch (yystack_[0].value.as< mlc::DUTOKGE_OPER_REL > ())
		{
		case DUTOKGE_OPER_REL::DUTOKGE_LT: yylhs.value.as< mlc::token_attr_s > ().second = "<"; break;
		case DUTOKGE_OPER_REL::DUTOKGE_LE: yylhs.value.as< mlc::token_attr_s > ().second = "<="; break;
		case DUTOKGE_OPER_REL::DUTOKGE_NE: yylhs.value.as< mlc::token_attr_s > ().second = "<>"; break;
		case DUTOKGE_OPER_REL::DUTOKGE_GE: yylhs.value.as< mlc::token_attr_s > ().second = ">="; break;
		case DUTOKGE_OPER_REL::DUTOKGE_GT: yylhs.value.as< mlc::token_attr_s > ().second = ">"; break;
		default: yylhs.value.as< mlc::token_attr_s > ().second = "?"; break;
		}
	}
#line 961 "dummyg.cpp" // lalr1.cc:859
    break;

  case 46:
#line 213 "D:\\bednarek\\@SVN\\mlaskal\\public-ro\\mlc\\src\\dummyg.y" // lalr1.cc:859
    { 
		yylhs.value.as< mlc::token_attr_s > ().first = "sign/add oper"; 
		switch (yystack_[0].value.as< mlc::DUTOKGE_OPER_SIGNADD > ())
		{
		case DUTOKGE_OPER_SIGNADD::DUTOKGE_PLUS: yylhs.value.as< mlc::token_attr_s > ().second = "+"; break;
		case DUTOKGE_OPER_SIGNADD::DUTOKGE_MINUS: yylhs.value.as< mlc::token_attr_s > ().second = "-"; break;
		default: yylhs.value.as< mlc::token_attr_s > ().second = "?"; break;
		}
	}
#line 975 "dummyg.cpp" // lalr1.cc:859
    break;

  case 47:
#line 222 "D:\\bednarek\\@SVN\\mlaskal\\public-ro\\mlc\\src\\dummyg.y" // lalr1.cc:859
    { 
		yylhs.value.as< mlc::token_attr_s > ().first = "mul oper"; 
		switch (yystack_[0].value.as< mlc::DUTOKGE_OPER_MUL > ())
		{
		case DUTOKGE_OPER_MUL::DUTOKGE_ASTERISK: yylhs.value.as< mlc::token_attr_s > ().second = "*"; break;
		case DUTOKGE_OPER_MUL::DUTOKGE_SOLIDUS: yylhs.value.as< mlc::token_attr_s > ().second = "/"; break;
		case DUTOKGE_OPER_MUL::DUTOKGE_DIV: yylhs.value.as< mlc::token_attr_s > ().second = "div"; break;
		case DUTOKGE_OPER_MUL::DUTOKGE_MOD: yylhs.value.as< mlc::token_attr_s > ().second = "mod"; break;
		case DUTOKGE_OPER_MUL::DUTOKGE_AND: yylhs.value.as< mlc::token_attr_s > ().second = "and"; break;
		default: yylhs.value.as< mlc::token_attr_s > ().second = "?"; break;
		}
	}
#line 992 "dummyg.cpp" // lalr1.cc:859
    break;

  case 48:
#line 234 "D:\\bednarek\\@SVN\\mlaskal\\public-ro\\mlc\\src\\dummyg.y" // lalr1.cc:859
    { 
		yylhs.value.as< mlc::token_attr_s > ().first = "for direction"; 
		switch (yystack_[0].value.as< mlc::DUTOKGE_FOR_DIRECTION > ())
		{
		case DUTOKGE_FOR_DIRECTION::DUTOKGE_TO: yylhs.value.as< mlc::token_attr_s > ().second = "to"; break;
		case DUTOKGE_FOR_DIRECTION::DUTOKGE_DOWNTO: yylhs.value.as< mlc::token_attr_s > ().second = "downto";  break;
		default: yylhs.value.as< mlc::token_attr_s > ().second = "?"; break;
		}
	}
#line 1006 "dummyg.cpp" // lalr1.cc:859
    break;

  case 49:
#line 246 "D:\\bednarek\\@SVN\\mlaskal\\public-ro\\mlc\\src\\dummyg.y" // lalr1.cc:859
    { yylhs.value.as< mlc::token_attr_i > ().first = "unsigned integer"; yylhs.value.as< mlc::token_attr_i > ().second = !! yystack_[0].value.as< mlc::ls_int_index > () ? *yystack_[0].value.as< mlc::ls_int_index > () : 0; }
#line 1012 "dummyg.cpp" // lalr1.cc:859
    break;

  case 50:
#line 250 "D:\\bednarek\\@SVN\\mlaskal\\public-ro\\mlc\\src\\dummyg.y" // lalr1.cc:859
    { yylhs.value.as< mlc::token_attr_r > ().first = "real number"; yylhs.value.as< mlc::token_attr_r > ().second = !! yystack_[0].value.as< mlc::ls_real_index > () ? * yystack_[0].value.as< mlc::ls_real_index > () : 0.0; }
#line 1018 "dummyg.cpp" // lalr1.cc:859
    break;


#line 1022 "dummyg.cpp" // lalr1.cc:859
            default:
              break;
            }
        }
      catch (const syntax_error& yyexc)
        {
          error (yyexc);
          YYERROR;
        }
      YY_SYMBOL_PRINT ("-> $$ =", yylhs);
      yypop_ (yylen);
      yylen = 0;
      YY_STACK_PRINT ();

      // Shift the result of the reduction.
      yypush_ (YY_NULLPTR, yylhs);
    }
    goto yynewstate;

  /*--------------------------------------.
  | yyerrlab -- here on detecting error.  |
  `--------------------------------------*/
  yyerrlab:
    // If not already recovering from an error, report this error.
    if (!yyerrstatus_)
      {
        ++yynerrs_;
        error (yyla.location, yysyntax_error_ (yystack_[0].state, yyla));
      }


    yyerror_range[1].location = yyla.location;
    if (yyerrstatus_ == 3)
      {
        /* If just tried and failed to reuse lookahead token after an
           error, discard it.  */

        // Return failure if at end of input.
        if (yyla.type_get () == yyeof_)
          YYABORT;
        else if (!yyla.empty ())
          {
            yy_destroy_ ("Error: discarding", yyla);
            yyla.clear ();
          }
      }

    // Else will try to reuse lookahead token after shifting the error token.
    goto yyerrlab1;


  /*---------------------------------------------------.
  | yyerrorlab -- error raised explicitly by YYERROR.  |
  `---------------------------------------------------*/
  yyerrorlab:

    /* Pacify compilers like GCC when the user code never invokes
       YYERROR and the label yyerrorlab therefore never appears in user
       code.  */
    if (false)
      goto yyerrorlab;
    yyerror_range[1].location = yystack_[yylen - 1].location;
    /* Do not reclaim the symbols of the rule whose action triggered
       this YYERROR.  */
    yypop_ (yylen);
    yylen = 0;
    goto yyerrlab1;

  /*-------------------------------------------------------------.
  | yyerrlab1 -- common code for both syntax error and YYERROR.  |
  `-------------------------------------------------------------*/
  yyerrlab1:
    yyerrstatus_ = 3;   // Each real token shifted decrements this.
    {
      stack_symbol_type error_token;
      for (;;)
        {
          yyn = yypact_[yystack_[0].state];
          if (!yy_pact_value_is_default_ (yyn))
            {
              yyn += yyterror_;
              if (0 <= yyn && yyn <= yylast_ && yycheck_[yyn] == yyterror_)
                {
                  yyn = yytable_[yyn];
                  if (0 < yyn)
                    break;
                }
            }

          // Pop the current state because it cannot handle the error token.
          if (yystack_.size () == 1)
            YYABORT;

          yyerror_range[1].location = yystack_[0].location;
          yy_destroy_ ("Error: popping", yystack_[0]);
          yypop_ ();
          YY_STACK_PRINT ();
        }

      yyerror_range[2].location = yyla.location;
      YYLLOC_DEFAULT (error_token.location, yyerror_range, 2);

      // Shift the error token.
      error_token.state = yyn;
      yypush_ ("Shifting", error_token);
    }
    goto yynewstate;

    // Accept.
  yyacceptlab:
    yyresult = 0;
    goto yyreturn;

    // Abort.
  yyabortlab:
    yyresult = 1;
    goto yyreturn;

  yyreturn:
    if (!yyla.empty ())
      yy_destroy_ ("Cleanup: discarding lookahead", yyla);

    /* Do not reclaim the symbols of the rule whose action triggered
       this YYABORT or YYACCEPT.  */
    yypop_ (yylen);
    while (1 < yystack_.size ())
      {
        yy_destroy_ ("Cleanup: popping", yystack_[0]);
        yypop_ ();
      }

    return yyresult;
  }
    catch (...)
      {
        YYCDEBUG << "Exception caught: cleaning lookahead and stack"
                 << std::endl;
        // Do not try to display the values of the reclaimed symbols,
        // as their printer might throw an exception.
        if (!yyla.empty ())
          yy_destroy_ (YY_NULLPTR, yyla);

        while (1 < yystack_.size ())
          {
            yy_destroy_ (YY_NULLPTR, yystack_[0]);
            yypop_ ();
          }
        throw;
      }
  }

  void
   mlaskal_parser ::error (const syntax_error& yyexc)
  {
    error (yyexc.location, yyexc.what());
  }

  // Generate an error message.
  std::string
   mlaskal_parser ::yysyntax_error_ (state_type yystate, const symbol_type& yyla) const
  {
    // Number of reported tokens (one for the "unexpected", one per
    // "expected").
    size_t yycount = 0;
    // Its maximum.
    enum { YYERROR_VERBOSE_ARGS_MAXIMUM = 5 };
    // Arguments of yyformat.
    char const *yyarg[YYERROR_VERBOSE_ARGS_MAXIMUM];

    /* There are many possibilities here to consider:
       - If this state is a consistent state with a default action, then
         the only way this function was invoked is if the default action
         is an error action.  In that case, don't check for expected
         tokens because there are none.
       - The only way there can be no lookahead present (in yyla) is
         if this state is a consistent state with a default action.
         Thus, detecting the absence of a lookahead is sufficient to
         determine that there is no unexpected or expected token to
         report.  In that case, just report a simple "syntax error".
       - Don't assume there isn't a lookahead just because this state is
         a consistent state with a default action.  There might have
         been a previous inconsistent state, consistent state with a
         non-default action, or user semantic action that manipulated
         yyla.  (However, yyla is currently not documented for users.)
       - Of course, the expected token list depends on states to have
         correct lookahead information, and it depends on the parser not
         to perform extra reductions after fetching a lookahead from the
         scanner and before detecting a syntax error.  Thus, state
         merging (from LALR or IELR) and default reductions corrupt the
         expected token list.  However, the list is correct for
         canonical LR with one exception: it will still contain any
         token that will not be accepted due to an error action in a
         later state.
    */
    if (!yyla.empty ())
      {
        int yytoken = yyla.type_get ();
        yyarg[yycount++] = yytname_[yytoken];
        int yyn = yypact_[yystate];
        if (!yy_pact_value_is_default_ (yyn))
          {
            /* Start YYX at -YYN if negative to avoid negative indexes in
               YYCHECK.  In other words, skip the first -YYN actions for
               this state because they are default actions.  */
            int yyxbegin = yyn < 0 ? -yyn : 0;
            // Stay within bounds of both yycheck and yytname.
            int yychecklim = yylast_ - yyn + 1;
            int yyxend = yychecklim < yyntokens_ ? yychecklim : yyntokens_;
            for (int yyx = yyxbegin; yyx < yyxend; ++yyx)
              if (yycheck_[yyx + yyn] == yyx && yyx != yyterror_
                  && !yy_table_value_is_error_ (yytable_[yyx + yyn]))
                {
                  if (yycount == YYERROR_VERBOSE_ARGS_MAXIMUM)
                    {
                      yycount = 1;
                      break;
                    }
                  else
                    yyarg[yycount++] = yytname_[yyx];
                }
          }
      }

    char const* yyformat = YY_NULLPTR;
    switch (yycount)
      {
#define YYCASE_(N, S)                         \
        case N:                               \
          yyformat = S;                       \
        break
        YYCASE_(0, YY_("syntax error"));
        YYCASE_(1, YY_("syntax error, unexpected %s"));
        YYCASE_(2, YY_("syntax error, unexpected %s, expecting %s"));
        YYCASE_(3, YY_("syntax error, unexpected %s, expecting %s or %s"));
        YYCASE_(4, YY_("syntax error, unexpected %s, expecting %s or %s or %s"));
        YYCASE_(5, YY_("syntax error, unexpected %s, expecting %s or %s or %s or %s"));
#undef YYCASE_
      }

    std::string yyres;
    // Argument number.
    size_t yyi = 0;
    for (char const* yyp = yyformat; *yyp; ++yyp)
      if (yyp[0] == '%' && yyp[1] == 's' && yyi < yycount)
        {
          yyres += yytnamerr_ (yyarg[yyi++]);
          ++yyp;
        }
      else
        yyres += *yyp;
    return yyres;
  }


  const signed char  mlaskal_parser ::yypact_ninf_ = -4;

  const signed char  mlaskal_parser ::yytable_ninf_ = -1;

  const signed char
   mlaskal_parser ::yypact_[] =
  {
      -4,    42,    -3,    -4,    -4,    -4,    -4,    -4,    -4,    -4,
      -4,    -4,    -4,    -4,    -4,    -4,    -4,    -4,    -4,    -4,
      -4,    -4,    -4,    -4,    -4,    -4,    -4,    -4,    -4,    -4,
      -4,    -4,    -4,    -4,    -4,    -4,    -4,    -4,    -4,    -4,
      -4,    -4,    -4,    -4,    -4,    -4,    -4,    -4,    -4,    -4,
      -4
  };

  const unsigned char
   mlaskal_parser ::yydefact_[] =
  {
       4,     0,     2,     1,     9,    10,    11,    12,    13,    14,
      15,    16,    17,    18,    19,    20,    21,    22,    23,    24,
      25,    26,    27,    28,    29,    30,    31,    43,    49,    50,
      44,    32,    33,    34,    35,    36,    37,    38,    39,    40,
      41,    42,    45,    46,    47,    48,     3,     5,     6,     7,
       8
  };

  const signed char
   mlaskal_parser ::yypgoto_[] =
  {
      -4,    -4,    -4,    -4,    -4,    -4,    -4,    -4
  };

  const signed char
   mlaskal_parser ::yydefgoto_[] =
  {
      -1,     1,     2,    46,    47,    48,    49,    50
  };

  const unsigned char
   mlaskal_parser ::yytable_[] =
  {
       4,     5,     6,     7,     8,     9,    10,    11,    12,    13,
      14,    15,    16,    17,    18,    19,    20,    21,    22,    23,
      24,    25,    26,    27,    28,    29,    30,    31,    32,    33,
      34,    35,    36,    37,    38,    39,    40,    41,    42,    43,
      44,    45,     3
  };

  const unsigned char
   mlaskal_parser ::yycheck_[] =
  {
       3,     4,     5,     6,     7,     8,     9,    10,    11,    12,
      13,    14,    15,    16,    17,    18,    19,    20,    21,    22,
      23,    24,    25,    26,    27,    28,    29,    30,    31,    32,
      33,    34,    35,    36,    37,    38,    39,    40,    41,    42,
      43,    44,     0
  };

  const unsigned char
   mlaskal_parser ::yystos_[] =
  {
       0,    46,    47,     0,     3,     4,     5,     6,     7,     8,
       9,    10,    11,    12,    13,    14,    15,    16,    17,    18,
      19,    20,    21,    22,    23,    24,    25,    26,    27,    28,
      29,    30,    31,    32,    33,    34,    35,    36,    37,    38,
      39,    40,    41,    42,    43,    44,    48,    49,    50,    51,
      52
  };

  const unsigned char
   mlaskal_parser ::yyr1_[] =
  {
       0,    45,    46,    47,    47,    48,    48,    48,    48,    49,
      49,    49,    49,    49,    49,    49,    49,    49,    49,    49,
      49,    49,    49,    49,    49,    49,    49,    49,    49,    49,
      49,    49,    49,    49,    49,    49,    49,    49,    49,    49,
      49,    49,    49,    50,    50,    50,    50,    50,    50,    51,
      52
  };

  const unsigned char
   mlaskal_parser ::yyr2_[] =
  {
       0,     2,     1,     2,     0,     1,     1,     1,     1,     1,
       1,     1,     1,     1,     1,     1,     1,     1,     1,     1,
       1,     1,     1,     1,     1,     1,     1,     1,     1,     1,
       1,     1,     1,     1,     1,     1,     1,     1,     1,     1,
       1,     1,     1,     1,     1,     1,     1,     1,     1,     1,
       1
  };



  // YYTNAME[SYMBOL-NUM] -- String name of the symbol SYMBOL-NUM.
  // First, the terminals, then, starting at \a yyntokens_, nonterminals.
  const char*
  const  mlaskal_parser ::yytname_[] =
  {
  "\"end of file\"", "error", "$undefined", "PROGRAM", "LABEL", "CONST",
  "TYPE", "VAR", "BEGIN", "END", "PROCEDURE", "FUNCTION", "ARRAY", "OF",
  "GOTO", "IF", "THEN", "ELSE", "WHILE", "DO", "REPEAT", "UNTIL", "FOR",
  "OR", "NOT", "RECORD", "IDENTIFIER", "UINT", "REAL", "STRING",
  "SEMICOLON", "DOT", "COMMA", "EQ", "COLON", "LPAR", "RPAR", "DOTDOT",
  "LSBRA", "RSBRA", "ASSIGN", "OPER_REL", "OPER_SIGNADD", "OPER_MUL",
  "FOR_DIRECTION", "$accept", "mlaskal", "tokens", "token", "token_n",
  "token_s", "token_i", "token_r", YY_NULLPTR
  };

#if YYDEBUG
  const unsigned char
   mlaskal_parser ::yyrline_[] =
  {
       0,   113,   113,   116,   117,   120,   127,   139,   146,   156,
     157,   158,   159,   160,   161,   162,   163,   164,   165,   166,
     167,   168,   169,   170,   171,   172,   173,   174,   175,   176,
     177,   178,   179,   180,   181,   182,   183,   184,   185,   186,
     187,   188,   189,   193,   197,   201,   213,   222,   234,   246,
     250
  };

  // Print the state stack on the debug stream.
  void
   mlaskal_parser ::yystack_print_ ()
  {
    *yycdebug_ << "Stack now";
    for (stack_type::const_iterator
           i = yystack_.begin (),
           i_end = yystack_.end ();
         i != i_end; ++i)
      *yycdebug_ << ' ' << i->state;
    *yycdebug_ << std::endl;
  }

  // Report on the debug stream that the rule \a yyrule is going to be reduced.
  void
   mlaskal_parser ::yy_reduce_print_ (int yyrule)
  {
    unsigned int yylno = yyrline_[yyrule];
    int yynrhs = yyr2_[yyrule];
    // Print the symbols being reduced, and their result.
    *yycdebug_ << "Reducing stack by rule " << yyrule - 1
               << " (line " << yylno << "):" << std::endl;
    // The symbols being reduced.
    for (int yyi = 0; yyi < yynrhs; yyi++)
      YY_SYMBOL_PRINT ("   $" << yyi + 1 << " =",
                       yystack_[(yynrhs) - (yyi + 1)]);
  }
#endif // YYDEBUG



} // yy
#line 1429 "dummyg.cpp" // lalr1.cc:1167
#line 253 "D:\\bednarek\\@SVN\\mlaskal\\public-ro\\mlc\\src\\dummyg.y" // lalr1.cc:1168


namespace yy {

	void mlaskal_parser::error(const location_type& l, const std::string& m)
	{
		message(DUERR_SYNTAX, l, m);
	}

}

