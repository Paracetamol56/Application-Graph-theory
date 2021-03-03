

#pragma once
#include "Node.hpp"

#include <array>
#include <memory>

class CEdge {


public : 
	using pEdge =  std::shared_ptr<CEdge>;
	using NodeVector = std::array<CNode::pNode,2> ;

	CEdge(CNode::pNode pNode1, CNode::pNode pNode2, double weight) {
		m_apNodes.at(0) = pNode1;
		m_apNodes.at(1) = pNode2;
		m_dWeight = weight;
	}

	// GETTER
	const NodeVector& GetNodes() const { return m_apNodes; }
	CNode::pNode GetNode(std::size_t i) const { return m_apNodes.at(i); }
	CNode::pNode GetFirstNode() const { return GetNode(0); }
	CNode::pNode GetSecondNode() const { return GetNode(1); }
	double GetWeight() const { return m_dWeight; }

protected :
	double m_dWeight;     // poids de l arete
	NodeVector m_apNodes; // vecteur de 2 noeuds
};