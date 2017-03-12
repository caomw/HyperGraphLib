#include "../include/Hypergraph/model/HyperFactory.hh"
#include "../include/Hypergraph/model/HypergrapheAbstrait.hh"
#include "../include/Hypergraph/model/Hypergraphe.hh"
#include <criterion/criterion.h>

boost::shared_ptr<HypergrapheAbstrait> ptrHpg ( new Hypergraphe );

void setup(void) {
    HyperFactory::startSession(ptrHpg);

    boost::shared_ptr<HyperEdge> ptrEdge1 ( HyperFactory::newHyperEdge() );
    boost::shared_ptr<HyperEdge> ptrEdge2 ( HyperFactory::newHyperEdge() );

    for(unsigned int i = 0; i < 50; i++) {

        boost::shared_ptr<HyperVertex> ptrVertexA( HyperFactory::newHyperVertex() );
        boost::shared_ptr<HyperVertex> ptrVertexB( HyperFactory::newHyperVertex() );

        HyperFactory::link(ptrVertexA, ptrEdge1);
        HyperFactory::link(ptrVertexB, ptrEdge2);

        ptrHpg->addHyperVertex(ptrVertexA);
        ptrHpg->addHyperVertex(ptrVertexB);

    }

    ptrHpg->addHyperEdge(ptrEdge1);
    ptrHpg->addHyperEdge(ptrEdge2);

    HyperFactory::closeSession();

    ptrHpg->flush();

}

void teardown(void) {
}

Test(test_model, hpg_create, .init = setup, .fini = teardown) {

    // Size of hpg's elements
    cr_expect(ptrHpg->getHyperEdgeList().size() == 2, "Incorrect HyperEdgeList size");
    cr_expect(ptrHpg->getHyperVertexList().size() == 100, "Incorrect HyperVertexList size");
}

Test(test_model, hpg_ids, .init = setup, .fini = teardown) {

    // Identifiers
    for(unsigned int i=0; i < ptrHpg->getHyperVertexList().size(); i++) {
        cr_expect(ptrHpg->getHyperVertexById(i)->getIdentifier() == i, "Incorrect Id");
    }
}

Test(test_model, hpg_mtx, .init = setup, .fini = teardown) {

	const boost::shared_ptr<HyperEdge> e1 = ptrHpg->getHyperEdgeById(0);
	const boost::shared_ptr<HyperEdge> e2 = ptrHpg->getHyperEdgeById(1);

	// Adjacent matrix
	cr_expect(ptrHpg->getAdjacentMatrix().getEdgeSize(e1) == e1->getEffectif(), "adj. mtx1 issue");
	cr_expect(ptrHpg->getAdjacentMatrix().getEdgeSize(e2) == e2->getEffectif(), "adj. mtx2 issue");
}
