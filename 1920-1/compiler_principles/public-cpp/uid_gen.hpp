#ifndef GUARD_MLASKAL_UID_GEN_HPP_
#define GUARD_MLASKAL_UID_GEN_HPP_

/*

	uid_gen.hpp

	Unique ID generator

	Kuba, 2006

*/

namespace mlaskal {

	/// @cond INTERNAL

	struct uid_gen_policy_counter {
		typedef unsigned long UID_type;
		class counter_holder {
		public:
			counter_holder() : counter_(0) { }
			UID_type get_UID() { return ++counter_; }
		private:
			UID_type counter_;
		};
		typedef counter_holder status_type;
		static UID_type generate_UID(status_type &status) { return status.get_UID(); }
		static const UID_type null_value=0;
	};

	template <typename T=uid_gen_policy_counter>
	class uid_gen {
	public:
		typedef typename T::UID_type UID_type;
		uid_gen() { }
		UID_type get_UID() { return T::generate_UID(status_); }
		static const UID_type null_value = T::null_value;
	private:
		typename T::status_type		status_;
	};

	typedef uid_gen<uid_gen_policy_counter> uid_all_type;
	extern uid_all_type uid_all;

	/// @endcond 

}

#endif
