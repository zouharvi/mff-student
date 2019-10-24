#ifndef GUARD_MLASKAL_ICM_VAL_H_
#define GUARD_MLASKAL_ICM_VAL_H_

/*

	icm_val.hpp

	ICM "any" value

	Kuba, 2006

*/

#include <iostream>

#include "icm_types.hpp"
#include "icexcept.hpp"

namespace mlaskal {

	enum icm_val_type {
		ICVT_NOTHING,
		ICVT_BOOL,
		ICVT_INT,
		ICVT_REAL,
		ICVT_STRING,
		ICVT_RA,
		ICVT_PTR,
		ICVT_ICIP
	};

	class icm_val {
	protected:
		icm_val(icm_val_type type, bool uninit) : uninit_(uninit),type_(type) { }
	public:
		virtual ~icm_val() { }

		icm_val_type get_type() const { return type_; }

		virtual void print(std::ostream &os) const =0;
		virtual ICMT_BOOL getBOOL(ICMT_ICIP icip) const =0;
		virtual ICMT_INT getINT(ICMT_ICIP icip) const =0;
		virtual ICMT_REAL getREAL(ICMT_ICIP icip) const =0;
		virtual ICMT_STRING getSTRING(ICMT_ICIP icip) const =0;
		virtual ICMT_RA getRA(ICMT_ICIP icip) const =0;
		virtual ICMT_PTR getPTR(ICMT_ICIP icip) const =0;
		virtual ICMT_ICIP getICIP(ICMT_ICIP icip) const =0;

	protected:
		bool				uninit_;
	private:
		icm_val_type		type_;
	};

	namespace icv {

		class NOTHING : public icm_val {
		public:
			NOTHING() : icm_val(ICVT_NOTHING, true) { }

			virtual void print(std::ostream &os) const { os << "NOTHING"; }
			virtual ICMT_BOOL getBOOL(ICMT_ICIP icip) const { throw ic_except(ICET_BAD_VAL_TYPE, icip); }
			virtual ICMT_INT getINT(ICMT_ICIP icip) const { throw ic_except(ICET_BAD_VAL_TYPE, icip); }
			virtual ICMT_REAL getREAL(ICMT_ICIP icip) const { throw ic_except(ICET_BAD_VAL_TYPE, icip); }
			virtual ICMT_STRING getSTRING(ICMT_ICIP icip) const { throw ic_except(ICET_BAD_VAL_TYPE, icip); }
			virtual ICMT_RA getRA(ICMT_ICIP icip) const { throw ic_except(ICET_BAD_VAL_TYPE, icip); }
			virtual ICMT_PTR getPTR(ICMT_ICIP icip) const { throw ic_except(ICET_BAD_VAL_TYPE, icip); }
			virtual ICMT_ICIP getICIP(ICMT_ICIP icip) const { throw ic_except(ICET_BAD_VAL_TYPE, icip); }
		};

		class BOOL : public icm_val {
		public:
			BOOL() : icm_val(ICVT_BOOL, true) { }
			BOOL(ICMT_BOOL b) : icm_val(ICVT_BOOL, false), b_(b) { }

			virtual void print(std::ostream &os) const { os << "BOOL\t"; if(uninit_) os << "unitialized"; else os << b_; }
			virtual ICMT_BOOL getBOOL(ICMT_ICIP icip) const { if(uninit_) throw ic_except(ICET_VAL_UNINIT, icip); return b_; }
			virtual ICMT_INT getINT(ICMT_ICIP icip) const { throw ic_except(ICET_BAD_VAL_TYPE, icip); }
			virtual ICMT_REAL getREAL(ICMT_ICIP icip) const { throw ic_except(ICET_BAD_VAL_TYPE, icip); }
			virtual ICMT_STRING getSTRING(ICMT_ICIP icip) const { throw ic_except(ICET_BAD_VAL_TYPE, icip); }
			virtual ICMT_RA getRA(ICMT_ICIP icip) const { throw ic_except(ICET_BAD_VAL_TYPE, icip); }
			virtual ICMT_PTR getPTR(ICMT_ICIP icip) const { throw ic_except(ICET_BAD_VAL_TYPE, icip); }
			virtual ICMT_ICIP getICIP(ICMT_ICIP icip) const { throw ic_except(ICET_BAD_VAL_TYPE, icip); }
		private:
			ICMT_BOOL b_;
		};

		class INT : public icm_val {
		public:
			INT() : icm_val(ICVT_INT, true) { }
			INT(ICMT_INT i) : icm_val(ICVT_INT, false), i_(i) { }

			virtual void print(std::ostream &os) const { os << "INT\t"; if(uninit_) os << "unitialized"; else os << i_; }
			virtual ICMT_BOOL getBOOL(ICMT_ICIP icip) const { throw ic_except(ICET_BAD_VAL_TYPE, icip); }
			virtual ICMT_INT getINT(ICMT_ICIP icip) const { if(uninit_) throw ic_except(ICET_VAL_UNINIT, icip); return i_; }
			virtual ICMT_REAL getREAL(ICMT_ICIP icip) const { throw ic_except(ICET_BAD_VAL_TYPE, icip); }
			virtual ICMT_STRING getSTRING(ICMT_ICIP icip) const { throw ic_except(ICET_BAD_VAL_TYPE, icip); }
			virtual ICMT_RA getRA(ICMT_ICIP icip) const { throw ic_except(ICET_BAD_VAL_TYPE, icip); }
			virtual ICMT_PTR getPTR(ICMT_ICIP icip) const { throw ic_except(ICET_BAD_VAL_TYPE, icip); }
			virtual ICMT_ICIP getICIP(ICMT_ICIP icip) const { throw ic_except(ICET_BAD_VAL_TYPE, icip); }
		private:
			ICMT_INT i_;
		};

		class REAL : public icm_val {
		public:
			REAL() : icm_val(ICVT_REAL, true) { }
			REAL(ICMT_REAL r) : icm_val(ICVT_REAL, false), r_(r) { }

			virtual void print(std::ostream &os) const { os << "REAL\t"; if(uninit_) os << "unitialized"; else os << r_; }
			virtual ICMT_BOOL getBOOL(ICMT_ICIP icip) const { throw ic_except(ICET_BAD_VAL_TYPE, icip); }
			virtual ICMT_INT getINT(ICMT_ICIP icip) const { throw ic_except(ICET_BAD_VAL_TYPE, icip); }
			virtual ICMT_REAL getREAL(ICMT_ICIP icip) const { if(uninit_) throw ic_except(ICET_VAL_UNINIT, icip); return r_; }
			virtual ICMT_STRING getSTRING(ICMT_ICIP icip) const { throw ic_except(ICET_BAD_VAL_TYPE, icip); }
			virtual ICMT_RA getRA(ICMT_ICIP icip) const { throw ic_except(ICET_BAD_VAL_TYPE, icip); }
			virtual ICMT_PTR getPTR(ICMT_ICIP icip) const { throw ic_except(ICET_BAD_VAL_TYPE, icip); }
			virtual ICMT_ICIP getICIP(ICMT_ICIP icip) const { throw ic_except(ICET_BAD_VAL_TYPE, icip); }
		private:
			ICMT_REAL r_;
		};

		class STRING : public icm_val {
		public:
			STRING() : icm_val(ICVT_STRING, true) { }
			STRING(ICMT_STRING s) : icm_val(ICVT_STRING, false), s_(s) { }

			virtual void print(std::ostream &os) const { os << "STRING\t"; if(uninit_) os << "unitialized"; else os << s_; }
			virtual ICMT_BOOL getBOOL(ICMT_ICIP icip) const { throw ic_except(ICET_BAD_VAL_TYPE, icip); }
			virtual ICMT_INT getINT(ICMT_ICIP icip) const { throw ic_except(ICET_BAD_VAL_TYPE, icip); }
			virtual ICMT_REAL getREAL(ICMT_ICIP icip) const { throw ic_except(ICET_BAD_VAL_TYPE, icip); }
			virtual ICMT_STRING getSTRING(ICMT_ICIP icip) const { if(uninit_) throw ic_except(ICET_VAL_UNINIT, icip); return s_; }
			virtual ICMT_RA getRA(ICMT_ICIP icip) const { throw ic_except(ICET_BAD_VAL_TYPE, icip); }
			virtual ICMT_PTR getPTR(ICMT_ICIP icip) const { throw ic_except(ICET_BAD_VAL_TYPE, icip); }
			virtual ICMT_ICIP getICIP(ICMT_ICIP icip) const { throw ic_except(ICET_BAD_VAL_TYPE, icip); }
		private:
			ICMT_STRING s_;
		};

		class RA : public icm_val {
		public:
			RA() : icm_val(ICVT_RA, true) { }
			RA(const ICMT_RA &ra) : icm_val(ICVT_RA, false), ra_(ra) { }

			virtual void print(std::ostream &os) const { os << "RA\t"; if(uninit_) os << "unitialized"; else os << "RetAddr=" << ra_.ra_ << ", PrevFP=" << ra_.prev_fp_; }
			virtual ICMT_BOOL getBOOL(ICMT_ICIP icip) const { throw ic_except(ICET_BAD_VAL_TYPE, icip); }
			virtual ICMT_INT getINT(ICMT_ICIP icip) const { throw ic_except(ICET_BAD_VAL_TYPE, icip); }
			virtual ICMT_REAL getREAL(ICMT_ICIP icip) const { throw ic_except(ICET_BAD_VAL_TYPE, icip); }
			virtual ICMT_STRING getSTRING(ICMT_ICIP icip) const { throw ic_except(ICET_BAD_VAL_TYPE, icip); }
			virtual ICMT_RA getRA(ICMT_ICIP icip) const { if(uninit_) throw ic_except(ICET_VAL_UNINIT, icip); return ra_; }
			virtual ICMT_PTR getPTR(ICMT_ICIP icip) const { throw ic_except(ICET_BAD_VAL_TYPE, icip); }
			virtual ICMT_ICIP getICIP(ICMT_ICIP icip) const { throw ic_except(ICET_BAD_VAL_TYPE, icip); }
		private:
			ICMT_RA ra_;
		};

		class PTR : public icm_val {
		public:
			PTR() : icm_val(ICVT_PTR, true) { }
			PTR(ICMT_PTR p) : icm_val(ICVT_PTR, false), p_(p) { }

			virtual void print(std::ostream &os) const { os << "PTR\t"; if(uninit_) os << "unitialized"; else os << p_; }
			virtual ICMT_BOOL getBOOL(ICMT_ICIP icip) const { throw ic_except(ICET_BAD_VAL_TYPE, icip); }
			virtual ICMT_INT getINT(ICMT_ICIP icip) const { throw ic_except(ICET_BAD_VAL_TYPE, icip); }
			virtual ICMT_REAL getREAL(ICMT_ICIP icip) const { throw ic_except(ICET_BAD_VAL_TYPE, icip); }
			virtual ICMT_STRING getSTRING(ICMT_ICIP icip) const { throw ic_except(ICET_BAD_VAL_TYPE, icip); }
			virtual ICMT_RA getRA(ICMT_ICIP icip) const { throw ic_except(ICET_BAD_VAL_TYPE, icip); }
			virtual ICMT_PTR getPTR(ICMT_ICIP icip) const { if(uninit_) throw ic_except(ICET_VAL_UNINIT, icip); return p_; }
			virtual ICMT_ICIP getICIP(ICMT_ICIP icip) const { throw ic_except(ICET_BAD_VAL_TYPE, icip); }
		private:
			ICMT_PTR p_;
		};

		class ICIP : public icm_val {
		public:
			ICIP() : icm_val(ICVT_ICIP, true) { }
			ICIP(ICMT_ICIP icip) : icm_val(ICVT_ICIP, false), icip_(icip) { }

			virtual void print(std::ostream &os) const { os << "ICIP\t"; if(uninit_) os << "unitialized"; else os << icip_; }
			virtual ICMT_BOOL getBOOL(ICMT_ICIP icip) const { throw ic_except(ICET_BAD_VAL_TYPE, icip); }
			virtual ICMT_INT getINT(ICMT_ICIP icip) const { throw ic_except(ICET_BAD_VAL_TYPE, icip); }
			virtual ICMT_REAL getREAL(ICMT_ICIP icip) const { throw ic_except(ICET_BAD_VAL_TYPE, icip); }
			virtual ICMT_STRING getSTRING(ICMT_ICIP icip) const { throw ic_except(ICET_BAD_VAL_TYPE, icip); }
			virtual ICMT_RA getRA(ICMT_ICIP icip) const { throw ic_except(ICET_BAD_VAL_TYPE, icip); }
			virtual ICMT_PTR getPTR(ICMT_ICIP icip) const { throw ic_except(ICET_BAD_VAL_TYPE, icip); }
			virtual ICMT_ICIP getICIP(ICMT_ICIP icip) const { if(uninit_) throw ic_except(ICET_VAL_UNINIT, icip); return icip_; }
		private:
			ICMT_ICIP icip_;
		};

	}

}

#endif
