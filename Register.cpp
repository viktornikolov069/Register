#include "Register.h"

static size_t currIndex = 0;

//===========================
// PLS EXPLAIN ???
namespace std {
	template <typename T> T* begin(std::pair<T*, T*> const& p) {
		return p.first;
	}
	template <typename T> T* end(std::pair<T*, T*> const& p) {
		return p.second;
	}
}
//===========================

Register::Register(size_t numCompanies)
	: numAdded{numCompanies} {
	companiesArray = new Company[numCompanies];
	currIndex = 0;
}

void Register::add(const Company& c) {
	
	companiesArray[currIndex] = c;
	++currIndex;
}

Company Register::get(int companyId) const {

	// STANDART WAY OF SOLVING THIS
	
	//for (size_t i = 0; i < numAdded; ++i) {
	//	if (companiesArray[i].getId() == companyId) {
	//		return companiesArray[i];
	//	}
	//}

	//===============================
	// THIS WAY ALSO WORKS BUT I DON'T UNDERSTAND IT VERY WELL ???
	// PLS EXPLAIN

	for (auto&& company : std::make_pair(companiesArray, companiesArray+numAdded)) {
		if (company.getId() == companyId) {
			return company;
		}
	}
	return Company();
	//===============================
}

Register::~Register() {
	delete[] companiesArray;
	companiesArray = nullptr;
}