#include <string>
#include <map>
#include <vector>
#include <set>
#include <iostream>
#include <iterator>
#include <algorithm>


using vec_str = ::std::vector<::std::string>;
using set_str = ::std::set<::std::string>;
class Dictionary {
	class StableDictionaryAtom {
		public:
			void add(std::string);
			void find();
			void del(std::string&);
		//private:
			vec_str data;
	};

	class OrderedDictionaryAtom {
		public:
			void add(std::string);
			void find();
			void del(std::string&);
		//private:
			set_str data;
	};

	public:
		void add(vec_str&);
		void del(vec_str&);
		void find(vec_str&);
		void rfind(vec_str&);
		void pfind(vec_str&);
		void process(vec_str);

	private:
		std::map<std::string, StableDictionaryAtom> atoms;
		// std::map<std::string, StableDictionaryAtom> rev_atoms;
		std::map<std::string, OrderedDictionaryAtom> rev_atoms;
};
