#pragma once

#include "Node.hpp"

#include <array>
#include <memory>

class CEdge {
public : 
	using pEdge = std::shared_ptr<CEdge>;
	static pEdge New(CNode::pNode pNode1, CNode::pNode pNode2, double weight = 0) { return std::make_shared<CEdge>(pNode1, pNode2, weight); }

	using   pNodeArray = std::array<CNode::pNode,2>;

	CEdge(CNode::pNode pNode1, CNode::pNode pNode2, double weight)
		: m_dWeight(weight), m_apNodes{ pNode1,pNode2 } {}

	const pNodeArray& GetNodes() const { return m_apNodes; }

	CNode::pNode GetFirstNode() const { return m_apNodes[0]; }
	CNode::pNode GetSecondNode() const { return m_apNodes[1]; }

protected:
	double m_dWeight;
	pNodeArray m_apNodes;

public :
	// TP 2 :
//// TODO : ajouter des Geteurs sur le milieu de l'arête et sur le poids
  	float GetMilieuX()const { return (m_apNodes[0]->GetX() + m_apNodes[1]->GetX()) / 2; }
  	float GetMilieuY()const { return (m_apNodes[0]->GetY() + m_apNodes[1]->GetY()) / 2; }
  	double GetWeight() const { return m_dWeight; }
//
//	// TODO : ajouter l'operateur d égalité entre 2 edges
  	bool operator==(const CEdge& edge) { return m_dWeight == edge.m_dWeight && m_apNodes[0] == edge.m_apNodes[0] && m_apNodes[1] == edge.m_apNodes[1]; }
};