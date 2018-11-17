#ifndef ABBREVIATION_SIMPLEALGORITHM_HPP_
#define ABBREVIATION_SIMPLEALGORITHM_HPP_

////////////////////////////////////////////////////////////////////////
////////////////////œ–Œ—“≈…ÿ»≈//////¿¡¡–≈¬»¿“”–€////////////////////////
////////////////////////////////////////////////////////////////////////

#include "AbstractAlgorithm.hpp"

class SimpleAlgorithm : public AbstractAlgorithm {
public:
	void search() override;
private:
	void searchSimpleAbbr(std::vector<std::string> &text, const bool &language);
};
#endif 