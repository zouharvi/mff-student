#include "Dictionary.h"


using namespace std;


void Dictionary::StableDictionaryAtom::add(string s) {
// possibly a better structure could be implemented to avoid this
	if(::std::find(data.begin(), data.end(), s) == data.end())
		data.push_back(s);
}

void Dictionary::StableDictionaryAtom::find() {
	if(data.size() != 0) {
		for(size_t i = 0; i < data.size(); ++i) {
			if(i != 0)
				cout << " ";
			cout <<  data[i];
		}
		cout << endl;;
	}
}

void Dictionary::StableDictionaryAtom::del(string& s) {
	// remove from data
	data.erase(remove(data.begin(), data.end(), s), data.end());
}


void Dictionary::OrderedDictionaryAtom::del(string& s) {
	// remove from data
	data.erase(s);
}

void Dictionary::OrderedDictionaryAtom::add(string s) {
	data.insert(s);
}

void Dictionary::OrderedDictionaryAtom::find() {
	if(data.size() != 0) {
		for(auto i = data.begin(); i != data.end(); ++i) {
			if(i != data.begin())
				cout << " ";
			cout << *i;
		}
		cout << endl;;
	}
}

void Dictionary::process(vector<string> r) {
	//vector<string> stripped(r.begin() + 1, r.end());
	if(r[0] == "add")
		add(r);
	else if(r[0] == "find")
		find(r);
	else if(r[0] == "rfind")
		rfind(r);
	else if(r[0] == "pfind")
		pfind(r);
	else if(r[0] == "del")
		del(r);
}

void Dictionary::del(vec_str& r) {
	// delete all
	if(r.size() == 2) {
		for(const auto& trans: atoms[r[1]].data) {
			rev_atoms[trans].del(r[1]);
		}
		// strictly not necessary
		atoms.erase(r[1]);
	} else {
		for(size_t i = 2; i < r.size(); i++) {
			rev_atoms[r[i]].del(r[1]);
			atoms[r[1]].del(r[i]);
		}
	}
}

void Dictionary::add(vec_str& r) {
	for(size_t i = 2; i < r.size(); ++i) {
		atoms[r[1]].add(r[i]);
		rev_atoms[r[i]].add(r[1]);
	}
}

void Dictionary::find(vec_str& r) {
	atoms[r[1]].find();
}

void Dictionary::rfind(vec_str& r) {
	// TODO: alpha sort
	rev_atoms[r[1]].find();
}

void Dictionary::pfind(vec_str& r) {
	auto lower = atoms.lower_bound(r[1]);

	// is prefix
	while(lower != atoms.end() && lower->first.find(r[1]) == 0) {
		if(lower->second.data.size() != 0) {
			cout << lower->first << " ";
			lower->second.find();
		}
		lower ++;
	}
}
