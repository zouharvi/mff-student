/*

	flat_icblock.cpp

	Flat IC block from file

	Kuba, 2006

*/

#include <fstream>
#include <iterator>

#include "flat_icblock.hpp"
#include "file_seq.hpp"
#include "ic_factory.hpp"
#include "ic_instr.hpp"
#include "ic_instrtab.hpp"
#include "abstract_ic.hpp"
#include "labeled_icblock.hpp"

using namespace std;

namespace {

	class ftor_afp2ffp_trans {
	public:
		ftor_afp2ffp_trans(const ::mlaskal::abstract_ic &aic) : aic_(&aic) { }
		::mlaskal::file_function_param operator()(const ::mlaskal::abstract_function_param &afp)
		{
			return ::mlaskal::file_function_param(
										aic_->get_ls_id().compute_index(afp.get_name()),
										afp.get_ptype(),
										afp.get_size(),
										afp.get_stkoffs()
										);
		}
	private:
		const ::mlaskal::abstract_ic *aic_;
	};

	class ftor_afv2ffv_trans {
	public:
		ftor_afv2ffv_trans(
					const ::mlaskal::abstract_ic &aic, 
					const ::mlaskal::abstract_function &af,
					::mlaskal::ICABSNUM stip) 
						: aic_(&aic),af_(&af),stip_(stip) { }
		::mlaskal::file_function_var operator()(const ::mlaskal::abstract_function_var &afv)
		{
			return ::mlaskal::file_function_var(
										aic_->get_ls_id().compute_index(afv.get_name()),
										afv.get_ptype(),
										af_->get_block()->compute_index(afv.get_icip_start())+stip_,
										af_->get_block()->compute_index(afv.get_icip_end())+stip_-1,		// inclusive end at file level - see ftor_afncvar_trans
										afv.get_size(),
										afv.get_stkoffs()
										);
		}
	private:
		const ::mlaskal::abstract_ic *aic_;
		const ::mlaskal::abstract_function *af_;
		::mlaskal::ICABSNUM stip_;
	};

	class ftor_af2ff_trans {
	public:
		ftor_af2ff_trans(const ::mlaskal::abstract_ic &aic) : stip_(0),aic_(&aic) { }
		::mlaskal::file_function operator()(const ::mlaskal::abstract_function &af)
		{
			::mlaskal::ICABSNUM start_ip = stip_;
			::mlaskal::ICABSNUM end_ip = (stip_+=static_cast< ::mlaskal::ICABSNUM>(af.get_block()->size()))-1;

			::mlaskal::file_function_params params;

			transform(af.get_params().begin(), af.get_params().end(), back_inserter(params), ftor_afp2ffp_trans(*aic_));

			::mlaskal::file_function_vars vars;

			transform(af.get_vars().begin(), af.get_vars().end(), back_inserter(vars), ftor_afv2ffv_trans(*aic_, af, start_ip));

			if(af.get_type()==::mlaskal::FNCSIG_FNC)
				return ::mlaskal::file_function(
									::mlaskal::file_function_rv(af.get_rv().get_ptype(), af.get_rv().get_size(), af.get_rv().get_stkoffs()),
									aic_->get_ls_id().compute_index(af.get_name()),
									start_ip,
									end_ip,
									af.get_used_regs(),
									params,
									vars
									);
			else
				return ::mlaskal::file_function(
									af.get_type(),
									aic_->get_ls_id().compute_index(af.get_name()),
									start_ip,
									end_ip,
									af.get_used_regs(),
									params,
									vars
									);
		}
	private:
		::mlaskal::ICABSNUM stip_;
		const ::mlaskal::abstract_ic *aic_;
	};

	struct ftor_ff2ffmap {
		pair< ::mlaskal::ICABSNUM, const ::mlaskal::file_function *> operator()(const ::mlaskal::file_function &ff)
		{
			return make_pair(ff.get_icip_start(), &ff);
		}
	};

	class ftor_aiaf2icff {
	public:
		ftor_aiaf2icff(
				const ::mlaskal::abstract_ic &aic, 
				const ::mlaskal::abstract_function &af,
				const ::mlaskal::flat_icblock &fic
				) : aic_(&aic),af_(&af),fncip_(0),fic_(&fic) { }
		::mlaskal::flat_icblock::plain_icblock_type::value_type operator()(::mlaskal::labeled_icblock::const_reference ai)
		{
			::mlaskal::ICRELNUM n=0;

			switch(ai::ic_instrtab[ai->get_opcode()].stkp_type_)
			{
			case ::mlaskal::ICSPT_NONE:
				break;
			case ::mlaskal::ICSPT_LITINT:
				n = static_cast< ::mlaskal::ICRELNUM>(aic_->get_ls_int().compute_index(ai->get_litint()));
				break;
			case ::mlaskal::ICSPT_LITREAL:
				n = static_cast< ::mlaskal::ICRELNUM>(aic_->get_ls_real().compute_index(ai->get_litreal()));
				break;
			case ::mlaskal::ICSPT_LITSTR:
				n = static_cast< ::mlaskal::ICRELNUM>(aic_->get_ls_string().compute_index(ai->get_litstr()));
				break;
			case ::mlaskal::ICSPT_GSTKOFFS:
			case ::mlaskal::ICSPT_LSTKOFFS:
			case ::mlaskal::ICSPT_SSTKOFFS:
				n = ai->get_stkoffs();
				break;
			case ::mlaskal::ICSPT_ABSNUM:
				n = static_cast< ::mlaskal::ICRELNUM>(ai->get_absnum());
				break;
			case ::mlaskal::ICSPT_RELJUMP:
				n = static_cast< ::mlaskal::ICRELNUM>(af_->get_block()->compute_index(ai->get_reljump()))-fncip_;
				break;
			case ::mlaskal::ICSPT_ABSJUMP:
				n = static_cast< ::mlaskal::ICRELNUM>((fic_->get_fncs().begin()+aic_->get_abstract_functions().compute_index(ai->get_absjump()))->get_icip_start());
				break;
			default:
				assert(0);
			}

			++fncip_;

			return ::mlaskal::ic_factory::create_ic_instr(
									ai->get_opcode(),
									n,
									ai->get_in1(),
									ai->get_in2(),
									ai->get_in3(),
									ai->get_in4(),
									ai->get_out());

		}
	private:
		const ::mlaskal::abstract_ic *aic_;
		const ::mlaskal::abstract_function *af_;
		::mlaskal::ICRELNUM fncip_;
		const ::mlaskal::flat_icblock *fic_;
	};

	class ftor_ai2ic {
	public:
		ftor_ai2ic(const ::mlaskal::abstract_ic &aic, ::mlaskal::flat_icblock &fic) : aic_(&aic),fic_(&fic) { }
		void operator()(const ::mlaskal::abstract_function &af)
		{
			transform(af.get_block()->begin(), af.get_block()->end(), back_inserter(fic_->get_icblock()), ftor_aiaf2icff(*aic_, af, *fic_));
		}
	private:
		const ::mlaskal::abstract_ic *aic_;
		::mlaskal::flat_icblock *fic_;
	};

}

namespace mlaskal {

	// explicit specialization for complex types
	template <>
	struct rwtrait_gen<file_function_param> {
		class read_bin_ftor {
		public:
			read_bin_ftor(std::istream &is) : is_(&is) { }
			file_function_param operator()()
			{
			unsigned name_idx;
				is_->read(reinterpret_cast<char *>(&name_idx), sizeof(unsigned));
			unsigned ptype;
				is_->read(reinterpret_cast<char *>(&ptype), sizeof(unsigned));
			unsigned size;
				is_->read(reinterpret_cast<char *>(&size), sizeof(unsigned));
			int stkoff;
				is_->read(reinterpret_cast<char *>(&stkoff), sizeof(int));

				return file_function_param(
					static_cast<ICLITIDX>(name_idx),
					static_cast<physical_type>(ptype),
					static_cast<ICABSNUM>(size),
					static_cast<ICSTKOFFS>(stkoff)
					);
			}
		private:
			std::istream *is_;
		};
		class write_bin_ftor {
		public:
			write_bin_ftor(std::ostream &os) : os_(&os) { }
			void operator()(const file_function_param &v)
			{
			unsigned u;
			int i;

				u = static_cast<unsigned>(v.get_name());
				os_->write(reinterpret_cast<const char *>(&u), sizeof(unsigned));
				u = static_cast<unsigned>(v.get_ptype());
				os_->write(reinterpret_cast<const char *>(&u), sizeof(unsigned));
				u = static_cast<unsigned>(v.get_size());
				os_->write(reinterpret_cast<const char *>(&u), sizeof(unsigned));
				i = static_cast<int>(v.get_stkoffs());
				os_->write(reinterpret_cast<const char *>(&i), sizeof(int));
			}
		private:
			std::ostream *os_;
		};
		template <typename U>
		class write_asm_ftor {
		public:
			write_asm_ftor(std::ostream &os, const U &ids) : os_(&os),ids_(&ids),first_(true) { }
			void operator()(const file_function_param &v)
			{
				if(!first_)
					*os_ << ", ";
				*os_ << ids_->at(v.get_name()) << ':' << v.get_ptype() << " [size=" << v.get_size() << ";stkoffs=" << v.get_stkoffs() << "]";
				first_ = false;
			}
		private:
			std::ostream	*os_;
			const U			*ids_;
			bool			first_;
		};
	};

	template <>
	struct rwtrait_gen<file_function_var> {
		class read_bin_ftor {
		public:
			read_bin_ftor(std::istream &is) : is_(&is) { }
			file_function_var operator()()
			{
			unsigned name_idx;
				is_->read(reinterpret_cast<char *>(&name_idx), sizeof(unsigned));
			unsigned ptype;
				is_->read(reinterpret_cast<char *>(&ptype), sizeof(unsigned));
			unsigned icip_start;
				is_->read(reinterpret_cast<char *>(&icip_start), sizeof(unsigned));
			unsigned icip_end;
				is_->read(reinterpret_cast<char *>(&icip_end), sizeof(unsigned));
			unsigned size;
				is_->read(reinterpret_cast<char *>(&size), sizeof(unsigned));
			int stkoff;
				is_->read(reinterpret_cast<char *>(&stkoff), sizeof(int));

				return file_function_var(
					static_cast<ICLITIDX>(name_idx),
					static_cast<physical_type>(ptype),
					static_cast<ICABSNUM>(icip_start),
					static_cast<ICABSNUM>(icip_end),
					static_cast<ICABSNUM>(size),
					static_cast<ICSTKOFFS>(stkoff)
					);
			}
		private:
			std::istream *is_;
		};
		class write_bin_ftor {
		public:
			write_bin_ftor(std::ostream &os) : os_(&os) { }
			void operator()(const file_function_var &v)
			{
			unsigned u;
			int i;

				u = static_cast<unsigned>(v.get_name());
				os_->write(reinterpret_cast<const char *>(&u), sizeof(unsigned));
				u = static_cast<unsigned>(v.get_ptype());
				os_->write(reinterpret_cast<const char *>(&u), sizeof(unsigned));
				u = static_cast<unsigned>(v.get_icip_start());
				os_->write(reinterpret_cast<const char *>(&u), sizeof(unsigned));
				u = static_cast<unsigned>(v.get_icip_end());
				os_->write(reinterpret_cast<const char *>(&u), sizeof(unsigned));
				u = static_cast<unsigned>(v.get_size());
				os_->write(reinterpret_cast<const char *>(&u), sizeof(unsigned));
				i = static_cast<int>(v.get_stkoffs());
				os_->write(reinterpret_cast<const char *>(&i), sizeof(int));
			}
		private:
			std::ostream *os_;
		};
		template <typename U>
		class write_asm_ftor {
		public:
			write_asm_ftor(std::ostream &os, const U &ids) : os_(&os),ids_(&ids) { }
			void operator()(const file_function_var &v)
			{
				*os_ << "\t\t" << ids_->at(v.get_name()) << ':' << v.get_ptype() << 
							"[start=" << v.get_icip_start() << ";end=" << v.get_icip_end() << 
							";size=" << v.get_size() << ";stkoffs=" << v.get_stkoffs() << "]\n";
			}
		private:
			std::ostream	*os_;
			const U			*ids_;
		};
	};

	template <>
	struct rwtrait_gen<file_function> {
		class read_bin_ftor {
		public:
			read_bin_ftor(std::istream &is) : is_(&is) { }
			file_function operator()()
			{
			unsigned fs_type_rd;
				is_->read(reinterpret_cast<char *>(&fs_type_rd), sizeof(unsigned));
			unsigned name_idx;
				is_->read(reinterpret_cast<char *>(&name_idx), sizeof(unsigned));
			unsigned icip_start;
				is_->read(reinterpret_cast<char *>(&icip_start), sizeof(unsigned));
			unsigned icip_end;
				is_->read(reinterpret_cast<char *>(&icip_end), sizeof(unsigned));
			unsigned ptype;
				is_->read(reinterpret_cast<char *>(&ptype), sizeof(unsigned));
			unsigned size;
				is_->read(reinterpret_cast<char *>(&size), sizeof(unsigned));
			int stkoff;
				is_->read(reinterpret_cast<char *>(&stkoff), sizeof(int));
			unsigned used_regs;
				is_->read(reinterpret_cast<char *>(&used_regs), sizeof(unsigned));
			file_function_params params;
				file_seq_read_cont_bin(params, *is_);
			file_function_vars vars;
				file_seq_read_cont_bin(vars, *is_);

				return static_cast<fnc_signature_type>(fs_type_rd)==FNCSIG_FNC?
					file_function(
						file_function_rv(static_cast<physical_type>(ptype),static_cast<ICABSNUM>(size),static_cast<ICSTKOFFS>(stkoff)),
						static_cast<ICLITIDX>(name_idx),
						static_cast<ICABSNUM>(icip_start),
						static_cast<ICABSNUM>(icip_end),
						static_cast<ICREGNUM>(used_regs),
						params,
						vars
						):
					file_function(
						static_cast<fnc_signature_type>(fs_type_rd),
						static_cast<ICLITIDX>(name_idx),
						static_cast<ICABSNUM>(icip_start),
						static_cast<ICABSNUM>(icip_end),
						static_cast<ICREGNUM>(used_regs),
						params,
						vars
						);
			}
		private:
			std::istream *is_;
		};
		class write_bin_ftor {
		public:
			write_bin_ftor(std::ostream &os) : os_(&os) { }
			void operator()(const file_function &v)
			{
			unsigned u;

				u = static_cast<unsigned>(v.get_type());
				os_->write(reinterpret_cast<const char *>(&u), sizeof(unsigned));
				u = static_cast<unsigned>(v.get_name());
				os_->write(reinterpret_cast<const char *>(&u), sizeof(unsigned));
				u = static_cast<unsigned>(v.get_icip_start());
				os_->write(reinterpret_cast<const char *>(&u), sizeof(unsigned));
				u = static_cast<unsigned>(v.get_icip_end());
				os_->write(reinterpret_cast<const char *>(&u), sizeof(unsigned));
				u = static_cast<unsigned>(v.get_type()==FNCSIG_FNC?v.get_rv().get_ptype():PTYPE_UNDEF);
				os_->write(reinterpret_cast<const char *>(&u), sizeof(unsigned));
				u = static_cast<unsigned>(v.get_type()==FNCSIG_FNC?v.get_rv().get_size():0);
				os_->write(reinterpret_cast<const char *>(&u), sizeof(unsigned));
				u = static_cast<unsigned>(v.get_type()==FNCSIG_FNC?v.get_rv().get_stkoffs():0);
				os_->write(reinterpret_cast<const char *>(&u), sizeof(unsigned));
				u = static_cast<unsigned>(v.get_used_regs());
				os_->write(reinterpret_cast<const char *>(&u), sizeof(unsigned));
				file_seq_write_cont_bin(v.get_params(), *os_);
				file_seq_write_cont_bin(v.get_vars(), *os_);
			}
		private:
			std::ostream *os_;
		};
		template <typename U>
		class write_asm_ftor {
		public:
			write_asm_ftor(std::ostream &os, const U &ids) : os_(&os),ids_(&ids) { }
			void operator()(const file_function &v)
			{
				*os_ << ids_->at(v.get_name());
				if(!v.get_params().empty())		// we have parameters
				{
					*os_ << '(';
					file_seq_write_cont_asm(v.get_params(), *os_, string(), *ids_);
					*os_ << ')';
				}
				if(v.get_type()==FNCSIG_FNC)		// it has return type
				{
					*os_ << ':' << v.get_rv().get_ptype();
				}
				*os_ << "\t[" << v.get_icip_start() << ';' << v.get_icip_end() << "], used registers=" << v.get_used_regs() << "\n";
				if(!v.get_vars().empty())		// we have variables
				{
					*os_ << "\tVAR\n";
					file_seq_write_cont_asm(v.get_vars(), *os_, string(), *ids_);
				}
			}
		private:
			std::ostream	*os_;
			const U			*ids_;
		};
	};

	template <>
	struct rwtrait_gen<ic_instr *> {
		class read_bin_ftor {
		public:
			read_bin_ftor(std::istream &is) : is_(&is) { }
			ic_instr * operator()()
			{
			unsigned opc;
				is_->read(reinterpret_cast<char *>(&opc), sizeof(unsigned));
			int stkn;
				is_->read(reinterpret_cast<char *>(&stkn), sizeof(int));
			unsigned in1;
				is_->read(reinterpret_cast<char *>(&in1), sizeof(unsigned));
			unsigned in2;
				is_->read(reinterpret_cast<char *>(&in2), sizeof(unsigned));
			unsigned in3;
				is_->read(reinterpret_cast<char *>(&in3), sizeof(unsigned));
			unsigned in4;
				is_->read(reinterpret_cast<char *>(&in4), sizeof(unsigned));
			unsigned out;
				is_->read(reinterpret_cast<char *>(&out), sizeof(unsigned));

				return ic_factory::create_ic_instr(
					static_cast<ai::IC_OPCODE>(opc),
					static_cast<ICRELNUM>(stkn),
					static_cast<ICABSNUM>(in1),
					static_cast<ICABSNUM>(in2),
					static_cast<ICABSNUM>(in3),
					static_cast<ICABSNUM>(in4),
					static_cast<ICABSNUM>(out));
			}
		private:
			std::istream *is_;
		};
		class write_bin_ftor {
		public:
			write_bin_ftor(std::ostream &os) : os_(&os) { }
			void operator()(const ic_instr *v)
			{
			unsigned u;

				u = static_cast<unsigned>(v->get_opcode());
				os_->write(reinterpret_cast<const char *>(&u), sizeof(unsigned));
				u = static_cast<int>(v->get_stkn());
				os_->write(reinterpret_cast<const char *>(&u), sizeof(int));
				u = static_cast<unsigned>(v->get_in1());
				os_->write(reinterpret_cast<const char *>(&u), sizeof(unsigned));
				u = static_cast<unsigned>(v->get_in2());
				os_->write(reinterpret_cast<const char *>(&u), sizeof(unsigned));
				u = static_cast<unsigned>(v->get_in3());
				os_->write(reinterpret_cast<const char *>(&u), sizeof(unsigned));
				u = static_cast<unsigned>(v->get_in4());
				os_->write(reinterpret_cast<const char *>(&u), sizeof(unsigned));
				u = static_cast<unsigned>(v->get_out());
				os_->write(reinterpret_cast<const char *>(&u), sizeof(unsigned));
			}
		private:
			std::ostream *os_;
		};
		template <typename U>
		class write_asm_ftor {
		public:
			write_asm_ftor(std::ostream &os, const U &flt_blk) : os_(&os),flt_blk_(&flt_blk),count_(0) { }
			void operator()(const ic_instr *v)
			{
				typename map<ICABSNUM, const file_function *>::const_iterator mci;

				if((mci=flt_blk_->find_fnc(static_cast<ICABSNUM>(count_)))!=flt_blk_->get_fncs_map().end())
					*os_ << flt_blk_->get_ls_id().at(mci->second->get_name()) << ":\n";

				string opc, oper;
				v->get_asm(opc, oper);

				*os_ << count_ << ":\t" << opc;
				if(oper!="")
					*os_ << '\t' << oper;
				switch(ai::ic_instrtab[v->get_opcode()].stkp_type_)
				{
				case ICSPT_RELJUMP:
					*os_ << "\t;; target=" << count_+v->get_stkn();
					break;
				case ICSPT_ABSJUMP:
					*os_ << "\t;; label=";
					if((mci=flt_blk_->get_fncs_map().find(static_cast<ICABSNUM>(v->get_stkn())))!=flt_blk_->get_fncs_map().end())
						*os_ << flt_blk_->get_ls_id().at(mci->second->get_name());
					else
						*os_ << "!!!UNDEFINED!!!";
					break;
				default:		// default for dazed GCC
					break;
				}
				++count_;
				*os_ << '\n';
			}
		private:
			std::ostream	*os_;
			const U			*flt_blk_;
			int					count_;
		};
	};

	class ftor_fnc_map {
	public:
		ftor_fnc_map(map<ICABSNUM, const file_function *> &fnc_map) : fnc_map_(&fnc_map) { }
		void operator()(const file_function &v)
		{
			fnc_map_->insert(make_pair(v.get_icip_start(), &v));
		}
	private:
		map<ICABSNUM, const file_function *>		*fnc_map_;
	};

	flat_icblock::flat_icblock(const string &filename)
	{
	ifstream ifs;

		ifs.exceptions(ios::badbit|ios::failbit);
		try 
		{
			ifs.open(filename.c_str(), ios_base::in|ios_base::binary);
		}
		catch(...)
		{
			throw flat_icblock_exception(flat_icblock_exception::FICBER_OPEN);
		}

		try
		{
			file_seq_read_cont_bin(ls_int_, ifs);
			file_seq_read_cont_bin(ls_real_, ifs);
			file_seq_read_cont_bin(ls_string_, ifs);
			file_seq_read_cont_bin(ls_id_, ifs);
			file_seq_read_cont_bin(fncs_, ifs);
			file_seq_read_cont_bin(icblock_, ifs);
		}
		catch(const ios_base::failure &)
		{
			throw flat_icblock_exception(ifs.fail()?flat_icblock_exception::FICBER_ERR:flat_icblock_exception::FICBER_CORRUPT);
		}

		// compute fnc map
		for_each(fncs_.begin(), fncs_.end(), ftor_fnc_map(fncs_map_));

		ifs.close();
	}

	flat_icblock::flat_icblock(const abstract_ic &aic)
	{
		// copy literals
		copy(aic.get_ls_int().begin(), aic.get_ls_int().end(), back_inserter(ls_int_));
		copy(aic.get_ls_real().begin(), aic.get_ls_real().end(), back_inserter(ls_real_));
		copy(aic.get_ls_string().begin(), aic.get_ls_string().end(), back_inserter(ls_string_));
		copy(aic.get_ls_id().begin(), aic.get_ls_id().end(), back_inserter(ls_id_));

		// transform functions
		// !!! here should be checks for exactly one occurence of program as the first fnc
		transform(aic.get_abstract_functions().begin(),
				  aic.get_abstract_functions().end(),
				  back_inserter(fncs_),
				  ftor_af2ff_trans(aic));

		// transform function map
		transform(fncs_.begin(), fncs_.end(), inserter(fncs_map_, fncs_map_.end()), ftor_ff2ffmap());

		// transform instructions
		for_each(aic.get_abstract_functions().begin(), aic.get_abstract_functions().end(), ftor_ai2ic(aic, *this));
	}

	void flat_icblock::save(const string &filename)
	{
	ofstream ofs;

		ofs.exceptions(ios::badbit|ios::failbit);
		ofs.open(filename.c_str(), ios_base::out|ios_base::binary);

		file_seq_write_cont_bin(ls_int_, ofs);
		file_seq_write_cont_bin(ls_real_, ofs);
		file_seq_write_cont_bin(ls_string_, ofs);
		file_seq_write_cont_bin(ls_id_, ofs);
		file_seq_write_cont_bin(fncs_, ofs);
		file_seq_write_cont_bin(icblock_, ofs);

		ofs.close();
	}

	void flat_icblock::save_asm(const string &filename)
	{
	ofstream ofs;

		ofs.exceptions(ios::badbit|ios::failbit);
		ofs.open(filename.c_str(), ios_base::out);

		file_seq_write_cont_asm(ls_int_, ofs, "Integer constants", ls_id_);
		file_seq_write_cont_asm(ls_real_, ofs, "Real constants", ls_id_);
		file_seq_write_cont_asm(ls_string_, ofs, "String constants", ls_id_);
		file_seq_write_cont_asm(ls_id_, ofs, "Identifiers", ls_id_);
		file_seq_write_cont_asm(fncs_, ofs, "Functions and procedures", ls_id_);
		file_seq_write_cont_asm(icblock_, ofs, "Instructions", *this);

		ofs.close();
	}

}
