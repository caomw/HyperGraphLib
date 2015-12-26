
#include "include/Isomorph.hh"

Isomorph::Isomorph(const boost::shared_ptr<HypergrapheAbstrait>& ptrHypergrapheAbstraitA, const boost::shared_ptr<HypergrapheAbstrait>& ptrHypergrapheAbstraitB) : _ptrHypergrapheAbstraitA(ptrHypergrapheAbstraitA), _ptrHypergrapheAbstraitB(ptrHypergrapheAbstraitB) {

}

void
Isomorph::runAlgorithme() {
}

RStructure
Isomorph::getResult() {
	return _result;
}

Isomorph::~Isomorph() {
}

